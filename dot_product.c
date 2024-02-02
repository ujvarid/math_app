#include "dot_product.h"

int dot_product_dp(int * vektor1, int * vektor2, short size)
{
    int ertek = 0;
    for(int i = 0; i < size; ++i)
        ertek += vektor1[i] * vektor2[i];
    return ertek;
}

void dot_product_input(short * size, int ** vektor1, int ** vektor2)
{
    printf("Component number of the vector: ");
    scanf("%hd", size);
    *vektor1 = (int*)malloc(sizeof(int) * (*size));
    *vektor2 = (int*)malloc(sizeof(int) * (*size));
    for (int i = 0; i < *size; ++i)
    {
        printf("Please supply the value for the first vector's %d. coordinate: ", (i+1));
        scanf("%d", &(*vektor1)[i]);
    }
    for (int i = 0; i < *size; ++i)
    {
        printf("Please supply the value for the second vector's %d. coordinate: ", (i+1));
        scanf("%d", &(*vektor2)[i]);
    }
    
}

void dot_product_welcome()
{
    	printf("~~ Welcome to Dot product ~~\n\n");
}

void result(int * vektor1, int * vektor2, short size, int dotproduct)
{
    printf("\n\nResult: \n\n");
    printf("<( ");
    for(short i = 0; i < size; ++i)
    {
        if(i == size - 1)
            printf("%d ), ", vektor1[i]);
        else
            printf("%d, ", vektor1[i]);
    }
    printf(" ( ");
    for(short i = 0; i < size; ++i)
    {
        if(i == size - 1)
            printf("%d )>", vektor2[i]);
        else
            printf("%d, ", vektor2[i]);
    }

    printf(" = %d\n\n", dotproduct);
}

void dot_product_directing()
{
    short size = 0;
    int * vektor1 = NULL;
    int * vektor2 = NULL;
    dot_product_welcome();
    dot_product_input(&size,&vektor1,&vektor2);
    int dotproduct = dot_product_dp(vektor1, vektor2, size);
    result(vektor1, vektor2, size, dotproduct);
    free(vektor1);
    free(vektor2);
}
