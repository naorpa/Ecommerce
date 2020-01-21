#ifndef __USERS_H
#define __USERS_H
#include "address.h"
#include "SystemExceptions.h"
#include <iostream>
#include <string.h>
#include <ostream>
#include <fstream>
#include <string>
#include <vector>

class Users
{
protected:
	string name;
	string password;
	Address add;
	Users() = default;
	Users(const string & name, const string & pass, Address & add);
	Users(const Users & other);
public:
	static const int MIN_PASSWORD_SIZE = 6;
	virtual ~Users();
public:
	void setName(const string & name);
	void setAddress(const Address  & address);
	void setPassword(const string & password);
	const string & getName() const;
	const Address & getAddress() const;
	const string & getPassword() const;
public:
	static const int TYPE_LEN = 6;//buyer5 seller6 bns3
	friend void saveUsers(vector<Users*> & users, int size, const string & fileName);
	friend vector <Users*> loadAllUsers(const string & filename, int &numOfusers);
	friend Users* loadUser(ifstream & inFile);
	friend ostream & operator <<(ostream & out, Users & u);
	friend istream & operator >>(istream & in, Users &u)
	{
		string  name;
		string password;//chane to string
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
	Users(ifstream & in) { in >> *this; }//for files
public:
	virtual const Users& operator=(const Users& other);
	virtual const Users& operator=(Users&& other);
};

#endif // !Users_H

