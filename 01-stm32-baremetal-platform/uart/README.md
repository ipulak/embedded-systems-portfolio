# UART Driver Development and Command Console

This module documents a bare-metal UART learning progression from polling TX
to an interrupt-driven command console. The source is structured to keep the
small experiments useful while presenting the final implementation as a
standalone, interview-ready capstone.

## Layout

```text
uart/
├── exercises/
│   ├── 01_tx_polling/
│   ├── 02_modular_tx_driver/
│   ├── 03_blocking_rxtx_led_control/
│   └── 04_interrupt_rx_console/
├── capstone/
│   ├── Inc/
│   ├── Src/
│   ├── Startup/
│   ├── STM32F446RETX_FLASH.ld
│   └── README.md
├── docs/
│   └── ARCHITECTURE.md
└── Makefile
```

## Exercises

- `01_tx_polling` configures USART2 transmit and retargets `printf`.
- `02_modular_tx_driver` moves UART behavior behind a small driver interface.
- `03_blocking_rxtx_led_control` adds receive polling and drives an LED from
  incoming data.
- `04_interrupt_rx_console` introduces RXNE interrupts and an early
  single-byte console.

These four exercises retain their original STM32F407VGTx target configuration.

## Capstone: UART Command Console

The final `capstone/` targets the NUCLEO-F446RE (STM32F446RETx) and provides:

- USART2 at 115200 baud, 8N1
- polling TX and interrupt-driven RX
- a 64-byte RX ring buffer with explicit drop-newest overflow behavior
- hardware UART error capture
- a non-blocking foreground RX API
- LED commands: `led on`, `led off`, `led toggle`, and `status`
- `help` and `echo <text>` commands

See [architecture notes](docs/ARCHITECTURE.md) for the complete data flow and
concurrency rationale.

## Build and flash

Build the capstone:

```sh
make
```

Build an exercise:

```sh
make LAB=04_interrupt_rx_console
```

List available choices with `make list`. Firmware output is written beneath
`build/` and is intentionally not committed. With STM32CubeProgrammer CLI
installed, use `make flash` or `make LAB=<lab> flash` to program the selected
image.
