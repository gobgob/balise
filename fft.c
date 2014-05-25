#include "fft.h"
#include "global.h"
#include "adc.h"
#include <inttypes.h>

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