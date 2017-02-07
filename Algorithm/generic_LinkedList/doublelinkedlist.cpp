#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include "doublelinkedlist.h"
/*--------------------------------------------------------------------------------------
�Լ��� �� ���: create() - ��ũ�帮��Ʈ �ʱ�ȭ
��������:  lp - ��ũ�帮��Ʈ ���� ����ü�� �ּ�
���ϰ�: ����
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
�Լ��� �� ���: makeNode() - �� ��� ���� �Լ�
��������:  dataPtr - �� ��忡 ������ ������ ������ �ּ�
prev - �� ����� �� ����� �ּ�
next - �� ����� �� ����� �ּ�
���ϰ�: ������ ����� �ּ�
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
�Լ��� �� ���: appendFromHead() - ����� �ڿ� �� ��� �߰�(���� ����)
��������: lp - ��ũ�帮��Ʈ ���� ����ü�� �ּ�
dataPtr - �� ��忡 ������ ������ ������ �ּ�
���ϰ�: �߰��� ����� �ּ�
--------------------------------------------------------------------------------------*/
Node * appendFromHead(LinkedList *linkedList, void *item, size_t size, void(*myMemCpy)(void *, void *))
{
	makeNode(item, linkedList->head, linkedList->head->next, size, myMemCpy);
	linkedList->length++;

	return linkedList->cur;
}
/*--------------------------------------------------------------------------------------
�Լ��� �� ���: appendFromTail() - ���ϳ�� �տ� �� ��� �߰�(���� ����)
��������: lp - ��ũ�帮��Ʈ ���� ����ü�� �ּ�
dataPtr - �� ��忡 ������ ������ ������ �ּ�
���ϰ�: �߰��� ����� �ּ�
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
�Լ��� �� ���: display() - ����Ʈ���� ��� ������ ��� ���
��������: lp - ��ũ�帮��Ʈ ���� ����ü�� �ּ�
print - ��� �� data���� ����� ���� �����Լ��� �����ּ�
���ϰ�: ����
--------------------------------------------------------------------------------------*/
void display(LinkedList *linkedList, void (*dataPrint)(void*))
{
	//# cur Pointer�� Ư�� �κ��� ����Ű�� �ִٰ� ���� �ϸ� �ȵȴ�.
	linkedList->cur = linkedList->head->next;  //data �ִ� ù Node�� ����Ű����

	while (linkedList->cur != linkedList->tail)
	{
		dataPrint(linkedList->cur + 1);

		linkedList->cur = linkedList->cur->next;
	}
}
/*--------------------------------------------------------------------------------------
�Լ��� �� ���: searchUnique() - ���޵� �����Ϳ� ��ġ�ϴ� ��� �˻� �Լ�
��������: lp - ��ũ�帮��Ʈ ���� ����ü�� �ּ�
dataPtr - �˻��� �����Ͱ� ����� ������ �ּ�
compare - data���� �񱳸� ���� �����Լ��� �����ּ�
���ϰ�: ã�� ����� �ּ� ����/���� �� NULL pointer ����
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
�Լ��� �� ���: searchDuplicate() - ���޵� �����Ϳ� ��ġ�ϴ� ��� ��带 ���� �˻��ϴ� �Լ�
��������: lp - ��ũ�帮��Ʈ ���� ����ü�� �ּ�
searchCnt - ã�� ����� ������ ������ ������ �ּ�
dataPtr - �˻��� �����Ͱ� ����� ������ �ּ�
compare - data���� �񱳸� ���� �����Լ��� �����ּ�
���ϰ�: ã�� ����� �ּҸ�Ϲ迭�� ���� �ּ� ����/���� �� NULL pointer ����
--------------------------------------------------------------------------------------*/
//searchPtr = searchDuplicate(lp, &searchCnt, &sData, comparePersonName)
Node** linearSearchDuplicate(LinkedList *linkedList, void *target, int *searchNodeCount, int (*compare)(void*, void*)) // dataPtr�� ��ġ�ϴ� ����� �ּҸ� ��� �ִ� Node *�迭�� �����ּ� ����/���� �� NULL pointer ����
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
�Լ��� �� ���: deleteNode() - ����Ʈ������ target ��� ����
��������: lp - ��ũ�帮��Ʈ ���� ����ü�� �ּ�
target - ������ ����� �����ּ�
���ϰ�: ����
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
�Լ��� �� ���: destroy() - ����Ʈ������ ��� ��� ����(head, tail ��� ����)
��������: lp - ��ũ�帮��Ʈ ���� ����ü�� �ּ�
���ϰ�: ����
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
�Լ��� �� ���: sortList() - ����Ʈ���� ��带 �����Լ��� ���ش�� �����ϴ� �Լ�
��������: lp - ��ũ�帮��Ʈ ���� ����ü�� �ּ�
compare - data���� �񱳸� ���� �����Լ��� �����ּ�
���ϰ�: ����
--------------------------------------------------------------------------------------*/
void sortList(LinkedList *list, size_t size, int(*compare)(void*, void*), void(*myMemCpy)(void*, void*), void(*dataFree)(void*))  // ��� ����  //Data swap
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