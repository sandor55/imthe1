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
Eindopdracht.lss \

FLASH_IMAGE += \
Eindopdracht.hex \

EEPROM_IMAGE += \
Eindopdracht.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: Eindopdracht.elf secondary-outputs

# Tool invocations
Eindopdracht.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Eindopdracht.map -mmcu=atmega88 -o "Eindopdracht.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Eindopdracht.lss: Eindopdracht.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Eindopdracht.elf  >"Eindopdracht.lss"
	@echo 'Finished building: $@'
	@echo ' '

Eindopdracht.hex: Eindopdracht.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Eindopdracht.elf  "Eindopdracht.hex"
	@echo 'Finished building: $@'
	@echo ' '

Eindopdracht.eep: Eindopdracht.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex Eindopdracht.elf  "Eindopdracht.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Eindopdracht.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega88 Eindopdracht.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Eindopdracht.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
