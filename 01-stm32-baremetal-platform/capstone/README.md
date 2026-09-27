# Bare-Metal Platform — Capstones

[Platform overview](../README.md)

## Peripheral capstones

- [ADC](../adc/capstone/README.md)
- [DMA](../dma/capstone/README.md)
- [UART](../uart/capstone/README.md)
- [SPI](../spi/capstone/README.md)
- [I2C](../i2c/capstone/README.md)
- [Hardware Timers](../hardware-timers/capstone/README.md)
- [SysTick and software timers](../systick/capstone/README.md)
- [GPIO](../gpio/capstone/README.md)
- [EXTI and NVIC](../exti-nvic/capstone/README.md)
- [Cortex-M](../cortex-m/capstone/README.md)
- [Embedded system design](../system-design/capstone/README.md)
- [Software-timer implementation](../systick/timer_06_capstone/README.md)

Each linked guide records whether it contains firmware or only a plan.

## Integrated platform capstone

**Status:** Planned. Combine ADC acquisition, DMA transfers, UART telemetry, SPI/I2C devices, hardware timer scheduling, SysTick timekeeping, and GPIO status/control.

- [ ] Define the board, pin map, timing requirements, and peripheral ownership.
- [ ] Integrate the register-level drivers into one application.
- [ ] Document interrupt priorities, data flow, and error recovery.
- [ ] Record build instructions, hardware tests, and measured results.
