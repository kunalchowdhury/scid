#include "message_factory.h"



message_factory::message_factory()
{
}


message_factory::~message_factory()
{
}

std::unique_ptr<xbee_message> message_factory::create_message(xbee_avr::Message_Type type)
{
	std::unique_ptr<xbee_message> ptr = std::unique_ptr<xbee_message>(nullptr);
	ptr.get();
	if(xbee_avr::Message_Type::XBEE == type)
	{
		ptr.reset(new xbee_message());
	}
	return ptr;
}
