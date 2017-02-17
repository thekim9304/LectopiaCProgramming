#pragma once
#pragma once
#include <iostream>
using namespace std;

class MyString
{
private:
	char *str;  // ���ڿ��������������͸��
	int len;  // ���ڿ��Ǳ��̸�����
public:
	MyString();  // ����Ʈ������
	MyString(const char *cp);  // �����ε�������
	MyString(const MyString &br);  // ���������
	~MyString();  // �Ҹ���
	MyString &operator=(const MyString &br);  // ���Կ����ڸ���Լ�
	MyString operator+(const MyString &br);  // ����������
	bool operator>(const MyString &br);  // ���迬���ڸ���Լ�
	char * getStr();
	int getLen();
	void setStr(char *cp);
	void setLen(int n);
};