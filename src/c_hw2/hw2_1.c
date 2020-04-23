#include <stdio.h>

int main()
{
	// variables: n1, n2, opr, result
	// initialization
	float n1 = 0.F, n2 = 0.F;
	char opr = ' ';
	float result = 0.F;

	// read n1, n2, opr
	printf("Input an expression: ");
	scanf("%f %c %f", &n1, &opr, &n2);

	// if statement
	if (opr == '+')
	{
		// compute result
		result = n1 + n2;
		// print n1,n2,result
		printf("%.2f + %.2f = %.2f\n", n1, n2, result);
	}
	// else if statement
	else if (opr == '-')
	{
		// compute result
		result = n1 - n2;
		// print n1,n2,result
		printf("%.2f - %.2f = %.2f\n", n1, n2, result);
	}
	// else if statement
	else if (opr == '*')
	{
		// compute result
		result = n1 * n2;
		// print n1,n2,result
		printf("%.2f * %.2f = %.2f\n", n1, n2, result);
	}
	// else if statement
	else if (opr == '/')
	{
		// if statement
		if (n2 == 0)
		{
			printf("Can't divide 0.\n");
		}
		// else statement
		else
		{
			// compute result
			result = n1 / n2;
			// print n1,n2,result
			printf("%.2f / %.2f = %.2f\n", n1, n2, result);
		}
	}
	// else statement
	else
	{
		printf("Wrong operator.\n");
	}

	return 0;
}