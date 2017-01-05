#include <stdio.h>

int main()
{
	double height, sum = 0;
	int i = 0;

	while (i < 5)
	{
		printf("- %d 번 학생의 키는? ", i + 1);
		scanf("%lf", &height);
		sum += height;
		i++;
	}

	sum /= 5;

	printf("다섯 명의 평균 키는 %.1lfcm 입니다.", sum);
}