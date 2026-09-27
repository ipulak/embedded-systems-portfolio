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
	GPIOA_AFRL = (1U << 20);

}

