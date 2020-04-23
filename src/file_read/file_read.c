#include <stdio.h>

int main()
{
	int x = 0;
	int n = 0;
	int ret = 0;

	FILE *fp = fopen("data.txt", "r");

	for (n = 0; fscanf(fp, "%d", &x) != EOF; n++) {
		printf("%d\n", x);
	}

	fclose(fp);
}