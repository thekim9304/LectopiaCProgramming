#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int input();
int output(int, int);
int random(int);

int main()
{
	int num, player, ret;
	int play1 = 0, play3 = 0;

	while (1)
	{
		srand((unsigned int)time(NULL));
		num = random(3) + 1;

		player = input();

		ret = output(player, num);

		if (ret == 1)
			play1++;
		else if (ret == 3)
			play3++;
		else
			break;
	}

	printf("게임 결과 : %d 승 %d 무", play1, play3);

}

int output(int input, int num)
{
	if (input == 1)
	{
		if (num == 1)
		{
			printf("당신은 바위 선택, 컴퓨터는 바위 선택 : 비겼습니다.\n");
			return 3;
		}
		else if (num == 2)
		{
			printf("당신은 바위 선택, 컴퓨터는 가위 선택 : 이겼습니다.\n");
			return 1;
		}
		else if (num == 3)
		{
			printf("당신은 바위 선택, 컴퓨터는 보 선택 : 졌습니다.\n");
			return 2;
		}
	}
	else if (input == 2)
	{
		if (num == 1)
		{
			printf("당신은 가위 선택, 컴퓨터는 바위 선택 : 졌습니다.\n");
			return 2;
		}
		else if (num == 2)
		{
			printf("당신은 가위 선택, 컴퓨터는 가위 선택 : 비겼습니다.\n");
			return 3;
		}
		else if (num == 3)
		{
			printf("당신은 가위 선택, 컴퓨터는 보 선택 : 이겼습니다.\n");
			return 1;
		}
	}
	else if (input == 3)
	{
		if (num == 1)
		{
			printf("당신은 보 선택, 컴퓨터는 바위 선택 : 이겼습니다.\n");
			return 1;
		}
		else if (num == 2)
		{
			printf("당신은 보 선택, 컴퓨터는 가위 선택 : 졌습니다.\n");
			return 2;
		}
		else if (num == 3)
		{
			printf("당신은 보 선택, 컴퓨터는 보 선택 : 비겼습니다.\n");
			return 3;
		}
	}
}

int input()
{
	int input, ret;
	
	while (1)
	{
		printf("# 바위는 1, 가위는 2, 보는 3 중에서 선택하세요 : ");
		ret = scanf("%d", &input);
		
		if (ret != 1)
		{
			printf("정수를 입력 하세요!!\n");
			getchar();
		}
		else if (input > 0 && input < 4)
			break;
		else
			printf("1 - 3 사이의 숫자를 입력 하세요!!\n");
	}

	return input;
}

int random(int n)
{
	int ret;
	ret = rand() % n;
	return ret;
}