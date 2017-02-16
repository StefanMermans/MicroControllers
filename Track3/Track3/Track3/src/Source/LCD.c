/*
 * LCD.c
 *
 * Created: 16-2-2017 10:29:24
 *  Author: Stefan
 */ 
#define F_CPU 8000000

#include "asf.h"
#include "../Headers/LCD.h"
#include <util/delay.h>

void LCD_init()
{
	// Set the pins to the correct setting for controlling the LCD
	DDRC = 0xFF; // set port c for output
	PORTC = 0x00; // set every pin to 0
	
	// return home
	LCD_command( 0x02 );
	// mode: 4 bits interface data, 2 lines, 5x8 dots
	LCD_command( 0x28 );
	// display: on, cursor off, blinking off
	LCD_command( 0x0C );
	// entry mode: cursor to right, no shift
	LCD_command( 0x06 );
	// RAM adress: 0, first position, line 1
	LCD_command( 0x80 );
}

void LCD_writeChar(unsigned char data)
{
	PORTC = data & 0xF0;		// hoge nibble
	PORTC = PORTC | 0x0C;		// data (RS=1),
								// start (EN=1)
	_delay_ms(1);				// wait 1 ms
	PORTC = 0x04;				// stop (EN = 0)
	
	PORTC = (data & 0x0F) << 4;	// lage nibble
	PORTC = PORTC | 0x0C;		// data (RS=1),
								// start (EN=1)
	_delay_ms(1);				// wait 1 ms
	PORTC = 0x00;				// stop
								// (EN=0 RS=0)
}

void LCD_writeLine1(char text[])
{
	// eerst de eerste 8 karakters = regel 1
	// eerste pos regel 1
	LCD_command(0x80);
	for (int i=0; i<16; i++) {
		LCD_writeChar( text[i] );
	}
}

void LCD_writeline2(char text[])
{
	// dan de eerste 8 karakters = regel 2
	// eerste pos regel 2
	LCD_command(0xC0);
	for (int i=0; i<16; i++) {
		LCD_writeChar( text[i] );
	}
}

void LCD_command(unsigned char data)
{
	PORTC = data & 0xF0;		// hoge nibble
	PORTC = PORTC | 0x08;		// data (RS=0),
								// start (EN=1)
	_delay_ms(1);				// wait 1 ms
	PORTC = 0x04;				// stop (EN = 0)
	
	PORTC = (data & 0x0F) << 4;	// lage nibble
	PORTC = PORTC | 0x08;		// data (RS=0),
								// start (EN=1)
	_delay_ms(1);				// wait 1 ms
	PORTC = 0x00;				// stop
}

void LCD_display_text(char *str)
{

}

void LCD_set_cursor()
{

}
