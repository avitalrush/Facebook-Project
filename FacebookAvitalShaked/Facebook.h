#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#include <iostream>

#ifndef __FACEBOOK_H
#define __FACEBOOK_H

#include "BasicPage.h"
#include "Profile.h"
#include "FanPage.h"
#include <vector>

class Facebook
{
private:
	vector<BasicPage*> everybody;
	int phy_size_of_everybody;
	int num_of_everybody;

public:
	Facebook()
	{
		phy_size_of_everybody = 1;
	}

	int get_num_of_everybody() const { return num_of_everybody; }
	int get_phy_size_of_everybody() const { return phy_size_of_everybody; }
	vector<BasicPage*> get_everybody() const { return everybody; }
	void add_profile();
	void add_fan_page();
	void add_status_to_profile();
	void add_status_to_fan_page();
	void show_all_status_of_profile();
	void show_all_status_of_fan_page();
	void print_status_according_to_type(vector<Status*> status_array, int num);
	void menu();
	void activate(int num);
	void show_all_profiles();
	void show_all_profiles(BasicPage* ptr, int num);
	void show_all_friends_of_profile();
	void show_all_fan_pages();
	void show_all_fan_pages_of_profile();
	void show_all_fan_pages(Profile* ptr, int num);
	void show_all_followers_of_fan_page();
	void show_last_ten_friend_status();
	void print_status_according_to_type_with_name(vector<Status*> status_array, int num);
	void follow_a_page();
	void make_friends();
	void compare_two_entities();
	void compare_two_status();


	~Facebook()
	{
		int i;
		if (this->everybody.empty() == 0)
		{
			for (i = 0; i < this->get_num_of_everybody(); i++)
			{
				if (this->everybody[i])
				{
					delete this->everybody[i];
				}
			}
		}
		//delete[] this->everybody;
	}
};
#endif //__FACEBOOK_H