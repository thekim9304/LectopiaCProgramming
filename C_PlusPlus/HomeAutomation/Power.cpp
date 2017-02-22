#include "Power.h"
#include "HomeAutomation.h"

int Power::calPowerConsumption(HomeAutomation &rHa)
{
	time_t current;
	time(&current);


	int sum = 0;
	for (int i = 0; i < rHa.applianceCnt; ++i)
	{
		if(rHa.applianceArray[i]->getStartHour() > 0)
			sum += (current - rHa.applianceArray[i]->getStartHour()) * (rHa.applianceArray[i]->getPowerConsumption() / 3600);
	}
	return sum;
}