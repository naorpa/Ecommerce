#ifndef __ADDRESS_H
#define __ADDRESS_H
#include <string>
#include <fstream>
using namespace std;
class Address
{
public:
	Address() = default;
	Address(const string & city, const string & state, const string & street);
	void setCity(const string & city);
	void setState(const string & state);
	void setStreet(const string & street);
	const string & getStreet() const;
	const string & getState()const;
	const string & getCity() const;
public:
	friend ostream & operator<<(ostream & os, Address & ad);
	friend istream & operator >>(istream & in, Address & ad)
	{
		string city;
		string state;
		string street;//change to string
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
private:
	string	a_state;
	string	a_city;
	string	a_street;
};


#endif // !ADDRESS_H

