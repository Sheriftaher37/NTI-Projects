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
STEPPER\ MOTOR.lss \

FLASH_IMAGE += \
STEPPER\ MOTOR.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: STEPPER\ MOTOR.elf secondary-outputs

# Tool invocations
STEPPER\ MOTOR.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,STEPPER MOTOR.map -mmcu=atmega32 -o "STEPPER MOTOR.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

STEPPER\ MOTOR.lss: STEPPER\ MOTOR.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S STEPPER MOTOR.elf  >"STEPPER MOTOR.lss"
	@echo 'Finished building: $@'
	@echo ' '

STEPPER\ MOTOR.hex: STEPPER\ MOTOR.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex STEPPER MOTOR.elf  "STEPPER MOTOR.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: STEPPER\ MOTOR.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 STEPPER MOTOR.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) "STEPPER MOTOR.elf"
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
