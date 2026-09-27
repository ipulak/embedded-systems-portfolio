/*
 * systick.h
 *
 *  Created on: 16-Sept-2026
 *      Author: pulak_mac
 */

#ifndef SYSTICK_H_
#define SYSTICK_H_

#include "stm32f407xx_reg.h"

void systick_init_100ms(void);
void systick_wait_tick(void);

#endif /* SYSTICK_H_ */
