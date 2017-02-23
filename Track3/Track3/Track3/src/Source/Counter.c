/*
 * Counter.c
 *
 * Created: 16-2-2017 12:50:58
 *  Author: Stefan
 */ 
#include "../asf.h"
#include "../Headers/Counter.h"
#include "avr/iom128.h"
#include <stdio.h>
#include "Headers/LCD.h"

void counter_init()
{
	DDRD = 0xFF;
	PORTD = 0x00;
	
	TCCR2 = 0x07;
	
	DDRD = 0x00;
	
	TCNT2 = 0x00;
	TIMSK = 0x01;
	
	DDRB = 0xFF;
	PORTB =0x00;
	
	while(1)
	{
		PORTB = TCNT2;
		int number = PORTB;
		char text[20];
		sprintf(text, "count: %i", number);
		LCD_display_text(text);
	}
	
}
