#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include "Maze.h"

int maze[14][17] = {
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
	{ 1,0,1,0,0,0,1,1,0,0,0,1,1,1,1,1,1 },
	{ 1,1,0,0,0,1,1,0,1,1,1,0,0,1,1,1,1 },
	{ 1,0,1,1,0,0,0,0,1,1,1,1,0,0,1,1,1 },
	{ 1,1,1,0,1,1,1,1,0,1,1,0,1,1,0,0,1 },
	{ 1,1,1,0,1,0,0,1,0,1,1,1,1,1,1,1,1 },
	{ 1,0,0,1,1,0,1,1,1,0,1,0,0,1,0,1,1 },
	{ 1,0,0,1,1,0,1,1,1,0,1,0,0,1,0,1,1 },
	{ 1,0,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1 },
	{ 1,0,0,1,1,0,1,1,0,1,1,1,1,1,0,1,1 },
	{ 1,1,1,0,0,0,1,1,0,1,1,0,0,0,0,0,1 },
	{ 1,0,0,1,1,1,1,1,0,0,0,1,1,1,1,0,1 },
	{ 1,0,1,0,0,1,1,1,1,1,0,1,1,1,1,0,1 },
	{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 }
};



int main()
{
	element * result;
	int i, j;
	printf("MAZE PROBLEM\n\n");
	printf("ENTRANCE\n");
	for (i = 1; i < 13; i++) {
		printf("  ");
		for (j = 1; j < 16; j++) {
			switch (maze[i][j])
			{
			case 0:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				printf("бс");
				break;
			case 1:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
				printf("бс");
				break;
			default:
				break;
			}
		}
		printf("\n");
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	printf("                              EXIT\n\n");
	printf("Start the Maze\n(Press any key to continue");
	getch();
	path(maze);
	printf("Press any key to exit\n");
	getch();
	return 0;
}