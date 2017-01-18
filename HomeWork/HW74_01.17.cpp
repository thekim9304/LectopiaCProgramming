/*
	!!Jolly Jumper

	@2017.01.18 pm11:42
*/
#if 1
#include <stdio.h>

FILE * fileOpen(char*, char*);
void fileRead(FILE*, int*, int);
int jollyCalculator(int*, int);
int absoluteValue(int);

int main()
{
	int testCnt, dataCnt = 0, dataArray[100];
	int i, j, ret, count;
	FILE *fp;

	fp = fileOpen("c:/data/hw74_jolly.txt", "rt");

	if (fp == NULL)
		return 1;

	fscanf(fp, "%d", &testCnt);  // 테스트 수

	for (i = 0; i < testCnt; i++)
	{
		fscanf(fp, "%d", &dataCnt);

		fileRead(fp, dataArray, dataCnt);

		printf("검사한 수열 : ");
		for(j = 0; j < dataCnt; j++)
			printf("%d ", dataArray[j]);

		ret = jollyCalculator(dataArray, dataCnt);

		if (ret == 0)
			printf(" (Not jolly jumper)\n");
		else
			printf(" (jolly jumper)\n");
	}
}

int jollyCalculator(int *dataArray, int count)
{
	int i, j, k, temp[100], data[100] = { 0, };

	for(i = 0; i < count; i++)
		data[i] = absoluteValue(dataArray[i]);

	for (i = 0; i < count - 1; i++)
	{
		temp[i] = data[i] - data[i + 1];

		temp[i] = absoluteValue(temp[i]);
	}

	for (i = 0; i < count - 1; i++)
	{
		for (k = 0; k < count; k++)
		{
			if (i == k)
				continue;

			if (temp[i] == temp[k])
				return 0;
		}

		for (j = 0; j < count; j++)
		{
			if (j == i)
				continue;
			
			
			if ((temp[i] - 1) == temp[j])
				break;
			else if ((temp[i] + 1) == temp[j])
				break;
		}
		if (j == count)
			return 0;
	}
	return 1;
}


int absoluteValue(int a)
{
	if (a > 0)
		return a;
	else
		return -a;
}

FILE * fileOpen(char *filename, char *mode)
{
	FILE *fp;

	if ((fp = fopen(filename, mode)) == NULL)
		printf("File open error!\n");

	return fp;
}

void fileRead(FILE *fp, int *dataArray, int count)
{
	int i;

	for (i = 0; i < count; i++)
	{
		fscanf(fp, "%d", &dataArray[i]);
	}
}
#endif // 1
