/*
 * uart.h
 *
 *  Created on: 07-Sept-2026
 *      Author: pulak_mac
 */

#ifndef UART_H_
#define UART_H_

#include <stdint.h>
#include "stm32f407xx_reg.h"

void uart_tx_init(void);
void uart2_write(int ch);

#endif /* UART_H_ */
