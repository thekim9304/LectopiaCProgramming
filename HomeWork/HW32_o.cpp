/*
	!!은행계좌 입출금 관리 프로그램

	-주 메뉴 = i-입금, o-출금, q-종료(주 메뉴 이외의 문자 입력시 재입력 요구)
	-시작 잔액 0원
	-잔액보다 인출액 많으면 "잔액이 부족합니다." -> 주메뉴로
	-입출금액 입력 시 음수 값 입력시 "잘못 입력하셨습니다." 출력 후 금액 재입력 요구
	-입출금액 입력시 문자 입력시 "잘못 입력하셨습니다." 출력 후 금액 재입력 요구

	1.menu() : 메뉴 출력 후 사용자가 선택한 메뉴 문자를 리턴 하는 함수 메뉴 문자(i, o, q)외 문자 입력 시 재입력 요구
	2.inputInt(string) : 전단일자로 받은 문자열을 출력하고, 정수(음,양수)를 입력 받아 리턴 하는 함수(문자 입력 시 재입력 요구)
	3.deposit() : 입금처리 함수
	4.withdraw() : 출금처리 함수

	@2017.01.07 pm07:35
*/

// inputInt()에서 음수 입력시 버퍼 비우는거 고쳐
#if 0
#include <stdio.h>

char menu();
int inputInt(char*);
void deposit(int*, int*);
void withdraw(int*, int*);
void myflush();

int main()
{
	int balanceMoney = 0, inputMoney;
	char inputMenu;

	printf("* 현재 잔액은 %d원 입니다.\n\n", balanceMoney);

	while ((inputMenu = menu()) != 'q')
	{
		switch (inputMenu)
		{
		case 'i':
			inputMoney = inputInt("# 입금액을 입력하세요 : ");
			deposit(&balanceMoney, &inputMoney);
			break;
		case 'o':
			inputMoney = inputInt("# 출금액을 입력하세요 : ");
			withdraw(&balanceMoney, &inputMoney);
			break;
		}
		printf("* 현재 잔액은 %d원 입니다.\n\n", balanceMoney);
	}
}

void withdraw(int *balanceMoney, int *withdrowMoney)
{
	*balanceMoney -= *withdrowMoney;
}

void deposit(int *balanceMoney, int *depositMoney)
{
	*balanceMoney += *depositMoney;
}

int inputInt(char *outMessage)
{
	int inputMoney;

	printf("%s", outMessage);

	while (1)
	{
		scanf("%d", &inputMoney);

		if (inputMoney > 0)
			break;

		printf("*1 잘못 입력하셨습니다. 다시 입력하십시오 : ");

		
	}

	myflush();
	return inputMoney;
}

char menu()
{
	char inputMenu	;

	while (1)
	{
		printf("# 메뉴를 입력하시오(i-입금, o-출금, q-종료) : ");
		scanf("%c", &inputMenu);

		if (inputMenu == 'i' | inputMenu == 'o' | inputMenu == 'q')
			break;
		else
			printf("*잘못 입력 했습니다.\n\n");

		getchar();
	}

	return inputMenu;
}

void myflush()
{
	while (getchar() != '\n')
		;
}
#endif