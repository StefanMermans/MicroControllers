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

#define MAX_OVERFLOW 2
#define REMAINDER_TIMER 31250

volatile int overflow_count = 0;

ISR ( TIMER1_OVF_vect )
{
	TCNT1 = REMAINDER_TIMER; // Reload timer with precalculated value

	overflow_count += 1;
	if(overflow_count >= MAX_OVERFLOW){
		overflow_count = 0;
		PORTB ^= (1 << 0) ; // Toggle the LED
	}	
}

ISR (TIMER2_COMP_vect)
{
	PORTB = TCNT2;
	};

void counter_init()
{
	//DDRB |= (1 << 0) ; // Set LED as output
	//
	//TIMSK |= (1 << TOIE1 ); // Enable overflow interrupt
	//sei () ; // Enable global interrupts
	//
	//TCNT1 = REMAINDER_TIMER; // Preload timer with precalculated value
	//
	//TCCR1B |= ((1 << CS10 ) | (1 << CS11 )) ; // Set up timer at Fcpu /64
	DDRD = 0xFF;
	PORTD = 0x00;
	TCCR2 = 0x07;
	DDRD = 0x00;
	
	
	DDRB = 0xFF;
	TCNT2 = 0x00;
	OCR2=0x01;
	TIMSK = 0x01;
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
