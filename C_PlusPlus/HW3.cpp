#include <iostream>

using namespace std;

class student {
private:
	char name[20];
	int kor, eng, math;
	float sum, ave;
public:
	void input();
	void output();
};

void student::input() {
	cout << "�̸� : ";
	cin.getline(name, sizeof(name));
	cout << "�� ������ ���� : ";
	cin >> kor >> eng >> math;
}

void student::output() {
	sum = kor + eng + math;
	ave = sum / 3.0;

	cout << "    " << name;
	cout << "       " << kor << "         " << eng;
	cout << "         " << math << "         " << sum;
	cout.setf(ios_base::fixed);
	cout.precision(2);
	cout << "       " << ave << endl;
}

int main()
{
	student stu;

	stu.input();

	cout << "                        ====< ����ǥ >====       " << endl;
	cout << "===================================================================" << endl;
	cout << "     �̸�       ����       ����       ����       ����       ���" << endl;
	cout << "===================================================================" << endl;

	stu.output();
}