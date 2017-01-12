/*
	!!문자열 첫 문자와 마지막 문자 출력하기

	다섯 개의 문자열을 입력 받아 char 5행 20열의 2차원 배열(배열명 : srt)에 순서대로 저장한 후,
	알파벳 순서대로(a~z순으로) sort 하여 문자열 전체, 첫 문자, 마지막 문자를 출력하자.

	@2017.01.12 pm07:37
*/
#if 0
#include <stdio.h>
#include <string.h>

void inputString(char(*)[20]);
void sort(char(*)[20]);
void outputString(char(*)[20]);

int main()
{
	char str[5][20];

	inputString(str);
	sort(str);
	outputString(str);
}

void outputString(char(*str)[20])
{
	int i;

	for (i = 0; i < 5; i++)
	{
		printf("str[%d] = %s  %c  %c\n", i, str[i], str[i][0], str[i][strlen(str[i]) - 1]);
	}
}

void sort(char(*str)[20])
{
	char swaping[20];

	int i, j;

	for (i = 0; i < 5 - 1; i++)
	{
		for (j = (i + 1); j < 5; j++)
		{
			if (strcmp(str[i], str[j]) > 0)
			{
				//swaping = dataArray[i];
				strcpy(swaping, str[i]);
				strcpy(str[i], str[j]);
				strcpy(str[j], swaping);
			}
		}
	}
}

void inputString(char(*str)[20])
{
	int i;

	for (i = 0; i < 5; i++)
	{
		printf("# %d번 문자열을 입력하시오 : ", i);
		scanf("%s", str[i]);
	}
}
#endif