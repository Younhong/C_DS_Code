#include <stdio.h>
#include <conio.h>
#include <windows.h>

#define BAR_INTERVAL 3
#define NO_BAR 7
#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 23

void gotoxy(int x, int y);
void clrscr();
void ClearBuffer(char buffer[][SCREEN_WIDTH]);
void DrawBar(int startx, int len, int y, char buffer[][SCREEN_WIDTH], char v);

int main()
{
	char screen[SCREEN_HEIGHT][SCREEN_WIDTH];
	int startx[NO_BAR];
	int y[NO_BAR];
	int len[NO_BAR];
	int delay[NO_BAR];
	int dx[NO_BAR];

	int i = 0, t = 0;

	clrscr();
	ClearBuffer(screen);

	for (i = 0; i < NO_BAR; i++)
	{
		startx[i] = 1;
		y[i] = BAR_INTERVAL * (i + 1);
		len[i] = rand() % 8 + 5;
		delay[i] = rand() % 31 + 10;
		dx[i] = 1;
	}

	for (t = 0; 1; t++)
	{
		for (i = 0; i < NO_BAR; i++)
		{
			if (t % delay[i] == 0)
			{
				DrawBar(startx[i], len[i], y[i], screen, ' ');

				startx[i] += dx[i];
				if (startx[i] > SCREEN_WIDTH - len[i])
					dx[i] = -1;

				if (startx[i] < 1)
					dx[i] = 1;

				DrawBar(startx[i], len[i], y[i], screen, '=');

				Sleep(delay[i]);
			}
		}

		if (_kbhit())
		{
			char key = _getch();
			if (key == 'q')
				break;
		}
	}

	gotoxy(1, 1);
	printf("Bye!\n");

	return 0;
}

void ClearBuffer(char buffer[][SCREEN_WIDTH])
{
	int x = 0, y = 0;

	for (y = 0; y < SCREEN_HEIGHT; y++)
	{
		for (x = 0; x < SCREEN_WIDTH; x++)
		{
			buffer[y][x] = ' ';
		}
	}
}

void DrawBar(int startx, int len, int y, char buffer[][SCREEN_WIDTH], char v)
{
	int endx = startx + len - 1;
	int x = 0;

	if (startx < 1)
		startx = 1;
	if (endx > SCREEN_WIDTH)
		endx = SCREEN_WIDTH;

	gotoxy(startx, y);

	for (x = startx; x <= endx; x++)
	{
		putchar(v);
		buffer[y - 1][x - 1] = v;
	}
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

	FillConsoleOutputCharacter(GetStdHandle(STD_OUTPUT_HANDLE),
		' ', 80 * 25, Cur, &dwLen);
	gotoxy(1, 1);
}