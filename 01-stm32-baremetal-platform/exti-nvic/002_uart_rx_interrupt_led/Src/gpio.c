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

	/* Configure PA3 as alternate function mode */
	GPIOA_MODER |= (1U << 7);
	GPIOA_MODER &= ~(1U << 6);

	/* Configure PA3 as USART_RX alternate function */
	GPIOA_AFRL |= (1U << 12);
	GPIOA_AFRL |= (1U << 13);
	GPIOA_AFRL |= (1U << 14);
	GPIOA_AFRL &= ~(1U << 15);


	/*----------Configure Output GPIO-----------------*/
	/* Clock is already enabled */
	GPIOA_ODR &= ~LED_PIN; /* Start LD2 off. */
	/* Configure PA5 as output */
	GPIOA_MODER |= (1U << 10);
	GPIOA_MODER &= ~(1U << 11);
}

void led_on(void)
{
	GPIOA_ODR |= LED_PIN;
}

void led_off(void)
{
	GPIOA_ODR &= ~LED_PIN;
}
