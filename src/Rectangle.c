#include <stdio.h>
#include <windows.h>

void DrawHorizontalLine(int x1, int x2, int y);
void DrawVerticalLine(int x, int y1, int y2);
void gotoxy(int x, int y);
void clrscr();

int main()
{
	int left_x = 0, top_y = 0, right_x = 0, bottom_y = 0;
	int a = 0, b = 0, c = 0, d = 0;
	int m = 0, n = 0, p = 0, q = 0;
	int x = 0, y = 0, z = 0, w = 0;

	printf("Input coordinate of Root <left top right bottom>: ");
	scanf("%d %d %d %d", &left_x, &top_y, &right_x, &bottom_y);

	printf("Input coordinate of Root <left top right bottom>: ");
	scanf("%d %d %d %d", &a, &b, &c, &d);

	printf("Input coordinate of Root <left top right bottom>: ");
	scanf("%d %d %d %d", &m, &n, &p, &q);

	printf("Input coordinate of Root <left top right bottom>: ");
	scanf("%d %d %d %d", &x, &y, &z, &w);

	clrscr();

	DrawHorizontalLine(left_x, right_x, top_y); // 10 10 30 30
	DrawHorizontalLine(left_x, right_x, bottom_y); // 10 20 30 40
	DrawVerticalLine(left_x, top_y, bottom_y); // 20 10 40 30
	DrawVerticalLine(right_x, top_y, bottom_y); // 20 20 40 40

	DrawHorizontalLine(a, c, b);
	DrawHorizontalLine(a, c, d);
	DrawVerticalLine(a, b, d);
	DrawVerticalLine(c, b, d);

	DrawHorizontalLine(m, p, n);
	DrawHorizontalLine(m, p, q);
	DrawVerticalLine(m, n, q);
	DrawVerticalLine(p, n, q);

	DrawHorizontalLine(x, z, y);
	DrawHorizontalLine(x, z, w);
	DrawVerticalLine(x, y, w);
	DrawVerticalLine(z, y, w);

	printf("\n");

	return 0;
}

void DrawHorizontalLine(int x1, int x2, int y)
{
	int x = 0;

	for (x = x1; x <= x2; x++)
	{
		gotoxy(x, y);
		printf("#");
	}

	return;
}

void DrawVerticalLine(int x, int y1, int y2)
{
	int y = 0;

	for (y = y1; y <= y2; y++)
	{
		gotoxy(x, y);
		printf("#");
	}

	return;
}

void gotoxy(int x, int y)
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);

	return;
}

void clrscr()
{
	COORD Cur = { 0, 0 };
	unsigned long dwLen = 0;
	FillConsoleOutputCharacter(GetStdHandle(STD_OUTPUT_HANDLE), ' ', 80 * 25, Cur, &dwLen);
	gotoxy(1, 1);

	return;
}