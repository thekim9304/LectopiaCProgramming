/*
	!!문자 검색 프로그램(다중 검색)

	HW53의 기능을 확장하여 문자열 내에 찾는 문자가 여러 개인 경우 모든 위치를 출력하는 프로그램 작성

	@2017.01.12 pm02:58
*/
#if 0
#include <stdio.h>
#include <string.h>

int inputChar(char*, char*);
int strcheck(char*, char);

int main()
{
	char word[100], inputWord, ret;
	int strLength, i, count;

	while (1)
	{
		count = 0;

		ret = inputChar(word, &inputWord);

		if (ret == 0)
			break;

		printf("\"%s\" 문자열 안에 '%c' 문자는 ", word, inputWord);

		strLength = strlen(word);

		for (i = 0; i < strLength; i++)
		{
			ret = strcheck(&word[i], inputWord);
			if (ret == 1)
			{
				printf("%d번 위치에 ", i);
				count++;
			}
		}

		if (count > 0)
		{
			printf("존재합니다.\n\n");
			
		}
		else
			printf("존재하지 않습니다.\n\n");
	}

#if 0
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
#endif
}

int strcheck(char *word, char inputWord)
{
	int i;

	if (*word == inputWord)
		return 1;
	
	return -1;
#if 0
	int i, strLength;

	strLength = strlen(word);

	for (i = 0; i < strLength; i++)
	{
		if (word[i] == inputWord)
			return i;
	}
	return -1;
#endif
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