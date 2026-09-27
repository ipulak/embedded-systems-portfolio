/*
 * adc.c
 *
 *  Created on: 07-Sept-2026
 *      Author: pulak_mac
 */

#include "adc.h"


#define        ADC1EN             (1U << 8)

volatile   uint32_t adc_irq_value = 0;
volatile   bool     adc_irq_ready = false;

void adc_init(void)
{
	/* Enable clock access to ADC1 */
	RCC_APB2ENR |= ADC1EN;

	/* ADC clock = APB2 / 2 = 8 MHz */
	ADC1_CCR &= ~(3U << 16);

    /* RES[25:24] = 00: 12 bit resolution */
	ADC1_CR1 &= ~(3U << 24);

	/* Sequence Length: one conversion (L field = 0000) */
	ADC1_SQR1 &= ~(15U << 20);

	/* First conversion: channel 0 (SQ1 field = 0000) */
	ADC1_SQR3 &= ~(31U << 0);

    /* Clear channel 0's three sampling-time bits */
	ADC1_SMPR2 &= ~(7U << 0);

	/* Set them to binary 100: 84 ADC clock cycles */
	ADC1_SMPR2 |= (4U << 0);

    /* CONT = 0: stop after the sequence */
	ADC1_CR2 &= ~(1U << 1);

	/* EXTEN = 00: disable external triggering */
	ADC1_CR2 &= ~(3U << 28);

	/* ALIGN = 0: right-align the result */
	ADC1_CR2 &= ~(1U << 11);

    /* ADON = 1: power on ADC1 */
	ADC1_CR2 |= (1U << 0);

	/* Give the ADC time to settle before its first conversion */
	for(volatile uint32_t delay = 0; delay < 1000U; delay++)
	{
		/* Do nothing */
	}
}

void ADC_IRQHandler(void)
{
	/* Check whether ADC1 completed a conversion */
	if ((ADC1_SR & (1U << 1)) != 0)
	{

		/* Read the result, this will also clear EOC */
		adc_irq_value = ADC1_DR;

		/* Tell main that a result is available */
		adc_irq_ready = true;
	}
}
