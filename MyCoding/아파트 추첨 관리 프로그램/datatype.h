#pragma once

typedef  struct _information DataType;     // 노드내의 데이터 영역의 형명 재지정 

struct _information
{
	char name[20];
	char phone[20];
	int since;
};

int exchangeInt(char *, int); // 문자열로 받은 생년원일 정수로 변경
int tenCalcu(int);  // 10의 n승
void printWinner(DataType *); // Queue Data 출력
int random(int ); // 추첨값 생성