/*
	!! 수도요금 계산 프로그램(switch~case문 사용)

	사용자 코드와 사용량을 입력 받아 수도요금을 게산하여 출력하자

	@2017.01.08 am11:58
*/

#if 0
#include <stdio.h>
#include <string.h>

int inputCapital(int*);
int calculatorCapital(int, int);
void outputResult(int, int, int);
int inputInt(char*, int);

int main()
{
	int userCode, useCount, result;

	useCount = inputCapital(&userCode);
	result = calculatorCapital(userCode, useCount);
	outputResult(userCode, useCount, result);
}

void outputResult(int type, int use, int result)
{
	char output[1000];

	switch (type)
	{
	case 1:
		strcpy(output, "가정용");
		break;
	case 2:
		strcpy(output, "상업용");
		break;
	case 3:
		strcpy(output, "공업용");
	}

	printf("\n\n# 사용자 코드 : %d(%s)\n", type, output);
	printf("# 사용량 : %d ton\n", use);
	printf("# 총수도요금 : %d원", result);
}

int calculatorCapital(int type, int use)
{
	int result;

	switch (type)
	{
	case 1:
		use *= 50;
		result = use + (use * (0.05));
		break;
	case 2:
		use *= 45;
		result = use + (use * (0.05));
		break;
	case 3:
		use *= 30;
		result = use + (use * (0.05));
		break;
	}

	return result;
}

int inputCapital(int *userCode)
{
	int useCount;

	*userCode = inputInt("* 사용자 코드를 입력 하시오(1:가정용/2:상업용/3:공업용) : ", 1);
	useCount = inputInt("* 사용량을 입력하시오(ton단위) : ", 2);
	

	return useCount;
}

int inputInt(char *msg, int n)
{
	int inputValue;
	if(n == 1)
	{
		while (1)
		{
			printf("%s", msg);
			scanf("%d", &inputValue);

			if (getchar() == '\n' && (inputValue > 0 && inputValue < 4))
				break;
		}
	}
	else
		while (1)
		{
			printf("%s", msg);
			scanf("%d", &inputValue);

			if (getchar() == '\n' && inputValue > 0)
				break;
		}
	

	return inputValue;
}

void myflush()
{
	while (getchar() != '\n')
		;
}
#endif