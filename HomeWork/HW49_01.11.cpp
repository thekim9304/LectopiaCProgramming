/*
	!!doubles

	일련의 수열이 주어질 때 각 원소의 2 배가 되는 값이 수열 내에 존재하면 몇 개가 존재하는 가를
	구하는 프로그램을 작성 하시오

	@2017.01.12 pm03:26
*/
#if 0
#include <stdio.h>
FILE * fileOpen(char*, char*);
int fileRead(FILE*, int*);

int main(int argc, char *argv[])
{
	int testCnt, dataCnt, dataArray[100];
	int i, j, k, count;
	FILE *fp;

	fp = fileOpen("c:\\data\\hw49_number_list.txt", "rt");

	if (fp == NULL)
		return 1;

	fscanf(fp, "%d", &testCnt);

	for (i = 0; i < testCnt; i++)
	{
		count = 0;
		dataCnt = fileRead(fp, dataArray);

		printf("# 수열 : ");
		for (j = 0; j < dataCnt; j++)
		{
			for (k = 0; k < dataCnt; k++)
			{
				if ((dataArray[j] * 2) == dataArray[k])
					count++;
			}

			printf("%d ", dataArray[j]);
		}
		printf("\n 2배 값이 존재하는 원소의 개수는 %d 개 입니다.\n\n", count);
	}
	fclose(fp);

	return 0;
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