#include <iostream>

using namespace std;

class Time {
private:
	int hour;
	int min;
public:
	Time(int h = 0, int m = 0);
	Time operator+(const Time &br);
	Time operator-();
	Time &operator++();
	Time operator++(int);
	Time operator*(int n);
	friend ostream& operator<<(ostream &os, Time &r);
	friend istream& operator >> (istream &is, Time &r);
	// void operator<<(ostream &os); // friend 안쓰고 돌려막기 
	//void operator >> (istream &is); //friend 안쓰고 돌려 막기
	void show();
};

Time::Time(int h, int m) {
	hour = h;
	min = m;
}

Time Time::operator*(int n) {
	int h, m;
	
	h = hour * n;
	m = min * n;

	if (m >= 60) {
		h += m / 60;
		m = m & 60;
	}

	return Time(h, m);
}

Time Time::operator+(const Time &br) {
	int h, m;
	h = hour + br.hour;
	m = min + br.min;

	if (m >= 60) {
		h += m / 60;
		m = m % 60;
	}

	Time res(h, m);
	
	return res;
}

Time Time::operator-() {
	Time temp(-hour, -min);

	return temp;
}

Time &Time::operator++() {
	min++;

	if (min == 60) {
		hour++;
		min = 0;
	}

	return *this;
}

Time Time::operator++(int) {
	Time temp(hour, min);
	min++;

	if (min == 60) {
		hour++;
		min = 0;
	}

	return temp;
}

void Time::show() {
	cout << hour << "시간 " << min << "분" << endl;
}

/*
void Time::operator<<(ostream &os) {
	os << hour << "시간 " << min << "분" << endl;
}

void Time::operator >> (istream &is) {
	is >> hour >> min;
}
*/

void func(Time &br);
Time operator*(int n, Time &r);
//ostream& operator<<(ostream &os, Time &r);
//istream& operator >> (istream &is, Time &r);

int main()
{

	ostream &myOut = cout;
	Time a(5, 50), b(3, 30), c;

	c = b + a;
	a.show();
	b.show();
	c.show();
	  
	c = ++a + b;
	a.show();
	b.show();
	c.show();

	c = a + b++;
	a.show();
	b.show();
	c.show();

	func(++a);
	a.show();

	func(a++);
	a.show();

	c = 3 * a;
	c.show();

	cin >> c;
	cout << c;
}

Time operator*(int n, Time &r)
{
	return r * n;
}

void func(Time &br)
{
	br++;
}

ostream& operator<<(ostream &os, Time &r) 
{
	os << r.hour << "시간 " << r.min << "분" << endl;
	//r << os;
	return os;
}

istream& operator >> (istream &is, Time &r) 
{
	is >> r.hour >> r.min;
	//r >> is;
	return is;
}