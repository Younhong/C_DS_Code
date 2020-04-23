#include "MinHeap.h"
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

MinHeap* CreateMinHeap(int max_size) {
	// allocating a memory to s, s->array 
	MinHeap *s = (MinHeap*)malloc(sizeof(MinHeap));
	s->array = (int*)malloc((max_size + 1)*sizeof(int));

	// if memory allocation failes
	if (s == NULL || s->array == NULL) {
		printf("Failed to allocate memory!");
	}

	// initial value of s->max_size, s->size
	s->max_size = max_size;
	s->size = 0;

	return s;
}

void FreeMinHeap(MinHeap* h) {
	// deallocate h->array, h and set it's value to NULL
	free(h->array);
	h->array = NULL;
	free(h);
	h = NULL;

	return;
}

int IsFullMinHeap(MinHeap *h) {
	// if heap is full, return 1
	if (h->size == h->max_size)
		return 1;
	else
		return 0;
}

int IsEmptyMinHeap(MinHeap *h) {
	// if heap is empty, return 1
	if (h->size == 0)
		return 1;
	else
		return 0;
}

void InsertMinHeap(MinHeap *h, int data) {
	int i = h->size + 1;

	// if heap is full
	if (IsFullMinHeap(h))
		printf("MinHeap is already full!\n");
	else {
		// while i is bigger than 1, and data is smaller than child array
		while ((i != 1) && data < h->array[i/2])
		{
			// change value of child array with its parent array
			h->array[i] = h->array[i / 2];
			// divide i by 2
			i /= 2;
		}
		// if i is 1 ordata is bigger(or equal) than child array
		h->array[i] = data;
		// increment h->size
		h->size++;
	}
}

int DeleteMinHeap(MinHeap *h) {
	int min, temp;
	int parent = 1;
	int smallerChild;

	// if heap is empty
	if (IsEmptyMinHeap(h))
		printf("MinHeap is already empty!\n");
	else {
		// save smallest value to min
		min = h->array[1];

		// after changing uppermost parent with last array value, decrement h->size
		h->array[1] = h->array[h->size--];

		// at least one child exists
		while (parent * 2 <= h->size) {
			// both left, right child exist
			if (parent * 2 + 1 <= h->size) {
				// left child is smaller than right child
				if (h->array[parent * 2] <= h->array[parent * 2 + 1]) {
					smallerChild = parent * 2;
				}
				// right child is bigger than left child
				else smallerChild = parent * 2 + 1;
			}
			// only left child exist
			else {
				smallerChild = parent * 2;
			}
			// if parent is smaller than child, exit the loop
			if (h->array[parent] <= h->array[smallerChild])
				break;
			else {
				// change parent with child
				temp = h->array[parent];
				h->array[parent] = h->array[smallerChild];
				h->array[smallerChild] = temp;

				// child becomes new parent
				parent = smallerChild;
			}
		}
	}

	return min;
}