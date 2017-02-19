#pragma once
#include <iostream>

using namespace std;
#include "MyString.h"

class Profile {
private:
	string name;
	string addr;
	int age;
	double height;
public:
	Profile();
	Profile(const char *np, const char *ap, int a, double h);
	bool operator>(const Profile &br);
	int getAge();
	string getName();
	string getAddr();
	double getHeight();
	void setName(string &br);
	void setAddr(string &br);
	void setAge(int a);
	void setHeight(double h);
};