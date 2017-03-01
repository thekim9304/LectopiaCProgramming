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
	
	void blockAutoDown(int(*makeBlock_Arr)[4], int(*ground_Arr)[22], int *endLine_Arr);
	void clearBlock(int(*makeBlock_Arr)[4]);
	void clearGround(int(*ground_Arr)[22]);
};

