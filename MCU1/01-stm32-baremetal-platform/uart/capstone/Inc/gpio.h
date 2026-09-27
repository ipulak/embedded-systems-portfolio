/*
 * gpio.h
 *
 *  Created on: 07-Sept-2026
 *      Author: pulak_mac
 */

#ifndef GPIO_H_
#define GPIO_H_

#include <stdint.h>
#include "stm32f446xx_reg.h"

void gpio_init(void);
void gpio_led_on(void);
void gpio_led_off(void);
void gpio_led_toggle(void);
uint8_t gpio_led_get_state(void);

#endif /* GPIO_H_ */
