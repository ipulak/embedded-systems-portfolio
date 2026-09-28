/*
 * uart.h
 *
 *  Created on: 28-Sept-2026
 *      Author: pulak_mac
 */

#ifndef UART_H_
#define UART_H_

#include "stm32f446xx_reg.h"


#define     UART2EN             (1U << 17)

#define     CR1_TE              (1U << 3)
#define     CR1_RE              (1U << 2)
#define     CR1_M               (1U << 12)
#define     CR1_UE              (1U << 13)
#define     SR_TXE              (1U << 7)
#define     CR1_RXNEIE          (1U << 5)
#define     USART2_IRQ_NO       38U
#define     USART2_IRQ_MASK     (1U << (USART2_IRQ_NO % 32U))

#define     SYS_CLOCK           16000000U
#define     APB1_CLOCK          SYS_CLOCK

#define     UART2_BAUDRATE      115200

extern volatile uint32_t uart_command;

void uart_rxtx_init(void);
int __io_putchar(int ch);
uint32_t uart2_take_command(void);

#endif /* UART_H_ */
