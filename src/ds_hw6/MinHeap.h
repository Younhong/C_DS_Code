#ifndef __MIN_HEAP__
#define __MIN_HEAP__

typedef struct tMinHeap {
	int *array;
	int size;
	int max_size;
} MinHeap;

MinHeap* CreateMinHeap(int max_size); // create min heap
void FreeMinHeap(MinHeap* h); // destroy min heap
int IsFullMinHeap(MinHeap *h); // if heap is full, return 1, otherwise, 0
int IsEmptyMinHeap(MinHeap *h); // if heap is empty, return 1, otherwise, 0
void InsertMinHeap(MinHeap *h, int data); // insert data into the heap
int DeleteMinHeap(MinHeap *h); // delete and return the mininum

#endif // !__HEAP__