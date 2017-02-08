#pragma once
#pragma warning(disable:4996)
#include "person.h"

typedef struct _stack{ // stack���� ����ü
	void *stack;       // stack���� ���Ǵ� �迭�� ����Ű�� ������ ����
	int sSize;             // ������ ũ��
	int top;               // ������ ��,�ⱸ ��ġ���� ����
}Stack;

void initStack(Stack *sPtr, size_t sSize, size_t dataSize);     //���� �޸� �Ҵ� �� �ʱ�ȭ �Լ� top�� ��ġ�� 0�� �ʱ�ȭ
void clearStack(Stack *sPtr, size_t dataSize, void(*memFree)(void*));         // ���� ���� �Լ�
int push(Stack *sPtr, void *pushData, size_t dataSize, void(*memCpy)(void *, void *));         // ���ÿ� ������ �����ϴ� �Լ�#
int pop(Stack * sPtr, void *popData, size_t dataSize, void(*memCpy)(void *, void *), void(*memFree)(void *));     // ���ÿ��� �����͸� ������ �Լ�#
void printStack(const Stack *sPtr, size_t dataSize, void(*memPrintf)(void *));    // ���� ���� ��� �����͸� ����ϴ� �Լ�#
void destroyStack(Stack *sPtr, size_t dataSize, void(*memFree)(void *));    // ���� �޸� ���� �Լ�#
int isStackFull(Stack *sPtr);     // ������ �� ���ִ��� �˻�#push����
int isStackEmpty(Stack *sPtr);    // ������ ����ִ��� �˻�#pop����