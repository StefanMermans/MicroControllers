/*
 * AssignmentB3.c
 *
 * Created: 9-2-2017 13:08:02
 *  Author: Camiel
 */ 
#include "../Headers/AssignmentB3.h"
/*
		0
	5		1	
		6
	4		2
		3
*/



void display(int number){
	int hexTable[20]={
		0x3F, // 0
		0x6,  // 1
		0x5B, // 2
		0x4F, // 3
		0x66, // 4
		0x6D, // 5
		0x7D, // 6
		0x07, // 7
		0x7F, // 8
		0x6F, // 9
		
		0x77, // A
		0x7c, // b
		0x39, // C
		0x5e, // d
		0x79, // E
		0x71, // F
		0x7b  // e (error)
	};
	if(number < 0 || number > 15){
		number = 16;
	}
	PORTC = hexTable[number];	
}

void runB3 ()
{	
	DDRD = 0x00;
	DDRC = 0xFF;
	PORTC = 0x00;	
	PORTD = 0x01;
	int number =0;	
	while(1)
	{		
		for(int i =0; i<17; i++)
		{
			display(i);
			wait(500);
		}
		for(int x=0;x<3;x++)
		{
			for(int i=0;i<7;i++)
			{
				PORTC = 0x01<<i;
				wait(300);
			}
		}
		
	}
}
