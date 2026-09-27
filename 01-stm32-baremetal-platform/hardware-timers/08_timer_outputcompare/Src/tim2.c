/*
 * tim2.c
 *
 *  Created on: 24-Sept-2026
 *      Author: pulak_mac
 */


#include "tim2.h"


void tim2_init_output_compare(void)
{

	/* Enable the clock access */
	RCC_APB1ENR |= TIM2_EN;

	/* Set Prescale value */
	TIM2_PSC = 1000 -1;

	/* Set ARR value */
	TIM2_ARR = 16000 -1;

    /* Set output compare to toggle mode */
	TIM2_CCMR1 = TIM2_CCMR1_TOG;

	/* Enable TIM2 ch1 in compare mode */
	TIM2_CCER |= (1U << 0);

	/* Clear Counter value */
	TIM2_CNT = 0;

	/* Enable the timer */
	TIM2_CR1 = TIM2_EN;
}

