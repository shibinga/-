#include<stdio.h>
#include<windows.h>
#include<conio.h>

#define ROW 9
#define COL 11
char map[ROW][COL + 1] = {
	{"*#*********"},
	{"***###*###*"},
	{"###**#****#"},
	{"*#**###**#*"},
	{"***********"},
	{"#####*##*##"},
	{"**#*****#*E"},
	{"***#*###**#"},
	{"*#*********"},
};

void print_map()
{
	for (int i = 0; i < ROW; i++)
	{
		puts(map[i]);
	}
}

void show_cursor(int x, int y)
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	printf("curX=%d,curY=%d\n", x, y);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int curX, curY;
int main()
{
	while (1)
	{
		system("cls");
		print_map();
		show_cursor(curX, curY);

		char t =_getch();
		switch (t) {
		case 'w':
			if ((curY - 1) >= 0 && (map[curY - 1][curX] == '*' || map[curY - 1][curX] == 'E'))curY--;
			break;
		case 's':
			if ((curY + 1) < ROW && (map[curY + 1][curX] == '*' || map[curY + 1][curX] == 'E'))curY++;
			break;
		case 'a':
			if ((curY - 1) >= 0 && (map[curY][curX - 1] == '*' || map[curY][curX - 1] == 'E'))curX--;
			break;
		case 'd':
			if ((curX + 1) < COL && (map[curY][curX + 1] == '*' || map[curY][curX + 1] == 'E'))curX++;
			break;
		}
		if (map[curY][curX] == 'E')
		{ 
			break;
		}
	}
	return 0;
}
