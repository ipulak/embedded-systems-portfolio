# UART Command Console Capstone

The final bare-metal UART project for this module.

Target: NUCLEO-F446RE / STM32F446RETx.

The implementation uses USART2 with polling TX, interrupt-driven RX, a
single-producer/single-consumer ring buffer, and a foreground command parser.
Build from the parent `05_UART` directory with `make`.

For the full design rationale, see `../docs/ARCHITECTURE.md`.
