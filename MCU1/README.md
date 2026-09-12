# MCU1 — STM32 Bare-Metal Embedded Firmware Portfolio

This directory is the structured home for the MCU1 learning path on STM32F407 / STM32F4DISCOVERY.

Each topic has one focused capstone project. Individual exercises remain useful
for learning, but the capstone is the portfolio-quality deliverable for that
topic.

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

Every completed topic follows this shape:

```text
<topic>/capstone/
├── README.md
├── Inc/
├── Src/
├── Startup/          (when required)
├── docs/
└── tests/            (when practical)
```

When a topic includes a learning sequence, its earlier experiments live under
`<topic>/exercises/`. UART is the first topic using this expanded structure.

The code will be added as each topic is completed and hardware-tested. Generated build output (`Debug/`, `.elf`, `.o`, `.d`, `.map`, etc.) should not be committed.

## Hardware targets

- Most existing MCU1 topics target STM32F407VGT6 on STM32F4DISCOVERY.
- The UART capstone targets STM32F446RETx on NUCLEO-F446RE.
- All projects use ARM Cortex-M4 and register-level, bare-metal C.
- STM32CubeIDE is the primary IDE; project-specific build instructions live
  beside the corresponding source.

## Learning flow

GPIO → EXTI/NVIC → SysTick/software timers → hardware timers → UART → SPI/I2C → ADC → DMA → Cortex-M → RTOS → system design.
