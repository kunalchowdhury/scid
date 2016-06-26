/*
 * xbee_message_struct.h
 *
 * Created: 6/14/2016 4:44:10 PM
 *  Author: Kunal Chowdhury
 */ 


#ifndef XBEE_MESSAGE_STRUCT_H_
#define XBEE_MESSAGE_STRUCT_H_

#include <string.h>

struct destination_address_64{
	uint8_t address[8];
};

struct destination_address_16{
	uint8_t address[2];
};

struct rf_data{
	uint8_t data[8];
};

struct tx_req_data
{
	uint8_t tx_data[UART_SENDER_BUFFER_SZ];
};


struct zigbee_transmit_request{
	struct destination_address_64 address_64;
	struct rf_data data ;
	struct tx_req_data tx_data;
	struct  destination_address_16 address_16;
	uint8_t start_delimiter;
	uint8_t msb;
	uint8_t lsb;
	uint8_t frame_type;
	uint8_t frame_id;
	uint8_t broadcast_radius;
	uint8_t options;
	uint8_t checksum;
	
};

class zigbee_tx_request
{
public:
    zigbee_tx_request(const uint8_t* init_data)
	{
		tx_data = new uint8_t[UART_SENDER_BUFFER_SZ];
		checksum = 0;
		copy_data(init_data, 5);
	}
	~zigbee_tx_request()
	{
		if (tx_data != NULL)
		{
			delete[] tx_data;
		}
	}	
	zigbee_tx_request(const zigbee_tx_request& other)
	{
		memcpy(tx_data, other.tx_data, UART_SENDER_BUFFER_SZ * sizeof(uint8_t));
	}
	zigbee_tx_request& operator=(const zigbee_tx_request& other)
	{
		if(this != &other)
		{
			delete[] tx_data;
			tx_data = new uint8_t[UART_SENDER_BUFFER_SZ];
			memcpy(tx_data, other.tx_data, UART_SENDER_BUFFER_SZ * sizeof(uint8_t));
		}
		return *this;
	}
	void address64(const uint8_t* add64)
	{
		copy_data(add64, 8);
	}
	
	void address16(const uint8_t* add16)
	{
	   copy_data(add16, 2);
    }

	void additional_data(bool is_slave_query, uint8_t* rf)
	{
		if (is_slave_query)
		{
			tx_data[idx++] = 0x02;
			tx_data[idx++] = 0x4D;
			tx_data[idx++] = 0x59;
			checksum += (0x02 + 0x4D + 0x59);
			checksum = checksum & 0xFF;
			tx_data[idx++] = 0xFF - checksum;
		}else
		{
			tx_data[idx++] = 0x00;
			tx_data[idx++] = 0x00;
			copy_data(rf, 8);
			checksum = checksum & 0xFF;
			tx_data[idx++] = 0xFF - checksum;
		}
	}
	
	const uint8_t* data()
	{
		return tx_data;
	}

private:
  	uint8_t checksum;
    uint8_t idx;
    uint8_t *tx_data;

    void copy_data(const uint8_t* arr, uint8_t len)
	{
		for(uint8_t i = 0 ;  i < len; i++)
		{
			uint8_t data  = arr[i];
			tx_data[idx++] = data;
			checksum += data;
		}
		delete[] arr;
	}

};



#endif /* XBEE_MESSAGE_STRUCT_H_ */