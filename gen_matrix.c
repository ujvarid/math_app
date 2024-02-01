#include "gen_matrix.h"

void freeMatrix(int ** matrix)
{
    free(*matrix);
    *matrix = NULL;
}

void startpos(int * row, int * col, short dimension, char depDir, char rotDir [])
{
    if(dimension % 2 == 0) 
    {
        switch (depDir)
        {
        case 'l': 
            if(strcmp(rotDir, "cw") == 0)
            {
                *col = (dimension/2);
                *row = (dimension/2);
            }
            else
            {
                *col = dimension/2;
                *row = (dimension/2)-1;
            }
            break;
        case 'r': 
            if(strcmp(rotDir, "cw") == 0)
            {
                *col = (dimension/2)-1;
                *row = (dimension/2)-1;
            }
            else
            {
                *col = (dimension/2)-1;
                *row = (dimension/2);
            }
            break;
        case 'd':
            if(strcmp(rotDir, "cw") == 0)
            {
                *col = (dimension/2);
                *row = (dimension/2) - 1;
            }
            else
            {
                *col = (dimension/2) - 1;
                *row = (dimension/2) - 1;
            }
            break;
        case 'u': 
            if(strcmp(rotDir, "cw") == 0)
            {
                *col = (dimension/2) - 1;
                *row = (dimension/2);
            }
            else
            {
                *col = (dimension/2);
                *row = (dimension/2);
            }
            break;
        }
    }
    else 
    {
        *row = (dimension / 2);
        *col = (dimension / 2);
    }
}

void generateSpiralMatrixDown(short dimension, int *matrix, char depDir, char rotDir [])
{
    int num = 1;
    int row,col;
    startpos(&row, &col, dimension, depDir, rotDir); 
    matrix[row * dimension + col] = num++;          
    if (strcmp(rotDir, "cw") == 0)
    {
        for (int k = 1; k < dimension; k += 2) 
        {
            // Move down
            for (int i = 0; i < k; ++i)
                matrix[(++row) * dimension + col] = num++;
            // Move left
            for (int i = 0; i < k; ++i)
                matrix[row * dimension + (--col)] = num++;
            // Move up
            if (k + 1 < dimension) 
            {
                for (int i = 0; i < k + 1; ++i)
                    matrix[(--row) * dimension + col] = num++;
            }
            // Move right
            if (k + 1 < dimension) 
            {
                for (int i = 0; i < k + 1; ++i)
                    matrix[row * dimension + (++col)] = num++;
            }
        }
        if(dimension % 2 == 0)
        {
            // Fill the first coloumn with decreasing elements from the first element of the matrix
            short maxnum = dimension * dimension;
            for (int i = 0; i < dimension; ++i) 
                matrix[i * dimension] = maxnum--; 
        }
        else 
        {
            // Fill the last coloumn with increasing elements from the first element of the last coloumn  
            num = dimension * (dimension-1);
            for(int i = 0; i < dimension; ++i)
                matrix[i * dimension + (dimension-1)] = ++num;
        }
    }
    else
    {
        for (int k = 1; k < dimension; k += 2) {
            // Move down
            for (int i = 0; i < k; ++i)
                matrix[(++row) * dimension + col] = num++;
            
            // Move right
            for (int i = 0; i < k; ++i)
                matrix[row * dimension + (++col)] = num++;

            // Move up
            if (k + 1 < dimension) 
            {
                for (int i = 0; i < k + 1; ++i)
                    matrix[(--row) * dimension + col] = num++;
            }
            // Move left
            if (k + 1 < dimension) 
            {
                for (int i = 0; i < k+1; ++i)
                    matrix[row * dimension + (--col)] = num++;
            }
        }
        if(dimension % 2 == 0)
        {
            //Fill the last coloumn with increasing elements from the matrices last element
            short maxnum = dimension * dimension;
            for (int i = 0; i < dimension; ++i)
            {
                matrix[i * dimension + (dimension-1)] = maxnum--;
            }
        }
        else
        {
            //Fill the first coloumn with increasing elements from the first element of the matrix (currently num)
            --num;
            for (int i = 0; i < dimension; ++i) 
                matrix[i * dimension] = num++; 
        }
    }
}

void generateSpiralMatrixUp(short dimension, int *matrix, char depDir, char rotDir []) 
{
    int num = 1; 
    int row,col;
    startpos(&row, &col, dimension, depDir, rotDir);
    matrix[row * dimension + col] = num++;
    if(strcmp(rotDir, "ccw") == 0)
    {
        for (int k = 1; k < dimension; k += 2) {
            // Move up
            for (int i = 0; i < k; ++i)
                matrix[(--row) * dimension + col] = num++;
            // Move left
            for (int i = 0; i < k; ++i)
                matrix[row * dimension + (--col)] = num++;
            // Move down
            if (k + 1 < dimension) 
            {
                for (int i = 0; i < k + 1; ++i)
                    matrix[(++row) * dimension + col] = num++;
            }
            // Move right
            if (k + 1 < dimension) {
                for (int i = 0; i < k + 1; ++i)
                    matrix[row * dimension + (++col)] = num++;
            }
        }
        if (dimension % 2 == 0) 
        {
            // Fill the first coloumn with increasing values until the max value 
            --num;
            for (int i = 0; i < dimension; ++i) 
                    matrix[i * dimension] = num++; 
        }
        else
        {
            // Fill the last coloumn with last row last element incremented 
            short maxnum = dimension * dimension;
            for (int i = 0; i < dimension; ++i)
            {
                matrix[i * dimension + (dimension-1)] = maxnum--;
            }
        }
    }
    else
    {
        for (int k = 1; k < dimension; k += 2) 
        {          
            // Move up
            for (int i = 0; i < k; ++i)
                matrix[(--row) * dimension + col] = num++;
            // Move right
                for (int i = 0; i < k; ++i)
                    matrix[row * dimension + (++col)] = num++;
            // Move down
            if (k + 1 < dimension) 
            {
                for (int i = 0; i < k + 1; ++i)
                    matrix[(++row) * dimension + col] = num++;
            }
            // Move left
            if (k + 1 < dimension) 
            {
                for (int i = 0; i < k + 1; ++i)
                    matrix[row * dimension + (--col)] = num++;
            }
        }
        if (dimension % 2 == 0) 
        {
            // FIll the last coloumn with increasing elements from the last element of the first row
            num = dimension * (dimension-1);
            for(int i = 0; i < dimension; ++i)
                matrix[i * dimension + (dimension-1)] = ++num;
        }
        else
        {
            // Fill the first coloumn with decreasing values from the maxnum
            short maxnum = dimension*dimension;
            for (int i = 0; i < dimension; ++i) 
                    matrix[i * dimension] = maxnum--; 
        }
    }
}

void generateSpiralMatrixLeft(short dimension, int *matrix, char depDir, char rotDir [])  
{
    int num = 1;
    int row,col;
    startpos(&row, &col, dimension, depDir, rotDir);
    matrix[row * dimension + col] = num++;
    if(strcmp(rotDir, "ccw") == 0)
    {
        for (int k = 1; k < dimension; k += 2) {
            // Move left
            for (int i = 0; i < k; ++i)
                matrix[row * dimension + (--col)] = num++;

            // Move down
            for (int i = 0; i < k; ++i)
                matrix[(++row) * dimension + col] = num++;

            // Move right
            if (k + 1 < dimension) {
                for (int i = 0; i < k + 1; ++i)
                    matrix[row * dimension + (++col)] = num++;
            }

            // Move up
            if (k + 1 < dimension) {
                for (int i = 0; i < k + 1; ++i)
                    matrix[(--row) * dimension + col] = num++;
            }
        }
        if(dimension % 2 == 0)
        {
            // Fill the remaining elements in the last iteration left column and the last row 
            for (int i = 0; i < dimension - 1; ++i)
                matrix[row * dimension + (++col)] = num++;
        }
        else
        {
            // Fill the remaining elements in the last iteration first row 
            short maxnum = dimension * dimension;
            for (int i = 0; i < dimension; ++i)
            {
                matrix[i] = maxnum--;
            } 
        }
    }
    else
    {
        for (int k = 1; k < dimension; k += 2) {
            // Move left
            for (int i = 0; i < k; ++i)
                matrix[row * dimension + (--col)] = num++;
            // Move up
                for (int i = 0; i < k; ++i)
                    matrix[(--row) * dimension + col] = num++;
            // Move right
            if (k + 1 < dimension) {
                for (int i = 0; i < k + 1; ++i)
                    matrix[row * dimension + (++col)] = num++;
            }
            // Move down
            if (k + 1 < dimension) {
                for (int i = 0; i < k+1; ++i)
                    matrix[(++row) * dimension + col] = num++;
            }

        }
        if(dimension % 2 == 0)
        {
            // Fill the remaining elements in the last iteration left column and the last row
            for (int i = 0; i < dimension - 1; ++i)
                matrix[row * dimension + (++col)] = num++;
        }
        else
        {
            // Fill the last row with increasing elements from the last value of the matrix 
            short maxnum = dimension * dimension;
            for (int i = 0; i < dimension; ++i)
            {
                matrix[(dimension - 1) * dimension + i] = maxnum--;
            }
            
        }
    }
}

void generateSpiralMatrixRight(short dimension, int *matrix, char depDir, char rotDir []) 
{
    int num = 1;
    int row, col;
    startpos(&row, &col, dimension,depDir, rotDir);
    matrix[row * dimension + col] = num++;
    if(strcmp(rotDir, "cw") == 0)
    {
        for (int k = 1; k < dimension; k += 2) {
            // Move right
            for (int i = 0; i < k; ++i)
                matrix[row * dimension + (++col)] = num++;
            // Move down
            for (int i = 0; i < k; ++i)
                matrix[(++row) * dimension + col] = num++;
            // Move left
            if((k+1) < dimension)
            {
                for (int i = 0; i < k + 1; ++i)
                    matrix[row * dimension + (--col)] = num++;
            }
            // Move up
            if((k+1) < dimension)
            {
                for (int i = 0; i < k + 1; ++i)
                    matrix[(--row) * dimension + col] = num++;
            }
        }
        if (dimension % 2 == 0) 
        {
            // Fill the last row with the last element incremented
            short maxnum = dimension * dimension;
            for (int i = 0; i < dimension; ++i)
                matrix[(dimension - 1) * dimension + i] = maxnum--;
        }
        else
        {
            // Fill the remaining elements in the last iteration (bottom-right corner)
            for (int i = 0; i < dimension - 1; ++i)
                matrix[row * dimension + (++col)] = num++;
        }
    }
    else
    {
        for (int k = 1; k < dimension; k += 2) {
            // Move right
            for (int i = 0; i < k; ++i)
                matrix[row * dimension + (++col)] = num++;

            // Move up
            for (int i = 0; i < k; ++i)
                matrix[(--row) * dimension + col] = num++;
            // Move left
            if((k+1) < dimension){
                for (int i = 0; i < k + 1; ++i)
                    matrix[row * dimension + (--col)] = num++;
            }
            // Move down
            if((k+1) < dimension){
            for (int i = 0; i < k + 1; ++i)
                matrix[(++row) * dimension + col] = num++;
            }
        }
        if (dimension % 2 == 0) 
        {
            // Fill the first row with decreasing elements of the maxnum
            short maxnum = dimension * dimension;
            for(int i = 0; i < dimension; ++i)
                matrix[i] = maxnum--;
        }
        else
        {
            // Fill the last row with the last element of the first coloumn incremented
            --num;
            for (int i = 0; i < dimension; ++i)
                matrix[(dimension - 1) * dimension + i] = num++;
        }
    }
}

void getDimension(short *dimension) 
{
    short tempdimension;
    do {
        printf("\nDimension of the matrix: ");
        scanf(" %hd", &tempdimension);
        clearInputBuffer();
        if(tempdimension < 1 || tempdimension > 20)
        {
            printf("\n\n\t>> The dimension of the matrix must be between 1-20. <<\n\n");
            tempdimension = -1; 
        }
    } while (tempdimension == -1);
    *dimension = tempdimension;
}

void getDepartureDirection(char *depDir)
{
    char tempdepDir;
    do {
        printf("\nPlease select a departure direction:\n");
        printf("\n u ~ up");
        printf("\n d ~ down");
        printf("\n r ~ right");
        printf("\n l ~ left\n");
        printf("\n\tChoice: ");
        scanf(" %c", &tempdepDir);
        clearInputBuffer();
        if(tempdepDir != 'u' && tempdepDir != 'd' && tempdepDir != 'r' && tempdepDir != 'l')
        {
            printf("\n\n\t>> Please select a valid option. <<\n\n");
            tempdepDir = '\0';
        } 
    } while (tempdepDir == '\0');
    *depDir = tempdepDir;
}

void getRotationDirection(char rotDir[]) 
{
    char temprotDir [2];
    do { 
        printf("\nPlease select the direction of the rotation:\n");
        printf("\n cw ~ clockwise");
        printf("\n cc ~ counterclockwise\n");
        printf("\n\tChoice: ");
        scanf(" %2c", temprotDir);
        clearInputBuffer();
        if ((strcmp(temprotDir, "cw") != 0 && strcmp(temprotDir, "cc") != 0))
        {
            printf("\n\n\t>> Please select from the options above <<\n\n");
        }
    } while (strcmp(temprotDir, "cw") != 0 && strcmp(temprotDir, "cc") != 0);
    
    if(strcmp(temprotDir, "cc") == 0) 
    {
        rotDir[0] = 'c';
        rotDir[1] = 'c';
        rotDir[2] = 'w';
    }
    else
    {
        rotDir[0] = 'c';
        rotDir[1] = 'w';
        rotDir[2] = '\0';
    }
}

void generate_matrix(int **matrix, short *dimension, char * depDir, char rotDir [])
{   
    getDimension(dimension);
    getDepartureDirection(depDir);
    getRotationDirection(rotDir);

    *matrix = (int *)malloc((*dimension) * (*dimension) * sizeof(int));
    if (matrix == NULL)
    {
        printf("\n>> Memory allocation failed. Exiting the program. <<\n");
        exit(EXIT_FAILURE); 
    }
    switch (*depDir)
    {
    case 'u':
        generateSpiralMatrixUp(*dimension, *matrix, *depDir, rotDir);
        break;
    case 'd':
        generateSpiralMatrixDown(*dimension, *matrix, *depDir, rotDir);
        break;
    case 'r':
        generateSpiralMatrixRight(*dimension, *matrix, *depDir, rotDir);
        break;
    case 'l':
        generateSpiralMatrixLeft(*dimension, *matrix, *depDir, rotDir);
        break;
    }
}