#include "product.h"

const string Product::ProductCategoryStr[] = { "KIDS", "ELECTRNOICS", "OFFICE","CLOTHES" };
//----------------------------------------------------------------------------------------//
Product::Product(const eProductCategory p_category, const string & name,const int price)
{
	//main c'tor
	setName(name);
	setCategory(p_category);
	setPrice(price);
	this->p_serial = ++serialCounter;
	this->p_seller = nullptr;
}
//----------------------------------------------------------------------------------------//
Product::Product(const Product & other)
{ //copy c'tor
	setName(other.getName());
	setCategory(other.getCategory());
	setPrice(other.getPrice());
	this->p_serial = other.p_serial;
	this->p_seller = other.p_seller;
}
//----------------------------------------------------------------------------------------//
Product::Product(Product && other)
{ //move c'tor
	p_name = other.p_name;
	p_category = other.p_category;
	p_price = other.p_price;
	p_serial = other.p_serial;
	other.p_name = nullptr;
	other.p_name = nullptr;
}

//----------------------------------------------------------------------------------------//
void Product::setName(const string & name)
{
	//the function sets the product's name
	p_name = name;
}
//----------------------------------------------------------------------------------------//
void Product::setCategory(const eProductCategory category)
{
	//the function sets the product's category
	p_category = category;
}
//----------------------------------------------------------------------------------------//
void Product::setPrice(const int price)
{
	//the function sets the product's price
	p_price = price;
}
//----------------------------------------------------------------------------------------//
void Product::setSerialNumber(const int serial)
{
	//the function sets the product's serial number
	p_serial = serial;
}
//----------------------------------------------------------------------------------------//
Product::eProductCategory Product::getCategory() const
{
	return p_category;
}
//----------------------------------------------------------------------------------------//
const string &  Product::getName() const
{
	return p_name;
}
//----------------------------------------------------------------------------------------//
int Product::getPrice() const
{
	return p_price;
}
//----------------------------------------------------------------------------------------//
int Product::getSerial() const
{
	return p_serial;
}
//----------------------------------------------------------------------------------------//

void Product::setSeller(Seller * seller)
{
	this->p_seller = seller;
}
//----------------------------------------------------------------------------------------//
Seller *Product::Getseller() const
{
	return this->p_seller;
}
//----------------------------------------------------------------------------------------//
const string & Product::getCategoryByString() 
{
	if (p_category == CLOTHES)
		return "CLOTHES";
	if (p_category == KIDS)
		return "KIDS";
	if (p_category == ELECTRONICS)
		return "ELECTRONICS";
	return "OFFICE";
}
//----------------------------------------------------------------------------------------//
int Product::serialCounter = 0;
//----------------------------------------------------------------------------------------//

