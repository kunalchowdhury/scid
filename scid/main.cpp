/*
 * scid.cpp
 *
 * Created: 6/11/2016 4:28:18 PM
 * Author : Ireena
 */ 

//#include <avr/io.h>
#include "header/inc.h"
#include "header/coord_slave_comm.h"
//#include "header/inc_all.h"
#include "header/WirelessMessage.h"
#include "header/xbee_message_struct.h"

uint8_t EEMEM NonVolatileAddresses[8] ={1, 1, 1, 1, 1, 1, 1, 1} ;
	
int main(void)
{
	void *address = malloc(sizeof(LCDDisplay));
	LCDDisplay *display = (LCDDisplay *)new (address) LCDDisplay();

    void *address_coord = malloc(sizeof(coordinator));
	coordinator *coord = (coordinator *)new (address_coord) coordinator();
	
	
	uint8_t slave_1[] = {0x00, 0x13, 0xA2, 0x00, 0x40, 0xDC, 0x80, 0xE6};
		
	//coord->set_display(*display);
	coord->write_slave_addresses(*display, 1, slave_1);
	coord->init(*display);
	
	//uint8_t addresses[] = {0x00, 0x13, 0xA2, 0x00, 0x40, 0xDC, 0x80, 0xE6};
	//uint8_t addresses[] = {13, 01, 15, 18, 19, 221, 190, 100};
		
	//eeprom_update_block((const void*)addresses, (void *)NonVolatileAddresses, 8);
	//display->print("done writing--");
	//uint8_t slave_add[8];
	//eeprom_read_block((void *)slave_add, (const void*)NonVolatileAddresses,  8);
	//display->gotoxy(1, 2);
	//display->print(slave_add);
	
	//display->print_num(slave_add[7], 16);
	//display->print_num(slave_add[6], 16);
	//display->print_num(slave_add[5], 16);
	//display->print_num(slave_add[4], 16);
	//display->print_num(slave_add[3], 16);
	//display->print_num(slave_add[2], 16);
	//display->print_num(slave_add[1], 16);
	//display->print_num(slave_add[0], 16);
//	char str[] = "The World Is" ;


//	display->print(str);
//	display->gotoxy(1, 2);
//	display->print("Not Enough");
	return 1;
	//while(1)
	//{}
		
}

