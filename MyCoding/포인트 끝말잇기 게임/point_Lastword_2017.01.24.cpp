#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <malloc.h>
#include "doublelinkedlist.h"

void dataFileLoad(LinkedList *lp); // 데이터 파일내의 데이터를 리스트에 저장 
void wInput(LinkedList *, LinkedList *lp, int*);  // 단어 입력 처리 함수
void mSearch(LinkedList *lp, DataType *word);      // 단일검색메뉴 처리 함수
int lastWordCheck(LinkedList *word, DataType *inData, int*);
void firstInput(LinkedList *word, DataType *first);

int main()
{
	LinkedList list;  //리스트관리 구조체 변수
	LinkedList word;
	DataType first;
	int round = 1;

	create(&list);      // 비어있는 리스트 생성 및 초기화
	dataFileLoad(&list); // 데이터 파일내의 데이터를 리스트에 저장 
	sortList(&list, compareWord);

	create(&word);
	strcpy(first.word, "pointer");
	firstInput(&word, &first);
	
	while (1)
	{
		if (list.head->next == list.tail)
			break;

		printf("* 포인트 단어 : ");
		display(&list, printWord);
		printf("\n");
	
		printf("* 사용자 입력 단어 : ");
		display(&word, printWord);

		wInput(&list, &word, &round);

		round++;
	}

	printf("\n** 포인트 단어를 모두 맞췄습니다. 게임을 종료합니다.\n");
	
	destroy(&list);
	destroy(&word);
}

void firstInput(LinkedList *word, DataType *first)
{
	makeNode(first, word->tail->prev, word->tail);
}
/*----------------------------------------------------------------------------------
함수명 : mInput()
----------------------------------------------------------------------------------*/
void wInput(LinkedList *list, LinkedList *word, int *round)
{
	DataType inData;
	int ret = 0;

	while (1)
	{
		printf("\n# 끝말잇기 단어 입력(%d회차) : ", *round);
		scanf("%s", inData.word);

		printf("\n");

		ret = lastWordCheck(word, &inData, round);

		if (ret == 1)
		{
			printf("잘못 입력하셨습니다.\n");
			(*round)--;
		}
		else
		{
			word->cur = appendFromTail(word, &inData);
			mSearch(list, &inData);
		}

		break;
	}
}

int lastWordCheck(LinkedList *word, DataType *inData, int *round)
{
	Node *t;
	int length1, length2;

	t = word->tail;

	length1 = strlen(t->prev->data.word);
	length2 = strlen(inData->word);

	if (t->prev->data.word[length1 - 1] == inData->word[0])
		return 0;
	else
	{
		return 1;
		(*round)--;
	}
}
/*----------------------------------------------------------------------------------
함수명 : mSearch()
----------------------------------------------------------------------------------*/
void mSearch(LinkedList * lp, DataType * word)
{
	Node *resp;

	resp = searchUnique(lp, word, compareWord);
	if (resp != NULL) //데이터를 찾았으면
	{
		//->cur = (Node*)malloc(sizeof(Node));
		//assert(word->cur != NULL);
		/*
		word->cur->prev = word->tail->prev;
		word->cur->next = word->tail;
		word->tail->prev->next = word->cur;
		word->tail->prev = word->cur;
		word->cur->data = resp->data;
		*/
		resp->next->prev = resp->prev;
		resp->prev->next = resp->next;
		
		free(resp);
	}

	return;
}
/*----------------------------------------------------------------------------------
함수명 : dataFileLoad()
----------------------------------------------------------------------------------*/
void dataFileLoad(LinkedList *lp) // 데이터 파일내의 데이터를 리스트에 저장 
{
	FILE *fp;
	fp = fopen("c:\\data\\pointWord.txt", "rt");
	assert(fp != NULL);
	DataType inData;
	char name[20];   // 성명 저장

	while (fscanf(fp, "%s", name) != EOF)
	{
		strcpy(inData.word, name);
		appendFromTail(lp, &inData);
	}
	fclose(fp);
}
//-------------------------------------
//   word 구조체 보조 함수
//-------------------------------------
int compareWord(DataType *p1, DataType *p2) // Person 구조체의 name멤버로 비교하는 함수
{
	return (strcmp(p1->word, p2->word));  // strcmp()함수의 리턴값을 바로 리턴
}

void printWord(DataType *p)  // Person 구조체의 모든 멤버를 출력하는 함수 
{
	printf(" %s /", p->word);
}