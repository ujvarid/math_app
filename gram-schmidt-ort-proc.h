#ifndef GRSCH

#define GRSCH

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

void grsch_welcome();
void vector_copy(double * temp_vector, double * original_vector, short component_num);
void scalar_subtraction(double *vector1, double *vector2, double * result_vector, short component_num);
void scalar_product_with_lambda(double * vector, short component_num, double lambda);
double dot_product(double *vector1, double *vector2, short component_num);
void base_vectors_input(short *component_num, short *base_vector_num, double ***vector_space);
void gram_schmidt_ort_proc(double ***orthogonal_system, double *** orthonormal_system, double **vector_space, short component_num, short base_vector_num);
void create_orthonormal_system(double *** orthonormal_system, short component_num, short base_vector_num);
void create_orthogonal_system(double *** orthogonal_system, short component_num, short base_vector_num);
void free_vector_spaces(double **orthogonal_system, double **vector_space, double ** orthonormal_system, short base_vector_num);
void print_result(double **orthogonal_system, double ** orthonormal_system, short component_num, short base_vector_num);
void grsch_directing();

#endif