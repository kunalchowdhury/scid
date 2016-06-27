#pragma once
#include <cstdint>
#include <string>

namespace xbee_avr
{
	const size_t F_CPU_1 = 12000000;
	const size_t UART_BAUDRATE = 9600;
	constexpr size_t UBRR_VALUE = (((F_CPU_1 / (UART_BAUDRATE * 16UL))) - 1);
	const uint8_t UART_BUFFER_SIZE = 0x1F;
	const uint8_t REMOTE_AT_COMMAND_SIZE = 0x13;
	const uint8_t REMOTE_AT_COMMAND_RESP_SIZE = 0x15;
	const uint8_t REMOTE_AT_COMMAND_ACK_FAILURE = 0x13;
	const uint8_t ZIGBEE_TX_REQUEST_SIZE = 0x1A;
	const int SERIAL_REQ_TIMEOUT_VAL = 1000;
	const uint8_t size_16_add = 2;
	const uint8_t size_64_add = 8;
	const uint8_t size_rf_data = 8;

	const std::string start_delimiter = "START_DELIMITER";
	const std::string msb = "MSB";
	const std::string lsb = "LSB";
	const std::string frame_type = "FRAME_TYPE";
	const std::string frame_id = "FRAME_ID";
	const std::string broadcast_radius = "BROADCAST_RADIUS";
	const std::string options = "OPTIONS";
	const std::string checksum = "CHECKSUM";

	enum class Message_Type : std::uint8_t
	{
		XBEE = 1
	};
	
}