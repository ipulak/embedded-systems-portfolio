/*
 * gpio.c
 *
 *  Created on: 28-Sept-2026
 *      Author: pulak_mac
 */

#include "gpio.h"

void gpio_init(void)
{
	/*---------Configure UART GPIO PIN -------------*/
	/* Enable clock for GPIOA */
	RCC_AHB1ENR |= GPIOAEN;

	/* Configure PA2 as alternate function */
	GPIOA_MODER |= (1U << 5);
	GPIOA_MODER &= ~(1U << 4);

	/* Configure PA2 as UART2 function */
	GPIOA_AFRL |= (1U << 8);
	GPIOA_AFRL |= (1U << 9);
	GPIOA_AFRL |= (1U << 10);
	GPIOA_AFRL &= ~(1U << 11);

	/*----------Configure Input GPIO-----------------*/
	/* Enable clock for GPIOC */
	RCC_AHB1ENR |= GPIOCEN;

	/* Configure PC13 as input */
	GPIOC_MODER &= ~(1U << 26);
	GPIOC_MODER &= ~(1U << 27);
	GPIOC_PUPDR &= ~(3U << 26); /* Board provides the PC13 button bias. */

	/*----------Configure Output GPIO-----------------*/
	/* Clock is already enabled */
	GPIOA_ODR &= ~LED_PIN; /* Start LD2 off. */
	/* Configure PA5 as output */
	GPIOA_MODER |= (1U << 10);
	GPIOA_MODER &= ~(1U << 11);
}

void gpio_toggle(void)
{
	GPIOA_ODR ^= LED_PIN;
}
