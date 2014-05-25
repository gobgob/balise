################################################################################
#                             VAR TO CROSS COMPILE                             #
################################################################################
CROSS?=avr-
CC=$(CROSS)gcc
OBJ=$(CROSS)objcopy
MMCU=atmega328
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

################################################################################
#                               VAR TO COMPILE                                 #
################################################################################
CFLAGS=-Wall -Werror -O3 -fpack-struct -fshort-enums -funsigned-char -funsigned-bitfields -mmcu=$(MMCU) -DF_CPU=$(FCPU)
CPPFLAGS=-I.
LDFLAGS=
PROG=balise

all: $(PROG).hex

$(PROG).hex: $(PROG).elf
	$(OBJ) -O ihex -R .eeprom $(PROG).elf $(PROG).hex

$(PROG).elf: main.o adc.o io.o tim0.o fft.o
	$(CC) $(CFLAGS) $^ -o $(PROG).elf $(LDFLAGS) 

%.o: %.c %.h
	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -c

upload: all
	avrdude $(PROGRAMMER) -p $(MMCUPROG) -U flash:w:$(PROG).hex

fuse:
	avrdude $(PROGRAMMER) -p $(MMCUPROG) -U lfuse:w:0x72:m -U hfuse:w:0xff:m

clean:
	rm -f *.o *.elf *.hex

.PHONY: clean upload fuse