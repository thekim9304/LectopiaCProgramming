#if 01
#include <iostream>

using namespace std;

class Time {
private:
	int hour;
	int min;
	double time;
	static int mode;
	enum { integer, real };
public:
	Time();
	Time(int, int);
	Time(double);
	Time(const Time &tr);
	Time plus(const Time &tr);
	void setHour(int);
	int getHour();
	void setMin(int);
	int getMin();
	friend ostream& operator<<(ostream &os, const Time &br);
	static void mode_change();
};

Time::Time() : hour(0), min(0), time(0){}

Time::Time(int h, int m) : hour(h), min(m){
	time = h;
	time += (double)m / 60.0;
}

Time::Time(double t) : time(t) {
	hour = (int)t;
	this->min = 60 * (t - (int)t);
}

Time::Time(const Time &tr) {
	hour = tr.hour;
	min = tr.min;
	time = tr.time;
	mode = tr.mode;
}

Time Time::plus(const Time &tr) {
	Time save;

	save.hour = hour + tr.hour;

	if ((save.min = (min + tr.min)) >= 60) {
		save.hour += (save.min / 60);
		save.min %= 60;
	}

	save.time = time + tr.time;

	return save;
}

void Time::setHour(int h) {
	hour = h;
}

int Time::getHour() {
	return hour;
}

void Time::setMin(int m) {
	min = m;
}

int Time::getMin() {
	return min;
}

ostream& operator<<(ostream &os, const Time &br){
	if (br.mode == br.integer) 
		cout << br.hour << "시간 " << br.min << "분" << endl;
	else
		cout << br.time << "시간" << endl;

	return os;
}

int Time::mode = integer;

void Time::mode_change() {
	if (mode == integer) {
		mode = real;
	}
	else {
		mode = integer;
	}
}

int main()
{
	Time a(3, 21);
	Time b(2.7);
	cout << "기분 출력 형태(시간, 분)..." << endl;
	cout << a << endl;
	cout << b << endl;
	Time::mode_change();
	cout << "출력모드를 바꾼 후..." << endl;
	cout << a << endl;
	cout << b << endl;
}
#endif