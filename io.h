#ifndef __IO_H__
#define __IO_H__

#define PORT_BLINK B
#define PIN_BLINK 5

#define PORT_GREEN D
#define PIN_GREEN 4

#define PORT_BLUE D
#define PIN_BLUE 5

void io_init();
void io_blink_toggle();
void io_blink_on();
void io_blink_off();
void io_green_toggle();
void io_green_on();
void io_green_off();
void io_blue_toggle();
void io_blue_on();
void io_blue_off();

#endif