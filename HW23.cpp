#include <stdio.h>

int main()
{
	int num1, num2, ex1, ex2, ret;

	while (1)
	{
		printf("두 개의 정수를 입력 하세요 : ");
		ret = scanf("%d %d", &num1, &num2);

		if (ret == 2)
		{
			if (num1 <= num2)
			{
				ex1 = num2;
				ex2 = num1;
			}
			else
			{
				ex1 = num1;
				ex2 = num2;
			}
		}
		else
			break;

		printf("%d + %d = %d\n", ex1, ex2, ex1 - ex2);
	}
}