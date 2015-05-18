#include "io.h"
#include "global.h"
#include <avr/io.h>
#include <inttypes.h>
#include <avr/interrupt.h>

void io_init()
{
	sbi(CONCAT(DDR, PORT_BLINK), CONCAT_3(PORT, PORT_BLINK, PIN_BLINK));
	sbi(CONCAT(DDR, PORT_GREEN), CONCAT_3(PORT, PORT_GREEN, PIN_GREEN));
	sbi(CONCAT(DDR, PORT_BLUE), CONCAT_3(PORT, PORT_BLUE, PIN_BLUE));
}

void io_blink_toggle()
{
	tbi(CONCAT(PORT, PORT_BLINK), CONCAT_3(PORT, PORT_BLINK, PIN_BLINK));
}

void io_blink_on()
{
	sbi(CONCAT(PORT, PORT_BLINK), CONCAT_3(PORT, PORT_BLINK, PIN_BLINK));
}

void io_blink_off()
{
	cbi(CONCAT(PORT, PORT_BLINK), CONCAT_3(PORT, PORT_BLINK, PIN_BLINK));
}

void io_green_toggle()
{
	tbi(CONCAT(PORT, PORT_GREEN), CONCAT_3(PORT, PORT_GREEN, PIN_GREEN));
}

void io_green_on()
{
	sbi(CONCAT(PORT, PORT_GREEN), CONCAT_3(PORT, PORT_GREEN, PIN_GREEN));
}

void io_green_off()
{
	cbi(CONCAT(PORT, PORT_GREEN), CONCAT_3(PORT, PORT_GREEN, PIN_GREEN));
}

void io_blue_toggle()
{
	tbi(CONCAT(PORT, PORT_BLUE), CONCAT_3(PORT, PORT_BLUE, PIN_BLUE));
}

void io_blue_on()
{
	sbi(CONCAT(PORT, PORT_BLUE), CONCAT_3(PORT, PORT_BLUE, PIN_BLUE));
}

void io_blue_off()
{
	cbi(CONCAT(PORT, PORT_BLUE), CONCAT_3(PORT, PORT_BLUE, PIN_BLUE));
}

ISR(INT0_vect)
{

}

ISR(INT1_vect)
{

}

ISR(PCINT0_vect)
{

}

ISR(PCINT1_vect)
{

}

ISR(PCINT2_vect)
{

}