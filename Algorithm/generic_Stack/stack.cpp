#include "stack.h"
#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <memory.h>
/*--------------------------------------------------------------------------------------
�Լ���ױ��: initStack() - ������ ũ���� ������ �����ϴ� �Լ�
��������: sPtr -  ������ �ּ� / sSize - ������ ũ�� / dataSize - ������ �ϳ��� ũ��
���ϰ�: ����
--------------------------------------------------------------------------------------*/
void initStack(Stack *sPtr, size_t sSize, size_t dataSize)
{
	sPtr->stack = calloc(sSize , dataSize);  // �޸� �Ҵ� & 0���� �ʱ�ȭ
	if (sPtr->stack == NULL)
		printf("���� �Ҵ� error -> (initStack) \n");

	sPtr->sSize = sSize;
	sPtr->top = 0;
}
/*--------------------------------------------------------------------------------------
�Լ���ױ��: clearStack() - ���� �ʱ�ȭ �Լ�(��� ������ ���� ����)
��������: sPtr - ������ �ּ� / dataSize - ������ �ϳ��� ũ�� / memFree - ���ؿ� ����Ǵ� �����Ϳ� �ΰ� �޸𸮸� �����ϴ� �Լ�
���ϰ�: ����
--------------------------------------------------------------------------------------
void clearStack(Stack *sPtr, size_t dataSize, void (*memFree)(void*))
{
	// TODO
}
*/
/*--------------------------------------------------------------------------------------
�Լ���ױ��: push() - ���ÿ� ������ �ϳ��� ������
��������: sPtr - ������ �ּ�
inData - ���ÿ� ������ ������
���ϰ�: ���������� �����ϸ�1, �����ϸ�0 ����
--------------------------------------------------------------------------------------*/
int push(Stack *sPtr, void *pushData, size_t dataSize, void (*memCpy)(void *, void *)) /* stack�� ������ �����ϱ� */
{
	if (isStackFull(sPtr) == 0)
	{
		memCpy((char*)sPtr->stack + (dataSize * sPtr->top) , pushData);
		(sPtr->top)++;
		return 1;
	}
	else
		return 0;
}

/*--------------------------------------------------------------------------------------
�Լ���ױ��: pop() - ���ÿ��� ������ �ϳ��� ����
��������: sPtr - ������ �ּ�
popData -  ���� �����͸� ������ �������� �ּ�
���ϰ�: ���������� ������1, �����ϸ�0 ����
--------------------------------------------------------------------------------------*/
int pop(Stack * sPtr, void *popData, size_t dataSize, void (*memCpy)(void *, void *), void (*memFree)(void *))
{
	if (isStackEmpty(sPtr) == 0)
	{
		sPtr->top--;

		memCpy(popData, (char*)sPtr->stack + (dataSize * sPtr->top));
		memFree((char*)sPtr->stack + (dataSize * sPtr->top));

		return 1;
	}
	else
		return 0;
}

/*--------------------------------------------------------------------------------------
�Լ���ױ��: printStack() - ������ ��� �����͸� ��� ��
��������: sPtr -  ������ �ּ�
���ϰ�: ����
--------------------------------------------------------------------------------------*/
void printStack(const Stack *sPtr, size_t dataSize, void (*memPrintf)(void *))  //0�� ����� ���
{
	int i;

	if (sPtr->top == 0)
		printf("Stack�� ��� �ֽ��ϴ�.\n");
	else
	{
		for (i = sPtr->top - 1; i >= 0; i--)
			memPrintf((char*)sPtr->stack + (dataSize * i));
	}
	printf("\n");
}

/*--------------------------------------------------------------------------------------
�Լ���ױ��: destroyStack() -  ���� �Ҹ� �Լ�
��������: sPtr -  ������ �ּ�
���ϰ�: ����
--------------------------------------------------------------------------------------*/
void destroyStack(Stack *sPtr, size_t dataSize, void (*memFree)(void *))
{
	while (isStackEmpty(sPtr) != 1) {
		sPtr->top--;
		memFree((char*)sPtr->stack + (dataSize * sPtr->top));
	}

	free(sPtr->stack);

	sPtr->stack = NULL;
	sPtr->sSize = 0;
	sPtr->top = 0;
}
/*-----------------------------------------------------------------------------------
�Լ��� �� ��� : isStackFull() - ������ �� ���ִ��� �˻�
�������� : sPtr - ������ �ּ�
���ϰ� : ������ �� �������� 1, �ƴϸ� 0 ����
-----------------------------------------------------------------------------------*/
int isStackFull(Stack *sPtr)
{
	if(sPtr->top == (sPtr->sSize))
		return 1;
	else
		return 0;
}
/*-----------------------------------------------------------------------------------
�Լ��� �� ��� : isStackEmpty() - ������ ����ִ��� �˻�
�������� : sPtr - ������ �ּ�
���ϰ� : ������ ��������� 1, �ƴϸ� 0 ����
-----------------------------------------------------------------------------------*/
int isStackEmpty(Stack *sPtr)
{
	if (sPtr->top == 0)
		return 1;
	else
		return 0;
}