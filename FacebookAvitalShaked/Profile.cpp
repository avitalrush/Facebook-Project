#include "Profile.h"

void Profile::add_page_to_pages_array(const FanPage* ptr)
{
	followed_pages.push_back((FanPage*)ptr);
}

Date Profile::get_date()
{
	return this->birth_date;
}