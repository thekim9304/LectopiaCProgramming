#if 0
#include<iostream>
using namespace std;

class Time
{
  private:
	int hour;
	int min;
  public:
	Time(int h=0, int m=0);   // 시, 분을 받는 오버로디드 생성자
	Time(double t);           // 시간을 실수값으로 초기화하는 생성자
	operator double() const;  // 형변환함수
	void show();              // 멤버 출력함수
};

Time::Time(int h, int m)
{
	cout << "int  생성자 호출..." << endl;
	hour=h;
	min=m;
}

Time::Time(double t)
{
	cout << "double 생성자 호출..." << endl;
	hour=int(t);
	min=(int)((t-hour)*60.0);
}

Time::operator double() const
{
	cout << "형변환함수 호출..." << endl;
	double temp;
	temp=hour+min/60.0;
	return temp;
}

void Time::show()
{
	cout << this->hour << "시간 " << this->min << "분" << endl;
}

int main()
{
	Time a;
	a=3.5;  // 생성자 함수 호출
	a.show();

	double res;
	res=1.5 + static_cast<double>(a);  // operator double() 형변환 멤버함수 호출
	cout << res << endl;


	int num;
	int *ip;
	char ch = 'A';

	num = static_cast<int>(ch);
	cout << num << endl;

	reinterpret_cat
	return 0;
 }
#endif