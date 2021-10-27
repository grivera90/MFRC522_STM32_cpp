################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../cpp_application/LED.cpp 

OBJS += \
./cpp_application/LED.o 

CPP_DEPS += \
./cpp_application/LED.d 


# Each subdirectory must supply rules for building sources it contributes
cpp_application/%.o: ../cpp_application/%.cpp cpp_application/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m3 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Asus-TUF/Datos/Firmware/github_gonzalo/MFRC522_STM32_cpp/cpp_application" -I"C:/Users/Asus-TUF/Datos/Firmware/github_gonzalo/MFRC522_STM32_cpp/mfrc522" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

