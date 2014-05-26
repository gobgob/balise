#ifndef __UART_H__
#define __UART_H__
#include <inttypes.h>

#define BAUD 9600

#define MY_UBRR (F_CPU/8/BAUD - 1)/2

#define UART_PARITY_NONE 0
#define UART_PARITY_EVEN (1 << UPM1)
#define UART_PARITY_ODD (1 << UPM1) | (1 << UPM0)

#define UART_ONE_STOP_BIT 0
#define UART_TWO_STOP_BIT (1 << USBS0)

void uart_init();
void uart_send_char(uint8_t data);
void uart_send_ln();
void uart_send_string(char *string);

void uart_send_uint8_t(uint8_t number);
void uart_send_int8_t(int8_t number);
void uart_send_uint16_t(uint16_t number);
void uart_send_int16_t(int16_t number);
void uart_send_uint32_t(uint32_t number);
void uart_send_int32_t(int32_t number);

inline void uart_set_parity(uint8_t parity);
inline void uart_set_stop_bit(uint8_t stop_bit);
inline void uart_enable_rx_interrupt();
inline void uart_disable_rx_interrupt();
inline void uart_enable_tx_interrupt();
inline void uart_disable_tx_interrupt();
inline void uart_enable_tx();
inline void uart_disable_tx();
inline void uart_enable_rx();
inline void uart_disable_rx();

#endif