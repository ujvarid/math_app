#ifndef MAIN

#define MAIN

#include <stdio.h>
#include <stdbool.h>
#include "dot_product.h"
#include "gram-schmidt-ort-proc.h"
#include "matrix.h"
#include "menu.h"
#include "gen_matrix.h"
#include "file_managing.h"

void exit_app();
void welcome();
void choice_input(short * choice);
void directing_math_app(short * choice);

#endif