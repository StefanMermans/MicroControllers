/*
 * Assignment5.c
 *
 * Created: 2-2-2017 14:11:30
 *  Author: Stefan
 */ 
#include "../Headers/Assignment5.h"

void lightEffect(){
	DDRD = 0b11111111;
	PORTD = 0;
	
	int pattern[8] = {
		0b00000001,
		0b00000011,
		0b00000111,
		0b00001111,
		0b00011111,
		0b00111111,
		0b01111111,
		0b11111111};
	
	while(1){
		for(int i = 0; i < 8; i++){
			PORTD = pattern[i];
			wait(500);
		}
		for(int i = 6; i >= 0; i--){
			PORTD = pattern[i];
			wait(500);
		}
	}
}
