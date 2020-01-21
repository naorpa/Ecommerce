#ifndef __SYSTEM_EXCEPTIONS_H_
#define __SYSTEM_EXCEPTIONS_H_
#include <string>
#include <iostream>
using namespace std;

//---------------- Exceptions Related to Users : ---------------------------- //
class UsersExceptions
{
public:
	virtual void msg() const = 0 ;
};

class NameException :public UsersExceptions
{ // a name already exist in the user array
private:
	string existing_name;
public:
	NameException(const string & name) : existing_name(name) {}
	virtual void msg() const override {
		cout << "The name you entered is invalid (only ABC words allowed), returning to main menu" << endl;
	}
};

class PasswordException : public UsersExceptions
{
public:
	PasswordException(const string & password) : pass(password) {}

	virtual void msg() const override
	{
		cout << "The length of the password is too short, at least 6 digits are required!" << endl;
	}

private:
	string pass;
};

//---------------- Exceptions Related to Users Array in System Class : ---------------------------- //

class UserArrayExceptions
{
public:
	virtual void msg() const = 0;
};

class NameExistException:UserArrayExceptions
{ // a name already exist in the user array
private:
	string existing_name;
public:
	NameExistException(const string & name) : existing_name(name) {}
	virtual void msg() const override {
		cout << existing_name << "'s name is already exist in the array!" << endl;
	}
};

class UserExistException :UserArrayExceptions
{ // user isn't found
private:
	string name;
public:
	UserExistException(const string & name) : name(name) { }
	virtual void msg() const override
	{
		cout << "Couldn't find user such as " << name << " , exiting!"<< endl;
	}
};

#endif // !__SYSTEM_EXCEPTIONS_H_
