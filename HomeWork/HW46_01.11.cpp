/*
	!!짝,홀 구하기

	키보드로부터 시작 값과 끝 값을 입력 받고, 홀수를 구할 것인지 짝수를 구할 것인지를
	입력 받아 두 값 사이에 존재하는 홀수나 짝수를 출력하고 그 합을 구하여 출력하시오.
	단, 이때 끝 값이 시작 값 보다 작거나 같을 경우에는 다시 입력 받으며, 
	짝홀수 구분 시 e 나 o 문자이외의 문자 입력 시 재입력을 요구

	@2017.01.11 pm09:40	
*/
#if 0
#include <stdio.h>

void inputNumber(int*, int*);
char inputSelect(int*, int*);
void output(int*, int*, char);

int main()
{
	int numStart, numLast;
	char inputSelec;

	inputNumber(&numStart, &numLast);
	inputSelec = inputSelect(&numStart, &numLast);
	output(&numStart, &numLast, inputSelec);
}

void inputNumber(int *numStart, int *numLast)
{
	while (1)
	{
		printf("# 시작 값을 입력하시오 : ");
		scanf("%d", numStart);

		if (*numStart > 0 && getchar() == '\n')
			break;
	}
	while (1)
	{
		printf("# 끝 값을 입력하시오 : ");
		scanf("%d", numLast);

		if (*numLast > *numStart && getchar() == '\n')
			break;

		getchar();
	}
}

char inputSelect(int *numStart, int *numLast)
{
	char select;

	while (1)
	{
		printf("* %d~%d까지의 짝수의 합을 구할까요? 홀수의 합을 구할까요?(짝수:e/홀수:o) : ", *numStart, *numLast);
		scanf("%c", &select);

		if (select == 'e' || select == 'o')
			break;

		getchar();
	}

	return select;
}

void output(int *numStart, int *numLast, char select)
{
	int i, sum = 0;

	switch (select)
	{
	case 'e':
		if ((*numStart % 2) == 0)
		{
			printf("  %d~%d까지의 짝수(", *numStart, *numLast);
			for (i = *numStart; i <= *numLast; i += 2)
			{
				printf("%d ", i);
				sum += i;
			}
			printf("\b)의 합은 %d 입니다.", sum);
		}
		else
		{
			printf("  %d~%d까지의 짝수(", *numStart, *numLast);
			for (i = (*numStart + 1); i <= *numLast; i += 2)
			{
				printf("%d ", i);
				sum += i;
			}
			printf("\b)의 합은 %d 입니다.", sum);
		}
		break;
	case 'o':
		if ((*numStart % 2) == 0)
		{
			printf("  %d~%d까지의 홀수(", *numStart, *numLast);
			for (i = (*numStart + 1); i <= *numLast; i += 2)
			{
				printf("%d ", i);
				sum += i;
			}
			printf("\b)의 합은 %d 입니다.", sum);
		}
		else
		{
			printf("  %d~%d까지의 홀수(", *numStart, *numLast);
			for (i = *numStart; i <= *numLast; i += 2)
			{
				printf("%d ", i);
				sum += i;
			}
			printf("\b)의 합은 %d 입니다.", sum);
		}
		break;
	}
}
#endif