# Timer 06 — Combined TIM2 and SysTick Capstone

[Platform capstones](../README.md)

This source snapshot combines two timing mechanisms on STM32F407:

- SysTick increments `system_tick` every 1 ms, assuming a 16 MHz core clock.
- TIM2 generates update interrupts every 10 ms under the configured 16 MHz timer clock assumption.
- The TIM2 handler records the SysTick timestamp, increments an event counter, and signals the foreground loop.
- The foreground loop attempts to toggle PD13 at every 50th TIM2 event, nominally 500 ms.

It belongs here because it integrates a peripheral timer, a core timer, and GPIO. The source has been preserved unchanged during the folder reorganization.

## Current limits

This is not a completed software-timer manager, button-debounce implementation, or LED-pattern state machine. A single event flag can coalesce interrupts when the foreground loop is delayed, so the nominal LED timing is not guaranteed in that case. This snapshot also needs a matching register header, startup code, and linker configuration before it can build independently.

## Related learning material

- [TIM2 interrupt example](../../hardware-timers/timer_03_interrupt/README.md)
- [SysTick 1 ms example](../../systick/timer_05_systick_1ms/README.md)
- [Planned SysTick software scheduler](../../systick/capstone/README.md)
