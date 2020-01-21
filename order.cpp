#include "order.h"
#include "product.h"
Order::Order()
{
	this->o_numberofP = 0;
	this->o_price = 0;
	this->o_number = ++counter;
	this->o_isPaid = false;
}
//----------------------------------------------------------------------------------------//
Order::Order(int numberofProduct)
{
	this->o_numberofP = numberofProduct;
	this->o_price = 0;
	this->o_number = ++counter;
	this->o_isPaid = false;
}
//----------------------------------------------------------------------------------------//
Order::Order(const Order & other)
{
	this->o_number = other.o_number;
	this->o_numberofP = other.o_numberofP;
	this->o_productArr = other.o_productArr;
	this->o_price = other.o_price;
	this->o_isPaid = other.o_isPaid;
}
//----------------------------------------------------------------------------------------//
void Order::SetPrice(const int price)
{
	o_price = price;
}
//----------------------------------------------------------------------------------------//
int Order::GetPriceOfOrder() const
{
	int sum = 0;
	if (this->o_productArr.size() == 0)
		return 0;
	for (int i = 0; i < this->o_numberofP; i++)
	{
		sum = sum + this->o_productArr[i]->getPrice();
	}
	return sum;
}
//----------------------------------------------------------------------------------------//
int Order::GetOrderNumber() const
{
	return this->o_number;
}
//----------------------------------------------------------------------------------------//

int Order::getNumberOfProd() const
{
	return this->o_numberofP;
}
//----------------------------------------------------------------------------------------//
void Order::setNumberOfProd(const int numberofp)
{
	this->o_numberofP = numberofp;
}
//----------------------------------------------------------------------------------------//
vector<Product *> Order::GetProductsArray() const
{
	return this->o_productArr;
}
void Order::addProduct(Product * prod)
{
	this->o_productArr.push_back(prod);
}
//----------------------------------------------------------------------------------------//
void Order::setNumberofOrder(const int number)
{
	this->o_numberofP = number;
}
//----------------------------------------------------------------------------------------//
bool Order::SetProductArray()
{
	if (this->o_numberofP == 0)
		return 0;
	return 1;
}
//----------------------------------------------------------------------------------------//
void Order::setPaymentSatus(bool flag)
{
	this->o_isPaid = flag;
}
bool Order::getPaymentSatus()
{
	return this->o_isPaid;
}
//----------------------------------------------------------------------------------------//
Order::~Order()
{
	this->o_productArr.clear();
}
//----------------------------------------------------------------------------------------//
int Order::counter = 0;
//----------------------------------------------------------------------------------------//
bool Order::checkQuantity(Product * temp)
{
	vector<Product *>::iterator itr = this->o_productArr.begin();
	vector<Product *>::iterator itrEnd = this->o_productArr.end();
	for (; itr != itrEnd; ++itr)
	{
		if (*itr == temp)
			return true;
	}
	return false;
}