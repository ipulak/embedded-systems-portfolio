#include "led_pattern.h"
#include "soft_timer.h"

static LEDPattern_t current_pattern = PATTERN_ALTERNATING;
static LED_t current_led = LED_GREEN;
static uint8_t alternate_state = 0;

/*==================================================================
 * LED Pattern Initialization
 *
 *==================================================================*/

void LEDPattern_Init(void)
{
	LED_Off(LED_GREEN);
	LED_Off(LED_ORANGE);
	LED_Off(LED_RED);
	LED_Off(LED_BLUE);

	LED_On(current_led);
}

/*==================================================================
 * Main Driver of LED patterns
 *
 *==================================================================*/

void LEDPattern_Run(void)
{
	switch(current_pattern)
	{
	case PATTERN_RUNNING:
		if(SoftTimer_Expired(&timers[TIMER_PATTERN]))
		{
			LED_Off(current_led);

			current_led++;

			if(current_led > LED_BLUE)
			{
				current_led = LED_GREEN;
			}

			LED_On(current_led);
		}

		break;

	case PATTERN_ALL_ON:
		/* Nothing to do */
		break;

	case PATTERN_ALL_OFF:
	    /* Nothing to do */
		break;

	case PATTERN_ALTERNATING:

		if(SoftTimer_Expired(&timers[TIMER_PATTERN]))
		{
			if(alternate_state == 0)
			{
				LED_Off(LED_GREEN);
				LED_On(LED_ORANGE);

				LED_Off(LED_RED);
				LED_On(LED_BLUE);

				alternate_state = 1;
			}
			else
			{
				LED_On(LED_GREEN);
				LED_Off(LED_ORANGE);

				LED_On(LED_RED);
				LED_Off(LED_BLUE);

				alternate_state = 0;
			}
		}
		break;
	default:
		break;
	}
}

/*==================================================================
 * Enter function for LED pattern
 *
 *==================================================================*/

void LEDPattern_Enter(void)
{
	LED_Off(LED_GREEN);
	LED_Off(LED_ORANGE);
	LED_Off(LED_RED);
	LED_Off(LED_BLUE);

	current_led = LED_GREEN;
	alternate_state = 0;

	switch(current_pattern)
	{
	case PATTERN_RUNNING:
		LED_On(LED_GREEN);
		break;

	case PATTERN_ALL_ON:
		LED_On(LED_GREEN);
		LED_On(LED_ORANGE);
		LED_On(LED_RED);
		LED_On(LED_BLUE);
		break;

	case PATTERN_ALL_OFF:
		/* All LEDs remain OFF */
		break;

	case PATTERN_ALTERNATING:
		LED_On(LED_GREEN);
		LED_On(LED_RED);
		break;

	default:
		current_pattern = PATTERN_RUNNING;
		LED_On(LED_GREEN);
		break;
	}
}

/*==================================================================
 * LED pattern Next functionality
 *
 *==================================================================*/

void LEDPattern_Next(void)
{
	switch(current_pattern)
	{
	case PATTERN_RUNNING:
		current_pattern = PATTERN_ALL_ON;
		break;

	case PATTERN_ALL_ON:
		current_pattern = PATTERN_ALL_OFF;
		break;

	case PATTERN_ALL_OFF:
		current_pattern = PATTERN_ALTERNATING;
		break;

	case PATTERN_ALTERNATING:
		current_pattern = PATTERN_RUNNING;
		break;

	default:
		current_pattern = PATTERN_RUNNING;
		break;
	}

	LEDPattern_Enter();
}
