#include "../Headers/OpgaveB2.h"
#include "../Headers/Wait.h"
#include <asf.h>
/*
 * OpgaveB2.c
 *
 * Created: 9-3-2017 12:32:44
 *  Author: Stefan
 */ 
void OpgaveB2(){
	
	
	DDRF = 0x00;				// set PORTF for input (ADC)
	DDRA = 0xFF;				// set PORTA for output
	
	ADMUX = 0b01000011;		// AREF=VCC, not left adjusted, channel3
	ADCSRA = 0b10100110;		// ADC-enable, no interrupt, start, free running, division by 64
	
	while(1){
		ADCSRA |= 1 << 6;
		while ( ADCSRA & 1 << 6 ) ;
		PORTA = ADCH;			// Laat de waarde deels zien op PORTA
		wait(500);
	}
}