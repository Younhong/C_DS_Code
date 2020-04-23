#include <stdio.h>
#include <conio.h>
#include <windows.h>

// define BAR_INTERVAL, NO_BAR, SCREEN_WIDTH, SCREEN_HEIGHT
#define BAR_INTERVAL 3
#define NO_BAR 7
#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 23

// declaration of functions
void gotoxy(int x, int y);
void clrscr();
void ClearBuffer(char buffer[][SCREEN_WIDTH]);
void DrawBar(int startx, int len, int y, char buffer[][SCREEN_WIDTH], char v);

int main()
{
	// variables screen, startx, y, len, delay, dx, i, t
	char screen[SCREEN_HEIGHT][SCREEN_WIDTH];
	int startx[NO_BAR];
	int y[NO_BAR];
	int len[NO_BAR];
	int delay[NO_BAR];
	int dx[NO_BAR];
	int i = 0, t = 0;

	// clear screen
	clrscr();
	ClearBuffer(screen);

	// initializing seed
	srand(time(NULL));

	// for i is 0 to NO_BAR-1
	for (i = 0; i < NO_BAR; i++)
	{
		startx[i] = 1;
		y[i] = BAR_INTERVAL * (i + 1);
		len[i] = rand() % 8 + 5;
		delay[i] = rand() % 31 + 10;
		dx[i] = 1;
	}

	// for t is 0
	for (t = 0; 1; t++)
	{
		// for i is 0 to NO_BAR-1
		for (i = 0; i < NO_BAR; i++)
		{
			// if statement
			if (t % delay[i] == 0)
			{
				// function call to erase previous result
				DrawBar(startx[i], len[i], y[i], screen, ' ');

				// compute startx[i]
				startx[i] += dx[i];

				// if startx[i] is bigger than SCREEN_WIDTH, then set startx[i] to 1
				if (startx[i] > SCREEN_WIDTH)
					startx[i] = 1;

				// function call to print '=' at new points
				DrawBar(startx[i], len[i], y[i], screen, '=');

				Sleep(delay[i]);
			}
		}

			if (_kbhit())
			{
				// receive the character entered as variable key
				char key = _getch();
				// if key is 'q' then exit the loop
				if (key == 'q')
					break;
			}
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