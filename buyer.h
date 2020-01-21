#ifndef __BUYER_H
#define __BUYER_H
#include <iostream>
#include <string.h>
#include "address.h"
#include "cart.h"
#include "order.h"
#include "users.h"

using namespace std;
#pragma warning(disable: 4996)
class Buyer : virtual public Users
{
protected:
	Cart		b_cart;
	Order**		b_order;
	int			b_order_size;
public:
	Buyer() = default; // default c'tor
	Buyer(ifstream &in) :Users(in) {};
	Buyer(const char * name, const char * password, Address & address); //main c'tor//
	Buyer(const Buyer & other); //copy c'tor
	Buyer(Buyer && other);//move c'tor!
	virtual ~Buyer();//d'tor
public:
	virtual const Buyer& operator=(const Buyer& other);
	virtual const Buyer& operator=(Buyer&& other);
	friend ostream& operator<<(ostream & os, Buyer & buyer);
	const Buyer & operator>(Buyer & other1);
public:
	Cart & getCart();
	bool findOrder(int num_of_order);
	Order ** GetOrderArray() const;
	void SetOrderLogicSize(const int size);
	void AddOrderToOrderArr(Order * order);
	int getOrderlogicsize() const;
	void makeOrder();
};

#endif // __BUYER_H

