#include <stdio.h>

// function declaration
int CountDigits(int num);
int GetDigit(int num, int place);

int main()
{
	// variable declaration: number, digit, sum, i
	int number = 0, digit = 0;
	int sum = 0, i = 0;

	// read number
	printf("Input a big integer number: ");
	scanf("%d", &number);

	// function call, compute digit
	digit = CountDigits(number);

	// read number, digit
	printf("%d has %d digits\n", number, digit);

	// for statement
	for (i = 0; i < digit; i++)
	{
		// compute sum
		sum = sum + GetDigit(number, i + 1);
	}

	// print number, sum
	printf("sum of digits in %d = %d\n", number, sum);
}

int CountDigits(int num)
{
	// variable no_digit
	int no_digit = 0;

	// while statement
	while (num > 0)
	{
		// compute num
		num = num / 10;
		// increment no_digit
		no_digit++;
	}

	return no_digit;
}

int GetDigit(int num, int place)
{
	// variable i
	int i = 0;

	// for statement
	for (i = 0; i < place - 1; i++)
	{
		// compute num
		num = num / 10;
	}

	return num % 10;
}