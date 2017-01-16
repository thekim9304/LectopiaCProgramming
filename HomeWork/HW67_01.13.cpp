/*
	!! 서로 다른 수의 개수 출력하기

	n개의 수를 입력으로 받아 서른 다른 수의 개수를 구하는 프로그램

	@2017.01.14 pm05:38
*/
#if 0
#include <stdio.h>
#define SIZE 1000

int inputCount();
void inputNum(int *, int);
void numCompare(int *, int);
int numCheck(int *, int);
void resultOutput(int);

int main()
{
	int num[SIZE], ret, count, countNum;

	while (1)
	{
		count = inputCount();

		if (count == -1)
			break;

		inputNum(num, count);
		numCompare(num, count);
		countNum = numCheck(num, count);
		resultOutput(countNum);
	}
}

void resultOutput(int count)
{
	printf(" 서로 다른 수의 개수 : %d\n\n", count);
}

int numCheck(int *num, int cnt)
{
	int i, count = 0;

	for (i = 0; i < cnt; i++)
	{
		if (num[i] != 0)
			count++;
	}

	return count;
}

void numCompare(int *num, int cnt)
{
	int i, j;

	for (i = 0; i < cnt; i++)
	{
		for (j = i + 1; j < cnt; j++)
		{
			if (num[i] == num[j])
				num[j] = 0;
		}
		if (num[i] == 0)
			continue;
	}
}

void inputNum(int *num, int cnt)
{
	int i, ret;

	printf("* 숫자 입력 : ");
	
	for (i = 0; i < cnt; i++)
	{
		ret = scanf("%d", &num[i]);
	}
}

int inputCount()
{
	int input, ret;

	printf("* 입력할 숫자의 개수 : ");
	ret = scanf("%d", &input);

	if (ret == 0)
		return -1;

	return input;
}
#endif