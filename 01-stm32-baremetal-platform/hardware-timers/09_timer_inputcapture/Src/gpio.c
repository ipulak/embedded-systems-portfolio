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

	/* Configure PA5 as alternate function mode */
	GPIOA_MODER &= ~(1U << 10);
	GPIOA_MODER |= (1U << 11);

	/* Set PA5 as TIM2_CH1 alternate function */
	GPIOA_AFRL |= (1U << 20);

	/* Configure PA6 as alternate function mode */
	GPIOA_MODER &= ~(1U << 12);
	GPIOA_MODER |= (1U << 13);

	/* SEt PA6 as TIM3_CH1 - AF2 alternate function */
	GPIOA_AFRL |= (1U << 25);

}

