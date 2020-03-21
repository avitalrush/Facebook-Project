#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#include <iostream>
#include <vector>

#ifndef __BOARD_H
#define __BOARD_H

#include "Status.h"

class Board
{
private:
	vector<Status*> Status_Array;

public:
	Board() {};

	void add_new_status(Status* status);
	vector<Status*> get_all_status() { return Status_Array; }
	int get_num_of_status() { return this->Status_Array.size(); }

	~Board()
	{
	}
};

#endif //__BOARD_H