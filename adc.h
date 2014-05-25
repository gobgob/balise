#ifndef __ADC_H__
#define __ADC_H__
#include <inttypes.h>

#define REF_VOLTAGE_AREF 0
#define REF_VOLTAGE_AVCC ( 1 << REFS0 )
#define REF_VOLTAGE_INTERNAL ( 1 << REFS0 ) | ( 1 << REFS1 )

#define ADC0 0
#define ADC1 ( 1 << MUX0 )
#define ADC2 ( 1 << MUX1 )
#define ADC3 ( 1 << MUX1 ) | ( 1 << MUX0 )
#define ADC4 ( 1 << MUX2 )
#define ADC5 ( 1 << MUX2 ) | ( 1 << MUX0 )
#define ADC6 ( 1 << MUX2 ) | ( 1 << MUX1 )
#define ADC7 ( 1 << MUX2 ) | ( 1 << MUX1 ) | ( 1 << MUX0 )
#define ADC8 ( 1 << MUX3 )

#define ADC_PRESCALER_2 0
#define ADC_PRESCALER_4 ( 1 << ADPS1 )
#define ADC_PRESCALER_8 ( 1 << ADPS1 ) | ( 1 << ADPS0 )
#define ADC_PRESCALER_16 ( 1 << ADPS2 )
#define ADC_PRESCALER_32 ( 1 << ADPS2 ) | ( 1 << ADPS0 )
#define ADC_PRESCALER_64 ( 1 << ADPS2 ) | ( 1 << ADPS1 )
#define ADC_PRESCALER_128 ( 1 << ADPS2 ) | ( 1 << ADPS1 ) | ( 1 << ADPS0 )

#define ADC_AUTO_TRIGGER_SOURCE_FREE 0
#define ADC_AUTO_TRIGGER_SOURCE_ANALOG_COMP ( 1 << ADTS0 )
#define ADC_AUTO_TRIGGER_SOURCE_EXTERNAL_INTERRUPT ( 1 << ADTS1 )
#define ADC_AUTO_TRIGGER_SOURCE_TIM0_COMP ( 1 << ADTS1 ) | ( 1 << ADTS0 )
#define ADC_AUTO_TRIGGER_SOURCE_TIM0_OVF ( 1 << ADTS2 )
#define ADC_AUTO_TRIGGER_SOURCE_TIM1_COMP ( 1 << ADTS2 ) | ( 1 << ADTS0 )
#define ADC_AUTO_TRIGGER_SOURCE_TIM1_OVF ( 1 << ADTS2 ) | ( 1 << ADTS1 )
#define ADC_AUTO_TRIGGER_SOURCE_TIM1_CAPTURE ( 1 << ADTS2 ) | ( 1 << ADTS1 ) | ( 1 << ADTS0 )

void adc_init(uint8_t prescaler, uint8_t adc_selected);
void adc_start_conversion();
void adc_auto_trigger_start();
void adc_auto_trigger_stop();
void adc_config_auto_trigger(uint8_t config);
uint8_t adc_is_converted();
void adc_is_converted_clear();
void adc_enable_interrupt();
void adc_disable_interrupt();
uint16_t adc_get_converted_value();
void adc_attach_interrupt(void (*userFunc)(void));
void adc_detach_interrupt();

#endif