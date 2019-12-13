#include "cart.h"
#include "product.h"

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
	if (other.getProductArr() != nullptr) 
	{
		this->c_prouductArr = new Product[other.c_logicSize];
		for (int i = 0; i < other.c_logicSize; i++)
		{
			c_prouductArr[i].setCategory(other.c_prouductArr[i].getCategory());
			c_prouductArr[i].setName(other.c_prouductArr[i].getName());
			c_prouductArr[i].setPrice(other.c_prouductArr[i].getPrice());
			c_prouductArr[i].setSerialNumber(other.c_prouductArr[i].getSerial());
		}
	}
}
//---------------------------------------------------------------------------------------//
Cart::~Cart()
{
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
Product * Cart::getProductArr() const
{
	return c_prouductArr;
}
//---------------------------------------------------------------------------------------//
void Cart::SetProductArr(Product *Arr)
{
	this->c_prouductArr = Arr;
	Arr = nullptr;
}

void Cart::PrintCart()
{
	cout << "The items in the cart are:" << endl;
	for (int i = 0; i < this->c_logicSize; i++)
	{
		cout << "Serial:" << this->c_prouductArr[i].getSerial() << " " << "Category:" << this->c_prouductArr[i].getCategory() << " " << "Name:" << this->c_prouductArr[i].getName() << " " << "Price:" << this->c_prouductArr[i].getPrice() << endl;
	}
}
