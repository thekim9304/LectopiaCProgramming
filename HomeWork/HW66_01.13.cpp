/*
	!!문자열 숫자의 합 구하기

	문자열로 입력된 금액을 숫자로 변환하여 총합을 출력하는 프로그램 작성
	반복수행하며 "0000" 문자열 입력 시 종료하며 
	총합 출력 시 3자리 단위로 콤마(,)를 표시하여 출력하시오.

	@2017.01.15 pm10:02
*/
#if 0
#include <stdio.h>
#include <string.h>

void inputString(char*);
int exchangeInt(char*, int);
int tenCalcu(int);
void exchangeChar(int, char*);

int main()
{
	char inputS[100], outputS[100];
	int sizeString, excInt = 0;

	while (1)
	{
		inputString(inputS);

		if (strcmp(inputS, "0000") == 0)
			break;

		sizeString = strlen(inputS);

		excInt += exchangeInt(inputS, sizeString);
	}

	exchangeChar(excInt, outputS);

	printf("\n총합 : %s", outputS);
}

int exchangeInt(char *inputS, int size)
{
	int i, excInt = 0, count = 0;

	for (i = (size - 1); i >= 0; i--)  // 6 5 4 3 2 1 
	{
		if (inputS[i] == ',')
		{
			count++;
 			continue;
		}

		if (count == 0)
			excInt += (inputS[i] - 48) * tenCalcu(size - (i + 1));
		else
			excInt += (inputS[i] - 48) * tenCalcu(size - (i + 1 + count));
	}
	return excInt;
}

void exchangeChar(int inputCost, char *exChar)
{
	int i, j = 0, k = 0, save = 0, count = 0, exInt[100] = { 0 , };

	for (i = 1000000000; i >= 1; i /= 10)
	{
		if ((inputCost / i) >= 1)
		{
			save = inputCost / i;
			inputCost = inputCost - (save * i);
			exInt[j] = (save + 48);
			j++;

			if ((i == 1000000000) || (i == 1000000) || (i == 1000))
			{
				exInt[j] = 44;
				j++;
			}
			count++;
		}
		else if (count > 0)
		{
			exInt[j] = 48;
			j++;
		}
	}

	while (exInt[k] != 0)
	{
		exChar[k] = exInt[k];

		k++;
	}
	exChar[k] = '\0';
}

void inputString(char *inputS)
{
	printf("금액 입력 : ");
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