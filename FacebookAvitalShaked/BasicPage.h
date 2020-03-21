#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#include <iostream>
#include <string.h>
#include "Board.h"
#include <string>
#include <vector>

#ifndef __BASICPAGE_H
#define __BASICPAGE_H

class FanPage;

class BasicPage
{
protected:
	string name;
	vector<BasicPage*> friends_array;
	Board* status_board;

public:

	// C'TOR:
	BasicPage() {};
	BasicPage(const string name)
	{
		this->status_board = new Board();
		this->name = name;
	}

	// OPERATORS:
	const BasicPage& operator+=(const BasicPage& other)
	{
		this->add_friend_to_friends_array(&other);
		return *this;
	}

	bool operator>(const BasicPage& other) const
	{
		BasicPage* temp = (BasicPage*)&other;
		return (this->get_num_of_friends() > temp->get_num_of_friends());
	}

	// REST OF METHODS:
	virtual const string getType() const { return "BasicPage"; }
	int get_num_of_friends() const { return friends_array.size(); }
	string get_name() const { return name; }
	void set_name(const string name) { this->name = name; }
	vector<BasicPage*> get_friends_array() const { return friends_array; }
	void add_friend_to_friends_array(const BasicPage* ptr);
	void add_status(Status* status);
	vector<Status*> get_all_status() { return this->status_board->get_all_status(); }
	int get_num_of_status() { return this->status_board->get_num_of_status(); }

	// D'TOR:
	virtual ~BasicPage()
	{
		delete status_board;
	}
};

#endif //__BASICPAGE_H