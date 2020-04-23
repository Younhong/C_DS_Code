#include <stdio.h>

// function declaration
void ConvertTime(int totalSec, int *hour, int *min, int *sec);

int main()
{
	// variable declaration: totalSec, hour, min, sec
	int totalSec = 0;
	int hour = 0, min = 0, sec = 0;

	// read totalSec
	printf("Input time in sec: ");
	scanf("%d", &totalSec);

	// function call
	ConvertTime(totalSec, &hour, &min, &sec);

	// print totalSec, hour, min, sec
	printf("%d sec = %02d:%02d:%02d\n", totalSec, hour, min, sec);

	return 0;
}

void ConvertTime(int totalSec, int *hour, int *min, int *sec)
{
	// compute *hour, *min, *sec
	*hour = totalSec / 3600;
	*min = (totalSec / 60) % 60;
	*sec = totalSec % 60;

	return;
}