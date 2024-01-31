#ifndef DOTPR

#define DOTPR

#include <stdio.h>
#include <stdlib.h>

int dot_product_dp(int * vektor1, int * vektor2, short size);
void dot_product_input(short * size, int ** vektor1, int ** vektor2);
void dot_product_welcome();
void result(int * vektor1, int * vektor2, short size, int dotproduct);
void dot_product_directing();


#endif