#pragma once
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <time.h>

using namespace std;

class Tetris_Etc
{
private:
	const int endLine;
	const int endLeft;
	const int endRight;
	const int startLeft;
	const int startRight;
public:
	Tetris_Etc();
	virtual ~Tetris_Etc();

	const int getEndLine() const { return endLine; }
	const int getEndLeft() const { return endLeft; }
	const int getEndRight() const { return endRight; }
	const int getstartLeft() const { return startLeft; }
	const int getstartRight() const { return startRight; }

	void gotoxy(int x, int y);   //  커서 x,y 좌표로 이동
	int nowTime(); // 현재 시간 출력 

	enum blockNum { quadrangle, straight, RtwoCurve, twoCurve, RoneCurve, oneCurve, fuckYou };
};

