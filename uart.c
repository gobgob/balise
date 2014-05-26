#include "global.h"
#include "uart.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <inttypes.h>
#include "io.h"

void uart_init()
{
	UBRR0H = (uint8_t)(MY_UBRR >> 8);
	UBRR0L = (uint8_t)(MY_UBRR);

	// Disable interrupt
	uart_disable_rx_interrupt();
	uart_disable_tx_interrupt();

	// Enable TX and disable RX
	uart_enable_tx();
	uart_enable_rx();

	// Use 8bit data
	sbi(UCSR0C, UCSZ00);
	sbi(UCSR0C, UCSZ01);
	cbi(UCSR0B, UCSZ02);

	uart_set_parity(UART_PARITY_NONE);

	uart_set_stop_bit(UART_ONE_STOP_BIT);
}

void uart_send_char(uint8_t byte)
{
	 // Wait That avr send register is empty
	while (!(gbi(UCSR0A, UDRE0)));
	UDR0 = byte;
}

void uart_send_ln()
{
	uart_send_char('\r');
	uart_send_char('\n');
}

void uart_send_string(char *string)
{
	uint8_t i;
	for (i = 0; string[i] != '\0'; ++i)
	{
		uart_send_char(string[i]);
	}
}

void uart_send_uint8_t(uint8_t number)
{
	uint8_t status = 0;

	if (number >= 100 ) {
		uart_send_char((number/100)+'0');
		number = number % 100;
		status = 1;
	}

	if (number >= 10 || status) {
		uart_send_char((number/10)+'0');
		number = number % 10;
	}

	uart_send_char(number+'0');
}

void uart_send_int8_t(int8_t number)
{
	if (number < 0) {
		number *= -1;
		uart_send_char('-');
	}

	uart_send_uint8_t((uint8_t)number);
}

void uart_send_uint16_t(uint16_t number)
{
	uint8_t status = 0;

	if (number >= 10000 ) {
		uart_send_char((number/10000)+'0');
		number = number % 10000;
		status = 1;
	}

	if (number >= 1000 || status) {
		uart_send_char((number/1000)+'0');
		number = number % 1000;
		status = 1;
	}

	if (number >= 100  || status) {
		uart_send_char((number/100)+'0');
		number = number % 100;
		status = 1;
	}

	if (number >= 10  || status) {
		uart_send_char((number/10)+'0');
		number = number % 10;
	}

	uart_send_char(number+'0');
}

void uart_send_int16_t(int16_t number)
{
	if (number < 0) {
		number *= -1;
		uart_send_char('-');
	}

	uart_send_uint16_t((uint16_t)number);
}

void uart_send_uint32_t(uint32_t number)
{
	unsigned char buf[8 * sizeof(uint32_t)]; // Assumes 8-bit chars. 
	unsigned int i = 0;

	if (number == 0)
	{
		uart_send_char('0');
		return;
	} 

	while (number > 0)
	{
		buf[i++] = number % 10;
		number /= 10;
	}

	for (; i > 0; i--)
		uart_send_char((char) (buf[i - 1] < 10 ? '0' + buf[i - 1] : 'A' + buf[i - 1] - 10));
}

void uart_send_int32_t(int32_t number)
{
	if (number < 0) {
		number *= -1;
		uart_send_char('-');
	}

	uart_send_uint32_t((uint32_t)number);
}

inline void uart_set_parity(uint8_t parity)
{
	uint8_t ucsr0c = UCSR0C & 0xcf;
	UCSR0C = ucsr0c | parity;
}

inline void uart_set_stop_bit(uint8_t stop_bit)
{
	if (stop_bit == ( 1 << USBS0)) {
		sbi(UCSR0C, USBS0);
	} else {
		cbi(UCSR0C, USBS0);
	}
}

inline void uart_enable_rx_interrupt()
{
	sbi(UCSR0B, RXCIE0);
}

inline void uart_disable_rx_interrupt()
{
	cbi(UCSR0B, RXCIE0);
}

inline void uart_enable_tx_interrupt()
{
	sbi(UCSR0B, TXCIE0);
}

inline void uart_disable_tx_interrupt()
{
	cbi(UCSR0B, TXCIE0);
}

inline void uart_enable_tx()
{
	sbi(UCSR0B, TXEN0);
}

inline void uart_disable_tx()
{
	cbi(UCSR0B, TXEN0);
}

inline void uart_enable_rx()
{
	sbi(UCSR0B, RXEN0);
}

inline void uart_disable_rx()
{
	cbi(UCSR0B, TXEN0);
}

ISR(USART_RX_vect)
{

}

ISR(USART_TX_vect)
{

}

ISR(USART_UDRE_vect)
{

}