#include <stdio.h>

int inputLength();
int hallEscapeDate(int);
void outputDate(int, int);

int main()
{
	int length, date;
	length = inputLength();

	date = hallEscapeDate(length);

	outputDate(length, date);
}

void outputDate(int length ,int date)
{
	double lengthD = length * 0.01;

	printf("%.2lf미터 깊이의 우물을 탈출하기 위해서는 %d일이 걸립니다.", lengthD, date);
}

int hallEscapeDate(int length)
{
	int i, date = 0;
	

	while (1)
	{
		if (length == 0)
			break;

		for (i = 0; i < 2; i++)
		{
			if (i == 0)
			{
				length -= 50;

				if (length <= 0)
				{
					date += 1;
					break;
				}
			}
			else
			{
				length += 20;

				if (length > 0)
					date += 1;
			}
		}
		if (length <= 0)
			break;
	}

	return date;
}

int inputLength()
{
	int input;

	printf("* 우물의 깊이를 입력하시오(cm단위) : ");
	scanf("%d", &input);

	return input;
}