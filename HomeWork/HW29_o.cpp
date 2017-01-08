/*
	!!고집수

	양의 정수(10 ~ 9999)를 입력 받아, 각 자릿수를 분할하여 서로 곱합니다.
	그 곱한 수를 마찬가지로 각 자릿수로 분할해서 곱해 나갑시다.
	이러한 과정을 계속해 나가면 1의 자리수에 도달하게 되는데 이렇게 곱해 나가는 반복 횟수를 고집수라 한다.

	@2017.01.06 pm06:22
*/

//inputUInt 고쳐야함
#if 0
#include <stdio.h>

int inputUInt(char*);
int transNumber(int);
void myflush();

int main()
{
	int inputStart, inputLast, inputTerms, num, result;
	int countTerms , countLast = 0, memory;

	inputStart = inputUInt("시작 값(P1) : ");
	inputLast = inputUInt("끝 값(P2) : ");
	inputTerms = inputUInt("고집수(N) : ");

	while (inputStart <= inputLast)
	{
		memory = inputStart;
		countTerms = 0;

		while ((memory / 10) != 0)
		{
			memory = transNumber(memory);
			countTerms++;
		}
		if (countTerms == inputTerms)
		{
			printf("%d\n", inputStart);
			countLast++;
		}

		inputStart++;
	}
	printf("총 개수 : %d", countLast);
/*
	while (inputStart <= inputLast)
	{
		countTerms = 1;
		printf("1\n");
		while (1)
		{
			printf("2\n");
			if ((inputStart / 10) != 0)
			{
				 memory = transNumber(memory);
				 countTerms++;
			}
			else
				break;
		}
		
		if (countTerms == inputTerms)
		{
			printf("%d\n", &inputStart);
			countLast++;
		}
		inputStart++;
	}
	printf("총 개수 : %d", countLast);
	*/
}

int transNumber(int num)
{
	int thou, hund, ten, one, memory, result;

	if (num >= 1000)
	{
		thou = num / 1000;
		memory = num - (thou * 1000);
		
		hund = memory / 100;
		memory -= hund * 100;
		
		ten = memory / 10;
		memory -= ten * 10;

		one = memory;

		result = thou * hund * ten * one;
	}
	else if (num >= 100)
	{
		hund = num / 100;
		memory = num - (hund * 100);

		ten = memory / 10;
		memory -= ten * 10;

		one = memory;

		result = hund * ten * one;
	}
	else
	{
		ten = num / 10;
		memory = num - (ten * 10);

		one = memory;

		result = ten * one;
	}

	return result;
}

// 음수 입력시 버그 있음   (버퍼 개념)
int inputUInt(char *message)
{
	int num;

	while (1)
	{
		printf("%s", message);
		scanf("%d", &num);

		if (num > 0)
				break;

		myflush();
	}

	return num;
	
/*
	while (1)
	{
		printf("# 양의 정수를 입력 하시오(100 ~ 9999) : ");
		ret = scanf("%d", &input);

		if (ret == 1)
		{
			if ((input >= 100) && (input <= 9999))
				break;
			else
				printf("정수 범위를 지켜서 다시 입력 하시오.\n");
		}
		else
		{
			printf("정수를 입력 하세요~ ^^\n");
			getchar();
		}
	}
*/
}

void myflush()
{
	while (getchar() != '\n')
		;
}
#endif