/*
 * Assignment6.c
 *
 * Created: 2-2-2017 14:35:13
 *  Author: Stefan
 */ 
#include "../Headers/Assignment6.h"

void testDelayedBlink(){
	DDRC = 0b10000000;
	
	int state = 1;
	
	while(1){
		if (PINC & 0b00000010)
		{
			state += 1;
			if(state == 4){
				state = 1;
			}
		}
		switch (state)
		{
			case 1:
			for(int i = 0; i < 3; i++){
				PORTC = 0b10000000;
				wait(1000);
				PORTC = 0b00000000;
				wait(1000);
			}
			break;
			case 2:
			for(int i = 0; i < 3; i++){
				PORTC = 0b10000000;
				wait(500);
				PORTC = 0;
				wait(500);
			}
			break;
			case 3:
			for(int i = 0; i < 3; i++){
				PORTC = 0b10000000;
				wait(250);
				PORTC = 0;
				wait(250);
			}
			break;
		}
	}
}