#include <stdio.h>

int main()
{
	int x = 0;
	int ret = 0;

	while (1)
	{
		printf("Input a number. Press <CTRL-Z> <Enter> to quit: ");
		ret = scanf("%d", &x);
		printf("x = %d, ret = %d\n", x, ret);

		if (ret == EOF)
			break;
	}

	return 0;
}