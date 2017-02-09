/*
 * AssignmentB2.c
 *
 * Created: 9-2-2017 10:57:09
 *  Author: Camiel
 */ 
#include "asf.h"
#include "../Headers/AssignmentB2.h"

// Uncommenting the ISR function will give build errors... pls help
//interrupt function
/*ISR( INT0_vect )
{
	if(PORTC==0x00 || PORTC==0x80)
	{
		PORTC=0x01;
		} else{
		PORTC = PORTC<<1;
	}
}*/

void run()
{
	DDRD = 0x01;
	DDRC = 0xFF;
	PORTC = 0x01;
	PORTD = 0x00;
	
	EICRA |= 0x0F;			// INT1 falling edge, INT0 rising edge
	EIMSK |= 0x01;			// Enable INT1 & INT0
	
	sei();
	while(1)
	{
		
	}
}


