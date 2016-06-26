################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL := cmd.exe
RM := rm -rf

USER_OBJS :=

LIBS := 
PROJ := 

O_SRCS := 
C_SRCS := 
S_SRCS := 
S_UPPER_SRCS := 
OBJ_SRCS := 
ASM_SRCS := 
PREPROCESSING_SRCS := 
OBJS := 
OBJS_AS_ARGS := 
C_DEPS := 
C_DEPS_AS_ARGS := 
EXECUTABLES := 
OUTPUT_FILE_PATH :=
OUTPUT_FILE_PATH_AS_ARGS :=
AVR_APP_PATH :=$$$AVR_APP_PATH$$$
QUOTE := "
ADDITIONAL_DEPENDENCIES:=
OUTPUT_FILE_DEP:=
LIB_DEP:=
LINKER_SCRIPT_DEP:=

# Every subdirectory with source files must be described here
SUBDIRS :=  \
../header


# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS +=  \
../avr_uart_sender_receiver.cpp \
../coordinator_eeprom_r_slaves.cpp \
../coordinator_installer.cpp \
../coord_installer.cpp \
../coord_slave_comm.cpp \
../cppinit.cpp \
../lcddisplay.cpp \
../ledblinking.cpp \
../main.cpp \
../WirelessMessage.cpp


PREPROCESSING_SRCS += 


ASM_SRCS += 


OBJS +=  \
avr_uart_sender_receiver.o \
coordinator_eeprom_r_slaves.o \
coordinator_installer.o \
coord_installer.o \
coord_slave_comm.o \
cppinit.o \
lcddisplay.o \
ledblinking.o \
main.o \
WirelessMessage.o

OBJS_AS_ARGS +=  \
avr_uart_sender_receiver.o \
coordinator_eeprom_r_slaves.o \
coordinator_installer.o \
coord_installer.o \
coord_slave_comm.o \
cppinit.o \
lcddisplay.o \
ledblinking.o \
main.o \
WirelessMessage.o

C_DEPS +=  \
avr_uart_sender_receiver.d \
coordinator_eeprom_r_slaves.d \
coordinator_installer.d \
coord_installer.d \
coord_slave_comm.d \
cppinit.d \
lcddisplay.d \
ledblinking.d \
main.d \
WirelessMessage.d

C_DEPS_AS_ARGS +=  \
avr_uart_sender_receiver.d \
coordinator_eeprom_r_slaves.d \
coordinator_installer.d \
coord_installer.d \
coord_slave_comm.d \
cppinit.d \
lcddisplay.d \
ledblinking.d \
main.d \
WirelessMessage.d

OUTPUT_FILE_PATH +=scid.elf

OUTPUT_FILE_PATH_AS_ARGS +=scid.elf

ADDITIONAL_DEPENDENCIES:=

OUTPUT_FILE_DEP:= ./makedep.mk

LIB_DEP+= 

LINKER_SCRIPT_DEP+= 


# AVR32/GNU C Compiler





















./%.o: .././%.cpp
	@echo Building file: $<
	@echo Invoking: AVR8/GNU C Compiler : 4.9.2
	$(QUOTE)C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-g++.exe$(QUOTE) -funsigned-char -funsigned-bitfields -DDEBUG -DF_CPU=12000000  -I"C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.0.98\include"  -Os -ffunction-sections -fdata-sections -fshort-enums -g2 -Wall -mmcu=atmega32a -B "C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.0.98\gcc\dev\atmega32a" -c -std=c++11 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	



# AVR32/GNU Preprocessing Assembler



# AVR32/GNU Assembler




ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: $(OUTPUT_FILE_PATH) $(ADDITIONAL_DEPENDENCIES)

$(OUTPUT_FILE_PATH): $(OBJS) $(USER_OBJS) $(OUTPUT_FILE_DEP) $(LIB_DEP) $(LINKER_SCRIPT_DEP)
	@echo Building target: $@
	@echo Invoking: AVR8/GNU Linker : 4.9.2
	$(QUOTE)C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-g++.exe$(QUOTE) -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) -Wl,-Map="scid.map" -Wl,--start-group -Wl,-lm  -Wl,--end-group -Wl,-L"E:\test_avr_comm\avr_comm_vcplus_plus\Debug"  -Wl,--gc-sections -mmcu=atmega32a -B "C:\Program Files (x86)\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.0.98\gcc\dev\atmega32a"  
	@echo Finished building target: $@
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O ihex -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures  "scid.elf" "scid.hex"
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -j .eeprom  --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0  --no-change-warnings -O ihex "scid.elf" "scid.eep" || exit 0
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objdump.exe" -h -S "scid.elf" > "scid.lss"
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O srec -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures "scid.elf" "scid.srec"
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-size.exe" "scid.elf"
	
	





# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS) $(EXECUTABLES)  
	-$(RM) $(C_DEPS_AS_ARGS)   
	rm -rf "scid.elf" "scid.a" "scid.hex" "scid.lss" "scid.eep" "scid.map" "scid.srec" "scid.usersignatures"
	