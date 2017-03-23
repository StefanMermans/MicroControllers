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
void dotMatrix_start(void);
void dotMatrix_stop(void);
void dotMatrix_init(void);
void dotMatrix_tx(unsigned char);
void dotMatrix_writeColumn(int,int);
void dotMatrix_clearScreen(void);
void dotMatrix_displayMatrix(int[8][8]);

#endif /* DOTMATRIX_H_ */
