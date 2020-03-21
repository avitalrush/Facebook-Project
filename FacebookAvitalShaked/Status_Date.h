#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#include <iostream>

#ifndef __STATUS_DATE_H
#define __STATUS_DATE_H

#include "Date.h"
#include <ctime>
#include <time.h>

class Status_Date : public Date
{
private:
	int hour;
	int minute;
	int second;

public:
	Status_Date();

	int get_hour() { return hour; }
	int get_minute() { return minute; }
	int get_second() { return second; }

	~Status_Date() {};
};
#endif //__STATUS_DATE_H