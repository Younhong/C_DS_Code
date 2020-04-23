#include <stdio.h>

int main()
{
	int x = 0;
	int n = 0;
	int ret = 0;

	FILE *fp = fopen("data.txt", "w");

	printf("Input a number (CTRL-Z to quit): ");

	for (n = 0; scanf("%d", &x) != EOF; n++) {
		fprintf(fp, "%d\n", x);
		printf("Input a number (CTRL-Z to quit): ");
	}

	fclose(fp);
}