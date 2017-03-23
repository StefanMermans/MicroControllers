/*
 * dotMatrix.c
 *
 * Created: 23-3-2017 11:34:24
 *  Author: Stefan
 */
// external library includes
#include <asf.h>

// Internal project includes
#include "../headers/dotMatrix.h"
#include "../headers/wait.h"

void dotMatrix_start()
{
	TWCR = (0x80 | 0x20 | 0x04);
	while( 0x00 == (TWCR & 0x80) );
}

void dotMatrix_stop()
{
	TWCR = (0x80 | 0x10 | 0x04);
}

void dotMatrix_init()
{
	TWSR = 0;
	TWBR = 32;

    dotMatrix_start();
	dotMatrix_tx(0xE0);	// Display I2C addres + R/W bit
	dotMatrix_tx(0x21);	// Internal osc on (page 10 HT16K33)
	dotMatrix_stop();

	dotMatrix_start();
	dotMatrix_tx(0xE0);	// Display I2C address + R/W bit
	dotMatrix_tx(0xA0);	// HT16K33 pins all output
	dotMatrix_stop();

	dotMatrix_start();
	dotMatrix_tx(0xE0);	// Display I2C address + R/W bit
	dotMatrix_tx(0xE3);	// Display Dimming 4/16 duty cycle
	dotMatrix_stop();

	dotMatrix_start();
	dotMatrix_tx(0xE0);	// Display I2C address + R/W bit
	dotMatrix_tx(0x81);	// Display OFF - Blink On
	dotMatrix_stop();
}

void dotMatrix_tx(unsigned char data)
{
	TWDR = data;
	TWCR = (0x80 | 0x04);
	while( 0 == (TWCR & 0x80) );
}
