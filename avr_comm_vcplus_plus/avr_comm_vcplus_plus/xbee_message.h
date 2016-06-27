#pragma once

#include <string>
#include <iterator>
#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
#include <map>
#include "inc.h"

class xbee_message
{
public:
	xbee_message()
	{
		_address_16.reserve(xbee_avr::size_16_add);
		_address_64.reserve(xbee_avr::size_64_add);
		_rf_data.reserve(xbee_avr::size_rf_data);
		//_tx_data.reserve(xbee_avr::UART_BUFFER_SIZE);
	}

	~xbee_message(){}

	std::vector<uint8_t>  get_message(bool is_slave_query);

	template<typename T, typename U>
	void set_message_params(T&& key , U&& value)
	{
		_message_params.insert(std::map<string, uint8_t>::value_type(key, value));
	}

	template<typename T>
	void add16(T&& val)
	{
		set(std::forward<T>(val), _address_16);
	}

	template<typename T>
	void add64(T&& val)
	{
		set(std::forward<T>(val), _address_64);
	}

	template<typename T>
	void rf(T&& val)
	{
		set(std::forward<T>(val), _rf_data);
	}

	/*template<typename T>
	void tx(T&& val)
	{
		set(std::forward<T>(val), _tx_data);
	}*/

		

private:
	std::map<std::string, uint8_t> _message_params;
	std::vector<uint8_t> _address_16;
	std::vector<uint8_t> _address_64;
	std::vector<uint8_t> _rf_data;
	//std::vector<uint8_t> _tx_data;
	std::vector<uint8_t> _message;

	template<class T>
	void set(std::vector<T> & lv, std::vector<T> & _v ) { _v = lv; }

	template<class T>
	void set(std::vector<T> && rv, std::vector<T> & _v) { _v = std::move(rv); }
};

