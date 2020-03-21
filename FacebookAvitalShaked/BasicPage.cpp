#include "BasicPage.h"

void BasicPage::add_friend_to_friends_array(const BasicPage* ptr)
{
	this->friends_array.push_back( (BasicPage*)ptr );
}

void BasicPage::add_status(Status* status)
{ 
	(this->status_board)->add_new_status(status);
}