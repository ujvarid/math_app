#include "matrix.h"

void printHelp()
{
    printf("\n\t |\n\t |\n\t V\n\n");   
}

void matrix_free(int ** matrix, short height, short width)
{
    for(short i = 0; i < height; ++i)
    {
        free(matrix[i]);
    }
    free(matrix);
}

void matrix_generating(int *** matrix, short height, short width)
{
    *matrix = (int**)malloc(sizeof(int *) * height);
    for(short i = 0; i < height; ++i)
    {
        (*matrix)[i] = (int *)malloc(sizeof(int) * width);
    }
}

void matrix_print(int ** matrix, short height, short width)
{
    for (short i = 0; i < height; ++i)
    {
        printf("\t");
        for (short j = 0; j < width; ++j)
        {
            printf(" %d", matrix[i][j]);
        }
        printf("\n");
    }
    
}

void matrix_init(int *** matrix, short height, short width)
{
    for (short i = 0; i < height; ++i)
    {
        for (short j = 0; j < width; ++j)
        {
            (*matrix)[i][j] = 0;
        }
    }
}

void matrix_transpose(int *** matrix, short *height, short *width) 
{
    int ** temp_copy_matrix = NULL;
    
    matrix_generating(&temp_copy_matrix, *height, *width);
    matrix_init(&temp_copy_matrix, *height, *width);
    
    for(short i = 0; i < *height; ++i)
    {
        for (short j = 0; j < *width; ++j)
        {
            temp_copy_matrix[i][j] = (*matrix)[i][j];
        }
    }
    
    matrix_free(*matrix, *height, *width);
    matrix_generating(matrix, *width, *height);

    for(short i = 0; i < *height; ++i)
    {
        for (short j = 0; j < *width; ++j)
        {
            (*matrix)[j][i] = temp_copy_matrix[i][j];
        }
    }
    matrix_free(temp_copy_matrix, *height, *width);
    printf("\n\nTransposed matrix: \n\n\n");
    short temp = *width;
    *width = *height;
    *height = temp;
    matrix_print(*matrix, *height, *width);
}

void matrix_multiplication_lambda(int *** matrix, short height, short width)
{
    printf("\n\nPlease supply the value for the multiplication with the matrix\n\n\n");
    short lambda;
    printf("value: ");
    scanf("%hd", &lambda);
    printf("\n\n");
    for(short i = 0; i < height; ++i) 
    {
        for(short j = 0; j < width; ++j)
        {
            printf(" %d ", (*matrix)[i][j]);
            (*matrix)[i][j] *= lambda;
        }
        if(i == height/2)
        {
            printf("\t * %hd", lambda);
        }
        printf("\n");
    }
    printHelp();
    matrix_print(*matrix, height, width);
}

void matrix_addition_constant(int *** matrix, short height, short width)
{
    printf("\n\nPlease supply the value for the additon with the matrix\n\n\n");
    short lambda;
    printf("value: ");
    scanf("%hd", &lambda);
    printf("\n\n");
    for(short i = 0; i < height; ++i) 
    {
        for(short j = 0; j < width; ++j)
        {
            printf(" %d ", (*matrix)[i][j]);
            (*matrix)[i][j] += lambda;
        }
        if(i == height/2)
        {
            printf("\t + %hd", lambda);
        }
        printf("\n");
    }
    printHelp();
    matrix_print(*matrix, height, width);
}

void matrix_addition(int *** matrix, short height, short width) 
{
    int ** temp_add_matrix = NULL;
    matrix_generating(&temp_add_matrix, height, width);
    matrix_init(&temp_add_matrix, height, width);

    printf("\n\nPlease supply the values of the matrix that you want to perform the addition with\n\n\n");

    for(short i = 0; i < height; ++i)
    {
        for (short j = 0; j < width; ++j)
        {
            printf("(%hd, %hd): ", (i+1), (j+1));
            scanf("%d", &(temp_add_matrix)[i][j]);
        }
        printf("\n");
    }

    for(short i = 0; i < height; ++i)
    {
        for(short j = 0; j < width; ++j)
        {
            printf(" %d ", (*matrix)[i][j]);
        }
        printf("\t");
        if(i == height/2)
        {
            printf(" +");
        }
        printf("\t");
        for(short j = 0; j < width; ++j)
        {
            printf(" %d ", temp_add_matrix[i][j]);
        }
        printf("\n");
    }

    printHelp();

    for(short i = 0; i < height; ++i)
    {
        for (short j = 0; j < width; ++j)
        {
            (*matrix)[i][j] += temp_add_matrix[i][j];
        }
    }

    matrix_print(*matrix, height, width);
    matrix_free(*matrix, height, width);
}

void matrix_input(int *** matrix, short * height, short * width)
{
    printf("\n\nThe height of the matrix: ");
    scanf("%hd", height);
    printf("\nThe width of the matrix: ");
    scanf("%hd", width);
    matrix_generating(matrix, *height, *width);
    matrix_init(matrix, *height, *width);
    for(short i = 0; i < *height; ++i)
    {
        for (short j = 0; j < *width; ++j)
        {
            printf("(%hd, %hd): ", (i+1), (j+1));
            scanf("%d", &(*matrix)[i][j]);
        }
        printf("\n");
    }
    matrix_print(*matrix, *height, *width);
}

void matrix_welcome()
{
    printf("~~ Welcome to Basic matrix arithmetics ~~");
    printf("\n\nMenu:\n");
	printf("0 ~ Adding a matrix to another matrix\n");
	printf("1 ~ Matrix multiplication with a constant\n");
	printf("2 ~ Matrix addition with a constant\n");
	printf("3 ~ Matrix transposing\n\n");
}

void matrix_choice_input(short * choice)
{
	printf("Choice: ");
	scanf("%hd", choice);
}

void matrix_directing()
{
    int ** matrix = NULL;
    short height = 0, width = 0;
    short choice;
    bool bad_choice = false;
    matrix_welcome();
    do
    {
        matrix_choice_input(&choice);
        if(choice <=3 && choice >= 0)
        {
            matrix_input(&matrix, &height, &width);
            switch (choice)
            {
            case 0:
            {
                matrix_addition(&matrix, height, width);
                break;
            }
            case 1:
            {
                matrix_multiplication_lambda(&matrix, height, width);
                break;
            }
            case 2:
            {
                matrix_addition_constant(&matrix, height, width);
                break;
            }
            case 3:
            {
                matrix_transpose(&matrix, &height, &width);
                break;
            }
            }
        }
        else
        {
            printf("\nInvalid choice, please choose again\n\n");
            bad_choice = true;
        }

    } while (bad_choice);

    matrix_free(matrix, height, width);
}

int main()
{
	matrix_directing();
}
