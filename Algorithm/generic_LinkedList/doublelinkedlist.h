#pragma once
#pragma warning(disable:4996) /* VS2005 �̻󿡼� �߻��ϴ� �ܼ� �Լ� ��� ���� */
#include "person.h"

typedef struct _node Node;    // ����ü ��� ����������

struct _node{         // �����͸� ������ ���(�ڱ����� ����ü)
	Node *prev;               // �� ��带 ����Ű�� ���
	Node *next;               // �� ��带 ����Ű�� ���
};

typedef struct _linkedList{   // ����Ʈ ���� ����ü
	Node *head;               // ��������� (����� ����Ŵ)
	Node *cur;                // Ư�� �۾� �� ��带 ����Ű�� ���� ������
	Node *tail;               // ���������� (���ϳ�� ����Ŵ)
	int length;               // ���� �����ͳ���� ����
}LinkedList;

//-------------------------------------------------------------------------------------------
//                                 ��ũ�帮��Ʈ ���� �Լ� 
//-------------------------------------------------------------------------------------------
void create(LinkedList *lp);   // ��ũ�帮��Ʈ �ʱ�ȭ
Node * makeNode(void *dataPtr, Node *prev, Node *next, size_t size, void(*myMemCpy)(void*, void*));
Node * appendFromHead(LinkedList *linkedList, void *item, size_t size, void(*myMemCpy)(void *, void *));      // ����� �ڿ� �� ��� �߰�(���� ����)
Node * appendFromTail(LinkedList *linkedList, void *item, size_t size, void(*myMemCpy)(void *, void*));     // ���ϳ�� �տ� �� ��� �߰�(���� ����)
void display(LinkedList *linkedList, void(*dataPrint)(void*));    // ����Ʈ���� ��� ������ ��� ���
Node* deleteNode(LinkedList *linkedList, Node *index, void(*dataFree)(void*));              // target��� ����
Node* linearSearchUnique(LinkedList *linkedList, void *target, int(*compare)(void*, void*)); // dataPtr�� ��ġ�ϴ� ����� �ּ� ����/���� �� NULL pointer ����
Node** linearSearchDuplicate(LinkedList *linkedList, void *target, int *searchNodeCount, int(*compare)(void*, void*)); // dataPtr�� ��ġ�ϴ� ����� �ּҸ� ��� �ִ� Node *�迭�� �����ּ� ����/���� �� NULL pointer ����
void sortList(LinkedList *list, size_t size, int(*compare)(void*, void*), void(*myMemCpy)(void*, void*), void(*dataFree)(void*)); // ��� ����
void destroy(LinkedList *linkedList, void (dataFree)(void*));              // ����Ʈ���� ��� ��带 ����
