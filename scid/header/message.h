/* 
* message.h
*
* Created: 6/21/2016 7:57:53 AM
* Author: Ireena
*/


#ifndef __MESSAGE_H__
#define __MESSAGE_H__


class message
{
//functions
public:
	virtual ~message(){}
	virtual void Method1() = 0;
	virtual void Method2() = 0;

}; //message

#endif //__MESSAGE_H__
