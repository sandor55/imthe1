################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
week2_3-1.lss \

FLASH_IMAGE += \
week2_3-1.hex \

EEPROM_IMAGE += \
week2_3-1.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: week2_3-1.elf secondary-outputs

# Tool invocations
week2_3-1.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,week2_3-1.map -mmcu=atmega88p -o "week2_3-1.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

week2_3-1.lss: week2_3-1.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S week2_3-1.elf  >"week2_3-1.lss"
	@echo 'Finished building: $@'
	@echo ' '

week2_3-1.hex: week2_3-1.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex week2_3-1.elf  "week2_3-1.hex"
	@echo 'Finished building: $@'
	@echo ' '

week2_3-1.eep: week2_3-1.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex week2_3-1.elf  "week2_3-1.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: week2_3-1.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega88p week2_3-1.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) week2_3-1.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
