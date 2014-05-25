#ifndef __TIM0_H__
#define __TIM0_H__
#include <inttypes.h>

#define TIM0_PRESCALER_1 ( 1 << CS00 )
#define TIM0_PRESCALER_8 ( 1 << CS01 )
#define TIM0_PRESCALER_64 ( 1 << CS01 ) | ( 1 << CS00 )
#define TIM0_PRESCALER_256 ( 1 << CS02 )
#define TIM0_PRESCALER_1024 ( 1 << CS02 ) | ( 1 << CS00 )

void tim0_init();
void tim0_set_prescaler(uint8_t prescaler);
void tim0_enable_ovf_interrupt();
void tim0_disable_ovf_interrupt();
void tim0_attach_ovf_interrupt(void (*userFunc)(void));
void tim0_detach_interrupt();

#endif