################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Generated_Code/ASerialLdd1.c \
../Generated_Code/Blue.c \
../Generated_Code/Cpu.c \
../Generated_Code/Green.c \
../Generated_Code/Inhr1.c \
../Generated_Code/PE_LDD.c \
../Generated_Code/Pins1.c \
../Generated_Code/PwmLdd1.c \
../Generated_Code/PwmLdd2.c \
../Generated_Code/PwmLdd3.c \
../Generated_Code/RED.c \
../Generated_Code/TU1.c \
../Generated_Code/Term1.c 

OBJS += \
./Generated_Code/ASerialLdd1.o \
./Generated_Code/Blue.o \
./Generated_Code/Cpu.o \
./Generated_Code/Green.o \
./Generated_Code/Inhr1.o \
./Generated_Code/PE_LDD.o \
./Generated_Code/Pins1.o \
./Generated_Code/PwmLdd1.o \
./Generated_Code/PwmLdd2.o \
./Generated_Code/PwmLdd3.o \
./Generated_Code/RED.o \
./Generated_Code/TU1.o \
./Generated_Code/Term1.o 

C_DEPS += \
./Generated_Code/ASerialLdd1.d \
./Generated_Code/Blue.d \
./Generated_Code/Cpu.d \
./Generated_Code/Green.d \
./Generated_Code/Inhr1.d \
./Generated_Code/PE_LDD.d \
./Generated_Code/Pins1.d \
./Generated_Code/PwmLdd1.d \
./Generated_Code/PwmLdd2.d \
./Generated_Code/PwmLdd3.d \
./Generated_Code/RED.d \
./Generated_Code/TU1.d \
./Generated_Code/Term1.d 


# Each subdirectory must supply rules for building sources it contributes
Generated_Code/%.o: ../Generated_Code/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"C:/Users/jc259420/Desktop/Lab 7/LAb7/Static_Code/System" -I"C:/Users/jc259420/Desktop/Lab 7/LAb7/Static_Code/PDD" -I"C:/Users/jc259420/Desktop/Lab 7/LAb7/Static_Code/IO_Map" -I"C:\Freescale\KDS_3.0.0\eclipse\ProcessorExpert/lib/Kinetis/pdd/inc" -I"C:/Users/jc259420/Desktop/Lab 7/LAb7/Sources" -I"C:/Users/jc259420/Desktop/Lab 7/LAb7/Generated_Code" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


