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



	testDotMatrix();
	/* Insert application code here, after the board has been initialized. */
}

void testDotMatrix(){
	while(1)
	{
		dotMatrix_start();
		dotMatrix_tx(0xE0);	// Display I2C addres + R/W bit
		dotMatrix_tx(0x0E);	// Address
		dotMatrix_tx(0xFF);	// data
		dotMatrix_stop();

		wait(500);

		dotMatrix_start();
		dotMatrix_tx(0xE0);	// Display I2C addres + R/W bit
		dotMatrix_tx(0x0E);	// Address
		dotMatrix_tx(0x00);	// data
		dotMatrix_stop();

		wait(500);
	}
}
