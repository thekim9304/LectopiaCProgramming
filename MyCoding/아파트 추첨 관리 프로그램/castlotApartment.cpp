#include "queue.h" 
#include <stdio.h> 
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <ctime>

#define Grade(i) "c:\\data\\grade"#i".txt"

void readAwaiter(Queue *awaiter, int countGrade); // 추첨 대기자 읽기
int castLot(Queue *awaiter, Queue *winner);  // 당첨자 추첨
void saveWinner(Queue *winner);  // 당첨자 목록 files
//--------------------------------------------------------------------------------
//   main() 
//--------------------------------------------------------------------------------
int main() 
{ 
	Queue awaiter;
	Queue winner;
	Queue outputWinner;
	int countGrade = 3;
	int i, winnerNum;

	awaiter.front = 0;
	awaiter.rear = 0;
	awaiter.qSize = 0;

	printf("아파트 추첨 수를 입력 하시오 : ");
	scanf("%d", &winnerNum);

	initQueue(&winner, winnerNum + 1);

	for (i = 0; i < countGrade; i++)
	{
		readAwaiter(&awaiter, i);
		castLot(&awaiter, &winner);

		if (isQueueFull(&winner) == TRUE)
			break;
	}

	outputWinner.front = 0;
	outputWinner.rear = 0;
	outputWinner.qSize = 0;

	saveWinner(&winner);
	readAwaiter(&outputWinner, 201214030);

	printf("[  No.   당첨자명\t\t주민번호\t\t연락처\t\t]\n\n");
	for (i = 0; i < outputWinner.qSize - 1; i++)
	{
		printf("   %d.\t", i + 1);
		printWinner(&outputWinner.queue[i]);
		printf("\n");
	}

	destroyQueue(&winner);
	destroyQueue(&outputWinner);
} 

int castLot(Queue *awaiter, Queue *winner)
{
	int count, rand , i, j = 0;
	DataType save;

	rand = 10;

	srand((unsigned int)time(NULL));

	while (j < awaiter->qSize - 1)
	{
		if (isQueueFull(winner) == TRUE)
			break;

		count = random(rand) + 1;

		for (i = 1; i < count - 1; i++)
		{
			dequeue(awaiter, &save);
			enqueue(awaiter, save);
		}

		dequeue(awaiter, &save);
		enqueue(winner, save);

		j++;
		//if (isQueueFull(winner) == TRUE)
		//	break;
	}

	destroyQueue(awaiter);

	return 0;
}

void readAwaiter(Queue *awaiter, int countGrade)
{
	FILE *fp;
	int i = 1;
	if ((countGrade + 1) == 1)
		fp = fopen(Grade(1), "rt");
	else if ((countGrade + 1) == 2)
		fp = fopen(Grade(2), "rt");
	else if ((countGrade + 1) == 3)
		fp = fopen(Grade(3), "rt");
	else
		fp = fopen("c:\\data\\win.txt", "rt");
	assert(fp != NULL);
	DataType inData;
	char name[20];   // 성명 저장
	char since[20];
	char phone[20];  // 핸드폰 번호 저장

	awaiter->queue = NULL;

	while (fgets(name, sizeof(name), fp) != NULL)
	{
		name[strlen(name) - 1] = '\0';

		fgets(since, sizeof(since), fp);
		since[strlen(since) - 1] = '\0';

		fgets(phone, sizeof(phone), fp);
		phone[strlen(phone) - 1] = '\0';
		strcpy(inData.name, name);
		strcpy(inData.phone, phone);
		inData.since = exchangeInt(since, strlen(since));

		awaiter->qSize = i + 1;
		awaiter->rear = i;
		awaiter->queue = (DataType *)realloc(awaiter->queue, (sizeof(DataType) * (i + 1)));
		assert(awaiter->queue != NULL);
		awaiter->queue[i - 1] = inData;

		i++;
	}

	fclose(fp);
}

void saveWinner(Queue *winner) // 리스트내의 모든 데이터를 파일에 저장 
{
	int i;
	DataType save;
	FILE *fp;
	fp = fopen("c:\\data\\win.txt", "wt");
	assert(fp != NULL);

	
	//lp->cur = lp->head->next;
	/*while (lp->cur != lp->tail)
	{
		fprintf(fp, "%s %d\n", lp->cur->data.name, lp->cur->data.age);
		lp->cur = lp->cur->next;
	}*/
	for (i = 0; i < winner->qSize - 1; i++)
	{
		save = winner->queue[i];

		fputs(save.name, fp);
		fputs("\n", fp);
		fprintf(fp, "%d\n", save.since);
		fputs(save.phone, fp); 
		fputs("\n", fp);
	}

	fclose(fp);
}

void printWinner(DataType *p)
{
	printf(" %-10s\t     %d-******* \t     %s\b\b\b\b****",p->name, p->since, p->phone);
}

int exchangeInt(char *inputS, int size)
{
	int i, excInt = 0, count = 0;
	for (i = (size - 1); i >= 0; i--)  // 6 5 4 3 2 1 
	{
		if (inputS[i] == ',')
		{
			count++;
			continue;
		}
		if (count == 0)
			excInt += (inputS[i] - 48) * tenCalcu(size - (i + 1));
		else
			excInt += (inputS[i] - 48) * tenCalcu(size - (i + 1 + count));
	}
	return excInt;
}

int tenCalcu(int count)
{
	int i, result = 1;
	if (count > 0)
	{
		for (i = 0; i < count; i++)
			result *= 10;
		return result;
	}
	else
		return 1;
}

int random(int n)
{
	int ret;
	ret = rand() % n;
	return ret;
}
