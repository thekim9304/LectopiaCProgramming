/*
	!!누승 함수 만들기

	정수 값을 n승하는 함수와 실수 값을 n승하는 함수를 작성하시오.(반환 값은 n승의 결과)
	단, 0의 어떤 승도 0이고, 어떤 수의 0승은 항상 1이며, 밑은 양수값으로 제한하며, 양수승만 구하는 것으로 제한 함.

	@2017.01.07 pm08:03
*/

#if 0
#include <stdio.h>

int inputUInt(char*);
double inputDouble(char*);
int ipow(int, int);
double fpow(double, int);

int main()
{
	int N, numI;
	double numD, nD;

	numI = inputUInt("* 양의 정수 밑을 입력 하시오 : ");
	printf("* 양의 승을 입력 하시오 : ");
	scanf("%d", &N);
	printf("%d의 %d승은 %d입니다. \n\n",numI, N,ipow(numI, N));

	numD = inputDouble("* 양의 실수 밑을 입력 하시오 : ");
	printf("* 양의 승을 입력 하시오 : ");
	scanf("%d", &N);
	printf("%.2lf의 %d승은 %.3lf 입니다.",numD, N, fpow(numD, N));
}

int inputUInt(char *msg)
{
	int ret;

	printf("%s", msg);
	scanf("%d", &ret);

	return ret;
}

double inputDouble(char *msg)
{
	double ret;

	printf("%s", msg);
	scanf("%lf", &ret);

	return ret;
}

int ipow(int num, int N)
{
	int i, result = 1;

	if (N != 0)
	{
		for (i = 0; i < N; i++)
			result *= num;

		return result;
	}

	return 0;
}

double fpow(double num, int N)
{
	int i;
	double result = 1.0;

	if (N != 0)
	{
		for (i = 0; i < N; i++)
			result *= num;

		return result;
	}

	return 0.0;
}
#endif