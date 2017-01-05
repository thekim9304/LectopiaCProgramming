#pragma waning(disable : 4996);
#include <stdio.h>

int main()
{
	int num1, num2, num3, sum;
	double ave;

	printf("역사, 문학, 예능 점수를 입력하세요 : ");
	scanf("%d %d %d", &num1, &num2, &num3);

	sum = num1 + num2 + num3;
	ave = sum / 3.0;

	printf("총점은 %d이고 평균은 %.2lf입니다.", sum, ave);
}
