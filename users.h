#ifndef __USERS_H
#define __USERS_H
#include "address.h"
#include <iostream>
#include <string.h>
#include <ostream>
#include <fstream>
#include <string>

class Users
{
protected:
	char * name;
	char * password;
	Address add;
	Users() = default;
	Users(ifstream & in){in >> *this;}//for files
	Users(const char * name,const char* password, Address & add);
	Users(const Users & other);
public:
	static const int TYPE_LEN = 6;//buyer5 seller6 bns3
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
	friend ostream & operator <<(ostream & out, Users & u);
	friend istream & operator >>(istream & in, Users &u)
	{
		char  name[20],  password[20];//chane to string
		char t;
		if (typeid(in) == typeid(ifstream))
		{
			in >> name >> password;
			in >> u.add;
			u.setName(name);
			u.setPassword(password);
		}
			return in;
	}	
	friend void saveUsers(Users ** users, int size, const char * fileName);
	friend Users ** loadAllUsers(const char * filename,int &numOfusers);
	friend Users *loadUser(ifstream & inFile);
	
	
};


#endif // !Users_H

