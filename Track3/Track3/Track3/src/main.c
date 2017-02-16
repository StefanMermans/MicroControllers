#include <asf.h>

#include "Headers/LCD.h"

int main (void)
{
	board_init();

	LCD_init();
	
	LCD_display_text("Hallo Diederich doei diederich");
}
