#include <stdio.h>
#include <conio.h>
#include <Windows.h>

// define SCREEN_WIDTH, SCREEN_HEIGHT
#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 23

// declaration of functions
void gotoxy(int x, int y);
void clrscr();
void ClearBuffer(char buffer[][SCREEN_WIDTH]);
void DrawBar(int startx, int len, int y, char buffer[][SCREEN_WIDTH], char v);

int main()
{
	// variable screen, t, startx, y, len, delay, dx
	char screen[SCREEN_HEIGHT][SCREEN_WIDTH];
	int t = 0;
	int startx = 1;
	int y = 12;
	int len = 7;
	int delay = 20;
	int dx = 1;

	// clear screen
	clrscr();
	ClearBuffer(screen);

	// for t is 0
	for (t = 0; 1; t++)
	{
		// if statement
		if (t % delay == 0)
		{
			// function call to erase previous result
			DrawBar(startx, len, y, screen, ' ');

			// compute startx[i]
			startx += dx;

			// if startx + len gets bigger than SCREEN_WIDTH, change direction to left
			if (startx > SCREEN_WIDTH - len)
				dx = -1;

			// if startx becomes less than 1, then change direction to right
			if (startx < 1)
				dx = 1;

			// function call to print '=' at new points
			DrawBar(startx, len, y, screen, '=');
		}

		if (_kbhit())
		{
			// receive the character entered as variable key
			char key = _getch();
			// if key is 'q' then exit the loop
			if (key == 'q')
				break;
		}

		Sleep(1);
	}

	// go to (1,1) and print message when 'q' is clicked
	gotoxy(1, 1);
	printf("Bye!\n");

	return 0;
}

void ClearBuffer(char buffer[][SCREEN_WIDTH])
{
	// variables x, y
	int x = 0, y = 0;
	
	// for statements to set buffer to ''
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
	// compute endx
	int endx = startx + len - 1;
	// variable x
	int x = 0;

	// if statements to print v in range
	if (startx < 1)
		startx = 1;
	if (endx > SCREEN_WIDTH)
		endx = SCREEN_WIDTH;

	gotoxy(startx, y);

	// print v from startx to endx
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