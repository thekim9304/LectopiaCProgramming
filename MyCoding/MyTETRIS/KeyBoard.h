#pragma once
#include "ViewGround.h"

const int COMMON_KEY = 1;
const int SPECIAL_KEY = 0;
const int UP_ARROW = 72;
const int DOWN_ARROW = 80;
const int LEFT_ARROW = 75;
const int RIGHT_ARROW = 77;
const int SPACE_BAR = 32;

class KeyBoard : public ViewGround
{
public:
	KeyBoard();
	~KeyBoard();

	char getKey();
	char inKey(int *keyFlag);

	void directionKey(int (*)[4], int(*)[22], int *, int blockNum);
	void upArrow(int(*)[4], int blockNum);
	void downArrow(int(*)[4], int(*)[22], int *, int blockNum);
	void leftArrow(int(*)[4], int(*)[22], int *);
	void rightArrow(int(*)[4], int *);
	void spaceBar(int(*makeBlock_Arr)[4], int*, int);

	void upStraight(int(*makeBlock_Arr)[4], int caseNum);
	void upRtwoCurve(int(*makeBlock_Arr)[4], int caseNum);
	void uptwoCurve(int(*makeBlock_Arr)[4], int caseNum);
	void upRoneCurve(int(*makeBlock_Arr)[4], int caseNum);
	void uponeCurve(int(*makeBlock_Arr)[4], int caseNum);
	void upfuckYou(int(*makeBlock_Arr)[4], int caseNum);
};

