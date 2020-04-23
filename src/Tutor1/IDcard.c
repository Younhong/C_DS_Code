#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "IDcard.h"


IDcard * MakeIdCard(int key) {

	IDcard * new_ID = (IDcard *)malloc(sizeof(IDcard));
	if (new_ID == NULL) {
		printf("Failed to allocate memory!\n");
		return ERR;
	}
	printf("Input Your Name : ");
	scanf("%s", new_ID->name);

	time_t current_time = time(NULL);
	struct tm *t;
	t = localtime(&current_time);

	new_ID->registered_date = (Date *)malloc(sizeof(Date));
	if (new_ID->registered_date == NULL) {
		printf("Failed to allocate memory!\n");
		return ERR;
	}
	new_ID->registered_date->year = t->tm_year + 1900;
	new_ID->registered_date->month = t->tm_mon + 1;
	new_ID->registered_date->day = t->tm_mday;
	new_ID->registered_date->hour = t->tm_hour;
	new_ID->registered_date->min = t->tm_min;
	new_ID->registered_date->sec = t->tm_sec;

	new_ID->key = key;

	printf("Successfully Registered!\n\n\n\n");
	return new_ID;
}
