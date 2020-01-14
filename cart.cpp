#include "cart.h"
#include "product.h"
#include "seller.h"
Cart::Cart() 
{
	this->c_logicSize = 0;
	this->c_phsize = 1;
	this->c_prouductArr = nullptr;
}
//---------------------------------------------------------------------------------------//
Cart::Cart(const Cart & other)
//copy c'tor
{
	SetLogicS(other.c_logicSize);
	SetPhiS(other.c_phsize);
	SetProductArr(other.c_prouductArr);
}
//---------------------------------------------------------------------------------------//
Cart::~Cart()
{
	for (int i = 0; i < this->c_logicSize; i++)
		delete this->c_prouductArr[i];
	delete[] c_prouductArr;
}
//---------------------------------------------------------------------------------------//
const int Cart::GetPhiS() const
{
	return c_phsize;
}
//---------------------------------------------------------------------------------------//
const int Cart::GetLogicS() const
{
	return c_logicSize;
}
//---------------------------------------------------------------------------------------//
void Cart::SetLogicS(int logic)
{
	this->c_logicSize = logic;
}
//---------------------------------------------------------------------------------------//
void Cart::SetPhiS(int phisc)
{
	this->c_phsize = phisc;
}
//---------------------------------------------------------------------------------------//
Product ** Cart::getProductArr() 
{
	return c_prouductArr;
}
//---------------------------------------------------------------------------------------//
void Cart::SetProductArr(Product **Arr)
{
	this->c_prouductArr = Arr;
}
//---------------------------------------------------------------------------------------//
void Cart::addToCart(Product * prod)
{
	if (this->c_prouductArr == nullptr || this->c_logicSize == 0)
	{//empty arr
		this->c_prouductArr = new Product *[this->c_phsize];
		this->c_prouductArr[this->c_logicSize] = new Product(*prod);
		this->c_logicSize++;
	}
	else
	{ // realloc
		if (this->c_logicSize == this->c_phsize)
		{
			this->c_phsize *= 2;
			Product ** new_prod_array = new Product *[this->c_phsize];
			for (int i = 0; i < this->c_logicSize; i++)
			{
				new_prod_array[i] = this->c_prouductArr[i];
			}
			delete[] this->c_prouductArr;
			this->c_prouductArr = new_prod_array;
		}
		this->c_prouductArr[this->c_logicSize] = new Product(*prod); //insert new product by ptr
		this->c_logicSize++;
	}
}
//---------------------------------------------------------------------------------------//
const Cart & Cart::operator=(const Cart & other)
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
}
//---------------------------------------------------------------------------------------//
void Cart::PrintCart()
{
	cout << "The items in the cart are:" << endl;
	for (int i = 0; i < this->c_logicSize; i++)
	{
		cout << "Serial:" << this->c_prouductArr[i]->getSerial() << " " << "Category:" << Product::ProductCategoryStr[this->c_prouductArr[i]->getCategory()] << " " << "Name:" << this->c_prouductArr[i]->getName() << " " << "Price:" << this->c_prouductArr[i]->getPrice() << endl;
	}
}
//---------------------------------------------------------------------------------------//
void Cart::PrintCartByCategory(char * pCategory)
{
	for (int i = 0; i < this->c_logicSize; i++)
	{
		if (strcmp(this->c_prouductArr[i]->getCategoryByString(), pCategory) == 0)
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
void Cart::PrintCartByProductName(char * pName)
{
	for (int i = 0; i < this->c_logicSize; i++)
	{
		if (strcmp(this->c_prouductArr[i]->getName(), pName) == 0)
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
const char * Cart::getProductName(int index)
{
	return this->c_prouductArr[index]->getName();
}
//---------------------------------------------------------------------------------------//
Product*Cart::getProductBySerial(int serial)
{
	bool flag = false;
	for (int i = 0; i < this->c_logicSize && flag == false; i++)
	{
		if (this->c_prouductArr[i]->getSerial() == serial)
		{
			return this->c_prouductArr[i];
		}
	}
	if (flag == false)
		return nullptr; //an indicator for the main that no product has found*/
}
