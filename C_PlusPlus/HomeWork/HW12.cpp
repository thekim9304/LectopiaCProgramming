/*
	!! 로봇 일시키기 프로그램

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
	cout << "에너지가 부족해 요청한 동작을 수행할 수 없습니다." << endl;
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
		cout << name << " 전진..." << endl << endl;
		energy -= 10;
	}
}

void Robot::back() {
	if ((energy - 20) < 0) 
		errPrn();
	else {
		cout << name << " 후진..." << endl << endl;
		energy -= 20;
	}
}

void Robot::turn() {
	if ((energy - 30) < 0) 
		errPrn();
	else {
		cout << name << " 턴..." << endl << endl;
		energy -= 30;
	}
}

void Robot::jump() {
	if ((energy - 40) < 0) 
		errPrn();
	else {
		cout << name << " 점프..." << endl << endl;
		energy -= 40;
	}
}

void Robot::charge(int e) {

	if ((energy + e) < 0)
		cout << "에너지 충전 실패! " << endl;
	else {
		cout << e << "에너지 충전..." << endl;
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
		cout << "에너지 설정 실패..." << endl;
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
		cout << "구입할 로봇 대수를 입력하시오 : ";
		cin >> robotNum;

		if (robotNum <= 0) {
			cout << "양의 정수 개수를 입력 하세요!" << endl;
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

		cout << endl << "# 로봇명 선택(";
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
			cout << "목록에 있는 로봇명을 입력 하세요!!" << endl;
			continue;
		}

		activeNum = 0;

		while ((activeNum <= 0) || (activeNum > 5)) {
			cout << "# 할일 선택(1.전진/2.후진/3.회전/4.점프/5.충전) : ";
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
				cout << "# 충전할 에너지양 입력 : ";
				cin >> charg;
				robotList[i].charge(charg);
				break;
			default:
				ret = -1;
			}

				cout << "목록에 있는 할일을 입력 하세요!!" << endl;
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
	cout << "번 로봇명을 입력하시오 : ";
	my_flush();
	cin.getline(name, sizeof(name));
}

void input(char *name,int &energy)
{
	cout << name << "의 에너지 양을 입력 하시오 : ";
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