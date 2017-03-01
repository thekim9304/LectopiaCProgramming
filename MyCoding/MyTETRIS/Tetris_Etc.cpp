#include "Tetris_Etc.h"


Tetris_Etc::Tetris_Etc() : endLine(22), endRight(52), endLeft(26), startLeft(28), startRight(50)
{
}

Tetris_Etc::~Tetris_Etc()
{
}

void Tetris_Etc::gotoxy(int x, int y)
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

int Tetris_Etc::nowTime()
{
	int reTime;
	time_t t;
	time(&t);
	reTime = t;

	return reTime;
}