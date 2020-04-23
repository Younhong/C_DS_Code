#include <stdio.h>

int main()
{
	// variables: value, result, opr
	// initialization
	float value = 0.F, result = 0.F;
	char opr = ' ';

	// print value
	printf("value = %.2f\n", value);
	// read opr
	printf("Input an expression (<operator> <operand>): ");
	scanf(" %c", &opr);

	// while statement
	while (opr != 'q')
	{
		// if statement
		if (opr == 'c')
		{
			result = 0;
			// print result
			printf("value = %.2f\n", result);

			// read opr
			printf("Input an expression (<operator> <operand>): ");
			scanf(" %c", &opr);
		}
		// else if statement
		else if (opr == '+')
		{
			// read value
			scanf("%f", &value);

			// compute result
			result = result + value;
			// print result
			printf("value = %.2f\n", result);

			// read opr
			printf("Input an expression (<operator> <operand>): ");
			scanf(" %c", &opr);
		}
		// else if statement
		else if (opr == '-')
		{
			// read value
			scanf("%f", &value);

			// compute result
			result = result - value;
			// print result
			printf("value = %.2f\n", result);

			// read opr
			printf("Input an expression (<operator> <operand>): ");
			scanf(" %c", &opr);
		}
		// else if statement
		else if (opr == '*')
		{
			// read value
			scanf("%f", &value);

			// compute result
			result = result * value;
			// print result
			printf("value = %.2f\n", result);

			// read opr
			printf("Input an expression (<operator> <operand>): ");
			scanf(" %c", &opr);
		}
		// else if statement
		else if (opr == '/')
		{
			// read value
			scanf("%f", &value);

			// if statement
			if (value != 0)
			{
				// compute result
				result = result / value;
				// print result
				printf("value = %.2f\n", result);

				// read opr
				printf("Input an expression (<operator> <operand>): ");
				scanf(" %c", &opr);
			}
			// else statement
			else
			{
				printf("Undividable number.\n");

				// read opr
				printf("Input an expression (<operator> <operand>): ");
				scanf(" %c", &opr);
			}
		}
	}

	return 0;
}