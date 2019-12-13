#ifndef __ADDRESS_H
#define __ADDRESS_H
class Address
{
public:
	static int constexpr MAX_ARR_SIZE = 256;
public:
	Address() = default;
	Address(const Address & other); //copy c'tor
	Address(char  *city, char* state, char * street);
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

};


#endif // !ADDRESS_H

