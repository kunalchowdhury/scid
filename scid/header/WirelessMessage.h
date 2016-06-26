/* 
* WirelessMessage.h
*
* Created: 6/21/2016 9:40:36 AM
* Author: Ireena
*/


#ifndef __WIRELESSMESSAGE_H__
#define __WIRELESSMESSAGE_H__

#include <avr/io.h>

class WirelessMessage
{
//functions
public:
	virtual ~WirelessMessage();
	uint8_t* header();
	virtual uint8_t* payload()=0;//make WirelessMessage not instantiable
    uint8_t  length();

}; //WirelessMessage

#endif //__WIRELESSMESSAGE_H__
