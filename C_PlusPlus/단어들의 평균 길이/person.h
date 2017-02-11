#pragma once

#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<assert.h>

typedef struct _word
{
	char *wp;
	int length;
	int count;
}Word;

//-------------------------------------
//   Person ����ü ���� �Լ�
//-------------------------------------
/*
int comparePersonName(DataType *p1, DataType *p2);  // Person ����ü�� name����� ���ϴ� �Լ�
int comparePersonAge(DataType *p1, DataType *p2);   // Person ����ü�� age����� ���ϴ� �Լ�
void printPerson(DataType *p);  // Person ����ü�� ��� ����� ����ϴ� �Լ� 
*/

void personMemCpy(void *p1, void *p2);
void personClear(void *p);
void personPrint(void *p);
int personNameCompare(void *p1, void *p2);
int personCompare(void *p1, void *p2);