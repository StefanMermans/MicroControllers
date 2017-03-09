#include <asf.h>
#include "Headers/LCD.h"
#include "Headers/ADC.h"
#include "Headers/Wait.h"
#include <stdio.h>

int main (void)
{
	board_init();
	
	DDRF = 0x00;
	DDRA = 0xFF;
	DDRB = 0xFF;

	ADC_INIT();
	LCD_init();
	
	while (1)
	{
		PORTB = ADCL;
		PORTA = ADCH;
		
		char text[16];
		
		sprintf(text, "ADCH: %i ADCL: %i", ADCH, ADCL);
		LCD_display_text(text);
		
		wait(100);
	}
}
