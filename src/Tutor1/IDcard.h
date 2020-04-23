#ifndef __ID_CARD_H
#define __ID_CARD_H

#define NAME_LEN 20
#define TRUE 1
#define FALSE 0
#define ERR -1

typedef struct __Date 
{
	int year;
	int month;
	int day;
	int hour;
	int min;
	int sec;
} Date;

typedef struct __IDcard 
{
	char name[NAME_LEN];
	int key;
	Date *registered_date;
} IDcard;

IDcard * MakeIdCard(int key);
void PrintID(IDcard **id_arr);
int DeleteID(IDcard **id_arr);
#endif