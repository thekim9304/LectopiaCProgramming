/*
	!!피보나치 수열 구하기

	1항부터 제 N항까지 피보나치 수열의 합을 계산하여 출력하는 프로그램 작성
	피보나치 수열은 첫 번째 항과 두 번째 항을 더해서 세 번째 항을 만들고, 두 번째 항과 세 번째
	항을 더해서 네 번째 항을 만드는 방법으로 계속해서 다음 항을 만들어가는 수열이다.

	@2017.01.09 pm04:05
*/
#if 0
#include <stdio.h>

int main()
{
	int i, a = 1, b = 1, c, sum = 0, input, result = 0;

	printf("피보나치 수열의 항수를 입력하시오 : ");
	scanf("%d", &input);

	printf("1 + 1 + ");

	for (i = 0; i < input - 2; i++)
	{
		if(b == 1)
			sum = a + b;

		printf("%d + ", sum);
		result += sum;

		c = sum;

		sum = c + b;

		b = c;
	}

	printf("\b\b= %d", result + 2);
}
#endif