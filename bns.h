#ifndef __BNS_H
#define __BNS_H
#include "seller.h"
#include "buyer.h"
class BNS : public Seller, public Buyer
{
public:
	BNS(const string & name, const string & pass, Address & add);
	BNS(const BNS & other);
public:
	friend ostream& operator<<(ostream & os, BNS & bns);
	BNS(ifstream &in) :Users(in) {};
};


#endif // !BNS_H

