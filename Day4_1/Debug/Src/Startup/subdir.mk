################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Src/Startup/startup_stm32f407vgtx.s 

OBJS += \
./Src/Startup/startup_stm32f407vgtx.o 

S_DEPS += \
./Src/Startup/startup_stm32f407vgtx.d 


# Each subdirectory must supply rules for building sources it contributes
Src/Startup/%.o: ../Src/Startup/%.s Src/Startup/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -DDEBUG -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=soft -mthumb -o "$@" "$<"

clean: clean-Src-2f-Startup

clean-Src-2f-Startup:
	-$(RM) ./Src/Startup/startup_stm32f407vgtx.d ./Src/Startup/startup_stm32f407vgtx.o

.PHONY: clean-Src-2f-Startup

