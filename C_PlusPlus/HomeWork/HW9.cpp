/*
	!! ������ѿ� ���� ��ǰ�� ������ ���� �Ǹ��ϴ� ���α׷��� �ۼ��Ѵ�.
	Ű����κ��� ǰ��, ����, ��������� �Է��ϸ� ���� ��¥�κ��� ������ѱ��� ���� �ϼ��� ����ϰ�,
	�׿� ���� �������� ���� �����Ͽ� ������ �����Ѵ�.
	
	- ������� 0~3�� �������� 50%, 4~10�� �������� 20% �����Ǹ��ϰ�, �� �ܴ� �����Ǹ�
	- ��������� ���� ���� "��������� �������ϴ�!" �޼��� ���

	@ 2017.02.14
*/

#if 0
#include <time.h> 
#include<windows.h> 
#include <iostream>

using namespace std;

struct date {
	unsigned int da_year;
	unsigned int da_mon;
	unsigned int da_day;
};

struct Goods {
	char item[50];
	int price;
	int year;
	int mon;
	int day;
	int discount;
};

int const monthD[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

void input(Goods &s);
void selling_price(Goods &s);
void prn(const Goods &s);
int tot_days(int y, int m, int d);
int leap_check(int year);
void getdate(struct date *);

int main()
{
	Goods s;

	input(s);

	selling_price(s);

	prn(s);
}

void input(Goods &s)
{
	cout << "ǰ�� �Է� : ";
	cin.getline(s.item, sizeof(s.item));
	cout << "���� �Է� : ";
	cin >> s.price;
	cout << "������� �Է� : ";
	cin >> s.year >> s.mon >> s.day;
}

void selling_price(Goods &s)
{
	date sell;

	getdate(&sell);

	int now, sellDate, gap;

	sellDate = tot_days(s.year, s.mon, s.day);
	now = tot_days(sell.da_year, sell.da_mon, sell.da_day);

	gap = sellDate - now;

	if ((gap <= 3) && (gap >= 0)) 
		s.discount = 50;
	else if ((gap >= 4) && (gap <= 10)) 
		s.discount = 20;
	else if (gap <= 0) 
		s.discount = -1;
	else 
		s.discount = 0;

	s.price = s.price - (s.price * ((float)s.discount / 100));

	getchar();
}

void prn(const Goods &s)
{
	if (s.discount == -1)
		cout << "��������� �������ϴ�!" << endl;
	else {
		cout << "ǰ�� : " << s.item << endl;
		cout << "�ǸŰ� : " << s.price << endl;
		cout << "���� ���� : " << s.year << "-" << s.mon << "-" << s.day << endl;
		cout << "������ : " << s.discount << "%" << endl;
	}
}

int tot_days(int year, int month, int day)
{
	int sumDay = 0, i;
	if (year > 1900)
	{
		for (i = 1900; i < year; i++)
		{
			if (leap_check(i) == 1)
				sumDay += 366;
			else
				sumDay += 365;
		}
	}
	if (month > 1)
	{
		for (i = 0; i < (month - 1); i++)
		{
			if (leap_check(year) == 1)
			{
				if (i == 1)
					sumDay += 29;
				else
					sumDay += monthD[i];
			}
			else
				sumDay += monthD[i];
		}
	}
	for (i = 1; i <= day; i++)
		sumDay++;
	return sumDay;

}

int leap_check(int year)
{
	int result;
	if ((year % 4) != 0)
		return 0;
	else if ((year % 100) != 0)
		return 1;
	else if ((year % 400) != 0)
		return 0;
	else
		return 1;
}

void getdate(struct date *p) // ���� �����͸� ��ȯ�Ҽ� �ֵ��� Call by pointer ��� ��� 
{
	char temp[128];
	char *cp, syear[5] = "20";
	_strdate(temp); // temp char�迭 �ȿ� 08/10/04(��/��/��)������ ������� ���ڿ� ���·� ���� 
	cp = strtok(temp, "/"); // temp�迭�� ù��° '/'���� ���ڿ��� ����� cp���� "08" ���ڿ��� �����ּҸ� ���� 
	p->da_mon = atoi(cp); // ��� "08"���ڿ��� ������ ������ 8�� ��ȯ�Ͽ� p->da_mon�� ���� 
	cp = strtok(NULL, "/"); // temp�迭�� �ι�° '/'���� ���ڿ��� ����� cp���� "10" ���ڿ��� �����ּҸ� ���� 
	p->da_day = atoi(cp); // ��� "10"���ڿ��� ������ ������ 10�� ��ȯ�Ͽ� p->da_day�� ���� 
	cp = strtok(NULL, "/"); // temp�迭�� ����° '/'���� ���ڿ��� ������ϳ� '/'�� ��Ÿ���� �ʰ� ���ڿ��� 
							// ������ �ǹǷ� ���� ���ڿ� ��ü�� �����Ѵ� ��, cp���� "04" ���ڿ��� �����ּҰ� �����Ѵ�. 
	strcat(syear, cp); // syear���� "20"�� cp�� ����Ű�� "04"�� �ٿ��� "2004" ���ڿ��� syear������ ���� 
	p->da_year = atoi(syear); // syear���� "2004" ���ڿ��� ������ ������ 2004�� ��ȯ�Ͽ� p->da_year�� ���� 
}
#endif