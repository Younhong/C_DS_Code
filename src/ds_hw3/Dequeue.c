#include <stdio.h>
#include <malloc.h>
#include "Dequeue.h"

Dequeue *CreateDequeue(int max_size)
{
	// allocating a memory space to Dequeue s
	Dequeue *s = (Dequeue*)malloc(sizeof(Dequeue));
	// allocating a memory space to s->dequeue
	s->dequeue = (int*)malloc(max_size * sizeof(int));
	// initializing value of s->max_size, s->left, s->right
	s->max_size = max_size;
	s->left = s->right = 0;
	return s;
}

void DestroyDequeue(Dequeue *d)
{
	// deallocate d->dequeue and set value to NULL
	free(d->dequeue);
	d->dequeue = NULL;
	// deallocate d and set value to NULL
	free(d);
	d = NULL;
}

void PushLeft(Dequeue *d, int item)
{
	// if full, then return
	if (IsFullDequeue(d))
		return;
	// else move d->left to left by 1 and print item on that place.
	else {
		d->left = (d->left - 1) % d->max_size;
		// if d->left became smaller than 0, then move to opposite end of dequeue
		if (d->left < 0)
			d->left = d->left + d->max_size;
		d->dequeue[d->left] = item;
	}
}

void PushRight(Dequeue *d, int item)
{
	// if full, then return
	if (IsFullDequeue(d))
		return;
	// else print item and move d->right to right by 1
	else {
		d->dequeue[d->right] = item;
		d->right = (d->right + 1) % d->max_size;
	}
}

int PopLeft(Dequeue *d)
{
	// if empty, then return
	if (IsEmptyDequeue(d))
		return -1;
	// else move d->left to right by 1
	else {
		d->left = (d->left + 1) % d->max_size;
		// if previous d->left was 0, then return d->dequeue[9]
		if (d->left == 0) {
			return d->dequeue[9];
		}
		// else return items from previous d->left position
		else {
			return d->dequeue[d->left - 1];
		}
	}
}

int PopRight(Dequeue *d)
{
	// if empty, then return
	if (IsEmptyDequeue(d))
		return -1;
	// else move d->right to left by 1 and return item of that place
	else {
		d->right = (d->right - 1) % d->max_size;
		// if d->right is smaller than 0, then move to opposite end of dequeue
		if (d->right < 0)
			d->right = d->right + d->max_size;
		return d->dequeue[d->right];
	}
}

int IsFullDequeue(Dequeue *d)
{
	// if dequeue is full return 1
	if ((d->right + 1) % d->max_size == d->left)
		return 1;
	// else return 0
	else
		return 0;
}

int IsEmptyDequeue(Dequeue *d)
{
	// if dequeue is empty return 1
	if (d->left == d->right)
		return 1;
	// else return 0;
	else
		return 0;
}

void DisplayDequeue(Dequeue *d)
{
	int i = 0;
	if (IsEmptyDequeue(d)) {
		printf("Dequeue is empty!\n");
		return;
	}
	printf("( left = %d, right = %d, max_size = %d )\n", d->left, d->right, d->max_size);
	for (i = 0; i < d->max_size; i++)
		printf("%3d ", i);
	printf("\n");
	if (d->left <= d->right) {
		for (i = 0; i < d->left; i++)
			printf("    ");
		for (; i < d->right; i++)
			printf("%3d ", d->dequeue[i]);
	}
	else {
		for (i = 0; i < d->right; i++)
			printf("%3d ", d->dequeue[i]);
		for (; i < d->left; i++)
			printf("    ");
		for (; i < d->max_size; i++)
			printf("%3d ", d->dequeue[i]);
	}
	printf("\n");
}