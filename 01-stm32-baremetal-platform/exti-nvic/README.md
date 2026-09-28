# EXTI and NVIC

[Platform overview](../README.md)

## Projects

- [exti_01_button_interrupt](exti_01_button_interrupt/README.md): STM32F407VG external button interrupt with SysTick-based software timing and LED patterns. Includes STM32CubeIDE project files.

- [exti_02_pc13_button_uart](exti_02_pc13_button_uart/README.md): NUCLEO-F446RE PC13/EXTI13 button input, PA5 LED toggle, and USART2 logging. Uses direct register access and a foreground event latch; working on-board behavior confirmed on 2026-09-28.

## UART interrupt exercise

- [exti_03_uart_rx_interrupt_led](exti_03_uart_rx_interrupt_led/README.md): NUCLEO-F446RE USART2 receive interrupt, protected command handoff, PA5 LED control and serial acknowledgements. Uses the NVIC directly; no GPIO EXTI input is involved.

## Capstone

The [capstone plan](capstone/README.md) remains a separate planned exercise.
