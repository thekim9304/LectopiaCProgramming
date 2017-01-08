#include <stdio.h>

int inputAgg();

int main()
{
	int aggHeight, boxAdd = 0;

	while (1)
	{
		aggHeight = inputAgg();

		if (aggHeight > 500)
			printf("* 타조알 가지고 장난하지 마시오~ ^^\n");
		else if (aggHeight < 150)
			printf("* 메추리알 가지고 장난하지 마시오~ ^^\n");
		else
		{
			boxAdd++;
			printf("* 현재 달걀의 수 : %d \n", boxAdd);
			if (boxAdd == 10)
				break;
		}
	}
	printf("\n*** 달걀 포장이 끝났습니다.\n");
}

int inputAgg()
{
	int ret, input;

	while (1)
	{
		printf("# 계란의 무게를 입력하세요(단위 : g) : ");
		ret = scanf("%d", &input);

		if (ret == 1)
			break;
		else
		{
			printf("정수를 입력 하세요~ ^^\n");
			getchar();
		}
	}

	return input;
}