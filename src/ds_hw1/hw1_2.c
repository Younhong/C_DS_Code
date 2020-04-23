#include <stdio.h>
#include <malloc.h>

int main()
{
	// declare variables
	int size = 10;
	int *ptr = NULL;
	int i = 0;

	// allocate memory spaces to ptr
	ptr = (int*)malloc(size*sizeof(int));
	// print ptr, ptr+3, &ptr[3]
	printf("ptr = %p, ptr + 3 = %p, &ptr[3] = %p\n", ptr, ptr + 3, &ptr[3]);		// store values on ptr[i]
	for (i = 0; i < size; i++) {
		ptr[i] = i * 10;
	}

	// print elements of ptr
	printf("ptr = { ");
	for (i = 0; i < size; i++) {
		printf("%d ", ptr[i]);
	}
	printf("}\n");
	// deallocate ptr
	free(ptr);
	// give ptr null value
	ptr = NULL;
	// deallocate ptr
	free(ptr);

	// print ending message
	printf("Bye!\n");

	return 0;
}

/*
Q: Why deallocating ptr twice doesn¡¯t make the program crash?
	A: After deallocating ptr once, I assigned NULL value to ptr. Since there exists value in ptr, it didn't make any crash.
Q: If you don¡¯t set ptr to NULL and run the program what happens?
	A: If ptr wasn't set to NULL after deallocating once, and tries to dellocate again, it causes error.
*/