/*
	!!컴퓨터와 빙고게임

	@2017.01.22 pm09:09
*/

#if 01 
#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>

int mainMenu();

void makeAllocI(char**, int);
void deleteAllocI(char**, int);

void playIndividual();
void playConfrontation();

int inputNumber(char**, int*, int, int*);
void inputNumberC(char **, char **, int, int);
int checkLine(char**, int);

void outputNumberU(char*, int);
void outputNumberC(char*, int);

void makeRandS(char**, int*, int);
int makeRand(int, int*);
int random(int);

int main()
{
	mainMenu();
}

int mainMenu()
{
	int inputMenu;

	while (1)
	{
		//my5x5 = (char**)malloc(sizeof(char*) * 5);
		//computer5x5 = (char**)malloc(sizeof(char*) * 5);

		printf("1. 연습게임(개인 연습용)\n");
		printf("2. 대전게임(컴퓨터와 대전용)\n");
		printf("3. 종료\n\n");
		printf("# 메뉴선택 : ");
		scanf("%d", &inputMenu);

		switch (inputMenu)
		{
		case 1:
			printf("\n연습용 빙고게임을 시작합니다.\n\n");
			playIndividual();
			break;
		case 2:
			playConfrontation();
			break;
		case 3:
			return NULL;
		}
	}
}


int checkLine(char **myBingo, int input)
{
	int i, j, count = 0;

	for (i = 0; i < input; i++)
	{
		for (j = 0; j < input; j++)
		{
			if (myBingo[i][j] != 'X')
				break;
			else if(j == input - 1)
				count++;
		}
	}

	for (i = 0; i < input; i++)
	{
		for (j = 0; j < input; j++)
		{
			if (myBingo[j][i] != 'X')
				break;
			else if (j == input - 1)
				count++;
		}
	}

	for (i = 0; i < input; i++)
	{
		if (myBingo[i][i] != 'X')
			break;
		else if (i == input - 1)
			count++;
	}

	for (i = 0; i < input; i++)
	{
		if (myBingo[i][(input - 1) - i] != 'X')
			break;
		else if (i == input - 1)
			count++;
	}

	return count;
}

int inputNumber(char **myBingo, int *t, int input, int *num)
{
	int i, j;

	printf("# 지울 숫자 입력(1 ~ %d) : ", input * input);
	scanf("%d", num);

	for (i = 0; i < input; i++)
	{ 
		for (j = 0; j < input; j++)
		{
			if (t[*num - 1] == 1)
			{
				printf("*이미 지워진 숫자 입니다. 다시 입력하세요.");
				return NULL;
			}

			if (myBingo[i][j] == *num)
			{
				myBingo[i][j] = 'X';
				t[*num - 1] = 1;
				return 1;
			}
		}
	}
}

void inputNumberC(char **myBingo, char **computerBingo, int input, int num)
{
	int ran, i, j, count = 0;
	
	while (1)
	{
		count = 0;
		ran = random(input * input) + 1;

		for (i = 0; i < input; i++)
		{
			for (j = 0; j < input; j++)
			{
				if (computerBingo[i][j] == ran)
				{
					computerBingo[i][j] = 'X';
					count++; 
				}
				if (myBingo[i][j] == ran)
					myBingo[i][j] = 'X';
			}	
		}

		if (count > 0)
		{
			printf("# 컴퓨터가 선택한 숫자는 (%d)입니다. \n\n", ran);
			break;
		}
	}
}

void playIndividual()
{
	int i, j, input, ret = 1, countLine = 0, num;
	static int count[1000], t[1000];
	char **myBingo;

	printf("# 빙고판의 가로,세로 크기를 입력해주세요(양수값 입력) : ");
	scanf("%d", &input);
	printf("\n");

	myBingo = (char**)malloc(sizeof(char*) * input);
	assert(myBingo != NULL);

	makeAllocI(myBingo, input);

	//배열 초기화
	for (i = 0; i < (input * input); i++)
	{
		count[i] = 0;
		t[i] = 0;
	}

	//난수 생성
	makeRandS(myBingo, count, input);
	printf("\n");

	//실제 게임 진행
	while (1)
	{
		if (ret > 0)
		{
			//숫자 출력
			for (i = 0; i < input; i++)
			{
				outputNumberU(myBingo[i], input);
				printf("\b|\n");
			}
			printf("\n");
			ret = inputNumber(myBingo, t, input, &num);
		}
		else if (ret == NULL)
			ret = inputNumber(myBingo, t, input, &num);
		printf("\n");

		countLine = checkLine(myBingo, input);

		if (countLine == input)
			break;
	}

	deleteAllocI(myBingo, input);
	free(myBingo);
}

void playConfrontation()
{
	int countLineU, countLineC, ret = 1, input, i, j, count[1000], t[1000];
	int num = 0;
	char **myBingo, **computerBingo;

	printf("# 빙고판의 가로,세로 크기를 입력해주세요(양수값 입력) : ");
	scanf("%d", &input);
	printf("\n");

	myBingo = (char**)malloc(sizeof(char*) * input);
	assert(myBingo != NULL);
	computerBingo = (char**)malloc(sizeof(char*) * input);
	assert(myBingo != NULL);

	makeAllocI(myBingo, input);
	makeAllocI(computerBingo, input);

	//배열 초기화
	for (i = 0; i < (input * input); i++)
	{
		count[i] = 0;
		t[i] = 0;
	}

	//난수 생성 (User)
	makeRandS(myBingo, count, input);
	for (i = 0; i < (input * input); i++)
	{
		count[i] = 0;
	}
	makeRandS(computerBingo, count, input);

	while (1)
	{ 
		if (ret > 0)
		{
			//숫자 출력
			printf(" [User] \t\t [Computer]\n");
			for (i = 0; i < input; i++)
			{
				outputNumberU(myBingo[i], input);
				outputNumberC(computerBingo[i], input);
			}
			printf("\n");
			ret = inputNumber(myBingo, t, input, &num);
		}
		else if (ret == NULL)
		{
			ret = inputNumber(myBingo, t, input, &num);
		}
		printf("\n");

		for (i = 0; i < input; i++)
		{
			for (j = 0; j < input; j++)
			{
				if (computerBingo[i][j] == num)
					computerBingo[i][j] = 'X';
			}
		}

		printf(" [User] \t\t [Computer]\n");
		for (i = 0; i < input; i++)
		{
			outputNumberU(myBingo[i], input);
			outputNumberC(computerBingo[i], input);
		}
		printf("\n");

		inputNumberC(myBingo, computerBingo, input, num);

		//지워진 라인 체크
		countLineU = checkLine(myBingo, input);
		countLineC = checkLine(computerBingo, input);

		if ((countLineU == input) && (countLineC == input))
		{
			printf("# 사용자, 컴퓨터 무승부! \n");
			break;
		}
		else if (countLineU == input)
		{
			printf("# 사용자 승! \n");
			break;
		}
		else if (countLineC == input)
		{
			printf("# 컴퓨터 승! \n");
			break;
		}
	}

	printf("\n");

	deleteAllocI(myBingo, input);
	deleteAllocI(computerBingo, input);
	free(myBingo);
	free(computerBingo);
}


void outputNumberU(char *Bingo, int input)
{
	int j;

	printf("|");

	for (j = 0; j < input; j++)
	{
		if (Bingo[j] == 'X')
			printf("%2c ", Bingo[j]);
		else
			printf("%2d ", Bingo[j]);
	}


}

void outputNumberC(char *Bingo, int input)
{
	int i;

	printf("|\t|");

	for (i = 0; i < input; i++)
	{
		if (Bingo[i] == 'X')
			printf("%2c ", Bingo[i]);
		else
			printf("%2c ", '?');
	}

	printf("\b|\n");
}


void makeRandS(char **Bingo, int *count, int input)
{
	int i, j;

	for (i = 0; i < input; i++)
	{
		for (j = 0; j < input; j++)
		{
			Bingo[i][j] = makeRand(input * input, count);
		}
	}
	printf("\n");
}


void makeAllocI(char **myBingo, int input)
{
	int i;

	for (i = 0; i < input; i++)
	{
		myBingo[i] = (char*)malloc(sizeof(char) * input);
		assert(myBingo[i] != NULL);
	}
}

void deleteAllocI(char **myBingo, int input)
{
	int i;

	for (i = 0; i < input; i++)
		free(myBingo[i]);
}


int makeRand(int n, int *count)
{
	int ret, i;

	while (1)
	{
		ret = (random(n) + 1);

		if (count[ret - 1] == 0)
		{
			count[ret - 1]++;
			return ret;
		}
	}
}

int random(int n)
{
	int ret;
	ret = rand() % n;
	return ret;
}
#endif // 0