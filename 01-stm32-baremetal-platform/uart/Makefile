LAB ?= capstone
BUILD_DIR := build/$(LAB)

VALID_LABS := 01_tx_polling 02_modular_tx_driver 03_blocking_rxtx_led_control 04_interrupt_rx_console capstone
ifeq ($(filter $(LAB),$(VALID_LABS)),)
$(error Unknown LAB '$(LAB)'. Run 'make list' to see valid values.)
endif

ifeq ($(LAB),capstone)
LAB_DIR := capstone
MCU_DEFINE := -DSTM32F446RETx -DNUCLEO_F446RE
LINKER_SCRIPT := $(LAB_DIR)/STM32F446RETX_FLASH.ld
else
LAB_DIR := exercises/$(LAB)
MCU_DEFINE := -DSTM32F407VGTx
LINKER_SCRIPT := $(LAB_DIR)/STM32F407VGTX_FLASH.ld
endif

# Prefer the system Arm GNU Toolchain when present; otherwise use the standard
# arm-none-eabi- prefix from PATH. Override TOOLCHAIN_PREFIX if needed.
TOOLCHAIN_BIN ?= $(dir $(lastword $(wildcard /Applications/ArmGNUToolchain/*/arm-none-eabi/bin/arm-none-eabi-gcc)))
TOOLCHAIN_PREFIX ?= $(TOOLCHAIN_BIN)arm-none-eabi-
CC := $(TOOLCHAIN_PREFIX)gcc
OBJCOPY := $(TOOLCHAIN_PREFIX)objcopy
SIZE := $(TOOLCHAIN_PREFIX)size

CPU := -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=hard
CFLAGS := $(CPU) -std=gnu11 -g3 -O0 -Wall -Wextra -ffunction-sections -fdata-sections -I$(LAB_DIR)/Inc
LDFLAGS := $(CPU) --specs=nosys.specs --specs=nano.specs -Wl,--gc-sections -Wl,-Map=$(BUILD_DIR)/$(LAB).map

C_SOURCES := $(wildcard $(LAB_DIR)/Src/*.c)
ASM_SOURCES := $(wildcard $(LAB_DIR)/Startup/*.s)
OBJECTS := $(patsubst $(LAB_DIR)/%.c,$(BUILD_DIR)/%.o,$(C_SOURCES)) \
           $(patsubst $(LAB_DIR)/%.s,$(BUILD_DIR)/%.o,$(ASM_SOURCES))
DEPS := $(OBJECTS:.o=.d)

.PHONY: all clean flash list

all: $(BUILD_DIR)/$(LAB).elf $(BUILD_DIR)/$(LAB).bin

list:
	@printf '%s\n' $(VALID_LABS)

$(BUILD_DIR)/%.o: $(LAB_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(MCU_DEFINE) -MMD -MP -c $< -o $@

$(BUILD_DIR)/%.o: $(LAB_DIR)/%.s
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(MCU_DEFINE) -c $< -o $@

$(BUILD_DIR)/$(LAB).elf: $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -T$(LINKER_SCRIPT) -o $@
	$(SIZE) $@

$(BUILD_DIR)/$(LAB).bin: $(BUILD_DIR)/$(LAB).elf
	$(OBJCOPY) -O binary $< $@

flash: $(BUILD_DIR)/$(LAB).elf
	STM32_Programmer_CLI -c port=SWD -w $< -v -rst

clean:
	rm -rf build

-include $(DEPS)
