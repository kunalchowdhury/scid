/*
 * coordinator_eeprom_r_slaves.cpp
 *
 * Created: 6/11/2016 11:17:56 PM
 *  Author: Kunal Chowdhury
 */ 
#include "avr/io.h"
//#include "header/lcddisplay.h"
#include <stdlib.h>
//#include "header/cppinit.h"
#include "avr/eeprom.h"
#include "util/delay.h"

volatile uint8_t eeprom_val ;

uint8_t read_eeprom(uint8_t add)
{
	
	while(EECR & (1 << EEWE));
	EEAR = add;
	EECR |= (1 << EERE);
	eeprom_val = EEDR;
	return eeprom_val;
	
}
int main00(void)   
{
	//void *address = malloc(sizeof(LCDDisplay));
	//LCDDisplay *display = new (address,1) LCDDisplay();
	//
	//uint8_t data ;
	//data = 0x12;
	//eeprom_write_byte((uint8_t *)60, data);
	//display->print("done writing..");
	//while(1){}

   return 1;
}

int main_19(void)
{
	   
	//void *address = malloc(sizeof(LCDDisplay));
	//LCDDisplay *display = new (address,1) LCDDisplay();
	//
	eeprom_write_byte((uint8_t *)0, 0x24);
	eeprom_write_byte((uint8_t *)1, 0x09);
	eeprom_write_byte((uint8_t *)2, 0x20);
	eeprom_write_byte((uint8_t *)3, 0x13);
	//display->print("done writing..");
	
	_delay_us(2000);
	
	//uint8_t start = 0x60 ;
	//display->print("MANU Bday ON");
	//display->gotoxy(1, 2);
	uint8_t d1 = eeprom_read_byte((uint8_t *)0);//read_eeprom(start++);
	uint8_t d2 = eeprom_read_byte((uint8_t *)1);
	uint8_t d3 = eeprom_read_byte((uint8_t *)2);
	uint8_t d4 = eeprom_read_byte((uint8_t *)3);
	//uint8_t y = 1;
	//display->print_num(d1, 16);
	//display->print("-");
	//display->print_num(d2, 16);
	//display->print("-");
	//display->print_num(d3, 16);
	//display->print_num(d4, 16);
	//while(c--)
	//{
		//uint8_t v = read_eeprom(start++);
	    //display->print_num(v, 16);
	//}
	
	//display->~LCDDisplay();
	return 1;
}