#include "HomeAutomation.h"

HomeAutomation::HomeAutomation() // appliaceArray의 메모리 영역을 모두 0으로 초기화 하고, applianceCnt를 0으로 초기화
{
	for (int i = 0; i < APPLIANCE_MAX_CNT; ++i)
	{
		applianceArray[i] = NULL;
	}
	applianceCnt = 0;
}

HomeAutomation::HomeAutomation(const HomeAutomation &r)
{
	Washer *wa;
	RiceCooker *ri;
	AirConditioner *ai;

	for (int i = 0; i < r.applianceCnt; ++i)
	{
		if (ri = dynamic_cast<RiceCooker*>(r.applianceArray[i])) {
			applianceArray[i] = new RiceCooker;
			dynamic_cast<RiceCooker*>(applianceArray[i])->setMachineState(dynamic_cast<RiceCooker*>(r.applianceArray[i])->getMachineState());

		}
		else if (ai = dynamic_cast<AirConditioner*>(r.applianceArray[i])) {
			applianceArray[i] = new AirConditioner;
			dynamic_cast<AirConditioner*>(applianceArray[i])->setMachineState(dynamic_cast<AirConditioner*>(r.applianceArray[i])->getMachineState());

		}
		else if (wa = dynamic_cast<Washer*>(r.applianceArray[i])) {
			applianceArray[i] = new Washer;
			dynamic_cast<Washer*>(applianceArray[i])->setMachineState(dynamic_cast<Washer*>(r.applianceArray[i])->getMachineState());
		}

		applianceArray[i]->setMachineName(r.applianceArray[i]->getMachineName());
		applianceArray[i]->setPowerConsumption(r.applianceArray[i]->getPowerConsumption());
		applianceArray[i]->setPowerFlag(r.applianceArray[i]->getPowerFlag());
	}
	applianceCnt = r.applianceCnt;

}

HomeAutomation & HomeAutomation::operator=(const HomeAutomation &r)
{
	Washer *wa;
	RiceCooker *ri;
	AirConditioner *ai;

	for (int i = 0; i < r.applianceCnt; ++i)
	{
		if (applianceArray[i] != NULL)
		{
			delete applianceArray[i];
		}

		if (ri = dynamic_cast<RiceCooker*>(r.applianceArray[i])) {
			delete applianceArray[i];
			applianceArray[i] = new RiceCooker;
			dynamic_cast<RiceCooker*>(applianceArray[i])->setMachineState(dynamic_cast<RiceCooker*>(r.applianceArray[i])->getMachineState());
		}
		else if (ai = dynamic_cast<AirConditioner*>(r.applianceArray[i])) {
			delete applianceArray[i];
			applianceArray[i] = new AirConditioner;
			dynamic_cast<AirConditioner*>(applianceArray[i])->setMachineState(dynamic_cast<AirConditioner*>(r.applianceArray[i])->getMachineState());
		}
		else if (wa = dynamic_cast<Washer*>(r.applianceArray[i])) {
			delete applianceArray[i];
			applianceArray[i] = new Washer;
			dynamic_cast<Washer*>(applianceArray[i])->setMachineState(dynamic_cast<Washer*>(r.applianceArray[i])->getMachineState());
		}


		applianceArray[i]->setMachineName(r.applianceArray[i]->getMachineName());
		applianceArray[i]->setPowerConsumption(r.applianceArray[i]->getPowerConsumption());
		applianceArray[i]->setPowerFlag(r.applianceArray[i]->getPowerFlag());


	}
	applianceCnt = r.applianceCnt;
	return *this;
}

int HomeAutomation::searchMachine(string machineName) // 가전제품명에 해당하는 가전제품을 찾아서 배열의 index리턴/없을 시 -1 리턴
{
	for (int i = 0; i < applianceCnt; ++i)
	{
		if (applianceArray[i]->getMachineName() == machineName)
		{
			return i;
		}
	}
	return -1;
}

bool HomeAutomation::deleteAppliance(string machineName) // 가전제품명에 해당하는 가전제품을 목록에서 삭제하다
{
	int index, i;
	Washer *wa;
	RiceCooker *ri;
	AirConditioner *ai;

	index = searchMachine(machineName);

	if (index != -1) {
		delete applianceArray[index];

		for (i = index; i < applianceCnt - 1; i++) {
			applianceArray[i] = applianceArray[i + 1];

		}
		//delete applianceArray[i];
		applianceCnt--;

		return true;
	}

	return false;
}

Appliance ** HomeAutomation::getApplianceArray()// applianceArray 멤버 값 반환 함수
{
	return applianceArray;
}

int HomeAutomation::getApplianceCnt() const // applianceCnt 멤버 값 반환 함수
{
	return applianceCnt;
}

bool HomeAutomation::addAppliance(Appliance *ap) {
	Washer *wa;
	RiceCooker *ri;
	AirConditioner *ai;

	for (int i = 0; i < applianceCnt; i++) {
		if (applianceArray[i]->getMachineName() == ap->getMachineName())
			return false;
	}

	if (ri = dynamic_cast<RiceCooker*>(ap)) {
		applianceArray[applianceCnt] = new RiceCooker;
	}
	else if (ai = dynamic_cast<AirConditioner*>(ap)) {
		applianceArray[applianceCnt] = new AirConditioner;
	}
	else if (wa = dynamic_cast<Washer*>(ap)) {
		applianceArray[applianceCnt] = new Washer;
	}

	applianceArray[applianceCnt]->setMachineName(ap->getMachineName());
	applianceArray[applianceCnt]->setPowerConsumption(ap->getPowerConsumption());
	applianceArray[applianceCnt]->setPowerFlag(ap->getPowerFlag());

	applianceCnt++;

	return true;
}

void HomeAutomation::listDisplayAppliance() {
	for (int i = 0; i < applianceCnt; i++)
		applianceArray[i]->stateView();
}

bool HomeAutomation::controlAppliance(string machineName) {
	int index, selectNum;
	char power;


	index = searchMachine(machineName);

	if (index == -1)
		return false;

	if (applianceArray[index]->getPowerFlag() == 0) {
		cout << "전원을 켜시겠습니까?(Y/N) : ";
		cin >> power;

		if (power == 'Y' || power == 'y')
			applianceArray[index]->turnOn();
		else if (power == 'N' || power == 'n')
			return true;
		else
			return false;
	}

	if (applianceArray[index]->getPowerFlag()) {
		setStateAppliance(applianceArray[index]);
		return true;
	}
}


void HomeAutomation::setStateAppliance(Appliance * ap) {
	int selectNum;
	Washer *wa;
	RiceCooker *ri;
	AirConditioner *ai;

	if (ri = dynamic_cast<RiceCooker*>(ap)) {
		cout << "1.무동작 / 2.보온 / 3.밥짓기 / 4.데우기 / 5.끄기 : ";
		cin >> selectNum;
		cin.ignore();

		while (cin.fail() || ((selectNum < 1) || (selectNum > 5))) {
			myFlush();
			cout << "1.무동작 / 2.보온 / 3.밥짓기 / 4.데우기 / 5.끄기 : ";
			cin >> selectNum;
		}

		if (selectNum == 5) {
			ap->turnOff();
			return;
		}
		else {
			dynamic_cast<RiceCooker*>(ap)->setMachineState(selectNum);
			return;
		}
	}
	else if (ai = dynamic_cast<AirConditioner*>(ap)) {
		cout << "1.송풍 / 2.냉방 / 3.난방 / 4.끄기 : ";
		cin >> selectNum;

		while (cin.fail() || ((selectNum < 1) || (selectNum > 4))) {
			myFlush();
			cout << "1.송풍 / 2.냉방 / 3.난방 / 4.끄기 : ";
			cin >> selectNum;
		}

		if (selectNum == 4) {
			ap->turnOff();
			return;
		}
		
		dynamic_cast<AirConditioner*>(ap)->setMachineState(selectNum);
		
		int temperIn = 0;
		while (1) {
			cout << "1.온도 올리기 / 2.온도 내리기 / 3.온도조절 종료 : ";
			cin >> temperIn;

			while (cin.fail() || ((selectNum < 1) || (selectNum > 3))) {
				myFlush();
				cout << "1.온도 올리기 / 2.온도 내리기 / 3.온도조절 종료 : ";
				cin >> temperIn;
			}

			if (temperIn == 3)
				break;
			else if (temperIn == 1)
				dynamic_cast<AirConditioner*>(ap)->operator++();
			else if (temperIn == 2)
				dynamic_cast<AirConditioner*>(ap)->operator--();
		}

		return;
		
	}
	else if (wa = dynamic_cast<Washer*>(ap)) {
		cout << "1.무동작 / 2.일반빨래 / 3.삶은빨래 / 4.건조 / 5.끄기 : ";
		cin >> selectNum;

		while (cin.fail() || ((selectNum < 1) || (selectNum > 5))) {
			myFlush();
			cout << "1.무동작 / 2.일반빨래 / 3.삶은빨래 / 4.건조 / 5.끄기 : ";
			cin >> selectNum;
		}

		if (selectNum == 5) {
			ap->turnOff();
			return;
		}
		else {
			dynamic_cast<Washer*>(ap)->setMachineState(selectNum);
			return;
		}
	}
}


HomeAutomation::~HomeAutomation() {
	for (int i = 0; i < applianceCnt; i++)
		delete applianceArray[i];
}