#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#include <iostream>

#ifndef __FANPAGE_H
#define __FANPAGE_H

#include "BasicPage.h"
#include "Profile.h"

class Profile;
class FanPage : public BasicPage
{
public:
	FanPage() = default;

	FanPage(const string name) : BasicPage(name)	// c'tor
	{
	}

	void add_follower(Profile& ptr);
	int get_num_of_followers() { return friends_array.size(); }
	virtual const string getType() const { return "FanPage"; }

	~FanPage()
	{
	}
};

#endif //__FANPAGE_H