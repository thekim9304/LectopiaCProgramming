#pragma waning(disable : 4996);
#include <stdio.h>
#include <string.h>

int main()
{
	char input[1000];
	int inLength, outLength, i;
	
	printf("*문자열 입력 : ");
	scanf("%s", input);

	inLength = strlen(input);
	outLength = inLength / 2;

	printf("[%*.*s...]", inLength, outLength, input);
}