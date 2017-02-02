/*
 * Wait.c
 *
 * Created: 2-2-2017 12:07:05
 *  Author: Stefan
 */ 

#include "../Headers/Wait.h"

void wait( int ms )
{
	for (int i=0; i<ms; i++)
	{
		_delay_ms( 1 );		// library function (max 30 ms at 8MHz)
	}
}