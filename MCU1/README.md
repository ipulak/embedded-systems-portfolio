# MCU1 — Embedded Systems Portfolio

[Repository overview](../README.md)

Eight ordered sections, from register-level STM32 firmware to a Linux BSP. Every section has a `capstone/` directory. Numbering describes learning order, not completion.

## Learning path

1. [STM32 Bare-Metal Platform](01-stm32-baremetal-platform/README.md) — Register-level drivers and peripheral integration.
2. [FreeRTOS Telemetry System](02-freertos-telemetry-system/README.md) — Task-based acquisition, telemetry, diagnostics, and synchronization.
3. [Zephyr Platform](03-zephyr-platform/README.md) — Board configuration, devicetree, drivers, and a Zephyr application.
4. [STM32 Board Bring-Up](04-stm32-board-bringup/README.md) — Power, clocks, reset, SWD, memory, and peripheral validation.
5. [STM32 Bootloader](05-stm32-bootloader/README.md) — Image layout, application handoff, firmware updates, and recovery.
6. [Embedded Linux Bring-Up](06-embedded-linux-bringup/README.md) — Boot chain, kernel, devicetree, root filesystem, and board validation.
7. [Linux Device Driver](07-linux-device-driver/README.md) — Kernel modules, device interfaces, interrupts, and driver validation.
8. [Mini BSP with Yocto](08-mini-bsp-yocto/README.md) — A board-support layer, image recipes, and reproducible image builds.

The bare-metal section contains existing firmware and five imported ADC/timer projects. The FreeRTOS section preserves the earlier RTOS capstone plan. Sections 03–08 are scaffolds; implementations and hardware validation remain to be added.

## Importing existing projects

Import each directory containing `.project` into STM32CubeIDE. Re-import projects from their new paths if your workspace referenced the old locations. Existing peripheral capstones remain with their modules; the bare-metal capstone index links to all of them.
