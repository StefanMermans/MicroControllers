/*
 * LCD.h
 *
 * Created: 16-2-2017 10:29:17
 *  Author: Stefan
 */


#ifndef LCD_H_
#define LCD_H_


// function prototypes
void LCD_init(void);

// Write a single character to the display
// @oaram unsigned char: The character which will be written
void LCD_writeChar(unsigned char data);

// Write a string to the top line of the display
// @param char *: the pointer to the string
void LCD_writeLine1(char * text);

// Write a string to the bottom line of the display
// @param char *: the pointer to the string
void LCD_writeline2(char * text);

// Send a command the the display
// @param unsigned char: the data which will be sent to the display
void LCD_command(unsigned char data);

// Display a string of text on the display
// @param char *: The string which will be displayed
void LCD_display_text(char *str);

#endif /* LCD_H_ */
