#include "RiceCooker.h"

RiceCooker::RiceCooker() : Appliance() {
	machineState = NO_OPERATION;
}

RiceCooker::RiceCooker(string machineName, int powerConsumption) : Appliance(machineName, powerConsumption) {
	machineState = NO_OPERATION;
}

int RiceCooker::getMachineState() const {
	return machineState;
}

void RiceCooker::setMachineState(int machineState) {
	this->machineState = machineState;
}

void RiceCooker::stateView() {
	cout << "제품명 : " << getMachineName();

	if (getPowerFlag() == true) {
		cout << "(ON) ";

		cout << "설정 상태 : ";

		if (getMachineState() == NO_OPERATION)
			cout << "무동작";
		else if (getMachineState() == WARM)
			cout << "보온";
		else if (getMachineState() == COOK)
			cout << "밥짓기";
		else
			cout << "데우기";

		cout << endl;
	}
	else
		cout << "(OFF)" << endl;
}