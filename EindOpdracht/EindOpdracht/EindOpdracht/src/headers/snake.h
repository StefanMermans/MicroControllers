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
#define DIRECTION_DOWN 2

// Use for the x and y variables in a grid
#define VECT_X 0
#define VECT_Y 1

// The maximum number of segments
// This is determined by the amount of dots on the display 8 * 8 = 64
#define SEGMENT_MAX 64

// A single segment in the snake represented by a dot on the display
// Members:
//     position: 2d vector containing X and Y location on the grid
//     isHead: boolean wether the segment is the head or not
typedef struct{
    int position[2];
    int isHead;
} Segment;

// The struct of the snake
// members:
//     segments: a list of every segment in the snake
//     nSegments: int value indicating the amount of segments present
//     direction: int value
typedef struct{
    Segment segments[SEGMENT_MAX];
    int nSegments;
    int direction;
} Snake;

// Function prototypes

// Initialse the snake game logic.
// This function starts the game anew.
void snake_init(void);

// Make a step in the game logic.
void snake_step(void);

// Draw the current state of the game to the dotMatrix.
void snake_draw(void);

// Set the new direction of the snake based on input
// @param int: DIRECTION_LEFT for left or DIRECTION_RIGHT for right
void snake_setDirection(int direction);

// Clear the internal display array of the game.
// This does not send any data to the actual dotmatrix.
void snake_clearDisplay(void);

// Create the food at a open location
void snake_createFood(void);

// Move the snake in a direction
// @param int[2]: a normalised 2d matrix for the direction
void snake_move(int direction[2]);

// Add a segment to the snake and update the score
void snake_addSegment(void);

// Add a segment to the snake at a specific point.
// Does not update the score
// @param int x: the x location on the grid
// @param int y: the y location on the grid
void snake_addSegmentAtPoint(int x, int y);

// Get the highScore
// @return int: The highScore
int snake_highScore(void);

// Write the current score to the display
void snake_writeScore(void);

// Get the score
// @return int: the score
int snake_score(void);

#endif
