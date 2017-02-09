/*
 * wait.h
 *
 * Created: 9-2-2017 13:21:02
 *  Author: Camiel
 */ 


#ifndef WAIT_H_
#define WAIT_H_

#define F_CPU 8000000

#include <util/delay.h>

void wait( int ms )
{
	for (int i=0; i<ms; i++)
	{
		_delay_ms( 1 );		// library function (max 30 ms at 8MHz)
	}
}



#endif /* WAIT_H_ */