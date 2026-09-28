# STM32 Bare-Metal Platform

[Portfolio learning path](../LEARNING_PATH.md)

Register-level STM32 drivers, independent learning projects, and peripheral integration capstones. This collection is not yet a single integrated driver library.

## Modules

- [ADC](adc)
- [DMA](dma) — planning notes.
- [UART](uart)
- [SPI](spi) — planning notes.
- [I2C](i2c) — planning notes.
- [Hardware Timers](hardware-timers)
- [SysTick and software timers](systick)
- [GPIO](gpio)
- [EXTI and NVIC](exti-nvic) — button interrupt projects for STM32F407 and NUCLEO-F446RE, a USART2 receive interrupt LED exercise, and a capstone plan.
- [Cortex-M](cortex-m) — planning notes.
- [Embedded system design](system-design) — planning notes.

## Capstones

See the [capstone index](capstone/README.md) for existing projects and planned integrations. Peripheral capstones remain beside their exercises to preserve their build layouts.

## Imported projects

- `exti-nvic/exti_01_button_interrupt/`
- `exti-nvic/exti_02_pc13_button_uart/`
- `exti-nvic/002_uart_rx_interrupt_led/`
- `adc/adc_01_polling/`
- `adc/02_adc_interrupt/`
- `hardware-timers/07_timer/`
- `hardware-timers/08_timer_outputcompare/`
- `hardware-timers/09_timer_inputcapture/`

These include source, headers, startup code, linker scripts, and STM32CubeIDE metadata. Generated build output and IDE workspace caches were excluded. Import projects individually into STM32CubeIDE and verify their target board before flashing.
