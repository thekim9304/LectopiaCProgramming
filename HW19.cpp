#if 1
#include <stdio.h>

int input();
int yearCheck(int);
void outputYear(int, int);

int main()
{
	int year;

	printf("년도를 입력하시오 : ");
	year = input();

	outputYear(year, yearCheck(year));
}

int input()
{
	int ret;

	scanf("%d", &ret);

	return ret;
}

int yearCheck(int year)
{
	int result;

	if ((year % 4) != 0)
		return 0;
	else if ((year % 100) != 0)
		return 1;
	else if ((year % 400) != 0)
		return 0;
	else
		return 1;
}

void outputYear(int year, int result)
{
	if (result == 1)
		printf("%d년은 윤년(Leap year)입니다.", year);
	else
		printf("%d년은 평년(Common year)입니다.", year);
}
#endif
