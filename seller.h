#ifndef __SELLER_H
#define __SELLER_H

#include "feedback.h"
#include "address.h"
#include "cart.h"
#include "buyer.h"
#include "users.h"
#include "array.h"

class Seller : virtual public Users
{
public:
	static constexpr int MAX_ARR_SIZE = 256;
protected :
	Array <Feedback> s_feedArr = NULL;
	Cart		s_cart;
public:
	Seller() = default; // default c'tor
	Seller(ifstream &in) :Users(in) {};
	Seller(const string & name, const string & password, Address & address); //main c'tor 
	Seller(const Seller & other); //copy c'tor
	Seller (Seller && other);//move c'tor!
	virtual ~Seller();//d'tor
public:
	Cart & getCart();
	void addFeedback(Feedback * feed);
	virtual const Seller& operator=(const Seller& other);
	virtual const Seller& operator=(Seller&& other);
	friend ostream& operator<<(ostream & os, Seller & seller);
};

#endif // __SELLER_H
