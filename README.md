# STM32 Bare-Metal Firmware

A register-level embedded C learning portfolio for STM32 Cortex-M4
microcontrollers. Projects explore peripheral configuration, interrupt
handling, timing, hardware debugging, and the separation of driver code
from application behavior.

This is a collection of independent firmware projects, not a single
application or a production-ready driver library. Detailed design notes,
hardware assumptions, and usage instructions belong to each module.

## Explore the projects

- [GPIO drivers and hardware debugging](MCU1/01_GPIO/README.md) — LED
  output, button input, blocking debounce, ODR/BSRR operations, and
  fault-injection notes. Includes STM32CubeIDE source projects.
- [Timers and SysTick](MCU1/03_SysTick_SoftwareTimers/README.md) — six
  source-and-documentation stages covering TIM2 polling and interrupts,
  SysTick, and a software-timer capstone. These are source snapshots;
  the timer folders do not yet contain full standalone build projects.
- [UART drivers and command console](MCU1/05_UART/README.md) — four
  exercises and a NUCLEO-F446RE capstone, with STM32CubeIDE project files
  and a module-level Makefile.
  Start with the [capstone](MCU1/05_UART/capstone/README.md) or its
  [architecture document](MCU1/05_UART/docs/ARCHITECTURE.md).

See the [MCU1 index](MCU1/README.md) for the full learning path. The
remaining topic folders currently contain planning notes rather than
standalone firmware implementations; a folder's presence does not mean
that module is complete.

## Repository layout

```text
stm32-bare-metal-firmware/
├── README.md                         # portfolio overview
└── MCU1/
    ├── README.md                     # module index and roadmap
    ├── 01_GPIO/                      # GPIO projects and detailed README
    ├── 02_EXTI_NVIC/                 # planning notes
    ├── 03_SysTick_SoftwareTimers/     # timer source snapshots and notes
    ├── 04_HardwareTimers/            # planning notes
    ├── 05_UART/                      # exercises, capstone, Makefile, docs
    ├── 06_SPI/                       # planning notes
    ├── 07_I2C/                       # planning notes
    ├── 08_ADC/                       # planning notes
    ├── 09_DMA/                       # planning notes
    ├── 10_Cortex_M/                  # planning notes
    ├── 11_RTOS/                      # planning notes
    └── 12_Embedded_System_Design/     # planning notes
```

Directory numbering records the curriculum order, not completion status.
Existing project paths are retained so this documentation change does not
disrupt IDE imports.

## Hardware targets

- **STM32F407 / STM32F4DISCOVERY:** GPIO projects and timer learning
  material. The four UART exercises also retain STM32F407VGTx target
  configurations.
- **STM32F446RE / NUCLEO-F446RE:** the UART command-console capstone.

Target selection is project-specific. Check the module documentation,
startup file, linker script, and board wiring before building or flashing;
do not assume all projects use the same pinout.

## Getting started

Clone the repository:

```sh
git clone https://github.com/ipulak/stm32-bare-metal-firmware.git
cd stm32-bare-metal-firmware
```

For projects with STM32CubeIDE metadata, import the individual project
directory. The repository root is not itself a CubeIDE project and has
no aggregate build target.

For the UART capstone, install Make and the Arm GNU `arm-none-eabi`
toolchain, then run:

```sh
cd MCU1/05_UART
make list
make
```

The default target is the STM32F446RE capstone. `make LAB=<name>` selects
an exercise, and outputs go under the module's ignored `build/` directory.
Flashing uses `make flash` with STM32CubeProgrammer CLI and a connected
ST-LINK; verify the board and selected image first. See the
[UART guide](MCU1/05_UART/README.md) for details.

## Engineering focus

- Trace application behavior to peripheral registers and physical pins.
- Keep interrupt work short and make ISR/foreground data ownership clear.
- Understand polling, interrupt-driven I/O, buffering, and overflow handling.
- Use debugger observations to explain failures and verify corrections.
- Preserve small learning stages alongside more integrated applications.

Build success and hardware validation are different checks. Consult each
module's notes for recorded results and limitations; this repository does
not imply that every exercise has been verified on every listed board.

## Author

Pulak Mukherjee — embedded firmware learning and portfolio work.
