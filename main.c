#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <inttypes.h>
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
	fft_init();
	sei();
	_delay_ms(10);

	while(TRUE)
	{
		fft_compute_fft();
	}
	return EXIT_SUCCESS;
}