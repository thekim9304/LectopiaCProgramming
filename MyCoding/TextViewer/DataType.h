#pragma once
typedef struct _line
{
	char word[81];
	int lineNumber;
}Line;

typedef  Line DataType;     // ��峻�� ������ ������ ���� ������ 

//-------------------------------------
//   Person ����ü ���� �Լ�
//-------------------------------------
int compareWord(DataType *p1, DataType *p2);  // Person ����ü�� name����� ���ϴ� �Լ�
void printWord(DataType *p);  // Person ����ü�� ��� ����� ����ϴ� �Լ� 
