#ifndef __BUYER_H
#define __BUYER_H
#include <iostream>
#include <string.h>
#include "address.h"
#include "cart.h"
#include "order.h"
using namespace std;
#pragma warning(disable: 4996)
class Buyer
{
private:

	char * b_name;
	Address b_address;
	char * b_password;
	Cart		b_cart;
	Order b_order;
public:
	Buyer() = default; // default c'tor
	Buyer(const char * name, const char * password, Address & address, Cart & cart, Order & order); //main c'tor//להוסיף עגלת קניות
	Buyer(const Buyer & other); //copy c'tor
	Buyer(Buyer && other);//move c'tor!
	~Buyer();//d'tor

public:
	static const int MIN_PASSWORD_SIZE = 6;
	void setName(const char * name);
	void setAddress(Address  address);
	bool setPassword(const char * password);
// להוסיף כאן סטרים של מערך עגלת קניות 
	const char * getName() const;
	const Address getAddress() const;
	const char * getPassword() const;
	Cart getCart();
	void addToCart(Product &product);
};

#endif // __BUYER_H

