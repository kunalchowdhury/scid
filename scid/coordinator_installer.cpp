/*
 * coordinator_installer.cpp
 *
 * Created: 6/11/2016 11:17:56 PM
 *  Author: Ireena
 */ 

#include "avr/io.h"
//#include "header/lcddisplay.h"

//#include "header/cppinit.h"

uint8_t start_add = 0x60;

volatile uint8_t num_slaves = 1;

uint8_t slave_64_address_8[1] = {0x00};
uint8_t slave_64_address_7[1] = {0x13};
uint8_t slave_64_address_6[1] = {0xA2};
uint8_t slave_64_address_5[1] = {0x00};
uint8_t slave_64_address_4[1] = {0x40};
uint8_t slave_64_address_3[1] = {0xDC};
uint8_t slave_64_address_2[1] = {0x80};
uint8_t slave_64_address_1[1] = {0xE6};


void write_eeprom(uint8_t c, uint8_t add)
{
	while(EECR & (1 << EEWE));
	EEAR = add;
	EEDR = c;
	EECR |= (1 << EEMWE);
	EECR |= (1 << EEWE);
	
}

int main_ci(void) {
	//LCDDisplay *display = new (malloc(sizeof(LCDDisplay)),1) LCDDisplay();
	//display->print("starts.");
	//
	//
	write_eeprom(num_slaves, start_add++);
	uint8_t idx =0;
	while(num_slaves--)
	{
		//display->print("hooked.");
		//display->print_num(start_add, 16);
		//
		write_eeprom(slave_64_address_8[idx], start_add++);
		write_eeprom(slave_64_address_7[idx], start_add++);
		write_eeprom(slave_64_address_6[idx], start_add++);
		write_eeprom(slave_64_address_5[idx], start_add++);
		
		write_eeprom(slave_64_address_4[idx], start_add++);
		write_eeprom(slave_64_address_3[idx], start_add++);
		write_eeprom(slave_64_address_2[idx], start_add++);
		write_eeprom(slave_64_address_1[idx], start_add++);

		idx++;
	}
	//display->gotoxy(1, 2);
	//display->print("done..");
	//display->~LCDDisplay();
	while(1){}
	// add checksum....

}

