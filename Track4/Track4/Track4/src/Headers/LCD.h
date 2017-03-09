/*
 * LCD.h
 *
 * Created: 16-2-2017 10:29:17
 *  Author: Stefan
 */ 


#ifndef LCD_H_
#define LCD_H_


// function prototypes
void LCD_init();

void LCD_writeChar(unsigned char data);
void LCD_writeLine1(char * text);
void LCD_writeline2(char * text);

void LCD_command(unsigned char data);
void LCD_display_text(char *str);

#endif /* LCD_H_ */