#ifndef __SYSTEM_H
#define __SYSTEM_H

#include "seller.h"
#include "buyer.h"
#include "bns.h"
#include "users.h"

class System
{
private:
	Users ** user_arr;
	int logic_size;
	int ph_size;

public:
	System();
	~System();
	Users ** getUserArray();
	int & getLogicSize();
	void addUser(Users * my_user);
	bool approveLogIn(const char *name,const char * pass);
	Seller * findSeller(const char * name);
	Buyer * findBuyer(const char * name);
	bool checkName(const char * name);
	void LargerCart();
	void SetUsersArray(Users **u);

public:
	void setLogicSize(const int num);
	
	const System & operator+=(Users & other);
};
#endif // !__System_H