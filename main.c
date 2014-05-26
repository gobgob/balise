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
		uint8_t i;
		cli();
		for (i = 0; i < SAMPLE_SIZE; ++i)
		{
			uart_send_uint8_t(i);
			uart_send_char(';');
			uart_send_uint32_t((uint32_t)fft_compute_fft(i));
			uart_send_ln();
		}
		sei();
		_delay_ms(10000);
	}
	return EXIT_SUCCESS;
}