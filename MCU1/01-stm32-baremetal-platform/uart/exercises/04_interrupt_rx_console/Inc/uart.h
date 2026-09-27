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

void uart2_init(void);
void uart2_write(uint8_t data);
uint8_t uart2_read(void);
extern volatile uint8_t rx_data;
extern volatile uint8_t rx_ready;

#endif /* UART_H_ */
