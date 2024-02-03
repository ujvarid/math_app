#include "gram-schmidt-ort-proc.h"

void grsch_welcome()
{
    printf("~~ Welcome to Gram-Schmidt ortogonalization process ~~\n\n");
}

void vector_copy(double * temp_vector, double * original_vector, short component_num)
{
    for (int i = 0; i < component_num; ++i)
    {
        temp_vector[i] = original_vector[i];
    }
}

void scalar_subtraction(double *vector1, double *vector2, double * result_vector, short component_num)
{
    for (int i = 0; i < component_num; ++i)
        result_vector[i] = vector1[i] - vector2[i];
}

void scalar_product_with_lambda(double * vector, short component_num, double lambda)
{
    for (int i = 0; i < component_num; i++)
    {
        vector[i] *= lambda;
    }
    
}

double dot_product(double *vector1, double *vector2, short component_num)
{
    double value = 0;
    for (int i = 0; i < component_num; ++i)
        value += vector1[i] * vector2[i];
    return value;
}

void base_vectors_input(short *component_num, short *base_vector_num, double ***vector_space)
{
    do
    {
        printf("\nNumber of base vectors of the vector space: ");
        scanf("%hd", base_vector_num);
        if(*base_vector_num <= 0)
            printf("\n\n>> Please enter a valid number greater than zero <<\n\n");
        while(getchar() != '\n'){};
    } while (*base_vector_num <= 0);

    *vector_space = (double **)malloc(sizeof(double *) * (*base_vector_num));

    do
    {
        printf("\nNumber of components of the base vectors: ");
        scanf("%hd", component_num);
        if(*component_num <= 0)
            printf("\n\n>> Please enter a valid number greater than zero <<\n\n");
        while(getchar() != '\n'){};
    } while (*component_num <= 0);

    printf("\n");

    for (int i = 0; i < *base_vector_num; ++i)
    {
        (*vector_space)[i] = (double *)malloc(sizeof(double) * (*component_num));

        for (int j = 0; j < *component_num; ++j)
        {
            bool bad_input;
            do
            {
                printf("The value of the %d. vector's %d. component: ", (i + 1), (j + 1));
                if (scanf("%lf", &(*vector_space)[i][j]) != 1)
                {
                    printf("\n\n>> Please enter a valid number. <<\n\n");
                    while (getchar() != '\n');
                    bad_input = true;
                }
                else
                {
                    bad_input = false;
                }
            } while (bad_input);
        }
    }
}

void gram_schmidt_ort_proc(double ***orthogonal_system, double *** orthonormal_system, double **vector_space, short component_num, short base_vector_num)
{
    double *temp_vector = (double *)malloc(sizeof(double) * component_num);

    for (int i = 0; i < base_vector_num; ++i)
    {
        vector_copy((*orthogonal_system)[i], vector_space[i], component_num); // u1 = b1

        for (int j = 0; j < i; ++j)
        {
            double projection = dot_product(vector_space[i], (*orthogonal_system)[j], component_num);
            double projection_of_itself = dot_product((*orthogonal_system)[j], (*orthogonal_system)[j], component_num);

            double lambda = projection / projection_of_itself;

            vector_copy(temp_vector, (*orthogonal_system)[j], component_num);
            scalar_product_with_lambda(temp_vector, component_num, lambda);
            scalar_subtraction((*orthogonal_system)[i], temp_vector, (*orthogonal_system)[i], component_num);
        }
    }
    free(temp_vector);

    double *temp_orthonorm_vector = (double *)malloc(sizeof(double) * component_num);

    for (int i = 0; i < base_vector_num; ++i)
    {
        double magnitude = dot_product((*orthogonal_system)[i],(*orthogonal_system)[i], component_num);
        vector_copy(temp_orthonorm_vector, (*orthogonal_system)[i], component_num);
        magnitude = sqrt(magnitude);

        if(magnitude > 0.0)
        {
            scalar_product_with_lambda(temp_orthonorm_vector, component_num, 1.0/magnitude);
            vector_copy((*orthonormal_system)[i], temp_orthonorm_vector, component_num);
        }
        else
            for(int j = 0; j < component_num; ++j)
                *orthonormal_system[i][j] = 0.0;
    }

    free(temp_orthonorm_vector);    
}

void create_orthonormal_system(double *** orthonormal_system, short component_num, short base_vector_num)
{
    *orthonormal_system = (double **)malloc(sizeof(double *) * base_vector_num);

    for (int i = 0; i < base_vector_num; ++i)
    {
        (*orthonormal_system)[i] = (double *)malloc(sizeof(double) * component_num);
    }
}

void create_orthogonal_system(double *** orthogonal_system, short component_num, short base_vector_num)
{
    *orthogonal_system = (double **)malloc(sizeof(double *) * (base_vector_num));

    for (int i = 0; i < base_vector_num; ++i)
    {
        (*orthogonal_system)[i] = (double *)malloc(sizeof(double) * (component_num));
    }
}

void free_vector_spaces(double **orthogonal_system, double **vector_space, double ** orthonormal_system, short base_vector_num)
{
    for (int i = 0; i < base_vector_num; ++i)
    {
        free(vector_space[i]);
        free(orthogonal_system[i]);
        free(orthonormal_system[i]);
    }
    free(orthogonal_system);
    free(orthonormal_system);
    free(vector_space);
}

void print_result(double **orthogonal_system, double ** orthonormal_system, short component_num, short base_vector_num)
{
    printf("\n~~~~~~~~~~~~ Orthogonal System ~~~~~~~~~~~~\n");

    for (int i = 0; i < base_vector_num; ++i)
    {
        printf("\n\t\tVector %d\n\n", (i + 1));
        for (int j = 0; j < component_num; ++j)
        {
            printf("\t\t%lf\n", orthogonal_system[i][j]);
        }
    }
    
    printf("\n");
    printf("\n\n");

    printf("\n~~~~~~~~~~~~ Orthonormal System ~~~~~~~~~~~~\n");

    for (int i = 0; i < base_vector_num; ++i)
    {
        printf("\n\t\tVector %d\n\n", (i + 1));
        for (int j = 0; j < component_num; ++j)
        {
            printf("\t\t%lf\n", orthonormal_system[i][j]);
        }
    }
    printf("\n");
}

void grsch_directing()
{
    grsch_welcome();
    short component_num = 0;
    short base_vector_num = 0;
    double **vector_space = NULL;
    double ** orthogonal_system = NULL;
    double ** orthonormal_system = NULL;
    base_vectors_input(&component_num, &base_vector_num, &vector_space);
    create_orthogonal_system(&orthogonal_system, component_num, base_vector_num);
    create_orthogonal_system(&orthonormal_system, component_num, base_vector_num);
    gram_schmidt_ort_proc(&orthogonal_system, &orthonormal_system, vector_space,component_num,base_vector_num);
    print_result(orthogonal_system, orthonormal_system,component_num,base_vector_num);
    free_vector_spaces(orthogonal_system, vector_space, orthonormal_system, base_vector_num);
}