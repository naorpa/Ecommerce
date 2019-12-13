#ifndef __ORDER_H
#define __ORDER_H
#include "cart.h"

class Seller;
class Buyer;
class Product;

class  Order
{
private:
	static int counter;
	int  o_number;
	Cart o_cart;
	int o_price;
	//להוסיף בproduct מצביע למוכר!!!
public:
	Order(Cart c);
	Order(const Order & other);//copy c'tor
	~Order();
public:
	inline void SetPrice(const int price);
	int GetPrice()const;
	int GetOrderNumber()const;

	

	
};
#endif // !__ORDER_H
