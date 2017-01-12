/*
	!!3행 4열 짜리 2차원 int 배열의 행, 열의 합을 구하기

	int 3행 4열짜리 num배열을 선언하여 각방의 값을 1~9 사이의 난수로 초기화 한 후 
	각 방의 내용 및 행의 합계, 열이 합계를 출력하는 프로그램을 작성하시오.

	@2017.01.12 pm07:05
*/
#if 0
#include <stdio.h>
#include <stdlib.h>

int random(int);
void numReset(int(*)[4]);
void aryCalculator(int(*)[4]);

int main()
{
	int num[3][4];

	numReset(&num[0]);
	aryCalculator(&num[0]);
	
}

void aryCalculator(int (*num)[4])
{
	int i, j, sum;

	for (i = 0; i < 3; i++)
	{
		sum = 0;
		printf("%d행\t: ", i);
		for (j = 0; j < 4; j++)
		{
			printf("%4d", num[i][j]);
			sum += num[i][j];
		}
		printf("   \t%i 행의 합 : %d\n", i, sum);
	}

	printf("열의 합 : ");

	for (i = 0; i < 4; i++)
	{
		sum = 0;
		for (j = 0; j < 3; j++)
		{
			sum += num[j][i];
		}
		printf("%4d", sum);
	}
	printf("\n");
}

void numReset(int (*num)[4])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
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
