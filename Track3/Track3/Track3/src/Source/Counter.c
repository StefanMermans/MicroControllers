/*
 * Counter.c
 *
 * Created: 16-2-2017 12:50:58
 *  Author: Stefan
 */ 
#include "../asf.h"
#include "../Headers/Counter.h"

ISR(TIMER2_COMP_vect){
	PORTB = 0xFF;
}

void counter_init()
{
	DDRD = 0x00;			// set PORTD to input
	TCCR2 = 0b00000111;		// Counting via PD7, rising edge
	
	DDRB = 0xFF;			// set PORTB to output
	PORTB = TCNT2;			// show value TCCR2
}
