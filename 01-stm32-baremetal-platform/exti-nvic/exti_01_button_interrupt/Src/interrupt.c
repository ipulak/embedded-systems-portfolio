#include "interrupt.h"
#include "soft_timer.h"
#include "stm32f407xx_reg.h"

/*==================================================================
 * EXTI0 initialization Function
 *
 *==================================================================*/

void EXTI0_Init(void)
{
    /*
     * Enable SYSCFG peripheral clock
     */
    RCC_APB2ENR |= (1U << 14);

    /*
     * Route PA0 to EXTI0
     *
     * EXTI0 corresponds to SYSCFG_EXTICR1 bits [3:0].
     * 0000 = PA0
     */
    SYSCFG_EXTICR1 &= ~(0xFU << 0);

    /*
     * Unmask EXTI0
     */
    EXTI_IMR |= (1U << 0);

    /*
     * Trigger on rising edge
     */
    EXTI_RTSR |= (1U << 0);

    /*
     * Clear any pending EXTI0 interrupt
     */
    EXTI_PR = (1U << 0);

    /*
     * Enable EXTI0 in NVIC
     *
     * STM32F407:
     * EXTI0_IRQn = 6
     */
    NVIC_ISER0 |= (1U << 6);
}

/*==================================================================
 * EXTI0 interrupt Handler
 *
 *==================================================================*/

void EXTI0_IRQHandler(void)
{
    if (EXTI_PR & (1U << 0))
    {
        /*
         * Clear pending interrupt
         */
        EXTI_PR = (1U << 0);

        /*
         * Start de-bounce window only if
         * de-bounce timer is not active.
         */
        if (!timers[TIMER_BUTTON_DEBOUNCE].active)
        {
        	SoftTimer_Start(
                &timers[TIMER_BUTTON_DEBOUNCE],
                50,
				TIMER_ONESHOT
            );
        }
    }
}
