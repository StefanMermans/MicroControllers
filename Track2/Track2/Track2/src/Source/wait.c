/*
 * wait.c
 *
 * Created: 9-2-2017 13:40:19
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