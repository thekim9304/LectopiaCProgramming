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
	Save(const char *np = "�ƹ���", int n = 0);
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
	cout << "�̸� : " << br.name << endl;
	cout << "���� : " << br.capital << endl;
	cout << "���ڼҵ� : " << br.profit << endl;
	cout << "���� : " << br.tax << endl;
	cout << "�ѱݾ� : " << br.tot << endl;
	cout << "���� : " << br.ratio << endl;
	cout << "���� : " << br.tax_ratio << endl;
	
	return os;
}

int main()
{
	Save a("ö��", 1000000);
	a.caclculate();
	cout << a << endl;
	Save::tax_ratio = 0.15;
	Save::set_ratio(0.25);
	Save b("����", 2000000);
	b.caclculate();
	cout << b << endl;
}
#endif