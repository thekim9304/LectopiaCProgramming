#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include "doublelinkedlist.h"

int menu(char **mList, size_t menuCnt);
void dataFileLoad(LinkedList *lp); // 데이터 파일내의 데이터를 리스트에 저장 
void dataFileSave(LinkedList *lp); // 리스트내의 모든 데이터를 파일에 저장 
void mInput(LinkedList *lp);       // 입력메뉴 처리 함수
void mSearch(LinkedList *lp);      // 단일검색메뉴 처리 함수
void mDupSearch(LinkedList *lp);   // 다중검색메뉴 처리 함수
void mDelete(LinkedList *lp);      // 삭제메뉴 처리 함수
/*----------------------------------------------------------------------------------
  함수명 : main() 
----------------------------------------------------------------------------------*/
int main()
{
	char *menuList[] = {"입력하기","출력하기","단일검색하기","다중검색하기", "삭제하기", "성명순 정렬하기", "나이순 정렬하기","종  료"};
	int menuNum;    //메뉴번호 저장 변수
	int menuCnt;    //메뉴개수 저장 변수
	LinkedList list;  //리스트관리 구조체 변수
	Person a;

	menuCnt = sizeof(menuList)/sizeof(menuList[0]);

	create(&list);      // 비어있는 리스트 생성 및 초기화
	dataFileLoad(&list); // 데이터 파일내의 데이터를 리스트에 저장 
	while(1)    
	{
		      // 비어있는 리스트 생성 및 초기화

		menuNum = menu(menuList, menuCnt); //메뉴화면을 띄우고 메뉴번호를 입력 받음
		if(menuNum==menuCnt) { break; }
		switch(menuNum)
		{
		case 1 : mInput(&list); break;               // 입력메뉴 실행
		case 2 : display(&list, printPerson);  break; // 출력메뉴 실행
		case 3 : mSearch(&list); break;              // 단일검색메뉴 실행
		case 4 : mDupSearch(&list); break;           // 다중검색메뉴 실행
		case 5 : mDelete(&list); break;              // 삭제메뉴 실행
		case 6: sortList(&list, sizeof(a), personNameCompare, personMemCpy, personClear); break; // 성명순 정렬메뉴 실행
		case 7 : sortList(&list, sizeof(a), personAgeCompare, personMemCpy, personClear); break;  // 나이순 정렬메뉴 실행
		}
	}
	//dataFileSave(&list); // 리스트내의 모든 데이터를 파일에 저장 
	destroy(&list, personClear); 
	
	return 0;
}
/*----------------------------------------------------------------------------------
  함수명 : menu()
----------------------------------------------------------------------------------*/
int menu(char **mList, size_t menuCnt)
{
	size_t menuNum=0;  // 존재하지 않는 메뉴 번호 저장 
	size_t i;

	printf("\n\n");
	for(i=0; i<menuCnt; i++)  // 메뉴 출력
	{
		printf("%d. %s\n", i+1, mList[i]);
	}

	while(menuNum<1 || menuNum>menuCnt) // 메뉴번호가 유효하지 않을 동안 반복
	{
		printf("# 메뉴 선택 : ");
		scanf("%d", &menuNum);  // 메뉴 번호 입력
	}
	return menuNum;
}
/*----------------------------------------------------------------------------------
  함수명 : mInput()
----------------------------------------------------------------------------------*/
void mInput(LinkedList *lp)
{
	Person inData;
	char name[20], phone[16];
	inData.name = (char*)calloc(1, sizeof(char) * 20);

	printf("\n[ 입력하기 메뉴 ]\n\n");
	while(1)
	{
		printf("# 이름을 입력하세요(끝 입력시 종료) : ");
		scanf("%s", name);
		if(strcmp(name,"끝")==0) // "끝"입력시 종료
			break;

		strcpy(inData.name, name);

		printf("# 나이을 입력하세요 : ");
		scanf("%d", &inData.age);

		printf("# 핸드폰 번호를 입력하세요 : ");
		scanf("%s", inData.phoneNumber);
		
		// tail 노드 앞에 데이터 추가 
		appendFromHead(lp, &inData, sizeof(inData), personMemCpy); 
	}
	return;
}
/*----------------------------------------------------------------------------------
  함수명 : mSearch()
----------------------------------------------------------------------------------*/
void mSearch(LinkedList * lp)
{
	Person sData;
	Node *resp;
	char name[20];

	sData.name = (char*)calloc(1, sizeof(char) * 20);

	printf("\n[ 검색하기 메뉴 ]\n\n");
	while(1)
	{
		printf("# 찾는 이름을 입력하세요(끝 입력시 종료) : ");
		scanf("%s", name);
		if(strcmp(name,"끝")==0) // "끝"입력시 종료
			break; 

		strcpy(sData.name, name);

		resp = linearSearchUnique(lp, &sData, personNameCompare);
		if(resp!=NULL) //데이터를 찾았으면
		{
			printf("@ 데이터가 존재합니다 : ");
			printPerson(resp + 1);
		}
		else //데이터를 못찾았으면
		{
			printf("@ 해당 데이터가 존재하지 않습니다.\n\n");
		}
	}

	free(sData.name);
	return ;
}
/*----------------------------------------------------------------------------------
  함수명 : mDelete()
----------------------------------------------------------------------------------*/
void mDelete(LinkedList * lp)
{
	Person dData;
	Node *resp; // 삭제할 노드의 주소 저장 변수
	char name[20];

	dData.name = (char*)calloc(1, sizeof(char) * 20);

	printf("\n[ 삭제하기 메뉴] \n\n");
	while(1)
	{
		printf("# 찾는 이름을 입력하세요(끝 입력시 종료) : ");
		scanf("%s", name);
		if (strcmp(name, "끝") == 0) // "끝"입력시 종료
			break;

		strcpy(dData.name, name);

		resp = linearSearchUnique(lp, &dData, personNameCompare);
		if(resp!=NULL) // 찾았으면
		{	
			deleteNode(lp, resp, personClear); //해당 노드를 지움
			printf("@ 삭제하였습니다.\n\n");
		}
		else //데이터가 없으면
		{
			printf("@ 해당 데이터가 존재하지 않습니다.\n\n");
		}
	}

	free(dData.name);

	return ;
}
/*----------------------------------------------------------------------------------
  함수명 : mDupSearch()
----------------------------------------------------------------------------------*/
void mDupSearch(LinkedList * lp)
{
	Node **searchPtr; // 찾은 노드의 주소들을 저장할 배열의 시작주소를 가리킬 포인터
	int searchCnt, i;    // 찾은 노드의 수
	Person sData;
	char name[20];

	sData.name = (char*)calloc(1, sizeof(char) * 20);

	printf("\n[ 다중 검색하기 메뉴 ]\n\n");
	while(1)
	{
		printf("# 찾는 이름을 입력하세요(끝 입력시 종료) : ");
		scanf("%s", name);
		if (strcmp(name, "끝") == 0) // "끝"입력시 종료
			break;

		strcpy(sData.name, name);
		searchPtr = linearSearchDuplicate(lp, &sData, &searchCnt, personNameCompare);

		if(searchPtr!=NULL) //데이터를 찾았으면
		{
			printf("@ 데이터가 %d건 존재합니다.\n", searchCnt);
			for(i=0; i<searchCnt; i++) // 찾은 노드수 만큼 데이터 출력하기
			{
				printf("%d. ", i + 1);  
				printPerson(searchPtr[i] + 1);
			}
			free(searchPtr);  // 찾은노드의 주소를 담고 있는 Node *배열 메모리 해제
		}
		else //데이터를 못찾았으면
		{
			printf("@ 해당 데이터가 존재하지 않습니다.\n\n");
		}
	}

	free(sData.name);
	return ;
}
/*----------------------------------------------------------------------------------
  함수명 : dataFileLoad()
----------------------------------------------------------------------------------*/
void dataFileLoad(LinkedList *lp) // 데이터 파일내의 데이터를 리스트에 저장 
{
	FILE *fp;
	fp=fopen("c:\\data\\ListData.txt", "rt");
	assert(fp!=NULL);
	Person inData;
	char name[20];   // 성명 저장
	
	while(fscanf(fp, "%s", name)!=EOF)
	{
		fscanf(fp, "%d", &inData.age);
		strcpy(inData.name, name);
		appendFromTail(lp, &inData, sizeof(inData), personMemCpy);
	}
	fclose(fp);
}
/*----------------------------------------------------------------------------------
  함수명 : dataFileSave()
----------------------------------------------------------------------------------*/
void dataFileSave(LinkedList *lp) // 리스트내의 모든 데이터를 파일에 저장 
{
	FILE *fp;
	fp=fopen(":\\data\\ListData.txt", "wt");
	assert(fp!=NULL);
	
	lp->cur = lp->head->next;
	while(lp->cur != lp->tail)
	{
		//fprintf(fp, "%s %d\n", lp->cur->data.name, lp->cur->data.age);
		lp->cur = lp->cur->next;
	}
	fclose(fp);
}
//-------------------------------------
//   Person 구조체 보조 함수
//-------------------------------------
int comparePersonName(void *p1, void *p2) // Person 구조체의 name멤버로 비교하는 함수
{
	return ( strcmp(((Person*)p1)->name, ((Person*)p2)->name) );  // strcmp()함수의 리턴값을 바로 리턴
}
int comparePersonAge(void *p1, void *p2) // Person 구조체의 age멤버로 비교하는 함수
{
	if(((Person*)p1)->age > ((Person*)p2)->age) return 1;
	else if(((Person*)p1)->age == ((Person*)p2)->age) return 0;
	else return -1;
}
