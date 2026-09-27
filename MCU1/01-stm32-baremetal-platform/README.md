# STM32 Bare-Metal Platform

[MCU1 learning path](../README.md)

Register-level STM32 drivers, independent learning projects, and peripheral integration capstones. This collection is not yet a single integrated driver library.

## Modules

- [ADC](adc/)
- [DMA](dma/) — planning notes.
- [UART](uart/)
- [SPI](spi/) — planning notes.
- [I2C](i2c/) — planning notes.
- [Hardware Timers](Hardware%20Timers/)
- [SysTick and software timers](systick/)
- [GPIO](gpio/)
- [EXTI and NVIC](exti-nvic/) — planning notes.
- [Cortex-M](cortex-m/) — planning notes.
- [Embedded system design](system-design/) — planning notes.

## Capstones

See the [capstone index](capstone/README.md) for existing projects and planned integrations. Peripheral capstones remain beside their exercises to preserve their build layouts.

## Newly imported projects

- `adc/adc_01_polling/`
- `adc/02_adc_interrupt/`
- `Hardware Timers/07_timer/`
- `Hardware Timers/08_timer_outputcompare/`
- `Hardware Timers/09_timer_inputcapture/`

These include source, headers, startup code, linker scripts, and STM32CubeIDE metadata. Generated build output and IDE workspace caches were excluded. Import projects individually into STM32CubeIDE and verify their target board before flashing.
