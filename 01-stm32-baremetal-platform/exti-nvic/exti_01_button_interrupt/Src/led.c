#include "led.h"
#include <stdint.h>

#define   LED_GREEN_PIN        12U
#define   LED_ORANGE_PIN       13U
#define   LED_RED_PIN          14U
#define   LED_BLUE_PIN         15U


#define   LED_PORT_MASK        (0xFU << 12)
#define   GPIOD_BASE           0x40020C00UL
#define   GPIO_ODR_OFFSET      0x14UL
#define   GPIOD_ODR            (*(volatile uint32_t *)(GPIOD_BASE + GPIO_ODR_OFFSET))

/*==================================================================
 * Turning ON the LEDs
 *
 *==================================================================*/

void LED_On (LED_t led)
{
	switch(led)
	{
	case LED_GREEN:
		GPIOD_ODR |= (1U << LED_GREEN_PIN);
		break;
	case LED_ORANGE:
		GPIOD_ODR |= (1U << LED_ORANGE_PIN);
		break;
	case LED_RED:
		//GPIOD_ODR |= (1U << LED_RED_PIN);
		break;
	case LED_BLUE:
		GPIOD_ODR |= (1U << LED_BLUE_PIN);
		break;
	default:
		break;
	}
}

/*==================================================================
 * Turning OFF the LEDs
 *
 *==================================================================*/

void LED_Off(LED_t led)
{
	switch(led)
	{
	case LED_GREEN:
		GPIOD_ODR &= ~(1U << LED_GREEN_PIN);
		break;
	case LED_ORANGE:
		GPIOD_ODR &= ~(1U << LED_ORANGE_PIN);
		break;
	case LED_RED:
		GPIOD_ODR &= ~(1U << LED_RED_PIN);
		break;
	case LED_BLUE:
		GPIOD_ODR &= ~(1U << LED_BLUE_PIN);
		break;
	default:
		break;
	}
}

/*==================================================================
 * Toggle the LEDs
 *
 *==================================================================*/

void LED_Toggle(LED_t led)
{
	switch(led)
	{
	case LED_GREEN:
		GPIOD_ODR ^= (1U << LED_GREEN_PIN);
		break;
	case LED_ORANGE:
		GPIOD_ODR ^= (1U << LED_ORANGE_PIN);
		break;
	case LED_RED:
		GPIOD_ODR ^= (1U << LED_RED_PIN);
		break;
	case LED_BLUE:
		GPIOD_ODR ^= (1U << LED_BLUE_PIN);
		break;
	default:
		break;
	}
}

