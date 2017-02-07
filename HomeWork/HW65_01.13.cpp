/*
	!!���ڿ� �޸�(,) �߰��ϱ�

	������ �Էµ� ���ڸ� ���ڷ� ��ȯ�Ͽ� �����ϴ� ���α׷� �ۼ�
	�ԷµǴ� ���� 1���� 20�� �̸��� ������ �����ϸ�, ��ȯ�� ���ڴ� ���ڸ� ��������
	�޸�(,)�� ǥ���Ѵ�.
	�ݺ������ϸ� ���� �Է� �� ����

	@2017.01.13 pm06:31
*/
#if 1
#include <stdio.h>

int inputInt();
void myflush();
void exchangeChar(int, char*);

int main()
{
	int inputCost;
	char exChar[100];

	while (1)
	{
		inputCost = inputInt();

    // 이 경우에도 비정상종료면 왜 비정상 종료인지 log 찍어주기
		if (inputCost < 0) {
      printf("0 이상의 숫자를 입력해주세요");
			break;
    }

		exchangeChar(inputCost, exChar);

		printf(" %d -> %s\n\n", inputCost, exChar);
	}
}

void exchangeChar(int inputCost, char *exChar)  // ',' = 44
{
	int i, j = 0, k = 0, save = 0, count = 0, exInt[100] = { 0 , };

/**
 * 변수로 쓰여야 할만한? 추후 유지보수에 중요한 역할을 하는 숫자들을 '변수'로 하지않고 '숫자'로 쓰는 것을 ==> 하드코딩 이라고합
 * 1000000000, 1000000, 1000, 48 이건 완벽한 하드코딩!!
 * 하드코딩은 무조건무조건 피해야함
 * ex ) maxValue = 1000000000; 해놓고 for (i = maxValue; i >= 1; i /= 10) 이런식으로 단순 변수로 해도됨
 * 하지만 아래 코드는... 너무 제한적인 코드임..
 * if ((i == 1000000000) || (i == 1000000) || (i == 1000)) 이런부분 절대 좋지 않음!
 *
 * 입력받은 숫자의 전체 길이를 먼저 알아챈다음에,
 * 동적으로 콤마의 갯수 및 위치를 파악하고 찍어야함
 * 저렇게 위치를 손으로 지정해주는거 좋지않음
 */
	for (i = 1000000000; i >= 1; i /= 10)
	{
		if ((inputCost / i) >= 1)
		{
			save = inputCost / i;
			inputCost = inputCost - (save * i);
			exInt[j] = (save + 48);
			j++;

			if ((i == 1000000000) || (i == 1000000) || (i == 1000))
			{
				exInt[j] = 44;
				j++;
			}
			count++;
		}
		else if(count > 0)
		{
			exInt[j] = 48;
			j++;
		}
	}

	while (exInt[k] != 0)
	{
		exChar[k] = exInt[k];

		k++;
	}
	exChar[k] = '\0';
}

int inputInt()
{
	int input;

	printf("# �ݾ� �Է� : ");

	while(1)
	{
		scanf("%d", &input);

		if (getchar() == '\n')
			break;

		myflush();

		printf("# �ݾ� �Է� : ");
	}

	return input;
}

void myflush()
{
	while (getchar() != '\n')
		;
}
#endif
