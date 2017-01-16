/*
	!!4*4 크기의 행열의 곱 계산하기

	4*4 크기의 A행렬과 B행렬의 곱을 계산하여 C배열에 저장한 후 A,B,C 배열의 내용을 출력하는
	프로그램을 작성하시오
	A, B배열의 내용은 미리 초기화 해놓고 프로그램을 작성하자.

	@2017.01.15 pm03:47
*/
#if 0
#include <stdio.h>

void aryCalculator(int (*)[4], int(*)[4], int(*)[4]);
void aryOutput(int(*)[4], int(*)[4], int(*)[4]);

int main()
{
	int aryA[4][4] = { {0, 1, 2, 3}, {1, -2, 1, 2}, {2, 5, -3, 2}, {0, -3, 1, 4} };
	int aryB[4][4] = { {1, -1, 2, 0},{1, -1, 1, 2}, {-1, 0, 3, 1}, {2, -1, 2, 8} };
	int aryC[4][4] = { 0 , };

	aryCalculator(aryA, aryB, aryC);

	aryOutput(aryA, aryB, aryC);
}

void aryCalculator(int (*aryA)[4], int (*aryB)[4], int (*aryC)[4])
{
	int i, j, k, sum = 0;

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			for (k = 0; k < 4; k++)
			{
				sum = aryA[i][k] * aryB[k][j];
				aryC[i][j] += sum; ;
			}
		}
	}
}

void aryOutput(int(*aryA)[4], int(*aryB)[4], int(*aryC)[4])
{
	int i, j, count;

	printf(" [Martix A]\t [Matrix B]\t [C = A * B]\n");

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%2d ", aryA[i][j]);
		}
		printf("\t");

		for (j = 0; j < 4; j++)
		{
			printf("%2d ", aryB[i][j]);
		}
		printf("\t");

		for (j = 0; j < 4; j++)
		{
			printf("%2d ", aryC[i][j]);
		}
		printf("\n");
	}
}
#endif