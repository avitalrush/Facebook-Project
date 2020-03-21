#include "Date.h"

Date::Date()
{
	time_t currentTime;
	tm* now;

	time(&currentTime);

	now = localtime(&currentTime);

	day = now->tm_mday;
	month = now->tm_mon;
	year = now->tm_year;
}
