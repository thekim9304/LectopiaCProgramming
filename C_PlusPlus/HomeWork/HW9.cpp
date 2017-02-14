/*
	!! 유통기한에 따라 제품의 가격을 할인 판매하는 프로그램을 작성한다.
	키보드로부터 품명, 정가, 유통기한을 입력하면 현재 날짜로부터 유통기한까지 남은 일수를 계산하고,
	그에 따라 할인율을 차등 적용하여 정가를 수정한다.
	
	- 유통기한 0~3일 전까지는 50%, 4~10일 전까지는 20% 할인판매하고, 그 외는 정가판매
	- 유통기한이 지난 경우는 "유통기한이 지났습니다!" 메세지 출력

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
	cout << "품목 입력 : ";
	cin.getline(s.item, sizeof(s.item));
	cout << "정가 입력 : ";
	cin >> s.price;
	cout << "유통기한 입력 : ";
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
		cout << "유통기한이 지났습니다!" << endl;
	else {
		cout << "품명 : " << s.item << endl;
		cout << "판매가 : " << s.price << endl;
		cout << "유통 기한 : " << s.year << "-" << s.mon << "-" << s.day << endl;
		cout << "할인율 : " << s.discount << "%" << endl;
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

void getdate(struct date *p) // 원본 데이터를 변환할수 있도록 Call by pointer 기법 사용 
{
	char temp[128];
	char *cp, syear[5] = "20";
	_strdate(temp); // temp char배열 안에 08/10/04(월/일/년)순으로 년월일이 문자열 상태로 저장 
	cp = strtok(temp, "/"); // temp배열의 첫번째 '/'까지 문자열를 끊어내어 cp에게 "08" 문자열의 시작주소를 리턴 
	p->da_mon = atoi(cp); // 끊어낸 "08"문자열을 정수형 데이터 8로 변환하여 p->da_mon에 저장 
	cp = strtok(NULL, "/"); // temp배열의 두번째 '/'까지 문자열를 끊어내어 cp에게 "10" 문자열의 시작주소를 리턴 
	p->da_day = atoi(cp); // 끊어낸 "10"문자열을 정수형 데이터 10로 변환하여 p->da_day에 저장 
	cp = strtok(NULL, "/"); // temp배열의 세번째 '/'까지 문자열를 끊어내려하나 '/'은 나타나지 않고 문자열이 
							// 끝나게 되므로 남은 문자열 전체를 리턴한다 즉, cp에게 "04" 문자열의 시작주소가 리턴한다. 
	strcat(syear, cp); // syear내의 "20"과 cp가 가리키는 "04"을 붙여서 "2004" 문자열을 syear변수에 저장 
	p->da_year = atoi(syear); // syear내의 "2004" 문자열을 정수형 데이터 2004로 변환하여 p->da_year에 저장 
}
#endif