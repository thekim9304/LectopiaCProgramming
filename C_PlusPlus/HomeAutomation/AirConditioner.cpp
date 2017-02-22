#include "AirConditioner.h"

AirConditioner::AirConditioner() : Appliance() {
	machineState = SENDAIR;
	setTemperature = 25;
}

AirConditioner::AirConditioner(string machineName, int powerConsumption) : Appliance(machineName, powerConsumption) {
	machineState = SENDAIR;
}

int AirConditioner::getMachineState() const {
	return machineState;
}

int AirConditioner::getSetTemperature() const {
	return setTemperature;
}

void AirConditioner::setMachineState(int machineState) {
	this->machineState = machineState;
}

void AirConditioner::setSetTemperature(int setTemperature) {
	this->setTemperature = setTemperature;
}

AirConditioner& AirConditioner::operator++() {
	setTemperature++;
	return *this;
}

AirConditioner& AirConditioner::operator--() {
	setTemperature--;
	return *this;
}

void AirConditioner::stateView(){
	cout << "��ǰ�� : " << getMachineName();

	if (getPowerFlag() == true) {
		cout << "(ON) ";

		cout << "���� ���� : ";

		if (getMachineState() == SENDAIR)
			cout << "��ǳ(";
		else if (getMachineState() == COOLER)
			cout << "�ù�(";
		else
			cout << "����(";

		cout << "�����µ� : " << getSetTemperature() << ")" << endl;
	}
	else
		cout << "(OFF)" << endl;
}
