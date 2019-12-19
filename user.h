#ifndef __USER_H
#define __USER_H

#include "seller.h"
#include "buyer.h"

class User
{
private:

	Seller **s_arr;
	Buyer **b_arr;
	int s_logicSizeArr;
	int b_logicSizeArr;
	int s_phiSizeArr;
	int b_phiSizeArr;
public:
	User();
	~User();
	Buyer** GetBuyerAddress() const;
	Seller** GetSellerAddress() const;
	const int GetBuyerLogicSizeArr() const;
	const int GetSellerLogicSizeArr() const;
	const int GetSellerPhiSizeArr() const;
	const int GetBuyerPhiSizeArr() const ;
	void addSeller(Seller* my_seller);
	void addBuyer(Buyer * my_buyer);
	bool approveLogIn(char *user, char * pass,int indicator);
	Seller * findSeller(char * name);
	Buyer * findBuyer(char * name);
	bool checkName(char *  name, int indicator);
};
#endif // !__USER_H