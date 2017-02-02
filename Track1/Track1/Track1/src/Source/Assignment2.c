/*
 * Assignment2.c
 *
 * Created: 2-2-2017 12:13:17
 *  Author: Stefan
 */ 

#include "../Headers/Assignment2.h"

void startBlink(){
	DDRD = 0b01100000; // Set the sixth and seventh pin to output on PORTD
	
	while (1)
	{
		PORTD = 0b01100000; // Power the sixth and seventh pin on PORTD
		wait( 500 );
		PORTD = 0;			// Power off the sixth and seventh pin on PORTD
		wait( 500 );
	}
}
