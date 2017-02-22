/*
	!! �κ� �Ͻ�Ű�� ���α׷�

	@ 2017.02.15
*/

#if 01
#include <iostream>
#include <string.h>

using namespace std;

class Robot {
private:
	char *name;
	int energy;
	void errPrn();
public:
	Robot();
	~Robot() { delete[] name; }
	Robot(char *name, int energy = 0);
	Robot(Robot& r);
	Robot &operator=(const Robot &r);
	void go();
	void back();
	void turn();
	void jump();
	void charge(int e);
	char* getName();
	void setName(char *);
	int getEnergy();
	void setEnergy(int);
};

void Robot::errPrn() {
	cout << "�������� ������ ��û�� ������ ������ �� �����ϴ�." << endl;
}

Robot::Robot() {
	name = new char[strlen(" ")];
	name = " ";
	energy = 0;
}

Robot::Robot(char *name, int energy) {
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->energy = energy;
}

Robot::Robot(Robot& r) {
	delete[] this->name;

	this->name = new char[strlen(r.name) + 1];
	strcpy(this->name, r.name);
	this->energy = r.energy;
}

Robot& Robot::operator=(const Robot &r) {
	if (this->name == r.name)
		return *this;

	delete[] this->name;
	this->name = new char[strlen(r.name) + 1];
	strcpy(this->name, r.name);
	this->energy = r.energy;

	return *this;
}

void Robot::go() {
	if ((energy - 10) < 0) 
		errPrn();
	else{
		cout << name << " ����..." << endl << endl;
		energy -= 10;
	}
}

void Robot::back() {
	if ((energy - 20) < 0) 
		errPrn();
	else {
		cout << name << " ����..." << endl << endl;
		energy -= 20;
	}
}

void Robot::turn() {
	if ((energy - 30) < 0) 
		errPrn();
	else {
		cout << name << " ��..." << endl << endl;
		energy -= 30;
	}
}

void Robot::jump() {
	if ((energy - 40) < 0) 
		errPrn();
	else {
		cout << name << " ����..." << endl << endl;
		energy -= 40;
	}
}

void Robot::charge(int e) {

	if ((energy + e) < 0)
		cout << "������ ���� ����! " << endl;
	else {
		cout << e << "������ ����..." << endl;
		energy += e;
	}
}

char* Robot::getName() {
	return name;
}

void Robot::setName(char *name){
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

int Robot::getEnergy() {
	return energy;
}

void Robot::setEnergy(int energy) {
	if (energy < 0)
		cout << "������ ���� ����..." << endl;
	else
		this->energy = energy;
}

void input(char (&)[100]);
void input(char *, int &);
void work(Robot *, int);
void prn(Robot&);
void my_flush();

int main()
{
	Robot *robotList;
	char name[100];
	int robotNum = 0, energy;

	while (robotNum <= 0) {
		cout << "������ �κ� ����� �Է��Ͻÿ� : ";
		cin >> robotNum;

		if (robotNum <= 0) {
			cout << "���� ���� ������ �Է� �ϼ���!" << endl;
			my_flush();
		}
	}

	robotList = new Robot[robotNum];
	for (int i = 0; i < robotNum; i++) {
		cout << endl << i + 1;
		input(name);
		input(name, energy);

		robotList[i].setName(name);
		robotList[i].setEnergy(energy);
	}

	work(robotList, robotNum);

	for (int i = 0; i < robotNum; i++) {
		cout << i + 1 << ". ";
		prn(robotList[i]);
	}

	delete[] robotList;
}

void work(Robot *robotList, int robotNum)
{
	int i, ret, activeNum, charg;
	char name[100];

	my_flush();

	while (name != '\0') {
		ret = -1;

		cout << endl << "# �κ��� ����(";
		for (i = 0; i < robotNum - 1; i++)
			cout << robotList[i].getName() << ", ";
		cout << robotList[i].getName() << ") : ";

		cin.getline(name, sizeof(name) + 1);

		if (strcmp(name, "\0") == 0)
			return;

		for (i = 0; i < robotNum; i++) {
			if (strcmp(name, robotList[i].getName()) == 0) {
				ret = i;
				break;
			}
		}

		if (ret == -1) {
			cout << "��Ͽ� �ִ� �κ����� �Է� �ϼ���!!" << endl;
			continue;
		}

		activeNum = 0;

		while ((activeNum <= 0) || (activeNum > 5)) {
			cout << "# ���� ����(1.����/2.����/3.ȸ��/4.����/5.����) : ";
			cin >> activeNum;

			switch (activeNum) {
			case 1:
				robotList[i].go();
				break;
			case 2:
				robotList[i].back();
				break;
			case 3:
				robotList[i].turn();
				break;
			case 4:
				robotList[i].jump();
				break;
			case 5:
				cout << "# ������ �������� �Է� : ";
				cin >> charg;
				robotList[i].charge(charg);
				break;
			default:
				ret = -1;
			}

				cout << "��Ͽ� �ִ� ������ �Է� �ϼ���!!" << endl;
				my_flush();
			if (ret == -1) {
				continue;
			}

			my_flush();
		}
	}
}

void input(char (&name)[100])
{
	cout << "�� �κ����� �Է��Ͻÿ� : ";
	my_flush();
	cin.getline(name, sizeof(name));
}

void input(char *name,int &energy)
{
	cout << name << "�� ������ ���� �Է� �Ͻÿ� : ";
	cin >> energy;
}

void prn(Robot &r)
{
	cout << r.getName() << " : " << r.getEnergy() << endl;
}

void my_flush()
{
	cin.clear();
	while (cin.get() != '\n');
}
#endif