/*
	!!정해진 금액으로 물건구입하기

	입력 받은 현금 금액으로 동네 슈퍼에서 크림빵(500원), 새우깡(700원), 콜라(400원)를 사려한다.
	잔돈을 하나도 남기지 않고 이 세가지 물건을 구입한다면 각각 몇개씩 사야 하는가?
	단, 모든 품목을 한 개 이상은 꼭 구입하는 것으로 한다.
	(반복수행 후 금액 입력란에 문자 입력 시 종료.)

	@2017.01.09 pm05:05
*/
#if 0
#include <stdio.h>

int main()
{
	int haveMoney, costBread, costShrimp, costCola;
	int i, j, k;

	costBread = 500;
	costShrimp = 700;
	costCola = 400;

	printf("현재 당신의 소유 금액 입력 : ");
	scanf("%d", &haveMoney);

	while (getchar() == '\n')
	{
		for (i = 1; 1; i++)
		{
			if ((costBread * i) >= haveMoney)
				break;

			for(j = 1; 1; j++)
			{
				if (((costBread * i) + (costShrimp * j)) >= haveMoney)
					break;

				for (k = 1; 1; k++)
				{
					if (((costBread * i) + (costShrimp * j) + (costCola * k)) > haveMoney)
						break;

					if(((costBread * i) + (costShrimp * j) + (costCola * k)) == haveMoney)
						printf("크림빵(%d 개), 새우깡(%d 개), 콜라(%d 병)\n", i, j, k);
				}
			}
		}
		printf("어떻게 구입하시겠습니까? \n\n");

		printf("현재 당신의 소유 금액 입력 : ");
		scanf("%d", &haveMoney);
	}
}
#endif