/*
 * Assignment4.c
 *
 * Created: 2-2-2017 13:34:02
 *  Author: Stefan
 */ 
#include "../Headers/Assignment4.h"

void flowLight(){
	DDRD = 0b11111111;
	PORTD = 0b00000000;
	
	while(1){
		for(int i = 0; i < 8; i++){
			PORTD = 0b00000001 << i;
			wait(50);
		}
		for(int i = 0; i < 6; i++){
			PORTD = 0b1000000 >> i;
			wait(50);
		}
	}
}