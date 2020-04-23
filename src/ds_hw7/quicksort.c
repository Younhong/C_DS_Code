#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>
#include <string.h>
#include <limits.h>

#define DEFAUT_SIZE 10

void QuickSort(int list[], int left, int right, int n);
// sort a list from left to right
// n is the size of total list and necessary only to print the intermediate result
// it is assumed that list[left].key <= list[right+1].key

void DisplayList(int list[], int left, int right, int n);
// display a list of size n
// displays blackets at left and right positions

void FillRandom(int list[], int n, int minValue, int maxValue);
// fill a list with random numbers, whose range is [minValue, maxValue).

void swap(int *px, int *py);

int main(int argc, char *argv[])
{
	int n = 0;
	int *list = NULL;

	if(argc > 1)
		n = atoi(argv[1]);

	if(n == 0)
		n = DEFAUT_SIZE;

	printf("Array size = %d\n", n);

	srand(time(NULL));

	list = (int*) malloc((n + 1) * sizeof(int));

	FillRandom(list, n, 0, 100);
	list[n] = INT_MAX;				// put a very large number at the end of list

	printf("Before Sort: ");
	DisplayList(list, 0, n - 1, n);
	printf("\n");

	QuickSort(list, 0, n - 1, n);

	printf("\nAfter Sort: ");
	DisplayList(list, 0, n - 1, n);

	free(list);

//	system("PAUSE");

	return 0;
}

void QuickSort(int list[], int left, int right, int n)
// It is assumed that list[left].key <= list[right+1].key
{
	printf("Quicksort(%d, %d)\n", left, right);
	DisplayList(list, left, right, n);
	int pivot, i, j;
	if (left < right) {
		i = left;
		j = right + 1;
		pivot = list[left];
		do {
			do
				i++;
			while (list[i] < pivot);
			do
				j--;
			while (list[j] > pivot);
			if (i < j)
				swap(&list[i], &list[j]);
		} while (i < j);
		swap(&list[left], &list[j]);

		DisplayList(list, left, right, n);
		QuickSort(list, left, j - 1, n);
		QuickSort(list, j + 1, right, n);
	}

	// Implement quicksort.
	// To print intermediate results, call DisplayList()
	// at the beginning of the function and immediately after partition.
}

void swap(int *px, int *py)
{
	int t = *px;
	*px = *py;
	*py = t;
}

void FillRandom(int list[], int n, int minValue, int maxValue)
{
	for (int i = 0; i < n; i++)
		list[i] = rand() % (maxValue - minValue + 1) + minValue;
	// Fill list with random numbers [minValue, maxValue)
}

void DisplayList(int list[], int min, int max, int n)
{
	int i = 0;
	for(i = 0; i < n; i++){
		if(i == min)
			printf("[ ");
		else
			printf("  ");

		printf("%2d", list[i]);

		if(i == max)
			printf(" ]");
		else
			printf("  ");
	}

	printf("\n");
}
