#include "Washer.h"

Washer::Washer() :Appliance() {
	machineState = NO_OPERATION;
};// Appliance�� default�����ڷ� ����, machineState�� ���������� �ʱ�ȭ
Washer::Washer(string machineName, int powerConsumption) :Appliance(machineName, powerConsumption) // Appliance�� Overloaded �����ڷ� ����, machineState�� ���������� �ʱ�ȭ
{
	machineState = NO_OPERATION;
}												  // getter, setter member function
int Washer::getMachineState() const // machineState ��� �� ��ȯ �Լ�
{
	return machineState;
}
void Washer::setMachineState(int machineState) // machineState ��� �ʱ�ȭ �Լ�
{
	if (machineState > 4 || machineState < 1)
	{
		return;
	}
	this->machineState = machineState;
}
// member function
void Washer::stateView()  // ��ü�� ���� ���
{
	cout << "��ǰ�� : " << getMachineName();

	if (getPowerFlag() == true) {
		cout << "(ON) ";

		cout << "���� ���� : ";

		if (getMachineState() == NO_OPERATION)
			cout << "������";
		else if (getMachineState() == GENERAL)
			cout << "�Ϲݻ���";
		else if (getMachineState() == BOIL)
			cout << "��������";
		else
			cout << "����";

		cout << endl;
	}
	else
		cout << "(OFF)" << endl;

}