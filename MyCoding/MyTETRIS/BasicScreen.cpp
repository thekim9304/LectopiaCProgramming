#include "BasicScreen.h"



BasicScreen::BasicScreen() : Tetris_Etc()
{
}


BasicScreen::~BasicScreen()
{
}

void BasicScreen::basicScreen()
{
	for (int i = 1; i < getEndLine(); i++) {  // 哭率 技肺
		gotoxy(getEndLeft(), i);
		cout << "⑺";
	}

	for (int i = 1; i < getEndLine(); i++) {  // 坷弗率 技肺
		gotoxy(getEndRight(), i);
		cout << "⑺";
	}

	for (int i = getEndLeft(); i <= getEndRight(); i += 2)  // 盖 关 
	{
		gotoxy(i, getEndLine());
		cout << "⑺";
	}
}
