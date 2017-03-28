/*
 * snake.c
 *
 * Created: 23-3-2017 13:22:37
 *  Author: Stefan
 */
// External library includes
#include <stdlib.h>

// Internal project includes
#include "../headers/snake.h"
#include "../headers/dotMatrix.h"


int display[GRID_SIZE][GRID_SIZE];
int foodLocation[2];
Snake snake;

void snake_init(){
    // Create the snake
    // create the first segment of the snake
    Segment segment;
    segment.isHead = 1;
    segment.position[VECT_X] = 0;
    segment.position[VECT_Y] = 0;

    // Add the first segment to the snake.
    snake.segments[0] = segment;
    snake.nSegments = 1;
    snake.direction = DIRECTION_UP;

    snake_addSegment();
    snake_addSegment();

    snake_createFood();
}

void snake_setDirection(int direction){
    snake.direction += direction;

    if(snake.direction > DIRECTION_DOWN){
        snake.direction = DIRECTION_LEFT;
    } else if(snake.direction < DIRECTION_LEFT){
        snake.direction = DIRECTION_DOWN;
    }
}

void snake_addSegment(){
    Segment segment;
    segment.isHead = 0;

    snake.segments[snake.nSegments] = segment;
    snake.nSegments += 1;
}

void snake_move(int direction[2]){
    for(int i = (snake.nSegments - 1); i > 0; i--){
        snake.segments[i].position[VECT_X] = snake.segments[i - 1].position[VECT_X];
        snake.segments[i].position[VECT_Y] = snake.segments[i - 1].position[VECT_Y];
    }

    snake.segments[0].position[VECT_X] += direction[VECT_X];
    snake.segments[0].position[VECT_Y] += direction[VECT_Y];

    if(snake.segments[0].position[VECT_X] >= GRID_SIZE){
        snake.segments[0].position[VECT_X] = 0;
    } else if (snake.segments[0].position[VECT_X] < 0){
        snake.segments[0].position[VECT_X] = GRID_SIZE - 1;
    }

    if(snake.segments[0].position[VECT_Y] >= GRID_SIZE){
        snake.segments[0].position[VECT_Y] = 0;
    } else if(snake.segments[0].position[VECT_Y] < 0){
        snake.segments[0].position[VECT_Y] = GRID_SIZE - 1;
    }
}

void snake_clearDisplay(){
    // Initialse the display array with zeros
    for(int i = 0; i < GRID_SIZE; i++){
        for(int ii = 0; ii < GRID_SIZE; ii++){
            display[i][ii] = 0;
        }
    }
}

void snake_createFood(){
    int possibleLocations[SEGMENT_MAX][2];
    int locationCount = 0;

    for(int i = 0; i < 8; i++){
        for(int ii = 0; ii < 8; ii++){

            int found = 0;
            for(int iii = 0; iii < snake.nSegments; iii++){
                if(snake.segments[iii].position[VECT_X] == i &&
                   snake.segments[iii].position[VECT_Y] == ii){
                    found = 1;
                }
            }
            if(!found){
                possibleLocations[locationCount][VECT_X] = i;
                possibleLocations[locationCount][VECT_Y] = ii;
                locationCount += 1;
            }
        }
    }

    int location = rand() % locationCount; // TODO test if this works correctly

    foodLocation[VECT_X] = possibleLocations[location][VECT_X];
    foodLocation[VECT_Y] = possibleLocations[location][VECT_Y];
}

void snake_draw(){
    snake_clearDisplay();

    for(int i = 0; i < snake.nSegments; i++){
        display[snake.segments[i].position[VECT_X]][snake.segments[i].position[VECT_Y]] = 1;
    }
    display[foodLocation[VECT_X]][foodLocation[VECT_Y]] = 1;

    dotMatrix_displayMatrix(display);
}

void snake_step(){
    int direction[2] = {0,0};

    for(int i = 0; i < snake.nSegments; i++){

        switch (snake.direction) {
            case DIRECTION_UP:
                direction[VECT_Y] = 1;
                break;
            case DIRECTION_DOWN:
                direction[VECT_Y] = -1;
                break;
            case DIRECTION_LEFT:
                direction[VECT_X] = -1;
                break;
            case DIRECTION_RIGHT:
                direction[VECT_X] = 1;
                break;
            default:
                break;
        }

        snake_move(direction);
    }

    if(snake.segments[0].position[VECT_X] == foodLocation[0] &&
       snake.segments[0].position[VECT_Y] == foodLocation[1]){
        snake_addSegment();
        snake_createFood();
    }
}
