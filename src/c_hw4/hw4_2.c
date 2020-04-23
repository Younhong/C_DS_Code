#include <Stdio.h>
#include <float.h>

int main()
{
	// variables declaration: min, max, sum, average, count, i, x, ret, filename
	float min = FLT_MAX;
	float max = -FLT_MAX;
	float sum = 0.F, average = 0.F;
	int count = 0;
	int i = 0, x = 0, ret = 0;
	char filename[30];

	// read filename
	printf("Input filename: ");
	scanf("%s", filename);

	// open a file
	FILE *fp = fopen(filename, "r");

	// if file doesn't exist
	if (fp == NULL)
	{
		// print error statement
		printf("Failed to open %s\n", filename);
	}

	// for statement
	// access file
	for (i = 0; fscanf(fp, "%d", &x) != EOF; i++)
	{
		// if statement to find min
		if (x < min)
		{
			min = x;
		}
		// if statement to find max
		if (x > max)
		{
			max = x;
		}

		// compute sum, count
		sum = sum + x;
		count++;
	}

	// if there is no data in the file
	if (count == 0)
	{
		printf("There is no data in the file.\n");
	}

	// else if data exists in the file
	else
	{
		// compute average
		average = sum / (float)count;

		// print min, max, average
		printf("min = %f, max = %f, average = %f\n", min, max, average);
	}

	// close a file
	fclose(fp);

	return 0;
}