#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h>

void relations_free(int ** relations, int * diff_nums, short count)
{
    for (short i = 0; i < count; ++i)
    {
        free(relations[i]);
    }
    free(relations);
    free(diff_nums);
}

short relations_howmany(int ** relations, short count, int ** diff_nums)
{
    short howmany = 0;
    short temp;

    int * allnumbers = (int*)malloc(sizeof(int) * count * 2); 
    for (short i = 0; i < count; ++i) 
    {
        for(short j = 0; j < 2; ++j)
        {
            allnumbers[i*2 + j] = relations[i][j];
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
        }
        
    }

    *diff_nums = (int*)malloc(sizeof(int) * howmany);
    howmany = 0;

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
            (*diff_nums)[howmany] = allnumbers[i];
            ++howmany;
        }
    }
    free(allnumbers);
    return howmany;
}

void relations_reflexive(int ** relations, short count, short howmany, int * diff_nums)
{
    bool reflexive = true;
    for (short i = 0; i < howmany; i++)
    {
        int j = 0;
        while (j < count)
        {
            if(relations[j][0] == diff_nums[i] && relations[j][1] == diff_nums[i])
            {
                break;
            }
            ++j;
        }
        if(j == count)
        {
            printf("(%d, %d)  ", diff_nums[i], diff_nums[i]);
            reflexive = false;
        }
    }
    if(reflexive)
        printf("\nThe relation is reflexive.\n\n");
    else
        printf("\n\nThe relation is not reflexive it misses the relation(s) above.\n\n");
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
    int * diff_nums;
    relations_get(&relations, &count);
    short howmany = relations_howmany(relations, count, &diff_nums);
    relations_reflexive(relations, count, howmany, diff_nums);
    relations_free(relations, diff_nums, count);
}

int main()
{
    // kétdimenziós mátrixban tárolja  arelációkat, megadhatsz neki egy relációt és kielemzi, hogy 
    // tranzitív, szimmetrikus stb
    relations_directing();
    return 0;
}