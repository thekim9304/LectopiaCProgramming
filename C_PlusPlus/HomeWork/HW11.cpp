/*
	!! Time객체는 시간과 분을 따로 저장하며 분은 항상 0 ~ 59 사이의 값을 갖는다.
	객체를 선언할 때 초기화를 하지 않으면 0시간 0분으로 객체를 생성하며 초기화를 할 때는 시간과 분으로 초기화를 한다.
	또한 실수값으로도 초기화를 할 수 있도록 한다. 예를 들어, 4.5로 초기화하면 4시간 30분이 된다.
	
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
	cout << a.getHour() << "시간" << a.getMin() << "분" << endl;
	cout << b.getHour() << "시간" << b.getMin() << "분" << endl;
	Time res = a.plus(b);
	cout << "두 시간을 더하면 : " << res.getHour() << "시간" << res.getMin() << "분" << endl;

	cout << a.getHour() << "시간" << a.getMin() << "분" << endl;
	cout << b.getHour() << "시간" << b.getMin() << "분" << endl;
}
#endif