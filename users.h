#ifndef __USERS_H
#define __USERS_H
#include "address.h"

class Users
{
protected:
	char * name;
	char * password;
	Address add;
	Users() = default;
	Users(const char * name,const char* password, Address & add);
	Users(const Users & other);
public:
	static const int MIN_PASSWORD_SIZE = 6;
	virtual ~Users();
public:
	void setName(const char * name);
	void setAddress(const Address  & address);
	bool setPassword(const char * password);
	const char * getName() const;
	const Address & getAddress() const;
	const char * getPassword() const;
public:
	virtual const Users& operator=(const Users& other);
	virtual const Users& operator=(Users&& other);
};


#endif // !Users_H

