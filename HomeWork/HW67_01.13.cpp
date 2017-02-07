/*
	!! ���� �ٸ� ���� ���� �����ϱ�

	n���� ���� �Է����� �޾� ���� �ٸ� ���� ������ ���ϴ� ���α׷�

	@2017.01.14 pm05:38
*/
#if 1
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
		resultOutput(countNum); // 이런건 함수 call 하면서 왓다갓다 하는게 더 비효율적임 그냥 안으로~
	}
}

void resultOutput(int count)
{
	printf(" ���� �ٸ� ���� ���� : %d\n\n", count);
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

	printf("* ���� �Է� : ");

	for (i = 0; i < cnt; i++)
	{
		ret = scanf("%d", &num[i]);
	}
}

int inputCount()
{
	int input, ret;

	printf("* �Է��� ������ ���� : ");
	ret = scanf("%d", &input);

	if (ret == 0) // 비종료명시
		return -1;

	return input;
}
#endif
