#include "address.h"
#include <string.h>
#pragma warning(disable: 4996)
Address::Address(char  *city,char* state,char * street)
{
	setState(state);
	setCity(city);
	setStreet(street);
}
//----------------------------------------------------------------------------------------//
Address::~Address()
{
	delete[] this->a_city;
	delete[] this->a_state;
	delete[] this->a_street;
}
//----------------------------------------------------------------------------------------//
Address::Address(const Address & other) //copy c'tor
{
	setCity(other.a_city);
	setState(other.a_state);
	setStreet(other.a_street);
}
//----------------------------------------------------------------------------------------//
const char * Address::getStreet() const
{
	return this->a_street;
}
//----------------------------------------------------------------------------------------//
const char * Address::getState()const
{
	return this->a_state;
}
//----------------------------------------------------------------------------------------//
const char * Address::getCity()const
{
	return this->a_city;
}
//----------------------------------------------------------------------------------------//
 void Address::setCity (const char* city)
{
	 this->a_city = strdup(city);
}
 //----------------------------------------------------------------------------------------//
 void Address::setState(const char * state)
 {
	 this->a_state = strdup(state);

 }
 //----------------------------------------------------------------------------------------//
 void Address::setStreet(const char * street)
 {
	 this->a_street = strdup(street);
 }
 //----------------------------------------------------------------------------------------//



