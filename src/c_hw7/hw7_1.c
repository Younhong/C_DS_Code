#include <stdio.h>
#include <ctype.h>

// function declaration
int my_strncmp(char *str1, char *str2, int n);

int main()
{
	// variable str1, str2, n
	char str1[256], str2[256];
	int n = 0;

	// read str1, str2, n
	printf("Input string1: ");
	gets(str1);
	printf("Input string2: ");
	gets(str2);
	printf("Input # of characters to compare: ");
	scanf("%d", &n);

	// print statement
	printf("my_strncmp(\"%s\", \"%s\") = %d\n", str1, str2, my_strncmp(str1, str2, n));

	return 0;
}

int my_strncmp(char *str1, char *str2, int n)
{
	// for i is from 0 to n-1
	for (int i = 0; i < n; i++)
	{
		// if lower letter of str1 is bigger than that of str2
		if (tolower(str1[i]) > tolower(str2[i]))
		{
			return 1;
		}
		// if lower letter of str1 is smaller than that of str2
		else if (tolower(str1[i]) < tolower(str2[i]))
		{
			return -1;
		}
		// if lower letter of str1 is same as that of str2
		else if (tolower(str1[i]) == tolower(str2[i]))
		{
			continue;
		}
		// if str1[i] is null character
		if (str1[i] = '\0')
		{
			break;
		}
	}

	return 0;
}
