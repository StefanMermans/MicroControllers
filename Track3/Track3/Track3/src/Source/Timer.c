/*
 * Timer.c
 *
 * Created: 23-2-2017 10:38:58
 *  Author: Stefan
 */ 
#include "Headers\Timer.h"
#include <stdio.h>
#include "Headers\LCD.h"
#include "asf.h"

// Instaed of using 15 ms and 25 ms we use 1500 and 2500 ms in order to see it with our own eyes
#define TIMER_UP_LIMIT 1500
#define TIMER_DOWN_LIMIT 4000

int number = 0;

ISR(TIMER2_COMP_vect){

	number += 1;
	
	if(number <= TIMER_UP_LIMIT){
		PORTE = 0xFF;
	}
	else
	{
		PORTE = 0x00;
		if(number == 4000)
			number = 0;
	} 
}

void Timer_init()
{
	DDRE = 0xFF; // Set Port E to output
	OCR2 = 125; // Set the timer to count every millisecond. Our timer is running is 64 prescaling.
	TIMSK |= 1 << 7; // Enable intterrupt
	
	sei();
	TCCR2 = 0x0b; // Set Timer to 64 prescaling.
}
