#include <stdio.h>

int main()
{
	int *p = 0;
	int n = 0;
	int i = 0;

	printf("Enter number: ");
	scanf("%d", &n);
	printf("\n");

	p = &n;

	printf("%d\n", n);
	printf("%d\n", *p);
	printf("\n");
	printf("%d\n", &n);
	printf("%d\n", p);
	printf("\n");

	p = &i;

	if (n >= 1)
	{
		for (i = 1; i <= n; i++)
		{
			printf("%d\n%d\n", i, *p);
			printf("\n");
			printf("%d\n%d\n", &i, p);
			printf("\n");
		}
		printf("Well done!!\n");
	}
	else
	{
		for (i = n; i <= 1; i++)
		{
			printf("%d\n%d\n", i, *p);
			printf("\n");
			printf("%d\n%d\n", &i, p);
			printf("\n");
		}
		printf("Well done!!\n");
	}
}