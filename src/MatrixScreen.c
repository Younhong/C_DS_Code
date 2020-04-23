#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <conio.h>

#define COLUMN 80
#define ROW 24

char GetRandomChar();		// a function that returns a random alpha-numeric character

void clrscr(void);			// clear the screen
void gotoxy(int x, int y);	// move cursor to (x, y)

int main()
{
	int t = 0;				// main timer
	int y[COLUMN];			// y coordinates for each column
	int delay[COLUMN];		// inverse of speed of each column
	int length[COLUMN];		// length of each column

	int col = 0;
	
	clrscr();

	printf("This program displays a Matrix-like screen.\n");
	printf("If you want to finish, press 'q'.\n");
	printf("Press enter to start :");
	getchar();

	srand(time(NULL));
	
	// initialize each columns
	for(col = 0; col < COLUMN; col++){
		y[col] = 1;
		delay[col] = rand() % 10 + 1;	// initialize delay and length
		length[col] = rand() % 5 + 3;
	}

	while(1){
		if(kbhit() && getch() == 'q')	// if 'q' is pressed, terminate the loop (You may ignore this line.)
				break;

		for(col = 0; col < COLUMN; col++){
			if(t % delay[col] == 0){
				// print a random character at current position
				gotoxy(col + 1, y[col]);
				putchar(GetRandomChar());

				// erase previous location
				if(y[col] - length[col] >= 1)
					gotoxy(col + 1, y[col] - length[col]);
				else
					gotoxy(col + 1, ROW + y[col] - length[col]);	// wrapped
				putchar(' ');

				// increase current y coordinate
				y[col]++;

				// check if y reached the last row
				if(y[col] > ROW){
					y[col] = 1;
					delay[col] = rand() % 10 + 1;	// reset delay and length
					length[col] = rand() % 5 + 3;
				}
			}
		}
		
		Sleep(100);
		t++;				// time
	}

	clrscr();
	
	gotoxy(1, 1);
	printf("Good bye!\n");

	system("PAUSE");

	return 0;	
}

char GetRandomChar()
{
	const int noUpperCase = 26;
	const int noLowerCase = 26;
	const int noDigits = 10;

	int x = rand() % (noUpperCase + noLowerCase + noDigits);
	if(x < noUpperCase)
		return 'A' + x;
	else if(x < noUpperCase + noLowerCase)
		return 'a' + x - noUpperCase;
	else
		return '0' + x - (noUpperCase + noLowerCase);
}

void clrscr(void)		// clear the screen
{
	COORD Cur= {0, 0};
	unsigned long dwLen = 0;

	FillConsoleOutputCharacter(GetStdHandle(STD_OUTPUT_HANDLE), ' ', 80*25, Cur, &dwLen);
}

void gotoxy(int x, int y)	// move cursor to (x, y)
{
	COORD Pos = {x - 1, y - 1};

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

