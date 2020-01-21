#include "cart.h"
#include "product.h"
#include <algorithm>
#include "seller.h"
Cart::Cart() 
{
}
//---------------------------------------------------------------------------------------//
Cart::~Cart()
{
	this->c_prouductArr.clear();
	/*vector<Product *>::iterator itr = this->c_prouductArr.begin();
	vector<Product *>::iterator itrEnd = this->c_prouductArr.end();
	for (; itr != itrEnd; ++itr)
	{
		if (*itr != nullptr)
		{
			delete *itr;
		}
	}*/
}
//---------------------------------------------------------------------------------------//
vector<Product *> Cart::getProductArr() 
{
	return c_prouductArr;
}
//---------------------------------------------------------------------------------------//
void Cart::SetProductArr(vector<Product *> Arr)
{
	this->c_prouductArr = Arr;
}
//---------------------------------------------------------------------------------------//
void Cart::addToCart(Product * prod)
{
	this->c_prouductArr.push_back(prod);
	if (this->c_prouductArr.capacity() == this->c_prouductArr.size())
		this->c_prouductArr.reserve(this->c_prouductArr.capacity() * 2); // for better complexity*/
}
//---------------------------------------------------------------------------------------//

void Cart::deleteFromCart(Product * product)
{
	vector<Product *>::iterator found = find(this->c_prouductArr.begin(), this->c_prouductArr.end(), product);
	this->c_prouductArr.erase(found);
}
vector<Product*>::iterator & Cart::getBegin()
{
	return this->c_prouductArr.begin();
}

//---------------------------------------------------------------------------------------//
/*const Cart & Cart::operator=(const Cart & other)
{
	if (this != &other)
	{
		for (int i = 0; i < this->c_logicSize; i++)
		{
			delete this->c_prouductArr[i];
		}
		delete[] c_prouductArr;
		this->c_logicSize = other.c_logicSize;
		this->c_phsize = other.c_phsize;
		this->c_prouductArr = new Product *[this->c_phsize];
		for (int i = 0; i < this->c_logicSize; i++)
		{
			this->c_prouductArr[i] = other.c_prouductArr[i];
		}
	}
	return *this;
}*/
//---------------------------------------------------------------------------------------//
void Cart::PrintCart()
{
	cout << "The items in the cart are:" << endl;
	for (int i = 0; i < this->c_prouductArr.size(); i++)
	{
		cout << "Serial:" << this->c_prouductArr[i]->getSerial() << " " << "Category:" << Product::ProductCategoryStr[this->c_prouductArr[i]->getCategory()] << " " << "Name:" << this->c_prouductArr[i]->getName() << " " << "Price:" << this->c_prouductArr[i]->getPrice() << endl;
	}
}
//---------------------------------------------------------------------------------------//
void Cart::PrintCartByCategory(const string & pCategory)
{
	for (int i = 0; i < this->c_prouductArr.size(); i++)
	{

		if  (Product::ProductCategoryStr [this->c_prouductArr[i]->getCategory()] == (pCategory))
		{
			cout << "- Seller's Name : " << this->c_prouductArr[i]->Getseller()->getName() << endl;
			cout << "- Product's Name : " << this->c_prouductArr[i]->getName() << endl;
			cout << "- Product's Price : " << this->c_prouductArr[i]->getPrice() << endl;
			cout << "- Product's serial number : " << this->c_prouductArr[i]->getSerial() << endl;
			cout << "<----------------------------------------->" << endl;
		}
	}
}
//---------------------------------------------------------------------------------------//
void Cart::PrintCartByProductName(const string & pName)
{
	for (int i = 0; i < this->c_prouductArr.size(); i++)
	{
		if (this->c_prouductArr[i]->getName().compare(pName) == 0)
		{
			cout << "- Seller's Name : " << this->c_prouductArr[i]->Getseller()->getName() << endl;
			cout << "- Product's Name : " << this->c_prouductArr[i]->getName() << endl;
			cout << "- Product's Price : " << this->c_prouductArr[i]->getPrice() << endl;
			cout << "- Product's serial number : " << this->c_prouductArr[i]->getSerial() << endl;
			cout << "<----------------------------------------->" << endl;
		}
	}
}
//---------------------------------------------------------------------------------------//
const int & Cart::GetLogicS() const
{
	return this->c_prouductArr.size();
}
//---------------------------------------------------------------------------------------//
const string & Cart::getProductName(int index) 
{
	return this->c_prouductArr[index]->getName();
}
//---------------------------------------------------------------------------------------//
Product*Cart::getProductBySerial(int serial)
{
	bool flag = false;
	for (int i = 0; i < this->c_prouductArr.size() && flag == false; i++)
	{
		if (this->c_prouductArr[i]->getSerial() == serial)
		{
			return this->c_prouductArr[i];
		}
	}
	if (flag == false)
		return nullptr; //an indicator for the main that no product has found*/
}
