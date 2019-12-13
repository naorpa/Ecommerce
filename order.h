#ifndef __ORDER_H
#define __ORDER_H
#include "cart.h"

class Seller;
class Buyer;
class Product;

class  Order
{
private:
	static int counter;//for o_number
	int  o_number;
	Product *o_productArr;
	int o_numberofP=0;
	int o_price;
	//להוסיף בproduct מצביע למוכר!!!
public:
	Order(int numberofProduct);
	Order();
	Order(const Order & other);//copy c'tor
	~Order();
public:
	inline void SetPrice(const int price);
	int GetPriceOfOrder() const;
	int GetOrderNumber()const;
	Product *GetProductsArray()const;
	bool SetProductArray();//מחזירה 0 אם אין מה להקצות ו1 עם הקצתה בגודל של כמות המוצרים


	

	
};
#endif // !__ORDER_H
