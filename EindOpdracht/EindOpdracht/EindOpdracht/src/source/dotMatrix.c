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

//shows the matrix on the matrixboard 
void dotMatrix_displayMatrix(int matrix[8][8])
{
	int x = 0;
	int y = 0;
	for(x=0; x<8; x++)
	{
		int row = 0;
		row |= matrix[x][0];
		for(y=7; y>0; y--)			//starts at 7 because the point x=0 has to be on the left of the binary number and it is mirrored
		{
			row = row<<1;
			row |= matrix[x][y];			
		}
		dotMatrix_writeColumn(x,row);
	}
	
}

void dotMatrix_writeColumn(int column, int row)
{
	dotMatrix_start();
	
	dotMatrix_tx(0xE0);
	dotMatrix_tx(column*2);
	dotMatrix_tx(row);
	
	dotMatrix_stop();
}

void dotMatrix_clearScreen()
{
	int i = 0;
	for(i =0; i<8;i++)
	{
		dotMatrix_writeColumn(i,0);
	}	
}

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
