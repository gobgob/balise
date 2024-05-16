################################################################################
#                             VAR TO CROSS COMPILE                             #
################################################################################
CROSS?=avr-
CC=$(CROSS)gcc
OBJCOPY=$(CROSS)objcopy
MMCU=atmega328p
FCPU=16000000


################################################################################
#                             VAR TO UPLOAD PROGRAM                            #
################################################################################
MMCUPROG=m328p
## CHOOSE TIME (in us) FOR BIT WHEN PROGRAMMING WITH ISP
#SPEEDPROG=-B1000
SPEEDPROG=
## CHOOSE PROGRAMMER
#PROGRAMMER=-c usbtiny $(SPEEDPROG)
#PROGRAMMER=-c usbasp $(SPEEDPROG)
PROGRAMMER=-P /dev/ttyUSB0 -c stk500v1 -b 57600
LOW_FUSE=0xbf
HIGH_FUSE=0xde


################################################################################
#                               VAR TO COMPILE                                 #
################################################################################

SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := bin
EXE := $(BIN_DIR)/balise
SRC := $(wildcard $(SRC_DIR)/*.c)
OBJ := $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CFLAGS=-Wall -O3 -fpack-struct -fshort-enums -funsigned-char -funsigned-bitfields -mmcu=$(MMCU) -DF_CPU=$(FCPU)
CPPFLAGS=-Iinclude
LDFLAGS=


all: $(EXE).hex

$(EXE).hex: $(BIN_DIR) $(OBJ_DIR) $(EXE).elf
	$(OBJCOPY) -O ihex -R .eeprom $(EXE).elf $(EXE).hex

$(EXE).elf: $(OBJ) | $(BIN_DIR)
	$(CC) $(CFLAGS) $^ -o $(EXE).elf $(LDFLAGS)

$(BIN_DIR):
	mkdir -p $@ 

$(OBJ_DIR):
	mkdir -p $@ 

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

upload: all
	avrdude $(PROGRAMMER) -p $(MMCUPROG) -U flash:w:$(EXE).hex

fuse:
	avrdude $(PROGRAMMER) -p $(MMCUPROG) -U hfuse:w:$(HIGH_FUSE):m -U lfuse:w:$(LOW_FUSE):m

clean:
	@$(RM) -rf $(BIN_DIR) $(OBJ_DIR)

.PHONY: clean upload fuse