/*
 * uart.c
 *
 *  Created on: 07-Sept-2026
 *      Author: pulak_mac
 */

#include "uart.h"

#define     GPIOAEN             (1U << 0)
#define     UART2EN             (1U << 17)

#define     CR1_TE              (1U << 3)
#define     CR1_M               (1U << 12)
#define     CR1_UE              (1U << 13)
#define     SR_TXE              (1U << 7)

#define     SYS_CLOCK           16000000U
#define     APB1_CLOCK          SYS_CLOCK

#define     UART2_BAUDRATE      115200

static uint16_t compute_uart2_bd(uint32_t periphClk, uint32_t baudrate);
static void uart_set_baudrate(uint32_t periphClk, uint32_t baudrate);


int __io_putchar(int ch)
{
	uart2_write(ch);
	return ch;
}

void uart_tx_init(void)
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

	/*-----------Configure UART module --------------*/
	/* Enable clock for UART2 */
	RCC_APB1ENR |= UART2EN;

	/* configure baud rate for transmission */
	uart_set_baudrate(APB1_CLOCK, UART2_BAUDRATE);

	/* Configure transfer  direction */
	UART2_CR1 |= CR1_TE;

	/* Configure data frame: 1 start bit, 8 data bits */
	UART2_CR1 &= ~ CR1_M;

	/* Setting stop bit as 1 bit */
	UART2_CR2 &= ~ (1U << 12);
	UART2_CR2 &= ~ (1U << 13);

	/* Enable UART module */
	UART2_CR1 |= CR1_UE;

}

void uart2_write(int ch)
{
	/* Make sure transmit data register is empty */
	while(!(UART2_SR & SR_TXE)) {}

	/* Write to transmit data register */
	UART2_DR = (ch & 0xFF);
}

static void uart_set_baudrate(uint32_t periphClk, uint32_t baudrate)
{
	UART2_BRR = compute_uart2_bd(periphClk, baudrate);
}

static uint16_t compute_uart2_bd(uint32_t periphClk, uint32_t baudrate)
{
	return ((periphClk + (baudrate/2))/baudrate);
}

