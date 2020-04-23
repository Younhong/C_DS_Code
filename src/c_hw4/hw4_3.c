#include <stdio.h>
#include <windows.h>

// function declaration
void gotoxy(int x, int y);
void clrscr();

int main()
{
	// variable x, y, oldx, oldy
	int x = 0, y = 0;
	int oldx = 0, oldy = 0;

	// read x,y
	printf("Input the coordinate of x and y: ");
	scanf("%d %d", &x, &y);

	// while statement if coordinate is out of range
	while (x < 1 || x > 80 || y < 1 || y > 24)
	{
		printf("Input the coordinate of x and y: ");
		scanf("%d %d", &x, &y);
	}

	// erase previous statements to see movements of coordinate better
	clrscr();
	
	oldx = x, oldy = y;

	// while statement
	while (1)
	{
		// erase previous point
		gotoxy(oldx, oldy);
		printf(" ");

		// print '*' at new point
		gotoxy(x, y);
		printf("*");

		oldx = x, oldy = y;

		// increment x,y
		x++, y++;

		// if statement to set x=1 if x is out of range
		if (x > 80)
		{
			x = 1;
		}
		// if statement to set y=1 if y is out of range
		if (y > 24)
		{
			y = 1;
		}

		Sleep(100);
	}

	return 0;
}

void gotoxy(int x, int y)
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void clrscr()
{
	COORD Cur = { 0, 0 };
	unsigned long dwLen = 0;
	FillConsoleOutputCharacter(GetStdHandle(STD_OUTPUT_HANDLE),' ', 80 * 25, Cur, &dwLen);
	gotoxy(1, 1);
}
