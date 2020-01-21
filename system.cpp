#include "system.h"
#include "product.h"


System::System()
{
	this->user_arr = nullptr;
	this->logic_size = 0;
	this->ph_size = 1;
}
//----------------------------------------------------------------------------------------//
System::~System()
{
	for (int i = 0; i < this->logic_size; i++)
	{
		delete this->user_arr[i];
	}
	delete[] this->user_arr;
}
//----------------------------------------------------------------------------------------//
Users ** System::getUserArray()
{
	return this->user_arr;
}
//----------------------------------------------------------------------------------------//
int & System::getLogicSize()
{
	return this->logic_size;
}

 //----------------------------------------------------------------------------------------//
 void System::addUser(Users * my_user)
 {
	 if (this->user_arr == nullptr)
	 {
		 // user array is empty
		 this->user_arr = new Users *[this->ph_size];
	 }
	 else //user array is not empty
	 {
		 if (this->logic_size == this->ph_size)
		 {
			 this->ph_size *= 2;
			 Users ** new_users_array = new Users *[this->ph_size];
			 for (int i = 0; i < this->logic_size; i++)
			 {
				 new_users_array[i] = this->user_arr[i];
			 }
			 delete[] this->user_arr;
			 this->user_arr = new_users_array;
		 }
	 }
	BNS * bnstemp = dynamic_cast<BNS *>(my_user);
	if (bnstemp)
	{
		this->user_arr[this->logic_size] = new BNS(*bnstemp);
	}
	else
	{ // if not buyer
		 Seller * stemp = dynamic_cast<Seller *>(my_user);
		 if (stemp)
		 {
			 this->user_arr[this->logic_size] = new Seller(*stemp);
		 }
		 else// if not  seller and bns
		 {
			 Buyer * btemp = dynamic_cast<Buyer *>(my_user);
			 if (btemp)
			 {
				 this->user_arr[this->logic_size] = new Buyer(*btemp);
			 }
		 }
	}
	this->logic_size++;
  }
 //----------------------------------------------------------------------------------------//
 bool System::approveLogIn(const char * name,const char * pass)
 { 
	for (int i = 0; i < this->logic_size; i++)
	{
		 if (strcmp(name, this->user_arr[i]->getName()) == 0)
		 { // found the exact name
			 if (strcmp(pass, this->user_arr[i]->getPassword()) == 0)
				 return true;
			 return false; // wrong password
		 }
	}
		 return false;//couldn't found the exact name
 }
 //----------------------------------------------------------------------------------------//
 Seller * System::findSeller(const char * name)
 { // finds and return the seller in the seller array
	 Seller * temp;
	 for (int i = 0; i < this->logic_size; i++)
	 {
		 if (strcmp(name, this->user_arr[i]->getName()) == 0)
		 {
			 temp = dynamic_cast<Seller*>(this->user_arr[i]);
			 if (temp)
				 return temp;
			 else
				 return nullptr;
		 }
	 }
	 return nullptr;//seller not found
 }
 //----------------------------------------------------------------------------------------//
 Buyer * System::findBuyer(const char * name)
 { // finds and return the buyer in the buyer's array
	 Buyer * temp;
	 for (int i = 0; i < this->logic_size; i++)
	 {
		 if (strcmp(name, this->user_arr[i]->getName()) == 0)
		 {
			 temp = dynamic_cast<Buyer*>(this->user_arr[i]);
			 if (temp)
				 return temp;
			 else
				 return nullptr;
		 }
	 }
	 return nullptr; //buyer not found
 }
 //----------------------------------------------------------------------------------------//
 bool System::checkName(const char * name)
 { // return true if the given name exist in the users array, false if not
	 for (int i = 0; i < this->logic_size; i++)
	 {
		 if (strcmp(this->user_arr[i]->getName(), name) == 0)
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
	 int cin1, cin2;
	 cout << "Please Enter the number of the 2 Buyers you want to compare:" << endl;
	 for (int i = 0; i < this->logic_size; i++)
	 {
		 bnstemp = dynamic_cast<BNS *>(this->user_arr[i]);
		 if (bnstemp)
		 {
			 cout << "Index: " << i << " - ";
			 cout << bnstemp->getName() << endl;
		 }
		 btemp = dynamic_cast<Buyer *>(this->user_arr[i]);
		 if (btemp && !bnstemp)
		 {
			 cout << "Index: " << i << " - ";
			 cout << btemp->getName() << endl;;
		 }
	 }
	 cin >> cin1;
	 cin >> cin2;
	 btemp = dynamic_cast<Buyer *>(user_arr[cin1]);
	 btemp2 = dynamic_cast<Buyer *>(user_arr[cin2]);

	 cout << "The name of buyer with the exspesive cart is:" << (*btemp > *btemp2).getName() << endl;

 }
 void System::SetUsersArray(Users ** u)
 {
	 this->user_arr = u;
 }
 //----------------------------------------------------------------------------------------//
 void System::setLogicSize(const int num)
 {
	 this->logic_size = num;
 }