/*
	!!string 제어 함수 만들기

	@2017.01.17 pm06:58
*/
#include <stdio.h>
#include <string.h>

char* ustrchr(char*, int);
char* ustrcat(char*, char*);
char* ustrstr(char*, char*);
void ustrcpy(char*, char*);
unsigned int ustrlen(char*);
int ustrcmp(char*, char*);

int main()
{
	char *chrtest;
	char test1[100] = "HelloWorld";
	int strlength, ret;

	chrtest = ustrchr(test1, 'W');
	printf("%c\n", *chrtest);

	chrtest = ustrcat(test1, "Korea");
	printf("%s\n", chrtest);

	ustrcpy(test1, "HelloWorld");
	printf("%s\n", test1);

	chrtest = ustrstr(test1, "llo");
	printf("%s\n", chrtest);

	strlength = ustrlen(test1);
	printf("%d\n", strlength);

	ret = ustrcmp(test1, "HelloWorld");
	printf("%d\n", ret);

	ret = ustrcmp(test1, "AelloWorld");
	printf("%d\n", ret);

	ret = ustrcmp(test1, "helloWorld");
	printf("%d\n", ret);
}

char* ustrchr(char *str, int ch)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] == ch)
			return &str[i];

		i++;
	}

	return NULL;
}

char* ustrcat(char *str, char *operand)
{
	int i = 0, j = 0;

	while (str[i] != '\0')
	{
		i++;
	}

	while (operand[j] != '\0')
	{
		str[i] = operand[j];

		i++;
		j++;
	}

	str[i] = '\0';
	return str;
}

char* ustrstr(char *str, char *operand)
{
	int i = 0, j, k;

	while (str[i] != '\0')
	{
		if (str[i] == operand[0])
		{
			k = i;
			j = 0;
			while (operand[j] != '\0')
			{
				if (str[k] == operand[j])
				{
					k++;
					j++;
				}
				else if(str[k] != operand[j])
					break;
			}
			if (operand[j] == '\0')
				return &str[i];
		}
		i++;
	}

	return NULL;
}

int ustrcmp(char *str, char *operand)
{
	int i = 0;

	do
	{
		if (str[i] > operand[i])
			return 1;
		else if (str[i] < operand[i])
			return -1;
		else if (str[i] == operand[i])
			continue;
	} while (str[i] == '\0' || operand[i] == '\0');

	return 0;
}

unsigned int ustrlen(char *str)
{
	int i = 0;

	while (str[i] != '\0')
		i++;

	return i;
}

void ustrcpy(char *str, char *operand)
{
	int i = 0;

	while (operand[i] != '\0')
	{
		str[i] = operand[i];

		i++;
	}

	str[i] = '\0';
}
