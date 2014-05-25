#ifndef __IO_H__
#define __IO_H__

#define PORT_BLINK B
#define PIN_BLINK 5

void io_init();
void io_blink_toggle();
void io_blink_on();
void io_blink_off();

#endif