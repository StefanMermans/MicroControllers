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


int display[GRID_SIZE][GRID_SIZE];
int foodLocation[2];
Snake snake;

void snake_init(){
    // Initialse the display array with zeros
    for(int i = 0; i < GRID_SIZE; i++){
        for(int ii = 0; ii < GRID_SIZE; ii++){
            display[i][ii] = 0;
        }
    }

    // Create the snake
    // create the first segment of the snake
    Segment segment;
    segment.isHead = 1;
    segment.position[0] = 4;
    segment.position[1] = 4;

    // Add the first segment to the snake.
    snake.segments[0] = segment;
    snake.nSegments = 1;
    snake.direction = DIRECTION_UP;

    snake_createFood();
}

void snake_addSegment(){
    Segment segment;
    segment.isHead = 0;

    snake.segments[snake.nSegments] = segment;
    snake.nSegments += 1;
}

void snake_move(int direction[2]){
    for(int i = (snake.nSegments - 1); i > 0; i--){
        snake.segments[i].position[0] = snake.segments[i - 1].position[0];
        snake.segments[i].position[1] = snake.segments[i - 1].position[1];
    }

    snake.segments[0].position[0] += direction[0];
    snake.segments[0].position[1] += direction[1];
}

void snake_createFood(){
    int possibleLocations[SEGMENT_MAX][2];
    int locationCount = 0;

    for(int i = 0; i < 8; i++){
        for(int ii = 0; ii < 8; ii++){

            int found = 0;
            for(int iii = 0; iii < snake.nSegments; iii++){
                if(snake.segments[iii].position[0] == i &&
                   snake.segments[iii].position[1] == ii){
                    found = 1;
                }
            }
            if(!found){
                possibleLocations[locationCount][0] = i;
                possibleLocations[locationCount][1] = ii;
                locationCount += 1;
            }
        }
    }

    int location = rand() % locationCount; // TODO test if this works correctly

    foodLocation[0] = possibleLocations[location][0];
    foodLocation[1] = possibleLocations[location][1];
}

void snake_step(){
    int direction[2] = {0,0};

    for(int i = 0; i < snake.nSegments; i++){

        switch (snake.direction) {
            case DIRECTION_UP:
                direction[1] = 1;
                break;
            case DIRECTION_DOWN:
                direction[1] = -1;
                break;
            case DIRECTION_LEFT:
                direction[0] = -1;
                break;
            case DIRECTION_RIGHT:
                direction[0] = 1;
                break;
            default:
                break;
        }

        snake_move(direction);
    }

    if(snake.segments[0].position[0] == foodLocation[0] &&
       snake.segments[1].position[1] == foodLocation[1]){
        snake_addSegment();
        snake_createFood();   
    }
}
