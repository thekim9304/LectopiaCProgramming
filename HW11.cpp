#include <stdio.h>
#pragma waning(disable : 4996);

int main()
{
	int input;

	printf("ASCII code값을 입력하시오 : ");
	scanf("%d", &input);

	printf("%d은 '%c'의 ASCII code 입니다.", input, input);
}
