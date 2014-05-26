#include <avr/io.h>
#include <avr/interrupt.h>
#include <inttypes.h>
#include "adc.h"
#include "global.h"

static volatile voidFuncPtr adc_interrupt_function = 0;

void adc_init(uint8_t prescaler, uint8_t adc_selected)
{
	// Config multiplexeur
	ADMUX = REF_VOLTAGE_AVCC | adc_selected;

	//Config Prescaler
	uint8_t adcsra = ADCSRA & 0xf8;
	ADCSRA = adcsra | prescaler;

	// Config Interrupt on TIM0 OVF
	adc_config_auto_trigger(ADC_AUTO_TRIGGER_SOURCE_TIM0_OVF);
	adc_auto_trigger_start();

	// Enable Interrupt when convert is finish
	adc_enable_interrupt();

	// Enable ADC
	sbi(ADCSRA, ADEN);
}

void adc_start_conversion()
{
	sbi(ADCSRA, ADSC);
}

void adc_auto_trigger_start()
{
	sbi(ADCSRA, ADATE);
}

void adc_auto_trigger_stop()
{
	cbi(ADCSRA, ADATE);
}

void adc_config_auto_trigger(uint8_t config)
{
	uint8_t adcsrb = ADCSRB & 0xf8;
	ADCSRB = adcsrb | config;
}

uint8_t adc_is_converted()
{
	return gbi(ADCSRA, ADSC);
}

void adc_enable_interrupt()
{
	sbi(ADCSRA, ADIE);
}

void adc_disable_interrupt()
{
	cbi(ADCSRA, ADIE);
}

uint16_t adc_get_converted_value()
{
	uint8_t high, low;
	low = ADCL;
	high = ADCH;
	return (high << 8) | low;
}

void adc_attach_interrupt(void (*userFunc)(void))
{
	adc_interrupt_function = userFunc;
}

void adc_detach_interrupt()
{
	adc_interrupt_function = 0;
}

ISR(ADC_vect)
{
	if (adc_interrupt_function)
		adc_interrupt_function();
}