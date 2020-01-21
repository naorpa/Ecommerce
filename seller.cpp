#include "seller.h"
#include "product.h"
#include "cart.h"


Seller::Seller(const string & name, const string & password, Address &add)
	: Users(name,password,add)
{
}
//----------------------------------------------------------------------------------------//
Seller::Seller(const Seller & other) : Users(other), s_cart(other.s_cart)
{//copy c'tor
	this->s_feed_lsize = other.s_feed_lsize;
	this->s_feed_phsize = other.s_feed_phsize;
	this->s_feedArr = new Feedback *[this->s_feed_lsize];
	for (int i = 0; i < this->s_feed_lsize; i++)
		this->s_feedArr[i] = new Feedback(*other.s_feedArr[i]);
}
//----------------------------------------------------------------------------------------//
Seller::Seller(Seller && other)  : Users(move(other)) // לבדוק אם צריך לממש מוב לבייסיק אינפו, כי כרגע נשלח לקופי
{ //move c'tor
	*this = move(other);
}
//----------------------------------------------------------------------------------------//
Seller::~Seller()
{	//d'tor
	for (int i = 0; i < this->s_feed_lsize; i++)
		delete this->s_feedArr[i];
	delete[] this->s_feedArr;
}

//----------------------------------------------------------------------------------------//
void Seller::addFeedback(Feedback * feed) 
{ // this function is adding a new feedback to the seller's feedback arr
	if (this->s_feedArr == nullptr || this->s_feed_lsize == 0)
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
const Seller & Seller::operator=(const Seller & other)
{
	if (this != &other)
	{
		Users::operator=(other);
		this->s_cart = other.s_cart;
		for (int i = 0; i < this->s_feed_lsize; i++)
			delete this->s_feedArr[i];
		delete[] this->s_feedArr;
		this->s_feed_lsize = other.s_feed_lsize;
		this->s_feed_phsize = other.s_feed_phsize;
		this->s_feedArr = new Feedback *[this->s_feed_phsize];
		for (int i = 0; i < this->s_feed_lsize; i++)
			this->s_feedArr[i] = new Feedback(*other.s_feedArr[i]);
	}
	return *this;
}
//----------------------------------------------------------------------------------------//
const Seller & Seller::operator=(Seller && other)
{
	if (this != &other)
	{
		Users::operator=(other);
		this->s_feedArr = other.s_feedArr;
		this->s_feed_lsize = other.s_feed_lsize;
		this->s_feed_phsize = other.s_feed_phsize;
		other.s_feedArr = nullptr;
		this->s_cart = other.s_cart;
	}
	return *this;
}
//----------------------------------------------------------------------------------------//
Cart & Seller::getCart()
{
	return s_cart;
}
//----------------------------------------------------------------------------------------//
ostream & operator<<(ostream & os,Seller & seller)
{
	os << "- Seller's Name : " << seller.getName() << endl;
	os << "- Seller's Address : " << seller.add.getState() << ", " << seller.add.getCity() << ", " << seller.add.getStreet() << endl;
	if (seller.s_feed_lsize == 0)
		os << "- " << seller.getName() << " doesn't have any feedback yet" << endl;
	else
	{
		os << "These are " << seller.getName() << " feedbacks:" << endl;
		for (int i = 0; i < seller.s_feed_lsize; i++)
		{
			os << "-By: " << seller.s_feedArr[i]->getName() << endl;
			os << "-At: " << seller.s_feedArr[i]->getDate().getDay() << "\\" << seller.s_feedArr[i]->getDate().getMonth() << "\\" << seller.s_feedArr[i]->getDate().getYear() << endl;
			os << "-Descripton: " << seller.s_feedArr[i]->getDescription() << endl;
			os << "<----------------------------------------->" << endl;
		}
	}
	if (seller.s_cart.GetLogicS() == 0)
	{
		os << "- " << seller.getName() << " doesn't have any products right now" << endl;
		os << "<----------------------------------------->" << endl;
	}
	else
	{
		os << "These are " << seller.getName() << " products:" << endl;
		for (int i = 0; i < seller.s_cart.GetLogicS(); i++)
		{
			os << "- Product's Name : " << seller.s_cart.getProductArr()[i]->getName() << endl;
			os << "- Product's Price : " << seller.s_cart.getProductArr()[i]->getPrice() << endl;
			os << "- Product's serial number : " << seller.s_cart.getProductArr()[i]->getSerial() << endl;
			os << "<----------------------------------------->" << endl;
		}
	}
	return os;
}
