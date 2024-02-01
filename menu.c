#include "menu.h"

void clearInputBuffer()
{
    while(getchar() != '\n'){};
}

char menu()
{
    char choice;
    printf("\n\n##########################");
    printf("\n# Spiral Matrix Program  #");
    printf("\n#                        #");
    printf("\n#                        #");
    printf("\n# 0 ~ User Guide         #");
    printf("\n# 1 ~ Generate a matrix  #");
    printf("\n# 2 ~ Save a matrix      #");
    printf("\n# 3 ~ Load a matrix      #");
    printf("\n# 4 ~ Print actual matrix#");
    printf("\n# 5 ~ Exit               #");
    printf("\n##########################\n");
    do
    {
        printf("\n\tChoice: ");
        scanf(" %c", &choice);
        clearInputBuffer();
        if (choice < '0' || choice > '5')
            printf("\n\n>> Please enter a valid number between 0 and 5 <<\n\n");
    } while (choice < '0' || choice > '5');
    return choice;
}

void end_of_program()
{
    printf("\n\n\n\tGoodbye!\n\n");
}

void directing() 
{
    int * matrix = NULL;
    short * dimension = (short*)malloc(sizeof(short));
    if (dimension == NULL)
    {
        printf(">> Memory allocation failed. Exiting the program. <<\n");
        exit(EXIT_FAILURE); 
    }
    char choice;
    char depDir;
    char rotDir[3];
    do
    {
        choice = menu();
        switch (choice)
        {
        case '0':
            user_guide();
            break;
        case '1':
            if(matrix != NULL)
                freeMatrix(&matrix);
            generate_matrix(&matrix, dimension, &depDir, rotDir);
            break;    
        case '2':
            if(matrix == NULL)
                printf("\n>> Spiral Matrix cannot be saved, a matrix is not generated or loaded yet <<");
            else
                save_matrix(matrix, *dimension, depDir, rotDir);
            break;
        case '3':
            load_matrix(&matrix, dimension, &depDir, rotDir);
            break;  
        case '4':
            if(matrix == NULL)
                printf("\n>> Matrix cannot be shown, because a matrix is not generated or loaded yet <<");
            else
                print_matrix(matrix, *dimension); // nem lehet NULL
            break;    
        case '5':
            end_of_program();
            break; 
        }
    } while (choice != '5');
    if(dimension != NULL)
        free(dimension);
    if(matrix != NULL)
        freeMatrix(&matrix);
}