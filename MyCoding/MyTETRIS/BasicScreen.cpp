#include "BasicScreen.h"



BasicScreen::BasicScreen() : Tetris_Etc()
{
}


BasicScreen::~BasicScreen()
{
}

void BasicScreen::basicScreen()
{
	for (int i = 1; i < getEndLine(); i++) {  // ���� ����
		gotoxy(getEndLeft(), i);
		cout << "��";
	}

	for (int i = 1; i < getEndLine(); i++) {  // ������ ����
		gotoxy(getEndRight(), i);
		cout << "��";
	}

	for (int i = getEndLeft(); i <= getEndRight(); i += 2)  // �� �� 
	{
		gotoxy(i, getEndLine());
		cout << "��";
	}
}
