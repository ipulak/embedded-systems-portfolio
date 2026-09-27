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
#define  TIM3_EN               (1U << 1)
#define  TIM3_CEN_EN           (1U << 0)
#define  TIM2_CCMR1_TOG        ((1U << 4) | (1U << 5))
#define  TIM3_SR_CC1IF         (1U << 1)

void tim2_init_output_compare(void);
void tim3_input_capture(void);

#endif /* TIM2_H_ */
