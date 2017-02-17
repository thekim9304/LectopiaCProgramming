/*
	!! 피트니스 클럽 회원관리 프로그램

	- 클럽회원의 등록 가능한 회원수는 최대 100명으로 제한한다.

	- 사용 메뉴 1.회원등록/ 2.회원전체보기/ 3.회원정보검색/ 4.회원탈퇴/ 5. 특별관리 회원/ 6. 종료

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
		cout << "                                    메인 메뉴" << endl;
		cout << "*********************************************************************************" << endl;

		cout << "▷ 1. 회원 등록" << endl;
		cout << "▷ 2. 회원 전체보기" << endl;
		cout << "▷ 3. 회원 정보탐색" << endl;
		cout << "▷ 4. 회원 탈퇴" << endl;
		cout << "▷ 5. 특별관리 회원" << endl;
		cout << "▷ 6. 종료" << endl;
		cout << "▷▷▷ 수행할 작업을 선택 하세요 : ";
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

	cout << "                             회원 관리를 종료 합니다..." << endl;
	cout << "*********************************************************************************" << endl;
	
	delete[] fary;
}

void memberRegister(Fitness *&fary) 
{
	char name[100];
	double weight, height;
	
	cout << "=================================================================================" << endl;
	cout << "                               신규 회원 등록" << endl;
	cout << "=================================================================================" << endl << endl << endl;
	
	cout << "▶ 이름을 입력 하세요 ▶ ";
	cin.getline(name, sizeof(name));

	cout << "▶ 키를 입력 하세요 ▶ ";
	cin >> height;
	while (cin.fail() || height <= 0) {
		my_flush();

		cout << "사람이 아닙니다... 키를 재입력 하세요 : ";
		cin >> height;
	}
	
	cout << "▶ 몸무게를 입력 하세요 ▶ ";
	cin >> weight;
	while (cin.fail() || height <= 0) {
		my_flush();

		cout << "사람이 아닙니다... 몸무게를 재입력 하세요 : ";
		cin >> height;
	}
	cin.ignore();

	memberCnt++;

	fary[memberCnt - 1].setName(name);
	fary[memberCnt - 1].setNum(memberCnt);
	fary[memberCnt - 1].setHeight(height);
	fary[memberCnt - 1].setWeight(weight);

	cout << endl << "========== [ 입력 완료 !! ] ==========" << endl << endl;
	cout << "회원 번호 : " << fary[memberCnt - 1].getNum() << endl;
	cout << "     이름 : " << fary[memberCnt - 1].getName() << endl;
	cout << "       키 : " << fary[memberCnt - 1].getHeight() << endl;
	cout << "   몸무게 : " << fary[memberCnt - 1].getWeight() << endl;
	cout << "      BMI : " << fary[memberCnt - 1].bmi();

	if (fary[memberCnt - 1].bmi() < 18.5)
		cout << " (저체중)" << endl << endl;
	else if ((fary[memberCnt - 1].bmi() >= 18.5) && (fary[memberCnt - 1].bmi() < 25.0))
		cout << " (정상체중)" << endl << endl;
	else if ((fary[memberCnt - 1].bmi() >= 25.0) && (fary[memberCnt - 1].bmi() < 30.0))
		cout << " (과체중)  !!특관" << endl << endl;
	else if ((fary[memberCnt - 1].bmi() >= 30.0) && (fary[memberCnt - 1].bmi() < 40.0))
		cout << " (비만)  !!특관" << endl << endl;
	else
		cout << " (고도비만) !!특관" << endl << endl;

	cout << "                               현재 회원 수 : " << memberCnt << endl;
	cout << "=================================================================================" << endl << endl << endl;
}

void memberAllList(Fitness *(&fary))
{
	cout << "=================================================================================" << endl;
	cout << "                               전체 회원 목록" << endl;
	cout << "=================================================================================" << endl << endl << endl;

	for (int i = 0; i < memberCnt; i++) {
		cout << "[ " << i + 1 << "번 ]" << endl;
		cout << "     이름 : " << fary[i].getName() << endl;
		cout << "       키 : " << fary[i].getHeight() << endl;
		cout << "   몸무게 : " << fary[i].getWeight() << endl;
		cout << "      BMI : " << fary[i].bmi();

		if (fary[i].bmi() < 18.5)
			cout << " (저체중)" << endl << endl;
		else if ((fary[i].bmi() >= 18.5) && (fary[i].bmi() < 25.0))
			cout << " (정상체중)" << endl << endl;
		else if ((fary[i].bmi() >= 25.0) && (fary[i].bmi() < 30.0))
			cout << " (과체중)  !!특관" << endl << endl;
		else if ((fary[i].bmi() >= 30.0) && (fary[i].bmi() < 40.0))
			cout << " (비만)  !!특관" << endl << endl;
		else
			cout << " (고도비만) !!특관" << endl << endl;
	}

	cout << "                               현재 회원 수 : " << memberCnt << endl;
	cout << "=================================================================================" << endl << endl << endl;
}

void memberInfoSearch(Fitness *(&fary))
{
	char name[100];
	int i;

	cout << "=================================================================================" << endl;
	cout << "                               회원 정보 검색" << endl;
	cout << "=================================================================================" << endl << endl << endl;

	while (1) {
		cout << "★ 찾을 회원의 이름을 입력 하세요 ('끝' 입력시 종료)★ ";
		cin.getline(name, sizeof(name));

		if (strcmp(name, "끝") == 0)
			break;

		for (i = 0; i < memberCnt; i++) {
			if (strcmp(fary[i].getName(), name) == 0)
				break;
		}

		if (i == memberCnt) {
			cout << "그런 사람 여기 없습니다 !!" << endl;
			continue;
		}
		else {
			cout << "[ " << i + 1 << "번 회원 ]" << endl;
			cout << "     이름 : " << fary[i].getName() << endl;
			cout << "       키 : " << fary[i].getHeight() << endl;
			cout << "   몸무게 : " << fary[i].getWeight() << endl;
			cout << "      BMI : " << fary[i].bmi();

			if (fary[i].bmi() < 18.5)
				cout << " (저체중)" << endl << endl;
			else if ((fary[i].bmi() >= 18.5) && (fary[i].bmi() < 25.0))
				cout << " (정상체중)" << endl << endl;
			else if ((fary[i].bmi() >= 25.0) && (fary[i].bmi() < 30.0))
				cout << " (과체중)  !!특관" << endl << endl;
			else if ((fary[i].bmi() >= 30.0) && (fary[i].bmi() < 40.0))
				cout << " (비만)  !!특관" << endl << endl;
			else
				cout << " (고도비만) !!특관" << endl << endl;
		}
	}

	cout << "                               현재 회원 수 : " << memberCnt << endl;
	cout << "=================================================================================" << endl << endl << endl;
}

void memberWithDraw(Fitness *(&fary))
{
	Fitness withdraw;
	int withdrawNum, i;

	cout << "=================================================================================" << endl;
	cout << "                                  회원 탈퇴" << endl;
	cout << "=================================================================================" << endl << endl << endl;

	if (memberCnt == 0) {
		cout << "회원이 하나도 없습니다. " << endl << endl;
		return;
	}

	cout << "★ 탈퇴할 회원의 번호를 입력 하세요 ★ ";
	cin >> withdrawNum;
	withdraw.setNum(withdrawNum);

	for (i = 0; i < memberCnt; i++) {
		if (fary[i].getNum() == withdraw.getNum())
			break;
	}

	if (i == memberCnt) {
		cout << "그런 사람 여기 없습니다 !!" << endl;
		my_flush();
		return;
	}
	else {
		cout << "[ " << fary[i].getNum() << "번 회원 ]을 목록에서 지웁니다." << endl << endl;

		for (i = withdrawNum - 1; i < memberCnt; i++)
			fary[i] = fary[i + 1];

		memberCnt--;
	}

	cout << "                                  현재 회원 수 : " << memberCnt << endl;
	cout << "=================================================================================" << endl << endl << endl;
}

void focusMember(Fitness *(&fary))
{
	int specialCnt = 0;

	cout << "=================================================================================" << endl;
	cout << "                             특별 관리 회원 정보" << endl;
	cout << "=================================================================================" << endl << endl << endl;

	for (int i = 0; i < memberCnt; i++) {
		if (fary[i].bmi() >= 25.0) {
			cout << "[ " << i + 1 << "번 회원 ]" << endl;
			cout << "     이름 : " << fary[i].getName() << endl;
			cout << "       키 : " << fary[i].getHeight() << endl;
			cout << "   몸무게 : " << fary[i].getWeight() << endl;
			cout << "      BMI : " << fary[i].bmi();

			if ((fary[memberCnt - 1].bmi() >= 25.0) && (fary[memberCnt - 1].bmi() < 30.0))
				cout << " (과체중) " << endl << endl;
			else if ((fary[memberCnt - 1].bmi() >= 30.0) && (fary[memberCnt - 1].bmi() < 40.0))
				cout << " (비만) " << endl << endl;
			else
				cout << " (고도비만) " << endl << endl;

			specialCnt++;
		}
	}

	cout << "                             특별 관리 회원 수 : " << specialCnt << endl;
	cout << "=================================================================================" << endl << endl << endl;
}

void my_flush()
{
	cin.clear();

	while (cin.get() != '\n');
}