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

void ViewGround::blockAutoDown(int(*makeBlock_Arr)[4], int(*ground_Arr)[22], int *endLine_Arr, int (*view)[4])
{
	if (checkGround(makeBlock_Arr, ground_Arr, endLine_Arr) == true)
		return;

	if (checkEndline(makeBlock_Arr, endLine_Arr) == true)
		return;

	clearBlock(makeBlock_Arr);
	clearPredict(view);

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

void ViewGround::viewPredict(int(*makeBlock)[4], int(*view)[4], int *endLine_Arr)
{
	int endline = 21;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++)
			view[i][j] = makeBlock[i][j];
	}

	
	for (int i = 0; i < 4; i++) {
		if (view[i][0] != 0) {
			for (int j = 1; j < 4; j++) {
				if (view[i][j] != 0) {
					if (endline > endLine_Arr[view[i][j] - getstartLeft()])
						endline = endLine_Arr[view[i][j] - getstartLeft()];
				}
			}
		}
	}

	if ((view[0][0] == view[3][0]) && (view[1][0] == view[3][0])) {
		for (int i = 0; i < 4; i++)
			view[i][0] = endline - 1;
	}
	else {
		for (int i = 3; i >= 0; i--) {
			if (view[i][0] != 0) {
				view[i][0] = --endline;
			}
		}
	}

	for (int i = 0; i < 4; i++) {
		if (view[i][0] != 0) {
			for (int j = 1; j < 4; j++) {
				if (view[i][j] != 0) {
					gotoxy(view[i][j], view[i][0]);
					cout << "бр";
				}
			}
		}
	}
}

void ViewGround::clearPredict(int(*view)[4])
{
	for (int i = 0; i < 4; i++) {
		if (view[i][0] != 0) {
			for (int j = 1; j < 4; j++) {
				if (view[i][j] != 0) {
					gotoxy(view[i][j], view[i][0]);
					cout << " ";
				}
			}
		}
	}
}