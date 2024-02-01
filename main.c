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
	printf("3 ~ Spiral Matrix generator\n");
	printf("4 ~ Exit\n\n");
	printf("Choice: ");
	scanf("%hd", choice);
	printf("\n");
}	

void directing_math_app(short * choice)
{
	bool bad_choice = false;
	welcome();
	while(*choice != 4)
	{
		do
		{
			choice_input(choice);
			if(*choice <= 4 && *choice >= 0)
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
					directing();
					break;
				}
				case 4:
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
	directing_math_app(&choice);
	return 0;
}