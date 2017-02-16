#include <asf.h>

#include "Headers/LCD.h"

int main (void)
{
	/* Insert system clock initialization code here (sysclk_init()). */

	board_init();

	LCD_init();
}
