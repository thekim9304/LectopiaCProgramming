/*
	!!총 5개의 정수를 입력 받아 그 수의 합 출력하기

	정수는 반드시 양수 값 이어야 한다. 만약 0 이하의 수를 입력 받을 경우에는 입력으로
	인정하지 않고 다시 입력 받도록 한다.

	@2017.01.09 pm02:54
*/
#if 0
#include <stdio.h>

int main()
{
	int i, sum = 0, input;

	for (i = 1; i <= 5; i++)
	{
		printf("0보다 큰수를 입력하시오(%d 번째) : ", i);
		scanf("%d", &input);

		if (input <= 0)
		{
			i -= 1;
			continue;
		}
		sum += input;
	}

	printf("입력된 값의 총 합 : %d\n", sum);
}
#endif