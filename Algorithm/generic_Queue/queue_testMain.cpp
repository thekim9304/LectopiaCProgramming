#include "queue.h" 
#include <stdio.h> 
int menu(char **, int); 
void myFlush(); 
void input(Queue *); 
void myDelete(Queue *); 
//--------------------------------------------------------------------------------
//   main() 
//--------------------------------------------------------------------------------
int main() 
{ 
	Queue que; /* 큐생성*/ 
	char *menuList[] = { "입력하기", "삭제하기", "출력하기", "종료"}; /* 메뉴리스트*/ 
	int menuCnt; /* 메뉴개수 저장 변수*/ 
	int menuNum; /* 메뉴번호 저장 변수*/

	initQueue(&que, 5, sizeof(Person)); /* 크기가 5인 큐 생성 및 초기화*/ 

	menuCnt = sizeof(menuList)/sizeof(menuList[0]); /* 메뉴 개수 계산 하기*/ 
	while(1) 
	{ 
		menuNum = menu(menuList, menuCnt); 
		if(menuNum == menuCnt) /* 종료메뉴 선택 시 반복문 탈출 하기*/ 
		{ 
			break; 
		} 
		switch(menuNum) 
		{ 
		case 1 : input(&que); break; 
		case 2 : myDelete(&que); break; 
		case 3 : printQueue(&que, sizeof(Person), personPrint); /* queue내의 모든 데이터 출력 하기*/ 
		} 
	} 
	destroyQueue(&que, sizeof(Person), personClear); 
	return 0; 
} 
/*-------------------------------------------------------------------------------------------------------- 
함수명및기능: input() - 큐에 데이터를 반복적으로 입력 함 
전달인자: qPtr - 큐의 주소 
리턴값: 없음 
----------------------------------------------------------------------------------------------------------*/ 
void input(Queue *qPtr)
{
	Person in;
	char name[20];

	in.name = (char*)calloc(20, sizeof(char));

	while (1) {
		printf("이름을 입력 하시오(끝 입력시 종료) : ");
		scanf("%s", name);
		if (strcmp(name, "끝") == 0) // "끝"입력시 종료
			break;

		myFlush();

		strcpy(in.name, name);

		printf("나이를 입력 하시오 : ");
		scanf("%d", &in.age);
		printf("전화번호를 입력 하시오 : ");
		scanf("%s", in.phoneNumber);

		if (!put(qPtr, &in, sizeof(Person), personMemCpy))
			printf("put(enqueue) 실패!!\n");
	}

	free(in.name);
}

/*------------------------------------------------------------------------------------------------------------ 
함수명 및 기능: myDelete() - 큐에 데이터를 반복적으로 꺼냄 
전달인자: qPtr - 큐의 주소 
리턴값: 없음 
------------------------------------------------------------------------------------------------------------*/ 
void myDelete(Queue *qPtr) 
{ 
	int getCnt, i;
	void *getP;

	getP = calloc(1, sizeof(Person));

	printf("Queue에서 데이터를 get할 회수를 입력하시오 : ");
	scanf("%d", &getCnt);

	for (i = 0; i < getCnt; i++) {
		if ((get(qPtr, getP, sizeof(Person), personMemCpy, personClear) == 1))
			personPrint(getP);
		else
			printf("get 실패! \n");
	}

	free(getP);
} 
/*------------------------------------------------------------------------------------------------------------ 
함수명 및 기능: menu() - 메뉴를 출력하고 메뉴번호를 입력 받아 리턴 함 
전달인자: menuLIst - 메뉴 출력할 문자열 
          menuCnt - 메뉴 개수 
리턴값: 선택된 메뉴번호 
------------------------------------------------------------------------------------------------------------*/ 
int menu(char **menuList, int menuCnt) 
{ 
	int i; 
	int menuNum=0; /* 입력된 메뉴번호 저장 변수*/ 
	int res; /* scanf()함수의 리턴값 저장 변수*/ 
	for(i=0; i<menuCnt; i++) 
	{ 
		printf("%d. %s\n", i+1, menuList[i]); 
	} 
	while(menuNum<1 || menuNum>menuCnt) /* 메뉴번호 범위의 번호가 입력시 까지 반복*/ 
	{ 
		printf("# 메뉴번호를 입력하세요 : "); 
		res = scanf("%d", &menuNum); 
		if(res!=1) /* 정수가 입력되지 않았으면*/ 
		{ 
			myFlush(); /* 입력버퍼 비우기*/ 
			continue; 
		} 
	} 
	return menuNum; 
} 

/*------------------------------------------------------------------------------------------------------------ 
함수명 및 기능: myFlush() - 입력버퍼 지우기 
전달인자: 없음 
리턴값: 없음 
------------------------------------------------------------------------------------------------------------*/ 
void myFlush() 
{ 
	while(getchar()!='\n') 
	{ ; } 
} 