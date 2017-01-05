#include <stdio.h>

int main()
{
	double km, kmH, second;
	int hour, minute;

	printf("* 거리를 입력하시오(km단위) : ");
	scanf_s("%lf", &km);
	printf("* 시속을 입력하시오(km/h단위) : ");
	scanf_s("%lf", &kmH);

	hour = (int)(km / kmH);
	minute = (int)(((km / kmH) - hour) * 60);
	second = ((((km / kmH) - hour) * 60) - minute) * 60;
	
	printf("%.3lfkm = >%d시간 %d분 %.3lf초 소요됨", km, hour, minute, second);
}