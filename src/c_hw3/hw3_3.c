#include <stdio.h>
#include <windows.h>

// function declaration
void DrawHorizontalLine(int x1, int x2, int y);
void DrawVerticalLine(int x, int y1, int y2);
void gotoxy(int x, int y);
void clrscr();

int main()
{
	// function call
	clrscr();

	// variables: left_x, top_y, right_x, bottom_y
	int left_x = 0, top_y = 0, right_x = 0, bottom_y = 0;

	// read variables
	printf("Input coordinate of Root <left top right bottom>: ");
	scanf("%d %d %d %d", &left_x, &top_y, &right_x, &bottom_y);

	// function call
	DrawHorizontalLine(left_x, right_x, top_y);
	DrawHorizontalLine(left_x, right_x, bottom_y);
	DrawVerticalLine(left_x, top_y, bottom_y);
	DrawVerticalLine(right_x, top_y, bottom_y);

	printf("\n");

	return 0;
}

void DrawHorizontalLine(int x1, int x2, int y)
{
	// variable x
	int x = 0;

	// for statement
	for (x = x1; x <= x2; x++)
	{
		// function call
		gotoxy(x, y);
		printf("#");
	}

	return;
}

void DrawVerticalLine(int x, int y1, int y2)
{
	// variable y
	int y = 0;
	
	// for statement
	for (y = y1; y <= y2; y++)
	{
		// function call
		gotoxy(x, y);
		printf("#");
	}

	return;
}

void gotoxy(int x, int y)
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);

	return;
}

void clrscr()
{
	COORD Cur = { 0, 0 };
	unsigned long dwLen = 0;
	FillConsoleOutputCharacter(GetStdHandle(STD_OUTPUT_HANDLE), ' ', 80 * 25, Cur, &dwLen);
	gotoxy(1, 1);

	return;
}