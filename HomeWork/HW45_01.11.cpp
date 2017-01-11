/*
	!!소수(prime number)출력하기

	한 정수를 입력 받아 그 수까지의 모든 소수를 출력하는 프로그램을 작성하시오.
	단, 출력할 때 한 줄에 5개씩 출력하시오.

	@2017.01.11 pm10:49
*/
#if 0
#include <stdio.h>
#include <math.h>

int inputNum();
int primeNumber(int);
int output(int, int);

int main()
{
	int inpuNum, i, check, sum = 0, count = 0, enter = 0;

	inpuNum = inputNum();

	printf("1~%d까지의 소수 값은 다음과 같습니다.\n", inpuNum);

	for (i = 2; i <= inpuNum; i++)
	{
		check = primeNumber(i);
		
		if (check == 1)
		{
			count++;
			enter++;
		}
		sum += output(i, check);

		//if ((enter % 5) == 0)
		if (enter == 5)
		{
			printf("\n");
			enter = 0;
		}
	}
	printf("\n");
	printf("1~%d까지의 총 소수는 %d개 입니다.", inpuNum, count);
}

int output(int inpuNum, int ret)
{
	if (ret == 1)
	{
		printf("%-5d", inpuNum);

		return inpuNum;
	}
	return 0;
}

int primeNumber(int number)
{
	int i, j, count = 1;

	for (i = 2; i <= sqrt(number); i++)
	{
		if (!(number % i))
			count++;
	}

	if (count > 1)
		return 0;
	else
		return 1;
}

int inputNum()
{
	int iNum;

	while (1)
	{
		printf("*정수값 하나를 입력하시오 : ");
		scanf("%d", &iNum);

		if (iNum > 0 && getchar() == '\n')
			break;

		getchar();
	}
	return iNum;
}
#endif
