/*
 * exti.h
 *
 *  Created on: 28-Sept-2026
 *      Author: pulak_mac
 */

#ifndef EXTI_H_
#define EXTI_H_

#include "stm32f446xx_reg.h"

#define      SYSCFGEN       (1U << 14)
#define      EXTI13_PORT_MASK (0xFU << 4)
#define      EXTIPORTCEN      (2U << 4) /* Port C in EXTI13 field */
#define      EXTIIMREN      (1U << 13)
#define      EXTIFTSREN     (1U << 13)
#define      IRQ_NO         40
#define      BIT_NO         (40%32)
#define      NVIC13EN       (1U << BIT_NO)

void exti_pc13_init(void);
uint32_t exti13_take_event(void);
extern volatile uint32_t exti13_event;

#endif /* EXTI_H_ */
