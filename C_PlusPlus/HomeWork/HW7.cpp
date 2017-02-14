/*
	!! �����뿡 �ܵ��� �����ϴ� ���α׷��� �ۼ��Ѵ�.
	   Ű����κ��� ������ �ݾװ� ������ �ݺ������� �Է��ϴٰ� �Է��� ������ �� ������� ����Ѵ�.
	   ������ ������ 500��, 100��, 50��, 10������ �ϰ� ������ �ݾ����� ������ �ԷµǸ� �Է��� �����Ѵ�.

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

	cout << "�� ���ݾ� : " << total(sa) << endl;
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
	cout << "������ �ݾ� : ";
	cin >> unit;

	if (unit < 0)
		return;

	while (cin.fail() || ((unit != 500) && (unit != 100) && (unit != 50) && (unit != 10))) {
		my_flush();

		cout << "�ݾ��� �ٽ� �Է� �ϼ��� : ";
		cin >> unit;
	}

	cout << "������ ���� : ";
	cin >> cnt;

	while (cin.fail() || cnt < 0) {
		my_flush();

		cout << "������ �ٽ� �Է� �ϼ��� : ";
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