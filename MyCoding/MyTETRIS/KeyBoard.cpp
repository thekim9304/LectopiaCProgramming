#include "KeyBoard.h"



KeyBoard::KeyBoard()
{
}


KeyBoard::~KeyBoard()
{
}

void KeyBoard::directionKey(int(*makeBlock_Arr)[4], int(*ground_Arr)[22], int *endline_Arr, int blockNum, int (*view)[4])
{
	char ch;
	int kFlag;

	ch = inKey(&kFlag);

	switch (ch) {
	case UP_ARROW:
		clearBlock(makeBlock_Arr);
		clearPredict(view);
		upArrow(makeBlock_Arr, blockNum);
		break;
	case DOWN_ARROW:
		clearBlock(makeBlock_Arr);
		clearPredict(view);
		downArrow(makeBlock_Arr, ground_Arr, endline_Arr, blockNum);
		break;
	case LEFT_ARROW:
		clearBlock(makeBlock_Arr);
		clearPredict(view);
		leftArrow(makeBlock_Arr, ground_Arr, endline_Arr);
		break;
	case RIGHT_ARROW:
		clearBlock(makeBlock_Arr);
		clearPredict(view);
		rightArrow(makeBlock_Arr, endline_Arr);
		break;
	case SPACE_BAR:
		clearBlock(makeBlock_Arr);
		clearPredict(view);
		spaceBar(makeBlock_Arr, endline_Arr, blockNum);
		break;
	default:
		break;
	}
}

void KeyBoard::downArrow(int(*makeBlock_Arr)[4], int(*ground_Arr)[22], int *endline_Arr, int blockNum)
{
	int i, check;

	for (i = 0; i < 4; i++) {
		if (makeBlock_Arr[i][0] != 0) {
			check = i + 1;

			for (int j = 0; j < 4; j++) {
				if (ground_Arr[makeBlock_Arr[i][j] - getstartLeft()][makeBlock_Arr[i][0] + 1] == 1) {
					return;
				}
			}
		}
	}
	for (int k = 0; k < check; k++)
		makeBlock_Arr[k][0]++;
}

void KeyBoard::leftArrow(int(*makeBlock_Arr)[4], int(*ground_Arr)[22], int *endline_Arr)
{
	for (int i = 0; i < 4; i++) {
		if (makeBlock_Arr[i][0] != 0) {
			for (int j = 1; j < 4; j++) {
				if ((makeBlock_Arr[i][j] != 0) && (makeBlock_Arr[i][j] - 2) == getEndLeft())
					return;
			}
		}
	}
	for (int i = 0; i < 4; i++) {   // 옆으로 끼기
		if (makeBlock_Arr[i][0] != 0) {
			for (int j = 1; j < 4; j++) {
				if (1 == ground_Arr[makeBlock_Arr[i][j] - 30][makeBlock_Arr[i][0]])
					return;
			}
		}
	}

	for (int i = 0; i < 4; i++) {
		if (makeBlock_Arr[i][0] != 0) {
			for (int j = 1; j < 4; j++) {
				if (makeBlock_Arr[i][j] != 0)
					makeBlock_Arr[i][j] -= 2;
			}
		}
	}
}

void KeyBoard::rightArrow(int(*makeBlock_Arr)[4], int *endline_Arr)
{
	for (int i = 0; i < 4; i++) {
		if (makeBlock_Arr[i][0] != 0) {
			for (int j = 1; j < 4; j++) {
				if ((makeBlock_Arr[i][j] != 0) && (makeBlock_Arr[i][j] + 2) == getEndRight())
					return;
			}
		}
	}
	for (int i = 0; i < 4; i++) {
		if (makeBlock_Arr[i][0] != 0) {
			for (int j = 1; j < 4; j++) {
				if (1 == ground_Arr[makeBlock_Arr[i][j] - 26][makeBlock_Arr[i][0]])
					return;
			}
		}
	}

	for (int i = 0; i < 4; i++) {
		if (makeBlock_Arr[i][0] != 0) {
			for (int j = 1; j < 4; j++) {
				if (makeBlock_Arr[i][j] != 0)
					makeBlock_Arr[i][j] += 2;
			}
		}
	}
}

void KeyBoard::spaceBar(int(*makeBlock_Arr)[4], int *endline_Arr, int blockNum)   // ㄹ 자랑 ㄴ 자 문제 해결하셈 
{
	int mini = getEndLine(), caseN = 1;
	int result = 1;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (makeBlock_Arr[i][0] < endLine_Arr[makeBlock_Arr[i][j] - getstartLeft()])
				caseN = 2;
		}
	}

	for (int i = 0; i < 4; i++) {
		if (makeBlock_Arr[i][0] != 0) {
			for (int j = 1; j < 4; j++) {
				if (makeBlock_Arr[i][j] != 0) {
					if (mini > endline_Arr[makeBlock_Arr[i][j] - getstartLeft()])
						mini = endline_Arr[makeBlock_Arr[i][j] - getstartLeft()];
				}
			}
		}
	}

	if ((makeBlock_Arr[0][0] == makeBlock_Arr[3][0]) && (makeBlock_Arr[1][0] == makeBlock_Arr[3][0])) {
		for (int i = 0; i < 4; i++)
			makeBlock_Arr[i][0] = mini - 1;
	}
	else {
		for (int i = 3; i >= 0; i--) {
			if (makeBlock_Arr[i][0] != 0) {
				makeBlock_Arr[i][0] = --mini;
			}
		}
	}
}

char KeyBoard::getKey()
{
	if (kbhit())
	{
		return getch();
	}
	return '\0';
}

char KeyBoard::inKey(int *keyFlag)
{
	char ascii, scan;

	ascii = getKey(); // 입력된 문자의 아스키코드를 입력받아옴 
	if (ascii != '\0') {
		if (ascii == -32 || ascii == 0) { // 입력된 문자의 아스키코드가 -32이거나 0이면 특수키가 입력된것임 
			scan = getch(); // 특수키가 입력되었을때에는 scan code값을 입력받아옴 
			*keyFlag = SPECIAL_KEY;
			return (scan);
		}
		else { // 일반키가 입력되었으면 
			*keyFlag = COMMON_KEY;
			return (ascii);
		}
	}

	return 0;
}

void KeyBoard::upArrow(int(*makeBlock_Arr)[4], int blockNum)
{
	int caseNum, copy[4][4];

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			copy[i][j] = makeBlock_Arr[i][j];
		}
	}

	switch (blockNum) {
	case quadrangle:
		break;
	case straight:
		caseNum = checkStraight(copy, ground_Arr, endLine_Arr);
		upStraight(makeBlock_Arr, caseNum);
		break;
	case RtwoCurve:
		caseNum = checkRtwoCurve(copy, ground_Arr, endLine_Arr);
		upRtwoCurve(makeBlock_Arr, caseNum);
		break;
	case twoCurve:
		caseNum = checktwoCurve(copy, ground_Arr, endLine_Arr);
		uptwoCurve(makeBlock_Arr, caseNum);
		break;
	case RoneCurve:
		caseNum = checkRoneCurve(copy, ground_Arr, endLine_Arr);
		upRoneCurve(makeBlock_Arr, caseNum);
		break;
	case oneCurve:
		caseNum = checkoneCurve(copy, ground_Arr, endLine_Arr);
		uponeCurve(makeBlock_Arr, caseNum);
		break;
	case fuckYou:
		caseNum = checkFuckYou(copy, ground_Arr, endLine_Arr);
		upfuckYou(makeBlock_Arr, caseNum);
		break;
	}
}

void KeyBoard::upStraight(int(*makeBlock_Arr)[4], int caseNum)
{
	if (caseNum == 0)
		return;
	else if (caseNum == 11) {
		makeBlock_Arr[0][0] = makeBlock_Arr[2][0] - 2;
		makeBlock_Arr[1][0] = makeBlock_Arr[2][0] - 1;
		makeBlock_Arr[3][0] = makeBlock_Arr[2][0] + 1;      // y축
		makeBlock_Arr[0][1] = makeBlock_Arr[1][1] = makeBlock_Arr[3][1] = makeBlock_Arr[2][1];   // x축
	}
	else if (caseNum == 21) {
		makeBlock_Arr[0][0] = makeBlock_Arr[1][0] = makeBlock_Arr[3][0] = makeBlock_Arr[2][0];   // y축
		makeBlock_Arr[0][1] = makeBlock_Arr[2][1] - 4;
		makeBlock_Arr[1][1] = makeBlock_Arr[2][1] - 2;
		makeBlock_Arr[3][1] = makeBlock_Arr[2][1] + 2;
	}
	else {
		;
	}
}

void KeyBoard::upRtwoCurve(int(*makeBlock_Arr)[4], int caseNum)
{
	if (caseNum == 0)
		return;
	else if (caseNum == 11) {
		makeBlock_Arr[2][0] = makeBlock_Arr[1][0] + 1;
		makeBlock_Arr[1][3] = makeBlock_Arr[2][3] = makeBlock_Arr[0][3];
		makeBlock_Arr[0][3] = makeBlock_Arr[1][1] = 0;
	}
	else if (caseNum == 21) {
		makeBlock_Arr[2][0] = 0;
		makeBlock_Arr[0][3] = makeBlock_Arr[1][3];
		makeBlock_Arr[1][1] = makeBlock_Arr[1][2] - 2;
		makeBlock_Arr[1][3] = makeBlock_Arr[2][3] = 0;
	}
	else {
		;
	}
}

void KeyBoard::uptwoCurve(int(*makeBlock_Arr)[4], int caseNum)
{
	if (caseNum == 0)
		return;
	else if (caseNum == 11) {
		makeBlock_Arr[2][0] = makeBlock_Arr[1][0] + 1;
		makeBlock_Arr[1][1] = makeBlock_Arr[2][1] = makeBlock_Arr[0][1];
		makeBlock_Arr[0][1] = makeBlock_Arr[1][3] = 0;
	}
	else if (caseNum == 21) {
		makeBlock_Arr[2][0] = 0;
		makeBlock_Arr[0][1] = makeBlock_Arr[1][1];
		makeBlock_Arr[1][3] = makeBlock_Arr[1][2] + 2;
		makeBlock_Arr[1][1] = makeBlock_Arr[2][1] = 0;
	}
	else {
		;
	}
}

void KeyBoard::upRoneCurve(int(*makeBlock_Arr)[4], int caseNum)
{
	if (caseNum == 0)
		return;
	else if (caseNum == 11) {
		makeBlock_Arr[2][0] = makeBlock_Arr[1][0] + 1;
		makeBlock_Arr[0][1] = makeBlock_Arr[2][1] = makeBlock_Arr[1][1];
		makeBlock_Arr[2][2] = makeBlock_Arr[1][2];
		makeBlock_Arr[1][2] = makeBlock_Arr[1][3] = makeBlock_Arr[0][3] = 0;
	}
	else if (caseNum == 21) {
		makeBlock_Arr[0][0] = makeBlock_Arr[1][0] - 1;
		makeBlock_Arr[0][1] = makeBlock_Arr[1][1];
		makeBlock_Arr[0][2] = makeBlock_Arr[2][2] = makeBlock_Arr[1][2];
		makeBlock_Arr[1][1] = makeBlock_Arr[2][1] = makeBlock_Arr[1][3] = 0;
	}
	else if (caseNum == 31) {
		makeBlock_Arr[0][0] = 0;
		makeBlock_Arr[1][2] = makeBlock_Arr[1][1] + 2;
		makeBlock_Arr[1][3] = makeBlock_Arr[1][2] + 2;
		makeBlock_Arr[0][1] = makeBlock_Arr[2][2] = 0;
	}
	else if (caseNum == 41) {
		makeBlock_Arr[2][0] = 0;
		makeBlock_Arr[1][1] = makeBlock_Arr[0][1];
		makeBlock_Arr[0][3] = makeBlock_Arr[1][3] = (makeBlock_Arr[0][2] + 2);
		makeBlock_Arr[0][1] = makeBlock_Arr[0][2] = makeBlock_Arr[2][2] = 0;
	}
	else {
		;
	}
}

void KeyBoard::uponeCurve(int(*makeBlock_Arr)[4], int caseNum)
{
	if (caseNum == 0)
		return;
	else if (caseNum == 11) {
		makeBlock_Arr[2][0] = makeBlock_Arr[1][0] + 1;
		makeBlock_Arr[0][2] = makeBlock_Arr[1][2];
		makeBlock_Arr[2][1] = makeBlock_Arr[1][1];
		makeBlock_Arr[1][2] = makeBlock_Arr[1][3] = 0;
	}
	else if (caseNum == 21) {
		makeBlock_Arr[0][0] = makeBlock_Arr[1][0] - 1;
		makeBlock_Arr[2][2] = makeBlock_Arr[0][2] = makeBlock_Arr[1][2];
		makeBlock_Arr[2][1] = makeBlock_Arr[1][1];
		makeBlock_Arr[1][1] = makeBlock_Arr[1][3] = makeBlock_Arr[2][3] = 0;
	}
	else if (caseNum == 31) {
		makeBlock_Arr[0][0] = 0;
		makeBlock_Arr[1][2] = makeBlock_Arr[0][2];
		makeBlock_Arr[1][3] = makeBlock_Arr[2][3] = (makeBlock_Arr[1][2] + 2);
		makeBlock_Arr[0][1] = makeBlock_Arr[0][2] = makeBlock_Arr[2][1] = 0;
	}
	else if (caseNum == 41) {
		makeBlock_Arr[2][0] = 0;
		makeBlock_Arr[0][1] = makeBlock_Arr[1][1] = makeBlock_Arr[2][1];
		makeBlock_Arr[1][3] = (makeBlock_Arr[1][2] + 2);
		makeBlock_Arr[0][2] = makeBlock_Arr[2][1] = makeBlock_Arr[2][2] = 0;
	}
	else {
		;
	}
}

void KeyBoard::upfuckYou(int(*makeBlock_Arr)[4], int caseNum)
{
	if (caseNum == 0)
		return;
	else if (caseNum == 11) {
		makeBlock_Arr[2][0] = makeBlock_Arr[1][0] + 1;
		makeBlock_Arr[2][2] = makeBlock_Arr[1][2];
		makeBlock_Arr[1][1] = 0;
	}
	else if (caseNum == 21) {
		makeBlock_Arr[0][0] = 0;
		makeBlock_Arr[1][1] = makeBlock_Arr[1][2] - 2;
		makeBlock_Arr[0][2] = 0;
	}
	else if (caseNum == 31) {
		makeBlock_Arr[0][0] = makeBlock_Arr[1][0] - 1;
		makeBlock_Arr[0][2] = makeBlock_Arr[1][2];
		makeBlock_Arr[1][3] = 0;
	}
	else if (caseNum == 41) {
		makeBlock_Arr[2][0] = 0;
		makeBlock_Arr[1][3] = makeBlock_Arr[1][2] + 2;
		makeBlock_Arr[2][2] = 0;
	}
	else {
		;
	}
}