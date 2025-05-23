#include "matrix.h"

void matrix_welcome()
{
    printf("~~ Welcome to Basic matrix arithmetics ~~");
}

void matrix_help_print()
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

void matrix_copy(int *** matrix, short height, short width, int *** temp_matrix)
{
    matrix_generating(temp_matrix, height, width);
    matrix_init(temp_matrix,height,width);
    for (short i = 0; i < height; ++i)
    {
        for(short j = 0; j < width; ++j)
        {
            (*temp_matrix)[i][j] = (*matrix)[i][j];
        }
    }
    
}

void matrix_transpose(int *** matrix, short *height, short *width) 
{
    int ** temp_copy_matrix = NULL;
    
    matrix_copy(matrix, *height, *width, &temp_copy_matrix);
    matrix_free(*matrix, *height, *width);
    matrix_generating(matrix, *width, *height);

    // a mátrix transzponálása

    for(short i = 0; i < *height; ++i)
    {
        for (short j = 0; j < *width; ++j)
        {
            (*matrix)[j][i] = temp_copy_matrix[i][j];
        }
    }
    
    printf("\n\nTransposed matrix: \n\n\n");
    matrix_print(temp_copy_matrix, *height, *width);
    matrix_help_print();
    matrix_free(temp_copy_matrix, *height, *width);
    short temp = *width;
    *width = *height;
    *height = temp;
    matrix_print(*matrix, *height, *width);
}

void matrix_multiplication_lambda(int *** matrix, short height, short width)
{
    printf("\n\nPlease supply the value for the multiplication with the matrix\n\n\n");
    short lambda;
    bool bad_input;
    do
    {
        printf("value: ");
        if (scanf("%hd", &lambda) != 1)
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
    matrix_help_print();
    matrix_print(*matrix, height, width);
}

void matrix_multiplication(int *** matrix, short * height, short * width)
{
    int ** multiplication_matrix = NULL;
    short multiplication_matrix_height, multiplication_matrix_width;
    printf("\n\nThe height of the matrix to be multiplied must be equal to the current width of the matrix, so the height is %hd\n", *width);
    multiplication_matrix_height = *width;
    bool bad_input;
    do
    {
        printf("\nThe width of the matrix: ");
        if (scanf("%hd", &multiplication_matrix_width) != 1)
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
    matrix_generating(&multiplication_matrix, multiplication_matrix_height, multiplication_matrix_width);
    matrix_init(&multiplication_matrix, multiplication_matrix_height, multiplication_matrix_width);
    printf("\n\nPlease supply the values of the matrix for the multiplication:\n\n");
    for(short i = 0; i < multiplication_matrix_height; ++i)
    {
        for (short j = 0; j < multiplication_matrix_width; ++j)
        {
            bool bad_input;
            do
            {
                printf("(%hd, %hd): ", (i+1), (j+1));
                if (scanf("%d", &multiplication_matrix[i][j]) != 1)
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
        printf("\n");
    }

    printf("\n\nThe matrix that you will be multiplying with:\n\n");
    matrix_print(multiplication_matrix, multiplication_matrix_height, multiplication_matrix_width);
    printf("\n\n\t *\n\n");
    matrix_print(*matrix, *height, *width);
    matrix_help_print();

    int ** temp_matrix = NULL;
    
    matrix_copy(matrix, *height, *width, &temp_matrix);
    matrix_free(*matrix, *height, *width);

    short copy_width = *width;

    *width = multiplication_matrix_width;

    matrix_generating(matrix, *height, *width);
    matrix_init(matrix, *height, *width);

    int sum;

    for (short i = 0; i < *height; i++)
    {
        for (short j = 0; j < *width; j++)
        {
            sum = 0;
            for (short k = 0; k < copy_width; k++) 
            {
                sum += temp_matrix[i][k] * multiplication_matrix[k][j];
            }
            (*matrix)[i][j] = sum; 
        }
    }


    matrix_print(*matrix, *height, *width);
    matrix_free(multiplication_matrix, multiplication_matrix_height, multiplication_matrix_width);
    matrix_free(temp_matrix, *height, copy_width); 
}

void matrix_addition_constant(int *** matrix, short height, short width)
{
    printf("\n\nPlease supply the value for the additon with the matrix\n\n\n");
    short lambda;
    bool bad_input;
    do
    {
        printf("value: ");
        if (scanf("%hd", &lambda) != 1)
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
    matrix_help_print();
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
            bool bad_input;
            do
            {
                printf("(%hd, %hd): ", (i+1), (j+1));
                if (scanf("%d", &(temp_add_matrix)[i][j]) != 1)
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

    matrix_help_print();

    for(short i = 0; i < height; ++i)
    {
        for (short j = 0; j < width; ++j)
        {
            (*matrix)[i][j] += temp_add_matrix[i][j];
        }
    }

    matrix_print(*matrix, height, width);
    matrix_free(temp_add_matrix, height, width);
}

long matrix_determinant(int ** matrix, short height, short width)
{
    long det = 0;
    
    // 2x2-es mátrix

    if(height == 2)
    {
        det = (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
        return det;
    }

    // nxn-es mátrix

    else 
    {
        short ii, jj;
        long temp_det;

	    for(short k = 0; k < width; ++k)
	    {
            temp_det = 0;

    		//printf("\n\n%hd. submatrix: \n\n", k+1);
    
    		// itt ha generálok minden alkalommal egy n-1-es mátrixot, és arra ezt a függvényt rekurzívan meghívom?
    
    		int ** temp_det_matrix = NULL;
    		short temp_height = height - 1; // elég ez, hiszen négyzetes a mátrix
    
    		matrix_generating(&temp_det_matrix, temp_height, temp_height); 
            matrix_init(&temp_det_matrix, temp_height, temp_height);

            ii = 0;

    	    for(short i = 1; i < height; ++i)
    	   	{
                jj = 0;
                for(short j = 0; j < width; ++j)
                {
                    if(j != k)
                    {
                        temp_det_matrix[ii][jj] = matrix[i][j]; // mivel az i nem lehet szar mert 1-től kezdjük?? amugyis csak a j-t csekkoljuk
                        ++jj;
                    }			
                }
                ++ii;
            }
            
            temp_det = matrix_determinant(temp_det_matrix, temp_height, temp_height);
            temp_det *= matrix[0][k];

            // BE KELL SZOROZNI DE NEM JÓ A MÁTRIX-AL MERT 3X3 FELETT MÁR TEMP_MATRIX-AL KÉNE SZOROZNI AZAZ HÜLYESÉG MERT BÁRMIVEL MEGHÍVOD, AZ matrix-nak lesz elnevezve

            if(k % 2 == 0)
                det += temp_det;

            else
                det -= temp_det;

            matrix_free(temp_det_matrix, temp_height, temp_height);
    	}		
        return det;
    }
}

void matrix_input(int *** matrix, short * height, short * width)
{
    printf("\n\nFirst, please supply the values of the matrix that you want to compute with\n");
    do
    {
        printf("\n\nThe height of the matrix: ");
        scanf("%hd", height);
        if(*height <= 0)
            printf("\n\n>> Please enter a valid number greater than zero <<\n\n");
        while(getchar() != '\n'){};
    } while (*height <= 0);
    
    do
    {
        printf("\nThe width of the matrix: ");
        scanf("%hd", width);
        if(*width <= 0)
            printf("\n\n>> Please enter a valid number bigger than zero <<\n\n");
        while(getchar() != '\n'){};
    } while (*width <= 0);

    printf("\n");
    matrix_generating(matrix, *height, *width);
    matrix_init(matrix, *height, *width);
    for(short i = 0; i < *height; ++i)
    {
        for (short j = 0; j < *width; ++j)
        {
            bool bad_input;
            do
            {
                printf("(%hd, %hd): ", (i+1), (j+1));
                if (scanf("%d", &(*matrix)[i][j]) != 1)
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
        printf("\n");
    }
    matrix_print(*matrix, *height, *width);
}

char matrix_choice_input()
{
    char choice; 
    printf("\n\n\t\tMenu:\n\n");
    printf("0 ~ Matrix addtion with a matrix\n");
    printf("1 ~ Matrix addition with a constant\n");
    printf("2 ~ Matrix multiplication with a matrix\n");
    printf("3 ~ Matrix multiplication with a constant\n");
    printf("4 ~ Matrix transposing\n");
    printf("5 ~ Determinant calculating\n");
    printf("6 ~ Exit\n\n");
	do
    {
        printf("\n\tChoice: ");
        scanf(" %c", &choice);

        while(getchar() != '\n'){};

        if (choice < '0' || choice > '6')
            printf("\n\n>> Please enter a valid number between 0 and 5 <<\n\n");
    } while (choice < '0' || choice > '6');
    return choice;
}

void matrix_directing()
{
    int ** matrix = NULL;
    short height = 0, width = 0;
    char choice;
    bool bad_choice = false;

    matrix_welcome();
    matrix_input(&matrix, &height, &width);

    do
    {   
        do
        {
            choice = matrix_choice_input();
            switch (choice)
            {
                case '0':
                {
                    matrix_addition(&matrix, height, width);
                    break;
                }
                case '1':
                {
                    matrix_addition_constant(&matrix, height, width);
                    break;
                }
                case '2':
                {
                    matrix_multiplication(&matrix, &height, &width);
                    break;
                }
                case '3':
                {
                    matrix_multiplication_lambda(&matrix, height, width);
                    break;
                }
                case '4':
                {
                    matrix_transpose(&matrix, &height, &width);
                    break;
                }
                case '5':
                {
                    if(height != width)
                        printf("\n\n>> The supplied matrix has to be a square matrix to calculate its determinant <<\n\n");

		    else if(height == 1)
			    printf("\n\n\nThe determinant of the matrix is %d\n\n", matrix[0][0]);

                    else
                        printf("\n\n\nThe determinant of the matrix is %ld\n\n", matrix_determinant(matrix, height, width));

                    break;
                }
                case '6':
                {
                    printf("\n\n\tGoodbye!\n\n");
                    break;
                }
            }
        } while (bad_choice);
    } while (choice != '6');

    matrix_free(matrix, height, width);
}