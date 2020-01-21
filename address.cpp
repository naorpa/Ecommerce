#include "address.h"
#include <string.h>
#pragma warning(disable: 4996)
Address::Address(const string & city, const string & state, const string & street)
{
	setState(state);
	setCity(city);
	setStreet(street);
}

//----------------------------------------------------------------------------------------//
const string & Address::getStreet() const
{
	return this->a_street;
}
//----------------------------------------------------------------------------------------//
const string & Address::getState()const
{
	return this->a_state;
}
//----------------------------------------------------------------------------------------//
const string & Address::getCity()const
{
	return this->a_city;
}
//----------------------------------------------------------------------------------------//
 void Address::setCity (const string & city)
{
	 this->a_city = city;
}
 //----------------------------------------------------------------------------------------//
 void Address::setState(const string & state)
 {
	 this->a_state = state;

 }
 //----------------------------------------------------------------------------------------//
 void Address::setStreet(const string & street)
 {
	 this->a_street = street;
 }
 //----------------------------------------------------------------------------------------//

 ostream & operator<<(ostream & out, Address & ad)
 {
	
	 if (typeid(out) == typeid(ofstream))
		 out << ad.a_state << " " << ad.a_city << " " << ad.a_street;
	 else //(typeid(out)==typeid(ostream)
	 {
		 out << "State: " << ad.a_state;
		 out << " City " << ad.a_city;
		 out << " Street: " << ad.a_street;
	 }
		 return out;
 }
