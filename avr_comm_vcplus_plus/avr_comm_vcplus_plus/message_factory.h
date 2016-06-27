#pragma once
#include <memory>
#include "xbee_message.h"
#include "inc.h"

class message_factory
{
public:
	message_factory();
	~message_factory();
    
	std::unique_ptr<xbee_message> create_message(xbee_avr::Message_Type type);
	

};

