/*
	!!회문(Palindrome) 검사 프로그램

	회문은 "level", "bob"과 같이 앞으로 읽으나 뒤로 읽으나 똑같은 단어들을 말한다.
	문자열이 회문인지 아닌지를 검사하는 함수를 작성하여 회문 검사 프로그램을 작성하자.
	반복 수행하고 "end" 입력 시 종료

	@2017.01.12 pm06:36
*/
#if 0
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void inputString(char*);
int testString(char*, int);
void outResult(char*, int);

int main()
{
	char inputS[100], sample[100];
	int strLength, ret;

	while (1)
	{
		inputString(inputS);

		if (strcmp(inputS, "end") == 0)
			break;

		strLength = strlen(inputS);
		strcpy(sample, inputS);

		ret = testString(inputS, strLength);

		outResult(inputS, ret);
	}
}

void outResult(char *inputS, int ret)
{
	if (ret == 1)
		printf("\"%s\" : 회문입니다!\n\n", inputS);
	else
		printf("\"%s\" : 회문이 아닙니다!\n\n", inputS);
}

int testString(char *inputS, int strLength)
{
	int i;

	for (i = 0; i < strLength / 2; i++)
	{
		if (tolower(inputS[i]) != tolower(inputS[(strLength - i) - 1]))
			return 0;
	}

	return 1;
}

void inputString(char *inputS)
{
	printf("# 단어 입력 : ");
	scanf("%s", inputS);
}
#endif