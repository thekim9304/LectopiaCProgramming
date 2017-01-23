#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include "doublelinkedlist.h"
/*--------------------------------------------------------------------------------------
함수명 및 기능: create() - 링크드리스트 초기화
전달인자:  lp - 링크드리스트 정보 구조체의 주소
리턴값: 없음
--------------------------------------------------------------------------------------*/
void create(LinkedList * lp)
{
	lp->head = (Node*)malloc(sizeof(Node));
	assert(lp->head != NULL);
	lp->tail = (Node*)malloc(sizeof(Node));
	assert(lp->tail != NULL);

	lp->head->next = lp->tail;
	lp->tail->prev = lp->head;

	lp->head->prev = lp->head;
	lp->tail->next = lp->tail;

	lp->cur = NULL;
	lp->length = 0;

	return ;
}
/*--------------------------------------------------------------------------------------
함수명 및 기능: makeNode() - 새 노드 생성 함수
전달인자:  dataPtr - 새 노드에 저장할 데이터 영역의 주소
prev - 새 노드의 앞 노드의 주소
next - 새 노드의 뒷 노드의 주소
리턴값: 생성된 노드의 주소
--------------------------------------------------------------------------------------*/
Node * makeNode(DataType *dataPtr, Node *prev, Node *next)
{


	return NULL;
}
/*--------------------------------------------------------------------------------------
함수명 및 기능: appendFromHead() - 헤드노드 뒤에 새 노드 추가(역순 저장)
전달인자: lp - 링크드리스트 정보 구조체의 주소
dataPtr - 새 노드에 저장할 데이터 영역의 주소
리턴값: 추가한 노드의 주소
--------------------------------------------------------------------------------------*/
Node * appendFromHead(LinkedList *lp, DataType *dataPtr)  
{
	lp->cur = (Node*)malloc(sizeof(Node));
	assert(lp->cur != NULL);

	lp->cur->next = lp->head->next;
	lp->cur->prev = lp->head;

	lp->head->next->prev = lp->cur;
	lp->head->next = lp->cur;

	lp->cur->data = *dataPtr;

	lp->length++;

	return lp->cur;
}
/*--------------------------------------------------------------------------------------
함수명 및 기능: appendFromTail() - 테일노드 앞에 새 노드 추가(정순 저장)
전달인자: lp - 링크드리스트 정보 구조체의 주소
dataPtr - 새 노드에 저장할 데이터 영역의 주소
리턴값: 추가한 노드의 주소
--------------------------------------------------------------------------------------*/
Node * appendFromTail(LinkedList *lp, DataType *dataPtr) 
{
	lp->cur = (Node*)malloc(sizeof(Node));
	assert(lp->cur != NULL);

	lp->cur->prev = lp->tail->prev;
	lp->cur->next = lp->tail;

	lp->tail->prev->next = lp->cur;
	lp->tail->prev = lp->cur;

	lp->cur->data = *dataPtr;

	lp->length++;

	return lp->cur;
}
/*--------------------------------------------------------------------------------------
함수명 및 기능: display() - 리스트내의 모드 데이터 노드 출력
전달인자: lp - 링크드리스트 정보 구조체의 주소
print - 노드 내 data영역 출력을 위한 보조함수의 시작주소
리턴값: 없음
--------------------------------------------------------------------------------------*/
void display(LinkedList *lp, void (*print)(DataType *))    
{
	//# cur Pointer가 특정 부분을 가리키고 있다고 가정 하면 안된다.
	lp->cur = lp->head->next;  //data 있는 첫 Node를 가리키게함

	while (lp->cur != lp->tail)
	{
		print(&lp->cur->data);

		lp->cur = lp->cur->next;
	}

	return;
}
/*--------------------------------------------------------------------------------------
함수명 및 기능: searchUnique() - 전달된 데이터와 일치하는 노드 검색 함수
전달인자: lp - 링크드리스트 정보 구조체의 주소
dataPtr - 검색할 데이터가 저장된 영역의 주소
compare - data영역 비교를 위한 보조함수의 시작주소
리턴값: 찾은 노드의 주소 리턴/없을 시 NULL pointer 리턴
--------------------------------------------------------------------------------------*/
Node * searchUnique(LinkedList *lp, DataType *dataPtr, int (*compare)(DataType *,DataType *))
{
	DataType *saveData;

	lp->cur = lp->head->next;

	while (lp->cur != lp->tail)
	{
		saveData = &lp->cur->data;

		if (compare(saveData, dataPtr) == 0)
			return lp->cur;

		lp->cur = lp->cur->next;
	}

	return NULL;
}
/*--------------------------------------------------------------------------------------
함수명 및 기능: searchDuplicate() - 전달된 데이터와 일치하는 모든 노드를 다중 검색하는 함수
전달인자: lp - 링크드리스트 정보 구조체의 주소
searchCnt - 찾은 노드의 개수를 저장할 영역의 주소
dataPtr - 검색할 데이터가 저장된 영역의 주소
compare - data영역 비교를 위한 보조함수의 시작주소
리턴값: 찾은 노드의 주소목록배열의 시작 주소 리턴/없을 시 NULL pointer 리턴
--------------------------------------------------------------------------------------*/
//searchPtr = searchDuplicate(lp, &searchCnt, &sData, comparePersonName)
Node** searchDuplicate(LinkedList *lp, int *searchCnt,  DataType *dataPtr, int (*compare)(DataType *, DataType *)) // dataPtr과 일치하는 노드의 주소를 담고 있는 Node *배열의 시작주소 리턴/없을 시 NULL pointer 리턴
{
	/*
	Node **rp = NULL;
	int i = 0;
	*searchCnt = 0;

	lp->cur = lp->head->next;

	while (lp->cur != lp->tail)
	{
		if (compare(&lp->cur->data, dataPtr) == 0)
		{
			rp = (Node**)realloc(rp, sizeof(Node*));
			assert(rp != NULL);
			rp[i] = lp->cur;
			(*searchCnt)++;
			i++;
		}

		lp->cur = lp->cur->next;
	}
	*/

	Node **rp = NULL, *temp;
	int i = 0;
	*searchCnt = 0;

	temp = lp->head->next;

	while (temp != lp->tail)
	{
		if (compare(&(temp->data), dataPtr) == 0)
		{
			rp = (Node**)realloc(rp, sizeof(Node));
			assert(rp != NULL);
			rp[i] = temp;
			(*searchCnt)++;
			i++;
		}
		temp = temp->next;
	}

	return rp;
}
/*--------------------------------------------------------------------------------------
함수명 및 기능: deleteNode() - 리스트내에서 target 노드 삭제
전달인자: lp - 링크드리스트 정보 구조체의 주소
target - 삭제할 노드의 시작주소
리턴값: 없음
--------------------------------------------------------------------------------------*/
void deleteNode(LinkedList *lp, Node *target)
{
	target->prev->next = target->next;
	target->next->prev = target->prev;

	free(target);

	lp--;
}
/*--------------------------------------------------------------------------------------
함수명 및 기능: destroy() - 리스트내에서 모든 노드 삭제(head, tail 노드 포함)
전달인자: lp - 링크드리스트 정보 구조체의 주소
리턴값: 없음
--------------------------------------------------------------------------------------*/
void destroy(LinkedList *lp)
{ 
	Node *temp;
	lp->cur = lp->head->next;

	while (lp->cur != lp->tail)
	{
		temp = lp->cur;

		lp->cur->prev->next = lp->cur->next;
		lp->cur->next->prev = lp->cur->prev;

		lp->cur = lp->cur->next;

		free(temp);

	}

	free(lp->head);
	free(lp->tail);
}
/*--------------------------------------------------------------------------------------
함수명 및 기능: sortList() - 리스트내의 노드를 보조함수의 기준대로 정렬하는 함수
전달인자: lp - 링크드리스트 정보 구조체의 주소
compare - data영역 비교를 위한 보조함수의 시작주소
리턴값: 없음
--------------------------------------------------------------------------------------*/
void sortList(LinkedList *lp, int (*compare)(DataType *, DataType *))  // 노드 정렬  //Data swap
{
	/*
	DataType temp3;
	
	lp->cur = lp->head->next;

	while (lp->cur->next != lp->tail)
	{	
		if (compare(&lp->cur->data, &lp->cur->next->data) == 1)
		{
			temp3 = lp->cur->data;
			lp->cur->data = lp->cur->next->data;
			lp->cur->next->data = temp3;
		}

		lp->cur = lp->cur->next;
	}
	*/

	/*
	LinkedList **temp, **temp2;
	temp = &lp;
	temp2 = &lp;
	//temp2->cur = (Node*)malloc(sizeof(Node));
	DataType save;

	for ((*temp)->cur = (*temp)->head; (*temp)->cur->next != (*temp)->tail; (*temp)->cur = (*temp)->cur->next)
	{
		for ((*temp2)->head = (*temp)->cur->next; (*temp2)->cur != (*temp)->tail; (*temp2)->cur = (*temp2)->cur->next)
		{
			if (compare(&(*temp)->cur->data, &(*temp2)->cur->data) == 1)
			{
				save = (*temp)->cur->data;
				(*temp)->cur->data = (*temp2)->cur->data;
				(*temp2)->cur->data = save;
			}
		}
	}
	*/
	
	Node *temp1, *temp2;
	DataType save;

	for (temp1 = lp->head->next; temp1->next != lp->tail; temp1 = temp1->next)
	{
		for (temp2 = temp1->next; temp2 != lp->tail; temp2 = temp2->next)
		{
			if (compare(&temp1->data, &temp2->data) == 1)
			{
				save = temp1->data;
				temp1->data = temp2->data;
				temp2->data = save;
			}
		}
	}
	
	return;
}