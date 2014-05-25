#include "fft.h"
#include "global.h"
#include "adc.h"
#include <inttypes.h>
#include <avr/interrupt.h>
#include <math.h>

volatile static FFTRingBuffer FFTbuffer;

void fft_init()
{
	FFT_ring_buffer_init();
	adc_attach_interrupt(fft_interrupt);
}

void fft_interrupt()
{
	FFT_ring_buffer_write(adc_get_converted_value());
}

uint16_t fft_get_value(uint8_t arg)
{
	return FFT_ring_buffer_read(arg);
}

double fft_compute_fft()
{
	// First, commit value from Ring buffer
	uint16_t buffer[SAMPLE_SIZE];
	uint8_t i;
	cli();
	for (i = 0; i < SAMPLE_SIZE; ++i)
	{
		buffer[i] = FFTbuffer.buffer[(FFTbuffer.head+i) % SAMPLE_SIZE];
	}
	sei();

	double real = 0, img = 0;
	for (i = 0; i < SAMPLE_SIZE; ++i)
	{
		real += buffer[i] * cos(-2*3.141592654*FFT_K*i/SAMPLE_SIZE);
		img += buffer[i] * sin(-2*3.141592654*FFT_K*i/SAMPLE_SIZE);
	}
	return real * real + img * img;
}

inline void FFT_ring_buffer_init()
{
	FFTbuffer.head = 0;
}

inline void FFT_ring_buffer_write(uint16_t value)
{
	FFTbuffer.buffer[FFTbuffer.head] = value;
	FFTbuffer.head = (FFTbuffer. head + 1 ) % SAMPLE_SIZE;
}

inline uint16_t FFT_ring_buffer_read(uint8_t value)
{
	return FFTbuffer.buffer[(FFTbuffer.head+value) % SAMPLE_SIZE];
}