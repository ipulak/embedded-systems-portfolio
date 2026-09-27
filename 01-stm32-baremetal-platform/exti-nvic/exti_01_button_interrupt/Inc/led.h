#ifndef  LED_H
#define  LED_H

typedef enum
{
	LED_GREEN  = 0,
	LED_ORANGE,
	LED_RED,
	LED_BLUE
}LED_t;


void LED_On(LED_t led);
void LED_Off(LED_t led);
void LED_Toggle(LED_t led);

#endif


