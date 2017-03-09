#include <asf.h>

/*
 * ADC.c
 *
 * Created: 9-3-2017 10:51:35
 *  Author: Stefan
 */ 

void ADC_INIT()
{
	//ADMUX = 0b01100001;
	ADMUX = 0xC1;
	
	// Enable the ADC 
	ADCSRA = 0b11100110;
}
