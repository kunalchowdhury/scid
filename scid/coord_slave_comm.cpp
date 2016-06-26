/*
 * coord_slave_comm.cpp
 *
 * Created: 6/12/2016 9:59:56 PM
 *  Author: Ireena
 */ 

#include "header/coord_slave_comm.h"
#include "avr/io.h"
#include <string.h>
#include <stdlib.h>


// facility to support up to 5 slave devices

uint8_t EEMEM NonVolatileAddresses_1[8] ={1, 1, 1, 1, 1, 1, 1, 1} ;
uint8_t EEMEM NonVolatileAddresses_2[8] ={1, 1, 1, 1, 1, 1, 1, 1} ;
uint8_t EEMEM NonVolatileAddresses_3[8] ={1, 1, 1, 1, 1, 1, 1, 1} ;	
uint8_t EEMEM NonVolatileAddresses_4[8] ={1, 1, 1, 1, 1, 1, 1, 1} ;
uint8_t EEMEM NonVolatileAddresses_5[8] ={1, 1, 1, 1, 1, 1, 1, 1} ;
	
coordinator::coordinator()
{
	num_slaves = 0;
}
coordinator::~coordinator(){}

void coordinator::init(LCDDisplay& disp)
{
	display = disp;	
	//display.print("starting-:>");
    
	
	slaves_16_address = init_array(num_slaves, 2);
	slaves_64_address = init_array(num_slaves, 8);
	
	uint8_t slave_add[8];
    uint8_t counter = num_slaves;
	while(counter)
	{
		switch(counter)
		{
			case 1:
			     //display.print_num(num_slaves, 10);
				 eeprom_read_block((void *)slave_add, (const void*)NonVolatileAddresses_1,  8);
				 break;
			case 2:
				// display.print_num(num_slaves, 10);
				 eeprom_read_block((void *)slave_add, (const void*)NonVolatileAddresses_2,  8);
				 break;
			case 3:
				 //display.print_num(num_slaves, 10);
				 eeprom_read_block((void *)slave_add, (const void*)NonVolatileAddresses_3,  8);
				 break;
			case 4:
				// display.print_num(num_slaves, 10);
				 eeprom_read_block((void *)slave_add, (const void*)NonVolatileAddresses_4,  8);
				 break;
			case 5:
				// display.print_num(num_slaves, 10);
				 eeprom_read_block((void *)slave_add, (const void*)NonVolatileAddresses_5,  8);
				 break;
		}
		memcpy(slaves_64_address[counter-1], slave_add, 8 * sizeof(uint8_t));
		--counter;
	}
	display.gotoxy(1, 2);
	
	//display.print_num(slave_add[7], 16);
	//display.print_num(slave_add[6], 16);
	//display.print_num(slave_add[5], 16);
	//display.print_num(slave_add[4], 16);
	//display.print_num(slave_add[3], 16);
	//display.print_num(slave_add[2], 16);
	//display.print_num(slave_add[1], 16);
	//display.print_num(slave_add[0], 16);
	//
	for (int i = 0 ; i < num_slaves ; i++)
	{
		for(int j = 0 ; j < 8 ; j++)
		{
			display.print_num(slaves_64_address[i][j], 16);
		}
	}
	
}
void coordinator::write_slave_addresses(LCDDisplay& disp, uint8_t idx, const uint8_t* addresses)
{
	//disp.print("writing idx ");
	//disp.print_num(idx, 10);
	switch(idx)
	{ 
		case 1:
			eeprom_update_block((const void*)addresses, (void *)NonVolatileAddresses_1, 8);
		    break;
		
		case 2:
			eeprom_update_block((const void*)addresses, (void *)NonVolatileAddresses_2, 8);
			break;
		
		case 3:
			eeprom_update_block((const void*)addresses, (void *)NonVolatileAddresses_3, 8);
			break;
		
		case 4:
			eeprom_update_block((const void*)addresses, (void *)NonVolatileAddresses_4, 8);
			break;
		
		case 5:
			eeprom_update_block((const void*)addresses, (void *)NonVolatileAddresses_5, 8);
			break;
	}
	if(num_slaves < idx)
	{
	        num_slaves = idx;	
	}
	//disp.gotoxy(1, 2);
	//disp.print("Done ");
	//disp.print_num(num_slaves, 10);
	
}	
//coordinator::coordinator(uint8_t start_add, LCDDisplay& disp)
//{
   //coordinator::eeprom_start_add = start_add;
   //coordinator::display = disp;
   //coordinator::slaves_16_address = init_array(1, 2);
   //coordinator::slaves_64_address = init_array(1, 8);
//}
