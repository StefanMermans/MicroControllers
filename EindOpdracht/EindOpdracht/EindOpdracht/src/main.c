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
	dotMatrix_clearScreen();
	int y=0;
	int x=0;
	int matrix[8][8];
	int toggle = 0;

	for(x = 0; x<8; x++)
	{
		//toggle= !toggle;
		for(y=0; y<8; y++)
		{
			//toggle= !toggle;
			if(x==y)
				toggle = 1;
			else
				toggle = 0;
			matrix[x][y] = 0;
		}
	}

	dotMatrix_displayMatrix(matrix);
	
}
