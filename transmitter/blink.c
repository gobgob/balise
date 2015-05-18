#include <avr/io.h>
#include <util/delay.h>
#include "global.h"
#include "blink.h"

int main()
{	
	sbi(DDRB, PORTB0);
	sbi(DDRD, PORTD5);
	sbi(DDRD, PORTD6);
	sbi(DDRD, PORTD7);
	
	cbi(PORTB, PORTB0);
	cbi(PORTD, PORTD5);
	cbi(PORTD, PORTD6);
	cbi(PORTD, PORTD7);
	while(TRUE)
	{
		cbi(PORTD, PORTD7);
		sbi(PORTB, PORTB0);
		_delay_us(250000/FREQ);
		cbi(PORTB, PORTB0);
		sbi(PORTD, PORTD5);
		_delay_us(250000/FREQ);
		cbi(PORTD, PORTD5);
		sbi(PORTD, PORTD6);
		_delay_us(250000/FREQ);
		cbi(PORTD, PORTD6);
		sbi(PORTD, PORTD7);
		_delay_us(250000/FREQ);
	}
	return EXIT_SUCCESS;
}
