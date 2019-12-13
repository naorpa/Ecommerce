#include "product.h"

const char * Product::ProductCategoryStr[] = { "Kids", "Electronics", "Office","Clothes" };

Product::Product(const eProductCategory p_category,const char * name,const int price)
{
	//main c'tor
	setName(name);
	setCategory(p_category);
	setPrice(price);
	this->p_seller = nullptr;
}   
//----------------------------------------------------------------------------------------//
Product::Product(const Product & other)
{ //copy c'tor
	setName(p_name);
	setCategory(p_category);
	setPrice(p_price);
	this->p_seller = other.p_seller;
}
//----------------------------------------------------------------------------------------//
Product::Product(Product && other)
{ //move c'tor
	p_name = other.p_name;
	p_category = other.p_category;
	p_price = other.p_price;
	p_serial = other.p_serial;
	p_seller = other.p_seller;
	other.p_name = nullptr;
}
//----------------------------------------------------------------------------------------//
Product::~Product()
{	//d'tor
	delete[] p_name;
}
//----------------------------------------------------------------------------------------//
void Product::setName(const char * name)
{
	//the function sets the product's name
	p_name = strdup(name);
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
const char * Product::getName() const
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

void Product::setSeller(Seller * seller)
{
	this->p_seller = seller;
}
Seller *Product::Getseller() const
{
	return this->p_seller;
}
