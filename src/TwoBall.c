#include <stdio.h>
#include <windows.h>

void gotoxy(int x, int y);
void clrscr();

int main()
{
	int x = 0, y = 0;
	int oldx = 0, oldy = 0;
	int a = 0, b = 0;
	int olda = 0, oldb = 0;

	printf("Input the coordinate of x and y: ");
	scanf("%d %d", &x, &y);

	printf("Input the coordinate of a and b: ");
	scanf("%d %d", &a, &b);

	while (x < 1 || x > 80 || y < 1 || y > 24)
	{
		printf("Input the coordinate of x and y: ");
		scanf("%d %d", &x, &y);
	}

	while (a < 1 || a > 80 || b < 1 || b > 24)
	{
		printf("Input the coordinate of a and b: ");
		scanf("%d %d", &a, &b);
	}

	clrscr();

	oldx = x, oldy = y;
	olda = a, oldb = b;

	while (1)
	{
		gotoxy(oldx, oldy);
		printf(" ");
		gotoxy(olda, oldb);
		printf(" ");

		gotoxy(x, y);
		printf("*");
		gotoxy(a, b);
		printf("@");

		oldx = x, oldy = y;
		olda = a, oldb = b;

		x++, y++;
		a++, b++;

		if (x > 80)
		{
			x = 1;
		}
		if (y > 24)
		{
			y = 1;
		}

		Sleep(100);

		if (a > 80)
		{
			a = 1;
		}
		if (b > 24)
		{
			b = 1;
		}
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
	FillConsoleOutputCharacter(GetStdHandle(STD_OUTPUT_HANDLE), ' ', 80 * 25, Cur, &dwLen);
	gotoxy(1, 1);
}