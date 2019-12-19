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
Product ** Cart::getProductArr() const
{
	return c_prouductArr;
}
//---------------------------------------------------------------------------------------//
void Cart::SetProductArr(Product **Arr)
{
	this->c_prouductArr = Arr;
}
//---------------------------------------------------------------------------------------//
void Cart::PrintCart()
{
	cout << "The items in the cart are:" << endl;
	for (int i = 0; i < this->c_logicSize; i++)
	{
		cout << "Serial:" << this->c_prouductArr[i]->getSerial() << " " << "Category:" << this->c_prouductArr[i]->getCategory() << " " << "Name:" << this->c_prouductArr[i]->getName() << " " << "Price:" << this->c_prouductArr[i]->getPrice() << endl;
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
