/*
	!!대칭되는 별찍기

	라인 수를 입력 받아 2중 for문을 이용하여 다음과 같이 출력하시오.
	반복수행하고 라인 수 입력란에서 문자 입력시 종료.
	단, 변수는 iterator변수 i, j 와 라인수 저장변수 1개 총 3개만 사용하여 작성 할 것. 

	@2017.01.11 pm08:59
*/
#if 0
#include <stdio.h>

int main()
{
	int i, j, inputNum;

	printf("# 출력 라인수를 입력하시오 : ");
	scanf("%d", &inputNum);

	while (getchar() == '\n')
	{
		for (i = inputNum; i >= 0; i--)
		{
			for (j = 0; j < (inputNum - i); j++)
				printf("*");
			for (j = 0; j <= (i * 2); j++)
				printf(" ");
			for (j = 0; j < (inputNum - i); j++)
				printf("*");
			printf("\n");
		}

		printf("# 출력 라인수를 입력하시오 : ");
		scanf("%d", &inputNum);
	}
}
#endif