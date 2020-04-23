#include <stdio.h>
#include "Dequeue2.h"
#include <stdlib.h>

int main()
{
	Dequeue *d = CreateDequeue(10);

	printf("PushRight(10)\n");
	PushRight(d, 10);
	printf("PushRight(20)\n");
	PushRight(d, 20);
	printf("PushRight(30)\n");
	PushRight(d, 30);
	DisplayDequeue(d);

	printf("PopLeft() returns %d\n", PopLeft(d));
	printf("PopLeft() returns %d\n", PopLeft(d));
	DisplayDequeue(d);

	printf("PushLeft(90)\n");
	PushLeft(d, 90);
	printf("PushLeft(80)\n");
	PushLeft(d, 80);
	printf("PushLeft(70)\n");
	PushLeft(d, 70);
	printf("PushLeft(60)\n");
	PushLeft(d, 60);
	printf("PushLeft(50)\n");
	PushLeft(d, 50);
	DisplayDequeue(d);

	printf("PopRight() returns %d\n", PopRight(d));
	printf("PopRight() returns %d\n", PopRight(d));
	printf("PopRight() returns %d\n", PopRight(d));
	printf("PopRight() returns %d\n", PopRight(d));
	DisplayDequeue(d);

	printf("PushRight(70)\n");
	PushRight(d, 70);
	printf("PushRight(80)\n");
	PushRight(d, 80);
	printf("PushRight(90)\n");
	PushRight(d, 90);
	DisplayDequeue(d);

	printf("Reverse order: ");
	DisplayDequeueReverse(d);

	DestroyDequeue(d);

	printf("Bye!\n");
	system("PAUSE");

	return 0;
}