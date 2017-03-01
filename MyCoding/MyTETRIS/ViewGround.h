#pragma once
#include "MakeBlock.h"

class ViewGround :
	public MakeBlock
{
public:
	ViewGround();
	~ViewGround();

	void viewBlock(const int(*makeBlock_Arr)[4]);
	void viewGround(const int(*ground_Arr)[22]);
	
	void blockAutoDown(int(*makeBlock_Arr)[4], int(*ground_Arr)[22], int *endLine_Arr, int(*)[4]);
	void clearBlock(int(*makeBlock_Arr)[4]);
	void clearGround(int(*ground_Arr)[22]);

	void ViewGround::viewPredict(int(*makeBlock)[4], int(*view)[4], int *endLine_arr);
	void ViewGround::clearPredict(int(*view)[4]);
};

