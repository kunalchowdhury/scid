/* 
* XbeeMessage.h
*
* Created: 6/21/2016 10:05:53 AM
* Author: Ireena
*/


#ifndef __XBEEMESSAGE_H__
#define __XBEEMESSAGE_H__


class XbeeMessage : public WirelessMessage
{
//variables
public:
   uint8_t* payload() ;//make WirelessMessage not instantiable
   
protected:
private:
   char** _params;
   uint8_t* _keys;
   

//functions
public:
	XbeeMessage();
	~XbeeMessage();
protected:
private:
	XbeeMessage( const XbeeMessage &c );
	XbeeMessage& operator=( const XbeeMessage &c );

}; //XbeeMessage

#endif //__XBEEMESSAGE_H__
