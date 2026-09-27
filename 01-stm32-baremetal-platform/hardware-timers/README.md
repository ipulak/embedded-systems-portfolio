# Hardware Timers

[Platform overview](../README.md)

STM32 peripheral timer exercises. Cortex-M SysTick examples are in [systick](../systick/README.md).

## TIM2 fundamentals — source snapshots

- [timer_01_basic](timer_01_basic/README.md): TIM2 counter configuration.
- [timer_02_polling](timer_02_polling/README.md): poll the update flag.
- [timer_03_interrupt](timer_03_interrupt/README.md): TIM2 update interrupt and NVIC.
- [TIM2 interrupt architecture](tim2_interrupt_architecture.md).

These three projects are source snapshots, not complete standalone builds. Matching register headers, startup code, and linker configuration are required.

## STM32CubeIDE projects

- [07_timer](07_timer/)
- [08_timer_outputcompare](08_timer_outputcompare/)
- [09_timer_inputcapture](09_timer_inputcapture/)

These projects target STM32F407VG. Import each project separately and confirm wiring against its source before running. Older copied launch profiles may refer to earlier exercises; select the configuration matching the current project.

## Capstones

- [Hardware timer capstone plan](capstone/README.md).
- [Combined TIM2 + SysTick example](../capstone/timer_06_capstone/README.md).

## TIM2 calculations

Counter frequency = timer input clock / (PSC + 1).

For a 16 MHz timer input clock and PSC = 15, the counter runs at 1 MHz. ARR = 999 gives a 1 ms update period. Verify the actual timer clock before applying these values.
