/*
	!! 저금통에 잔돈을 저금하는 프로그램을 작성한다.
	   키보드로부터 동전의 금액과 개수를 반복적으로 입력하다가 입력이 끝나면 총 저축액을 출력한다.
	   동전의 단위는 500원, 100원, 50원, 10원으로 하고 동전의 금액으로 음수가 입력되면 입력을 종료한다.

	@ 2017.02.14
*/

#if 0
#include <iostream>

using namespace std;

struct Savings {
	int w500;
	int w100;
	int w50;
	int w10;
};

void init(Savings &s);
void input(int &unit, int &cnt);
void save(Savings &s, int unit, int cnt);
int total(Savings &s);
void my_flush();

int main()
{
	Savings sa;
	int cost = 1, costCnt;

	init(sa);

	while (cost >= 0) {
		input(cost, costCnt);
		save(sa, cost, costCnt);
	}

	cout << "총 저금액 : " << total(sa) << endl;
}

int total(Savings &s)
{
	return ((500 * s.w500) + (100 * s.w100) + (50 * s.w50) + (10 * s.w10));
}

void save(Savings &s, int unit, int cnt)
{
	switch (unit) {
	case 500:
		s.w500 += cnt;
		break;
	case 100:
		s.w100 += cnt;
		break;
	case 50:
		s.w50 += cnt;
		break;
	case 10:
		s.w10 += cnt;
	}
}

void input(int &unit, int &cnt)
{
	cout << "동전의 금액 : ";
	cin >> unit;

	if (unit < 0)
		return;

	while (cin.fail() || ((unit != 500) && (unit != 100) && (unit != 50) && (unit != 10))) {
		my_flush();

		cout << "금액을 다시 입력 하세요 : ";
		cin >> unit;
	}

	cout << "동전의 개수 : ";
	cin >> cnt;

	while (cin.fail() || cnt < 0) {
		my_flush();

		cout << "개수를 다시 입력 하세요 : ";
		cin >> cnt;
	}
}

void init(Savings &s)
{
	s.w10 = 0;
	s.w100 = 0;
	s.w50 = 0;
	s.w500 = 0;
}

void my_flush()
{
	cin.clear();

	while (cin.get() != '\n');
}
#endif