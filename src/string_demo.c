#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
	char str1[32] = "Hello";
	char str2[32] = "Hello";
	char str3[32] = "Empty String";

	printf("str1 = [%s] (%p)\n", str1, str1);
	printf("str2 = [%s] (%p)\n", str2, str2);
	printf("str3 = [%s] (%p)\n", str3, str3);

	// strlen()
	printf("strlen(str1) = %d\n", strlen(str1));
	printf("strlen(str2) = %d\n", strlen(str2));
	printf("strlen(str3) = %d\n", strlen(str3));

	// strcmp()
	printf("\n");
	printf("== operator compares the addresses of strings.\n");
	printf("str1 == str2 = %d\n", str1 == str2);	

	printf("\n");
	printf("strcmp() compares the contents of strings.\n");
	printf("strcmp(str1, str2) = %d\n", strcmp(str1, str2));
	printf("strcmp(\"abc\", \"def\") = %d\n", strcmp("abc", "def"));
	printf("strcmp(\"def\", \"abc\") = %d\n", strcmp("def", "abc"));

	printf("\n");

	// strcpy()
	printf("str3 = %s\n", str3);
	printf("strcpy() copies strings.\n");
	strcpy(str3, str1);
	printf("After strcpy(), str3 = %s\n", str3);

	// strcat()
	printf("strcat() concatenates strings.\n");
	strcat(str3, " World!");
	printf("After strcat(), str3 = %s\n", str3);

	system("PAUSE");
	
	return 0;
}
