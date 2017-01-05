#include <stdio.h>
#include <string.h>
#pragma waning(disable : 4996);

int main()
{
	char nameFirst[1000], nameLast[1000];
	int getLengthF, getLengthL;

	printf("#성을 입력하시오 : ");
	scanf("%s", nameFirst);
	printf("#이름을 입력하시오 : ");
	scanf("%s", nameLast);

	getLengthF = strlen(nameFirst);
	getLengthL = strlen(nameLast);

	printf("%s %s\n", nameFirst, nameLast);
	printf("%*d %*d", getLengthF, getLengthF, getLengthL, getLengthL);
}

