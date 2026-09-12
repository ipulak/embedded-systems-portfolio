/*
 * uart.c
 *
 *  Created on: 07-Sept-2026
 *      Author: pulak_mac
 */

#include "uart.h"
#include "gpio.h"

#define     UART2EN             (1U << 17)

#define     CR1_TE              (1U << 3)
#define     CR1_RE              (1U << 2)
#define     CR1_M               (1U << 12)
#define     CR1_UE              (1U << 13)
#define     CR1_RXNEIE          (1U << 5)

#define     SR_TXE              (1U << 7)
#define     SR_RXNE             (1U << 5)

#define     SYS_CLOCK           16000000U
#define     APB1_CLOCK          SYS_CLOCK

#define     UART2_BAUDRATE      115200

volatile uint8_t rx_data;
volatile uint8_t rx_ready;

static uint16_t compute_uart2_bd(uint32_t periphClk, uint32_t baudrate);
static void uart_set_baudrate(uint32_t periphClk, uint32_t baudrate);

int __io_putchar(int ch)
{
	uart2_write(ch);
	return ch;
}

void uart2_init(void)
{
	/*-----------Configure UART module --------------*/
	/* Enable clock for UART2 */
	RCC_APB1ENR |= UART2EN;

	/* configure baud rate for transmission */
	uart_set_baudrate(APB1_CLOCK, UART2_BAUDRATE);

	/* Configure rx/tx and interrupt */
	UART2_CR1 = (CR1_TE | CR1_RE | CR1_RXNEIE);

	/* Enable UART module */
	UART2_CR1 |= CR1_UE;

}

uint8_t uart2_read(void)
{
	/* Make sure receive data register is not empty */
	while(!(UART2_SR & SR_RXNE)) {}

	/* Read from receive data register  */
	return UART2_DR;
}

void uart2_write(uint8_t data)
{
	/* Make sure transmit data register is empty */
	while(!(UART2_SR & SR_TXE)) {}

	/* Write to transmit data register */
	UART2_DR = data;
}

static void uart_set_baudrate(uint32_t periphClk, uint32_t baudrate)
{
	UART2_BRR = compute_uart2_bd(periphClk, baudrate);
}

static uint16_t compute_uart2_bd(uint32_t periphClk, uint32_t baudrate)
{
	return ((periphClk + (baudrate/2))/baudrate);
}

void USART2_IRQHandler(void)
{
	if (UART2_SR & SR_RXNE)
	{
		rx_data = UART2_DR;
		rx_ready = 1;
	}
}
