/*
 * gpio.c
 *
 *  Created on: 24-Sept-2026
 *      Author: pulak_mac
 */


#include "gpio.h"


void gpio_init(void)
{

	/* enable the clock access */
	RCC_AHB1ENR |= GPIOEN;

	/* Configure PA5 as output register */
	GPIOA_MODER |= (1U << 10);
	GPIOA_MODER &= ~(1U << 11);

}

void gpio_led_blink (void)
{
	GPIOA_ODR ^= (1U << 5);
}
