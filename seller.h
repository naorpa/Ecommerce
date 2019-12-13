#ifndef __SELLER_H
#define __SELLER_H

#include "feedback.h"
#include "address.h"
#include "cart.h"
#include "buyer.h"

class Seller
{
public:
	static constexpr int MAX_ARR_SIZE = 256;
private :
	Feedback *	s_feedArr; // לעדכן הכל
	Address	    s_address;
	Cart		s_cart;
	int			s_feed_lsize;
	int			s_feed_phsize;
	//int			s_bl_lsize;
	//int			s_bl_phsize;
	char 		*s_name;
	char 		*s_password;
	//Buyer		*s_buyers_list;

public:
	Seller() = default; // default c'tor
	Seller(const char * name, const char * password, Address & address , Cart & cart); //main c'tor 
	Seller(const Seller & other); //copy c'tor
	Seller (Seller && other);//move c'tor!
	~Seller();//d'tor
public:
	static const int MIN_PASSWORD_SIZE = 6;
	void setName(const char * name);
	void setAddress(Address address);
	bool setPassword(const char * password);
	//const Buyer * getBuyersList() const;
	const char * getName() const;
	const Address getAddress() const;
	Cart getCart();
	const char * getPassword() const;
	void addFeedback(Feedback &feed);
	Feedback * getFeedBackArr() const;
	void addProductToSeller(Product & newP);
	//void addBuyerToList(Buyer & my_buyer);
	//bool isBoughtBefore(Buyer & my_buyer);
};

#endif // __SELLER_H
