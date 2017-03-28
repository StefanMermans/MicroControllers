#include <asf.h>

#include "../headers/input.h"
#include "../headers/snake.h"

int lastInput = 0;
int wasPressed = 0;

void input_init(){
    DDRA = 0x00;

    PORTA = 0x00;
}

void input_update(){
    if(PINA & 0x80 && !wasPressed){
        wasPressed = 1;
        lastInput =  DIRECTION_LEFT;
    } else if(PINA & 0x01 && !wasPressed){
        wasPressed = 1;
        lastInput = DIRECTION_RIGHT;
    } else if(PINA == 0x00){
        wasPressed = 0;
    }
}

void input_reset(){
    lastInput = 0;
}

int input_check(){
    return lastInput;
}
