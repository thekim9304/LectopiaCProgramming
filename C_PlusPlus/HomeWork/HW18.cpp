#if 01
#include <iostream>
#include <cstring>

using namespace std;

class Save{
private:
	char name[20];
	int capital;
	int profit;
	int tax;
	int tot;
	static double ratio;
public:
	static double tax_ratio;
	Save(const char *np = "아무개", int n = 0);
	void caclculate();
	friend ostream &operator<<(ostream &os, const Save &br);
	static void set_ratio(double r);
};

double Save::ratio = 0.2;
double Save::tax_ratio = 0.1;

void Save::set_ratio(double r) {
	ratio = r;
}

Save::Save(const char *np, int n) : capital(n) {
	strcpy(name, np);
}

void Save::caclculate() {
	profit = capital * ratio;
	tax = profit * tax_ratio;

	tot = capital + profit - tax;
}

ostream &operator<<(ostream &os, const Save &br) {
	cout << "이름 : " << br.name << endl;
	cout << "원금 : " << br.capital << endl;
	cout << "이자소득 : " << br.profit << endl;
	cout << "세금 : " << br.tax << endl;
	cout << "총금액 : " << br.tot << endl;
	cout << "이율 : " << br.ratio << endl;
	cout << "세율 : " << br.tax_ratio << endl;
	
	return os;
}

int main()
{
	Save a("철이", 1000000);
	a.caclculate();
	cout << a << endl;
	Save::tax_ratio = 0.15;
	Save::set_ratio(0.25);
	Save b("메텔", 2000000);
	b.caclculate();
	cout << b << endl;
}
#endif