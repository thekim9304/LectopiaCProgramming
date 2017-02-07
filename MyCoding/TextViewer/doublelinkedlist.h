#pragma once
#pragma warning(disable:4996) /* VS2005 �̻󿡼� �߻��ϴ� �ܼ� �Լ� ��� ���� */
#include "datatype.h"

typedef struct _node Node;    // ����ü ��� ����������

struct _node{         // �����͸� ������ ���(�ڱ����� ����ü)
	Node *prev;               // �� ��带 ����Ű�� ���
	DataType data;            // ������ ���� ���
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
Node * makeNode(DataType *dataPtr, Node *prev, Node *next);
Node * appendFromHead(LinkedList *lp, DataType *dataPtr);      // ����� �ڿ� �� ��� �߰�(���� ����)
Node * appendFromTail(LinkedList *lp, DataType *dataPtr);      // ���ϳ�� �տ� �� ��� �߰�(���� ����)
void display(LinkedList *lp, void (*print)(DataType *));       // ����Ʈ���� ��� ������ ��� ���
void deleteNode(LinkedList *lp, Node *target);                // target��� ����
Node * searchUnique(LinkedList *lp, DataType *dataPtr, int (*compare)(DataType *,DataType *)); // dataPtr�� ��ġ�ϴ� ����� �ּ� ����/���� �� NULL pointer ����
Node ** searchDuplicate(LinkedList *lp, int *searchCnt,  DataType *dataPtr, int (*compare)(DataType *, DataType *)); // dataPtr�� ��ġ�ϴ� ����� �ּҸ� ��� �ִ� Node *�迭�� �����ּ� ����/���� �� NULL pointer ����
void sortList(LinkedList *lp, int (*compare)(DataType *, DataType *));  // ��� ����
void destroy(LinkedList *lp);                                   // ����Ʈ���� ��� ��带 ����
