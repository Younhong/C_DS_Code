#include <stdio.h>
#include <windows.h>

// define CAR_WIDTH, CAR_HEIGHT
#define CAR_WIDTH 5
#define CAR_HEIGHT 5

// declaration of functions
void gotoxy(int x, int y);
void clrscr();
void DrawCar(int x, int y, char shape[][CAR_WIDTH + 1]);
void EraseCar(int x, int y);

int main()
{
	// variable type, x, y, GoogleCar_shape, AppleCar_shape
	int type = 0, x = 0, y = 0;
	char GoogleCar_shape[CAR_HEIGHT][CAR_WIDTH + 1] = {
		"0---0",
		" I I ",
		" IGI ",
		" I I ",
		"0---0"
	};
	char AppleCar_shape[CAR_HEIGHT][CAR_WIDTH + 1] = {
		"0===0",
		"  +  ",
		" IAI ",
		"  +  ",
		"0===0"
	};

	// read type
	printf("Input the type of smart car (1: Google car, 2: Apple car): ");
	scanf("%d", &type);
	// if type is not 1 or 2, then repeat until 1 or 2 has been typed
	while (type != 1 && type != 2)
	{
		printf("Input the type of smart car (1: Google car, 2: Apple car): ");
		scanf("%d", &type);
	}
	// read x, y
	printf("Input the coordinate of smart car (x and y): ");
	scanf("%d %d", &x, &y);

	// clear the previous statements to see the object better
	clrscr();
	EraseCar(x, y);

	// if type is 1, then draw GoogleCar_shape
	if (type == 1)
	{
		DrawCar(x, y, GoogleCar_shape);
	}
	// if type is 2, then draw AppleCar_shape
	if (type == 2)
	{
		DrawCar(x, y, AppleCar_shape);
	}

	printf("\n");

	return 0;
}

void DrawCar(int x, int y, char shape[][CAR_WIDTH + 1])
{
	// for j is from 0 to 4
	for (int j = 0; j < 5; j++)
	{
		// move to (x,y)
		gotoxy(x, y);
		// for i is from 0 to 4
		for (int i = 0; i < 5; i++)
		{
			// print shape[j][i]
			printf("%c", shape[j][i]);
		}
		// increment y by 1
		y++;
	}
	return;
}

void EraseCar(int x, int y)
{
	// for j is from 0 to 4
	for (int j = 0; j < 5; j++)
	{
		// move to (x,y)
		gotoxy(x, y);
		// for i is from 0 to 4
		for (int i = 0; i < 5; i++)
		{
			// print " "
			printf(" ");
		}
		// increment y by 1
		y++;
	}

	return;
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