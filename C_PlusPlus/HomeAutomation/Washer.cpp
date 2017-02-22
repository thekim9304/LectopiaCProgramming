#include "Washer.h"

Washer::Washer() :Appliance() {
	machineState = NO_OPERATION;
};// Appliance는 default생성자로 생성, machineState는 무동작으로 초기화
Washer::Washer(string machineName, int powerConsumption) :Appliance(machineName, powerConsumption) // Appliance는 Overloaded 생성자로 생성, machineState는 무동작으로 초기화
{
	machineState = NO_OPERATION;
}												  // getter, setter member function
int Washer::getMachineState() const // machineState 멤버 값 반환 함수
{
	return machineState;
}
void Washer::setMachineState(int machineState) // machineState 멤버 초기화 함수
{
	if (machineState > 4 || machineState < 1)
	{
		return;
	}
	this->machineState = machineState;
}
// member function
void Washer::stateView()  // 객체의 상태 출력
{
	cout << "제품명 : " << getMachineName();

	if (getPowerFlag() == true) {
		cout << "(ON) ";

		cout << "설정 상태 : ";

		if (getMachineState() == NO_OPERATION)
			cout << "무동작";
		else if (getMachineState() == GENERAL)
			cout << "일반빨래";
		else if (getMachineState() == BOIL)
			cout << "삶은빨래";
		else
			cout << "건조";

		cout << endl;
	}
	else
		cout << "(OFF)" << endl;

}