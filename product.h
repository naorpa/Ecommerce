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
	static const char * ProductCategoryStr[];// = { "Kids", "Electronics", "Office","Clothes" };
private:
	eProductCategory		 p_category;
	char *					 p_name;
	int						 p_price;
	int						 p_serial;
	static int				 serialCounter;
	Seller *				 p_seller;

public:
	Product() = default; // default c'tor
	Product(const eProductCategory p_category, const char * name, const int price); //main c'tor 
	Product(const Product & other); //copy c'tor
	Product(Product && other);//move c'tor
	~Product();//d'tor	
public:
	void setCategory(eProductCategory category);
	void setName(const char * name);
	void setPrice(int price);
	void setSerialNumber(int serial);
	eProductCategory getCategory() const;
	const char * getName() const;
	int getPrice() const;
	int getSerial() const;
	void setSeller(Seller * seller);
	Seller *Getseller()const;
	char * getCategoryByString() const;
};

#endif // __PRODUCT_H
