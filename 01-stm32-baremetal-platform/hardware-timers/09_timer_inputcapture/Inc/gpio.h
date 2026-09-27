/*
 * gpio.h
 *
 *  Created on: 24-Sept-2026
 *      Author: pulak_mac
 */

#ifndef GPIO_H_
#define GPIO_H_

#include "stm32f407xx_reg.h"

#define   GPIOEN          (1U << 0)


void gpio_init(void);

#endif /* GPIO_H_ */
