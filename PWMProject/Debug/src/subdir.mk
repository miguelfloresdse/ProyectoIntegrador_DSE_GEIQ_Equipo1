################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/PWM_thread_entry.c \
../src/blinky_thread_entry.c \
../src/hal_entry.c 

OBJS += \
./src/PWM_thread_entry.o \
./src/blinky_thread_entry.o \
./src/hal_entry.o 

C_DEPS += \
./src/PWM_thread_entry.d \
./src/blinky_thread_entry.d \
./src/hal_entry.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	C:\Renesas\e2_studio\eclipse\../Utilities/isdebuild arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O2 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal  -g3 -D_RENESAS_SYNERGY_ -I"C:\Users\Cesario\e2_studio\workspace\PWMProject\src" -I"C:\Users\Cesario\e2_studio\workspace\PWMProject\src\synergy_gen" -I"C:\Users\Cesario\e2_studio\workspace\PWMProject\synergy_cfg\ssp_cfg\bsp" -I"C:\Users\Cesario\e2_studio\workspace\PWMProject\synergy_cfg\ssp_cfg\driver" -I"C:\Users\Cesario\e2_studio\workspace\PWMProject\synergy\ssp\inc" -I"C:\Users\Cesario\e2_studio\workspace\PWMProject\synergy\ssp\inc\bsp" -I"C:\Users\Cesario\e2_studio\workspace\PWMProject\synergy\ssp\inc\bsp\cmsis\Include" -I"C:\Users\Cesario\e2_studio\workspace\PWMProject\synergy\ssp\inc\driver\api" -I"C:\Users\Cesario\e2_studio\workspace\PWMProject\synergy\ssp\inc\driver\instances" -I"C:\Users\Cesario\e2_studio\workspace\PWMProject\synergy_cfg\ssp_cfg\framework\el" -I"C:\Users\Cesario\e2_studio\workspace\PWMProject\synergy\ssp\inc\framework\el" -I"C:\Users\Cesario\e2_studio\workspace\PWMProject\synergy\ssp\src\framework\el\tx" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" -x c "$<"
	@echo 'Finished building: $<'
	@echo ' '


