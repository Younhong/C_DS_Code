#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include "Maze.h"

int top = -1;

//maze stack
element stack[100];
//to check whether the route has been passed already
int mark[14][17] = { 0 };

//N, NE, E, SE, S, SW, W, NW
offsets move[8] = {
	{-1,0},
	{-1,1},
	{0,1},
	{1,1},
	{1,0},
	{1,-1},
	{0,-1},
	{-1,-1}
};

//draw the result
void draw(int(*maze)[17],int row, int col)
{

	//marking the colored part 0->2
	int i,j;
	for (i = 0; i <= top; i++)
		maze[stack[i].row][stack[i].col]=2;
	maze[row][col]=2;
	maze[EXIT_ROW][EXIT_COL]=2;

	//clear screen
	system("cls");
	//redraw
	printf(" Result: \n");
	printf("ENTRANCE\n");
	for (i = 1; i < 13; i++) {
		printf("  ");
		for (j = 1; j < 16; j++) {
			switch (maze[i][j])
			{
			//not passed - 5white
			case 0:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				printf("бс");
				break;
			//wall - yellow
			case 1:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
				printf("бс");
				break;
			//path color - blue
			case 2:
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
				printf("бс");
				break;
			default:
				break;
			}
		}
		printf("\n");
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	printf("                              EXIT\n\n");
}

//What you have to do
void path(int (*maze)[17]) {

	//row col: current location
	//nextRow: nextCol: predicted location
	//dir:direction
	int i, row, col, nextRow, nextCol, dir, found = FALSE;
	element position;
	
	//initialization
	top = 0;
	mark[1][1] = 1;
	stack[0].row = 1;
	stack[0].col = 1;
	stack[0].dir = 1;

	//stop searching until the exit is found 
	//or no route has been found
	while (top > -1 && !found)
	{
		//Write Code Here
		while (dir < 8 && !found)
		{
			//move in direction dir
			//prediction of next move

			//if it is exit, change to true

			//pushing if next row and next coloumn is 0 
			//and has not been marked 
			else if (!maze[nextRow][nextCol] && !mark[nextRow][nextCol])
			{
				//change the mark as 1

				//set position's current row, col, and direction

				//set row & col as nextRow & nextCol and dir = 0

			}
			//else dir up
		}
	}
	//if found redraw the maze 
	if (found)
	{
		draw(maze, row, col);
	}
	//else not found
	else printf("The maze does not have a path\n");

}

int isFull() {
	if (top == 99) {
		printf("Stack is Full\n");
		return YES;
	}
	return NO;
}

int isEmpty() {
	if (top == -1) {
		printf("Stack is Empty\n");
		return YES;
	}
	return NO;
}

void push(element item) {
	if (isFull==YES)
		return;
	stack[++top] = item;
}

element pop() {
	if (isEmpty == YES)
		return;
	return stack[top--];
}


