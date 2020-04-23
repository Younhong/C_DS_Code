#include <Stdio.h>
#include <malloc.h>

int main()
{
	// variables n,i,data
	int n = 0, i = 0;
	int *data = NULL;

	// read n
	printf("Input # of data: ");
	scanf("%d", &n);

	// allocating memory
	data = (int*)malloc(n*sizeof(int));

	printf("random numbers: \n");

	// initializing seed
	srand(time(NULL));

	// for statement to print n numbers
	for (i = 0; i < n; i++)
	{
		// give random numbers from 1 to 100 on data[i]
		data[i] = rand() % 100 + 1;
		// print data[i]
		printf("\tdata[%d] = %d\n", i, data[i]);
	}

	printf("reverse order: \n");

	// for statement to print n numbers in reverse order
	for (i = n - 1; i >= 0; i--)
	{
		// print data[i]
		printf("\tdata[%d] = %d\n", i, data[i]);
	}

	// deallocating memory
	free(data);

	return 0;
}