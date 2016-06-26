/* 
* avr_uart_sender_receiver.h
*
* Created: 6/26/2016 7:04:58 AM
* Author: Kunal Chowdhury
*/


#ifndef __AVR_UART_SENDER_RECEIVER_H__
#define __AVR_UART_SENDER_RECEIVER_H__

#include "uart_sender_receiver.h"
#include "avr/io.h"
#include "lcddisplay.h"
#include "inc.h"

class avr_uart_sender_receiver : public uart_sender_receiver
{
public:
	avr_uart_sender_receiver(LCDDisplay& display);
	~avr_uart_sender_receiver();
	
	void send(const uint8_t * ptr, uint8_t sz);
	void receive();
	void init(bool send);

	static uint8_t* _receive_circular_buffer;
	static uint8_t* _send_buffer;
	static volatile uint8_t  _read_idx;
	static volatile uint8_t  _send_buffer_sz;

private:

	avr_uart_sender_receiver( const avr_uart_sender_receiver &c );
	avr_uart_sender_receiver& operator=( const avr_uart_sender_receiver &c );

    void validate_message();
	void circular_inc();
    LCDDisplay _lcd_display;

    uint8_t* _int_buf;
	
}; //avr_uart_sender_receiver

uint8_t* avr_uart_sender_receiver::_receive_circular_buffer = 0;
uint8_t* avr_uart_sender_receiver::_send_buffer = 0;
volatile uint8_t avr_uart_sender_receiver::_read_idx = 0;
volatile uint8_t avr_uart_sender_receiver::_send_buffer_sz = 0;


#endif //__AVR_UART_SENDER_RECEIVER_H__
