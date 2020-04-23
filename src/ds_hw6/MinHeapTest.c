#include "MinHeap.h"
#include <stdio.h>

int main()
{
	MinHeap *heap = CreateMinHeap(10);
	int data[12];
	int i = 0;
	srand((unsigned)time(NULL));
	for (i = 0; i < 12; i++)
		data[i] = rand() % 100;
	for (i = 0; i < 12; i++) {
		printf("Inserting %d\n", data[i]);
		InsertMinHeap(heap, data[i]);
	}
	printf("deleting data: ");
	while (!IsEmptyMinHeap(heap))
		printf("%d ", DeleteMinHeap(heap));
	printf("\n");
	FreeMinHeap(heap);
	return 0;
}