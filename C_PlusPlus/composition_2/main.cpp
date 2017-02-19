#include <iostream>
#include <string>
#include "Profile.h"
using namespace std;

void userScreen(void);
char menu(void);
int proInput(Profile *);
void proDisplay(Profile *, int);
void proUpdate(Profile *, int);
void my_flush();

int cnt = 0;  // 입력 받은 프로필의 개수를 카운트하는 변수

int main()
{
	userScreen();
	return 0;
}
//----------------------------------------------------------------------------------------------
void userScreen()
{
	Profile  ary[20];   // 프로필 저장 객체 배열
	int profileCnt;     // 입력 받은 프로필의 개수 카운트 변수
	char ch;          // 메뉴번호 저장 변수 

	while (1)
	{
		ch = menu();        // 입력된 메뉴의 번호를 ch에 리턴받음
		if (ch == '4') { break; }  // 4번 종료하기 메뉴 입력시 무한반복문을 탈출
		switch (ch)
		{
		case '1': profileCnt = proInput(ary); break;    // profileCnt를 parameter로 받는 방법도 있음 
		case '2' : proUpdate(ary,profileCnt); break;
		case '3': proDisplay(ary, profileCnt); break;
		}
	}
}

void proUpdate(Profile *ary, int profileCnt)
{
	string change;
	string inputName, changeStr;
	int i, selChange, ageChange;
	double heightChange;

	while (1) {
		cout << "# 수정할 사람의 이름 입력 : ";
		cin >> inputName;

		if (inputName == "끝")
			break;

		for (i = 0; i < profileCnt; i++) {
			if (ary[i].getName() == inputName)
				break;
		}

		if (i == profileCnt) {
			cout << "!! 그런 사람 없습니다. " << endl << endl;
			continue;
		}

		cout << "    -> 수정 전 Profile : ";
		cout << ary[i].getName() << " / ";
		cout << ary[i].getAddr() << " / ";
		cout << ary[i].getAge() << " / ";
		cout << ary[i].getHeight() << endl << endl;


		cout << "# 수정 항목 선택 : 1. 이름 / 2. 주소 / 3. 나이 / 4. 신장 : ";
		cin >> selChange;
		cin.ignore();

		while (cin.fail() || ((selChange < 1) || (selChange > 4))) {
			my_flush();

			cout << "# 수정 항목 선택 : 1. 이름 / 2. 주소 / 3. 나이 / 4. 신장 : ";
			cin >> selChange;
			cin.ignore();
		}


		switch (selChange) {
		case 1:
			cout << "  * 바꿀 이름을 입력 하세요 : ";
			cin >> change;
			ary[i].setName(change);
			//ary[i].getName().setStr(changeStr);
			//ary[i].getName().setLen(strlen(changeStr));
			break;
		case 2:
			cout << "  * 바꿀 주소를 입력 하세요 : ";
			cin >> changeStr;
			ary[i].setAddr(changeStr);
			break;
		case 3:
			cout << "  * 바꿀 나이를 입력 하세요 : ";
			cin >> ageChange;
			cin.ignore();
			ary[i].setAge(ageChange);
			break;
		case 4:
			cout << "  * 바꿀 신장을 입력 하세요 : ";
			cin >> heightChange;
			cin.ignore();
			ary[i].setHeight(heightChange);
			break;
		}

		cout << "    -> 수정 후 Profile : ";
		cout << ary[i].getName() << " / ";
		cout << ary[i].getAddr() << " / ";
		cout << ary[i].getAge() << " / ";
		cout << ary[i].getHeight() << endl << endl;
	}
}

//----------------------------------------------------------------------------------------------
char menu(void)
{
	char n = 0, i;
	char menulist[4][20] = { "프로필 입력", "프로필 수정", "프로필 출력","종료" };

	for (i = 0; i<4; i++)   // 메뉴 문자열을 출력하는 반복문
	{
		cout << i + 1 << ". " << menulist[i] << endl;
	}

	while (n<'1' || n>'4') // 유효한 번호가 아니면 다시 입력
	{
		cout << "* Select menu No. : _\b";
		cin >> n;
	}
	return(n);
}
//--------------------------------------------------------------------------------------------
int proInput(Profile *ap)
{
	char name[50];
	char addr[80];
	int age;
	double height;
	//int cnt = 0;  // 입력 받은 프로필의 개수를 카운트하는 변수

	while (1)
	{
		cout << "이름입력 : ";
		cin >> name;
		if (strcmp(name, "끝") == 0) { break; }
		cout << "주소입력 : ";		cin >> addr;
		cout << "나이입력 : ";		cin >> age;
		cout << "키입력 : ";		cin >> height;

		ap[cnt] = Profile(name, addr, age, height); // 입력 받은 데이터로 객체 초기화
		cnt++;
	}
	return cnt;
}
//---------------------------------------------------------------
void proDisplay(Profile *ap, int cnt)
{
	int i;
	for (i = 0; i<cnt; i++)
	{
		cout << i + 1 << ". " << ap[i].getName() << " : "
			<< ap[i].getAddr() << "/" << ap[i].getAge() << "세/"
			<< ap[i].getHeight() << "cm" << endl;
	}
}

void my_flush()
{
	cin.clear();

	while (cin.get() != '\n');

	cin.ignore();
}