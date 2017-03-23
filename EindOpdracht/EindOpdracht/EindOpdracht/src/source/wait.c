/*
 * wait.c
 *
 * Created: 23-3-2017 11:41:06
 *  Author: Stefan
 */

// F_CPU must be defined before using delay
#define F_CPU 8000000

// external library includes
#include <asf.h>
#include <util/delay.h>

// internal project includes
#include "../headers/wait.h"

void wait(int ms){
    for (int i=0; i<ms; i++)
	{
		_delay_ms( 1 );		// library function (max 30 ms at 8MHz)
	}
}
