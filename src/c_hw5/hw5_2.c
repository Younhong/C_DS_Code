#include <stdio.h>
#include <windows.h>

// define variable SCREEN_WIDTH, SCREEN_HEIGHT
#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 23

// function declaration
void ReadText(char file_name[], char text_buffer[][SCREEN_WIDTH]);
void DisplayText(char text_buffer[][SCREEN_WIDTH]);
void gotoxy(int x, int y);
void clrscr();

int main()
{
	// variable filename[], text_buffer[]
	char filename[30];
	char text_buffer[SCREEN_HEIGHT][SCREEN_WIDTH];

	// read filename
	printf("Input filename: ");
	scanf("%s", filename);

	// function to to read the file
	ReadText(filename, text_buffer);

	return 0;
}

void ReadText(char file_name[], char text_buffer[][SCREEN_WIDTH])
{
	// open the file
	FILE *fp = fopen(file_name, "r");

	// if file doesn't exist, exit
	if (fp == NULL)
	{
		printf("Failed to open %s\n", file_name);
		exit(-1);
	}
	
	// variable c, row, col
	char c = ' ';
	int row = 0, col = 0;

	// 
	for (row = 0; row <= SCREEN_HEIGHT - 1; row++)
	{
		//
		for (col = 0; col <= SCREEN_WIDTH - 1; col++)
		{
			// initialize the array to ' '
			text_buffer[row][col] = ' ';
		}
	}

	// for row is 0 to SCREEN_HEIGHT-1
	for (row = 0; row <= SCREEN_HEIGHT - 1; row++)
	{
		// for col is 0 to SCREEN_WIDTH-1
		for (col = 0; col <= SCREEN_WIDTH - 1; col++)
		{
			// while c is printable
			do{
				// if c from fp didn't reach EOF
				if ((c = fgetc(fp)) != EOF)
				{
					// set text_buffer[row][col] to c
					text_buffer[row][col] = c;
				}
			} while (!isprint(c));
		}
	}

	// function to display the text read from the file
	DisplayText(text_buffer);

	// close the file
	fclose(fp);

	return;
}

void DisplayText(char text_buffer[][SCREEN_WIDTH])
{
	// erase previous instructions
	clrscr();

	// for t is o to SCREEN_WIDTH/2-1
	for (int t = 0; t < SCREEN_WIDTH / 2; t++)
	{
		// for y is 1 to SCREEN_HEIGHT
		for (int y = 1; y <= SCREEN_HEIGHT; y++)
		{
			// print text_buffer[y-1][40-t-1] on (40-t,y)
			gotoxy(40 - t, y);
			printf("%c", text_buffer[y - 1][40 - t - 1]);
			// print text_buffer[y-1][41+t+1] on (41+t,y)
			gotoxy(41 + t, y);
			printf("%c", text_buffer[y - 1][41 + t - 1]);
		}
	// sleep for 10
	Sleep(10);
	}
	
	printf("\n");

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