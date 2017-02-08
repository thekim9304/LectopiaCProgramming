#pragma once 
#pragma warning(disable:4996)
#include "person.h"
enum {FALSE, TRUE};

typedef struct _queue { 
	void *queue; 
	int qSize; 
	int front, rear; 
}Queue; 

void initQueue(Queue * qPtr, int qSize, int dataSize); // ť ���� �� �ʱ�ȭ �Լ�
int put(Queue * qPtr, void *inData, int dataSize, void(*dataCpy)(void *, void *));   // ť�� ������ �ϳ��� ������
int get(Queue * qPtr, void *getData, int dataSize, void(*dataCpy)(void *, void *), void(*MemFree)(void *));  // ť���� ������ �ϳ��� ����
void printQueue(const Queue * qPtr, int dataSize, void(*dataPrint)(void *));  // ť ���� ��� �����͸� ���(dequeue�ϴ� ���� �ƴ�)
void destroyQueue(Queue * qPtr, int dataSize, void(*MemFree)(void *));  // ť �Ҹ� �Լ�
int isQueueEmpty(const Queue *qPtr); // ť�� ����ִ°� �˻�
int isQueueFull(const Queue *qPtr);