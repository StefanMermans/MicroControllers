/*
 * snake.h
 *
 * Created: 23-3-2017 13:23:45
 *  Author: Stefan
 */
#ifndef SNAKE_H_
#define SNAKE_H_

// The size of the square grid
#define GRID_SIZE 8

// The direction in which the snake will move.
#define DIRECTION_LEFT -1
#define DIRECTION_UP 0
#define DIRECTION_RIGHT 1
#define DIRECTION_DOWN 4

// Use for the x and y variables in a grid
#define VECT_X 0
#define VECT_Y 1

// The maximum number of segments
// This is determined by the amount of dots on the display 8 * 8 = 64
#define SEGMENT_MAX 64

// A single segment in the snake represented by a dot on the display
typedef struct{
    int position[2];
    int isHead;
} Segment;

// The snake itself.
typedef struct{
    Segment segments[SEGMENT_MAX];
    int nSegments;
    int direction;
} Snake;

// Function prototypes
void snake_init(void);
void snake_step(void);
void snake_draw(void);
// Set the new direction of the snake based on input
// use DIRECTION_LEFT for left, and DIRECTION_RIGHT for right
void snake_setDirection(int direction);

void snake_clearDisplay(void);
void snake_createFood(void);
void snake_move(int direction[2]);
void snake_addSegment(void);

#endif
