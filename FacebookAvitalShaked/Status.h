#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#include <iostream>

#ifndef __STATUS_H
#define __STATUS_H

#include "Status_Date.h"

const int TEXT_STATUS = 1;
const int PHOTO_STATUS = 2;
const int VIDEO_STATUS = 3;
const int TEXT_AND_PHOTO_STATUS = 4;
const int TEXT_AND_VIDEO_STATUS = 5;

class Status
{
private:
	Status_Date publish_date;
	int type;
	string name;

public:
	Status() = default;

	//OPERATORS
	bool operator==(const Status& other) const
	{
		Status* temp = (Status*)&other;
		return (this->type == temp->type);
	}
	bool operator!=(const Status& other) const
	{
		Status* temp = (Status*)&other;
		return (this->type != temp->type);
	}

	//METHODS
	Status(Status_Date date, int type, const string name) // c'tor
	{
		this->publish_date = date;
		this->type = type;
		this->name = name;
	}

	int get_status_type() { return type; }
	string get_name() { return this->name; }
	int get_sec() { return this->publish_date.get_second(); }

	~Status()
	{
	}
};
#endif //__STATUS_H