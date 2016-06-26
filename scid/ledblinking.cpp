/*
 * ledblinking.cpp
 *
 * Created: 6/12/2016 4:52:59 PM
 *  Author: Ireena
 */ 

#include <avr/io.h>
#include "util/delay.h"
#include <stdlib.h>


#define LCD_DPRT PORTA				// LCD data port
#define LCD_DDDR DDRA				// LCD Data DDR
#define LCD_CPRT PORTB				// LCD Command Port
#define LCD_CDDR DDRB				// LCD Command DDR
#define LCD_RS 0					// LCD RS
#define LCD_RW 1					// LCD RW
#define LCD_EN 2					// LCD EN

void command(unsigned char cmd)
{
	LCD_DPRT = 0xF0 & cmd ;			// only high nibble
	LCD_CPRT &= ~( 1 << LCD_RS  ) ;	// RS= 0 for command
	LCD_CPRT &= ~( 1 << LCD_RW ) ;  // RW = 0 for write
	LCD_CPRT |= (1 << LCD_EN);		// EN = 1 for H to L pulse
	_delay_us(1);
	LCD_CPRT &= ~(1 << LCD_EN);		// EN= 0 for H to L pulse
	_delay_us(100);
	
	LCD_DPRT = cmd << 4;
	LCD_CPRT |= (1 << LCD_EN);		// EN = 1 for H to L pulse
	_delay_us(1);
	LCD_CPRT &= ~(1 << LCD_EN);		// EN= 0 for H to L pulse
	_delay_us(100);
	
	
}

void data(unsigned char data)
{
	LCD_DPRT = 0xF0 & data;			// only high nibble
	LCD_CPRT |=  ( 1 << LCD_RS ) ;	// RS = 1 for data
	LCD_CPRT &= ~( 1 << LCD_RW ) ;  // RW = 0 for write
	LCD_CPRT |= (1 << LCD_EN);		// EN = 1 for H to L pulse
	_delay_us(1);
	LCD_CPRT &= ~(1 << LCD_EN);		// EN= 0 for H to L pulse
	_delay_us(100);
	
	LCD_DPRT = data << 4;
	LCD_CPRT |= (1 << LCD_EN);		// EN = 1 for H to L pulse
	_delay_us(1);
	LCD_CPRT &= ~(1 << LCD_EN);		// EN= 0 for H to L pulse
	_delay_us(100);
	
	
}

void init()
{
	LCD_DDDR = 0xFF;
	LCD_CDDR = 0xFF;
	//LCD_CPRT |= (1 << LCD_EN);
	//_delay_us(10);
	LCD_CPRT &= ~(1 << LCD_EN);
	_delay_us(2000);
	// command(0x33);					// 2 lines 5x7 matrix
	// command(0x32);
	command(0x28);
	command(0x0E);					// display on cursor on
	command(0x01);					// clear lcd
	// command(0x0C);
	_delay_us(2000);
	command(0x02);                    // shift cursor right
	
}

void gotoxy(unsigned char x, unsigned char y)
{
	unsigned char firstCharAddr[] = {0x80, 0xC0, 0x94, 0xD4} 	;
	command(firstCharAddr[y-1] + x -1);
	_delay_us(100);
}


void print1(char * str, unsigned char len)
{
	unsigned char pt = 0 ;
	while(pt < len )
	{
		data(str[pt]);
		pt++;
	}
	
}

void print1(char * str)
{
	while(*str !=0 )
	{
		data(*str);
		str++;
	}
	
}
char str[] = "WELCME ANIRUDDHA";
void printTime(){
	unsigned char hr = 5;
	unsigned char min = 16;
	unsigned char sec = 0;
	char buffer [33];
	while(1){
		gotoxy(1, 2);
		if(sec >= 59){
			//command(0x01);
			//gotoxy(1, 1);
			if(min >= 59){
				if(hr >= 23){
					hr =0;
					min = 0;
					sec = 0;
					}else {
					hr++;
					min =0;
					sec= 0;
					
				}
				}else{
				min++;
				sec = 0;
			}
			}else{
			sec++;
		}
		
		itoa(hr, buffer, 10);
		print1(buffer);
		data(':');
		itoa(min, buffer, 10);
		print1(buffer);
		data(':');
		itoa(sec, buffer, 10);
		print1(buffer);
		_delay_ms(100);
	}
	
	
}


int main11111()
{
	init();
	gotoxy(1, 1);
	//command(0x80);
	//  _delay_us(100);
	
	print1(str);//, 14) ;
	//char str1[] = "HOW R U";
	//gotoxy(1, 2);
	//  print1(str1);//, 15) ;
	//unsigned char i = 0x31;
	//data(i);
	//printTime();
	while(1);
	return 0;
}

