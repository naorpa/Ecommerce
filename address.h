#ifndef __ADDRESS_H
#define __ADDRESS_H
#include <string.h>
#include <fstream>
#include <string>
using namespace std;


class Address
{
public:
	Address() = default;
	Address(ifstream & in) { in >> *this; }
	Address(const Address & other); //copy c'tor
	Address(char  *city, char* state, char * street);
	~Address();
	void setCity(const char * city);
	void setState(const char * state);
	void setStreet(const char * street);
	const char * getStreet() const;
	const char * getState()const;
	const char * getCity() const;

private:
	char	*a_state;
	char	*a_city;
	char	*a_street;
public:
	friend ostream & operator<<(ostream & os, Address & ad);
	friend istream & operator >>(istream & in, Address & ad)
	{
			char  city[20], state[20],street[20];//change to string
			char t;
			if (typeid(in) == typeid(ifstream))
			{
				in >> state >> city >> street;
				ad.setCity(city);
				ad.setState(state);
				ad.setStreet(street);
			}
			return in;
	}
};


#endif // !ADDRESS_H

