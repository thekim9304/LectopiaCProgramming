/*
	!!최소값, 최대값 찾기(1)

	임의의 숫자 5개를 키보드로부터 입력 받아서 배열에 저장한다.
	저장된 숫자 중에서 가장 큰 값과 작은 값을 찾아 출력하는 프로그램을 작성한다.
	일단 첫 번째 배열요소의 값이 가장 크다고(또는 작다고) 가정한 후에 이 값을 나머지 배열요소의 값들과 비교하면 된다.

	@2017.01.12 am09:18
*/
#if 0
#include <stdio.h>

void inputArray(double*);
double minCalculator(double*);
double maxCalculator(double*);
void outputMaxMin(double, double);

int main()
{
	double mmArray[5], max, min;

	inputArray(mmArray);
	max = maxCalculator(mmArray);
	min = minCalculator(mmArray);
	outputMaxMin(max, min);
}

void outputMaxMin(double max, double min)
{
	printf("\n가장 큰 값 : %.2lf\n", max);
	printf("가장 작은 값 : %.2lf\n", min);
}

double maxCalculator(double *mmArray)
{
	double storage;
	int i;

	storage = mmArray[0];

	for (i = 1; i < 5; i++)
	{
		if (storage < mmArray[i])
			storage = mmArray[i];
	}

	return storage;
}

double minCalculator(double *mmArray)
{
	double storage;
	int i;

	storage = mmArray[0];

	for (i = 1; i < 5; i++)
	{
		if (storage > mmArray[i])
			storage = mmArray[i];
	}

	return storage;
}

void inputArray(double *mmArray)
{
	int i = 0;

	for (i = 0; i < 5; i++)
	{
		printf("%d 번 방 값 : ", i);
		scanf("%lf", &mmArray[i]);

		if (getchar() != '\n')
		{
			i -= 1;
			continue;
		}
	}
	/*while (1)
	{	
		printf("%d 번 방 값 : ", i);
		scanf("%d", &mmArray[i]);

		i++;
	}*/
}
#endif