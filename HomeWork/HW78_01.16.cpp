/*
	!!학생 줄 세우기



	@2017.01.16 @pm 09:34
*/
#include <stdio.h>

FILE * fileOpen(char*, char*);
int fileRead(FILE*, int*, int);
void lineChange(int*, int*, int);

int main(int argc, char *argv[])
{
	int testCnt, dataCnt, dataArray[100], aryStudent[100] = {0 , };
	int i, j, k, count, studentCount;
	FILE *fp;

	fp = fileOpen("c:/data/hw78_line.txt", "rt");

	if (fp == NULL)
		return 1;

	fscanf(fp, "%d", &testCnt);  // 반 수

	for (i = 0; i < testCnt; i++)
	{
		fscanf(fp, "%d", &studentCount);
		dataCnt = fileRead(fp, dataArray, studentCount); // 학생 수

		/*for (k = 0; k < dataCnt; k++)
		{
			aryStudent[k] = k + 1;
		}*/

		lineChange(aryStudent, dataArray, studentCount);

		printf("%i반 학생의 순서 출력 : ", i + 1);
		for (j = 0; j < studentCount; j++)
		{
			printf("%d ", aryStudent[j]);
		}
		printf("\n");
	}

	fclose(fp);

	return 0;
}

void lineChange(int *aryStudent, int *dataArray, int dataCnt)
{
	int i, j, k, save = 0;

	for (i = 0; i < dataCnt; i++)
	{
		if (dataArray[i] == 0)
			aryStudent[i] = i + 1;
		else
		{
			save = aryStudent[i - dataArray[i]];
			aryStudent[i - dataArray[i]] = i + 1;

			for (j = i; j > (i - dataArray[i]); j--)
				aryStudent[j] = aryStudent[j - 1];

			aryStudent[j + 1] = save;
		}
	}

	/*
	for (i = 0; i < dataCnt; i++)
	{
		if (dataArray[i] == 0)
			aryStudent[i] = i + 1;
		else
		{
			aryStudent[i] = aryStudent[i - dataArray[i]];

			for (j = (i - dataArray[i]); j < i; j++)
			{
				aryStudent[j] += 1;
				printf("%d", aryStudent[j]);
			}
		}
	}*/
}

FILE * fileOpen(char *filename, char *mode)
{
	FILE *fp;

	if ((fp = fopen(filename, mode)) == NULL)
		printf("File open error!\n");

	return fp;
}

int fileRead(FILE *fp, int *dataArray, int student)
{
	int dataCnt;

	for (dataCnt = 0; dataCnt < student; dataCnt++)
	{
		fscanf(fp, "%d", &dataArray[dataCnt]);
	}

	/*
	while (1)
	{
		fscanf(fp, "%d", &dataArray[dataCnt]);

		if (dataArray[dataCnt] == 0)
			break;
		dataCnt++;
	}
	*/
	return dataCnt;
}