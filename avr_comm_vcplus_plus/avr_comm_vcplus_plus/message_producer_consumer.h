#pragma once
#include <vector>

class message_producer_consumer
{
public:
	message_producer_consumer();
	~message_producer_consumer();

	void send(std::vector<uint8_t> data);

};

