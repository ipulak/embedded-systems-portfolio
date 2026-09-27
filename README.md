# Embedded Systems Portfolio

An embedded C learning portfolio progressing from STM32 register-level drivers to RTOS applications, board bring-up, bootloaders, Linux drivers, and Yocto BSP work.

## Repository structure

```text
embedded-systems-portfolio/
├── 01-stm32-baremetal-platform/
│   ├── adc/
│   ├── dma/
│   ├── uart/
│   ├── spi/
│   ├── i2c/
│   ├── hardware-timers/
│   ├── systick/
│   ├── gpio/
│   ├── exti-nvic/
│   ├── cortex-m/
│   ├── system-design/
│   └── capstone/
├── 02-freertos-telemetry-system/
│   └── capstone/
├── 03-zephyr-platform/
│   └── capstone/
├── 04-stm32-board-bringup/
│   └── capstone/
├── 05-stm32-bootloader/
│   └── capstone/
├── 06-embedded-linux-bringup/
│   └── capstone/
├── 07-linux-device-driver/
│   └── capstone/
└── 08-mini-bsp-yocto/
    └── capstone/
```

Start with the [Portfolio learning path](LEARNING_PATH.md) or the [bare-metal platform](01-stm32-baremetal-platform/README.md). Every numbered section has a capstone directory. Existing peripheral capstones are indexed from the platform capstone guide.

## Current implementation

The bare-metal section includes GPIO projects, timer/SysTick source snapshots, UART exercises and a command-console capstone, plus two ADC and three hardware-timer CubeIDE projects. Several peripheral integrations are still plans. FreeRTOS preserves the earlier RTOS plan, and sections 03–08 are scaffolds. Folder presence does not indicate completion.

## Getting started

```sh
git clone https://github.com/ipulak/embedded-systems-portfolio.git
cd embedded-systems-portfolio
```

Import individual directories containing `.project` into STM32CubeIDE. Projects moved from the former numbered peripheral folders must be re-imported at their new locations. There is no repository-wide firmware build.

For the UART capstone, with Make and the Arm GNU toolchain installed:

```sh
cd 01-stm32-baremetal-platform/uart
make list
make
```

See the [UART guide](01-stm32-baremetal-platform/uart/README.md) for exercise selection and flashing instructions.

## Hardware and validation

Targets are project-specific: existing GPIO and imported hardware-timer projects use STM32F407 configurations; imported ADC projects and the UART capstone use STM32F446RE configurations. Check the startup file, linker script, configuration, and wiring for each project.

Reorganizing files does not validate firmware on hardware. Record build and board-test results beside each project. Generated build output and IDE workspace caches should remain untracked.

## Author

Pulak Mukherjee — embedded firmware learning and portfolio work.
