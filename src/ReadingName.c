#include <stdio.h>

int main()
{
	// Initialization of variable s
	char s[100] = "";

	// print message
	// read and print s
	printf("What's your name?: ");
	scanf("%s", s);
	printf("Nice to meet you, %s!\n", s);
}