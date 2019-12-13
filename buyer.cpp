#include "buyer.h"
#include "product.h"
Buyer::Buyer(const char * name, const char * password, Address &add, Cart & cart,Order & order)
	: b_address(add), b_cart(cart),b_order(order)
{
	//main c'tor
	setPassword(password);// צריך לבדוק מה עושים אם המתודה תחזיר 0 וצריך להקיש סיסמה מחדש
	setName(name);

}
//----------------------------------------------------------------------------------------//
Buyer::Buyer(const Buyer & other)
{//copy c'tor
	b_order = other.b_order;
	setName(other.b_name);
	setAddress(other.b_address);
	setPassword(other.b_password);
}
//----------------------------------------------------------------------------------------//
Buyer::Buyer(Buyer && other)
{
	//move c'tor
	b_name = other.b_name;
	b_address = other.b_address;
	b_password = other.b_password;
	b_order = other.b_order;
	other.b_name = nullptr;
	other.b_password = nullptr;
}
//----------------------------------------------------------------------------------------//
Buyer::~Buyer()
{//d'tor
	delete[] b_name;
	delete[] b_password;
}

//----------------------------------------------------------------------------------------//
void Buyer::setName(const char * name)
{
	//the function sets the buyer's name
	b_name = strdup(name);
}
//----------------------------------------------------------------------------------------//
void Buyer::setAddress(Address address)
{
	//the function sets the buyer's address
	this->b_address.setCity(address.getCity());
	this->b_address.setState(address.getState());
	this->b_address.setStreet(address.getStreet());
}
//----------------------------------------------------------------------------------------//
bool Buyer::setPassword(const char * password)
{
	if (strlen(password) < MIN_PASSWORD_SIZE)
	{
		cout << "The password must contain a least 6 digits or numbers, please enter a new one" << endl;
		return 0; //password didn't match requierments
	}
	else
	{
		b_password = strdup(password);
		return 1; //password has set
	}
}
//----------------------------------------------------------------------------------------//
const char *Buyer::getName() const
{//the function return the buyer's name
	return b_name;
}
//----------------------------------------------------------------------------------------//
const Address Buyer::getAddress() const
{//the function return the buyer's address
	return b_address;
}
//----------------------------------------------------------------------------------------//
const char *Buyer::getPassword()const
{//the function return the buyer's password
	return b_password;
}
//----------------------------------------------------------------------------------------//
Cart Buyer::getCart()
{
	return this->b_cart;
}

//----------------------------------------------------------------------------------------//
void Buyer::addToCart(Product & prod)
{
	if (this->b_cart.c_logicSize == 0)
	{
		this->b_cart.c_prouductArr = new Product[this->b_cart.c_phsize];
		this->b_cart.c_prouductArr[this->b_cart.c_logicSize].setCategory(prod.getCategory());
		this->b_cart.c_prouductArr[this->b_cart.c_logicSize].setName(prod.getName());
		this->b_cart.c_prouductArr[this->b_cart.c_logicSize].setPrice(prod.getPrice());
		this->b_cart.c_prouductArr[this->b_cart.c_logicSize].setSerialNumber(prod.getSerial());
		this->b_cart.c_logicSize++;
	}
	else
	{
		if (this->b_cart.c_logicSize == this->b_cart.c_phsize)
		{ //the array need realloc
			this->b_cart.c_phsize *= 2;
			Product * newProdArray = new Product[this->b_cart.c_phsize];
			for (int i = 0; i < this->b_cart.c_logicSize; i++)
			{
				newProdArray[i].setCategory(this->b_cart.c_prouductArr[i].getCategory());
				newProdArray[i].setName(this->b_cart.c_prouductArr[i].getName());
				newProdArray[i].setPrice(this->b_cart.c_prouductArr[i].getPrice());
				newProdArray[i].setSerialNumber(this->b_cart.c_prouductArr[i].getSerial());
			}
			delete[] this->b_cart.c_prouductArr;
			this->b_cart.c_prouductArr = newProdArray;
		}
		this->b_cart.c_prouductArr[this->b_cart.c_logicSize].setCategory(prod.getCategory());
		this->b_cart.c_prouductArr[this->b_cart.c_logicSize].setName(prod.getName());
		this->b_cart.c_prouductArr[this->b_cart.c_logicSize].setPrice(prod.getPrice());
		this->b_cart.c_prouductArr[this->b_cart.c_logicSize].setSerialNumber(prod.getSerial());
		this->b_cart.c_logicSize++;
	}
}
