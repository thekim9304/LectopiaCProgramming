#pragma once
#include "Tetris_Etc.h"
class MakeBlock : public Tetris_Etc
{
private:

public:
	MakeBlock();
	~MakeBlock();

	static int tetBlock_Arr[7][4][4];
	static int ground_Arr[24][22];    // x, y
	static int endLine_Arr[24];
	static int makeBlock_Arr[4][4];

	int makeBlock(int(*makeBlock_Arr)[4]);
	int random(int n);

	void plusGround(int(*makeBlock_Arr)[4], int(*ground_Arr)[22], int *endLine_Arr);
	void plusEndline(int (*ground_Arr)[22], int *endLine_Arr);
	bool checkEndline(int(*)[4], int*);
	bool checkGround(int(*makeBlock_Arr)[4], int(*ground_Arr)[22], int*);


	int checkStraight(int(*copy)[4], int(*ground_Arr)[22], int *endLine_Arr);
	int checkRtwoCurve(int(*copy)[4], int(*ground_Arr)[22], int *endLine_Arr);
	int checktwoCurve(int(*copy)[4], int(*ground_Arr)[22], int *endLine_Arr);
	int checkRoneCurve(int(*copy)[4], int(*ground_Arr)[22], int *endLine_Arr);
	int checkoneCurve(int(*copy)[4], int(*ground_Arr)[22], int *endLine_Arr);
	int checkFuckYou(int(*copy)[4], int(*ground_Arr)[22], int *endLine_Arr);

	void extractionCooldinate(int (*copy)[4], int &extrac_Coold_Left, int &extrac_Coold_Right);
};

