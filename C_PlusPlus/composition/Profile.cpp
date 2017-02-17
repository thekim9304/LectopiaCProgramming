#include <iostream>
using namespace std;
#include "Profile.h"

Profile::Profile() : name(), addr(), age(0), height(0)
{ }
//-----------------------------------------------------------------------------------
Profile::Profile(const char *np, const char *ap, int a, double h)
	: name(np), addr(ap), age(a), height(h)
{ }
//-----------------------------------------------------------------------------------
bool Profile::operator>(const Profile &br)
{
	if (height>br.height) return true;
	else return false;
}
//----------------------------------------------------------------------------------
MyString Profile::getName()
{
	return name;
}
//----------------------------------------------------------------------------------
MyString Profile::getAddr()
{
	return addr;
}
//----------------------------------------------------------------------------------
int Profile::getAge()
{
	return age;
}
//----------------------------------------------------------------------------------
double Profile::getHeight()
{
	return height;
}
//----------------------------------------------------------------------------------
void Profile::setName(MyString &br)
{
	name = br;
}
//----------------------------------------------------------------------------------
void Profile::setAddr(MyString &br)
{
	addr = br;
}
//----------------------------------------------------------------------------------
void Profile::setAge(int a)
{
	age = a;
}
//----------------------------------------------------------------------------------
void Profile::setHeight(double h)
{
	height = h;
}