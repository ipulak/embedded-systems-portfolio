# EXTI 01 — Button Interrupt

[EXTI and NVIC overview](../README.md)

STM32F407VG register-level button interrupt project, imported from `gpio_05_exti_button_interrupt` and renamed to `exti_01_button_interrupt`.

The application initializes GPIO and EXTI0, uses SysTick for a 1 ms software-timer tick, and processes button events to advance LED patterns. EXTI/NVIC is the primary topic; SysTick supports the software timing.

## STM32CubeIDE

1. Import this directory as an existing project.
2. Build `exti_01_button_interrupt` in Debug or Release.
3. Select the matching `exti_01_button_interrupt` launch configuration.
4. Check board wiring against the GPIO and interrupt source before flashing.

Project metadata, build paths, executable references, and the debugger log path use the new project name. Source files are preserved. Generated build output and workspace caches are excluded. Hardware behavior has not been revalidated as part of this import.
