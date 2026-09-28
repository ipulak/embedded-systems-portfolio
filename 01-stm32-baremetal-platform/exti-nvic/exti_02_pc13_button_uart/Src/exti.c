#include "exti.h"

volatile uint32_t exti13_event = 0;

void exti_pc13_init(void)
{
    RCC_APB2ENR |= SYSCFGEN;
    (void)RCC_APB2ENR; /* Allow the peripheral clock enable to take effect. */

    EXTI_IMR &= ~EXTIIMREN;
    /* Update only EXTI13's port field, preserving EXTI12/14/15. */
    SYSCFG_EXTICR4 = (SYSCFG_EXTICR4 & ~EXTI13_PORT_MASK) | EXTIPORTCEN;
    EXTI_RTSR &= ~EXTIIMREN;
    EXTI_FTSR |= EXTIFTSREN; /* NUCLEO-F446RE B1: falling edge on press. */
    EXTI_PR = EXTIIMREN;    /* Clear stale pending status: write 1 to clear. */
    EXTI_IMR |= EXTIIMREN;
    NVIC_ISER1 = NVIC13EN;  /* IRQ 40, ISER1 bit 8: write 1 to enable. */
}

/* Claim a pending event before slow foreground work. Preserve interrupt state. */
uint32_t exti13_take_event(void)
{
    uint32_t primask;
    uint32_t event;
    __asm volatile ("mrs %0, primask\n\tcpsid i" : "=r" (primask) :: "memory");
    event = exti13_event;
    exti13_event = 0;
    __asm volatile ("msr primask, %0" :: "r" (primask) : "memory");
    return event;
}

void EXTI15_10_IRQHandler(void)
{
    if (EXTI_PR & EXTIIMREN)
    {
        EXTI_PR = EXTIIMREN;
        exti13_event = 1;
    }
}
