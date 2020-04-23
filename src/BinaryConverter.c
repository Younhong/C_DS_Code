#include <stdio.h>
#include <math.h>

int GetBinaryDigit(int x);
int GetHexadecimalDigit(int s);
void ConvertingHexadecimal(int n, int d);
void ConvertingBinary(int a, int b);

// program that converts the decimal number to binary and hexadecimal.

int main()
{
	int number = 0, binary_digit = 0, hexadecimal_digit = 0;

	printf("Input a number: ");
	scanf("%d", &number);

	binary_digit = GetBinaryDigit(number);
	printf("The number has %d digits in binary.\n", binary_digit);

	hexadecimal_digit = GetHexadecimalDigit(number);
	printf("The number has %d digits in hexadecimal.\n", hexadecimal_digit);

	ConvertingBinary(number, binary_digit);
	printf("\n");
	
	ConvertingHexadecimal(number, hexadecimal_digit);
	printf("\n");

	return 0;
}

int GetBinaryDigit(int x)
{
	int binary_digit_count = 0;

	while (x > 0)
	{
		x = x / 2;
		binary_digit_count++;
	}

	return binary_digit_count;
}

int GetHexadecimalDigit(int s)
{
	int hexadecimal_digit_count = 0;

	while (s > 0)
	{
		s = s / 16;
		hexadecimal_digit_count++;
	}

	return hexadecimal_digit_count;
}

void ConvertingBinary(int a, int b)
{
	int square = 1;
	int i = 0;

	square = pow(2, b - 1);

	printf("The binary number of %d is ", a);

	for (i = 0; i < b; i++)
	{
		int result = a / square;		
		a = a - result * square;
		square = square / 2;
		printf("%d", result);
	}

	return;
}

void ConvertingHexadecimal(int n, int d)
{
	int square = 1;
	int i = 0;
	
	square = pow(16, d - 1);

	printf("The hexadecimal number of %d is ", n);

	for (i = 0; i < d; i++)
	{
		int result = n / square;
		if (result >= 10 && result < 16)
		{
			switch (result)
			{
			case 10: printf("A"); break;
			case 11: printf("B"); break;
			case 12: printf("C"); break;
			case 13: printf("D"); break;
			case 14: printf("E"); break;
			case 15: printf("F"); break;
			default: break;
			}
		}
		else
		{
			printf("%d", result);
		}
		n = n - result * square;
		square = square / 16;
	}

	return;
}