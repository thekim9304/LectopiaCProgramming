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
	cout << "��ǰ�� : " << getMachineName();

	if (getPowerFlag() == true) {
		cout << "(ON) ";

		cout << "���� ���� : ";

		if (getMachineState() == NO_OPERATION)
			cout << "������";
		else if (getMachineState() == WARM)
			cout << "����";
		else if (getMachineState() == COOK)
			cout << "������";
		else
			cout << "�����";

		cout << endl;
	}
	else
		cout << "(OFF)" << endl;
}