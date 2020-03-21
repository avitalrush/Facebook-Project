#include <iostream>
#include <Windows.h>
using namespace std;
const int MAXLENGTH = 50;

#include "Facebook.h"
#include "BasicPage.h"
#include "Board.h"

void Facebook::menu()
{
	cout << "Welcome to our Facebook System." << endl << endl;
	cout << "To create new profile, press 1" << endl;
	cout << "To create fan page, press 2" << endl;
	cout << "To add status to profile, press 3" << endl;
	cout << "To add status to fan page, press 4" << endl;
	cout << "To show all status of profile, press 5" << endl;
	cout << "To show all status of fan page, press 6" << endl;
	cout << "To create a friendship, press 7" << endl;
	cout << "To follow a page, press 8" << endl;
	cout << "To show all profiles in the system, press 9" << endl;
	cout << "To show all fan pages in the system, press 10" << endl;
	cout << "To show all friend of a profile, press 11" << endl;
	cout << "To show all fan pages that a profile followed, press 12" << endl;
	cout << "To show all followers of a fan page, press 13" << endl;
	cout << "To show last 10 status profile's friends, press 14" << endl;
	cout << "To compare between 2 entities, press 15" << endl;
	cout << "To compare between 2 status of an entity, press 16" << endl;

	cout << "To exit, press 0" << endl << endl;
}


void Facebook::activate(int num)
{
	if (num == 1)
	{
		cout << "You chose to create a new profile" << endl;
		Facebook::add_profile();
	}
	else if (num == 2)
	{
		cout << "You chose to create a new fan page" << endl;
		Facebook::add_fan_page();
	}
	else if (num == 3)
	{
		cout << "You chose to add a status to a specific profile" << endl;
		Facebook::add_status_to_profile();
	}
	else if (num == 4)
	{
		cout << "You chose to add a status to a specific fan page" << endl;
		Facebook::add_status_to_fan_page();
	}
	else if (num == 5)
	{
		cout << "You chose to show all the status of a specific profile" << endl;
		Facebook::show_all_status_of_profile();
	}
	else if (num == 6)
	{
		cout << "You chose to show all the status of a specific fan page" << endl;
		Facebook::show_all_status_of_fan_page();
	}
	else if (num == 7)
	{
		cout << "You chose to create friendship between 2 profiles" << endl;
		Facebook::make_friends();
	}
	else if (num == 8)
	{
		cout << "You chose to make a profile follow a fan page" << endl;
		Facebook::follow_a_page();
	}
	else if (num == 9)
	{
		cout << "You chose to show all the profiles in Facebook" << endl;
		Facebook::show_all_profiles();
	}
	else if (num == 10)
	{
		cout << "You chose to show all the fan pages in Facebook" << endl;
		Facebook::show_all_fan_pages();
	}
	else if (num == 11)
	{
		cout << "You chose to show all friends of a specific profile" << endl;
		Facebook::show_all_friends_of_profile();
	}
	else if (num == 12)
	{
		cout << "You chose to show all fan pages followed by a specific profile" << endl;
		Facebook::show_all_fan_pages_of_profile();
	}
	else if (num == 13)
	{
		cout << "You chose to show all followers of a specific fan page" << endl;
		Facebook::show_all_followers_of_fan_page();
	}
	else if (num == 14)
	{
		cout << "You chose to show the latest status of of profile's friends" << endl;
		Facebook::show_last_ten_friend_status();
	}
	else if (num == 15)
	{
		cout << "You chose to compare between 2 entities" << endl;
		Facebook::compare_two_entities();
	}
	else if (num == 16)
	{
		cout << "You chose to compare between 2 status of an entity" << endl;
		Facebook::compare_two_status();
	}
}


// 1
void Facebook::add_profile()
{
	// the method gets name&birth date from user, creates new profile and adds it to the profiles array

	string name;
	int i, temp_day, temp_month, temp_year, ISEXIST = 0;

	cout << "Enter profile name (profile's name length must be less than 50 characters): ";
	cin.ignore();
	cin >> name;
	cout << endl;

	if (everybody.size() == 0)
		ISEXIST = 0;
	else
	{
		for (i = 0; i < everybody.size(); i++)	// find  the relevant profile in all profiles array
			if ((name == everybody[i]->get_name()) && (everybody[i]->getType() == "Profile"))	// it means the strings are equal
				ISEXIST = 1;
		while (ISEXIST == 1)
		{
			cout << "Profile is already exist. please choose a different name: " << endl;
			cout << "Enter profile name (profile's name length must be less than 50 characters): " << endl;
			cin >> name;
			cout << endl;
			ISEXIST = 0;
			for (i = 0; i < everybody.size(); i++)	// find  the relevant profile in all profiles array
				if ((name == everybody[i]->get_name()) && (everybody[i]->getType() == "Profile"))	// it means the strings are equal
					ISEXIST = 1;
		}
	}
	cout << "Enter your birth date by: " << endl;
	cout << "day: ";
	cin >> temp_day;
	cout << "month: ";
	cin >> temp_month;
	cout << "year: ";
	cin >> temp_year;
	cout << endl;

	temp_year = temp_month = temp_day = 1;

	Date temp_date(temp_day, temp_month, temp_year);
	everybody.push_back(new Profile(name, temp_date));
	cout << "PROFILE CREATED." << endl;
}

// 2
void Facebook::add_fan_page()
{
	// the method gets name from user, creates new page and adds it to the pages array

	string name;
	int i, ISEXIST = 0;

	cout << "Enter fan page's name (fan page's name length must be less than 50 characters): ";
	cin.ignore();
	cin >> name;
	cout << endl;

	if (everybody.size() == 0)
		ISEXIST = 0;
	else
	{
		for (i = 0; i < everybody.size(); i++)	// find  the relevant profile in all profiles array
			if ((name == everybody[i]->get_name()) && (everybody[i]->getType() == "FanPage"))	// it means the strings are equal
				ISEXIST = 1;
		while (ISEXIST == 1)
		{
			cout << "Fan Page is already exist. please choose a different name: " << endl;
			cout << "Enter fan page's name (fan page's name length must be less than 50 characters): ";
			cin >> name;
			cout << endl;
			ISEXIST = 0;
			for (i = 0; i < everybody.size(); i++)	// find  the relevant profile in all profiles array
				if ((name == everybody[i]->get_name()) && (everybody[i]->getType() == "FanPage"))	// it means the strings are equal
					ISEXIST = 1;
		}
	}
	everybody.push_back(new FanPage(name));
	cout << "FAN PAGE CREATED." << endl;
}

// 3
void Facebook::add_status_to_profile()
{
	/*	the method asks the user for the profile's name & status type
	it finds the profile in the profiles array, creates a status
	and calls the profile's method to add the status to it's status array	*/

	// declarations:
	string name;
	int status_type;
	int size = everybody.size();
	BasicPage* profile_ptr = nullptr;
	Status_Date curr_date;

	// input from user:
	cout << "Enter profile's name (profile's name length must be less than 50 characters): ";
	cin.ignore();
	cin >> name;

	// rest of code:
	for (int i = 0; i < size; i++)
		if ((name == everybody[i]->get_name()) && (everybody[i]->getType() == "Profile"))	// it means the strings are equal
			profile_ptr = (everybody[i]);

	if (profile_ptr == nullptr)
		cout << "PROFILE DOESN'T EXIST." << endl << endl;
	else
	{
		cout << "Choose status type: " << endl;
		cout << "	1. text" << endl << "	2. photo" << endl << "	3. video" << endl << "	4. text and photo" << endl << "	5. text and video" << endl;
		cin >> status_type;

		Status* new_status = new Status(curr_date, status_type, name); // c'tor

		profile_ptr->add_status(new_status); // calls the profile's method to add the status to it's status array
		cout << "STATUS CREATED." << endl;
	}
}

//4
void Facebook::add_status_to_fan_page()
{
	/* the method asks the user for the fan page's name & status type
	it finds the fan page in the fan pages array, creates a status
	and calls the fan page's method to add the status to it's status array	*/

	// declarations:
	string name;
	int status_type;
	int size = everybody.size();
	BasicPage* fanpage_ptr = nullptr;
	Status_Date curr_date;

	// input from user:
	cout << "Enter fan page's name (fan page's name length must be less than 50 characters): ";
	cin.ignore();
	cin >> name;

	// rest of code:
	for (int i = 0; i < size; i++)
		if ((name == everybody[i]->get_name()) && (everybody[i]->getType() == "FanPage"))	// it means the strings are equal
			fanpage_ptr = (everybody[i]);

	if (fanpage_ptr == nullptr)
		cout << "FAN PAGE DOESN'T EXIST." << endl << endl;
	else
	{
		cout << "Choose status type: " << endl;
		cout << "	1. text" << endl << "	2. photo" << endl << "	3. video" << endl << "	4. text and photo" << endl << "	5. text and video" << endl;
		cin >> status_type;

		Status* new_status = new Status(curr_date, status_type, name); // c'tor

		fanpage_ptr->add_status(new_status); // calls the fan page's method to add the status to it's status array
		cout << "STATUS CREATED." << endl;
	}
}

// 5
void Facebook::show_all_status_of_profile()
{
	//the method asks the user for the profile's name
	//it finds the profile in the profiles array and prints all of it's status

	// declarations:
	string name;
	int size = everybody.size();
	BasicPage* profile_ptr = nullptr;

	// input from user:
	cout << "Enter profile's name (profile's name length must be less than 50 characters): ";
	cin.ignore();
	cin >> name;
	cout << endl;

	// rest of code:
	for (int i = 0; i < size; i++)	// find  the relevant profile in all profiles array
		if ((name == everybody[i]->get_name()) && (everybody[i]->getType() == "Profile"))	// it means the strings are equal
			profile_ptr = (everybody[i]);

	if (profile_ptr == nullptr)
		cout << "PROFILE DOESN'T EXIST." << endl << endl;
	else
	{
		vector<Status*> status_array = profile_ptr->get_all_status();
		int num_of_status = status_array.size(); 

		if (num_of_status == 0)
			cout << "THERE ARE NO STATUS FOR THIS PROFILE." << endl << endl;
		else
		{
			cout << name << "'s status:" << endl << endl;
			print_status_according_to_type(status_array, num_of_status);
		}
	}
}

// 6
void Facebook::show_all_status_of_fan_page()
{
	//the method asks the user for the fan page's name
	//it finds the fan page in the fan pages array and prints all of it's status

	// declarations:
	string name;
	int size = everybody.size();
	BasicPage* fan_page_ptr = nullptr;

	// input from user:
	cout << "Enter fan page's name (fan page's name length must be less than 50 characters): ";
	cin.ignore();
	cin >> name;
	cout << endl;

	// rest of code:
	for (int i = 0; i < size; i++)	// find  the relevant profile in all profiles array
		if ((name == everybody[i]->get_name()) && (everybody[i]->getType() == "FanPage"))	// it means the strings are equal
			fan_page_ptr = (everybody[i]);

	if (fan_page_ptr == nullptr)
		cout << "FAN PAGE DOESN'T EXIST." << endl << endl;
	else
	{

		vector<Status*> status_array = fan_page_ptr->get_all_status();
		int num_of_status = status_array.size();

		if (num_of_status == 0)
			cout << "THERE ARE NO STATUS FOR THIS FAN PAGE." << endl << endl;
		else
		{
			cout << name << "'s status:" << endl << endl;
			print_status_according_to_type(status_array, num_of_status);
		}
	}
}

// 7
void Facebook::make_friends()
{
	/*	the method asks the user for 2 profile's names
	it finds the first profile in the profiles array
	and calls the method make friends with the other profile 	*/

	// declarations:
	string name1;
	string name2;
	int size = everybody.size(), isExist = 0, i;
	BasicPage* profile_ptr1 = nullptr;
	BasicPage* profile_ptr2 = nullptr;
	vector<BasicPage*> friendsArr;

	// inpute from user:
	cout << "Enter first profile's name (profile's name length must be less than 50 characters): ";
	cin.ignore();
	cin >> name1;

	cout << "Enter second profile's name (profile's name length must be less than 50 characters): ";
	cin >> name2;

	if (name1 == name2)
	{
		cout << "YOU CAN'T ADD YOURSELF AS A FRIEND!" << endl;
	}
	else
	{
		// rest of code:
		for (i = 0; i < size; i++)	// find  the relevant profiles in all profiles array
		{
			if ((name1 == everybody[i]->get_name()) && (everybody[i]->getType() == "Profile"))	// it means the strings are equal
				profile_ptr1 = everybody[i];

			if ((name2 == everybody[i]->get_name()) && (everybody[i]->getType() == "Profile"))	// it means the strings are equal
				profile_ptr2 = everybody[i];
		}

		if (profile_ptr1 == nullptr || profile_ptr2 == nullptr)
			cout << "ONE OR BOTH OF THE PROFILES DON'T EXIST." << endl;
		else
		{
			friendsArr = profile_ptr1->get_friends_array();
			for (i = 0; i < profile_ptr1->get_num_of_friends(); i++)
			{
				if (friendsArr[i]->get_name() == name2)
					isExist = 1;
			}
			if (isExist == 1)
			{
				cout << "UNABLE TO ADD FRIEND. FRIENDSHIP IS ALREADY CREATED" << endl;
			}
			else
			{
				*profile_ptr1 += *profile_ptr2;
				*profile_ptr2 += *profile_ptr1;
				cout << "FRIENDSHIP CREATED." << endl;
			}
		}
	}
}

// 8
void Facebook::follow_a_page()
{
	/*	the method asks the user for profile's name and fan page's name
	it finds the them if the relevant arrays
	and calls the method add_friend_to_friends_array(profile) and add_page_to_pages_array(page) */

	// declarations:
	string profile_name;
	string page_name;
	int profiles_size = everybody.size();
	int pages_size = everybody.size();
	int i, isExist = 0;

	BasicPage* profile_ptr = nullptr;
	BasicPage* page_ptr = nullptr;
	vector<BasicPage*> followersArr;
	Profile* iAmTheProfile;
	FanPage* iAmThePage;

	// inpute from user:
	cout << "Enter profile's name (profile's name length must be less than 50 characters): ";
	cin.ignore();
	cin >> profile_name;

	cout << "Enter fan page's name (fan page's name length must be less than 50 characters): ";
	cin >> page_name;

	// rest of code:
	for (i = 0; i < profiles_size; i++)	// find  the relevant profile in all profiles array
		if ((profile_name == everybody[i]->get_name()) && (everybody[i]->getType() == "Profile"))	// it means the strings are equal
			profile_ptr = everybody[i];

	for (i = 0; i < pages_size; i++)	// find  the relevant fan page in all fan pages array
		if ((page_name == everybody[i]->get_name()) && (everybody[i]->getType() == "FanPage"))	// it means the strings are equal
			page_ptr = everybody[i];

	if (profile_ptr == nullptr || page_ptr == nullptr)
		cout << "PROFILE OR FAN PAGE DOESN'T EXIST." << endl;
	else
	{
		followersArr = page_ptr->get_friends_array();
		for (i = 0; i < page_ptr->get_num_of_friends(); i++)
		{
			if (followersArr[i]->get_name() == profile_name)
				isExist = 1;
		}
		if (isExist == 1)
		{
			cout << "UNABLE TO FOLLOW THIS PAGE. PROFILE IS ALREADY FOLLOWING THIS PAGE" << endl;
		}
		else
		{
			iAmTheProfile = dynamic_cast<Profile*>(profile_ptr);
			iAmThePage = dynamic_cast<FanPage*>(page_ptr);
			page_ptr->add_friend_to_friends_array(profile_ptr);

			*iAmTheProfile += *iAmThePage;
			cout << "FOLLOWERSHIP CREATED." << endl;
		}
	}
}

// 9
void Facebook::show_all_profiles()
{
	// prints all the profiles in facebook
	Profile* temp;
	int size = everybody.size();
	int i, j = 1;
	if (size == 0)
	{
		cout << "THERE ARE NO PROFILES IN THE SYSTEM" << endl;
	}
	else
	{
		for (i = 0; i < size; i++)
		{
			if (everybody[i]->getType() == "Profile")
			{
				temp = dynamic_cast<Profile*>(everybody[i]);
				cout << j++ << ". Profile's name: " << temp->get_name() << endl;
				cout << "   Profile's birthday: " << temp->get_date().get_day() << "." << temp->get_date().get_month() << "." << temp->get_date().get_year() << endl;
			}
		}
		if (j == 1)
		{
			cout << "THERE ARE NO PROFILES IN THE SYSTEM" << endl;
		}
		cout << endl;
	}
}

// 10
void Facebook::show_all_fan_pages()
{
	// prints all fan pages on facebook                                                                          ?האם אנחנו עדיין צריכים את זה
	int size = everybody.size();
	int i, j = 1;

	if (size == 0)
		cout << "THERE ARE NO FAN PAGES IN THE SYSTEM" << endl;
	else
	{
		for (int i = 0; i < size; i++)
		{
			if (everybody[i]->getType() == "FanPage")
				cout << j++ << ". Fan Pages's name: " << everybody[i]->get_name() << endl;
		}

		if (j == 1)
			cout << "THERE ARE NO FAN PAGES IN THE SYSTEM" << endl;
		cout << endl;
	}
}

// 11
void Facebook::show_all_friends_of_profile()
{
	/*	the method asks the user for the profile's name
	it finds the profile in the profiles array
	and calls the method show all profiles	*/

	// declarations:
	string name;
	int size = everybody.size();
	BasicPage* profile_ptr = nullptr;

	// inpute from user:
	cout << "Enter profile's name (profile's name length must be less than 50 characters): ";
	cin.ignore();
	cin >> name;

	// rest of code:
	for (int i = 0; i < size; i++)	// find  the relevant profile in all profiles array
		if ((name == everybody[i]->get_name()) && (everybody[i]->getType() == "Profile"))	// it means the strings are equal
			profile_ptr = everybody[i];

	if (profile_ptr == nullptr)
		cout << "PROFILE DOESN'T EXIST." << endl;
	else
	{
		cout << endl << name << "'s friends are: " << endl;

		int num_of_friends = profile_ptr->get_friends_array().size();

		if (num_of_friends == 0)
			cout << "PROFILE DONT HAVE ANY FRIENDS" << endl;
		else
			show_all_profiles(profile_ptr, num_of_friends);
	}
}

void Facebook::show_all_profiles(BasicPage* ptr, int num)
{
	// prints all the friends of a specific profile

	int size = num;
	vector<BasicPage*> temp_array = ptr->get_friends_array();

	for (int i = 0; i < size; i++)
		cout << i + 1 << ". " << temp_array[i]->get_name() << endl;
}

// 12
void Facebook::show_all_fan_pages_of_profile()
{
	/*	the method asks the user for the profile's name
	it finds the profile in the profiles array
	and calls the method show all the fan pages this profile follows	*/

	// declarations:
	string name;
	int size = everybody.size();
	Profile* profile_ptr = nullptr;
	BasicPage* temp = nullptr;

	// inpute from user:
	cout << "Enter profile's name (profile's name length must be less than 50 characters): ";
	cin.ignore();
	cin >> name;

	// rest of code:
	for (int i = 0; i < size; i++)	// find  the relevant profile in all profiles array
		if ((name == everybody[i]->get_name()) && (everybody[i]->getType() == "Profile"))	// it means the strings are equal
			temp = everybody[i];

	if (temp == nullptr)
		cout << "PROFILE DOESN'T EXIST." << endl;
	else
	{
		cout << endl << name << "'s followed pages are: " << endl;

		profile_ptr = dynamic_cast<Profile*>(temp);

		int num_of_followed_pages = profile_ptr->get_num_of_followed_pages();

		if (num_of_followed_pages == 0)
			cout << "PROFILE DONT FOLLOW ANY PAGE" << endl;
		else
			show_all_fan_pages(profile_ptr, num_of_followed_pages);
	}
}

void Facebook::show_all_fan_pages(Profile* ptr, int num)
{
	// prints all the fan pages followed by a specific profile

	int size = num;
	vector<FanPage*> temp_array = ptr->get_followed_pages();

	for (int i = 0; i < size; i++)
		cout << i + 1 << ". " << temp_array[i]->get_name() << endl;
}

// 13
void Facebook::show_all_followers_of_fan_page()
{
	/*	the method asks the user for the fan page's name
	it finds the fan page in the fan pages array
	and calls the method show all profiles	*/

	// declarations:
	string name;
	int size = everybody.size();
	FanPage* page_ptr = nullptr;
	BasicPage* temp = nullptr;

	// inpute from user:
	cout << "Enter fan page's name (fan page's name length must be less than 50 characters): ";
	cin.ignore();
	cin >> name;

	// rest of code:
	for (int i = 0; i < size; i++)	// find  the relevant profile in all profiles array
		if ((name == everybody[i]->get_name()) && (everybody[i]->getType() == "FanPage"))	// it means the strings are equal
			temp = everybody[i];

	if (temp == nullptr)
		cout << "FAN PAGE DOESN'T EXIST." << endl;
	else
	{
		cout << endl;
		cout << name << "'s followers are: " << endl;
		page_ptr = dynamic_cast<FanPage*>(temp);

		int num_of_followers = page_ptr->get_friends_array().size();

		if (num_of_followers == 0)
		{
			cout << "PAGE HAS NO FOLLOWERS" << endl;
		}
		else
		{
			show_all_profiles(page_ptr, num_of_followers);
		}

	}
}

// 14
void Facebook::show_last_ten_friend_status()
{
	string name;
	Profile* iAmProfile;
	BasicPage* profile_ptr = nullptr;
	int size = everybody.size(), friend_count, i, j, k, m, size_status_array = 0;
	vector<Status*> status_array;
	vector<BasicPage*> temp_friends_array;
	BasicPage* temp_ptr;
	Status* temp;
	vector<Status*> temp_status_array;
	vector<Status*> temp_status_array2;
	int temp_status_count;


	// input from user:
	cout << "Enter profile's name (profile's name length must be less than 50 characters): ";
	cin.ignore();
	cin >> name;

	for (i = 0; i < size; i++)	// find  the relevant profile in all profiles array
		if ((name == everybody[i]->get_name()) && (everybody[i]->getType() == "Profile"))	// it means the strings are equal
			profile_ptr = (everybody[i]);
	iAmProfile = dynamic_cast<Profile*>(profile_ptr);

	if (profile_ptr == nullptr)
	{
		cout << "PROFILE DOESN'T EXIST" << endl;
	}

	else
	{
		friend_count = iAmProfile->get_friends_array().size(); // this will be the first index

		for (j = 0; j < friend_count; j++)
		{
			temp_friends_array = iAmProfile->get_friends_array(); // holds a friend every time

			temp_ptr = temp_friends_array[j];
			temp_status_array = temp_ptr->get_all_status(); // holds this^ friend's status array
			temp_status_count = temp_ptr->get_all_status().size(); // holds this^ friend's status count

			for (k = 0; k < temp_status_count; k++)
			{
				status_array.push_back(temp_status_array[k]);
				size_status_array++;
			}
		}
		if (size_status_array == 0)
		{
			cout << "THERE ARE NO FRIENDS STATUS FOR THIS PROFILE." << endl << endl;
		}
		else
		{
			//sorting - Descending ORDER
			for (i = 0; i < size_status_array; i++)
			{
				for (j = i + 1; j < size_status_array; j++)
				{
					if (status_array[i]->get_sec() < status_array[j]->get_sec())
					{
						temp = status_array[i];
						status_array[i] = status_array[j];
						status_array[j] = temp;
					}
				}
			}
			print_status_according_to_type_with_name(status_array, size_status_array);
		}
	}
}

// 15
void Facebook::compare_two_entities()
{
	// declarations :
	int type1, type2;
	string text_type1;
	string text_type2;
	string name1;
	string name2;
	BasicPage* temp1 = nullptr;
	BasicPage* temp2 = nullptr;
	int res;

	// input:
	cout << "Please choose the type of the first entity: " << endl;
	cout << "For Profile - press 1, for FanPage - press 2 " << endl;
	cin >> type1;
	if (type1 == 1)
		text_type1 = "Profile";
	else
		text_type1 = "FanPage";

	cout << "Please type the name of the first entity: " << endl;
	cin.ignore();
	cin >> name1;

	cout << "Please choose the type of the second entity: " << endl;
	cout << "For Profile - press 1, for FanPage - press 2 " << endl;
	cin >> type2;

	if (type2 == 1)
		text_type2 = "Profile";
	else
		text_type2 = "FanPage";
	cout << "Please type the name of the second entity: " << endl;
	cin.ignore();
	cin >> name2;

	// rest:
	int size = everybody.size();
	for (int i = 0; i < size; i++)
	{
		if ((everybody[i]->get_name() == name1) && (everybody[i]->getType() == text_type1))
			temp1 = everybody[i];

		if ((everybody[i]->get_name() == name2) && (everybody[i]->getType() == text_type2))
			temp2 = everybody[i];
	}

	cout << temp1->get_name() << " has " << temp1->get_num_of_friends() << " friends." << endl;
	cout << temp2->get_name() << " has " << temp2->get_num_of_friends() << " friends." << endl;

	if (temp1->get_num_of_friends() == temp2->get_num_of_friends())
		cout << "Both entities have the same number of friends!" << endl;
	else
	{
		res = (*temp1 > *temp2); // temp1=the operator object, temp2=the parameter object

		cout << "The more popular entity is: ";
		if (res)
			cout << name1 << endl;
		else
			cout << name2 << endl;
	}
	cout << endl;
}

// 16
void Facebook::compare_two_status()
{
	// declarations :
	int type;
	string text_type;
	string name;
	BasicPage* temp = nullptr;
	vector<Status*> arr;
	int i1, i2;
	Status* s1;
	Status* s2;
	bool flag;

	// input:
	cout << "Please choose the type of the entity: " << endl;
	cout << "For Profile - press 1, for FanPage - press 2 " << endl;
	cin >> type;

	if (type == 1)
		text_type = "Profile";
	else
		text_type = "FanPage";

	cout << "Please type the name of entity: " << endl;
	cin.ignore();
	cin >> name;

	// rest:
	int size = everybody.size();
	for (int i = 0; i < size; i++)
	{
		if ((everybody[i]->get_name() == name) && (everybody[i]->getType() == text_type));
			temp = everybody[i];
	}

	arr = temp->get_all_status();	//arr holds the status arr of temp

	if (type == 1)
		cout << "This Profile has " << temp->get_num_of_status() << " Statuses" << endl;
	else
		cout << "This Fan Page has " << temp->get_num_of_status() << " Statuses" << endl;

	cout << "Enter index of first status you'd like to compare: (Bewtween 1 to " << temp->get_num_of_status() << ") " << endl;
	cin >> i1;

	cout << "Enter index of second status you'd like to compare: (Bewtween 1 to " << temp->get_num_of_status() << ") " << endl;
	cin >> i2;

	s1 = arr[i1-1];
	s2 = arr[i2-1];

	flag = (*s1 == *s2);
	if (flag == TRUE)
		cout << "STATUSES ARE THE SAME" << endl;
	else
		cout << "STAUTSES ARE NOT THE SAME" << endl;
}


// GENERAL
void Facebook::print_status_according_to_type(vector<Status*> status_array, int num)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int photoStatusColor = 10, videoStatusColor = 10;
	for (int i = 0; i < num; i++)
	{
		if (status_array[i]->get_status_type() == 1)
		{
			SetConsoleTextAttribute(hConsole, 15);
			cout << i + 1 << ". SHOWING TEXT STATUS" << endl;
		}
		else if (status_array[i]->get_status_type() == 2)
		{
			if (photoStatusColor == 15)
				photoStatusColor = 10;
			SetConsoleTextAttribute(hConsole, photoStatusColor);
			cout << i + 1 << ". SHOWING PHOTO STATUS" << endl;
			photoStatusColor++;
		}
		else if (status_array[i]->get_status_type() == 3)
		{
			if (videoStatusColor == 15)
				videoStatusColor = 10;
			SetConsoleTextAttribute(hConsole, videoStatusColor);
			cout << i + 1 << ". SHOWING VIDEO STATUS" << endl;
			videoStatusColor++;
		}
		else if (status_array[i]->get_status_type() == 4)
		{
			SetConsoleTextAttribute(hConsole, 15);
			cout << i + 1 << ". SHOWING TEXT AND";
			if (photoStatusColor == 15)
				photoStatusColor = 10;
			SetConsoleTextAttribute(hConsole, photoStatusColor);
			cout << " PHOTO STATUS" << endl;
			photoStatusColor++;
		}
		else if (status_array[i]->get_status_type() == 5)
		{
			SetConsoleTextAttribute(hConsole, 15);
			cout << i + 1 << ". SHOWING TEXT AND";
			if (videoStatusColor == 15)
				videoStatusColor = 10;
			SetConsoleTextAttribute(hConsole, videoStatusColor);
			cout << " VIDEO STATUS" << endl;
			videoStatusColor++;
		}
	}
	SetConsoleTextAttribute(hConsole, 15);

	cout << endl;
}

void Facebook::print_status_according_to_type_with_name(vector<Status*> status_array, int num)
{
	if (num > 10)
		num = 10;

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int photoStatusColor = 10, videoStatusColor = 10;
	for (int i = 0; i < num; i++)
	{
		if (status_array[i]->get_status_type() == 1)
		{
			SetConsoleTextAttribute(hConsole, 15);
			cout << i + 1 << ". Profile: " << status_array[i]->get_name() << " |" << " SHOWING TEXT STATUS" << endl;
		}
		else if (status_array[i]->get_status_type() == 2)
		{
			if (photoStatusColor == 15)
				photoStatusColor = 10;
			SetConsoleTextAttribute(hConsole, photoStatusColor);
			cout << i + 1 << ". Profile: " << status_array[i]->get_name() << " |" << " SHOWING PHOTO STATUS" << endl;
			photoStatusColor++;
		}
		else if (status_array[i]->get_status_type() == 3)
		{
			if (videoStatusColor == 15)
				videoStatusColor = 10;
			SetConsoleTextAttribute(hConsole, videoStatusColor);
			cout << i + 1 << ". Profile: " << status_array[i]->get_name() << " |" << " SHOWING VIDEO STATUS" << endl;
			videoStatusColor++;
		}

		else if (status_array[i]->get_status_type() == 4)
		{
			SetConsoleTextAttribute(hConsole, 15);
			cout << i + 1 << ". Profile: " << status_array[i]->get_name() << " |" << " SHOWING TEXT";
			if (photoStatusColor == 15)
				photoStatusColor = 10;
			SetConsoleTextAttribute(hConsole, photoStatusColor);
			cout << " AND PHOTO STATUS" << endl;
			photoStatusColor++;
		}
		else if (status_array[i]->get_status_type() == 5)
		{
			SetConsoleTextAttribute(hConsole, 15);
			cout << i + 1 << ". Profile: " << status_array[i]->get_name() << " |" << " SHOWING TEXT";
			if (videoStatusColor == 15)
				videoStatusColor = 10;
			SetConsoleTextAttribute(hConsole, videoStatusColor);
			cout << " AND VIDEO STATUS" << endl;
			videoStatusColor++;
		}
	}
	SetConsoleTextAttribute(hConsole, 15);

	cout << endl;
}