#include "PlayTime.h"
#include <time.h>


PlayTime::PlayTime()
{
}


PlayTime::~PlayTime()
{
}

int PlayTime::elapsedTime(int startTime)
{
	int ingTime;
	time_t current;
	time(&current);
	ingTime = current;

	return (ingTime - startTime);
}
