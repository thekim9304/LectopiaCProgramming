/*
	!!정수 값 소트 프로그램(1 차원 배열사용)

	hw56_sortData.txt 파일 내의 임의의 개수의 정수를 입력 받아 오름차순으로 정렬하는 프로그램을 작성 하시오.

	@2017.01.12 pm06:05
*/
#if 0
#include <stdio.h>
FILE * fileOpen(char*, char*);
int fileRead(FILE*, int*);
void sort(int*, int);

int main(int argc, char *argv[])
{
	int testCnt, dataCnt, dataArray[100];
	int i, j, k, count;
	FILE *fp;

	fp = fileOpen("c:/data/hw56_sortData.txt", "rt");

	if (fp == NULL)
		return 1;

	fscanf(fp, "%d", &testCnt);

	for (i = 0; i < testCnt; i++)
	{
		dataCnt = fileRead(fp, dataArray); // 데이터 개수
		
		printf("# 소트 전 데이터 : ");
		for (j = 0; j < dataCnt; j++)
		{
			printf("%d ", dataArray[j]);
		}
		printf("\n");

		sort(dataArray, dataCnt);

		printf("# 소트 후 데이터 : ");
		for (j = 0; j < dataCnt; j++)
		{
			printf("%d ", dataArray[j]);
		}
		printf("\n\n");
	}

	fclose(fp);

	return 0;
}

void sort(int *dataArray, int dataLength)
{
	int i, j, swaping;

	for (i = 0; i < (dataLength - 1); i++)
	{
		for (j = (i + 1); j < dataLength; j++)
		{
			if (dataArray[i] > dataArray[j])
			{
				swaping = dataArray[i];
				dataArray[i] = dataArray[j];
				dataArray[j] = swaping;
			}
		}
	}
}

FILE * fileOpen(char *filename, char *mode)
{
	FILE *fp;

	if ((fp = fopen(filename, mode)) == NULL)
		printf("File open error!\n");

	return fp;
}

int fileRead(FILE *fp, int *dataArray)
{
	int dataCnt = 0;

	while (1)
	{
		fscanf(fp, "%d", &dataArray[dataCnt]);

		if (dataArray[dataCnt] == 0)
			break;
		dataCnt++;
	}

	return dataCnt;
}
#endif