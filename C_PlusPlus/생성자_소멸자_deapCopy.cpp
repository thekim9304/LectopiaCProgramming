#include <iostream>
#include <string.h>

using namespace std;

class MoneyBox {
private:
	char *name;
	int sum;
public:
	MoneyBox();
	MoneyBox(const char *np, int m = 0);
	MoneyBox(const MoneyBox &br);
	~MoneyBox() { 
		cout << "destructor... " << this->name << endl; 
		delete[] this->name;
	}
	void save(int m);
	void use(int m);
	void prn();
};

MoneyBox::MoneyBox()
{
	this->name = new char[strlen("아무개") + 1];
	strcpy(this->name, "아무개");
	this->sum = 0;

	cout << "디폴트 생성자 호출..." << this->name << endl;
	/*
	strcpy(this->name, "아무개");
	this->sum = 0;
	cout << "디폴트 생성자 호출..." << this->name << endl;
	*/
}

MoneyBox::MoneyBox(const char *np, int m)
{
	this->name = new char[strlen(np) + 1];
	strcpy(this->name, np);
	this->sum = m;

	cout << "오버로디드 생성자 호출..." << this->name << endl;
	/*
	strcpy(this->name, np);
	this->sum = m;
	cout << "오버로디드 생성자 호출..." << this->name << endl;
	*/
}

MoneyBox::MoneyBox(const MoneyBox &br)
{
	this->name = new char[strlen(br.name) + 1];
	strcpy(this->name, br.name);
	this->sum = br.sum;

	cout << "복사 생성자 호출..." << this->name << endl;

	/*
	strcpy(this->name, br.name);
	this->sum = br.sum;
	cout << "복사 생성자 호출..." << this->name << endl;
	*/
}

void MoneyBox::save(int m)
{
	if (m >= 0)
		this->sum += m;
}

void MoneyBox::use(int m)
{
	if (m > 0 && m < this->sum)
		this->sum = m;
}

void MoneyBox::prn()
{
	cout << "이름 : " << this->name << endl;
	cout << "잔액 : " << this->sum << endl;
}

MoneyBox &func(MoneyBox &m);

int main()
{
	MoneyBox a;
	MoneyBox b("홍길동");
	MoneyBox c("이순신", 500);
	MoneyBox d = b;
	MoneyBox *mp1 = new MoneyBox("홍길동");
	MoneyBox *mp2 = new MoneyBox(c);
	func(b);

	delete mp1;
	delete mp2;
}

MoneyBox& func(MoneyBox &m)
{
	return m;
}