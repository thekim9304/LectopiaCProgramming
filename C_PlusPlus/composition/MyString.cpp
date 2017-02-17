#pragma warning (disable:4996)
#include <iostream>
#include <string.h>
#include "MyString.h"
using namespace std;

MyString::MyString()
{
	len = 0;
	str = new char[len + 1];
	strcpy(str, "");
}
//---------------------------------------------------------------------------------------
MyString::MyString(const char *cp)
{
	len = strlen(cp);
	str = new char[len + 1];
	strcpy(str, cp);
}
//---------------------------------------------------------------------------------------
MyString::MyString(const MyString &br)
{
	len = br.len;
	str = new char[len + 1];
	strcpy(str, br.str);
}
//---------------------------------------------------------------------------------------
MyString::~MyString()
{
	delete[] str;
}
//---------------------------------------------------------------------------------------
MyString &MyString::operator=(const MyString &br)
{
	if (this == &br) return *this;
	len = br.len;
	delete[] str;
	str = new char[len + 1];
	strcpy(str, br.str);
	return *this;
}
//---------------------------------------------------------------------------------------
MyString MyString::operator+(const MyString &br)
{
	int ln = len + br.len;
	char *tp = new char[ln + 1];
	strcpy(tp, str);
	strcat(tp, br.str);
	MyString temp(tp);
	delete[] tp;
	return temp;
}
//---------------------------------------------------------------------------------------
bool MyString::operator>(const MyString &br)
{
	if (len>br.len) return true;
	else return false;
}
//---------------------------------------------------------------------------------------
char * MyString::getStr()
{
	return str;
}
//---------------------------------------------------------------------------------------
int MyString::getLen()
{
	return len;
}
//---------------------------------------------------------------------------------------
void MyString::setStr(char *cp)
{
	if (this->str == cp) return; // 내 문자열을 내가 저장하려고 하면 리턴
	len = strlen(cp);
	delete[]str;
	str = new char[len + 1];
	strcpy(str, cp);
}
//----------------------------------------------------------------------------------------
void MyString::setLen(int n)
{
	len = n;
}
