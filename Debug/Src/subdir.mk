################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/MGPIO_Prog.c \
../Src/MRCC_Prog.c \
../Src/MSTK_Prog.c \
../Src/MUSART_Program.c \
../Src/WIFI_program.c \
../Src/main.c \
../Src/syscalls.c \
../Src/sysmem.c 

OBJS += \
./Src/MGPIO_Prog.o \
./Src/MRCC_Prog.o \
./Src/MSTK_Prog.o \
./Src/MUSART_Program.o \
./Src/WIFI_program.o \
./Src/main.o \
./Src/syscalls.o \
./Src/sysmem.o 

C_DEPS += \
./Src/MGPIO_Prog.d \
./Src/MRCC_Prog.d \
./Src/MSTK_Prog.d \
./Src/MUSART_Program.d \
./Src/WIFI_program.d \
./Src/main.d \
./Src/syscalls.d \
./Src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F401CEUx -DSTM32 -DSTM32F4 -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/MGPIO_Prog.cyclo ./Src/MGPIO_Prog.d ./Src/MGPIO_Prog.o ./Src/MGPIO_Prog.su ./Src/MRCC_Prog.cyclo ./Src/MRCC_Prog.d ./Src/MRCC_Prog.o ./Src/MRCC_Prog.su ./Src/MSTK_Prog.cyclo ./Src/MSTK_Prog.d ./Src/MSTK_Prog.o ./Src/MSTK_Prog.su ./Src/MUSART_Program.cyclo ./Src/MUSART_Program.d ./Src/MUSART_Program.o ./Src/MUSART_Program.su ./Src/WIFI_program.cyclo ./Src/WIFI_program.d ./Src/WIFI_program.o ./Src/WIFI_program.su ./Src/main.cyclo ./Src/main.d ./Src/main.o ./Src/main.su ./Src/syscalls.cyclo ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.cyclo ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su

.PHONY: clean-Src

