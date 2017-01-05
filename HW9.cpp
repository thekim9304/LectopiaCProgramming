#include <stdio.h>

int input();

int main()
{
	int number;
	number = input();

	printf("입력된 값을 8진수로 %#o입니다. \n", number);
	printf("입력된 값을 16진수로 %#x입니다. \n", number);
}

int input()
{
	int ret;

	printf("정수값을 입력하세요. : ");
	scanf_s("%d", &ret);

	return ret;
}