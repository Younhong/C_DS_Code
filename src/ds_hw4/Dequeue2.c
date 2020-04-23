#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "Dequeue2.h"

Dequeue *CreateDequeue(int max_size) {
	// allocate memory space to s, s->left, s->right
	Dequeue *d = (Dequeue*)malloc(sizeof(Dequeue));
	// if memory allocation fails
	if (d == NULL) {
		printf("Failed to allocate memory");
		exit(0);
	}
	// initialize d->left, d->right
	d->left = d->right = NULL;

	return d;
}

void DestroyDequeue(Dequeue *d) {
	// deallocate d and set it's value to NULL
	free(d);
	d = NULL;
}

// Adding from left side
void PushLeft(Dequeue *d, int item) {
	// allocate memory space to p
	Node *p = (Node*)malloc(sizeof(Node));

	// if d is empty
	if (IsEmptyDequeue(d)) {
		p->llink = p->rlink = NULL;
		d->left = d->right = p;
		p->data = item;
	}
	// if d is not empty
	else {
		p->rlink = d->left;
		p->llink = NULL;
		d->left->llink = p;
		d->left = p;
		p->data = item;
	}

	return;
}

// Adding from right side
void PushRight(Dequeue *d, int item) {
	Node *p = (Node*)malloc(sizeof(Node));

	// if d is empty
	if (IsEmptyDequeue(d)) {
		p->llink = p->rlink = NULL;
		d->left = d->right = p;
		p->data = item;
	}
	// if d is not empty
	else {
		p->llink = d->right;
		p->rlink = NULL;
		d->right->rlink = p;
		d->right = p;
		p->data = item;
	}

	return;
}

// Removing from left side
int PopLeft(Dequeue *d) {
	int value = 0;
	Node *p = d->left;

	// if empty, then return
	if (IsEmptyDequeue(d))
		return -1;
	// if there's item
	else if (p->rlink == NULL) {
		value = p->data;
		d->left = d->right = NULL;
		free(p);

		return value;
	}
	else {
		value = p->data;
		d->left = p->rlink;
		d->left->llink = NULL;
		p->rlink = NULL;
		free(p);

		return value;
	}
}

// Removing from right side
int PopRight(Dequeue *d) {
	int value = 0;
	Node *p = d->right;

	// if empty, then return
	if (IsEmptyDequeue(d))
		return -1;
	// if there's item
	else if (p->llink == NULL) {
		value = p->data;
		d->left = d->right = NULL;
		free(p);

		return value;
	}
	else {
		value = p->data;
		d->right = p->llink;
		d->right->rlink = NULL;
		p->llink = NULL;
		free(p);

		return value;
	}
}
int IsFullDequeue(Dequeue *d) {
	return 0;
}

int IsEmptyDequeue(Dequeue *d) {
	if ((void*)d->left->data == NULL)
		return 1;
	else
		return 0;
}

void DisplayDequeue(Dequeue *d)
{
	Node *p = NULL;
	int n = 0;
	if (IsEmptyDequeue(d)) {
		printf("Dequeue is empty!\n");
		return;
	}
	for (p = d->left; p != NULL; p = p->rlink, n++)
		printf("%3d ", p->data);
	printf(" (%d items)\n", n);
}

void DisplayDequeueReverse(Dequeue *d) {
	Node *p = NULL;
	int n = 0;
	if (IsEmptyDequeue(d)) {
		printf("Dequeue is empty!\n");
		return;
	}
	for (p = d->right; p != NULL; p = p->llink, n++)
		printf("%3d ", p->data);
	printf(" (%d items)\n", n);
}