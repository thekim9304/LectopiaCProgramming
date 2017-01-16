/*
	!!최대값, 최소값 찾기(2)

	int ary[100] 배열에 데이터를 원하는 만큼 데이터를 입력 받아 그 수 중에 최대값과 최소값을 구하여 출력하시오.
	이때 최대값과 최소값아 각각 몇 번째였는지도 함께 구하여 출력하는 프로그램 작성
	반복 수행하고 문자 입력시 종료 (sort 기능 사용x)

	@2017.01.13 pm06:18
*/
#if 0
#include <stdio.h>

int inputArray(int*);
int minCalculator(int*, int, int*);
int maxCalculator(int*, int, int*);
void outputMaxMin(int, int, int*, int*);

int main()
{
	int ary[100], max, min, indexMax = 0, indexMin = 0, aryLength;

	while (1)
	{
		aryLength = inputArray(ary);

		if (aryLength == -1)
			break;

		max = maxCalculator(ary, aryLength, &indexMax);
		min = minCalculator(ary, aryLength, &indexMin);

		outputMaxMin(max, min, &indexMax, &indexMin);
	}
	//max = maxCalculator(ary);
	//min = minCalculator(ary);
	//outputMaxMin(max, min);
}

void outputMaxMin(int max, int min, int *indexMax, int *indexMin)
{
	printf("\n가장 큰 값 : %d(index:%d) / ", max, *indexMax);
	printf("가장 작은 값 : %d(index:%d)\n\n", min, *indexMin);
}

int maxCalculator(int *mmArray, int aryLength, int *indexMax)
{
	int storage;
	int i;

	storage = mmArray[0];

	for (i = 1; i < aryLength; i++)
	{
		if (storage < mmArray[i])
		{
			storage = mmArray[i];
			*indexMax = i;
		}
	}

	return storage;
}

int minCalculator(int *mmArray, int aryLength, int *indexMin)
{
	int storage;
	int i;

	storage = mmArray[0];

	for (i = 1; i < aryLength; i++)
	{
		if (storage > mmArray[i])
		{
			storage = mmArray[i];
			*indexMin = i;
		}
	}

	return storage;
}

int inputArray(int *mmArray)
{
	int i = 0, ret;

	printf("* 정수 입력 : ");

	while (1)
	{
		ret = scanf("%d", &mmArray[i]);

		if (ret == 0)
			return -1;

		if (mmArray[i] == 0)
			break;

		i++;
	}

	return i;
	/*while (1)
	{
	printf("%d 번 방 값 : ", i);
	scanf("%d", &mmArray[i]);

	i++;
	}*/
}
#endif