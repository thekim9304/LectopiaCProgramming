/*
	!! ��Ʈ�Ͻ� Ŭ�� ȸ������ ���α׷�

	- Ŭ��ȸ���� ��� ������ ȸ������ �ִ� 100������ �����Ѵ�.

	- ��� �޴� 1.ȸ�����/ 2.ȸ����ü����/ 3.ȸ�������˻�/ 4.ȸ��Ż��/ 5. Ư������ ȸ��/ 6. ����

	@ 2017.02.16
*/

#include <iostream>
#include <cstring>
#include <conio.h>

using namespace std;

int memberCnt;

class Fitness {
private:
	int num;
	char *name;
	double weight;
	double height;

public:
	Fitness();
	Fitness(int num, char *name, double weight, double height);

	void setNum(int num);
	Fitness(Fitness &r);
	~Fitness() { delete[] name; }

	Fitness &operator=(Fitness &r);
	double getHeight();

	bool operator==(Fitness &r);
	int getNum();
	void setName(char *name);
	char* getName();
	void setWeight(double weight);
	double getWeight();
	void setHeight(double height);
	double bmi();
};

Fitness::Fitness() {
	num = 0;
	name = new char[strlen("") + 1];
	strcpy(name, "");
	weight = 0;
	height = 0;
}

Fitness::Fitness(int num, char *name, double weight, double height) {
	this->num = num;

	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);

	this->weight = weight;
	this->height = height;
}

Fitness::Fitness(Fitness &r) {
	//delete[] this->name;
	
	num = r.num;
	this->name = new char[strlen(r.name) + 1];
	strcpy(this->name, r.name);
	height = r.height;
	weight = r.weight;
}

Fitness& Fitness::operator=(Fitness &r) {
	if (this->name == r.name)
		return *this;

	delete[] this->name;

	this->name = new char[strlen(r.name) + 1];
	strcpy(this->name, r.name);
	num = r.num;
	height = r.height;
	weight = r.weight;

	return *this;
}

bool Fitness::operator==(Fitness &r) {
	if (num == r.num)
		return true;
	
	return false;
}

void Fitness::setNum(int num) {
	this->num = num;
}

int Fitness::getNum() {
	return num;
}

void Fitness::setName(char *name) {
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

char* Fitness::getName() {
	return name;
}

void Fitness::setWeight(double weight) {
	this->weight = weight;
}

double Fitness::getWeight() {
	return weight;
}

void Fitness::setHeight(double height) {
	this->height = height;
}

double Fitness::getHeight() {
	return height;
}

double Fitness::bmi() {
	return weight / ((height * 0.01) * (height * 0.01));
}

void memberRegister(Fitness *&);
void memberAllList(Fitness *(&));
void memberInfoSearch(Fitness *(&));
void memberWithDraw(Fitness *(&));
void focusMember(Fitness *(&));
void my_flush();

int main()
{
	memberCnt = 0;
	Fitness *fary;
	int inputMenu;

	fary = new Fitness[100];
	
	while (1) {
		cout << "*********************************************************************************" << endl;
		cout << "                                    ���� �޴�" << endl;
		cout << "*********************************************************************************" << endl;

		cout << "�� 1. ȸ�� ���" << endl;
		cout << "�� 2. ȸ�� ��ü����" << endl;
		cout << "�� 3. ȸ�� ����Ž��" << endl;
		cout << "�� 4. ȸ�� Ż��" << endl;
		cout << "�� 5. Ư������ ȸ��" << endl;
		cout << "�� 6. ����" << endl;
		cout << "������ ������ �۾��� ���� �ϼ��� : ";
		cin >> inputMenu;
		cin.ignore();

		if (cin.fail() || ((inputMenu < 1) || (inputMenu > 6))) {
			my_flush();
			continue;
		}

		if (inputMenu == 6)
			break;

		switch (inputMenu) {
		case 1:
			memberRegister(fary);
			break;
		case 2:
			memberAllList(fary);
			break;
		case 3:
			memberInfoSearch(fary);
			break;
		case 4:
			memberWithDraw(fary);
			break;
		case 5:
			focusMember(fary);
			break;
		}
	}

	cout << "                             ȸ�� ������ ���� �մϴ�..." << endl;
	cout << "*********************************************************************************" << endl;
	
	delete[] fary;
}

void memberRegister(Fitness *&fary) 
{
	char name[100];
	double weight, height;
	
	cout << "=================================================================================" << endl;
	cout << "                               �ű� ȸ�� ���" << endl;
	cout << "=================================================================================" << endl << endl << endl;
	
	cout << "�� �̸��� �Է� �ϼ��� �� ";
	cin.getline(name, sizeof(name));

	cout << "�� Ű�� �Է� �ϼ��� �� ";
	cin >> height;
	while (cin.fail() || height <= 0) {
		my_flush();

		cout << "����� �ƴմϴ�... Ű�� ���Է� �ϼ��� : ";
		cin >> height;
	}
	
	cout << "�� �����Ը� �Է� �ϼ��� �� ";
	cin >> weight;
	while (cin.fail() || height <= 0) {
		my_flush();

		cout << "����� �ƴմϴ�... �����Ը� ���Է� �ϼ��� : ";
		cin >> height;
	}
	cin.ignore();

	memberCnt++;

	fary[memberCnt - 1].setName(name);
	fary[memberCnt - 1].setNum(memberCnt);
	fary[memberCnt - 1].setHeight(height);
	fary[memberCnt - 1].setWeight(weight);

	cout << endl << "========== [ �Է� �Ϸ� !! ] ==========" << endl << endl;
	cout << "ȸ�� ��ȣ : " << fary[memberCnt - 1].getNum() << endl;
	cout << "     �̸� : " << fary[memberCnt - 1].getName() << endl;
	cout << "       Ű : " << fary[memberCnt - 1].getHeight() << endl;
	cout << "   ������ : " << fary[memberCnt - 1].getWeight() << endl;
	cout << "      BMI : " << fary[memberCnt - 1].bmi();

	if (fary[memberCnt - 1].bmi() < 18.5)
		cout << " (��ü��)" << endl << endl;
	else if ((fary[memberCnt - 1].bmi() >= 18.5) && (fary[memberCnt - 1].bmi() < 25.0))
		cout << " (����ü��)" << endl << endl;
	else if ((fary[memberCnt - 1].bmi() >= 25.0) && (fary[memberCnt - 1].bmi() < 30.0))
		cout << " (��ü��)  !!Ư��" << endl << endl;
	else if ((fary[memberCnt - 1].bmi() >= 30.0) && (fary[memberCnt - 1].bmi() < 40.0))
		cout << " (��)  !!Ư��" << endl << endl;
	else
		cout << " (����) !!Ư��" << endl << endl;

	cout << "                               ���� ȸ�� �� : " << memberCnt << endl;
	cout << "=================================================================================" << endl << endl << endl;
}

void memberAllList(Fitness *(&fary))
{
	cout << "=================================================================================" << endl;
	cout << "                               ��ü ȸ�� ���" << endl;
	cout << "=================================================================================" << endl << endl << endl;

	for (int i = 0; i < memberCnt; i++) {
		cout << "[ " << i + 1 << "�� ]" << endl;
		cout << "     �̸� : " << fary[i].getName() << endl;
		cout << "       Ű : " << fary[i].getHeight() << endl;
		cout << "   ������ : " << fary[i].getWeight() << endl;
		cout << "      BMI : " << fary[i].bmi();

		if (fary[i].bmi() < 18.5)
			cout << " (��ü��)" << endl << endl;
		else if ((fary[i].bmi() >= 18.5) && (fary[i].bmi() < 25.0))
			cout << " (����ü��)" << endl << endl;
		else if ((fary[i].bmi() >= 25.0) && (fary[i].bmi() < 30.0))
			cout << " (��ü��)  !!Ư��" << endl << endl;
		else if ((fary[i].bmi() >= 30.0) && (fary[i].bmi() < 40.0))
			cout << " (��)  !!Ư��" << endl << endl;
		else
			cout << " (����) !!Ư��" << endl << endl;
	}

	cout << "                               ���� ȸ�� �� : " << memberCnt << endl;
	cout << "=================================================================================" << endl << endl << endl;
}

void memberInfoSearch(Fitness *(&fary))
{
	char name[100];
	int i;

	cout << "=================================================================================" << endl;
	cout << "                               ȸ�� ���� �˻�" << endl;
	cout << "=================================================================================" << endl << endl << endl;

	while (1) {
		cout << "�� ã�� ȸ���� �̸��� �Է� �ϼ��� ('��' �Է½� ����)�� ";
		cin.getline(name, sizeof(name));

		if (strcmp(name, "��") == 0)
			break;

		for (i = 0; i < memberCnt; i++) {
			if (strcmp(fary[i].getName(), name) == 0)
				break;
		}

		if (i == memberCnt) {
			cout << "�׷� ��� ���� �����ϴ� !!" << endl;
			continue;
		}
		else {
			cout << "[ " << i + 1 << "�� ȸ�� ]" << endl;
			cout << "     �̸� : " << fary[i].getName() << endl;
			cout << "       Ű : " << fary[i].getHeight() << endl;
			cout << "   ������ : " << fary[i].getWeight() << endl;
			cout << "      BMI : " << fary[i].bmi();

			if (fary[i].bmi() < 18.5)
				cout << " (��ü��)" << endl << endl;
			else if ((fary[i].bmi() >= 18.5) && (fary[i].bmi() < 25.0))
				cout << " (����ü��)" << endl << endl;
			else if ((fary[i].bmi() >= 25.0) && (fary[i].bmi() < 30.0))
				cout << " (��ü��)  !!Ư��" << endl << endl;
			else if ((fary[i].bmi() >= 30.0) && (fary[i].bmi() < 40.0))
				cout << " (��)  !!Ư��" << endl << endl;
			else
				cout << " (����) !!Ư��" << endl << endl;
		}
	}

	cout << "                               ���� ȸ�� �� : " << memberCnt << endl;
	cout << "=================================================================================" << endl << endl << endl;
}

void memberWithDraw(Fitness *(&fary))
{
	Fitness withdraw;
	int withdrawNum, i;

	cout << "=================================================================================" << endl;
	cout << "                                  ȸ�� Ż��" << endl;
	cout << "=================================================================================" << endl << endl << endl;

	if (memberCnt == 0) {
		cout << "ȸ���� �ϳ��� �����ϴ�. " << endl << endl;
		return;
	}

	cout << "�� Ż���� ȸ���� ��ȣ�� �Է� �ϼ��� �� ";
	cin >> withdrawNum;
	withdraw.setNum(withdrawNum);

	for (i = 0; i < memberCnt; i++) {
		if (fary[i].getNum() == withdraw.getNum())
			break;
	}

	if (i == memberCnt) {
		cout << "�׷� ��� ���� �����ϴ� !!" << endl;
		my_flush();
		return;
	}
	else {
		cout << "[ " << fary[i].getNum() << "�� ȸ�� ]�� ��Ͽ��� ����ϴ�." << endl << endl;

		for (i = withdrawNum - 1; i < memberCnt; i++)
			fary[i] = fary[i + 1];

		memberCnt--;
	}

	cout << "                                  ���� ȸ�� �� : " << memberCnt << endl;
	cout << "=================================================================================" << endl << endl << endl;
}

void focusMember(Fitness *(&fary))
{
	int specialCnt = 0;

	cout << "=================================================================================" << endl;
	cout << "                             Ư�� ���� ȸ�� ����" << endl;
	cout << "=================================================================================" << endl << endl << endl;

	for (int i = 0; i < memberCnt; i++) {
		if (fary[i].bmi() >= 25.0) {
			cout << "[ " << i + 1 << "�� ȸ�� ]" << endl;
			cout << "     �̸� : " << fary[i].getName() << endl;
			cout << "       Ű : " << fary[i].getHeight() << endl;
			cout << "   ������ : " << fary[i].getWeight() << endl;
			cout << "      BMI : " << fary[i].bmi();

			if ((fary[memberCnt - 1].bmi() >= 25.0) && (fary[memberCnt - 1].bmi() < 30.0))
				cout << " (��ü��) " << endl << endl;
			else if ((fary[memberCnt - 1].bmi() >= 30.0) && (fary[memberCnt - 1].bmi() < 40.0))
				cout << " (��) " << endl << endl;
			else
				cout << " (����) " << endl << endl;

			specialCnt++;
		}
	}

	cout << "                             Ư�� ���� ȸ�� �� : " << specialCnt << endl;
	cout << "=================================================================================" << endl << endl << endl;
}

void my_flush()
{
	cin.clear();

	while (cin.get() != '\n');
}