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
	lp->head = (Node*)calloc(1, sizeof(Node));
	assert(lp->head != NULL);
	lp->tail = (Node*)calloc(1, sizeof(Node));
	assert(lp->tail != NULL);

	lp->head->next = lp->tail;
	lp->tail->prev = lp->head;

	lp->head->prev = lp->head;
	lp->tail->next = lp->tail;

	lp->cur = NULL;
	lp->length = 0;

	return;
}
/*--------------------------------------------------------------------------------------
함수명 및 기능: makeNode() - 새 노드 생성 함수
전달인자:  dataPtr - 새 노드에 저장할 데이터 영역의 주소
prev - 새 노드의 앞 노드의 주소
next - 새 노드의 뒷 노드의 주소
리턴값: 생성된 노드의 주소
--------------------------------------------------------------------------------------*/
Node * makeNode(void *dataPtr, Node *prev, Node *next, size_t size, void (*myMemCpy)(void*, void*))
{
	Node *np;
	np = (Node*)calloc(1, sizeof(Node) + size);
	assert(np != NULL);

	np->prev = prev;
	np->next = next;

	np->prev->next = np;
	np->next->prev = np;

	myMemCpy(np + 1/* (char*)np + 8)*/, dataPtr);

	return np;
}
/*--------------------------------------------------------------------------------------
함수명 및 기능: appendFromHead() - 헤드노드 뒤에 새 노드 추가(역순 저장)
전달인자: lp - 링크드리스트 정보 구조체의 주소
dataPtr - 새 노드에 저장할 데이터 영역의 주소
리턴값: 추가한 노드의 주소
--------------------------------------------------------------------------------------*/
Node * appendFromHead(LinkedList *linkedList, void *item, size_t size, void(*myMemCpy)(void *, void *))
{
	makeNode(item, linkedList->head, linkedList->head->next, size, myMemCpy);
	linkedList->length++;

	return linkedList->cur;
}
/*--------------------------------------------------------------------------------------
함수명 및 기능: appendFromTail() - 테일노드 앞에 새 노드 추가(정순 저장)
전달인자: lp - 링크드리스트 정보 구조체의 주소
dataPtr - 새 노드에 저장할 데이터 영역의 주소
리턴값: 추가한 노드의 주소
--------------------------------------------------------------------------------------*/
Node * appendFromTail(LinkedList *linkedList, void *item, size_t size, void(*myMemCpy)(void *, void*))
{
	/*
	lp->cur = (Node*)malloc(sizeof(Node));
	assert(lp->cur != NULL);

	lp->cur->prev = lp->tail->prev;
	lp->cur->next = lp->tail;

	lp->tail->prev->next = lp->cur;
	lp->tail->prev = lp->cur;

	lp->cur->data = *dataPtr;
	*/
	makeNode(item, linkedList->tail->prev, linkedList->tail, size, myMemCpy);
	linkedList->length++;

	return linkedList->cur;
} // Person *dataPtr, Node *prev, Node *next, size_t size, void (*myMemCpy)(void*, void*)
/*--------------------------------------------------------------------------------------
함수명 및 기능: display() - 리스트내의 모드 데이터 노드 출력
전달인자: lp - 링크드리스트 정보 구조체의 주소
print - 노드 내 data영역 출력을 위한 보조함수의 시작주소
리턴값: 없음
--------------------------------------------------------------------------------------*/
void display(LinkedList *linkedList, void (*dataPrint)(void*))
{
	//# cur Pointer가 특정 부분을 가리키고 있다고 가정 하면 안된다.
	linkedList->cur = linkedList->head->next;  //data 있는 첫 Node를 가리키게함

	while (linkedList->cur != linkedList->tail)
	{
		dataPrint(linkedList->cur + 1);

		linkedList->cur = linkedList->cur->next;
	}
}
/*--------------------------------------------------------------------------------------
함수명 및 기능: searchUnique() - 전달된 데이터와 일치하는 노드 검색 함수
전달인자: lp - 링크드리스트 정보 구조체의 주소
dataPtr - 검색할 데이터가 저장된 영역의 주소
compare - data영역 비교를 위한 보조함수의 시작주소
리턴값: 찾은 노드의 주소 리턴/없을 시 NULL pointer 리턴
--------------------------------------------------------------------------------------*/
Node* linearSearchUnique(LinkedList *linkedList, void *target, int (*compare)(void*, void*))
{
	Node *saveData;

	linkedList->cur = linkedList->head->next;

	while (linkedList->cur != linkedList->tail)
	{
		saveData = linkedList->cur + 1;

		if (compare(saveData, target) == 0)
			return linkedList->cur;

		linkedList->cur = linkedList->cur->next;
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
Node** linearSearchDuplicate(LinkedList *linkedList, void *target, int *searchNodeCount, int (*compare)(void*, void*)) // dataPtr과 일치하는 노드의 주소를 담고 있는 Node *배열의 시작주소 리턴/없을 시 NULL pointer 리턴
{
	Node **rp = NULL, *temp;
	int i = 1;
	*searchNodeCount = 0;

	temp = linkedList->head->next;

	while (temp != linkedList->tail)
	{
		if (compare(temp + 1, target) == 0)
		{
			(*searchNodeCount)++;
			rp = (Node**)realloc(rp, sizeof(Node*)*(*searchNodeCount));
			assert(rp != NULL);
			rp[*searchNodeCount - 1] = temp;
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
Node* deleteNode(LinkedList *linkedList, Node *index, void(*dataFree)(void*))
{
	index->prev->next = index->next;
	index->next->prev = index->prev;

	if ((index + 1) != NULL)
		dataFree(index + 1);

	free(index);

	return index;
}
/*--------------------------------------------------------------------------------------
함수명 및 기능: destroy() - 리스트내에서 모든 노드 삭제(head, tail 노드 포함)
전달인자: lp - 링크드리스트 정보 구조체의 주소
리턴값: 없음
--------------------------------------------------------------------------------------*/
void destroy(LinkedList *linkedList, void (dataFree)(void*))
{
	Node *temp;
	linkedList->cur = linkedList->head->next;

	while (linkedList->cur != linkedList->tail)
	{
		temp = linkedList->cur;

		linkedList->cur->prev->next = linkedList->cur->next;
		linkedList->cur->next->prev = linkedList->cur->prev;

		linkedList->cur = linkedList->cur->next;

		free(temp);
	}

	free(linkedList->head);
	free(linkedList->tail);
}
/*--------------------------------------------------------------------------------------
함수명 및 기능: sortList() - 리스트내의 노드를 보조함수의 기준대로 정렬하는 함수
전달인자: lp - 링크드리스트 정보 구조체의 주소
compare - data영역 비교를 위한 보조함수의 시작주소
리턴값: 없음
--------------------------------------------------------------------------------------*/
void sortList(LinkedList *list, size_t size, int(*compare)(void*, void*), void(*myMemCpy)(void*, void*), void(*dataFree)(void*))  // 노드 정렬  //Data swap
{
	Node *temp1, *temp2, *save;

	save = (Node*)calloc(1, sizeof(Node) + size);
	assert(save != NULL);

	for (temp1 = list->head->next; temp1->next != list->tail; temp1 = temp1->next)
	{
		for (temp2 = temp1->next; temp2 != list->tail; temp2 = temp2->next)
		{
			if (compare(temp1 + 1, temp2 + 1) == 1)
			{
				myMemCpy(save + 1, temp1 + 1);
				dataFree(temp1 + 1);
				myMemCpy(temp1 + 1, temp2 + 1);
				dataFree(temp2 + 1);
				myMemCpy(temp2 + 1, save + 1);
			}
		}
	}

	dataFree(save);
	return;
}