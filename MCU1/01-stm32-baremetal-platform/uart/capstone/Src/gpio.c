/*
 * gpio.c
 *
 *  Created on: 07-Sept-2026
 *      Author: pulak mukherjee
 */

#include "gpio.h"


#define     GPIOAEN             (1U << 0)
#define     LED_PIN             (1U << 5)

void gpio_init(void)
{
	/*---------Configure UART GPIO PIN -------------*
	 *   PA2 -> TX
	 *   PA3 -> RX
	 *   PA5 -> LD2
	 ************************************************/
	/* Enable clock for GPIOA */
	RCC_AHB1ENR |= GPIOAEN;

	/* Configure PA5 as output */
	GPIOA_MODER |= (1U << 10);
	GPIOA_MODER &= ~(1U << 11);

	/* Configure PA2 as alternate function */
	GPIOA_MODER |= (1U << 5);
	GPIOA_MODER &= ~(1U << 4);

	/* Configure PA2 as UART2_TX function */
	GPIOA_AFRL |= (1U << 8);
	GPIOA_AFRL |= (1U << 9);
	GPIOA_AFRL |= (1U << 10);
	GPIOA_AFRL &= ~(1U << 11);

	/* Configure PA3 as alternate function */
	GPIOA_MODER |= (1U << 7);
	GPIOA_MODER &= ~(1U << 6);

	/* Configure PA3 as UART2_RX function */
	GPIOA_AFRL |= (1U << 12);
	GPIOA_AFRL |= (1U << 13);
	GPIOA_AFRL |= (1U << 14);
	GPIOA_AFRL &= ~(1U << 15);
}

void gpio_led_on(void)
{
	GPIOA_ODR |= LED_PIN;
}

void gpio_led_off(void)
{
	GPIOA_ODR &= ~LED_PIN;
}

void gpio_led_toggle(void)
{
	GPIOA_ODR ^= LED_PIN;
}

uint8_t gpio_led_get_state(void)
{
	return (GPIOA_ODR & LED_PIN) ? 1U : 0U;
}
