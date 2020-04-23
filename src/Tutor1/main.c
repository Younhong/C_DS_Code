/*
 *********************************************
 ********* IDcard Management System **********
 ***** 2016-1 4th week DS Tutor Session ******
 ***** Developed by HyunHoKIM, JiHeeCHOI *****  
 *********************************************
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "IDcard.h"

#define MAX_LEN 100

/* INPUT MENU */
int menu() {
	int input = 0;
	
	printf("----- ID card Management System -----\n");
	printf("1. Make New ID card\n");
	printf("2. Show All ID card\n");
	printf("3.   Delete ID card\n");
	printf("4. Quit the Program\n");
	printf("-------------------------------------\n");
	printf("Select Menu :  ");
	scanf("%d", &input);
	getchar();
	return input;
}

int main() {
	int key = 0;
	int index = 0;
	int i = 0, flag = FALSE;
	IDcard * pcard[MAX_LEN] = { NULL, };
	
	do {
		while (TRUE) {
			key = menu();
			if (key >= 1 && key <= 4)
				break;
			system("cls");
			printf("please input right Key.\n\n\n");
		}
		
		switch (key) {
		//make ID card
		case 1:
			system("cls");
			if (index > MAX_LEN - 1) {
				printf("Memory is Full. Cannot Make New ID Card \n");
				break;
			}
			pcard[index] = MakeIdCard(index + 1);
			if (pcard[index] == ERR) {
				printf("Making Card Error. Failed to allocate Memory. \n");
				break;
			}
			index++;
			break;
		//show all ID card
		case 2:
			system("cls");
			PrintID(pcard);
			break;
		//Delete ID card
		case 3:
			system("cls");
			flag = DeleteID(pcard);
			if (flag == TRUE)
				if (index > 0)
					index--;
			break;
		case 4:
			break;
		}



	} while (key != 4);
	//Free allocated Memory
	while (pcard [i] != NULL) {
		free(pcard[i]);
		pcard[i] = NULL;
		i++;
	}

	return 0;
}