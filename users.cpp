#include "users.h"
#include "system.h"
Users::Users(const char * name, const char * password, Address & add) : add(add)
{ // default c'tor
	setName(name);
	setPassword(password);
}
//----------------------------------------------------------------------------------------//
Users::Users(const Users & other) : add(other.add)
{
	setName(other.name);
	setPassword(other.password);
}
//----------------------------------------------------------------------------------------//
Users::~Users()
{
	delete[] this->password;
	delete[] this->name;
}
//----------------------------------------------------------------------------------------//
void Users::setName(const char * name)
{
	//the function sets the name
	this->name = strdup(name);
}
//----------------------------------------------------------------------------------------//
void Users::setAddress(const Address & address)
{
	//the function sets the address
	this->add.setCity(address.getCity());
	this->add.setState(address.getState());
	this->add.setStreet(address.getStreet());
}
//----------------------------------------------------------------------------------------//
bool Users::setPassword(const char * password)
{
	if (strlen(password) < MIN_PASSWORD_SIZE)
	{
		cout << "The password must contain a least 6 digits or numbers, please enter a new one" << endl;
		return 0; //password didn't match requierments
	}
	else
	{
		this->password = strdup(password);
		return 1; //password has set
	}
}
//----------------------------------------------------------------------------------------//

const char * Users::getName() const
{
	return this->name;
}
//----------------------------------------------------------------------------------------//
const Address & Users::getAddress() const
{
	return this->add;
}
//----------------------------------------------------------------------------------------//
const char * Users::getPassword() const
{
	return this->password;
}
//----------------------------------------------------------------------------------------//
const Users & Users::operator=(const Users & other)
{
	if (this != &other)
	{
		delete[] this->name;
		setName(other.name);
		delete[]this->password;
		setPassword(other.password);
		setAddress(other.add);//
	}

	return *this;
}
//----------------------------------------------------------------------------------------//
const Users & Users::operator=(Users && other)
{
	if (this != &other)
	{
		delete[] this->name;
		this->name = other.name;
		delete[]this->password;
		this->password = other.password;
		other.name = nullptr;
		other.password = nullptr;
		this->add = other.add;
	}
	return *this;
}
//----------------------------------------------------------------------------------------//

