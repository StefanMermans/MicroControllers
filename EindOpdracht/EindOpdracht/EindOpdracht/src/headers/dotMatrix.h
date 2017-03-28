/*
 * dotMatrix.h
 *
 * Created: 23-3-2017 11:34:34
 *  Author: Stefan
 */


#ifndef DOTMATRIX_H_
#define DOTMATRIX_H_

// external library includes
#include <asf.h>

// Function prototypes
//sends the start command for the dotmatrix.
void dotMatrix_start(void);
//sends the end command for the dotmatrix
void dotMatrix_stop(void);
//initialze the dotmatrix
void dotMatrix_init(void);
//writes data to the dotmatrix.
//@param: data
void dotMatrix_tx(unsigned char);
//writes data to a specific column.
//@param: the column in witch will be written and the row in witch will be written.
void dotMatrix_writeColumn(int,int);
//clears the dotmtraix.
void dotMatrix_clearScreen(void);
//writes a double 8 by 8 array on the dotmatrix 1 = ON 0 = OFF
//@param: a double 8 by 8 array witch must contain the value 1 or 0.
void dotMatrix_displayMatrix(int[8][8]);

#endif /* DOTMATRIX_H_ */
