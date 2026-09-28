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
#define     CR1_M               (1U << 12)
#define     CR1_UE              (1U << 13)
#define     SR_TXE              (1U << 7)

#define     SYS_CLOCK           16000000U
#define     APB1_CLOCK          SYS_CLOCK

#define     UART2_BAUDRATE      115200

void uart_tx_init(void);
int __io_putchar(int ch);

#endif /* UART_H_ */
