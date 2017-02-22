/*
	!! 철이와 메텔이 만원의 행복을 촬영한다. 각각 10000원의 잔액을 가지고 시작하며,
	사용내역과 금액을 입력한 후에 잔액이 많은 사람의 데이터를 출력한다.
	사용내역은 100개 이내

	@ 2017.02.20
*/
#include <iostream>
#include <string>

using namespace std;

class Happy {
private:
	string name;
	int money;
	char *list[100];
	int index;
public:
	Happy(char *np = "", int money = 10000);
	Happy(Happy &r);
	~Happy();
	Happy& operator=(Happy &r);
	void use(char *lp, int n);
	Happy &winner(Happy &r);
	void setName(string &name);
	string& getName();
	void setMoney(int money);
	int getMoney();
	char** getList();
	int getIndex();
};

Happy::Happy(char *np, int money) {
	name = np;
	this->money = money;
	index = 0;
}

Happy::Happy(Happy &r) {
	this->name = r.name;
	this->money = r.money;

	for (int i = 0; i < r.index; i++) {
		this->list[i] = new char[strlen(r.list[i]) + 1];
		strcpy(this->list[i], r.list[i]);
	}
	
	this->index = r.index;
}

Happy::~Happy() {
	for (int i = 0; i < index; i++) {
		delete[] this->list[i];
	}
}

Happy& Happy::operator=(Happy &r) {
	if (this == &r) return *this;

	for (int i = 0; i < index; i++) {
		delete[] list[i];
	}

	for (int i = 0; i < r.index; i++) {
		this->list[i] = new char[strlen(r.list[i]) + 1];
		strcpy(this->list[i], r.list[i]);
	}

	this->name = r.name;
	this->money = r.money;
	this->index = r.index;

	return *this;
}

void Happy::use(char *lp, int n) {
	money -= n;

	list[index] = new char[strlen(lp) + 1];
	strcpy(list[index], lp);

	index++;
}

Happy& Happy::winner(Happy &r) {
	if (money > r.money)
		return *this;
	else
		return r;
}

void Happy::setName(string &name) {
	this->name = name;
}

string& Happy::getName() {
	return name;
}

void Happy::setMoney(int money) {
	this->money = money;
}

int Happy::getMoney() {
	return money;
}

char** Happy::getList() {
	return list;
}

int Happy::getIndex() {
	return index;
}

int main()
{
	Happy a("철이"), b("메텔"), w;
	char item[100];
	int price;

	cout << "철이가 돈을 씁니다..." << endl;

	while (1) {
		cout << "구입 내역 : ";
		cin >> item;
		if (strcmp(item, "끝") == 0)
			break;

		cout << "금액 입력 : ";
		cin >> price;
		a.use(item, price);
	}

	cout << "메텔이 돈을 씁니다..." << endl;
	while (1) {
		cout << "구입 내역 : ";
		cin >> item;
		if (strcmp(item, "끝") == 0)
			break;

		cout << "금액 입력 : ";
		cin >> price;
		b.use(item, price);
	}

	cout << "최종 승자는?" << endl;
	w = a.winner(b);
	cout << w.getName() << "이고 총 " << w.getIndex()
		<< "건을 사용하고 남은 금액은 " << w.getMoney() << "원 입니다." << endl;

	cout << "사용 내역 : ";

	for(int i = 0; i < w.getIndex(); i++)
		cout << w.getList()[i] << " ";

	cout << endl;
}