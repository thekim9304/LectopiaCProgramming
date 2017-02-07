#pragma once

#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<assert.h>

typedef struct _person
{
	char *name;
	int age;
	char phoneNumber[16];
}Person;

//-------------------------------------
//   Person 구조체 보조 함수
//-------------------------------------
/*
int comparePersonName(DataType *p1, DataType *p2);  // Person 구조체의 name멤버로 비교하는 함수
int comparePersonAge(DataType *p1, DataType *p2);   // Person 구조체의 age멤버로 비교하는 함수
void printPerson(DataType *p);  // Person 구조체의 모든 멤버를 출력하는 함수 
*/
void printPerson(void *p);

void personMemCpy(void *p1, void *p2);
void personClear(void *p);
void personPrint(void *p);
int personNameCompare(void *p1, void *p2);
int personAgeCompare(void *p1, void *p2);
int personCompare(void *p1, void *p2);