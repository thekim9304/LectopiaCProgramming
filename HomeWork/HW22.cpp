#include <stdio.h>

int inputStar();

int main()
{
	int input, i = 0;

	input = inputStar();

	while (i < input)
	{
		printf("*");

		i++;

		if ((i % 5) == 0)
			printf("\n");
	}
}

int inputStar()
{
	int input, ret;
	
	while (1)
	{
		printf("# 정수값을 입력하세요 : ");
		ret = scanf("%d", &input);

		getchar();

		if (ret == 1)
			break;
	}
	return input;
}