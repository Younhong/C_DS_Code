#include <stdio.h>
#include <conio.h>

#include <Windows.h>

#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 23


void gotoxy(int x, int y);	// move cursor to (x, y)
void clrscr();

void ClearBuffer(char buffer[][SCREEN_WIDTH]);
void DrawBar(int startx, int len, int y, char buffer[][SCREEN_WIDTH], char v);

int main()
{
	char screen[SCREEN_HEIGHT][SCREEN_WIDTH];
	int t = 0;					// master clock
	int startx = 1;
	int y = 12;
	int len = 7;
	int delay = 20;
	int dx = 1;

	clrscr();
	ClearBuffer(screen);

	for(t = 0; 1; t++){
		if(t % delay == 0){
			DrawBar(startx, len, y, screen, ' ');		// erase previous bar

			startx += dx;
			if(startx > SCREEN_WIDTH)
				startx = 1;

			DrawBar(startx, len, y, screen, '=');		// draw new bar
		}

		if(_kbhit()){
			char key = _getch();
			if(key == 'q')
				break;
		}

		Sleep(1);
	}

	gotoxy(1, 1);
	printf("Bye!\n");

	return 0;
}

void ClearBuffer(char buffer[][SCREEN_WIDTH])
{
	int x = 0, y = 0;
	
	for(y = 0; y < SCREEN_HEIGHT; y++){
		for(x = 0; x < SCREEN_WIDTH; x++){
			buffer[y][x] = ' ';
		}
	}
}

void DrawBar(int startx, int len, int y, char buffer[][SCREEN_WIDTH], char v)
{
	int endx = startx + len - 1;
	int x = 0;

	if(startx < 1)
		startx = 1;
	if(endx > SCREEN_WIDTH)
		endx = SCREEN_WIDTH;

	gotoxy(startx, y);

	for(x = startx; x <= endx; x++){
		putchar(v);
		buffer[y-1][x-1] = v;
	}
}

void gotoxy(int x, int y)	// move cursor to (x, y)
{
	COORD Pos = {x - 1, y - 1};

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}


void clrscr()		// clear the screen
{
	COORD Cur= {0, 0};
	unsigned long dwLen = 0;

	FillConsoleOutputCharacter(GetStdHandle(STD_OUTPUT_HANDLE),
		' ', 80*25, Cur, &dwLen);
	gotoxy(1, 1);
}
