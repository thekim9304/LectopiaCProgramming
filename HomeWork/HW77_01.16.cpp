/*
	!!주차요금 할인 받기

	@2017.01.17 am09:34
*/
#include <stdio.h>
#define COST_COUNT 3
#define TRUCK_TIME 6

FILE * fileOpen(char*, char*);
int fileRead(FILE*, int*, int);
int costCalculator(int*, int*);

int main(int argc, char *argv[])
{
	int testCnt, dataCnt, dataArray[100];
	int i, j, k, count, costCount[COST_COUNT], truckCount[TRUCK_TIME], costParking;
	FILE *fp;

	fp = fileOpen("c:/data/hw77_parking_info.txt", "rt");

	if (fp == NULL)
		return 1;

	fscanf(fp, "%d", &testCnt);  // 테스트 수

	for (i = 0; i < testCnt; i++)
	{
		for (j = 0; j < COST_COUNT; j++)
			fscanf(fp, "%d", &costCount[j]);
		/*
		for (j = 0; j < COST_COUNT; j++)
			printf("%d ", costCount[j]);

		printf("\n");
		*/
		for (k = 0; k < TRUCK_TIME; k++)
			fscanf(fp, "%d", &truckCount[k]);
		/*
		for (k = 0; k < TRUCK_TIME; k++)
			printf("%d ", truckCount[k]);
		printf("\n");
		*/

		printf("A 요금 : %d / B 요금 : %d / C 요금 : %d\n", costCount[0], costCount[1], costCount[2]);

		costParking = costCalculator(costCount, truckCount);

		printf("총 주차 요금 : %d\n", costParking);
		//dataCnt = fileRead(fp, dataArray, studentCount); // 학생 수
	}

	fclose(fp);

	return 0;
}

int costCalculator(int *costCount, int *truckCount)
{
	int i, j, costParking = 0, time = 0, saveTime[1000] = { 0, };

	for (j = 0; j < 5; j += 2)
	{
		for (i = truckCount[j]; i < truckCount[j + 1]; i++) 
		{
			saveTime[i]++;
		}
	}

	for (i = truckCount[0]; i < 1000; i++)
	{
		if (saveTime[i] == 1)
			costParking += (saveTime[i] * costCount[0]);
		else if (saveTime[i] == 2)
			costParking += (saveTime[i] * costCount[1]);
		else
			costParking += (saveTime[i] * costCount[2]);
	}
	/*for (i = truckCount[0]; i < truckCount[1]; i++)
	{
		if (i >= truckCount[2] && i < truckCount[3])
		{
			if (i >= truckCount[4] && i <= truckCount[5])
				costParking += (costCount[2] * 3);
			else
				costParking += (costCount[1] * 2);
		}
		else if (i >= truckCount[4] && truckCount[5])
			costParking += (costCount[1] * 2);
		else
			costParking += costCount[0];
	}

	if (truckCount[3] > truckCount[1])
	{
		for (i = truckCount[1]; i < truckCount[3]; i++)
		{
			if (i >= truckCount[4] && i <= truckCount[5])
				costParking += (costCount[1] * 2);
			else
				costParking += costCount[0];
		}
	}
	
	if (truckCount[5] > truckCount[1])
	{
		for (i = truckCount[5] - (truckCount[5] - truckCount[1]); i < truckCount[5]; i++)
			costParking += costCount[0];
	}*/

	return costParking;
}

FILE * fileOpen(char *filename, char *mode)
{
	FILE *fp;

	if ((fp = fopen(filename, mode)) == NULL)
		printf("File open error!\n");

	return fp;
}
#if 0
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