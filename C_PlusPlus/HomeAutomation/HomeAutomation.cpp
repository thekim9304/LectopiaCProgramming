#include "HomeAutomation.h"

HomeAutomation::HomeAutomation() // appliaceArray�� �޸� ������ ��� 0���� �ʱ�ȭ �ϰ�, applianceCnt�� 0���� �ʱ�ȭ
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

int HomeAutomation::searchMachine(string machineName) // ������ǰ�� �ش��ϴ� ������ǰ�� ã�Ƽ� �迭�� index����/���� �� -1 ����
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

bool HomeAutomation::deleteAppliance(string machineName) // ������ǰ�� �ش��ϴ� ������ǰ�� ��Ͽ��� �����ϴ�
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

Appliance ** HomeAutomation::getApplianceArray()// applianceArray ��� �� ��ȯ �Լ�
{
	return applianceArray;
}

int HomeAutomation::getApplianceCnt() const // applianceCnt ��� �� ��ȯ �Լ�
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
		cout << "������ �ѽðڽ��ϱ�?(Y/N) : ";
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
		cout << "1.������ / 2.���� / 3.������ / 4.����� / 5.���� : ";
		cin >> selectNum;
		cin.ignore();

		while (cin.fail() || ((selectNum < 1) || (selectNum > 5))) {
			myFlush();
			cout << "1.������ / 2.���� / 3.������ / 4.����� / 5.���� : ";
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
		cout << "1.��ǳ / 2.�ù� / 3.���� / 4.���� : ";
		cin >> selectNum;

		while (cin.fail() || ((selectNum < 1) || (selectNum > 4))) {
			myFlush();
			cout << "1.��ǳ / 2.�ù� / 3.���� / 4.���� : ";
			cin >> selectNum;
		}

		if (selectNum == 4) {
			ap->turnOff();
			return;
		}
		
		dynamic_cast<AirConditioner*>(ap)->setMachineState(selectNum);
		
		int temperIn = 0;
		while (1) {
			cout << "1.�µ� �ø��� / 2.�µ� ������ / 3.�µ����� ���� : ";
			cin >> temperIn;

			while (cin.fail() || ((selectNum < 1) || (selectNum > 3))) {
				myFlush();
				cout << "1.�µ� �ø��� / 2.�µ� ������ / 3.�µ����� ���� : ";
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
		cout << "1.������ / 2.�Ϲݻ��� / 3.�������� / 4.���� / 5.���� : ";
		cin >> selectNum;

		while (cin.fail() || ((selectNum < 1) || (selectNum > 5))) {
			myFlush();
			cout << "1.������ / 2.�Ϲݻ��� / 3.�������� / 4.���� / 5.���� : ";
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