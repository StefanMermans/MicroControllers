#ifndef INPUT_H
#define INPUT_H

// Initialise the input
// This has to be called before the input module can be used
void input_init(void);

// Check the lastest input value
// @return int: DIRECTION_LEFT or DIRECTION_RIGHT indicating the direction
int input_check(void);

// Update the input based on the user input
void input_update(void);

// Reset the lastest input to 0
void input_reset(void);

#endif
