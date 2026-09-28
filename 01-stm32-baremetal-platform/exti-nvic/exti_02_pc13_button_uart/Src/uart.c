/*
 * uart.c
 *
 *  Created on: 28-Sept-2026
 *      Author: pulak_mac
 */

#include "uart.h"

static uint16_t compute_uart2_bd(uint32_t periphClk, uint32_t baudrate);
static void uart_set_baudrate(uint32_t periphClk, uint32_t baudrate);


void uart_tx_init(void)
{

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

static void uart_set_baudrate(uint32_t periphClk, uint32_t baudrate)
{
	UART2_BRR = compute_uart2_bd(periphClk, baudrate);
}

static uint16_t compute_uart2_bd(uint32_t periphClk, uint32_t baudrate)
{
	return ((periphClk + (baudrate/2))/baudrate);
}

/* Called by the existing _write() in syscalls.c; no CMSIS required. */
int __io_putchar(int ch)
{
    while ((UART2_SR & SR_TXE) == 0U)
    {
        /* Wait until the transmit data register is empty. */
    }
    UART2_DR = (uint8_t)ch;
    return ch;
}
