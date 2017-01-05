#include <stdio.h>

int main()
{
	double value = 365.2422;      // 주어진 값
	double oday = value;          // 일시분초 계산 용도
	int day, hour, minute;        // 일시분 저장 변수
	double second, sday;          // 초 저장 변수 , 남은 초 저장 변수

	sday = oday * 86400;          // 일을 초로 변환

	day = sday / 86400;           // 일 계산 
	sday = sday - (day * 86400);

	hour = sday / 3600;           // 시 계산
	sday = sday - (hour * 3600);

	minute = sday / 60;           // 분 계산
	sday = sday - (minute * 60);

	second = sday;                // 남은 초 대입

	printf("%.4lf일은 %d일 %d시간 %d분 %.2lf초 입니다.", value, day, hour, minute, second);
}