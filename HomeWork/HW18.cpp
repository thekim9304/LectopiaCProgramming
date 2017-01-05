#if 0
#include <stdio.h>

int input();
void outputCost(int, int);

int main()
{
	int age, count, cost, discount;
	int lastCost;

	printf("입장객의 나이를 입력하시오 : ");
	age = input();
	printf("입장객의 수를 입력하시오 : ");
	count = input();
	printf("\n");

	if (age <= 7)
		cost = 500;
	else if (age <= 13)
		cost = 700;
	else if (age <= 19)
		cost = 1000;
	else if (age <= 55)
		cost = 1500;
	else {
		cost = 500;
	}
	
	lastCost = cost * count;

	if (count >= 5)
		discount = (int)(lastCost * 0.1);
	else
		discount = 0;

	outputCost(lastCost, discount);
}

int input()
{
	int ret;

	scanf("%d", &ret);

	return ret;
}

void outputCost(int cost, int discount)
{
	printf("입장료 => %d원\n", cost);
	printf("할인금액 => %d원\n", discount);
	printf("결제금액 => %d원", cost - discount);
}
#endif
