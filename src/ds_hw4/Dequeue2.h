#ifndef __DEQUEUE2__
#define __DEQUEUE2__

typedef struct tNode {
	int data;
	struct tNode *llink, *rlink;
} Node;

typedef struct {
	Node *left, *right;
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
void DisplayDequeueReverse(Dequeue *d);
#endif