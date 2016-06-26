/* 
* uart_sender_receiver.h
*
* Created: 6/26/2016 7:02:48 AM
* Author: Ireena
*/


#ifndef __UART_SENDER_RECEIVER_H__
#define __UART_SENDER_RECEIVER_H__

#include "avr/io.h"
class uart_sender_receiver
{
//functions
public:
	virtual ~uart_sender_receiver();
	virtual void send(const uint8_t * ptr, uint8_t sz)=0;//make uart_sender_receiver not instantiable
	virtual void receive();
	virtual void init(bool send);

}; //uart_sender_receiver

#endif //__UART_SENDER_RECEIVER_H__
