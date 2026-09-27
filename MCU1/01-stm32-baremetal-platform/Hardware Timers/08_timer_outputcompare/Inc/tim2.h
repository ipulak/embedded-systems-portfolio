/*
 * tim2.h
 *
 *  Created on: 24-Sept-2026
 *      Author: pulak_mac
 */

#ifndef TIM2_H_
#define TIM2_H_

#include "stm32f407xx_reg.h"


#define  TIM2_EN               (1U << 0)
#define  TIM2_CCMR1_TOG        ((1U << 4) | (1U << 5))

void tim2_init_output_compare(void);

#endif /* TIM2_H_ */
