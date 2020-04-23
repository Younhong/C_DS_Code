#include <stdio.h>

void triangle(int x);

int main()
{
	int number = 0;

	printf("Input an number: ");
	scanf("%d", &number);

	triangle(number);

	return 0;
}

void triangle (int x)
{
	int i = 0, a = 0, n = 0;

	for (i = 1; i <= x; i++)
	{
		for (a = x - 1; a >= i; a--)
		{
			printf(" ");
		}

		for (n = 1; n <= i; n++)
		{
			printf("*");
		}

		for (n = 2; n <= i; n++)
		{
			printf("*");
		}

		printf("\n");
	}

	for (i = x - 1; i > 0; i--)
	{
		for (a = x - 1; a >= i; a--)
		{
			printf(" ");
		}

		for (n = 1; n <= i; n++)
		{
			printf("*");
		}

		for (n = 2; n <= i; n++)
		{
			printf("*");
		}

		printf("\n");
	}

	return;
}