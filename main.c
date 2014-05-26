#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <inttypes.h>
#include "global.h"
#include "fft.h"
#include "adc.h"
#include "io.h"
#include "tim0.h"
#include "uart.h"

int main()
{
	adc_init(ADC_PRESCALER_4, ADC0);
	io_init();
	tim0_init();
	fft_init();
	uart_init();
	sei();

	while(TRUE)
	{
		if (fft_compute_fft(FFT_K) >= FFT_VALUE_CMP) {
			io_blink_on();
		} else {
			io_blink_off();
		}
	}
	return EXIT_SUCCESS;
}