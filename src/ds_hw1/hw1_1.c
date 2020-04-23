#include <stdio.h>

int main()
{
	// declare variables 
	int size = 10;
	int ary[10];
	int *ptr = NULL;
	int i = 0;

	// print ary, ary+3, &ary[3]
	printf("ary = %p, ary + 3 = %p, &ary[3] = %p\n", ary, ary + 3, &ary[3]);

	// assign ary's address to ptr
	ptr = &ary;

	// print ptr, ptr+3, &ptr[3]
	printf("ptr = %p, ptr + 3 = %p, &ptr[3] = %p\n", ptr, ptr + 3, &ptr[3]);

	// store values on ptr[i]
	for (i = 0; i < size; i++) {
		ptr[i] = i * 10;
	}

	// print elements of ary
	printf("ary = { ");
	for (i = 0; i < size; i++) {
		printf("%d ", ary[i]);
	}
	printf("}\n");

	return 0;
}

/*
Q: What is the meaning of the number 00000000009FFE10?
	A: address of arrays
Q: Why ary+3, &ary[3], ptr+3, &ptr[3] are the same?
	A: ary+3 is different way of representing &ary[3]. Similarly, ptr+3 is same as &ptr[3].
		I assigned ptr to & ary, which means ptr has an address of ary. Those two arrays share their address.
		So &ary[3], &ptr[3], ary+3, ptr+3 have same values.
Q: After storing { 0, 10, 20, ¡¦, 90 } to ary, what is the value of ary and *ary?
	A: ary = address of ary[0], *ary = 0
Q: After storing { 0, 10, 20, ¡¦, 90 } to ary, what is the value of ptr and *ptr?
	A: ptr = address of ary[0], *ptr = 0
*/