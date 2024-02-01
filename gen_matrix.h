#ifndef GEN_MATRIX

#define GEN_MATRIX

#include "menu.h"

void startpos(int * row, int * col, short dimension, char depDir, char rotDir []);
void freeMatrix(int ** matrix);
void generateSpiralMatrixDown(short dimension, int *matrix, char depDir, char rotDir []);
void generateSpiralMatrixUp(short dimension, int *matrix, char depDir, char rotDir []);
void generateSpiralMatrixLeft(short dimension, int *matrix, char depDir, char rotDir []); 
void generateSpiralMatrixRight(short dimension, int *matrix, char depDir, char rotDir []);
void getDimension(short *dimension);
void getDepartureDirection(char *depDir);
void getRotationDirection(char rotDir[]);
void generate_matrix(int ** matrix, short *dimension, char * depDir, char rotDir []);

#endif