#include "seller.h"
#include "product.h"
Seller::Seller(const char * name, const char * password, Address &add, Cart & cart)
	: s_address(add), s_cart(cart)
{
	//main c'tor
	//this->s_buyers_list = nullptr;
	//this->s_bl_lsize = 0;
	//this->s_bl_phsize = 1;
	this->s_feed_phsize = 1;
	this->s_feed_lsize = 0;
	this->s_feedArr = nullptr;
	setName(name);
	setPassword(password); // צריך לבדוק מה עושים אם המתודה תחזיר 0 וצריך להקיש סיסמה מחדש
}
//----------------------------------------------------------------------------------------//
Seller::Seller(const Seller & other) : s_address(other.s_address) , s_cart(other.s_cart)
{//copy c'tor
	setName(other.s_name);
	/*this->s_buyers_list = new Buyer[other.s_bl_lsize];
	memcpy(this->s_buyers_list, other.s_buyers_list, sizeof(Buyer*)*(this->s_bl_lsize));*/
	setPassword(other.s_password);
	//setAddress(other.s_address);
	//this->s_cart = other.s_cart;
}
//----------------------------------------------------------------------------------------//
Seller::Seller(Seller && other)
{ //move c'tor
	this->s_name = other.s_name;
	this->s_password = other.s_password;
	this->s_address = other.s_address;
	this->s_cart = other.s_cart;
	//this->s_buyers_list = other.s_buyers_list;
	//other.s_buyers_list = nullptr;
}
//----------------------------------------------------------------------------------------//
Seller::~Seller()
{	//d'tor
	delete[] s_name;
	delete[] s_password;
	//delete[] s_feedArr;
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
Feedback * Seller::getFeedBackArr() const
{//the function return the seller's feedback array
	return s_feedArr;
}
//----------------------------------------------------------------------------------------//
void Seller::addFeedback(Feedback &feed) 
{ // this function is adding a new feedback to the seller's feedback arr
	/* if(!isBoughtBefore(my_buyer))
	{
		cout << "You can't post a feedback if you didn't purchase from this seller!" << endl;
		return;
	}*/
	if (this->s_feedArr == nullptr)
	{ // no feedback has been added yet
		this->s_feedArr = new Feedback[this->s_feed_phsize];
	}
	if (this->s_feed_lsize <= this->s_feed_phsize)
	{  //there is still space left in the arr
		this->s_feedArr[this->s_feed_lsize].setDate(feed.getDate());
		this->s_feedArr[this->s_feed_lsize].setDescription(feed.getDescription());
		this->s_feedArr[this->s_feed_lsize].setName(feed.getName());
		this->s_feed_lsize++;
	}
	if (this->s_feed_lsize >= this->s_feed_phsize)
	{
		// need to realloc
		this->s_feed_phsize *= 2;
		Feedback * newFeedback = new Feedback[this->s_feed_phsize];
		for (int i = 0; i < this->s_feed_lsize; i++)
		{
			newFeedback[i].setDate(this->s_feedArr[i].getDate());
			newFeedback[i].setDescription(this->s_feedArr[i].getDescription());
			newFeedback[i].setName(this->s_feedArr[i].getName());
		}
		delete[] this->s_feedArr;
		this->s_feedArr = newFeedback;
		newFeedback = nullptr;
	}
}
//----------------------------------------------------------------------------------------//
Cart Seller::getCart() 
{
	return s_cart;
}
//----------------------------------------------------------------------------------------//
void Seller::addProductToSeller(Product & newP)
{
	if (this->s_cart.c_prouductArr == nullptr)//(this->s_cart.c_prouductArr == nullptr)
	{
		this->s_cart.c_prouductArr = new Product[this->s_cart.c_phsize];
		this->s_cart.c_prouductArr[s_cart.c_logicSize].setCategory(newP.getCategory());
		this->s_cart.c_prouductArr[s_cart.c_logicSize].setName(newP.getName());
		this->s_cart.c_prouductArr[s_cart.c_logicSize].setPrice(newP.getPrice());
		this->s_cart.c_prouductArr[s_cart.c_logicSize].setSerialNumber(newP.getSerial());
		this->s_cart.c_logicSize++;
		
	}
	else
	{
		if (s_cart.c_logicSize == s_cart.c_phsize)
		{
			s_cart.c_phsize *= 2;
			Product *Arr = new Product[s_cart.c_phsize];
			for (int i = 0; i < s_cart.c_logicSize; i++)
			{
				Arr[i].setCategory(this->s_cart.c_prouductArr[i].getCategory());
				Arr[i].setName(this->s_cart.c_prouductArr[i].getName());
				Arr[i].setPrice(this->s_cart.c_prouductArr[i].getPrice());
				Arr[i].setSerialNumber(this->s_cart.c_prouductArr[i].getSerial());
			}
			Arr[s_cart.c_logicSize].setCategory(newP.getCategory());
			Arr[s_cart.c_logicSize].setName(newP.getName());
			Arr[s_cart.c_logicSize].setPrice(newP.getPrice());
			Arr[s_cart.c_logicSize].setSerialNumber(newP.getSerial());
			this->s_cart.c_logicSize++;
			delete[] this->s_cart.c_prouductArr;
			this->s_cart.c_prouductArr = Arr;
		}
		
			this->s_cart.c_prouductArr[s_cart.c_logicSize].setCategory(newP.getCategory());
			this->s_cart.c_prouductArr[s_cart.c_logicSize].setName(newP.getName());
			this->s_cart.c_prouductArr[s_cart.c_logicSize].setPrice(newP.getPrice());
			this->s_cart.c_prouductArr[s_cart.c_logicSize].setSerialNumber(newP.getSerial());
			this->s_cart.c_logicSize++;
	}
}
/*const Buyer * Seller::getBuyersList() const
{
	return this->s_buyers_list;
}
//----------------------------------------------------------------------------------------//
void Seller::addBuyerToList(Buyer & my_buyer)
{
	if (this->s_buyers_list = nullptr)
	{
		this->s_buyers_list = new Buyer[this->s_bl_phsize];
		this->s_buyers_list[this->s_bl_lsize] = my_buyer;
		this->s_bl_lsize++;
		//realloc:
		this->s_bl_phsize *= 2;
		Buyer * newBuyersList = new Buyer[this->s_bl_phsize];
		memcpy(newBuyersList, this->s_buyers_list, sizeof(Buyer *)*this->s_bl_lsize);
		this->s_buyers_list = newBuyersList;
		newBuyersList = nullptr;
	}
	else
	{
		if (this->s_bl_lsize == this->s_bl_phsize)
		{
			this->s_bl_phsize *= 2;
			Buyer * newBuyersList = new Buyer[this->s_bl_phsize];
			memcpy(newBuyersList, this->s_buyers_list, sizeof(Buyer *)*this->s_bl_lsize);
			this->s_buyers_list = newBuyersList;
			newBuyersList = nullptr;
		}
		this->s_buyers_list[this->s_bl_lsize] = my_buyer;
		this->s_bl_lsize++;
	}
}
//----------------------------------------------------------------------------------------//
bool Seller::isBoughtBefore(Buyer & my_buyer)
{
	for(int i=0;i<this->s_bl_lsize;i++)
		if(this->s_buyers_list[i] = my_buyer)

}*/