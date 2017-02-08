#pragma once 
#pragma warning(disable:4996)
#include "person.h"
enum {FALSE, TRUE};

typedef struct _queue { 
	void *queue; 
	int qSize; 
	int front, rear; 
}Queue; 

void initQueue(Queue * qPtr, int qSize, int dataSize); // 큐 생성 및 초기화 함수
int put(Queue * qPtr, void *inData, int dataSize, void(*dataCpy)(void *, void *));   // 큐에 데이터 하나를 저장함
int get(Queue * qPtr, void *getData, int dataSize, void(*dataCpy)(void *, void *), void(*MemFree)(void *));  // 큐에서 데이터 하나를 꺼냄
void printQueue(const Queue * qPtr, int dataSize, void(*dataPrint)(void *));  // 큐 내의 모든 데이터를 출력(dequeue하는 것은 아님)
void destroyQueue(Queue * qPtr, int dataSize, void(*MemFree)(void *));  // 큐 소멸 함수
int isQueueEmpty(const Queue *qPtr); // 큐가 비어있는가 검사
int isQueueFull(const Queue *qPtr);