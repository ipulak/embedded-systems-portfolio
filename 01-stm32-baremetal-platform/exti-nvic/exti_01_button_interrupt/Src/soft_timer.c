#include "soft_timer.h"


/* =========================
 * Software Timer Instances
 * ========================= */

volatile SoftTimer_t timers[MAX_SOFT_TIMERS];


/* =========================
 * Start Timer
 * ========================= */

void SoftTimer_Start(volatile SoftTimer_t *timer,
                     uint32_t period,
                     SoftTimer_Mode_t mode)
{
    timer->period  = period;
    timer->counter = 0;
    timer->expired = 0;
    timer->active  = 1;
    timer->mode    = mode;
}


/* =========================
 * Stop Timer
 * ========================= */

void SoftTimer_Stop(volatile SoftTimer_t *timer)
{
    timer->active  = 0;
    timer->counter = 0;
    timer->expired = 0;
}


/* =========================
 * Restart Timer
 * ========================= */

void SoftTimer_Restart(volatile SoftTimer_t *timer)
{
    timer->counter = 0;
    timer->expired = 0;
    timer->active  = 1;
}


/* =========================
 * Check Timer Expiration
 * ========================= */

uint8_t SoftTimer_Expired(volatile SoftTimer_t *timer)
{
    if (timer->expired)
    {
        timer->expired = 0;
        return 1;
    }

    return 0;
}


/* =========================
 * Timer Tick
 *
 * Called every 1 ms from
 * SysTick_Handler()
 * ========================= */

void SoftTimer_Tick(volatile SoftTimer_t *timer)
{
    if (!timer->active)
    {
        return;
    }

    timer->counter++;

    if (timer->counter >= timer->period)
    {
        timer->counter = 0;
        timer->expired = 1;

        /*
         * One-shot timer:
         * stop after expiration.
         */
        if (timer->mode == TIMER_ONESHOT)
        {
            timer->active = 0;
        }

        /*
         * Periodic timer:
         * remain active and automatically
         * start counting the next period.
         */
    }
}


/* =========================
 * Tick All Timers
 *
 * Called from SysTick_Handler()
 * ========================= */

void SoftTimer_TickAll(void)
{
    for (uint32_t i = 0; i < MAX_SOFT_TIMERS; i++)
    {
        SoftTimer_Tick(&timers[i]);
    }
}
