#include <stdio.h>
#include <ctype.h>

void GetCharFrequency(char file_name[], int frequency[]);
void PrintCharFrequency(int frequency[]);

int main()
{
	// variables: filename, frequency
	char filename[30];
	int frequency[128] = { 0 };

	// read filename
	printf("Input filename: ");
	scanf("%s", filename);

	// function to get frequency of char
	GetCharFrequency(filename, frequency);

	return 0;
}

void GetCharFrequency(char file_name[], int frequency[])
{
	// variables c
	char c = ' ';

	// open the file
	FILE *fp = fopen(file_name, "r");

	// if file doesn't exist, exit
	if (fp == NULL)
	{
		printf("Failed to open %s\n", file_name);
		exit(-1);
	}

	// while c from fp didn't reach EOF
	while ((c = fgetc(fp)) != EOF)
	{
		// increment frequency[c]
		frequency[c]++;
	}

	// function to print frequency of char
	PrintCharFrequency(frequency);

	// close the file
	fclose(fp);

	return;
}

void PrintCharFrequency(int frequency[])
{
	for (int c = 0; c < 128; c++)
	{
		// print frequency which is not 0, and print only letters that are printable
		if (frequency[c] != 0 && isprint(c))
		{
			printf("\tfrequency[%c](%d) = %d\n", c, c, frequency[c]);
		}
	}

	return;
}