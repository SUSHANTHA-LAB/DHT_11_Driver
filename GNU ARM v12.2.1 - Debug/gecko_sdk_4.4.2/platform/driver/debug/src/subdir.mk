################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../gecko_sdk_4.4.2/platform/driver/debug/src/sl_debug_swo.c 

OBJS += \
./gecko_sdk_4.4.2/platform/driver/debug/src/sl_debug_swo.o 

C_DEPS += \
./gecko_sdk_4.4.2/platform/driver/debug/src/sl_debug_swo.d 


# Each subdirectory must supply rules for building sources it contributes
gecko_sdk_4.4.2/platform/driver/debug/src/sl_debug_swo.o: ../gecko_sdk_4.4.2/platform/driver/debug/src/sl_debug_swo.c gecko_sdk_4.4.2/platform/driver/debug/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m33 -mthumb -std=c99 '-DDEBUG=1' '-DDEBUG_EFM=1' '-DEFR32MG22C224F512IM40=1' '-DSL_BOARD_NAME="BRD4182A"' '-DSL_BOARD_REV="B06"' '-DHARDWARE_BOARD_DEFAULT_RF_BAND_2400=1' '-DHARDWARE_BOARD_SUPPORTS_1_RF_BAND=1' '-DHARDWARE_BOARD_SUPPORTS_RF_BAND_2400=1' '-DHFXO_FREQ=38400000' '-DSL_COMPONENT_CATALOG_PRESENT=1' -I"C:\Users\susha\SimplicityStudio\v5_workspace\DHT_11_Driver\config" -I"C:\Users\susha\SimplicityStudio\v5_workspace\DHT_11_Driver\autogen" -I"C:\Users\susha\SimplicityStudio\v5_workspace\DHT_11_Driver" -I"C:\Users\susha\SimplicityStudio\v5_workspace\DHT_11_Driver\gecko_sdk_4.4.2\platform\Device\SiliconLabs\EFR32MG22\Include" -I"C:\Users\susha\SimplicityStudio\v5_workspace\DHT_11_Driver\gecko_sdk_4.4.2\platform\common\inc" -I"C:\Users\susha\SimplicityStudio\v5_workspace\DHT_11_Driver\gecko_sdk_4.4.2\hardware\board\inc" -I"C:\Users\susha\SimplicityStudio\v5_workspace\DHT_11_Driver\gecko_sdk_4.4.2\platform\CMSIS\Core\Include" -I"C:\Users\susha\SimplicityStudio\v5_workspace\DHT_11_Driver\gecko_sdk_4.4.2\hardware\driver\configuration_over_swo\inc" -I"C:\Users\susha\SimplicityStudio\v5_workspace\DHT_11_Driver\gecko_sdk_4.4.2\platform\driver\debug\inc" -I"C:\Users\susha\SimplicityStudio\v5_workspace\DHT_11_Driver\gecko_sdk_4.4.2\platform\service\device_init\inc" -I"C:\Users\susha\SimplicityStudio\v5_workspace\DHT_11_Driver\gecko_sdk_4.4.2\platform\emdrv\dmadrv\inc" -I"C:\Users\susha\SimplicityStudio\v5_workspace\DHT_11_Driver\gecko_sdk_4.4.2\platform\emdrv\common\inc" -I"C:\Users\susha\SimplicityStudio\v5_workspace\DHT_11_Driver\gecko_sdk_4.4.2\platform\emlib\inc" -I"C:\Users\susha\SimplicityStudio\v5_workspace\DHT_11_Driver\gecko_sdk_4.4.2\platform\service\iostream\inc" -I"C:\Users\susha\SimplicityStudio\v5_workspace\DHT_11_Driver\gecko_sdk_4.4.2\hardware\driver\mx25_flash_shutdown\inc\sl_mx25_flash_shutdown_usart" -I"C:\Users\susha\SimplicityStudio\v5_workspace\DHT_11_Driver\gecko_sdk_4.4.2\util\third_party\printf" -I"C:\Users\susha\SimplicityStudio\v5_workspace\DHT_11_Driver\gecko_sdk_4.4.2\util\third_party\printf\inc" -I"C:\Users\susha\SimplicityStudio\v5_workspace\DHT_11_Driver\gecko_sdk_4.4.2\platform\common\toolchain\inc" -I"C:\Users\susha\SimplicityStudio\v5_workspace\DHT_11_Driver\gecko_sdk_4.4.2\platform\service\system\inc" -I"C:\Users\susha\SimplicityStudio\v5_workspace\DHT_11_Driver\gecko_sdk_4.4.2\platform\service\udelay\inc" -Os -Wall -Wextra -mno-sched-prolog -fno-builtin -ffunction-sections -fdata-sections -imacrossl_gcc_preinclude.h -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mcmse -fno-builtin-printf -fno-builtin-sprintf --specs=nano.specs -c -fmessage-length=0 -MMD -MP -MF"gecko_sdk_4.4.2/platform/driver/debug/src/sl_debug_swo.d" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


