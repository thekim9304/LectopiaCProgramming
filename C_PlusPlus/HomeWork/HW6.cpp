/*
	!! �������� �µ��� str_prn�Լ��� �����ϰ� �����Ͽ� ���� ���α׷��� �ϼ�����. 
	   str_prn�Լ��� �ϳ��� �ۼ��ϸ� ���ڸ� ó���ϴ� �� ��° �Ű������� �⺻ �������ڸ� ����Ѵ�.

	@ 2017.02.14 
*/

#if 0
#include <iostream>

using namespace std;

int my_strlen(char *, char = '\0');

int main()
{
	char strIn[100], check;
	int strLength;

	cout << "���ڿ� �Է� : ";
	cin >> strIn;
	cout << "���ڿ��� ���� : " << my_strlen(strIn) << endl;

	cout << "���� �Է� : ";
	cin >> check;
	cout << check << "���� ������ ���� : " << my_strlen(strIn, check) << endl;

	cout << "���� �Է� : ";
	cin >> check;
	cout << check << "���� ������ ���� : " << my_strlen(strIn, check) << endl;
}

int my_strlen(char *str, char check)
{
	int count = 0;

	while (str[count++] != check) {
		if (str[count - 1] == '\0')
			break;
	}

	return count - 1;
}
#endif