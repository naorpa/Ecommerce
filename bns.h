#ifndef __BNS_H
#define __BNS_H
#include "seller.h"
#include "buyer.h"
class BNS : public Seller, public Buyer
{
public:
	BNS(const char * name,const char* pass, Address & add);
	BNS(const BNS & other);
	BNS(ifstream &in) :Users(in) {};
public:
	friend ostream& operator<<(ostream & os, BNS & bns);
};


#endif // !BNS_H

