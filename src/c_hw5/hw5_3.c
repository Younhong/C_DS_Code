#include <stdio.h>
#include <windows.h>

// function declaration
void gotoxy(int x, int y);
void clrscr();

int main()
{
	// variable x, y, oldx, oldy
	int x = 40, y = 12;
	int oldx = 0, oldy = 0;

	// save coordinate of x, y to oldx, oldy
	oldx = x, oldy = y;
	
	while(1)
	{
		// erase previous point
		gotoxy(oldx, oldy);
		printf(" ");
		// print '*' at new point
		gotoxy(x, y);
		printf("*");

		// save coordinate of x, y to oldx, oldy
		oldx = x, oldy = y;
	
		// variable key to get new character
		char key = getch();

		switch (key)
		{
		// if key='j'
		case 'j': if (x > 1) {
			// decrement x if x>1
			x--; break;
		}
				  // else set x=1
				  else {
					  x = 1; break;
				  }
		// if key='l'
		case 'l': if (x < 80) {
			// increment x if x<80
			x++; break;
		}
				  // else set x=80
				  else {
					  x = 80; break;
				  }
		// if key='i'
		case 'i': if (y > 1) {
			// decrement y if y>1
			y--; break;
		}
				  // else set y=1
				  else {
					  y = 1; break;
				  }
		// if key='k'
		case 'k': if (y < 24) {
			// increment y if y<24
			y++; break;
		}
				  // else set y=24
				  else {
					  y = 24; break;
				  }
		// if key='q', then end the program
		case 'q': clrscr(); printf("Bye.\n"); exit(-1);
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

	FillConsoleOutputCharacter(GetStdHandle(STD_OUTPUT_HANDLE),
		' ', 80 * 25, Cur, &dwLen);
	gotoxy(1, 1);
}