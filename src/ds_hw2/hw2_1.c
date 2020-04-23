#include <stdio.h>
#include <time.h>

// function declaration
int RecursiveSearch(int array[], int size, int target);

int main()
{
	// initializing random seed
	srand(time(NULL));
	// variable declaration
	int array[10] = { 0, 10, 20, 30, 40, 50, 60, 70, 80, 90 };
	int recursionResult = 0;
	int result = 0;

	// for i from 0 to 9
	for (int i = 0; i < 10; i++)
	{
		// j is random number from 0 to 9
		int j = rand()%10;
		// change the value of arra[i] and array[j]
		int temp = array[i];
		array[i] = array[j];
		array[j] = temp;
	}

	// print elements of array
	printf("array = ");
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");

	// call function to find array[0] and store the return value on result
	result = RecursiveSearch(array, 10, array[0]);
	// print result
	printf("searching %d... result = %d\n", array[0], result);

	// call function to find array[5] and store the return value on result
	result = RecursiveSearch(array, 10, array[5]);
	// print result
	printf("searching %d... result = %d\n", array[5], result);

	// call function to find array[9] and store the return value on result
	result = RecursiveSearch(array, 10, array[9]);
	// print result
	printf("searching %d... result = %d\n", array[9], result);

	// call function to find 15 from array and store the return value on result
	result = RecursiveSearch(array, 10, 15);
	// print result
	printf("searching %d... result = %d\n", 15, result);

	return 0;
}

int RecursiveSearch(int array[], int size, int target)
{
	// variable declaration
	int recursionResult = 0;
	// if array has more than 2 elements
	if (size >= 2) {
		// if target is array[0], return 0
		if (target == array[0]) {
			return 0;
		}
		// if target is not array[0], use recursive function which moves the start of array 1 to the right.
		else
		{
			recursionResult = RecursiveSearch((array + 1), (size - 1), target);
			return recursionResult + 1;
		}
	}
	// if array has only one element
	else {
		// if last element of array is not the target, return -10
		if (target != array[0])
		{
			/*
			Size of the array started from 10 and every time it gets decremented, it returned recursionResult+1.
			When size became 1, return value became recursionResult+9 which is 9.
			So, in order to get the result -1, I made return value -10		
			*/
			return - 10;
		}
		// if last element of array is the target, return 0
		else
			return 0;
	}
}