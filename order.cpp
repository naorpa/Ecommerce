
#include "order.h"
#include "product.h"
Order::Order(Cart c) :o_cart(c)
{
	this->o_price = 0;
	this->o_number = ++counter;

}
Order::Order(const Order & other)
{
	this->o_number = other.o_number;
	this->o_price = o_price;
	//?this->o_cart(other.o_cart);
}
//----------------------------------------------------------------------------------------//
void Order::SetPrice(const int price)
{
	o_price = price;
}
//----------------------------------------------------------------------------------------//
int Order::GetPrice() const
{
	int sum = 0;
	if (this->o_cart.getProductArr() == nullptr)
		return 0;
	for (int i = 0; i < this->o_cart.GetLogicS(); i++)
	{
		sum = sum + this->o_cart.getProductArr()[i].getPrice();
	}
	return sum;
}
//----------------------------------------------------------------------------------------//
int Order::GetOrderNumber() const
{
	return this->o_number;
}
//----------------------------------------------------------------------------------------//
Order::~Order()
{
	
}

//----------------------------------------------------------------------------------------//
int Order::counter = 0;
//----------------------------------------------------------------------------------------//