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
week3_2.lss \

FLASH_IMAGE += \
week3_2.hex \

EEPROM_IMAGE += \
week3_2.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: week3_2.elf secondary-outputs

# Tool invocations
week3_2.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,week3_2.map -mmcu=atmega88p -o "week3_2.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

week3_2.lss: week3_2.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S week3_2.elf  >"week3_2.lss"
	@echo 'Finished building: $@'
	@echo ' '

week3_2.hex: week3_2.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex week3_2.elf  "week3_2.hex"
	@echo 'Finished building: $@'
	@echo ' '

week3_2.eep: week3_2.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex week3_2.elf  "week3_2.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: week3_2.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega88p week3_2.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) week3_2.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
