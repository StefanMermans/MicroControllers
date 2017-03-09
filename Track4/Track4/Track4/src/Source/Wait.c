/*
 * Wait.c
 *
 * Created: 9-3-2017 11:06:19
 *  Author: Stefan
 */ 
#include "../Headers/wait.h"

void wait( int ms )
{
	for (int i=0; i<ms; i++)
	{
		_delay_ms( 1 );		// library function (max 30 ms at 8MHz)
	}
}