#pragma once
typedef struct _line
{
	char word[81];
	int lineNumber;
}Line;

typedef  Line DataType;     // 노드내의 데이터 영역의 형명 재지정 

//-------------------------------------
//   Person 구조체 보조 함수
//-------------------------------------
int compareWord(DataType *p1, DataType *p2);  // Person 구조체의 name멤버로 비교하는 함수
void printWord(DataType *p);  // Person 구조체의 모든 멤버를 출력하는 함수 
