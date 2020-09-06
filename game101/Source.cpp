#include<stdio.h>
#include<windows.h>
#include<conio.h>
void gotoxy(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void draw_ship(int x, int y)
{
	if (x < 0) x = 0;
	if (x > 80)x = 80;
	if (y < 0) y = 0;
	if (y > 80)y = 80;
	gotoxy(x, y);
	printf("<-0->");
}
void erase_ship(int x, int y)
{
	gotoxy(x, y);
	printf("     ");
}
int main()
{
	char ch = ' ';
	int x = 38, y = 20;
	draw_ship(x, y);
	do 
	{
		if (_kbhit())
		{
			ch = _getch();
			erase_ship(x, y);
			if (ch == 'a') { draw_ship(--x, y); }
			if (ch == 'd') { draw_ship(++x, y); }
			if (ch == 'w') { draw_ship(x, --y); }
			if (ch == 's') { draw_ship(x, ++y); }
			fflush(stdin);
		}
		Sleep(10);
	} while (ch != 'x');
	return 0;
}