/*
	!!문자열 내의 숫자의 합 구하기

	문자열을 입력 받아 문자열 내의 숫자들의 총 합을 계산한다. (문자열의 길이는 99이하로 제한 함)
	예를 들어서 입력 받은 문자열이 "ab123@5f#4_31"이면 123+5+4+31을 계산하여 163을 출력 해준다.
	단, 양수 값 만을 인식한다는 전제하에서 프로그래밍 해보자
	반복 수행하고 "end" 입력 시 종료

	@2017.01.12 pm08:38
*/
#if 01
#include <stdio.h>
#include <string.h>
#include <math.h>

void inputString(char*);
int sNumCalculator(char*);
void outputResult(char*, int);
int tenCalcu(int);

int main()
{
	char inputS[100];
	int ret;

	while (1)
	{
		inputString(inputS);

		if (strcmp(inputS, "end") == 0)
			break;

		ret = sNumCalculator(inputS);

		outputResult(inputS, ret);
	}
}

void outputResult(char *inputS, int ret)
{
	printf("\"%s\" 내의 총 숫자는 [%d]입니다.\n\n", inputS, ret);
}

int sNumCalculator(char *inputS)
{
	int sum = 0, i, j, count;

	for (i = 0; i < strlen(inputS); i++)
	{
		if (inputS[i] >= '0' && inputS[i] <= '9')
		{
			count = 0;
			for (j = 1; j < strlen(inputS) - i; j++)
			{
				if (inputS[i + j] >= '0' && inputS[i + j] <= '9')
				{
					count++;
				}
				else
					break;
			}
			sum += (inputS[i] - '0') * pow(10, count);
		}
	}
	return sum;
}

void inputString(char *inputS)
{
	printf("# 문장을 입력하시오 : ");
	scanf("%s", inputS);
}

int tenCalcu(int count)
{
	int i, result = 1;

	if (count > 0)
	{
		for (i = 0; i < count; i++)
			result *= 10;

		return result;
	}
	else
		return 1;
}
#endif