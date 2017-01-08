/*
	!!환풍구 관리 프로그램

	총 8개의 환풍구 개폐(ON, OFF)관리 시스템 구현
	1. 특정 확풍구 만을 ON하는 기능
	2. 특정 환풍구 만을 OFF하는 기능
	3. 전체 환풍구 상태를 반전하는 기능
	4. 처음 시작상태는 모든 환풍구가 닫혀 있음

	@2017.01.08  am10:29
*/

#if 0
#include <stdio.h>

int menu();
char openFan(unsigned char);
char offFan(unsigned char);
char reverseFan(unsigned char);
void displayFan(unsigned char);

void myflush();
int inputInt();
void selectM(int, unsigned char*);
void outputBinary(unsigned char);

int main()
{
	unsigned char numberFan = 0x00, select;

	while (1)
	{
		select = menu();
		if (select == 4)
			break;

		selectM(select, &numberFan);
		displayFan(numberFan);
	}
}

int menu()
{
	int ret;

	while (1)
	{
		printf("\n1. 환풍구 열기 / 2. 환풍구 닫기 / 3. 환풍구 전체 전환 / 4. 종료 : ");
		ret = inputInt();
		printf("-------------------------------------------------------------\n");

		if (ret >= 1 && ret <= 4)
			return ret;

		myflush();
		printf("\n");
	}
}

void displayFan(unsigned char num)
{
	printf("8번FAN  7번FAN  6번FAN  5번FAN  4번FAN  3번FAN  2번FAN  1번FAN\n");
	outputBinary(num);
	printf("\n-------------------------------------------------------------\n\n");
}

char reverseFan(unsigned char num)
{
	printf("                Fan 전체 전환 작업 실행 화면\n");
	printf("-------------------------------------------------------------\n");
	printf("전체 FAN의 상태가 전환되었습니다. (ON, OFF 상태 뒤바뀜)\n");
	printf("-------------------------------------------------------------\n");

	num = ~num;

	return num;
}

char offFan(unsigned char num)
{
	unsigned char calculator = 0x7f;
	int fanNumber;

	printf("                Fan 닫기 작업 실행 화면\n");
	printf("-------------------------------------------------------------\n");
	while (1)
	{
		printf("* CLOSE할 FAN 번호를 입력하시오(1-8) : ");
		fanNumber = inputInt();

		if (fanNumber >= 1 && fanNumber <= 8)
			break;

		myflush();
	}
	printf("-------------------------------------------------------------\n");

	calculator = (calculator >> (8 - fanNumber) | (calculator << (fanNumber)));
	//calculator = calculator >> (8 - fanNumber);

	num = num & calculator;

	return num;
}

char openFan(unsigned char num)
{
	unsigned char calculator = 0x80;
	int fanNumber;

	printf("                Fan 열기 작업 실행 화면\n");
	printf("-------------------------------------------------------------\n");
	while (1)
	{
		printf("* OPEN할 FAN 번호를 입력하시오(1-8) : ");
		fanNumber = inputInt();

		if (fanNumber >= 1 && fanNumber <= 8)
			break;

		myflush();
	}
	printf("-------------------------------------------------------------\n");

	calculator = calculator >> (8 - fanNumber);

	num = num | calculator;

	return num;
}

int inputInt()
{
	int inputValue;


	scanf("%d", &inputValue);
	/*while (1)
	{
		scanf("%d", &inputValue);

		if (getchar() == '\n')
			break;

		myflush();
	}*/

	return inputValue;
}

void myflush()
{
	while (getchar() != '\n')
		;
}

void outputBinary(unsigned char num)
{
	unsigned char calculator = 0x80, result;
	int i;

	for (i = 0; i <= 7; i++)
	{
		result = (num & calculator) >> (7 - i);

		if (result == 1)
			printf("  ON\t");
		else
			printf("  OFF\t");

		calculator = calculator >> 1;
	}
}

void selectM(int number, unsigned char *numberFan)
{
	switch (number)
	{
	case 1:
		*numberFan = openFan(*numberFan);
		break;
	case 2:
		*numberFan = offFan(*numberFan);
		break;
	case 3:
		*numberFan = reverseFan(*numberFan);
		break;
	}
}
#endif