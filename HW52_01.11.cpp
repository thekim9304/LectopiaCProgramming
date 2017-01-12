/*
	!!배열 내의 데이터를 역순으로 저장하기

	배열에 임의의 숫자를 초기화한 후에 각 수자들의 위치를 반대로 바꾸는 프로그램을 작성한다.
	배열은 하나만 사용하며 배열의 크기가 바뀌더라도 코드를 수정할 필요가 없도록 작성한다.
	두 변수의 값을 바꾸기 위해서는 swap()함수를 구현하여 바꾸도록 하자.

	@2017.01.12 am09:55
*/
#if 0
#include <stdio.h>

void swap(int*, int);

int main()
{
	int swapArray[5], i, arySize;

	arySize = sizeof(swapArray) / sizeof(swapArray[0]);

	printf("처음 배열에 저장된 값 : ");
	for (i = 0; i < arySize; i++)
		scanf("%d", &swapArray[i]);

	swap(swapArray, arySize);

	printf("바뀐 배열에 저장된 값 : ");
	for (i = 0; i < arySize; i++)
		printf("%d ", swapArray[i]);
}

void swap(int *swapArray, int arraySize)
{
	int swaping, i;

	for (i = 0; i < (arraySize / 2); i++)
	{
		swaping = swapArray[i];
		swapArray[i] = swapArray[(arraySize - 1) - i];
		swapArray[(arraySize - 1) - i] = swaping;
	}
}
#endif