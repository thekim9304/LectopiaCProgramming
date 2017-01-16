/*
	!!숫자에 콤마(,) 추가하기

	정수로 입력된 숫자를 문자로 변환하여 출력하는 프로그램 작성
	입력되는 값은 1부터 20억 미만의 정수로 제한하며, 변환된 문자는 세자리 단위마다 
	콤마(,)를 표시한다.
	반복수행하며 음수 입력 시 종료

	@2017.01.13 pm06:31
*/
#if 0
#include <stdio.h>

int inputInt();
void myflush();
void exchangeChar(int, char*);

int main()
{
	int inputCost;
	char exChar[100];

	while (1)
	{
		inputCost = inputInt();

		if (inputCost < 0)
			break;

		exchangeChar(inputCost, exChar);

		printf(" %d -> %s\n\n", inputCost, exChar);
	}
}

void exchangeChar(int inputCost, char *exChar)  // ',' = 44
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
		else if(count > 0)
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

int inputInt()
{
	int input;

	printf("# 금액 입력 : ");

	while(1)
	{
		scanf("%d", &input);

		if (getchar() == '\n')
			break;

		myflush();

		printf("# 금액 입력 : ");
	}

	return input;
}

void myflush()
{
	while (getchar() != '\n')
		;
}
#endif