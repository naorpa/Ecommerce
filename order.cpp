#include "order.h"
#include "product.h"
Order::Order()
{
	this->o_productArr = nullptr;
	this->o_numberofP = 0;
	this->o_price = 0;
	this->o_number = ++counter;
	this->o_isPaid = false;
}
//----------------------------------------------------------------------------------------//
Order::Order(int numberofProduct)
{
	this->o_productArr = new Product *[numberofProduct];
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
	this->o_productArr = new Product*[other.o_numberofP];
	for (int i = 0; i < this->o_numberofP; i++)
	{
		this->o_productArr[i] = other.o_productArr[i];
	}
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
	if (this->o_productArr == nullptr)
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
Product ** Order::GetProductsArray() const
{
	return this->o_productArr;
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
	this->o_productArr = new Product *[this->o_numberofP];
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
	delete[] this->o_productArr;
}
//----------------------------------------------------------------------------------------//
int Order::counter = 0;
//----------------------------------------------------------------------------------------//
bool Order::checkQuantity(Product * temp)
{
	for (int i = 0; i < this->o_numberofP; i++)
	{
		if (temp == this->GetProductsArray()[i])
			return true;
	}
	return false;
}