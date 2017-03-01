#include "ViewGround.h"

ViewGround::ViewGround() : MakeBlock()
{
}


ViewGround::~ViewGround()
{
}

void ViewGround::viewBlock(const int(*makeBlock_Arr)[4])
{
	for (int i = 0; i < 4; i++) {
		if (makeBlock_Arr[i][0] != 0) {
			for (int j = 1; j < 4; j++) {
				if (makeBlock_Arr[i][j] != 0) {
					gotoxy(makeBlock_Arr[i][j], makeBlock_Arr[i][0]);
					cout << "бс";
				}
			}
		}
	}
}

void ViewGround::viewGround(const int(*ground_Arr)[22])  // ground_Arr[24][22]
{
	for (int i = 0; i < 24; i++) {
		for (int j = 0; j < 22; j++) {
			if (ground_Arr[i][j] != 0) {
				gotoxy(i + getstartLeft(), j);
				cout << "бс";
			}
		}
	}
}

void ViewGround::clearBlock(int(*viewBlock)[4])
{
	for (int i = 0; i < 4; i++) {
		for (int j = 1; j < 4; j++) {
			if (viewBlock[i][0] != 0) {
				if (viewBlock[i][j] != 0) {
					gotoxy(viewBlock[i][j], viewBlock[i][0]);
					cout << " ";
				}
			}
		}
	}
}

void ViewGround::blockAutoDown(int(*makeBlock_Arr)[4], int(*ground_Arr)[22], int *endLine_Arr)
{
	if (checkGround(makeBlock_Arr, ground_Arr, endLine_Arr) == true)
		return;

	if (checkEndline(makeBlock_Arr, endLine_Arr) == true)
		return;

	clearBlock(makeBlock_Arr);

	if (makeBlock_Arr[0][0] != 0)
		makeBlock_Arr[0][0]++;

	if (makeBlock_Arr[1][0] != 0)
		makeBlock_Arr[1][0]++;

	if (makeBlock_Arr[2][0] != 0)
		makeBlock_Arr[2][0]++;

	if (makeBlock_Arr[3][0] != 0)
		makeBlock_Arr[3][0]++;
}

void ViewGround::clearGround(int(*ground_Arr)[22])
{
	for (int i = 0; i < 24; i++) {
		for (int j = 0; j < 22; j++) {
			if (ground_Arr[i][j] != 0) {
				gotoxy(i + getstartLeft(), j);
				cout << " ";
			}
		}
	}
}