#include "io.h"
#include "global.h"
#include <avr/io.h>
#include <inttypes.h>
#include <avr/interrupt.h>

void io_init()
{
	sbi(CONCAT(DDR, PORT_BLINK), CONCAT_3(PORT, PORT_BLINK, PIN_BLINK));
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