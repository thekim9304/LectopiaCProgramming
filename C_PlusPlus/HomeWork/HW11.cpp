/*
	!! Time��ü�� �ð��� ���� ���� �����ϸ� ���� �׻� 0 ~ 59 ������ ���� ���´�.
	��ü�� ������ �� �ʱ�ȭ�� ���� ������ 0�ð� 0������ ��ü�� �����ϸ� �ʱ�ȭ�� �� ���� �ð��� ������ �ʱ�ȭ�� �Ѵ�.
	���� �Ǽ������ε� �ʱ�ȭ�� �� �� �ֵ��� �Ѵ�. ���� ���, 4.5�� �ʱ�ȭ�ϸ� 4�ð� 30���� �ȴ�.
	
	@ 2017.02.15
*/

#if 0
#include <iostream>

using namespace std;

class Time {
private:
	int hour;
	int min;
public:
	Time();
	Time(int, int);
	Time(double);
	Time(const Time &rt);
	Time plus(const Time &tr);
	void setHour(int);
	int getHour();
	void setMin(int);
	int getMin();
};

Time::Time() {
	hour = 0;
	min = 0;
}

Time::Time(int hour, int min) {
	this->hour = hour;
	this->min = min;
}

Time::Time(double hourM) {
	this->hour = (int)hourM;
	this->min = 60 * (hourM - (int)hourM);
}

Time::Time(const Time &rt) {
	this->hour = rt.hour;
	this->min = rt.min;
}

Time Time::plus(const Time &rt) {
	Time save;

	save.hour = this->hour + rt.hour;
	save.min = this->min + rt.min;

	if ((save.min / 60) > 0) {
		save.hour += (save.min / 60);
		save.min = (save.min % 60);
	}

	return save;
}

void Time::setHour(int hour) {
	this->hour = hour;
}

int Time::getHour() {
	return this->hour;
}

void Time::setMin(int min) {
	this->min = min;
}

int Time::getMin() {
	return this->min;
}

int main()
{
	Time a(3, 20), b(4.5);
	cout << a.getHour() << "�ð�" << a.getMin() << "��" << endl;
	cout << b.getHour() << "�ð�" << b.getMin() << "��" << endl;
	Time res = a.plus(b);
	cout << "�� �ð��� ���ϸ� : " << res.getHour() << "�ð�" << res.getMin() << "��" << endl;

	cout << a.getHour() << "�ð�" << a.getMin() << "��" << endl;
	cout << b.getHour() << "�ð�" << b.getMin() << "��" << endl;
}
#endif