# UART Architecture and Design Notes

## Scope and targets

This UART module contains a progression of independent labs. Labs 1–4 retain
their original STM32F407VGTx startup files, linker scripts, and register
headers. They should be built and flashed only for that target.

Lab 5 is the final portfolio project and targets the NUCLEO-F446RE with an
STM32F446RETx. Its stale F407-named register header has been renamed and its
documentation retargeted; it is not an F407 project.

## Final capstone data flow

```text
Host terminal
  → ST-LINK virtual COM port
  → USART2 RX on PA3
  → RXNE interrupt
  → USART2_IRQHandler
  → 64-byte RX ring buffer
  → foreground main loop
  → command parser
  → GPIO driver
  → LD2 on PA5
```

The transmit path is intentionally simpler:

```text
printf
  → __io_putchar
  → uart2_write
  → wait for TXE
  → USART2 data register
  → PA2 / ST-LINK virtual COM port
```

## Module responsibilities

Within `capstone/`, `Src/main.c` contains the foreground application loop and command parser. It
does not manipulate UART buffer indexes or GPIO registers directly.

Within `capstone/`, `Src/uart.c` configures USART2, provides blocking transmit, captures receive
bytes in the ISR, records hardware error status, and exposes a non-blocking
read API.

Within `capstone/`, `Src/gpio.c` configures PA2 and PA3 for USART2 alternate function 7, configures
PA5 for LD2 output, and exposes LED operations to the application.

Within `capstone/`, `Inc/stm32f446xx_reg.h` contains only the register definitions required by the
capstone. Startup code and linker scripts establish the device-specific memory
layout and interrupt vector table.

## Receive-buffer design

The ISR is the sole producer and advances `head`; foreground code is the sole
consumer and advances `tail`. A 64-byte array reserves one slot so
`head == tail` remains an unambiguous empty condition. Therefore the usable
capacity is 63 bytes.

When the next head position equals `tail`, new data is discarded and
`rx_overflow` is set. This explicit drop-newest policy preserves bytes the
application has not yet consumed.

The driver also records parity, framing, noise, and hardware-overrun status.
Those conditions originate in the USART itself and are distinct from software
ring-buffer overflow.

## Concurrency rationale

The buffer indexes are `volatile` because they are observed in both interrupt
and foreground contexts. `volatile` alone is not general synchronization; this
design works because it is single-producer/single-consumer and each context
owns one index.

The ISR performs only receive/error handling and buffer insertion. Formatting,
command parsing, and polling TX stay in foreground context, limiting interrupt
latency.

## Scaling path

Polling TX is appropriate for the current low-rate interactive console. A
higher-throughput design could add a TX queue and TX-empty interrupt, or use
DMA. DMA would also be a natural next step for continuous high-rate receive.
