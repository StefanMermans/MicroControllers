// external library includes
#include <asf.h>

// internal project includes
#include "../headers/wait.h"
#include "../headers/dotMatrix.h"

void testDotMatrix(void);

int main (void)
{
	/* Insert system clock initialization code here (sysclk_init()). */

	board_init();

	dotMatrix_init();

	testDotMatrix();
	/* Insert application code here, after the board has been initialized. */
}

void testDotMatrix()
{
	int i =0;
	int x = 1;
	while(1)
	{
				dotMatrix_start();
				dotMatrix_tx(0xE0);	// Display I2C addres + R/W bit
				dotMatrix_tx(0x00+i);	// Address
				dotMatrix_tx(x);	// data
				dotMatrix_stop();

				wait(100);

				dotMatrix_start();
				dotMatrix_tx(0xE0);	// Display I2C addres + R/W bit
				dotMatrix_tx(0x0+i);	// Address
				dotMatrix_tx(x);	// data
				dotMatrix_stop();
				
				wait(100);
				
				x*=2;
				if(x==16)
				{
					i+=2;
					if(i==16)
					i=0;
					x=1;
				}
	}
}
