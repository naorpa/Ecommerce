#include "system.h"
#include "product.h"
#include "Operation.h"
#include <iostream>
#include <string>
using namespace std;
static const int ExitMenu = 16;

void PrintMenu()
{
	cout << "Welcome: " << endl;
	cout << "Please select from the list: " << endl;
	cout << "0.  Add a buyer-seller " << endl;
	cout << "1.  Add a buyer " << endl;
	cout << "2.  Add a seller " << endl;
	cout << "3.  Add a product for seller" << endl;
	cout << "4.  Add a feedback to the seller " << endl;
	cout << "5.  Add a product to a buyer's cart " << endl;
	cout << "6.  Place an order for a buyer" << endl;
	cout << "7.  Payment order for buyer " << endl;
	cout << "8.  View all buyers information " << endl;
	cout << "9.  View all sellers information" << endl;
	cout << "10. View all the products with the same name" << endl;
	cout << "11. View all buyer-seller's information " << endl;
	cout << "12. View all users by type" << endl;
	cout << "13. View comprasion between 2 Buyer's wich cart is bigger" << endl;
	cout << "14. View operator += for buyer" << endl;
	cout << "15. View operator += for seller" << endl;
	cout << "16. Exit " << endl;
}
void Menu(System & user)
{
	int menu;
	PrintMenu();
	cin >> menu;

	while (menu != ExitMenu)
	{
		MenuOpertaion(menu, user);
		PrintMenu();
		cin >> menu;
	}
}

void MenuOpertaion(int oper, System & user)
{
	switch (oper)
	{
	case 0:
	{// Add a buyer-seller
		Case0(user);
	}break;
	case 1:
	{ //Add a buyer
		Case1_Or_14(user);
	} break;
	case 2:
	{//Add a seller
		Case2_Or_15(user);
	}break;
	case 3:
	{// Add a product for seller
		Case3(user);
	}break;
	case 4:
	{ //Add a feedback to the seller
		Case4(user);
	}break;
	case 5:
	{// add product for buyer's cart
		Case5(user);
	}break;
	case 6:
	{// Place an order for a buyer
		Case6(user);
	}break;
	case 7:
	{//payment for order
		Case7(user);	
	}break;
	case 8:
	{// View all buyers information
		Case8(user);	
	}break;
	case 9:
	{//View all sellers information
		Case9(user);
	}break;
	case 10:
	{//View all the products with the same name
		Case10(user);
	}break;
	case 11:
	{//View all buyer-seller's information
		Case11(user);
	}break;
	case 12:
	{// View all users by type
		Case12(user);
	}break;
	case 13:
	{//View comprasion between 2 Buyer's wich cart is bigger
		user.LargerCart();
	}break;
	case 14:
	{//View operator += for buyer
		Case1_Or_14(user);
	}break;
	case 15:
	{//View operator += for seller
		Case2_Or_15(user);
	}break;
	default: break;
	}
}

//----------------------------------------------------------------------------------------//
void logIn(string & name, string & pass, System & user)
{
	try {
		cout << "Hey, Please enter your name: " << endl;
		cin.ignore(numeric_limits <streamsize> ::max(), '\n');
		std::getline(std::cin, name);
		cout << "Please enter your password: " << endl;
		std::getline(std::cin, pass);
		user.approveLogIn(name, pass);
	}
	catch (UserExistException & exp)
	{
		exp.msg();
		exit(1);
	}
}

//-------------------------------------Case's---------------------------------------------------//
//----------------------------------------------------------------------------------------------//
void Case0(System & user)
{

	string name;
	string pass;
	string city;
	string state;
	string street;
	try {
		cout << "Hello Buyer-Seller, please enter name:" << endl;
		cin.ignore(numeric_limits <streamsize> ::max(), '\n');
		getline(cin, name);
		cout << "please enter your password: (at least 6 digits) " << endl;
		cin.clear();
		getline(cin, pass);
		cout << "please enter your Address: (1. state 2. city 3. street) " << endl;
		getline(cin, state);
		getline(cin, city);
		getline(cin, street);
		Address my_address(city, state, street);
		BNS * my_bns = new BNS(name, pass, my_address);
		user.addUser(my_bns);
	}
	catch (UsersExceptions & exp)
	{
		exp.msg();
		return;
	}
	catch (NameExistException & exp)
	{
		exp.msg();
		return;
	}
}
//---------------------------------------------------------------------------------------------//
void Case1_Or_14(System & user)
{
	string b_name;
	string b_pass;
	string b_city;
	string b_state;
	string b_street;
	try {
		cout << "Hello Buyer, please enter name:" << endl;
		cin.ignore(numeric_limits <streamsize> ::max(), '\n');
		getline(cin, b_name);
		cout << "please enter your password: (at least 6 digits) " << endl;
		cin.clear();
		getline(cin, b_pass);
		cout << "please enter your Address: (1. state 2. city 3. street) " << endl;
		getline(cin, b_state);
		getline(cin, b_city);
		getline(cin, b_street);
	}
	catch (UsersExceptions & exp)
	{
		exp.msg();
		return;
	}
	try
	{
		Address my_address(b_city, b_state, b_street);
		Buyer * my_buyer = new Buyer(b_name, b_pass, my_address);
		user += *my_buyer;
	}
	catch (NameExistException & exp)
	{
		exp.msg();
		return;
	}
}
//---------------------------------------------------------------------------------------------//

void Case2_Or_15(System & user)
{
	string s_name;
	string s_pass;
	string s_city;
	string s_state;
	string s_street;
	try {
		cout << "Hello Seller, please enter name:" << endl;
		cin.ignore(numeric_limits <streamsize> ::max(), '\n');
		getline(cin, s_name);
		cout << "please enter your password: (at least 6 digits) " << endl;
		cin.clear();
		getline(cin, s_pass);
		cout << "please enter your Address: (1. state 2. city 3. street) " << endl;
		getline(cin, s_state);
		getline(cin, s_city);
		getline(cin, s_street);
	}
	catch (UsersExceptions & exp)
	{
		exp.msg();
		return;
	}
	try
	{
		Address my_address(s_city, s_state, s_street);
		Seller * my_seller = new Seller(s_name, s_pass, my_address);
		user += *my_seller;
	}
	catch (NameExistException & exp)
	{
		exp.msg();
		return;
	}
}
//--------------------------------------------------------------------------------------------//
void Case3(System & user)
{
	string name;
	string pass;
	logIn(name, pass, user);
	string pName;
	string pCategory;
	int pPrice;
	Seller * my_seller = user.findSeller(name);
	cout << "Welcome, " << my_seller->getName() << endl;
	cout << "Please enter the product's name: " << endl;
	getline(cin, pName);
	cin.clear();
	cout << "Please enter the product category: (KIDS,CLOTHES,ELECTRONICS,OFFICE)" << endl;
	getline(cin, pCategory);
	while (pCategory != "KIDS" && pCategory != "OFFICE" && pCategory != "ELECTRONICS" && pCategory != "CLOTHES")
	{
		cout << "Please enter again the product category: (KIDS,CLOTHES,ELECTRONICS,OFFICE)" << endl;
		getline(cin, pCategory);
	}
	cout << "Please enter the price:" << endl;
	cin >> pPrice;
	while (pPrice <= 0)
	{
		cout << "Price can't be lower than 1, please enter again: " << endl;
		cin >> pPrice;
	}
	if (pCategory == "KIDS")
	{
		Product * my_product = new Product(Product::KIDS, pName, pPrice);
		my_product->setSeller(my_seller);
		my_seller->getCart().addToCart(my_product);
	}
	else if (pCategory == "OFFICE")
	{
		Product * my_product = new Product(Product::OFFICE, pName, pPrice);
		my_product->setSeller(my_seller);
		my_seller->getCart().addToCart(my_product);
	}
	else if (pCategory == "CLOTHES")
	{
		Product * my_product = new Product(Product::CLOTHES, pName, pPrice);
		my_product->setSeller(my_seller);
		my_seller->getCart().addToCart(my_product);
	}
	else if (pCategory == "ELECTRONICS")
	{
		Product * my_product = new Product(Product::ELECTRONICS, pName, pPrice);
		my_product->setSeller(my_seller);
		my_seller->getCart().addToCart(my_product);
	}
}
//--------------------------------------------------------------------------------------------//
void Case4(System & user)
{
	string name;
	string pass;
	cout << "Hey Buyer, Please Log in first to add a feedback" << endl;
	logIn(name, pass, user);
	Buyer * my_buyer = user.findBuyer(name);
	string sellerName;
	int	purchaseDay;
	int orderNumber;
	int	purchaseMonth;
	int	purchaseYear;
	string description;
	cout << "Welcome, " << my_buyer->getName() << endl;
	cout << "Please enter the name of the seller you want to write a feedback to: " << endl;
	getline(cin, sellerName);
	if (user.findSeller(sellerName) == nullptr)
	{
		cout << "We haven't found seller as you entered! returning to main menu" << endl;
		return;
	}
	cout << "Please enter the order number:" << endl;
	cin >> orderNumber;
	if (my_buyer->findOrder(orderNumber) == 0)
	{
		cout << "We haven't found your'e order or you didn't pay for it yet, returning to main menu" << endl;
		return;
	}
	// find order and confirm the buyer bought from this seller, then send a ref for this seller
	Seller * my_seller = user.findSeller(sellerName);
	cout << "Please enter the day,month and year you made the order :" << endl;
	cin >> purchaseDay;
	cin >> purchaseMonth;
	cin >> purchaseYear;
	Date purchaseDate(purchaseDay, purchaseMonth, purchaseYear);
	cout << "Please enter your feedback description : " << endl;
	cin.ignore(numeric_limits <streamsize> ::max(), '\n');
	getline(cin, description);
	Feedback my_feedback(my_buyer->getName(), purchaseDate, description);
	my_seller->addFeedback(&my_feedback);

}
//--------------------------------------------------------------------------------------------//
void Case5(System & user)
{
	string name;
	string pass;
	cout << "Hey Buyer, Please Log in first to add a product" << endl;
	logIn(name, pass, user);
	bool flag = false;
	int to_continue, pSerial;
	string pCategory;
	Buyer * my_buyer = user.findBuyer(name);
	cout << "Welcome, " << my_buyer->getName() << endl;
	while (flag == false) // press 1 to continue looking for products, 0 to start adding products to cart
	{
		cout << "Please enter the category you want to search in: (KIDS,ELECTRONICS,OFFICE,CLOTHES) " << endl;
		getline(cin, pCategory);
		cin.clear();
		while (pCategory != "KIDS" && pCategory != "OFFICE" && pCategory != "ELECTRONICS" && pCategory != "CLOTHES")
		{
			cout << "Please enter again the product category: (KIDS,CLOTHES,ELECTRONICS,OFFICE)" << endl;
			getline(cin, pCategory);
		}
		cout << "These are the products that are currently in the category " << pCategory << endl;
		Seller * temp;
		for (int i = 0; i < user.getLogicSize(); i++)
		{
			temp = dynamic_cast <Seller *>(user.getUserArray()[i]);
			if (temp)
				temp->getCart().PrintCartByCategory(pCategory);
		}
		cout << "to keep looking press 0, if you want to add products to your cart press 1" << endl;
		cin >> to_continue;
		if (to_continue == 1)
			flag = true;
		if (to_continue != 0 && to_continue != 1)
		{
			while (to_continue != 0 && to_continue != 1)
			{
				cout << "invalid input, try again :" << endl;
				cin >> to_continue;
			}
			if (to_continue == 1)
				flag = true;
		}
	}
	cout << "Please enter the seller you want to buy from" << endl;
	cin.ignore(numeric_limits <streamsize> ::max(), '\n');
	getline(cin, name);
	if (name == my_buyer->getName())
	{ // Buyer-Seller trying to buy something from itself
		cout << "You can't buy a product you are selling yourself! returning to main menu " << endl;
		return;
	}
	cout << "Please enter the product's serial number you want to add to your cart: " << endl;
	cin >> pSerial;
	Seller * my_seller = user.findSeller(name);
	while (my_seller == nullptr)
	{
		cout << "Are you sure? seller not found! try again" << endl;
		cin.ignore(numeric_limits <streamsize> ::max(), '\n');
		std::getline(std::cin, name);
		my_seller = user.findSeller(name);
	}
	Product * my_product = my_seller->getCart().getProductBySerial(pSerial);
	while (my_product == nullptr)
	{
		cout << "Are you sure? product not found! enter serial number again" << endl;
		cin >> pSerial;
		my_product = my_seller->getCart().getProductBySerial(pSerial);
	}
	my_buyer->getCart().addToCart(my_product);

}
//--------------------------------------------------------------------------------------------//
void Case6(System & user)
{//place a order
	string name;
	string pass;
	cout << "Hey Buyer, Please Log in first to add a product" << endl;
	logIn(name, pass, user);
	int countP = 0, counterArr = 0;
	int serial;
	Buyer *my_buyer = (user.findBuyer(name));
	cout << "Welcome, " << my_buyer->getName() << endl;
	//check cart is not empty
	if (my_buyer->getCart().GetLogicS() == 0)
	{
		cout << "Please add products to cart first" << endl;
		return;
	}
	//check all orders has been paid already:
	if (my_buyer->getOrderlogicsize() != 0)
	{
		if (my_buyer->GetOrderArray()[my_buyer->getOrderlogicsize() - 1]->getPaymentSatus() == false) // didn't pay for his last order
		{
			cout << "Please pay for your last order first!" << endl;
			return;
		}
	}
	cout << "This is your current cart:" << endl;
	my_buyer->getCart().PrintCart();
	cout << "Please enter the number of the product that you going to buy:" << endl;
	cin >> countP;
	while (countP > my_buyer->getCart().GetLogicS())
	{
		cout << "You cant buy more products than you have in your cart, please enter again:" << endl;
		cin >> countP;
	}
	Order * order = new Order(countP);
	if (countP == 0)
	{
		cout << "You Pressed 0 Proudcts." << endl;return;
	}
	cout << "Please write the serial number of the product that you want to order:(if you want to stop adding press -1)" << endl;
	cin >> serial;
	Product *temp;
	int orderTotalPrice = 0, counter = 0;
	int logicArr = my_buyer->getCart().GetLogicS();//how many proudcts in the old cart
	while (serial != -1 && counter < countP)
	{
		for (int i = 0; i < logicArr; i++)
		{
			if ((my_buyer->getCart().getProductArr())[i]->getSerial() == serial)
			{
				temp = ((my_buyer->getCart().getProductArr())[i]);
				if (order->checkQuantity(temp) == false)
				{
					order->addProduct(temp);
					orderTotalPrice += order->GetProductsArray()[counterArr]->getPrice();
					counterArr++;
					counter++;
				}
			}
		}
		cout << "Please write the serial number of the product that you want to order:(if you want to stop adding press -1:)" << endl;
		cin >> serial;
		while (serial == -1 && countP > counterArr)
		{
			cout << "You didn't choose " << countP << " products yet! enter serial number again: " << endl;
			cin >> serial;
		}
	}
	order->setNumberOfProd(counterArr);
	order->SetPrice(orderTotalPrice);
	my_buyer->AddOrderToOrderArr(order);
	cout << "that is your order:" << endl;
	for (int i = 0; i < countP; i++)
	{
		cout << "<----------------------------------------->" << endl;
		cout << "- Product's Name : " << order->GetProductsArray()[i]->getName() << endl;
		cout << "- Product's Price : " << order->GetProductsArray()[i]->getPrice() << endl;
		cout << "- Product's serial number : " << order->GetProductsArray()[i]->getSerial() << endl;
	}
	cout << "<----------------------------------------->" << endl;
	cout << "Total cart cost:-" << order->GetPriceOfOrder() << "- shekel's" << endl;

}
//--------------------------------------------------------------------------------------------//
void Case7(System & user)
{
	int confirm;
	string name;
	string pass;
	logIn(name, pass, user);
	Buyer *my_buyer = (user.findBuyer(name));
	cout << "Welcome, " << my_buyer->getName() << endl;
	cout << "Please press 1 to confirm your'e purchase, if you still need more time, press 0" << endl;
	cin >> confirm;
	if (confirm == 0)
		return;
	else if (confirm == 1)
	{
		my_buyer->makeOrder();
	}
}
//--------------------------------------------------------------------------------------------//
void Case8(System & user)
{
	Buyer * temp;
	for (int i = 0; i < user.getLogicSize(); i++)
	{
		temp = dynamic_cast<Buyer *>(user.getUserArray()[i]);
		if (temp)
			cout << *temp;
	}
}
//--------------------------------------------------------------------------------------------//
void Case9(System & user)
{
	Seller * temp;
	for (int i = 0; i < user.getLogicSize(); i++)
	{
		temp = dynamic_cast<Seller *>(user.getUserArray()[i]);
		if (temp)
			cout << *temp;
	}
}
//--------------------------------------------------------------------------------------------//
void Case10(System & user)
{
	string pName;
	cout << "Please enter the name of the product you want to search for: " << endl;
	cin.ignore(numeric_limits <streamsize> ::max(), '\n');
	getline(cin, pName);
	Seller * temp;
	for (int i = 0; i < user.getLogicSize(); i++)
	{
		temp = dynamic_cast<Seller *>(user.getUserArray()[i]);
		if (temp)
			temp->getCart().PrintCartByProductName(pName);
	}
}
//----------------------------------------------------------------------------------------//
void Case11(System & user)
{
	BNS * temp;
	for (int i = 0; i < user.getLogicSize(); i++)
	{
		temp = dynamic_cast<BNS *>(user.getUserArray()[i]);
		if (temp)
			cout << *temp;
	}
}
//----------------------------------------------------------------------------------------//
void Case12(System & user)
{
	int i;
	cout << "Please enter the user type you want to see: (0 for Buyer-Seller, 1 for Buyer, 2 for Seller)" << endl;
	cin >> i;
	if (i == 0)
	{
		BNS * temp;
		for (int i = 0; i < user.getLogicSize(); i++)
		{
			temp = dynamic_cast<BNS *>(user.getUserArray()[i]);
			if (temp)
				cout << *temp;
		}
	}
	else if (i == 1)
	{
		Buyer * temp;
		BNS * tempBNS;
		for (int i = 0; i < user.getLogicSize(); i++)
		{
			temp = dynamic_cast<Buyer *>(user.getUserArray()[i]);
			tempBNS = dynamic_cast<BNS *>(user.getUserArray()[i]);
			if (temp && !tempBNS)
				cout << *temp;
		}
	}
	else if (i == 2)
	{
		Seller * temp;
		BNS * tempBNS;
		for (int i = 0; i < user.getLogicSize(); i++)
		{
			temp = dynamic_cast<Seller *>(user.getUserArray()[i]);
			tempBNS = dynamic_cast<BNS *>(user.getUserArray()[i]);
			if (temp && !tempBNS)
				cout << *temp;
		}
	}

}
//--------------------------------------------------------------------------------------------//
