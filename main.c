#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "global.h"
#include "fft.h"
#include "adc.h"
#include "io.h"
#include "tim0.h"

int main()
{
	adc_init(ADC_PRESCALER_2, ADC0);
	io_init();
	tim0_init();
	sei();

	adc_attach_interrupt(io_blink_off);
	tim0_attach_ovf_interrupt(io_blink_on);

	while(TRUE)
	{
	}
	return EXIT_SUCCESS;
}