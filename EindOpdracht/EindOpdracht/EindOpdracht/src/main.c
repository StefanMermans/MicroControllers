// external library includes
#include <asf.h>

// internal project includes
#include "../headers/wait.h"
#include "../headers/dotMatrix.h"

int main (void)
{
	board_init();

	dotMatrix_clearScreen();
	dotMatrix_init();

	snake_init();

	while(1){
		snake_step();

		wait(500);
	}
}
