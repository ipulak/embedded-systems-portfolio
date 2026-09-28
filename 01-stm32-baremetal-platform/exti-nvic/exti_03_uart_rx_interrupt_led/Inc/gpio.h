/*
 * gpio.h
 *
 *  Created on: 28-Sept-2026
 *      Author: pulak_mac
 */

#ifndef GPIO_H_
#define GPIO_H_

#include "stm32f446xx_reg.h"

#define     GPIOAEN             (1U << 0)
#define     GPIOCEN             (1U << 2)
#define     LED_PIN             (1U << 5)

void gpio_init(void);
void led_on(void);
void led_off(void);

#endif /* GPIO_H_ */
