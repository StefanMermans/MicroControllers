// external library includes
#include <asf.h>

// internal project includes
#include "../headers/wait.h"
#include "../headers/dotMatrix.h"
#include "../headers/snake.h"

int main (void)
{
	board_init();

	dotMatrix_clearScreen();
	dotMatrix_init();

	snake_init();

	while(1){
		snake_step();
		snake_draw();

		wait(1000);
	}
}
