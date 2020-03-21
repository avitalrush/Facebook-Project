#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#include <iostream>

#ifndef __PROFILE_H
#define __PROFILE_H

#include "BasicPage.h"
#include "FanPage.h"
#include "Date.h"
#include "Board.h"
#include <vector>

class FanPage;
class Profile : public BasicPage
{
private:
	Date birth_date;
	vector<FanPage*> followed_pages;

public:
	// C'TOR:
	Profile() {};
	Profile(const string name, Date temp_date) : BasicPage(name)		// c'tor
	{
		this->birth_date = temp_date;
	}
	Profile(const Profile& src) : BasicPage(name) // copy c'tor
	{
		this->birth_date = src.birth_date;
	}

	// OPERATORS:
	const Profile& operator+=(const FanPage& other)
	{
		this->add_page_to_pages_array(&other);
		return *this;
	}

	// REST OF METHODS:
	virtual const string getType() const { return "Profile"; }
	int get_num_of_followed_pages() { return followed_pages.size(); }
	vector<FanPage*> get_followed_pages() { return followed_pages; }
	Date get_date();
	void add_page_to_pages_array(const FanPage* ptr);

	// D'TOR:
	~Profile()
	{
	}
};

#endif //__PROFILE_H