/*
 * assignmentb3.h
 *
 * Created: 9-2-2017 13:21:56
 *  Author: Camiel
 */ 


#ifndef ASSIGNMENTB3_H_
#define ASSIGNMENTB3_H_

#define hexTable 
				0x3F, // 0
				0x6,  // 1
				0x5B, // 2
				0x4F, // 3
				0x66, // 4
				0x6D, // 5
				0x7D, // 6
				0x07, // 7
				0x7F, // 8
				0x6F, // 9

				0x77, // A
				0x7c, // b
				0x39, // C
				0x5e, // d
				0x79, // E
				0x71, // F
				0x7b  // e (error)
#define number 0

// Internal includes
#include "../Headers/wait.h"

// External includes
#include <avr/io.h>

// Declarations
void runB3();
void display(int number);

#endif /* ASSIGNMENTB3_H_ */