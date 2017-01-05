#include <stdio.h>

int inputF();
void outputC(double outCha);

int main()
{
	double valueF, valueC;
	
	valueF = inputF();

	valueC = 5.0 / 9.0 * (valueF - 32);

	outputC(valueC);
}

int inputF()
{
	int of;
	printf("화씨 온도를 입력하세요 : ");
	scanf_s("%d", &of);

	return of;
}

void outputC(double outC)
{
	printf("섭씨 온도는 %.1lf도 입니다.", outC);
}