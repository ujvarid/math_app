#ifndef MTRX

#define MTRX

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void matrix_free(int ** matrix, short height, short width);
void matrix_generating(int *** matrix, short height, short width);
void matrix_print(int ** matrix, short height, short width);
void matrix_init(int *** matrix, short height, short width);
void matrix_transpose(int *** matrix, short *height, short *width);
void matrix_multiplication_lambda(int *** matrix, short height, short width);
void copy_matrix(int *** matrix, short height, short width, int *** temp_matrix);
void matrix_multiplication(int *** matrix, short * height, short * width);
void matrix_addition_constant(int *** matrix, short height, short width);
void matrix_addition(int *** matrix, short height, short width);
void matrix_determinant(int ** matrix, short height, short width);
void matrix_input(int *** matrix, short * height, short * width);
void matrix_welcome();
void matrix_choice_input(short * choice);
void matrix_directing();

#endif