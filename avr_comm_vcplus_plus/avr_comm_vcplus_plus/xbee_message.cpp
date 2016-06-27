#include "xbee_message.h"
#include "inc.h"
#include <memory>

using namespace xbee_avr;

std::vector<uint8_t> xbee_message::get_message(bool is_slave_query)
{
	uint8_t checksum = 0;
	_message.push_back(_message_params.find(start_delimiter)->second);
	_message.push_back(_message_params.find(msb)->second);
	_message.push_back(_message_params.find(lsb)->second);
	
	auto& frame_t = _message_params.find(frame_type)->second;
	checksum += frame_t;
	_message.push_back(frame_t);
	
	auto& frameid = _message_params.find(frame_id)->second;
	checksum += frameid;
	_message.push_back(frameid);

	for(const auto& v : _address_64)
	{
		checksum += v;
		_message.push_back(v);

	}

	for (const auto& v : _address_16)
	{
		checksum += v;
		_message.push_back(v);

	}

	if (is_slave_query)
	{
		_message.push_back(0x02);
		_message.push_back(0x4D);
		_message.push_back(0x59);
		
		checksum += (0x02 + 0x4D + 0x59);
		checksum = checksum & 0xFF;

		_message.push_back(0xFF - checksum);

	}
	else
	{
		_message.push_back(0x00);
		_message.push_back(0x00);

		for (const auto& v: _rf_data )
		{
			checksum += v;
			_message.push_back(v);
		}

		checksum = checksum & 0xFF;
		_message.push_back(0xFF - checksum);
	}
	
	return _message;
}
