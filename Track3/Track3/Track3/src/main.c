#include <asf.h>

#include "Headers/LCD.h"
#include "Headers/Counter.h"

int main (void)
{
	board_init();

	LCD_init();
	
	counter_init();
	//LCD_display_text("Hallo Diederich doei diederich");
}
