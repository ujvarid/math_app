#include "main.h"

void exit_app()
{
	printf("\n\n\tGoodbye!\n\n");
}

void welcome()
{
	printf("~~ Welcome to Linear Algebra ~~");
}

void choice_input(short * choice)
{
	printf("\n\nMenu:\n\n");
	printf("0 ~ Basic matrix arithmetics\n");
	printf("1 ~ Dot product\n");
	printf("2 ~ Gram-Schmidt ortogonalization process\n");
	printf("3 ~ Exit\n\n");
	printf("Choice: ");
	scanf("%hd", choice);
	printf("\n");
}	

void directing(short * choice)
{
	bool bad_choice = false;
	welcome();
	while(*choice != 3)
	{
		do
		{
			choice_input(choice);
			if(*choice <= 3 && *choice >= 0)
			{
				switch (*choice)
				{
				case 0:
				{
					matrix_directing();
					break;
				}
				case 1:
				{
					dot_product_directing();
					break;
				}
				case 2:
				{
					grsch_directing();
					break;
				}
				case 3:
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
	short choice;
	directing(&choice);
	return 0;
}