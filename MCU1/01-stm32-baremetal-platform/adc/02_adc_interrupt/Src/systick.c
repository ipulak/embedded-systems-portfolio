/*
 * systick.c
 *
 *  Created on: 16-Sept-2026
 *      Author: pulak_mac
 */

#include "systick.h"


void systick_init_100ms(void)
{
	/* Stop systick before configure it */
	SYST_CSR = 0;

	/* 16 MHz * 0.1 seconds = 1,600,000 clock cycles */
	SYST_RVR = 1600000U - 1U;

	/* Clear the current count and COUNTFLAG */
	SYST_CVR = 0;

	/* Bit 2:Processor clock
	 * Bit 1: disabled interrupts
	 * Bit 2: timer enabled */
	SYST_CSR = (1U << 2) | (1U << 0);

}

void systick_wait_tick(void)
{
	/* wait until counter flag is set
	 * Reading CSR also clear the flag */
	while((SYST_CSR & (1U << 16)) == 0)
	{
	}
}
