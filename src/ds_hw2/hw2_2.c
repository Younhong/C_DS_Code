#include <stdio.h>
#include <malloc.h>

int main()
{
	// declare variables
	int number = 0, i = 0;

	// make structure type Plan to store data
	struct Plan{
		int month, day, hour, min;
		char title[256];
	};

	// read number of schedules
	printf("# of schedules: ");
	scanf("%d", &number);
	
	// allocate a memory for struct Plan plan
	struct Plan *plan = (struct Plan*)malloc(number*sizeof(struct Plan));

	// if failed to allocate memory for plan, end the program
	if (plan == NULL) {
		printf("Failed to allocate memory.\n");
		exit(-1);
	}

	// for i from 0 to number-1
	for (i = 0; i < number; i++) {
		printf("%d-th schedule: \n", i);
		// read plan[i].month, plan[i].day on struct Plan
		printf("\tdate (month date): ");
		scanf("%d %d", &plan[i].month, &plan[i].day);
		// read plan[i].hour, plan[i].minand store the data on struct Plan
		printf("\ttime (hour min): ");
		scanf("%d %d", &plan[i].hour, &plan[i].min);
		// read plan[i].title and store the data on struct Plan
		printf("\ttitle: ");
		scanf(" %s", &plan[i].title);
	}

	// print messages
	printf("=== %d schedules ===\n", number);
	
	// print plan[i].month, plan[i].day, plan[i].hour, plan[i].min, plan[i].title for n 
	for (i = 0; i < number; i++) {
		printf("%d/%d, %d:%d, %s\n", plan[i].month, plan[i].day, plan[i].hour, plan[i].min, plan[i].title);
	}

	// deallocate plan
	free(plan);
	// set plan to NULL after deallocation for safety
	plan = NULL;

	return 0;
}