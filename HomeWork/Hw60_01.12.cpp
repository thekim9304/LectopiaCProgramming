/*
	!!배열의 부분합 구하기(이차원배열 이용)

	int형 5행 5열짜리 2차원 배열을 선언하여 1~20까지의 난수를 발생시켜 초기화 한 후
	다음의 각각의 합을 구하시오. (p188 그림)

	@2017.01.12 pm07:20
*/
#if 0
#include <stdio.h>
#include <stdlib.h>

int random(int);
void numReset(int(*)[5]);
void aryCalculator(int(*)[5], int*, int*, int*);

int main()
{
	int num[5][5], sum1 = 0, sum2 = 0, sum3 = 0;

	numReset(&num[0]);

	aryCalculator(&num[0], &sum1, &sum2, &sum3);

}

void aryCalculator(int(*num)[5], int *sum1, int *sum2, int *sum3)
{
	int i, j;

	for (i = 0; i < 5; i++)
	{
		*sum1 += num[i][i];

		printf("%d행 : ", i);
		for (j = 0; j < 5; j++)
		{
			printf("%d ", num[i][j]);
		}
		printf("\n");
	}
	printf("\nsum1 = %d\n", *sum1);
	
	for (i = 0; i < 4; i++)
	{
		for (j = i + 1; j < 5; j++)
		{
			*sum2 += num[i][j];
		}
	}
	printf("sum2 = %d\n", *sum2);

	for (i = 4; i > 0; i--)
	{
		for (j = i - 1; j >= 0; j--)
		{
			*sum3 += num[i][j];
		}
	}
	printf("sum3 = %d\n", *sum3);
}

void numReset(int(*num)[5])
{
	int i, j;

	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			//srand((unsigned int)time(NULL));
			num[i][j] = random(9) + 1;
		}
	}
}

int random(int n)
{
	int ret;
	ret = rand() % n;
	return ret;
}
#endif