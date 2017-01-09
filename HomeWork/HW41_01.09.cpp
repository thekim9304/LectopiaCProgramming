/*
	!!0부터 99까지의 정수를 한 줄에 10개씩 수직으로 출력하기

	@2017.01.09 pm04:13
*/
#if 0
#include <stdio.h>

int main()
{
	int i, j;

	for (i = 0; i < 10; i++)
	{
		printf("%-3d", i);

		for (j = (i + 10); j < 100; j += 10)
			printf("%-4d", j);

		printf("\n");
	}
}
#endif