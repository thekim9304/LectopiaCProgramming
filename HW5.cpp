#include <stdio.h>

int inputKw();
void outputCharge(double outCha);

int main()
{
	double chargeAll, use, chargeLast;
	double duty;
	double chargeBasic = 660;
	double chargeKw = 88.5;

	use = inputKw();

	chargeAll = chargeBasic + (use * chargeKw);

	duty = chargeAll * (9.0/ 100.0);

	chargeLast = chargeAll + duty;

	outputCharge(chargeLast);
}

int inputKw()
{
	int kw;
	printf("전기 사용량을 입력하세요(kw) : ");
	scanf_s("%d", &kw);

	return kw;
}

void outputCharge(double outCha)
{
	printf("전기 사용요금은 %lf원 입니다.", outCha);
}