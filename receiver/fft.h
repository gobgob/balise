/**
 * Use http://fr.wikipedia.org/wiki/Transform%C3%A9e_de_Fourier_discr%C3%A8te like ref
 */
#ifndef __FFT_H__
#define __FFT_H__
#include <inttypes.h>

// Sample Size is > 2 * fe / F (because Shannon)
// fe = 62.5khZ and F = 1464

// New fe = 78125Hz (because cristal is 20MHz)
#define SAMPLE_SIZE 128

// Compute K = F * N / fe
//#define FFT_K 2 // K=2, fe = 78125Hz et N = 128 ==> F = 1220.7Hz
#define FFT_K 3 // K=3, fe = 62500Hz et N = 128 ==> F = 1464 Hz

#define FFT_VALUE_CMP 150000000

typedef struct FFTRingBuffer {
	uint16_t buffer[SAMPLE_SIZE];
	uint8_t head;
} FFTRingBuffer;

void fft_init();
void fft_interrupt();
uint16_t fft_get_value(uint8_t arg);
double fft_compute_fft(uint8_t coef);
long fft_get_computed_long(uint8_t coef);

inline void FFT_ring_buffer_init();
inline void FFT_ring_buffer_write(uint16_t value);
inline uint16_t FFT_ring_buffer_read(uint8_t value);

#endif