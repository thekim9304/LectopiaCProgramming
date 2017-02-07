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

	return;
}
/*--------------------------------------------------------------------------------------
�Լ��� �� ���: makeNode() - �� ��� ���� �Լ�
��������:  dataPtr - �� ��忡 ������ ������ ������ �ּ�
prev - �� ����� �� ����� �ּ�
next - �� ����� �� ����� �ּ�
���ϰ�: ������ ����� �ּ�
--------------------------------------------------------------------------------------*/
Node * makeNode(DataType *dataPtr, Node *prev, Node *next)
{
	Node *np;
	np = (Node*)malloc(sizeof(Node));
	assert(np != NULL);

	np->prev = prev;
	np->next = next;

	np->prev->next = np;
	np->next->prev = np;

	np->data = *dataPtr;

	return np;
}
/*--------------------------------------------------------------------------------------
�Լ��� �� ���: appendFromHead() - ����� �ڿ� �� ��� �߰�(���� ����)
��������: lp - ��ũ�帮��Ʈ ���� ����ü�� �ּ�
dataPtr - �� ��忡 ������ ������ ������ �ּ�
���ϰ�: �߰��� ����� �ּ�
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
�Լ��� �� ���: appendFromTail() - ���ϳ�� �տ� �� ��� �߰�(���� ����)
��������: lp - ��ũ�帮��Ʈ ���� ����ü�� �ּ�
dataPtr - �� ��忡 ������ ������ ������ �ּ�
���ϰ�: �߰��� ����� �ּ�
--------------------------------------------------------------------------------------*/
Node * appendFromTail(LinkedList *lp, DataType *dataPtr)
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
	makeNode(dataPtr, lp->tail->prev, lp->tail);
	lp->length++;

	return lp->cur;
}
/*--------------------------------------------------------------------------------------
�Լ��� �� ���: display() - ����Ʈ���� ��� ������ ��� ���
��������: lp - ��ũ�帮��Ʈ ���� ����ü�� �ּ�
print - ��� �� data���� ����� ���� �����Լ��� �����ּ�
���ϰ�: ����
--------------------------------------------------------------------------------------*/
void display(LinkedList *lp, void(*print)(DataType *))
{
	//# cur Pointer�� Ư�� �κ��� ����Ű�� �ִٰ� ���� �ϸ� �ȵȴ�.
	lp->cur = lp->head->next;  //data �ִ� ù Node�� ����Ű����

	while (lp->cur != lp->tail)
	{
		print(&lp->cur->data);

		lp->cur = lp->cur->next;
	}

	return;
}
/*--------------------------------------------------------------------------------------
�Լ��� �� ���: searchUnique() - ���޵� �����Ϳ� ��ġ�ϴ� ��� �˻� �Լ�
��������: lp - ��ũ�帮��Ʈ ���� ����ü�� �ּ�
dataPtr - �˻��� �����Ͱ� ����� ������ �ּ�
compare - data���� �񱳸� ���� �����Լ��� �����ּ�
���ϰ�: ã�� ����� �ּ� ����/���� �� NULL pointer ����
--------------------------------------------------------------------------------------*/
Node * searchUnique(LinkedList *lp, DataType *dataPtr, int(*compare)(DataType *, DataType *))
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
�Լ��� �� ���: searchDuplicate() - ���޵� �����Ϳ� ��ġ�ϴ� ��� ��带 ���� �˻��ϴ� �Լ�
��������: lp - ��ũ�帮��Ʈ ���� ����ü�� �ּ�
searchCnt - ã�� ����� ������ ������ ������ �ּ�
dataPtr - �˻��� �����Ͱ� ����� ������ �ּ�
compare - data���� �񱳸� ���� �����Լ��� �����ּ�
���ϰ�: ã�� ����� �ּҸ�Ϲ迭�� ���� �ּ� ����/���� �� NULL pointer ����
--------------------------------------------------------------------------------------*/
//searchPtr = searchDuplicate(lp, &searchCnt, &sData, comparePersonName)
Node** searchDuplicate(LinkedList *lp, int *searchCnt, DataType *dataPtr, int(*compare)(DataType *, DataType *)) // dataPtr�� ��ġ�ϴ� ����� �ּҸ� ��� �ִ� Node *�迭�� �����ּ� ����/���� �� NULL pointer ����
{
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
�Լ��� �� ���: deleteNode() - ����Ʈ������ target ��� ����
��������: lp - ��ũ�帮��Ʈ ���� ����ü�� �ּ�
target - ������ ����� �����ּ�
���ϰ�: ����
--------------------------------------------------------------------------------------*/
void deleteNode(LinkedList *lp, Node *target)
{
	target->prev->next = target->next;
	target->next->prev = target->prev;

	free(target);

	lp--;
}
/*--------------------------------------------------------------------------------------
�Լ��� �� ���: destroy() - ����Ʈ������ ��� ��� ����(head, tail ��� ����)
��������: lp - ��ũ�帮��Ʈ ���� ����ü�� �ּ�
���ϰ�: ����
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
�Լ��� �� ���: sortList() - ����Ʈ���� ��带 �����Լ��� ���ش�� �����ϴ� �Լ�
��������: lp - ��ũ�帮��Ʈ ���� ����ü�� �ּ�
compare - data���� �񱳸� ���� �����Լ��� �����ּ�
���ϰ�: ����
--------------------------------------------------------------------------------------*/
void sortList(LinkedList *lp, int(*compare)(DataType *, DataType *))  // ��� ����  //Data swap
{
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