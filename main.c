#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <inttypes.h>
#include <math.h>
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
		cli();
		io_blink_on();
		uint8_t i;
		double real = 0, img = 0;
		for (i = 0; i < SAMPLE_SIZE; ++i)
		{
			real += fft_get_value(i) * cos(-2*3.141592654*FFT_K*i/SAMPLE_SIZE);
			img += fft_get_value(i) * sin(-2*3.141592654*FFT_K*i/SAMPLE_SIZE);
		}
		double module = sqrt(real * real + img * img);
		io_blink_off();
		module +=1;
		sei();
		_delay_ms(10);
	}
	return EXIT_SUCCESS;
}