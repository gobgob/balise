#include "global.h"
#include "tim0.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <inttypes.h>

static volatile voidFuncPtr tim0_ovf_interrupt_function = 0;

// Use Timer to sample ADC with specy frequency

void tim0_init()
{
	// Set prescaler of TIMER 0
	tim0_set_prescaler(TIM0_PRESCALER_1);

	// Enable OVF Interrupt
	tim0_enable_ovf_interrupt();
}

void tim0_set_prescaler(uint8_t prescaler)
{
	uint8_t tccr0b = TCCR0B & 0xf8;
	TCCR0B = tccr0b | prescaler;
}

void tim0_enable_ovf_interrupt()
{
	sbi(TIMSK0, TOIE0);
}

void tim0_disable_ovf_interrupt()
{
	cbi(TIMSK0, TOIE0);
}

void tim0_attach_ovf_interrupt(void (*userFunc)(void))
{
	tim0_ovf_interrupt_function = userFunc;
}

void tim0_detach_interrupt()
{
	tim0_ovf_interrupt_function = 0;
}

ISR(TIMER0_OVF_vect)
{
	if (tim0_ovf_interrupt_function)
		tim0_ovf_interrupt_function();
}

ISR(TIMER0_COMPA_vect)
{

}

ISR(TIMER0_COMPB_vect)
{

}