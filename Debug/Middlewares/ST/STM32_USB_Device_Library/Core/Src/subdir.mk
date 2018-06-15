################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_core.c \
../Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ctlreq.c \
../Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ioreq.c 

OBJS += \
./Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_core.o \
./Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ctlreq.o \
./Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ioreq.o 

C_DEPS += \
./Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_core.d \
./Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ctlreq.d \
./Middlewares/ST/STM32_USB_Device_Library/Core/Src/usbd_ioreq.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/ST/STM32_USB_Device_Library/Core/Src/%.o: ../Middlewares/ST/STM32_USB_Device_Library/Core/Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F407xx -I"C:/Warehouse/Embedded/STM32Cube_FW_F4/MyProjects/FreeRTOS_USB_F407/Embedded_Web/Inc" -I"C:/Warehouse/Embedded/STM32Cube_FW_F4/MyProjects/FreeRTOS_USB_F407/Embedded_Web/Web-server/inc" -I"C:/Warehouse/Embedded/STM32Cube_FW_F4/MyProjects/FreeRTOS_USB_F407/Embedded_Web/Middlewares/Third_Party/LwIP/src/include" -I"C:/Warehouse/Embedded/STM32Cube_FW_F4/MyProjects/FreeRTOS_USB_F407/Embedded_Web/Middlewares/Third_Party/LwIP/system" -I"C:/Warehouse/Embedded/STM32Cube_FW_F4/MyProjects/FreeRTOS_USB_F407/Embedded_Web/Drivers/STM32F4xx_HAL_Driver/Inc" -I"C:/Warehouse/Embedded/STM32Cube_FW_F4/MyProjects/FreeRTOS_USB_F407/Embedded_Web/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"C:/Warehouse/Embedded/STM32Cube_FW_F4/MyProjects/FreeRTOS_USB_F407/Embedded_Web/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"C:/Warehouse/Embedded/STM32Cube_FW_F4/MyProjects/FreeRTOS_USB_F407/Embedded_Web/Middlewares/Third_Party/LwIP/src/include/netif/ppp" -I"C:/Warehouse/Embedded/STM32Cube_FW_F4/MyProjects/FreeRTOS_USB_F407/Embedded_Web/Middlewares/Third_Party/LwIP/src/apps/httpd" -I"C:/Warehouse/Embedded/STM32Cube_FW_F4/MyProjects/FreeRTOS_USB_F407/Embedded_Web/Middlewares/ST/STM32_USB_Device_Library/Core/Inc" -I"C:/Warehouse/Embedded/STM32Cube_FW_F4/MyProjects/FreeRTOS_USB_F407/Embedded_Web/Middlewares/ST/STM32_USB_Device_Library/Class/CDC/Inc" -I"C:/Warehouse/Embedded/STM32Cube_FW_F4/MyProjects/FreeRTOS_USB_F407/Embedded_Web/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"C:/Warehouse/Embedded/STM32Cube_FW_F4/MyProjects/FreeRTOS_USB_F407/Embedded_Web/Middlewares/Third_Party/FreeRTOS/Source/include" -I"C:/Warehouse/Embedded/STM32Cube_FW_F4/MyProjects/FreeRTOS_USB_F407/Embedded_Web/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"C:/Warehouse/Embedded/STM32Cube_FW_F4/MyProjects/FreeRTOS_USB_F407/Embedded_Web/Middlewares/Third_Party/LwIP/src/include/lwip" -I"C:/Warehouse/Embedded/STM32Cube_FW_F4/MyProjects/FreeRTOS_USB_F407/Embedded_Web/Middlewares/Third_Party/LwIP/src/include/lwip/apps" -I"C:/Warehouse/Embedded/STM32Cube_FW_F4/MyProjects/FreeRTOS_USB_F407/Embedded_Web/Middlewares/Third_Party/LwIP/src/include/lwip/priv" -I"C:/Warehouse/Embedded/STM32Cube_FW_F4/MyProjects/FreeRTOS_USB_F407/Embedded_Web/Middlewares/Third_Party/LwIP/src/include/lwip/prot" -I"C:/Warehouse/Embedded/STM32Cube_FW_F4/MyProjects/FreeRTOS_USB_F407/Embedded_Web/Middlewares/Third_Party/LwIP/src/include/netif" -I"C:/Warehouse/Embedded/STM32Cube_FW_F4/MyProjects/FreeRTOS_USB_F407/Embedded_Web/Middlewares/Third_Party/LwIP/src/include/posix" -I"C:/Warehouse/Embedded/STM32Cube_FW_F4/MyProjects/FreeRTOS_USB_F407/Embedded_Web/Middlewares/Third_Party/LwIP/src/include/posix/sys" -I"C:/Warehouse/Embedded/STM32Cube_FW_F4/MyProjects/FreeRTOS_USB_F407/Embedded_Web/Middlewares/Third_Party/LwIP/system/arch" -I"C:/Warehouse/Embedded/STM32Cube_FW_F4/MyProjects/FreeRTOS_USB_F407/Embedded_Web/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


