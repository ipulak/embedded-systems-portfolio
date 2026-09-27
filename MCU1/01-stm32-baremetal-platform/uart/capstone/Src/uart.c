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

#define     SR_PE               (1U << 0)  /* Parity error */
#define     SR_FE               (1U << 1)  /* Framing error */
#define     SR_NF               (1U << 2)  /* Noise error */
#define     SR_ORE              (1U << 3)  /* Overrun error */
#define     SR_TXE              (1U << 7)
#define     SR_RXNE             (1U << 5)

#define     SYS_CLOCK           16000000U
#define     APB1_CLOCK          SYS_CLOCK
#define     UART2_BAUDRATE      115200

#define     RX_BUFFER_SIZE      64U

static uint8_t rx_buffer[RX_BUFFER_SIZE];

static volatile uint8_t  head = 0;
static volatile uint8_t  tail = 0;

static volatile uint8_t  rx_overflow = 0;
volatile uint8_t  uart_error_flags = 0;

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
	uint32_t status = UART2_SR;

	if (status & (SR_PE | SR_FE | SR_NF | SR_ORE))
	{
		uart_error_flags |= (uint8_t)(status & (SR_PE | SR_FE | SR_NF | SR_ORE));
	}

	if (status & SR_RXNE)
	{
		uint8_t data;
		uint8_t next_head;

		data = UART2_DR;

		next_head = (head + 1U) % RX_BUFFER_SIZE;

		if (next_head == tail)
		{
			rx_overflow = 1;
		}
		else
		{
			rx_buffer[head] = data;
			head = next_head;
		}
	}
}

uint8_t uart2_read_nonblocking(uint8_t *data)
{
	if (head == tail)
	{
		return 0;
	}

	*data = rx_buffer[tail];
	tail = (tail + 1) % RX_BUFFER_SIZE;

	return 1;
}
