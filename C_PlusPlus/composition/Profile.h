#pragma once
#include <iostream>

using namespace std;
#include "MyString.h"

class Profile {
private:
	MyString name;
	MyString addr;
	int age;
	double height;
public:
	Profile();
	Profile(const char *np, const char *ap, int a, double h);
	bool operator>(const Profile &br);
	MyString getName();
	MyString getAddr();
	int getAge();
	double getHeight();
	void setName(MyString &br);
	void setAddr(MyString &br);
	void setAge(int a);
	void setHeight(double h);
};