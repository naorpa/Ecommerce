#include "seller.h"
#include "product.h"
Seller::Seller(const char * name, const char * password, Address &add, Cart & cart)
	: s_address(add), s_cart(cart)
{
	//main c'tor
	this->s_feed_phsize = 1;
	this->s_feed_lsize = 0;
	this->s_feedArr = nullptr;
	setName(name);
	setPassword(password); 
}
//----------------------------------------------------------------------------------------//
Seller::Seller(const Seller & other) : s_address(other.s_address) , s_cart(other.s_cart)
{//copy c'tor
	setName(other.s_name);
	setPassword(other.s_password);
}
//----------------------------------------------------------------------------------------//
Seller::Seller(Seller && other)
{ //move c'tor
	this->s_name = other.s_name;
	this->s_password = other.s_password;
	this->s_address = other.s_address;
	this->s_cart = other.s_cart;
}
//----------------------------------------------------------------------------------------//
Seller::~Seller()
{	//d'tor
	delete[] this->s_name;
	delete[] this->s_password;
	for (int i = 0; i < this->s_feed_lsize; i++)
		delete this->s_feedArr[i];
	delete[] this->s_feedArr;
}
//----------------------------------------------------------------------------------------//
void Seller::setName(const char * name)
{
	//the function sets the seller's name
	this->s_name = strdup(name);
}

//----------------------------------------------------------------------------------------//
void Seller::setAddress(Address address)
{
	//the function sets the seller's address
	this->s_address.setCity(address.getCity());
	this->s_address.setState(address.getState());
	this->s_address.setStreet(address.getStreet());
}

//----------------------------------------------------------------------------------------//
bool Seller::setPassword(const char * password)
{
	if (strlen(password) < MIN_PASSWORD_SIZE)
	{
		cout << "The password must contain a least 6 digits or numbers, please enter a new one" << endl;
		return 0; //password didn't match requierments
	}
	else
	{
		this->s_password = strdup(password);
		return 1; //password has set
	}
}
//----------------------------------------------------------------------------------------//
const char * Seller::getName() const
{//the function return the seller's name
	return s_name;
}
//----------------------------------------------------------------------------------------//
const Address Seller::getAddress() const
{//the function return the seller's address
	return s_address;
}
//----------------------------------------------------------------------------------------//
const char * Seller::getPassword() const
{//the function return the seller's password
	return s_password;
}
//----------------------------------------------------------------------------------------//
/*Feedback * Seller::getFeedBackArr() const
{//the function return the seller's feedback array
	return s_feedArr;
}*/
//----------------------------------------------------------------------------------------//
void Seller::addFeedback(Feedback * feed) 
{ // this function is adding a new feedback to the seller's feedback arr
	if (this->s_feedArr == nullptr)
	{//empty arr
		this->s_feedArr = new Feedback *[this->s_feed_phsize];
		this->s_feedArr[this->s_feed_lsize] = new Feedback(*feed);
		this->s_feed_lsize++;
	}
	else
	{ // realloc
		if (this->s_feed_lsize == this->s_feed_phsize)
		{
			this->s_feed_phsize *= 2;
			Feedback ** new_feedback_array = new Feedback *[this->s_feed_phsize];
			for (int i = 0; i < this->s_feed_lsize; i++)
			{
				new_feedback_array[i] = this->s_feedArr[i];
			}
			delete[] this->s_feedArr;
			this->s_feedArr = new_feedback_array;
			}
		this->s_feedArr[this->s_feed_lsize] = new Feedback(*feed); //insert new feedback by ptr
		this->s_feed_lsize++;
	}
}
//----------------------------------------------------------------------------------------//
Cart & Seller::getCart() 
{
	return s_cart;
}
//----------------------------------------------------------------------------------------//
void Seller::addProductToSeller(Product * newP)
{
	if (this->s_cart.c_prouductArr == nullptr)
	{//empty arr
		this->s_cart.c_prouductArr = new Product *[this->s_cart.c_phsize];
		this->s_cart.c_prouductArr[this->s_cart.c_logicSize] = new Product(*newP);
		this->s_cart.c_prouductArr[this->s_cart.c_logicSize]->setSeller(this);
		this->s_cart.c_logicSize++;
	}
	else
	{ // realloc
		if (this->s_cart.c_logicSize == this->s_cart.c_phsize)
		{
			this->s_cart.c_phsize *= 2;
			Product ** new_prod_array = new Product *[this->s_cart.c_phsize];
			for (int i = 0; i < this->s_cart.c_logicSize; i++)
			{
				new_prod_array[i] = this->s_cart.c_prouductArr[i];
			}
			delete[] this->s_cart.c_prouductArr;
			this->s_cart.c_prouductArr = new_prod_array;
		}
		this->s_cart.c_prouductArr[this->s_cart.c_logicSize] = new Product(*newP); //insert new product by ptr
		this->s_cart.c_prouductArr[this->s_cart.c_logicSize]->setSeller(this);
		this->s_cart.c_logicSize++;
	}
}
//----------------------------------------------------------------------------------------//
void Seller::printSeller()
{
	cout << "- Seller's Name : " << this->getName() << endl;
	cout << "- Seller's Address : " << this->s_address.getState() << ", " << this->s_address.getCity() << ", " << this->s_address.getStreet() << endl;
	if (this->s_feed_lsize == 0)
		cout << "- " << this->getName() << " doesn't have any feedback yet" << endl;
	else
	{
		cout << "These are " << this->getName() << " feedbacks:" << endl;
		for (int i = 0; i < this->s_feed_lsize; i++)
		{
			cout << "-By: " << this->s_feedArr[i]->getName() << endl;
			cout << "-At: " << this->s_feedArr[i]->getDate().getDay() << "\\" << this->s_feedArr[i]->getDate().getMonth() << "\\" << this->s_feedArr[i]->getDate().getYear() << endl;
			cout << "-Descripton: " << this->s_feedArr[i]->getDescription() << endl;
			cout << "<----------------------------------------->" << endl;
		}
	}
	if (this->s_cart.c_logicSize == 0)
	{
		cout << "- " << this->getName() << " doesn't have any products right now" << endl;
		cout << "<----------------------------------------->" << endl;
	}
	else
	{
		cout << "These are" << this->getName() << " products:" << endl;
		for (int i = 0; i < this->s_cart.c_logicSize; i++)
		{
			cout << "- Product's Name : " << this->s_cart.c_prouductArr[i]->getName() << endl;
			cout << "- Product's Price : " << this->s_cart.c_prouductArr[i]->getPrice() << endl;
			cout << "- Product's serial number : " << this->s_cart.c_prouductArr[i]->getSerial() << endl;
			cout << "<----------------------------------------->" << endl;
		}
	}
}
