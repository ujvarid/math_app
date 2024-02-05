#include "main.h"

void exit_app()
{
	printf("\n\n\tGoodbye!\n\n");
	system("sleep 1");
	system("clear");
}

void welcome()
{
	system("clear");
	printf("~~ Welcome to the Math App ~~");
}

char choice_input()
{
	char choice;
	printf("\n\n\tMain menu:\n\n");
	printf("0 ~ Basic matrix arithmetics\n");
	printf("1 ~ Dot product\n");
	printf("2 ~ Gram-Schmidt ortogonalization process\n");
	printf("3 ~ Spiral Matrix generator\n");
	printf("4 ~ Exit\n\n");
	do
    {
        printf("\n\tChoice: ");
        scanf(" %c", &choice);
        clearInputBuffer();
        if (choice < '0' || choice > '4')
            printf("\n\n>> Please enter a valid number between 0 and 4 <<\n\n");
    } while (choice < '0' || choice > '4');
    return choice;
}	

void directing_math_app()
{
	char choice;
	bool bad_choice = false;
	welcome();
	while(choice != '4')
	{
		do
		{
			choice = choice_input();
			if(choice <= '4' && choice >= '0')
			{
				system("clear");
				switch (choice)
				{
				case '0':
				{
					matrix_directing();
					break;
				}
				case '1':
				{
					dot_product_directing();
					break;
				}
				case '2':
				{
					grsch_directing();
					break;
				}
				case '3':
				{ 
					directing();
					break;
				}
				case '4':
				{
					exit_app();
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
	}
}

int main()
{
	directing_math_app();
	return 0;
}