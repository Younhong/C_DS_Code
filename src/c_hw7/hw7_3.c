#include <stdio.h>
#include <windows.h>

// define CAR_WIDTH, CAR_HEIGHT
#define CAR_WIDTH 5
#define CAR_HEIGHT 5

// define enumeration type SmartCarType
enum SmartCarType {Google_car = 1, Apple_Car = 2};

// define structure SmartCar
typedef struct {
	// structure fields
	enum SmartCarType type;
	int x;
	int y;
} SmartCar;

// declaration of functions
void gotoxy(int x, int y);
void clrscr();
void DrawCar(int x, int y, char shape[][CAR_WIDTH + 1]);
void EraseCar(int x, int y);
void DrawSmartCar(SmartCar car);

int main()
{
	// variable type, key, my_car, oldx, oldy
	int type = 0;
	char key = ' ';
	SmartCar my_car;
	int oldx = 0, oldy = 0;

	// initialize my_car.x, my_car.y
	my_car.x = 38, my_car.y = 10;

	clrscr();

	// read my_car.type
	printf("Input the type of smart car (1: Google car, 2: Apple car): ");
	scanf("%d", &my_car.type);
	// if my_car.type is not 1 or 2, then repeat until 1 or 2 has been typed
	while (my_car.type != 1 && my_car.type != 2)
	{
		printf("Input the type of smart car (1: Google car, 2: Apple car): ");
		scanf("%d", &my_car.type);
	}

	// clear the previous statements to see the object better
	clrscr();
	
	// set oldx, oldy to my_car.x, my_car.y
	oldx = my_car.x, oldy = my_car.y;

	while (1)
	{
		// erase previous car
		gotoxy(oldx, oldy);
		EraseCar(oldx, oldy);
		// print car at new point
		gotoxy(my_car.x, my_car.y);
		DrawSmartCar(my_car);

		// save coordinate of my_car.x, my_car.y to oldx, oldy
		oldx = my_car.x, oldy = my_car.y;

		// variable key to get new character
		char key = getch();

		switch (key)
		{
			// if key='j'
		case 'j': if (my_car.x > 1) {
			// decrement my_car.x if my_car.x>1
			my_car.x--; break;
		}
				  // else set my_car.x=1
				  else {
					  my_car.x = 1; break;
				  }
				  // if key='l'
		case 'l': if (my_car.x < 76) {
			// increment my_car.x if my_car.x<76
			my_car.x++; break;
		}
				  // else setmy_car. x=76
				  else {
					  my_car.x = 76; break;
				  }
				  // if key='i'
		case 'i': if (my_car.y > 1) {
			// decrement my_car.y if my_car.y>1
			my_car.y--; break;
		}
				  // else set my_car.y=1
				  else {
					  my_car.y = 1; break;
				  }
				  // if key='k'
		case 'k': if (my_car.y < 20) {
			// increment my_car.y if my_car.y<20
			my_car.y++; break;
		}
				  // else set my_car.y=20
				  else {
					  my_car.y = 20; break;
				  }
				  // if key='q', then end the program
		case 'q': clrscr(); printf("Bye!\n"); exit(-1);
		}
	}

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

void DrawSmartCar(SmartCar car)
{
	// variable GoogleCar_shape, AppleCar_shape
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

	// if car.type is 1, then draw GoogleCar_shape
	if (car.type == 1)
	{
		DrawCar(car.x, car.y, GoogleCar_shape);
	}
	// if car.type is 2, then draw AppleCar_shape
	if (car.type == 2)
	{
		DrawCar(car.x, car.y, AppleCar_shape);
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