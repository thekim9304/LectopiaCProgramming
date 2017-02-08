#include <stdio.h> 
#include <malloc.h> 
#include <assert.h> 
#include "queue.h" 

/*--------------------------------------------------------------------------------------
  �Լ���ױ�� : initQueue() - ť �ʱ�ȭ �Լ�
  �������� : qPtr - ť ����ü�� �ּ�
             size - ť�� ũ��
  ���ϰ� : ����
--------------------------------------------------------------------------------------*/
void initQueue(Queue * qPtr, int qSize, int dataSize)
{ 
	qPtr->qSize = qSize; 
	qPtr->front = 0; 
	qPtr->rear = 0; 
	qPtr->queue = calloc(qSize, dataSize); 
} 
/*--------------------------------------------------------------------------------------
  �Լ���ױ�� : enqueue() - ť�� ������ �ϳ��� ������
  �������� : qPtr - ť ����ü�� �ּ�
             inData - ť�� ������ ������
  ���ϰ� : ���������� �����ϸ� TRUE, �����ϸ� FALSE ����
--------------------------------------------------------------------------------------*/
int put(Queue * qPtr, void *inData, int dataSize, void (*dataCpy)(void *, void *))
{ 
	if (isQueueFull(qPtr) == FALSE)
	{
		dataCpy((char*)qPtr->queue + (qPtr->rear * dataSize), inData);
		qPtr->rear = ++(qPtr->rear) % qPtr->qSize;
		return TRUE;
	}

	return FALSE;
} 
/*--------------------------------------------------------------------------------------
  �Լ��� �� ��� : dequeue() - ť���� ������ �ϳ��� ����
  �������� : qPtr - ť ����ü�� �ּ�
             getData - ���� �����͸� ������ �������� �ּ�
  ���ϰ� : ���������� ������ TRUE, �����ϸ� FALSE ����
--------------------------------------------------------------------------------------*/
int get(Queue * qPtr, void *getData, int dataSize, void (*dataCpy)(void *, void *), void (*MemFree)(void *))
{ 

	if (isQueueEmpty(qPtr) == FALSE)
	{
		dataCpy(getData, (char*)qPtr->queue + (qPtr->front * dataSize));
		MemFree((char*)qPtr->queue + (qPtr->front * dataSize));
		qPtr->front = (++qPtr->front) % qPtr->qSize;

		return TRUE;
	}
	else
		return FALSE;
} 
/*--------------------------------------------------------------------------------------
  �Լ���ױ�� : printQueue() - ť ���� ��� �����͸� ��� ��
  �������� : qPtr - ť ����ü�� �ּ�
             print -  DataType�� ������ ����ϴ� ��� ���� �Լ�
  ���ϰ� : ����
--------------------------------------------------------------------------------------*/
void printQueue(const Queue * qPtr, int dataSize, void (*dataPrint)(void *))
{ 
	int i;

	for (i = qPtr->front; i != qPtr->rear; i = (++i % qPtr->qSize))
		dataPrint((char*)qPtr->queue + (dataSize * i));

	printf("\n");
} 
/*--------------------------------------------------------------------------------------
  �Լ���ױ�� : destroyQueue() - ť �Ҹ� �Լ�
  �������� : qPtr - ť ����ü�� �ּ�
  ���ϰ� : ����
--------------------------------------------------------------------------------------*/
void destroyQueue(Queue * qPtr, int dataSize, void (*MemFree)(void *))
{ 
	int i;

	for (i = 0; i < dataSize; i++)
		MemFree(qPtr->queue);

	free(qPtr->queue);

	qPtr->queue = NULL;
	qPtr->front = 0;
	qPtr->rear = 0;
	qPtr->qSize = 0;
} 
/*--------------------------------------------------------------------------------------
  �Լ��� �� ���: isQueueEmpty() - ť�� ����ִ°� �˻�
  ��������: qPtr - ť ����ü�� �ּ�
  ���ϰ�: ��������� TRUE ����, ������� ������ FALSE ����
--------------------------------------------------------------------------------------*/
int isQueueEmpty(const Queue *qPtr)
{
	if (qPtr->front == qPtr->rear)
		return TRUE;
	else
		return FALSE;
}

int isQueueFull(const Queue *qPtr)
{
	if (qPtr->front == ((qPtr->rear + 1) % qPtr->qSize))
		return TRUE;
	else
		return FALSE;
}