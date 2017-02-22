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
	cout << "제품명 : " << getMachineName();

	if (getPowerFlag() == true) {
		cout << "(ON) ";

		cout << "설정 상태 : ";

		if (getMachineState() == SENDAIR)
			cout << "송풍(";
		else if (getMachineState() == COOLER)
			cout << "냉방(";
		else
			cout << "난방(";

		cout << "설정온도 : " << getSetTemperature() << ")" << endl;
	}
	else
		cout << "(OFF)" << endl;
}
