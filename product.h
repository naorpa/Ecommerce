#ifndef __PRODUCT_H
#define __PRODUCT_H
#include <iostream>
#include <string.h>
using namespace std;
#pragma warning(disable: 4996)
class Seller;
class Product
{
public:
	enum eProductCategory {KIDS,ELECTRONICS,OFFICE,CLOTHES};
	static const string ProductCategoryStr[];// = { "KIDS", "ELECTRONICS", "OFFICE","CLOTHES" };
private:
	eProductCategory		 p_category;
	string					 p_name;
	int						 p_price;
	int						 p_serial;
	static int				 serialCounter;
	Seller *				 p_seller;

public:
	Product() = default; // default c'tor
	~Product();
	Product(const eProductCategory p_category, const string & name, const int price); //main c'tor 
	Product(const Product & other); //copy c'tor
	Product(Product && other);//move c'tor
public:
	void setCategory(eProductCategory category);
	void setName(const string & name);
	void setPrice(int price);
	void setSerialNumber(int serial);
	eProductCategory getCategory() const;
	const string & getName() const;
	int getPrice() const;
	int getSerial() const;
	void setSeller(Seller * seller);
	Seller *Getseller()const;
	const string & getCategoryByString();
};

#endif // __PRODUCT_H
