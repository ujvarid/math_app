#ifndef FILE_MANAGING

#define FILE_MANAGING

#include "menu.h"

#define MAX_FILENAME_LENGTH 50

void user_guide();
void save_matrix(int * matrix, short dimension, char depDir, char rotDir []);
void load_matrix(int ** matrix, short * dimension, char * depDir, char * rotDir);
void print_matrix(int * matrix, short dimension);
int str_real_length(char filename []);

#endif