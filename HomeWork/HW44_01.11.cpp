/*
	!!구구단 출력하기

	구구단 2~9단을 한 화면에 다음과 같이 출력하되 2중 for문을 2set를 이용해서 한번 출력하고
	바로 이어서 3중 for문 1set만을 이용해서 똑같이 출력되도록 작성하시오

	@2017.01.11 pm09:17
*/
#if 0
#include <stdio.h>

int main()
{
	int i, j, k;

	printf("<2중 for문을 이용한 출력>\n");

	for (i = 1; i <= 9; i++)
	{
		for (j = 2; j <= 5; j++ )
			printf("%d * %d = %2d\t", j, i, j*i);

		printf("\n");
	}

	printf("\n\n");

	for (i = 1; i <= 9; i++)
	{
		for (j = 6; j <= 9; j++)
			printf("%d * %d = %2d\t", j, i, j*i);

		printf("\n");
	}

	printf("---------------------------------------------------------------------------------- \n\n");
	printf("<3중 for문을 이용한 출력>\n");

	for (i = 2; i <= 6; i += 4)
	{
		for (j = 1; j <= 9; j++)
		{
			for (k = i; k <= (i + 3); k++)
				printf("%d * %d = %2d\t", k, j, k * j);

			printf("\n");
		}
		printf("\n\n");
	}
}
#endif