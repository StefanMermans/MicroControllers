// external library includes
#include <asf.h>

// internal project includes
#include "../headers/wait.h"
#include "../headers/dotMatrix.h"
#include "../headers/snake.h"
#include "../headers/input.h"
#include "../headers/LCD.h"
#include <stdio.h>

int main (void)
{
	int tics = 0;

	board_init();

	LCD_init();
	LCD_writeLine1("Score: 0        ");
	LCD_writeline2("HighScore: 0    ");

	input_init();

	dotMatrix_init();
	dotMatrix_clearScreen();

	snake_init();

	while(1){
		input_update();


		if(tics >= 500){
			snake_setDirection(input_check());
			input_reset();

			snake_step();
			snake_draw();

			tics = 0;
		}

		tics += 1;
		wait(1);
	}
}
