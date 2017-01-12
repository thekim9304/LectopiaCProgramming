/*
	!!문자검색 프로그램(단일 검색)

	문자열 하나 문자 하나를 입력 받아 문자열중에서 문자가 포함되어 있는가를 검사하여 문자의
	위치를 출력하는 프로그램을 작성하시오.
	단, 문자열 내에 찾는 문자가 여러 개인 경우 첫 번째 위치만 리턴 함(단일 검색만 지원)
	검색 작업을 반복하며 입력 문자열로 "end"입력 시 종료하기

	@2017.01.12 am11:59
*/
#if 0
#include <stdio.h>
#include <string.h>

int inputChar(char*, char*);
int strcheck(char*, char);

int main()
{
	char word[100], inputWord, ret;

	while (1)
	{
		ret = inputChar(word, &inputWord);

		if (ret == 0)
			break;

		ret = strcheck(word, inputWord);

		if (ret >= 0)
			printf("\"%s\" 문자열 안에 '%c' 문자는 %d번 위치에 존재합니다.\n\n", word, inputWord, ret);
		else
			printf("\"%s\" 문자열 안에 '%c' 존재하지 않습니다.\n\n", word, inputWord);
	}
}

int strcheck(char *word, char inputWord)
{
	int i, strLength;

	strLength = strlen(word);

	for (i = 0; i < strLength; i++) 
	{
		if (word[i] == inputWord)
			return i;
	}
	return -1;
}

int inputChar(char *word, char *inputWord)
{
	printf("# 문자열을 입력하시오 : ");
	scanf("%s", word);
	
	if (strcmp(word, "end") == 0)
		return 0;

	printf("# 문자를 입력하시오 : ");
	scanf(" %c", inputWord);

	return 1;
}
#endif