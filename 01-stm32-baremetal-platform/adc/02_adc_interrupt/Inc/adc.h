/*
 * adc.h
 *
 *  Created on: 16-Sept-2026
 *      Author: pulak_mac
 */

#ifndef ADC_H_
#define ADC_H_

#include "stm32f407xx_reg.h"
#include <stdbool.h>


void adc_init(void);

extern volatile uint32_t adc_irq_value;
extern volatile bool adc_irq_ready;

#endif /* ADC_H_ */
