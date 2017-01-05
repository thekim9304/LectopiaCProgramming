#if 0
#include <stdio.h>

double input();
double bmiCalculator(double, double);
void output(double);

int main()
{
	double height, bmiV;
	int weight;

	printf("몸무게를 입력하세요(kg) : ");
	weight = input();

	printf("키를 입력하세요(m) : ");
	height = input();

	bmiV = bmiCalculator(weight, height);

	output(bmiV);
}

double input()
{
	double input;

	scanf("%lf", &input);

	return input;
}

double bmiCalculator(double a, double b)
{
	double bm;

	bm = a / (b * b);

	return bm;
}

void output(double out)
{
	if (out < 18.5)
		printf("당신의 BMI는 %.1lf으로 저체중입니다.", out);
	else if (out < 25.0)
		printf("당신의 BMI는 %.1lf으로 정상체중 입니다.", out);
	else if (out < 30.0)
		printf("당신의 BMI는 %.1lf으로 과체중 입니다.", out);
	else if (out < 40.0)
		printf("당신의 BMI는 %.1lf으로 비만 입니다.", out);
	else
		printf("당신의 BMI는 %.1;f으로 고도비만 입니다.", out);
}
#endif
