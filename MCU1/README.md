# MCU1 — STM32 Bare-Metal Embedded Firmware Portfolio

[Back to the firmware portfolio](../README.md)

This directory organizes the MCU1 learning path across STM32F407 and
STM32F446RE projects. Topics are at different stages of consolidation;
numbered folders describe the curriculum, not a completion checklist.

## Included work

- [GPIO](01_GPIO/README.md): source projects and detailed hardware-debugging
  notes, with the existing stage collection under `capstone/`.
- [Timers and SysTick](03_SysTick_SoftwareTimers/README.md): six source
  snapshots and design notes; full standalone build projects are not yet
  included in these timer folders.
- [UART](05_UART/README.md): four exercises, a NUCLEO-F446RE command-console
  capstone, a Makefile, and [architecture notes](05_UART/docs/ARCHITECTURE.md).

## Planned or not yet consolidated

These folders currently contain planning documentation, not standalone
firmware implementations:

- [EXTI and NVIC](02_EXTI_NVIC/capstone/README.md)
- [Hardware timer capstone](04_HardwareTimers/capstone/README.md)
- [SPI](06_SPI/capstone/README.md)
- [I2C](07_I2C/capstone/README.md)
- [ADC](08_ADC/capstone/README.md)
- [DMA](09_DMA/capstone/README.md)
- [Cortex-M](10_Cortex_M/capstone/README.md)
- [RTOS](11_RTOS/capstone/README.md)
- [Embedded system design](12_Embedded_System_Design/capstone/README.md)

TIM2 polling and interrupt examples already live in the timers/SysTick
module; the separate hardware-timer capstone remains a planning document.

## Structure

```text
MCU1/
├── 01_GPIO/
├── 02_EXTI_NVIC/
├── 03_SysTick_SoftwareTimers/
├── 04_HardwareTimers/
├── 05_UART/
├── 06_SPI/
├── 07_I2C/
├── 08_ADC/
├── 09_DMA/
├── 10_Cortex_M/
├── 11_RTOS/
└── 12_Embedded_System_Design/
```

## Topic convention

The intended shape for new standalone capstones is:

```text
<topic>/capstone/
├── README.md
├── Inc/
├── Src/
├── Startup/          (when required)
├── docs/
└── tests/            (when practical)
```

UART uses `<topic>/exercises/` for its learning sequence and `capstone/`
for its final application. GPIO retains its existing stage collection under
`capstone/`; timer snapshots retain their `timer_01_*` through `timer_06_*`
directories. Consult the module README for the actual layout.

Add implementation and validation notes as each topic is consolidated.
Generated build output (`Debug/`, `.elf`, `.o`, `.d`, `.map`, etc.) should
not be committed.

## Hardware targets

- Most existing MCU1 topics target STM32F407VGT6 on STM32F4DISCOVERY.
- The UART capstone targets STM32F446RETx on NUCLEO-F446RE.
- All projects use ARM Cortex-M4 and register-level, bare-metal C.
- STM32CubeIDE is the primary IDE; project-specific build instructions live
  beside the corresponding source.

## Learning flow

GPIO → EXTI/NVIC → SysTick/software timers → hardware timers → UART → SPI/I2C → ADC → DMA → Cortex-M → RTOS → system design.
