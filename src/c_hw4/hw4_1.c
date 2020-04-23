#include <stdio.h>
#include <string.h>

// function declaration
void PrintTitle(char title[], int width);
void MonthCalendar(int start_day, int no_date, int *next_day);

int main()
{
	// variable start_day
	int start_day = 4;

	// function call
	PrintTitle("January", 27);
	MonthCalendar(start_day, 31, &start_day);

	PrintTitle("February", 27);
	MonthCalendar(start_day, 28, &start_day);
	
	PrintTitle("March", 27);
	MonthCalendar(start_day, 31, &start_day);
	
	PrintTitle("April", 27);
	MonthCalendar(start_day, 30, &start_day);

	PrintTitle("May", 27);
	MonthCalendar(start_day, 31, &start_day);

	PrintTitle("June", 27);
	MonthCalendar(start_day, 30, &start_day);

	PrintTitle("July", 27);
	MonthCalendar(start_day, 31, &start_day);

	PrintTitle("August", 27);
	MonthCalendar(start_day, 31, &start_day);

	PrintTitle("September", 27);
	MonthCalendar(start_day, 30, &start_day);

	PrintTitle("October", 27);
	MonthCalendar(start_day, 31, &start_day);

	PrintTitle("November", 27);
	MonthCalendar(start_day, 30, &start_day);

	PrintTitle("December", 27);
	MonthCalendar(start_day, 31, &start_day);

	return 0;
}

void PrintTitle(char title[], int width)
{
	// variable title_len
	int title_len = strlen(title);

	// for statement
	for (int i = 1; i <= width; i++)
	{
		// for statement to put '=' before title
		for (i = 1; i <= (width - title_len - 2) / 2; i++)
		{
			printf("=");
		}

		// print title
		printf(" %s ", title);

		// for statement to fill rest '='
		for (i = (width + title_len + 4) / 2; i <= width; i++)
		{
			printf("=");
		}
	}

	printf("\n");

	return;
}

void MonthCalendar(int start_day, int no_date, int *next_day)
{
	// print days
	printf("SUN MON TUE WED THU FRI SAT\n");

	// for statement to make empty space before 1st day of month.
	for (int i = 0; i <= 4 * start_day - 1; i++)
	{
		printf(" ");
	}

	// for statement
	for (int x = 1; x <= no_date; x++)
	{
		// print date
		printf("%3d ", x);

		// print new line character after Saturday
		if ((start_day + x) % 7 == 0)
		{
			printf("\n");
		}
	}

	// compute *next_day
	*next_day = (start_day + no_date) % 7;

	// if *next_day is sunday, print one '\n'
	if (*next_day == 0)
	{
		printf("\n");
	}
	// else if *next_day is not Sunday, print two '\n'
	else
	{
		printf("\n");
		printf("\n");
	}

	return;
}