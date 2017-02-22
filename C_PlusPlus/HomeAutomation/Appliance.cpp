#include "Appliance.h"

Appliance::Appliance()  // default constructor (machineName:Null string, powerFlag:false, powerConsumption:0, startHour:0, useHour:0)
{
	machineName = "";
	powerFlag = false;
	powerConsumption = 0;
	startHour = 0;
	useHour = 0;
}
Appliance::Appliance(string machineName, int powerConsumption, bool powerFlag, time_t startHour, time_t useHour)
{
	this->machineName = machineName;
	this->powerConsumption = powerConsumption;
	this->powerFlag = powerFlag;
	this->startHour = startHour;
	this->useHour = useHour;
}
// getter, setter member function
string Appliance::getMachineName() const  // machineName 멤버값 반환 함수
{
	return machineName;
}
bool Appliance::getPowerFlag() const // powerFlag 멤버 값 반환 함수 
{
	return powerFlag;
}
int Appliance::getPowerConsumption() const // powerConsumtion 멤버 값 반환 함수
{
	return powerConsumption;
}
time_t Appliance::getStartHour() // startHour 멤버 값 반환 함수
{
	return startHour;
}
time_t Appliance::getUseHour() // useHour 멤버 값 반환 함수
{
	return useHour;
}
void Appliance::setMachineName(string machineName)  // machineName 멤버 초기화 함수
{
	this->machineName = machineName;
}
void Appliance::setPowerFlag(bool powerFlag) // powerFlag 멤버 초기화 함수 
{
	this->powerFlag = powerFlag;
}
void Appliance::setPowerConsumption(int powerConsumption) // powerConsumtion 멤버 초기화 함수
{
	this->powerConsumption = powerConsumption;
}

bool Appliance::turnOn()// 제품을 켜다
{
	time_t current;
	if (powerFlag == false) { powerFlag = true; }
	time(&current);
	startHour = current;
	return powerFlag;

}
bool Appliance::turnOff()
{
	time_t current;
	time(&current);
	if (powerFlag == true) { powerFlag = false; }
	useHour = current - startHour;
	return !powerFlag;
}