#include <stdio.h>

int main()
{
	// variables: start_hour, start_min, start_sec, end_hour, end_min, end_sec, start_time_in_sec, end_time_in_sec
	// variables: elapsed_time_in_sec, elapsed_hour, elapsed_min, elapsed_sec
	// initialization
	int start_hour = 0, start_min = 0, start_sec = 0, end_hour = 0, end_min = 0, end_sec = 0;
	int start_time_in_sec = 0, end_time_in_sec = 0;
	int elapsed_time_in_sec = 0, elapsed_hour = 0, elapsed_min = 0, elapsed_sec = 0;
	
	// print messages
	// read start_hour, start_min, start_sec, end_hour, end_min, end_sec
	printf("Input start time in hour, min, and sec: ");
	scanf("%d %d %d", &start_hour, &start_min, &start_sec);
	printf("Input end time in hour, min, and sec: ");
	scanf("%d %d %d", &end_hour, &end_min, &end_sec);

	// compute start_time_in_sec, end_time_in_sec
	start_time_in_sec = 3600 * start_hour + 60 * start_min + start_sec;
	end_time_in_sec = 3600 * end_hour + 60 * end_min + end_sec;

	// print start_time_in_sec, end_time_in_sec
	printf("start time in sec: %d\n", start_time_in_sec);
	printf("end time in sec: %d\n", end_time_in_sec); //

	// compute elapsed_time_in_sec
	elapsed_time_in_sec = end_time_in_sec - start_time_in_sec;

	// print elapsed_time_in_sec
	printf("elapsed time in sec: %d\n", elapsed_time_in_sec);

	// compute elapsed_hour, elapsed_min, elapsed_sec
	elapsed_hour = elapsed_time_in_sec / 3600;
	elapsed_min = (elapsed_time_in_sec % 3600) / 60;
	elapsed_sec = elapsed_time_in_sec % 60;

	// print elapsed_hour, elapsed_min, elapsed_sec
	printf("Elapsed time = %02d:%02d:%02d\n", elapsed_hour, elapsed_min, elapsed_sec);
}