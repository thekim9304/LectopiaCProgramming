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
string Appliance::getMachineName() const  // machineName ����� ��ȯ �Լ�
{
	return machineName;
}
bool Appliance::getPowerFlag() const // powerFlag ��� �� ��ȯ �Լ� 
{
	return powerFlag;
}
int Appliance::getPowerConsumption() const // powerConsumtion ��� �� ��ȯ �Լ�
{
	return powerConsumption;
}
time_t Appliance::getStartHour() // startHour ��� �� ��ȯ �Լ�
{
	return startHour;
}
time_t Appliance::getUseHour() // useHour ��� �� ��ȯ �Լ�
{
	return useHour;
}
void Appliance::setMachineName(string machineName)  // machineName ��� �ʱ�ȭ �Լ�
{
	this->machineName = machineName;
}
void Appliance::setPowerFlag(bool powerFlag) // powerFlag ��� �ʱ�ȭ �Լ� 
{
	this->powerFlag = powerFlag;
}
void Appliance::setPowerConsumption(int powerConsumption) // powerConsumtion ��� �ʱ�ȭ �Լ�
{
	this->powerConsumption = powerConsumption;
}

bool Appliance::turnOn()// ��ǰ�� �Ѵ�
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