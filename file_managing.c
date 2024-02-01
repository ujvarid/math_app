#include "file_managing.h"

void print_matrix(int * matrix, short dimension) 
{
    printf("\n\n\nThe actual matrix:\n\n");
    if(dimension >= 10)
    {
        printf("  ");
        for (int i = 0; i < dimension; ++i)
        {
            printf("____");
        }
        printf("\n\n");
        for (int i = 0; i < dimension; ++i)
        {
            printf("|");
            for (int j = 0; j < dimension; ++j)
            {
                if(matrix[i * dimension + j] < 10)
                    printf("   %d", matrix[i * dimension + j]);
                else if(matrix[i * dimension + j] < 100)   
                    printf("  %d", matrix[i * dimension + j]);
                else
                    printf(" %d",matrix[i * dimension + j]);
            
            }
            printf("  |");
            printf("\n");
        }
        printf("  ");
        for (int i = 0; i < dimension; ++i)
        {
            printf("____");
        }
    }
    else
    {
        printf("  ");
        for (int i = 0; i < dimension; ++i)
        {
            printf("___");
        }
        printf("\n\n");
        for (int i = 0; i < dimension; ++i)
        {
            printf("|");
            for (int j = 0; j < dimension; ++j)
            {
                if(matrix[i * dimension + j] < 10)
                    printf("  %d", matrix[i * dimension + j]);
                else
                     printf(" %d", matrix[i * dimension + j]);
            }
            printf("  |");
            printf("\n");
        }   
        printf("  ");
        for (int i = 0; i < dimension; ++i)
        {
            printf("___");
        }         
    }
    printf("\n\n\n\n");
}

void save_matrix(int * matrix, short dimension, char depDir, char rotDir [])
{
    if (matrix == NULL)
    {
        printf("\n\n\t>> No matrix to save. Generate a matrix first. <<\n\n");
        return;
    }
    
    char foldername[] = "generated_matrices";
    char filename[50]; 
    snprintf(filename, sizeof(filename), "%s/spiral%hd%c%s.txt", foldername, dimension, depDir, rotDir);

    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < dimension; ++i)
    {
        for (int j = 0; j < dimension; ++j)
        {
            fprintf(file, "%d ", matrix[i * dimension + j]);
        }
        fprintf(file, "\n");
    }

    fclose(file);

    printf("\nMatrix saved to %s\n", filename);
}

int str_real_length(char filename [])
{
    int i = 0;
    while(filename[i] != '\0')
        ++i;
    return i;
}

void load_matrix(int **matrix, short *dimension, char *depDir, char *rotDir)
{
    char filename[MAX_FILENAME_LENGTH];
    printf("\nPlease enter the name of the file: ");
    fgets(filename, sizeof(filename), stdin);

    int len = str_real_length(filename);
    if (len > 0 && filename[len - 1] == '\n')
    {
        filename[len - 1] = '\0'; // Remove the newline character if present
    }
    else
    {
        clearInputBuffer();
    }

    char foldername[] = "generated_matrices";
    char fullpath[MAX_FILENAME_LENGTH + sizeof(foldername) + 1]; // +1 for the path separator

    // Concatenate folder name and file name to create the full path
    snprintf(fullpath, sizeof(fullpath), "%s/%s", foldername, filename);

    FILE *file = fopen(fullpath, "r");
    if (file == NULL)
    {
        printf("\n\n\t>> File not found. <<\n\n");
        return;
    }

    if (sscanf(filename, "spiral%hd%c%c", dimension, depDir, rotDir) != 3)
    {
        printf("\n\n\t>> Error parsing information from the file. <<\n\n");
        fclose(file);
        return;
    }

    if (*dimension <= 0)
    {
        printf("\n\n\t>> Invalid matrix dimensions. <<\n\n");
        fclose(file);
        return;
    }

    if (*matrix != NULL)
        freeMatrix(matrix);

    *matrix = (int *)malloc((*dimension) * (*dimension) * sizeof(int));
    if (*matrix == NULL)
    {
        printf("\n\n\t>> Memory allocation failed. Exiting the program. <<\n\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < *dimension; ++i)
    {
        for (int j = 0; j < *dimension; ++j)
        {
            if (fscanf(file, "%d", &(*matrix)[i * (*dimension) + j]) != 1)
            {
                printf("\n>> Error reading matrix element from the file. <<\n");
                fclose(file);
                freeMatrix(matrix);
                return;
            }
        }
    }
    fclose(file);
    printf("\nMatrix loaded from %s\n", fullpath);
}


void user_guide()
{
    printf("\n\n\n\n");
    FILE *file = fopen("user_guide.txt", "r");
    if (file == NULL)
        printf("\n\n>> Error opening user_guide.txt for reading. <<\n\n");
    char ch;
    while ((ch = fgetc(file)) != EOF)
        printf("%c", ch);
    fclose(file);
}