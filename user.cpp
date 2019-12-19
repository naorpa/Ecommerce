#include "user.h"
#include "product.h"

User::User()
{
	this->b_arr = nullptr;
	this->s_arr = nullptr;
	this->b_logicSizeArr = 0;
	this->s_logicSizeArr = 0;
	this->b_phiSizeArr = 1;
	this->s_phiSizeArr = 1;
}
//----------------------------------------------------------------------------------------//
User::~User()
{
	for (int i = 0; i < this->b_logicSizeArr; i++)
		delete this->b_arr[i];
	for (int i = 0; i < this->s_logicSizeArr; i++)
		delete this->s_arr[i];
	delete[] this->b_arr;
	delete[] this->s_arr;
}
//----------------------------------------------------------------------------------------//
Buyer** User::GetBuyerAddress() const
{
	 return b_arr;
 }
//----------------------------------------------------------------------------------------//
 Seller** User::GetSellerAddress() const
{
	 return s_arr;
 }
 //----------------------------------------------------------------------------------------//
 const int User::GetBuyerLogicSizeArr() const
 {
	 return b_logicSizeArr;
 }
 //----------------------------------------------------------------------------------------//
 const int User::GetSellerLogicSizeArr() const
 {
	 return s_logicSizeArr;
 }
 //----------------------------------------------------------------------------------------//
 const int User::GetSellerPhiSizeArr() const
 {
	 return s_phiSizeArr;
 }
 //----------------------------------------------------------------------------------------//
 const int User::GetBuyerPhiSizeArr() const
 {
	 return b_phiSizeArr;
 }
 //----------------------------------------------------------------------------------------//
 void User::addSeller(Seller * my_seller)
 {
	 if (this->s_arr == nullptr)
	 {
		 this->s_arr = new Seller *[this->s_phiSizeArr];
		 this->s_arr[this->s_logicSizeArr] = new Seller(*my_seller);
		 this->s_logicSizeArr++;
	 }
	 else
	 {
		 if (this->s_logicSizeArr == this->s_phiSizeArr)
		 {
			 this->s_phiSizeArr *= 2;
			 Seller ** new_seller_array = new Seller *[this->s_phiSizeArr];
			 for (int i = 0; i < this->s_logicSizeArr; i++)
			 {
				 new_seller_array[i] = this->s_arr[i];
			 }
			 delete[] this->s_arr;
			 this->s_arr = new_seller_array;
			 //new_seller_array = nullptr;
		 }
		 this->s_arr[this->s_logicSizeArr] = new Seller(*my_seller);
		 this->s_logicSizeArr++;
	 }
 }
 //----------------------------------------------------------------------------------------//
 void User::addBuyer(Buyer * my_buyer)
 {
	 if (this->b_arr == nullptr)
	 {
		 this->b_arr = new Buyer *[this->b_phiSizeArr];
		 this->b_arr[this->b_logicSizeArr] = new Buyer(*my_buyer);
		 this->b_logicSizeArr++;
	 }
	 else
	 {
		 if (this->b_logicSizeArr == this->b_phiSizeArr)
		 {
			 this->b_phiSizeArr *= 2;
			 Buyer ** new_buyer_array = new Buyer *[this->b_phiSizeArr];
			 for (int i = 0; i < this->b_logicSizeArr; i++)
			 {
				 new_buyer_array[i] = this->b_arr[i];
			 }
			 delete[] this->b_arr;
			 this->b_arr = new_buyer_array;
			 //new_seller_array = nullptr;
		 }
		 this->b_arr[this->b_logicSizeArr] = new Buyer(*my_buyer);
		 this->b_logicSizeArr++;
	 }
 }
 //----------------------------------------------------------------------------------------//
 bool User::approveLogIn(char * name, char * pass , int indicator )
 { // indicator is 1 = seller , indicator is 0 = buyer
	 if (indicator == 1)
	 {
		 for (int i = 0; i < this->GetSellerLogicSizeArr(); i++)
		 {
			 if (strcmp(name, this->s_arr[i]->getName()) == 0)
			 { // found the exact name
				 if (strcmp(pass, this->s_arr[i]->getPassword()) == 0)
					 return true;
				 return false; // wrong password
			 }
		 }
		 return false;//couldn't found the exact name
	 }
	 else if (indicator == 0)
	 {
		 for (int i = 0; i < this->GetBuyerLogicSizeArr(); i++)
		 {
			 if (strcmp(name, this->b_arr[i]->getName()) == 0)
			 { // found the exact name
				 if (strcmp(pass, this->b_arr[i]->getPassword()) == 0)
					 return true;
				 return false; // wrong password
			 }
		 }
		 return false;//couldn't found the exact name
	 }
 }
 //----------------------------------------------------------------------------------------//
 Seller * User::findSeller(char * name)
 { // finds and return the seller in the seller array
	 for (int i = 0; i < this->s_logicSizeArr; i++)
	 {
		 if (strcmp(name, this->s_arr[i]->getName()) == 0)
			 return (this->s_arr[i]);
	 }
	 return nullptr;//seller not found
 }
 //----------------------------------------------------------------------------------------//
 Buyer * User::findBuyer(char * name)
 { // finds and return the buyer in the buyer's array
	 for (int i = 0; i < this->b_logicSizeArr; i++)
	 {
		 if (strcmp(name, this->b_arr[i]->getName()) == 0)
			 return (this->b_arr[i]);
	 }
	 return nullptr; //buyer not found
 }
 //----------------------------------------------------------------------------------------//
 bool User::checkName(char * name, int indicator)
 { // if indicator = 0 check buyer's name, if indicator = 1 check seller's name
	 if (indicator == 0)
	 {
		 for (int i = 0; i < this->b_logicSizeArr; i++)
		 {
			 if (strcmp(this->b_arr[i]->getName(), name) == 0)
				 return true;
		 }
	 }
	 if (indicator == 1)
	 {
		 for (int i = 0; i < this->s_logicSizeArr; i++)
		 {
			 if (strcmp(this->s_arr[i]->getName(), name) == 0)
				 return true;
		 }
	 }
	 return false;
 }
