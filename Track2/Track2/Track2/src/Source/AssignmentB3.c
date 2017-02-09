/*
 * AssignmentB3.c
 *
 * Created: 9-2-2017 13:08:02
 *  Author: Camiel
 */ 
#include "../Headers/assignmentb3.h"
#include "../Headers/wait.h"
#define F_CPU 8000000
#include <avr/io.h>



/*
		0
	5		1	
		6
	4		2
		3
*/



void runb3 ()
{
	int * hexTable={
		0x3F,
		0x3,
		0x5B,
		0x4F,
		0x66,
		0x6D,
		0x7D,
		0x07,
		0x7F,
		0x6F
	};
	DDRC=0xFF;
	while(1)
	{
		for(int i=0;i<10;i++)
		{
			PORTC = hexTable[i];
			wait(1000);
		}
		
	}
}
