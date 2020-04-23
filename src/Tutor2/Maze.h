#ifndef __MAZE_H
#define __MAZE_H

#define YES 1
#define NO 0

#define TRUE 1
#define FALSE 0

#define EXIT_ROW 12
#define EXIT_COL 15


typedef struct element
{
	short int row;
	short int col;
	short int dir;
}element;

typedef struct offsets
{
	short int vert;
	short int horiz;
}offsets;

//Normal Stack functions
int isFull();
int isEmpty();
void push(element item);
element pop();

//What we are going to do

void path(int (*maze)[17]);

void draw(int (*maze)[17], int row, int col);
#endif