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
//   Person 구조체 보조 함수
//-------------------------------------
/*
int comparePersonName(DataType *p1, DataType *p2);  // Person 구조체의 name멤버로 비교하는 함수
int comparePersonAge(DataType *p1, DataType *p2);   // Person 구조체의 age멤버로 비교하는 함수
void printPerson(DataType *p);  // Person 구조체의 모든 멤버를 출력하는 함수 
*/

void personMemCpy(void *p1, void *p2);
void personClear(void *p);
void personPrint(void *p);
int personNameCompare(void *p1, void *p2);
int personCompare(void *p1, void *p2);