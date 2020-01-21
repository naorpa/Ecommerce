#ifndef __BUYER_H
#define __BUYER_H
#include <iostream>
#include <string.h>
#include <vector>
#include "address.h"
#include "cart.h"
#include "order.h"
#include "users.h"

using namespace std;
#pragma warning(disable: 4996)
class Buyer : virtual public Users
{
protected:
	Cart					b_cart;
	vector <Order *>		b_order;
public:
	Buyer() = default; // default c'tor
	Buyer(const string & name, const string & password, Address & address); //main c'tor//
	Buyer(ifstream &in) :Users(in) {};
	virtual ~Buyer();//d'tor
public:
	virtual const Buyer& operator=(const Buyer& other);
	virtual const Buyer& operator=(Buyer&& other);
	friend ostream& operator<<(ostream & os, Buyer & buyer);
	const Buyer & operator>(Buyer & other1);
public:

	Cart & getCart();
	bool findOrder(int num_of_order);
	vector <Order *> GetOrderArray() const;
	void AddOrderToOrderArr(Order * order);
	int getOrderlogicsize() const;
	void makeOrder();
};

#endif // __BUYER_H

