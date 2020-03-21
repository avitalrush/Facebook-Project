#include "Status_Date.h"

Status_Date::Status_Date()
{
	time_t t = time(0);
	tm* now = localtime(&t);
	hour = now->tm_hour;
	minute = now->tm_min;
	second = time(0);
}