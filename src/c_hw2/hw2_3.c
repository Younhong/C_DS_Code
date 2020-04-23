#include <stdio.h>

int main()
{
	// variables: len, i
	// initialization
	int len = 0;
	int i = 0;

	// read len
	printf("Len = ");
	scanf("%d", &len);

	// while statement
	while (len != 0)
	{
		// for statement
		for (i = 0; i < len; i++)
		{
			printf("#");
		}
		printf("\n");

		// read len
		printf("Len = ");
		scanf("%d", &len);
	}

	return 0;
}
