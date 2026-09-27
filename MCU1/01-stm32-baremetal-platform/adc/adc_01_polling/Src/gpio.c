/*
 * gpio.c
 *
 *  Created on: 07-Sept-2026
 *      Author: pulak_mac
 */

#include "gpio.h"


#define     GPIOAEN             (1U << 0)

void gpio_init(void)
{
	/*---------Configure UART GPIO PIN -------------*/
	/* Enable clock for GPIOA */
	RCC_AHB1ENR |= GPIOAEN;

	/* Configure PA1 as analog mode */
	GPIOA_MODER |= (3U << 0);

	/* Configure PA1 as no push pull register */
	GPIOA_PUPDR &= ~(3U << 0);


}
