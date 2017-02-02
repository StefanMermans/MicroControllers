/*
 * Assignment3.c
 *
 * Created: 2-2-2017 13:06:03
 *  Author: Stefan
 */ 
#include "../Headers/Assignment3.h"

void testButton(){
	DDRD = 0b11111111;
	DDRC = 0b00000000;
	
	while(1){
		if(PINC & 0b00000001){
			PORTD = 0b01000000;
		} else{
			PORTD = 0b00000000;
		}
	}
}