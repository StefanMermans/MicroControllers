/*
 * AssignmentB2.c
 *
 * Created: 9-2-2017 10:57:09
 *  Author: Camiel
 */ 
#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>


void wait( int ms )
{
	for (int i=0; i<ms; i++)
	{
		_delay_ms( 1 );		// library function (max 30 ms at 8MHz)
	}
}

void run()
{
	DDRD = 0x01;
	DDRC = 0xFF;
	PORTC = 0x00;
	PORTD = 0x00;
	
	EICRA |= 0x0F;			// INT1 falling edge, INT0 rising edge
	EIMSK |= 0x01;			// Enable INT1 & INT0
	
	sei();
	while(1)
	{
		//wait(1000);
		//PORTD = 0x01;
		//wait(1000);
		//PORTD = 0x00;
	}
}


