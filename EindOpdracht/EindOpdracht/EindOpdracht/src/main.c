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
	/* Insert application code here, after the board has been initialized. */
}
