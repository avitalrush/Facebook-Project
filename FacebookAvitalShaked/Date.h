#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#include <iostream>

#ifndef __DATE_H
#define __DATE_H

#include <ctime>
#include <time.h>

class Date
{
private:
	int day;
	int month;
	int year;

public:
	Date();
	Date(int day, int month, int year)
	{
		this->day = day;
		this->month = month;
		this->year = year;
	}

	int get_day() { return day; }
	int get_month() { return month; }
	int get_year() { return year; }

	~Date() {};
};
#endif //__DATE_H