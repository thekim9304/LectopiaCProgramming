/*
	!!히스토그램을 출력하기

	1이상 9이하의 정수를 N개 입력 받아 아래서 위로 올라가는 히스토 그램 구현
        *
        *
	    *
	*   *
	*   *
	*   *
	*   *
	* * *
	* * *
	6 2 9
  
	@2017.01.13 pm04:49
 */
#if 0
#include <stdio.h>
FILE * fileOpen(char*, char*);
int fileRead(FILE*, int*);
void outputHisto(int*, int);

int main(int argc, char *argv[])
{
	int testCnt, dataCnt, dataArray[100];
	int i, j, k, count;
	FILE *fp;

	fp = fileOpen("c:/data/hw63_histogram.txt", "rt");  

	if (fp == NULL)  
		return 1;

	fscanf(fp, "%d", &testCnt);  

	for (i = 0; i < testCnt; i++)
	{
		dataCnt = fileRead(fp, dataArray);

		outputHisto(dataArray, dataCnt);

		for (j = 0; j < dataCnt; j++)
		{
			printf("%d ", dataArray[j]);
		}
		printf("\n--------------------------------------------------------\n");
	}

	fclose(fp);

	return 0;
}

void outputHisto(int *dataArray, int dataCnt)
{
	int i, j, largeValue = 9;

	for (i = largeValue; i > 0; i--)
	{
		for (j = 0; j < dataCnt; j++)
		{
			if (dataArray[j] >= i)
				printf("* ");
			else
				printf("  ");
		}
		printf("\n");
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