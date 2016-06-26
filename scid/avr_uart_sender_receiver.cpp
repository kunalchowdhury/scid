/* 
* avr_uart_sender_receiver.cpp
*
* Created: 6/26/2016 7:04:58 AM
* Author: Kunal Chowdhury
*/


#include "header/avr_uart_sender_receiver.h"
#include <string.h>
#include "header/inc.h"
#include "avr/interrupt.h"


ISR(USART_RXC_vect)
{
   avr_uart_sender_receiver::_receive_circular_buffer
              [avr_uart_sender_receiver::_read_idx % UART_SENDER_BUFFER_SZ] =UDR;
}

ISR(USART_UDRE_vect)
{
  for(uint8_t i = 0; i < avr_uart_sender_receiver::_send_buffer_sz ; i++)
  {
      UDR = avr_uart_sender_receiver::_send_buffer[i];        	  
  }

}

// default constructor
avr_uart_sender_receiver::avr_uart_sender_receiver(LCDDisplay& display)
{
	_lcd_display = display;
	_receive_circular_buffer = new uint8_t[UART_SENDER_BUFFER_SZ];
	_send_buffer = new uint8_t[UART_SENDER_BUFFER_SZ];
	_int_buf = new uint8_t[UART_SENDER_BUFFER_SZ];
}

// default destructor
avr_uart_sender_receiver::~avr_uart_sender_receiver()
{
	if(_receive_circular_buffer != NULL)
	{
		delete[] _receive_circular_buffer;
	}
	
	if(_send_buffer != NULL)
	{
		delete[] _send_buffer;
	}
	if(_int_buf != NULL)
	{
		delete[] _int_buf;
	}
	
	_lcd_display.~LCDDisplay();
}

avr_uart_sender_receiver::avr_uart_sender_receiver( const avr_uart_sender_receiver &other )
{
	memcpy(_int_buf, other._int_buf, UART_SENDER_BUFFER_SZ * sizeof(uint8_t));
}

avr_uart_sender_receiver& avr_uart_sender_receiver::operator=( const avr_uart_sender_receiver& other )
{
	if(this != &other)
	{
		delete[] _int_buf;
		_int_buf = new uint8_t[UART_SENDER_BUFFER_SZ];
		memcpy(_int_buf, other._int_buf, UART_SENDER_BUFFER_SZ * sizeof(uint8_t));
	}
	return *this;
}

void avr_uart_sender_receiver::send(const uint8_t * ptr, uint8_t sz)
{
	memcpy(_send_buffer, ptr, UART_SENDER_BUFFER_SZ * sizeof(uint8_t));
	_send_buffer_sz = sz;
	init(true);
}
void avr_uart_sender_receiver::receive()
{
    init(false);	
}
void avr_uart_sender_receiver::init(bool send)
{
	if(send)
	{
		UCSRB = (1 << TXEN) | (1 << UDRIE);
		
	}else
	{
		UCSRB = (1 << RXEN) | (1 << RXCIE);
	}
	
	UCSRC = (1 << UCSZ1) | (1 << UCSZ0) | (1 << URSEL) ;
	UBRRL = UBRR_VALUE ;
	
	sei();
	
}

void avr_uart_sender_receiver::circular_inc()
{
	_read_idx = (_read_idx + 1) % UART_SENDER_BUFFER_SZ;
}
bool avr_uart_sender_receiver::validate_message()
{
	memset(_int_buf, 0, UART_SENDER_BUFFER_SZ * sizeof(uint8_t));
	
	while(_receive_circular_buffer[_read_idx] != 0x7E 
	| _receive_circular_buffer[_read_idx] != 0x7F)
	{
	        circular_inc();	
	}
	uint8_t _int_idx = 0;
	uint8_t _start = _receive_circular_buffer[_read_idx];
	_int_buf[_int_idx++] = _start;
	
	_lcd_display.print("Found ");
	_lcd_display.print_num(_start, 16);
	uint8_t lsb , msb , checksum = 0;
	switch(_start)
	{
		case 0x7E:
		    circular_inc();
			lsb = _receive_circular_buffer[_read_idx];
			_int_buf[_int_idx++] = lsb;
			
			circular_inc();
			msb = _receive_circular_buffer[_read_idx];
			_int_buf[_int_idx++] = msb;
			checksum = 0;
			
	     	for(int i = 0 ; i <= (lsb - msb) ; i++)
			{
			   	circular_inc();
				uint8_t _dat = _receive_circular_buffer[_read_idx];
				_int_buf[_int_idx++] = _dat;
				checksum += _dat;
			}
			
			checksum = checksum & 0xFF ;
			checksum = 0xFF - checksum;
			if(_int_buf[--_int_idx] != checksum )
			{
				_lcd_display.gotoxy(1, 2);
				_lcd_display.print("DiERR RETR");
	             return false;			
			}
			break;
	
		case 0x7F: // retrieve 64-bit address of the target slave
		    for (uint8_t i = 0 ; i < 8 ; i++)
		    {
				circular_inc();
				_int_buf[_int_idx++] = _receive_circular_buffer[_read_idx];
		    }
	        break;
		
		
		return true;
	}
	
}

