################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/AUDIO.c \
../Core/Src/AUDIO_LINK.c \
../Core/Src/File_Handling.c \
../Core/Src/HAL_ESP8266.c \
../Core/Src/cs43l22.c \
../Core/Src/main.c \
../Core/Src/stm32f4xx_hal_msp.c \
../Core/Src/stm32f4xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32f4xx.c \
../Core/Src/uart.c \
../Core/Src/waveplayer.c 

OBJS += \
./Core/Src/AUDIO.o \
./Core/Src/AUDIO_LINK.o \
./Core/Src/File_Handling.o \
./Core/Src/HAL_ESP8266.o \
./Core/Src/cs43l22.o \
./Core/Src/main.o \
./Core/Src/stm32f4xx_hal_msp.o \
./Core/Src/stm32f4xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32f4xx.o \
./Core/Src/uart.o \
./Core/Src/waveplayer.o 

C_DEPS += \
./Core/Src/AUDIO.d \
./Core/Src/AUDIO_LINK.d \
./Core/Src/File_Handling.d \
./Core/Src/HAL_ESP8266.d \
./Core/Src/cs43l22.d \
./Core/Src/main.d \
./Core/Src/stm32f4xx_hal_msp.d \
./Core/Src/stm32f4xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32f4xx.d \
./Core/Src/uart.d \
./Core/Src/waveplayer.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su Core/Src/%.cyclo: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../FATFS/Target -I../FATFS/App -I../USB_HOST/App -I../USB_HOST/Target -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FatFs/src -I../Middlewares/ST/STM32_USB_Host_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Host_Library/Class/MSC/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/STM32Project/TUT_F4_AUDIO_I2S/chip_headers/CMSIS/Device/ST/STM32F4xx/Include" -I"D:/STM32Project/TUT_F4_AUDIO_I2S/chip_headers/CMSIS/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/AUDIO.cyclo ./Core/Src/AUDIO.d ./Core/Src/AUDIO.o ./Core/Src/AUDIO.su ./Core/Src/AUDIO_LINK.cyclo ./Core/Src/AUDIO_LINK.d ./Core/Src/AUDIO_LINK.o ./Core/Src/AUDIO_LINK.su ./Core/Src/File_Handling.cyclo ./Core/Src/File_Handling.d ./Core/Src/File_Handling.o ./Core/Src/File_Handling.su ./Core/Src/HAL_ESP8266.cyclo ./Core/Src/HAL_ESP8266.d ./Core/Src/HAL_ESP8266.o ./Core/Src/HAL_ESP8266.su ./Core/Src/cs43l22.cyclo ./Core/Src/cs43l22.d ./Core/Src/cs43l22.o ./Core/Src/cs43l22.su ./Core/Src/main.cyclo ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/stm32f4xx_hal_msp.cyclo ./Core/Src/stm32f4xx_hal_msp.d ./Core/Src/stm32f4xx_hal_msp.o ./Core/Src/stm32f4xx_hal_msp.su ./Core/Src/stm32f4xx_it.cyclo ./Core/Src/stm32f4xx_it.d ./Core/Src/stm32f4xx_it.o ./Core/Src/stm32f4xx_it.su ./Core/Src/syscalls.cyclo ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.cyclo ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32f4xx.cyclo ./Core/Src/system_stm32f4xx.d ./Core/Src/system_stm32f4xx.o ./Core/Src/system_stm32f4xx.su ./Core/Src/uart.cyclo ./Core/Src/uart.d ./Core/Src/uart.o ./Core/Src/uart.su ./Core/Src/waveplayer.cyclo ./Core/Src/waveplayer.d ./Core/Src/waveplayer.o ./Core/Src/waveplayer.su

.PHONY: clean-Core-2f-Src

