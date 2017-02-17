#pragma once
#pragma once
#include <iostream>
using namespace std;

class MyString
{
private:
	char *str;  // 문자열을연결할포인터멤버
	int len;  // 문자열의길이를저장
public:
	MyString();  // 디폴트생성자
	MyString(const char *cp);  // 오버로디드생성자
	MyString(const MyString &br);  // 복사생성자
	~MyString();  // 소멸자
	MyString &operator=(const MyString &br);  // 대입연산자멤버함수
	MyString operator+(const MyString &br);  // 덧셈연산자
	bool operator>(const MyString &br);  // 관계연산자멤버함수
	char * getStr();
	int getLen();
	void setStr(char *cp);
	void setLen(int n);
};