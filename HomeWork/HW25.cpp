#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int random(int);
int inputNum();
int outputResult(int);

int main()
{
	int num, result = 0, count = 0;

	{
		srand((unsigned int)time(NULL));
		num = random(100) + 1;
	}

	result = outputResult(num);

	printf("우와~ 맞았당~~~ 추카추카~~ %d 번째 만에 맞추셨습니다.", result);
}

int outputResult(int random)
{
	int input, count = 0, max = 100, min = 0;

	while (1)
	{
		input = inputNum();

		count++;

		if (input == random)
			return count;
		else if (input < random)
		{
			min = input;
		}
		else if (input > random)
		{	
			max = input;
		}
		printf("%d 보다는 크고 %d 보다는 작습니다.\n", min, max);
	}
	
	return count;
}

int inputNum()
{
	int num, ret;

	while (1)
	{
		printf("# 숫자를 입력하시오 : ");
		ret = scanf("%d", &num);

		if (ret == 1)
		{
			if (num >= 1 && num <= 100)
				break;
			else
				printf("1 - 100 사이의 숫자를 입력 하시오 : \n");
		}
		else
		{
			printf("1 - 100 사이의 숫자를 입력 하시오 : \n");
			getchar();
		}
	}

	return num;
}

int random(int n)
{
	int ret;
	ret = rand() % n;
	return ret;
}