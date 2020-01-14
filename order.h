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
	Product **o_productArr;
	int o_numberofP;
	int o_price;
	bool o_isPaid;
public:
	Order(int numberofProduct);
	Order();
	Order(const Order & other);//copy c'tor
	~Order();
public:
	void SetPrice(const int price);
	int GetPriceOfOrder() const;
	int GetOrderNumber()const;
	int getNumberOfProd() const;
	void setNumberOfProd(const int numberofp);
	Product **GetProductsArray()const;
	void setNumberofOrder(const int number);
	bool SetProductArray();
	void setPaymentSatus(bool flag);
	bool getPaymentSatus();
	bool checkQuantity(Product * temp);

};
#endif // !__ORDER_H