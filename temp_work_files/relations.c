#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

short relation_howmany(int ** relations, short count)
{
    short howmany = 0;
    short temp;

    int * allnumbers = (int*)malloc(sizeof(int) * count * 2); 
    for (short i = 0; i < count; ++i) 
    {
        for(short j = 0; j < 2; ++j)
        {
            allnumbers[i*2 + j] = relations[i][j];
            printf("%d,", allnumbers[i*2+j]); 
        }
    }

    for (short i = 0; i < count * 2; ++i) 
    {
        temp = 0;
        for(short j = 0; j < i; ++j)
        {
            if(allnumbers[i] == allnumbers[j])
            {
                ++temp;
            }
        }
        if (temp == 0)
        {
            ++howmany;
            printf("\n%d", allnumbers[i]);
        }
        
    }

    return howmany;
}

void relation_reflexive(int ** relations, short count)
{
    // hanyfele algoritmus es kivalasztani a kulonbozoket ugy lenne a leggyorsabb
    // mallocolsz egy tömböt a különbözőkkel és csak a tömb méretéig nézed mindegyik az-e
    // először végig hányféle
    // aztán berakni tömbbe
    // aztán végig a tömb elemein hogy az összes reflexiv-e, ha nem akkor false, egyebkent true
}

void relations_generate(int *** relations, short count) 
{
    *relations = (int**)malloc(sizeof(int*) * count);
    for (short i = 0; i < count; i++)
    {
        // fix hogy rendezett párok, ezért kettő a szélesség
        (*relations)[i] = (int *)malloc(sizeof(int) * 2);
    }
}

void relations_get(int *** relations, short * count)
{
    printf("\nNumber of relations: ");
    scanf("%hd", count);
    relations_generate(relations, *count);
    printf("\nNow please enter the ordered pairs one by one:\n\n");
    for (short i = 0; i < *count; ++i)
    {
        printf("\n1. number of the ordered pair: ");
        scanf("%d", &(*relations)[i][0]);
        printf("\n2. number of the ordered pair: ");
        scanf("%d", &(*relations)[i][1]);
        printf("\nYou added: (%d, %d)\n", (*relations)[i][0], (*relations)[i][1]);
    }
    printf("\n");
    
}

void relations_directing()
{
    int ** relations = NULL;
    short count;
    relations_get(&relations, &count);
    printf("kulonbozo elemek szama: %hd", relation_howmany(relations, count));
}

int main()
{
    // kétdimenziós mátrixban tárolja  arelációkat, megadhatsz neki egy relációt és kielemzi, hogy 
    // tranzitív, szimmetrikus stb
    relations_directing();
    return 0;
}