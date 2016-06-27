//#include "stdafx.h"
#include <iostream>
#include <string>
#include <utility>
#include <iomanip>
#include <vector>
#include "xbee_message.h"
#include "inc.h"
#include "message_factory.h"
#include <iomanip>
#include "item.h"

using namespace std;

template<typename T1, typename T2>
auto Plus(T1&& t1, T2&& t2) ->
decltype(forward<T1>(t1) + forward<T2>(t2))
{
	return forward<T1>(t1) + forward<T2>(t2);
}

class X
{
	friend X operator+(const X& x1, const X& x2)
	{
		return X(x1.m_data + x2.m_data);
	}

public:
	X(int data) : m_data(data) {}
	int Dump() const { return m_data; }
private:
	int m_data;
};

int main()
{
	item *i = new item() ;
	i->showdata();
	
	bike* b = reinterpret_cast<bike*> (i);

	b->extra();
	//cout << i.showdata()<< "\n";
	while (true)
	{

	}
}

int main_messsage_working()
{
	using namespace xbee_avr;
	message_factory mf = message_factory();
	xbee_message msg = *mf.create_message(xbee_avr::Message_Type::XBEE);
	msg.set_message_params(start_delimiter, 0x7E);
	msg.set_message_params(msb, 0x00);
	msg.set_message_params(lsb, 0x0F);
	msg.set_message_params(frame_type, 0x17);
	msg.set_message_params(broadcast_radius, 0x00);
	msg.set_message_params(frame_id, 0x01);
	
	std::vector<uint8_t> v64 = {0x00, 0x13, 0xA2, 0x00, 0x40, 0xDC, 0x80, 0xE6};
	std::vector<uint8_t> v16 = { 0xFF, 0xFE };

	msg.add16(v16);
	msg.add64(v64);

	std::vector<uint8_t> av = msg.get_message(true);

	for (auto p : av)
	{
		std::cout << std::hex << static_cast<int>(p) << " ";
	}

	while (true)
	{}
}

int main1()
{
	std::map<string, uint8_t> s;
	s.insert(std::map<string, uint8_t>::value_type("aka", 1));
	s.insert(std::map<string, uint8_t>::value_type("aka", 2));
	cout << s.find("aka")->first << " " << s.find("aka")->second << "\n";
	
	// Integer 
	int i = 4;
	cout <<
		"Plus(i, 9) = " <<
		Plus(i, 9) << endl;

	// Floating point
	float dx = 4.0;
	float dy = 9.5;
	cout <<
		setprecision(3) <<
		"Plus(dx, dy) = " <<
		Plus(dx, dy) << endl;

	// String      
	string hello = "Hello, ";
	string world = "world!";
	cout << Plus(hello, world) << endl;

	// Custom type
	X x1(20);
	X x2(22);
	X x3 = Plus(x1, x2);
	cout <<

		"x3.Dump() = " <<
		x3.Dump() << endl;

	while (true)
	{

	}
}
