#ifndef  LED_PATTERN_H
#define  LED_PATTERN_H

#include "led.h"
typedef enum
{
	PATTERN_RUNNING = 0,
	PATTERN_ALL_ON,
	PATTERN_ALL_OFF,
	PATTERN_ALTERNATING
}LEDPattern_t;

void LEDPattern_Init(void);
void LEDPattern_Run(void);
void LEDPattern_Next(void);

#endif
