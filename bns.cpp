#include "bns.h"
#include "product.h"
BNS::BNS(const string & name,const string & pass, Address & add) : Users(name, pass, add)
{

};
//----------------------------------------------------------------------------------------//
BNS::BNS(const BNS & other) :Users(other)
{
	*this = other;
}

//----------------------------------------------------------------------------------------//
ostream & operator<<(ostream & os, BNS & bns)
{
		os << "- Buyer-Seller's Name : " << bns.getName() << endl;
		os << "- Buyer-Seller's Address : " << bns.add.getState() << ", " << bns.add.getCity() << ", " << bns.add.getStreet() << endl;
		if (bns.b_order.size() == 0)
			os << "- " << bns.getName() << " didn't buy anything yet!" << endl;
		else
		{
			os << "- These are the products " << bns.getName() << " bought:" << endl;
			for (int i = 0; i < bns.b_order.size(); i++)
			{
				for (int j = 0; j < bns.b_order[i]->getNumberOfProd(); j++)
				{
					os << "	- Product's Name : " << bns.b_order[i]->GetProductsArray()[j]->getName() << endl;
					os << "	- Product's Price : " << bns.b_order[i]->GetProductsArray()[j]->getPrice() << endl;
					os << "	- Product's serial number : " << bns.b_order[i]->GetProductsArray()[j]->getSerial() << endl;
					os << "<----------------------------------------->" << endl;
				}
			}
		}
		os << "<----------------------------------------->" << endl;
	return os;
}
