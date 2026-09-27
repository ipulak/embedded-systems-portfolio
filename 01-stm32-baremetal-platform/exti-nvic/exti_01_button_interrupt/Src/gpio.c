#include "gpio.h"
#include "stm32f407xx_reg.h"

/*==================================================================
 * GPIO Initialization Function
 *
 *==================================================================*/
void GPIO_Init(void)
{
    /* Enable GPIOA and GPIOD clocks */
    RCC_AHB1ENR |= (1U << 0);   /* GPIOA */
    RCC_AHB1ENR |= (1U << 3);   /* GPIOD */


    /* =========================
     * PA0 - User Button
     * Input mode
     * ========================= */

    GPIOA_MODER &= ~(3U << 0);

    /*
     * PA0 is configured as input.
     * The STM32F4 Discovery board provides
     * the required button bias externally.
     */
    GPIOA_PUPDR &= ~(3U << 0);


    /* =========================
     * PD12-PD15 - LEDs
     * General purpose output
     * ========================= */

    /* PD12 */
    GPIOD_MODER &= ~(3U << 24);
    GPIOD_MODER |=  (1U << 24);

    /* PD13 */
    GPIOD_MODER &= ~(3U << 26);
    GPIOD_MODER |=  (1U << 26);

    /* PD14 */
    GPIOD_MODER &= ~(3U << 28);
    GPIOD_MODER |=  (1U << 28);

    /* PD15 */
    GPIOD_MODER &= ~(3U << 30);
    GPIOD_MODER |=  (1U << 30);


    /* Low speed for LEDs */
    GPIOD_OSPEEDR &= ~(3U << 24);
    GPIOD_OSPEEDR &= ~(3U << 26);
    GPIOD_OSPEEDR &= ~(3U << 28);
    GPIOD_OSPEEDR &= ~(3U << 30);


    /* No pull-up / pull-down for LEDs */
    GPIOD_PUPDR &= ~(3U << 24);
    GPIOD_PUPDR &= ~(3U << 26);
    GPIOD_PUPDR &= ~(3U << 28);
    GPIOD_PUPDR &= ~(3U << 30);


    /* Initially turn all LEDs OFF */
    GPIOD_ODR &= ~(1U << 12);
    GPIOD_ODR &= ~(1U << 13);
    GPIOD_ODR &= ~(1U << 14);
    GPIOD_ODR &= ~(1U << 15);
}
