#include "system.h"
#include "product.h"
#include "SystemExceptions.h"
#include "users.h"
System::System()
{

}
//----------------------------------------------------------------------------------------//
System::~System()
{
	this->user_arr.clear();
}
//----------------------------------------------------------------------------------------//
vector <Users *> & System::getUserArray() 
{
	return this->user_arr;
}
//----------------------------------------------------------------------------------------//
int System::getLogicSize() const
{
	return this->user_arr.size();
}

void System::SetUserArray(vector<Users*> u)
{
	this->user_arr = u;
}

 //----------------------------------------------------------------------------------------//
 void System::addUser(Users * my_user) noexcept(false)
 {
	 if (checkName(my_user->getName()))
		 throw NameExistException(my_user->getName()); // checking name isn't exist yet
	 this->user_arr.push_back(my_user);
	 if (this->user_arr.capacity() == this->user_arr.size())
		 this->user_arr.reserve(this->user_arr.capacity() * 2); // for better complexity
  }
 //----------------------------------------------------------------------------------------//
 void System::approveLogIn( string &  name, string & pass) noexcept(false)
 { 
	 vector<Users *>::iterator itr = this->user_arr.begin();
	 vector<Users *>::iterator itrEnd = this->user_arr.end();
	for (; itr != itrEnd ; ++itr)
	{
		if((*itr)->getName() == name)
		 { // found the exact name
			 if ((*itr)->getPassword() == pass)
				 return;
			 throw UserExistException((*itr)->getName()); // wrong password
		 }
	}
	throw UserExistException(name);//couldn't found the exact name
 }
 //----------------------------------------------------------------------------------------//
 Seller * System::findSeller(const string & name)
 { // finds and return the seller in the seller array
	 Seller * temp;
	 vector<Users *>::iterator itr = this->user_arr.begin();
	 vector<Users *>::iterator itrEnd = this->user_arr.end();
	 for (; itr != itrEnd; ++itr)
	 {
		 if (name == (*itr)->getName())
		 {
			 temp = dynamic_cast<Seller*>(*itr);
			 if (temp)
				 return temp;
			 else
				 return nullptr;
		 }
	 }
	 return nullptr;//seller not found
 }
 //----------------------------------------------------------------------------------------//
 Buyer * System::findBuyer(const string & name)
 { // finds and return the buyer in the buyer's array
	 Buyer * temp;
	 vector<Users *>::iterator itr = this->user_arr.begin();
	 vector<Users *>::iterator itrEnd = this->user_arr.end();
	 for (; itr != itrEnd; ++itr)
	 {
		 if (name == (*itr)->getName())
		 {
			 temp = dynamic_cast<Buyer*>(*itr);
			 if (temp)
				 return temp;
			 else
				 return nullptr;
		 }
	 }
	 return nullptr; //buyer not found
 }
 //----------------------------------------------------------------------------------------//
 bool System::checkName(const string & name)
 { // return true if the given name exist in the users array, false if not
	 vector<Users *>::iterator itr = this->user_arr.begin();
	 vector<Users *>::iterator itrEnd = this->user_arr.end();

	 for (; itr != itrEnd ; ++itr)
	 {
		 if (name == (*itr)->getName())
		 {
			 return true;
		 }
	 }
	 return false;
 }
 //----------------------------------------------------------------------------------------//
 const System & System::operator+=(Users & other)
 {
	 addUser(&other);
	 return *this;
 }
 //----------------------------------------------------------------------------------------//
 void System::LargerCart()
 {
	 BNS * bnstemp;
	 Buyer * btemp, *btemp2;
	 vector<Users *>::iterator itr = this->user_arr.begin();
	 vector<Users *>::iterator itrEnd = this->user_arr.end();
	 int cin1, cin2,counter=0;
	 cout << "Please Enter the number of the 2 Buyers you want to compare:" << endl;
	 for (; itr != itrEnd; ++itr)
	 {
		 bnstemp = dynamic_cast<BNS *>(*itr);
		 if (bnstemp)
		 {
			 cout << "Index: " << counter << " - ";
			 cout << bnstemp->getName() << endl;
			 counter++;
		 }
		 btemp = dynamic_cast<Buyer *>(*itr);
		 if (btemp && !bnstemp)
		 {
			 cout << "Index: " << counter << " - ";
			 cout << btemp->getName() << endl;;
			 counter++;
		 }
	 }
	 cin >> cin1;
	 cin >> cin2;
	 btemp = dynamic_cast<Buyer *>(user_arr[cin1]);
	 btemp2 = dynamic_cast<Buyer *>(user_arr[cin2]);

	 cout << "The name of buyer with the exspesive cart is:" << (*btemp > *btemp2).getName() << endl;

 }

 //----------------------------------------------------------------------------------------//
