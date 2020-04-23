#ifndef __DEQUEUE__
#define __DEQUEUE__

typedef struct {
	int *dequeue;
	int max_size;
	int left;
	int right;
} Dequeue;

Dequeue *CreateDequeue(int max_size);
void DestroyDequeue(Dequeue *d);
void PushLeft(Dequeue *d, int item);
void PushRight(Dequeue *d, int item);
int PopLeft(Dequeue *d);
int PopRight(Dequeue *d);
int IsFullDequeue(Dequeue *d);
int IsEmptyDequeue(Dequeue *d);
void DisplayDequeue(Dequeue *d);
#endif