#include "MakeBlock.h"



MakeBlock::MakeBlock() : Tetris_Etc()
{
	if (endLine_Arr[0] == 0) {
		for (int i = 0; i < 24; i++) {
			endLine_Arr[i] = getEndLine();
		}
	}
}

MakeBlock::~MakeBlock()
{
}

int MakeBlock::makeBlock(int(*makeBlock_Arr)[4])
{
	int ret, i;

	srand((unsigned int)time(NULL));
	ret = random(7);

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			makeBlock_Arr[i][j] = tetBlock_Arr[ret][i][j];
		}
	}

	return ret;
}

int MakeBlock::random(int n)
{
	int ret;
	ret = rand() % n;
	return ret;
}

void MakeBlock::plusGround(int(*makeBlock_Arr)[4], int(*ground_Arr)[22], int *endLine_Arr)
{
	for (int i = 0; i < 4; i++) {
		if (makeBlock_Arr[i][0] != 0) {
			for (int j = 1; j < 4; j++) {
				if (makeBlock_Arr[i][j] != 0) {
					ground_Arr[makeBlock_Arr[i][j] - getstartLeft()][makeBlock_Arr[i][0]] = 1;
				}
			}
		}
	}

	plusEndline(ground_Arr, endLine_Arr);
}

void MakeBlock::plusEndline(int(*ground_Arr)[22], int *endLine_Arr)
{
	for (int i = 0; i < 24; i++) {
		endLine_Arr[i] = 22;
	}

	for (int i = 0; i < 24; i += 2) {
		for (int j = 0; j < 22; j++) {
			if (ground_Arr[i][j] != 0) {
				endLine_Arr[i] = j;
				break;
			}
		}
	}
}

bool MakeBlock::checkGround(int(*makeBlock_Arr)[4], int(*ground_Arr)[22], int *endline_Arr)
{
	if (checkEndline(makeBlock_Arr, endline_Arr) == true)
		return true;

	for (int i = 3; i >= 0; i--) {
		for (int j = 3; j > 0; j--) {
			if (ground_Arr[makeBlock_Arr[i][j] - getstartLeft()][makeBlock_Arr[i][0] + 1] != 0)
				return true;
		}
	}

	return false;
}

bool MakeBlock::checkEndline(int(*makeBlock_Arr)[4], int *endline_Arr)  // 다음이 endline이면 true
{
	for (int i = 3; i >= 0; i--) {
		if (makeBlock_Arr[i][0] != 0) {
			for (int j = 1; j < 4; j++) {
				if (makeBlock_Arr[i][j] != 0) {
					if ((makeBlock_Arr[i][0] + 1) == endline_Arr[makeBlock_Arr[i][j] - getstartLeft()])
						return true;
				}
			}
		}
	}

	return false;
}

int MakeBlock::checkStraight(int(*copy)[4], int(*ground_Arr)[22], int*endline_Arr) 
{
	int extrac_Coold_Left = getEndRight(), extrac_Coold_Right = getEndLeft();
	int ret;

	if (copy[0][0] == copy[1][0]) {
		copy[0][0] = copy[2][0] - 2;
		copy[1][0] = copy[2][0] - 1;
		copy[3][0] = copy[2][0] + 1;      // y축
		copy[0][1] = copy[1][1] = copy[3][1] = copy[2][1];   // x축
		
		if (ground_Arr[copy[3][1] - getstartLeft()][copy[3][0]] == 1)
			ret = 0;
		else if (copy[3][0] == getEndLine())
			ret = 0;    // 가로 1자에서 변환 실패
		else
			ret = 11;    // 가로 1자에서 변환 성공
	}
	else {
		copy[0][0] = copy[1][0] = copy[3][0] = copy[2][0];   // y축
		copy[0][1] = copy[2][1] - 4;
		copy[1][1] = copy[2][1] - 2;
		copy[3][1] = copy[2][1] + 2;

		if ((copy[0][1] == getEndLeft()) || (ground_Arr[copy[0][1] - getstartLeft()][copy[0][0]] == 1))
			ret = 0;
		else if ((copy[1][1] == getEndLeft()) || (ground_Arr[copy[1][1] - getstartLeft()][copy[1][0]] == 1))
			ret = 0;
		else if ((copy[3][1] == getEndRight()) || (ground_Arr[copy[3][1] - getstartLeft()][copy[3][0]] == 1))
			ret = 0;
		else
			ret = 21;
	}

	return ret;
}

int MakeBlock::checkRtwoCurve(int(*copy)[4], int(*ground_Arr)[22], int *endline_Arr)
{
	int ret;

	if (copy[1][3] == 0) {
		copy[2][0] = copy[1][0] + 1;
		copy[1][3] = copy[2][3] = copy[0][3];
		copy[0][3] = copy[1][1] = 0;

		if ((copy[2][0] == getEndLine()) || (ground_Arr[copy[2][3] - getstartLeft()][copy[2][0]] == 1))
			ret = 0;
		else if ((copy[1][0] == getEndLine()) || (ground_Arr[copy[1][3] - getstartLeft()][copy[1][0]] == 1))
			ret = 0;
		else
			ret = 11;
	}
	else {
		copy[2][0] = 0;
		copy[0][3] = copy[1][3];
		copy[1][1] = copy[1][2] - 2;
		copy[1][3] = copy[2][3] = 0;

		if ((copy[1][1] == getEndLeft()) || (ground_Arr[copy[1][1] - getstartLeft()][copy[1][0]] == 1))
			ret = 0;
		else if (ground_Arr[copy[0][3] - getstartLeft()][copy[0][0]] == 1)
			ret = 0;
		else
			ret = 21;
	}

	return ret;
}

int MakeBlock::checktwoCurve(int(*copy)[4], int(*ground_Arr)[22], int*endLine_Arr)
{
	int ret;

	if (copy[2][0] == 0) {
		copy[2][0] = copy[1][0] + 1;
		copy[1][1] = copy[2][1] = copy[0][1];
		copy[0][1] = copy[1][3] = 0;

		if (copy[1][1] == getEndLeft() || (ground_Arr[copy[1][1] - getstartLeft()][copy[1][1]] == 1))
			ret = 0;
		else if ((copy[2][0] == getEndLine()) || (ground_Arr[copy[2][1] - getstartLeft()][copy[2][1]] == 1))
			ret = 0;
		else
			ret = 11;
	}
	else {
		copy[2][0] = 0;
		copy[0][1] = copy[1][1];
		copy[1][3] = copy[1][2] + 2;
		copy[1][1] = copy[2][1] = 0;

		if ((copy[1][3] == getEndRight()) || (ground_Arr[copy[1][3] - getstartLeft()][copy[1][3]] == 1))
			ret = 0;
		else if (ground_Arr[copy[0][1] - getstartLeft()][copy[0][1]] == 1)
			ret = 0;
		else
			ret = 21;
	}

	return ret;
}

int MakeBlock::checkRoneCurve(int(*copy)[4], int(*ground_Arr)[22], int *endLine_Arr)
{
	int ret;

	if (copy[2][2] == 0) {
		if (copy[2][0] == 0) {
			copy[2][0] = copy[1][0] + 1;
			copy[0][1] = copy[2][1] = copy[1][1];
			copy[2][2] = copy[1][2];
			copy[1][2] = copy[1][3] = copy[0][3] = 0;

			if ((copy[2][0] == getEndLine()) || (ground_Arr[copy[2][1] - getstartLeft()][copy[2][0]] == 1))
				ret = 0;
			else if ((copy[2][0] == getEndLine()) || (ground_Arr[copy[2][2] - getstartLeft()][copy[2][0]] == 1))
				ret = 0;
			else if (ground_Arr[copy[0][1] - getstartLeft()][copy[0][0]] == 1)
				ret = 0;
			else
				ret = 11;
		}
		else {
			copy[0][0] = copy[1][0] - 1;
			copy[0][1] = copy[1][1];
			copy[0][2] = copy[2][2] = copy[1][2];
			copy[1][1] = copy[2][1] = copy[1][3] = 0;

			if ((ground_Arr[copy[0][1] - getstartLeft()][copy[0][0]] == 1) || ground_Arr[copy[0][2] - getstartLeft()][copy[0][0]] == 1)
				ret = 0;
			else if (ground_Arr[copy[2][2] - getstartLeft()][copy[2][0]] == 1)
				ret = 0;
			else
				ret = 21;
		}
	}
	else {
		if (copy[0][2] == 0) {
			copy[0][0] = 0;
			copy[1][2] = copy[1][1] + 2;
			copy[1][3] = copy[1][2] + 2;
			copy[0][1] = copy[2][2] = 0;

			if (ground_Arr[copy[1][2] - getstartLeft()][copy[1][0]] == 1)
				ret = 0;
			else if ((copy[1][3] == getEndRight()) || (ground_Arr[copy[1][3] - getstartLeft()][copy[1][0]] == 1))
				ret = 0;
			else
				ret = 31;
		}
		else {
			copy[2][0] = 0;
			copy[1][1] = copy[0][1];
			copy[0][3] = copy[1][3] = (copy[0][2] + 2);
			copy[0][1] = copy[0][2] = copy[2][2] = 0;

			if (ground_Arr[copy[1][1] - getstartLeft()][copy[1][0]] == 1)
				ret = 0;
			else if ((copy[0][3] == getEndRight()) || (ground_Arr[copy[0][3] - getstartLeft()][copy[0][0]] == 1))
				ret = 0;
			else if ((ground_Arr[copy[1][3] - getstartLeft()][copy[1][0]] == 1))
				ret = 0;
			else
				ret = 41;
		}
	}

	return ret;
}

int MakeBlock::checkoneCurve(int(*copy)[4], int(*ground_Arr)[22], int*endLine_Arr)
{
	int ret;

	if (copy[2][1] == 0) {
		if (copy[0][0] != 0) {
			copy[2][0] = copy[1][0] + 1;
			copy[0][2] = copy[1][2];
			copy[2][1] = copy[1][1];
			copy[1][2] = copy[1][3] = 0;

			if (ground_Arr[copy[0][2] - getstartLeft()][copy[0][0]] == 1)
				ret = 0;
			else if ((copy[2][0] == getEndLine()) || (ground_Arr[copy[2][1] - getstartLeft()][copy[2][0]] == 1))
				ret = 0;
			else
				ret = 11;
		}
		else {
			copy[0][0] = copy[1][0] - 1;
			copy[2][2] = copy[0][2] = copy[1][2];
			copy[2][1] = copy[1][1];
			copy[1][1] = copy[1][3] = copy[2][3] = 0;

			if (ground_Arr[copy[0][2] - getstartLeft()][copy[0][0]] == 1)
				ret = 0;
			else if (copy[2][0] == getEndLine())
				ret = 0;
			else if (ground_Arr[copy[2][1] - getstartLeft()][copy[2][0]] == 1)
				ret = 0;
			else if (ground_Arr[copy[2][2] - getstartLeft()][copy[2][0]] == 1)
				ret = 0;
			else
				ret = 21;
		}
	}
	else {
		if (copy[0][1] != 0) {
			copy[0][0] = 0;
			copy[1][2] = copy[0][2];
			copy[1][3] = copy[2][3] = (copy[1][2] + 2);
			copy[0][1] = copy[0][2] = copy[2][1] = 0;

			if (ground_Arr[copy[1][2] - getstartLeft()][copy[1][0]] == 1)
				ret = 0;
			else if ((copy[1][3] == getEndRight()) || (ground_Arr[copy[1][3] - getstartLeft()][copy[1][0]] == 1))
				ret = 0;
			else if (ground_Arr[copy[2][3] - getstartLeft()][copy[2][0]] == 1)
				ret = 0;
			else
				ret = 31;
		}
		else {
			copy[2][0] = 0;
			copy[0][1] = copy[1][1] = copy[2][1];
			copy[1][3] = (copy[1][2] + 2);
			copy[0][2] = copy[2][1] = copy[2][2] = 0;

			if ((copy[1][3] == getEndRight()) || (ground_Arr[copy[1][3] - getstartLeft()][copy[1][0]] == 1))
				ret = 0;
			else if (ground_Arr[copy[0][1] - getstartLeft()][copy[0][0]] == 1)
				ret = 0;
			else if (ground_Arr[copy[1][1] - getstartLeft()][copy[1][0]] == 1)
				ret = 0;
			else
				ret = 41;
		}
	}

	return ret;
}

int MakeBlock::checkFuckYou(int(*copy)[4], int(*ground_Arr)[22], int * endLine_Arr)
{
	int ret;

	if (copy[2][2] == 0) {
		copy[2][0] = copy[1][0] + 1;
		copy[2][2] = copy[1][2];
		copy[1][1] = 0;

		if ((copy[2][2] == getEndLine()) || (ground_Arr[copy[2][2] - getstartLeft()][copy[2][0]] == 1))
			ret = 0;
		else
			ret = 11;
	}
	else if (copy[1][1] == 0) {
		copy[0][0] = 0;
		copy[1][1] = copy[1][2] - 2;
		copy[0][2] = 0;

		if ((copy[1][1] == getEndLeft()) || (ground_Arr[copy[1][1] - getstartLeft()][copy[1][0]] == 1))
			ret = 0;
		else
			ret = 21;
	}
	else if (copy[0][2] == 0) {
		copy[0][0] = copy[1][0] - 1;
		copy[0][2] = copy[1][2];
		copy[1][3] = 0;

		if (ground_Arr[copy[0][2] - getstartLeft()][copy[0][0]] == 1)
			ret = 0;
		else
			ret = 31;
	}
	else if (copy[1][3] == 0) {
		copy[2][0] = 0;
		copy[1][3] = copy[1][2] + 2;
		copy[2][2] = 0;

		if ((copy[1][3] == getEndRight()) || (ground_Arr[copy[1][3] - getstartLeft()][copy[1][0]] == 1))
			ret = 0;
		else
			ret = 41;
	}

	return ret;
}