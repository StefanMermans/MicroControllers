/*
 * Counter.c
 *
 * Created: 16-2-2017 12:50:58
 *  Author: Stefan
 */ 
#include "../asf.h"
#include "../Headers/Counter.h"

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

void counter_init()
{
	DDRB |= (1 << 0) ; // Set LED as output
	
	TIMSK |= (1 << TOIE1 ); // Enable overflow interrupt
	sei () ; // Enable global interrupts
	
	TCNT1 = REMAINDER_TIMER; // Preload timer with precalculated value
	
	TCCR1B |= ((1 << CS10 ) | (1 << CS11 )) ; // Set up timer at Fcpu /64
}
