# SysTick and Software Timing

[Platform overview](../README.md)

This folder contains Cortex-M SysTick examples. STM32 TIM2 peripheral projects live separately in [hardware-timers](../hardware-timers/README.md).

## Source snapshots

- [timer_04_systick](timer_04_systick/README.md): configure SysTick and increment a tick counter in its handler.
- [timer_05_systick_1ms](timer_05_systick_1ms/README.md): use a 1 ms SysTick counter for a blocking millisecond delay and LED toggling.

These are source snapshots, not complete standalone CubeIDE projects. Supply the matching register header, startup code, and linker configuration before building. Original stage numbers are retained.

## Capstones

- [SysTick-only software scheduler plan](capstone/README.md): planned non-blocking LED patterns and button debounce.
- [Combined TIM2 + SysTick example](../capstone/timer_06_capstone/README.md): the existing mixed-peripheral snapshot is now under the platform capstone folder.

## Distinction

SysTick is the Cortex-M core timer. TIM2 is an STM32 peripheral timer with its own clock and interrupt configuration. Software timing can be built on a tick counter; using such a counter does not by itself make a delay non-blocking.
