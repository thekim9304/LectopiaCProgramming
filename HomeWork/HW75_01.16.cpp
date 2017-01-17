/*
	!!야구게임 만들기

	컴퓨터가 랜덤으로 정한 4자리의 숫자를 알아 맞추는 게임 작성

	@2017.01.17 am11:46
*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#define TRUE 1
#define FALSE 0

int random(int n);
int ballCountCheck(char *, char *, int *);
void randCreat(char *);
int randCheck(char *, int);
void randM(char *);
void outputResult(int, int*);
void baseBallGame(char*, char*, int*);

int main()
{
	int i, countRound = 0, ballCount[2] = { 0, }, ret;
	char input[4], rand[4];

	randM(rand);
	
	baseBallGame(rand, input, ballCount);
}

void baseBallGame(char *rand, char *input, int *ballCount)
{
	int ret, i, countRound = 0;

	while (1)
	{
		countRound++;
		printf("# %d차 : ", countRound);

		for (i = 0; i < 4; i++)
		{
			input[i] = _getche();
			if (input[i] == ' ')
				i--;
		}

		ret = ballCountCheck(rand, input, ballCount);

		outputResult(ret, ballCount);

		if (ballCount[0] == 4 || countRound == 10)
			break;

	}
}

void outputResult(int ret, int *ballCount)
{
	if (ret == FALSE)
		printf("   No!\n");
	else if (ballCount[0] == 4)
	{
		printf("   OK!!!\n");
	}
	else
		printf("   %dS %dB\n", ballCount[0], ballCount[1]);
}

int ballCountCheck(char *rand, char *input, int *ballCount)
{
	int i, j;

	ballCount[0] = 0;
	ballCount[1] = 0;

	for (i = 0; i < 4; i++)
	{
		if (rand[i] == (input[i] - '0'))
			ballCount[0]++;

		for (j = 0; j < 4; j++)
		{
			if (i == j)
				continue;

			if (rand[i] == (input[j] - '0'))
				ballCount[1]++;
		}
	}

	if ((ballCount[0] == 0) && (ballCount[1] == 0))
		return FALSE;

	return TRUE;
}

void randM(char *rand)
{
	int i;

	for (i = 0; i < 4; i++)
	{
		srand((unsigned int)time(NULL));
		randCreat(rand);
	}
	for (i = 0; i < 4; i++)
		printf("%d  ", rand[i]);

	printf("\n");
}

void randCreat(char *rand)
{
	int i, ret;

	for (i = 0; i < 4; i++)
	{
		rand[i] = random(9) + 1;

		ret = randCheck(rand, i);

		if (ret == FALSE)
		{
			i--;
			continue;
		}
	}
}

int randCheck(char *rand, int count)
{
	int i;

	for (i = (count - 1); i >= 0; i--)
	{
		if (rand[count] == rand[i])
			return FALSE;
	}
	return TRUE;
}

int random(int n)
{
	int ret;
	ret = rand() % n;
	return ret;
}