#include "ViewGround.h"
#include "BasicScreen.h"
#include "KeyBoard.h"
#include "PlayTime.h"

int blockStart = 38;

int MakeBlock::tetBlock_Arr[7][4][4] = {
	{ { 1, blockStart, blockStart + 2, 0 },{ 2, blockStart, blockStart + 2, 0 }, },  // 네모
	{ { 1, blockStart, 0, 0 },{ 2, blockStart, 0, 0 },{ 3, blockStart, 0, 0 },{ 4, blockStart, 0, 0 } },  // 일자
	{ { 1, 0, blockStart + 2, blockStart + 4 },{ 2, blockStart, blockStart + 2, 0 } },    // reverse ㄹ
	{ { 1, blockStart, blockStart + 2, 0 },{ 2, 0, blockStart + 2, blockStart + 4 } }, // ㄹ
	{ { 1, 0, 0, blockStart + 4 },{ 2, blockStart, blockStart + 2, blockStart + 4 } }, // reverse ㄴ
	{ { 1, blockStart, 0, 0 },{ 2, blockStart, blockStart + 2, blockStart + 4 } }, // ㄴ
	{ { 1, 0, blockStart + 2, 0 },{ 2, blockStart, blockStart + 2, blockStart + 4 } }  // ㅗ
};
int MakeBlock::ground_Arr[24][22] = { 0, };
int MakeBlock::endLine_Arr[24] = { 0, };
int MakeBlock::makeBlock_Arr[4][4] = { 0, };


void deleteCursor();  // 커서 없애기
void checkGround(int(*ground_Arr)[22], int *groundCheck);
void deleteGround(int(*ground_Arr)[22], int*groundCheck);

int main()
{
	BasicScreen basicScreen;
	MakeBlock block;
	ViewGround viewBlock;
	KeyBoard keyBoard;
	int ret, retD;
	int nowTime, ingTime;
	int groundCheck[22] = { 0, };

	deleteCursor();

	basicScreen.basicScreen();

	ingTime = keyBoard.nowTime();

	retD = viewBlock.makeBlock(block.makeBlock_Arr);
	while (1) {
		
		viewBlock.viewBlock(block.makeBlock_Arr);
		viewBlock.viewGround(block.ground_Arr);

		keyBoard.directionKey(block.makeBlock_Arr, block.ground_Arr, block.endLine_Arr, retD);

		nowTime = keyBoard.nowTime();

		if ((nowTime - ingTime) > 1) {
			viewBlock.blockAutoDown(block.makeBlock_Arr, block.ground_Arr, block.endLine_Arr);
			ingTime = keyBoard.nowTime();
		}

		viewBlock.viewBlock(block.makeBlock_Arr);

		ret = block.checkGround(block.makeBlock_Arr, block.ground_Arr, block.endLine_Arr);

	    if (ret == true) {
			viewBlock.plusGround(block.makeBlock_Arr, block.ground_Arr, block.endLine_Arr);
			retD = viewBlock.makeBlock(block.makeBlock_Arr);

			viewBlock.clearGround(block.ground_Arr);
			checkGround(block.ground_Arr, groundCheck);
			deleteGround(block.ground_Arr, groundCheck);
			block.plusEndline(block.ground_Arr, block.endLine_Arr);
		}
	}
}

void deleteCursor()
{
	CONSOLE_CURSOR_INFO info;

	info.bVisible = 0;
	info.dwSize = 100;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

void checkGround(int(*ground_Arr)[22], int *groundCheck)
{
	int i, j, check;

	for (i = 21; i > 0; i--) {
		check = 1;

		for (j = 0; j < 24; j += 2) {
			if (ground_Arr[j][i] != 1) {
				check = 0;
				break;
			}
		}
		if (check == 1)
			groundCheck[i] = 1;
	}
}

void deleteGround(int(*ground_Arr)[22], int*groundCheck)
{/*
	for (int i = 21; i > 0; i--) {
		if (groundCheck[i] == 1) {
			for (int j = 0; j < 24; j += 2) {
				for (int k = i; k > 0; k--) {
					ground_Arr[j][k] = ground_Arr[j][k - 1];
				}
			}
			groundCheck[i] = 0;
		}
	}
	*/

	for (int i = 1; i < 22; i++) {
		if (groundCheck[i] == 1) {
			for (int j = 0; j < 24; j += 2) {
				for (int k = i; k > 0; k--) {
					ground_Arr[j][k] = ground_Arr[j][k - 1];
				}
			}
			groundCheck[i] = 0;
		}
	}
}