/*
 * lcddisplay.cpp
 *
 * Created: 6/11/2016 5:31:20 PM
 *  Author: Ireena
 */
#include "header/lcddisplay.h"
#include "avr/io.h"
#include "util/delay.h"
#include <stdlib.h>


LCDDisplay::LCDDisplay()
{
  LCD_DDDR = 0xFF;
  LCD_CDDR = 0xFF;
  LCD_CPRT &= ~(1 << LCD_EN);
  _delay_us(2000);
  LCDDisplay::command(0x28);
  LCDDisplay::command(0x0E);
  LCDDisplay::command(0x01);
  _delay_us(2000);
  LCDDisplay::command(0x02); 
} 

LCDDisplay::~LCDDisplay()
{
	
}

void LCDDisplay::print(char * str)
{
	while(*str !=0 )
	{
		LCDDisplay::data(*str);
		str++;
	}
	
}

void _high_to_low_pulse()
{
	LCD_CPRT |= (1 << LCD_EN);		// EN = 1 for H to L pulse
	_delay_us(1);
	LCD_CPRT &= ~(1 << LCD_EN);		// EN= 0 for H to L pulse
	_delay_us(100);

}

void _init_data_cmd(bool isData, unsigned char val)
{
	LCD_DPRT = 0xF0 & val;
	if(isData)
	{
		LCD_CPRT |=  ( 1 << LCD_RS ) ;
		
	}else
	{
		LCD_CPRT &= ~( 1 << LCD_RS  ) ;
	}
	LCD_CPRT &= ~( 1 << LCD_RW );
	_high_to_low_pulse(); 
	LCD_DPRT = val << 4;
    _high_to_low_pulse();
}

void LCDDisplay::data(unsigned char data)
{
	_init_data_cmd(true, data);
}

void LCDDisplay::command(unsigned char cmd)
{
	_init_data_cmd(false, cmd);
}

void LCDDisplay::gotoxy(unsigned char x, unsigned char y)
{
	unsigned char firstCharAddr[] = {0x80, 0xC0, 0x94, 0xD4} 	;
	command(firstCharAddr[y-1] + x -1);
	_delay_us(100);
}

void LCDDisplay::print_num(uint8_t num, uint8_t base)
{
	itoa(num, LCDDisplay::buffer, base);
	print(LCDDisplay::buffer);
}