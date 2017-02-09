/*
 * AssignmentB2.h
 *
 * Created: 9-2-2017 11:48:31
 *  Author: Camiel
 */ 


#ifndef ASSIGNMENTB2_H_
#define ASSIGNMENTB2_H_
#include "../Headers/wait.h"

void run();

//interrupt function
ISR( INT0_vect )
{
	if(PORTC==0x00 || PORTC==0x80)
	{
		PORTC=0x01;
	} else{
		PORTC = PORTC<<1;
	}
}




#endif /* ASSIGNMENTB2_H_ */