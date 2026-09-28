/*
 * uart.c
 *
 *  Created on: 28-Sept-2026
 *      Author: pulak_mac
 */

#include "uart.h"

static uint16_t compute_uart2_bd(uint32_t periphClk, uint32_t baudrate);
static void uart_set_baudrate(uint32_t periphClk, uint32_t baudrate);

volatile uint32_t uart_command = 0;

void uart_rxtx_init(void)
{

	/*-----------Configure UART module --------------*/
	/* Enable clock for UART2 */
	RCC_APB1ENR |= UART2EN;

	/* configure baud rate for transmission */
	uart_set_baudrate(APB1_CLOCK, UART2_BAUDRATE);

	/* Configure transfer  direction */
	UART2_CR1 |= (CR1_TE | CR1_RE);

	/* Configure data frame: 1 start bit, 8 data bits */
	UART2_CR1 &= ~ CR1_M;

	/* Setting stop bit as 1 bit */
	UART2_CR2 &= ~ (1U << 12);
	UART2_CR2 &= ~ (1U << 13);

	/* Enable RXNIE interrupt */
	UART2_CR1 |= CR1_RXNEIE;

	/* Enable UART module */
	UART2_CR1 |= CR1_UE;

	/* Enable USART2 interrupt in NVIC
	 * USART@ IRQ 38: 38 % 32 = 6 */
	NVIC_ISER1 = USART2_IRQ_MASK;

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

void USART2_IRQHandler(void)
{
	if (UART2_SR & (1U << 5)) /* RXNE */
	{
		uint8_t ch = (uint8_t)UART2_DR;

		if (ch == '1' || ch == '0')
		{
			uart_command = ch;
		}

	}

}

uint32_t uart2_take_command(void)
{
	uint32_t saved_primask;
	uint32_t command;

	/* Save interrupt state, then briefly disable interrupt */
	__asm volatile(
			"mrs %0, primask\n\t"
			"cpsid i"
			: "=r" (saved_primask)
			:
			: "memory"
	);

	command = uart_command;
	uart_command = 0U;

	/* Restore the previous interrupt state */
	__asm volatile (
			"msr primask, %0"
			:
			: "r" (saved_primask)
			: "memory"
	);

	return command;
}
