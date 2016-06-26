/*
 * lcddisplay.h
 *
 * Created: 6/11/2016 4:32:12 PM
 *  Author: Kunal Chowdhury
 */ 


#ifndef LCDDISPLAY_H_
#define LCDDISPLAY_H_

#include "avr/io.h"

#define LCD_DPRT PORTA				// LCD data port
#define LCD_DDDR DDRA				// LCD Data DDR
#define LCD_DPIN PINA				// LCD Data Pin
#define LCD_CPRT PORTB				// LCD Command Port
#define LCD_CDDR DDRB				// LCD Command DDR
#define LCD_CPIN PINB				// LCD Commands PIN
#define LCD_RS 0					// LCD RS
#define LCD_RW 1					// LCD RW
#define LCD_EN 2					// LCD EN

using namespace std;

class LCDDisplay
{

public:
  	LCDDisplay();
	~LCDDisplay();
	void print(char * str);
	void data(unsigned char data);
	void gotoxy(unsigned char x, unsigned char y);
    void print_num(uint8_t i, uint8_t base);
private:
    void command(unsigned char command);	
	char buffer[1];
};



#endif /* LCDDISPLAY_H_ */