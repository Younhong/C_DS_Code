#include <stdio.h>
#include <windows.h>

void gotoxy(int x, int y);
void clrscr();

int main()
{
	int x = 0, y = 0;
	int oldx = 0, oldy = 0;
	int savex = 0, savey = 0;

	printf("Enter the coordinate of x and y: ");
	scanf("%d %d", &x, &y);

	if (x < 1 || x > 80 || y < 1 || y > 24)
	{
		printf("Enter the coordinate of x and y: ");
		scanf("%d %d", &x, &y);
	}

	clrscr();

	oldx = x, oldy = y;
	x++, y++;

	while (1)
	{
		gotoxy(oldx, oldy);
		printf(" ");

		gotoxy(x, y);
		printf("*");
		
		savex = oldx, savey = oldy;

		if (oldx == x - 1 && oldy == y - 1 && x < 80 && y < 24)
		{
			oldx = x, oldy = y;
			x++, y++;
		}
		if (oldx == x + 1 && oldy == y + 1 && x > 1 && y > 1)
		{
			oldx = x, oldy = y;
			x--, y--;
		}
		if (oldx == x + 1 && oldy == y - 1 && x > 1 && y < 24)
		{
			oldx = x, oldy = y;
			x--, y++;
		}
		if (oldx == x - 1 && oldy == y + 1 && x < 80 && y > 1)
		{
			oldx = x, oldy = y;
			x++, y--;
		}

		if (x == 1 && y == 1)
		{
			oldx = x, oldy = y;
			x++, y++;
		}
		if (x == 1 && y == 24)
		{
			oldx = x, oldy = y;
			x++, y--;
		}
		if (x == 80 && y == 1)
		{
			oldx = x, oldy = y;
			x--, y++;
		}
		if (x == 80 && y == 24)
		{
			oldx = x, oldy = y;
			x--, y--;
		}

		if (x == 1)
		{
			if (savey == y - 1)
			{
				oldx = x, oldy = y;
				x++, y++;
			}
			if (savey == y + 1)
			{
				oldx = x, oldy = y;
				x++, y--;
			}
		}
		if (x == 80)
		{
			if (savey == y - 1)
			{
				oldx = x, oldy = y;
				x--, y++;
			}
			if (savey == y + 1)
			{
				oldx = x, oldy = y;
				x--, y--;
			}
		}
		if (y == 1)
		{
			if (savex == x - 1)
			{
				oldx = x, oldy = y;
				x++, y++;
			}
			if (savex == x + 1)
			{
				oldx = x, oldy = y;
				x--, y++;
			}
		}
		if (y == 24)
		{
			if (savex == x - 1)
			{
				oldx = x, oldy = y;
				x++, y--;
			}
			if (savex == x + 1)
			{
				oldx = x, oldy = y;
				x--, y--;
			}
		}

		Sleep(75);
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