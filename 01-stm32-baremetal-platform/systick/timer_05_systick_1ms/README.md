# Timer 05 — SysTick 1 ms Time Base

[SysTick overview](../README.md)

Configure a 1 ms Cortex-M SysTick time base and increment a volatile tick counter in `SysTick_Handler()`. The foreground code uses the counter for a blocking millisecond delay and LED toggling.

This demonstrates a tick-based delay; it does not yet implement a non-blocking software-timer service. It is a source snapshot rather than a standalone build project.

## Next steps

- [Planned non-blocking SysTick scheduler](../capstone/README.md).
- [Combined TIM2 + SysTick capstone](../../capstone/timer_06_capstone/README.md).
