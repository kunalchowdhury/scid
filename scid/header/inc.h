/*
 * inc.h
 *
 * Created: 6/14/2016 8:47:09 AM
 *  Author: Ireena
 */ 


#ifndef INC_H_
#define INC_H_

#define F_CPU_1 12000000
#define USART_BAUDRATE 9600
#define UBRR_VALUE (((F_CPU_1 / (USART_BAUDRATE * 16UL))) - 1)
#define UART_SENDER_BUFFER_SZ 0x1F
#define REMOTE_AT_COMMAND_SIZE 0x13
#define REMOTE_AT_COMMAND_RESP_SIZE 0x15
#define REMOTE_AT_COMMAND_ACK_FAILURE 0x13
#define ZIGBEE_TX_REQUEST_SIZE 0x1A
#define SERIAL_REQ_TIMEOUT_VAL 1000
#define ZIGBEE_START_BYTE 0x7E;
#define GATEWAY_START_BYTE 0x7F;


#include "cppinit.h"
#include "lcddisplay.h"
#include "xbee_message_struct.h"
#include "avr/io.h"
#include "avr/eeprom.h"


#endif /* INC_H_ */