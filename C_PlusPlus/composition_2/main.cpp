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

int cnt = 0;  // �Է� ���� �������� ������ ī��Ʈ�ϴ� ����

int main()
{
	userScreen();
	return 0;
}
//----------------------------------------------------------------------------------------------
void userScreen()
{
	Profile  ary[20];   // ������ ���� ��ü �迭
	int profileCnt;     // �Է� ���� �������� ���� ī��Ʈ ����
	char ch;          // �޴���ȣ ���� ���� 

	while (1)
	{
		ch = menu();        // �Էµ� �޴��� ��ȣ�� ch�� ���Ϲ���
		if (ch == '4') { break; }  // 4�� �����ϱ� �޴� �Է½� ���ѹݺ����� Ż��
		switch (ch)
		{
		case '1': profileCnt = proInput(ary); break;    // profileCnt�� parameter�� �޴� ����� ���� 
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
		cout << "# ������ ����� �̸� �Է� : ";
		cin >> inputName;

		if (inputName == "��")
			break;

		for (i = 0; i < profileCnt; i++) {
			if (ary[i].getName() == inputName)
				break;
		}

		if (i == profileCnt) {
			cout << "!! �׷� ��� �����ϴ�. " << endl << endl;
			continue;
		}

		cout << "    -> ���� �� Profile : ";
		cout << ary[i].getName() << " / ";
		cout << ary[i].getAddr() << " / ";
		cout << ary[i].getAge() << " / ";
		cout << ary[i].getHeight() << endl << endl;


		cout << "# ���� �׸� ���� : 1. �̸� / 2. �ּ� / 3. ���� / 4. ���� : ";
		cin >> selChange;
		cin.ignore();

		while (cin.fail() || ((selChange < 1) || (selChange > 4))) {
			my_flush();

			cout << "# ���� �׸� ���� : 1. �̸� / 2. �ּ� / 3. ���� / 4. ���� : ";
			cin >> selChange;
			cin.ignore();
		}


		switch (selChange) {
		case 1:
			cout << "  * �ٲ� �̸��� �Է� �ϼ��� : ";
			cin >> change;
			ary[i].setName(change);
			//ary[i].getName().setStr(changeStr);
			//ary[i].getName().setLen(strlen(changeStr));
			break;
		case 2:
			cout << "  * �ٲ� �ּҸ� �Է� �ϼ��� : ";
			cin >> changeStr;
			ary[i].setAddr(changeStr);
			break;
		case 3:
			cout << "  * �ٲ� ���̸� �Է� �ϼ��� : ";
			cin >> ageChange;
			cin.ignore();
			ary[i].setAge(ageChange);
			break;
		case 4:
			cout << "  * �ٲ� ������ �Է� �ϼ��� : ";
			cin >> heightChange;
			cin.ignore();
			ary[i].setHeight(heightChange);
			break;
		}

		cout << "    -> ���� �� Profile : ";
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
	char menulist[4][20] = { "������ �Է�", "������ ����", "������ ���","����" };

	for (i = 0; i<4; i++)   // �޴� ���ڿ��� ����ϴ� �ݺ���
	{
		cout << i + 1 << ". " << menulist[i] << endl;
	}

	while (n<'1' || n>'4') // ��ȿ�� ��ȣ�� �ƴϸ� �ٽ� �Է�
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
	//int cnt = 0;  // �Է� ���� �������� ������ ī��Ʈ�ϴ� ����

	while (1)
	{
		cout << "�̸��Է� : ";
		cin >> name;
		if (strcmp(name, "��") == 0) { break; }
		cout << "�ּ��Է� : ";		cin >> addr;
		cout << "�����Է� : ";		cin >> age;
		cout << "Ű�Է� : ";		cin >> height;

		ap[cnt] = Profile(name, addr, age, height); // �Է� ���� �����ͷ� ��ü �ʱ�ȭ
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
			<< ap[i].getAddr() << "/" << ap[i].getAge() << "��/"
			<< ap[i].getHeight() << "cm" << endl;
	}
}

void my_flush()
{
	cin.clear();

	while (cin.get() != '\n');

	cin.ignore();
}