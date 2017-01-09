/*
	!!황금 동전

	왕은 그의 충성스러운 기사에게 금화를 주기로 했다.
	- 첫 째 날 기사는 금화 한닢을 받았다.
	- 2,3 일째는 금화 두 닢을 받았다.
	- 4,5,6 일째는 금화 세 닢을 받았다.
	...
	1 2 2 3 3 3 4 4 4 4 5 5 5 5 5 ...
	날 수가 주어질 때 첫 날부터 받은 총 금화의 수를 구하라

	@2017.01.09 pm03:51
*/
#if 0
#include <stdio.h>

int main()
{
	int i, j, sum = 0, input, count = 0;

	printf("* 기사의 근무일수를 입력하시오 : ");
	scanf("%d", &input);

	for (i = 1; i <= input; i++)
	{
		for (j = 1; j <= i; j++)
		{
			count++;

			if (count <= input)
				sum += i;
		}
	}

	printf("근무일 : %d일 / 총 금화 수 %d 개\n", input, sum);
}
#endif