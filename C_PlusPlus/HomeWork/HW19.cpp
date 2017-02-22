/*
	!! ö�̿� ������ ������ �ູ�� �Կ��Ѵ�. ���� 10000���� �ܾ��� ������ �����ϸ�,
	��볻���� �ݾ��� �Է��� �Ŀ� �ܾ��� ���� ����� �����͸� ����Ѵ�.
	��볻���� 100�� �̳�

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
	Happy a("ö��"), b("����"), w;
	char item[100];
	int price;

	cout << "ö�̰� ���� ���ϴ�..." << endl;

	while (1) {
		cout << "���� ���� : ";
		cin >> item;
		if (strcmp(item, "��") == 0)
			break;

		cout << "�ݾ� �Է� : ";
		cin >> price;
		a.use(item, price);
	}

	cout << "������ ���� ���ϴ�..." << endl;
	while (1) {
		cout << "���� ���� : ";
		cin >> item;
		if (strcmp(item, "��") == 0)
			break;

		cout << "�ݾ� �Է� : ";
		cin >> price;
		b.use(item, price);
	}

	cout << "���� ���ڴ�?" << endl;
	w = a.winner(b);
	cout << w.getName() << "�̰� �� " << w.getIndex()
		<< "���� ����ϰ� ���� �ݾ��� " << w.getMoney() << "�� �Դϴ�." << endl;

	cout << "��� ���� : ";

	for(int i = 0; i < w.getIndex(); i++)
		cout << w.getList()[i] << " ";

	cout << endl;
}