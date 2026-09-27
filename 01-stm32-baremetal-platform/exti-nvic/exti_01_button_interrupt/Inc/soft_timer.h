#ifndef  SOFT_TIMER_H
#define  SOFT_TIMER_H

#include <stdint.h>

#define   MAX_SOFT_TIMERS    2

typedef enum
{
	TIMER_PATTERN = 0,
	TIMER_BUTTON_DEBOUNCE
}SoftTimer_ID_t;

typedef enum
{
	TIMER_ONESHOT = 0,
	TIMER_PERIODIC
}SoftTimer_Mode_t;

typedef struct
{
	uint32_t         period;
	uint32_t         counter;
	uint8_t          expired;
	uint8_t          active;
	SoftTimer_Mode_t mode;
}SoftTimer_t;

void SoftTimer_Start(volatile SoftTimer_t *timer, uint32_t period, SoftTimer_Mode_t mode);
void SoftTimer_Stop(volatile SoftTimer_t *timer);
void SoftTimer_Restart(volatile SoftTimer_t *timer);
uint8_t SoftTimer_Expired(volatile SoftTimer_t *timer);
void SoftTimer_Tick(volatile SoftTimer_t *timer);
void SoftTimer_TickAll(void);

extern volatile SoftTimer_t timers[MAX_SOFT_TIMERS];


#endif
