#include "user.h"
#include "product.h"

static const int ExitMenu = 11;
void PrintMenu();
void Menu(User & user);
void MenuOpertaion(int oper, User & user);
static const int MAX_CHAR_INPUT = 30;
static const int MAX_DESCRIPTION_SIZE = 256;
int main()
{
	User A;
	Menu(A);
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
}

void PrintMenu()
{
	cout << "Welcome: " << endl;
	cout << "Please select from the list: " << endl;
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
	cout << "11. Exit " << endl;
}
void Menu(User & user)
{
	int menu;
	PrintMenu();
	cin >> menu;

	while (menu != ExitMenu)
	{
		MenuOpertaion(menu, user);
//		system("CLS");
		PrintMenu();
		cin >> menu;
	}
}


void MenuOpertaion(int oper, User & user)
{
	switch (oper)
	{
	case 1:
	{
		char b_name[MAX_CHAR_INPUT];
		char b_pass[MAX_CHAR_INPUT];
		char b_city[MAX_CHAR_INPUT];
		char b_state[MAX_CHAR_INPUT];
		char b_street[MAX_CHAR_INPUT];
		Cart bmy_cart;
		cout << "Hello Buyer, please enter name:" << endl;
		cin.ignore(numeric_limits <streamsize> ::max(), '\n');
		cin.getline(b_name, MAX_CHAR_INPUT);
		while (user.checkName(b_name, 0) == true)
		{
			cout << "your username is already take. please enter another one:" << endl;
			cin.getline(b_name, MAX_CHAR_INPUT);
		}
		cout << "please enter your password: (at least 6 digits) " << endl;
		cin.clear();
		cin.getline(b_pass, MAX_CHAR_INPUT);
		if (strlen(b_pass) < 6)
		{
			while (strlen(b_pass) < 6)
			{
				cout << "Your password didn't match the requierments! Please enter again :)" << endl;
				cin.clear();
				cin.getline(b_pass, MAX_CHAR_INPUT);
			}
		}
		cout << "please enter your Address: (1. state 2. city 3. street) " << endl;
		cin.getline(b_state, MAX_CHAR_INPUT);
		cin.getline(b_city, MAX_CHAR_INPUT);
		cin.getline(b_street, MAX_CHAR_INPUT);
		Address my_address(b_city, b_state, b_street);
		Buyer my_buyer(b_name, b_pass, my_address, bmy_cart);
		user.addBuyer(&my_buyer);
	} break;
	//----------------------------------------------------------------------------------------//
	case 2:
	{
		char s_name[MAX_CHAR_INPUT];
		char s_pass[MAX_CHAR_INPUT];
		char s_city[MAX_CHAR_INPUT];
		char s_state[MAX_CHAR_INPUT];
		char s_street[MAX_CHAR_INPUT];
		Cart smy_cart;
		cout << "Hello Seller, please enter full name:" << endl;
		cin.ignore(numeric_limits <streamsize> ::max(), '\n');
		cin.getline(s_name, MAX_CHAR_INPUT);
		while (user.checkName(s_name, 1) == true)
		{
			cout << "your username is already take. please enter another one:" << endl;
			cin.getline(s_name, MAX_CHAR_INPUT);
		}
		cout << "please enter your password: (at least 6 digits) " << endl;
		cin.clear();
		cin.getline(s_pass, MAX_CHAR_INPUT);
		if (strlen(s_pass) < 6)
		{
			while (strlen(s_pass) < 6)
			{
				cout << "Your password didn't match the requierments! Please enter again :)" << endl;
				cin.clear();
				cin.getline(s_pass, MAX_CHAR_INPUT);
			}
		}
		cout << "please enter your Address: (1. state 2. city 3. street) " << endl;
		cin.getline(s_state, MAX_CHAR_INPUT);
		cin.getline(s_city, MAX_CHAR_INPUT);
		cin.getline(s_street, MAX_CHAR_INPUT);
		Address my_address(s_city, s_state, s_street);
		Seller my_seller(s_name, s_pass, my_address, smy_cart);
		user.addSeller(&my_seller);
	}break;
	//----------------------------------------------------------------------------------------//
	case 3:
	{
		char name[MAX_CHAR_INPUT];
		char pass[MAX_CHAR_INPUT];
		cout << "Please Log in first to add a product" << endl;
		cout << "Please enter your name: " << endl;
		cin.ignore(numeric_limits <streamsize> ::max(), '\n');
		cin.getline(name, MAX_CHAR_INPUT);
		cout << "Please enter your password: " << endl;
		cin.getline(pass, MAX_CHAR_INPUT);
		if (user.approveLogIn(name, pass, 1) == 0)
		{ // couldn't find the requested user
			while (user.approveLogIn(name, pass, 1) == 0)
			{
				int indicator;
				cout << "Your input didn't match, press 0 to exit: " << endl;
				cin >> indicator;
				if (indicator == 0)
					exit(1);
				cout << "Please enter your name: " << endl;
				cin.ignore(numeric_limits <streamsize> ::max(), '\n');
				cin.getline(name, MAX_CHAR_INPUT);
				cout << "Please enter your password: (press 0 to exit) " << endl;
				cin.getline(pass, MAX_CHAR_INPUT);
			}
		}
		char pName[MAX_CHAR_INPUT];
		char pCategory[MAX_CHAR_INPUT];
		int pPrice;
		Seller * my_seller = user.findSeller(name);
		cout << "Welcome, " << my_seller->getName() << endl;
		cout << "Please enter the product's name: " << endl;
		cin.getline(pName, MAX_CHAR_INPUT);
		cin.clear();
		cout << "Please enter the product category: (KIDS,CLOTHES,ELECTRONICS,OFFICE)" << endl;
		cin.getline(pCategory, MAX_CHAR_INPUT);
		while (strcmp(pCategory, "KIDS") != 0 && strcmp(pCategory, "OFFICE") != 0 && strcmp(pCategory, "ELECTRONICS") != 0 && strcmp(pCategory, "CLOTHES") != 0)
		{
			cout << "Please enter again the product category: (KIDS,CLOTHES,ELECTRONICS,OFFICE)" << endl;
			cin.getline(pCategory, MAX_CHAR_INPUT);
		}
		cout << "Please enter the price:" << endl;
		cin >> pPrice;
		if (strcmp(pCategory, "KIDS") == 0)
		{
			Product my_product(Product::KIDS, pName, pPrice);
			my_seller->addProductToSeller(&my_product);
		}
		else if (strcmp(pCategory, "OFFICE") == 0)
		{
			Product my_product(Product::OFFICE, pName, pPrice);
			my_seller->addProductToSeller(&my_product);
		}
		else if (strcmp(pCategory, "CLOTHES") == 0)
		{
			Product my_product(Product::CLOTHES, pName, pPrice);
			my_seller->addProductToSeller(&my_product);
		}
		else if (strcmp(pCategory, "ELECTRONICS") == 0)
		{
			Product my_product(Product::ELECTRONICS, pName, pPrice);
			my_seller->addProductToSeller(&my_product);
		}
	}break;//Add a product for seller
		   //----------------------------------------------------------------------------------------//
	case 4:
	{
		char name[MAX_CHAR_INPUT];
		char pass[MAX_CHAR_INPUT];
		cout << "Please Log in first to add a feedback" << endl;
		cout << "Please enter your name: " << endl;
		cin.ignore(numeric_limits <streamsize> ::max(), '\n');
		cin.getline(name, MAX_CHAR_INPUT);
		cout << "Please enter your password: " << endl;
		cin.getline(pass, MAX_CHAR_INPUT);
		if (user.approveLogIn(name, pass, 0) == 0)
		{ // couldn't find the requested user
			while (user.approveLogIn(name, pass, 0) == 0)
			{
				int indicator;
				cout << "Your input didn't match, press 0 to exit: " << endl;
				cin >> indicator;
				if (indicator == 0)
					exit(1);
				cout << "Please enter your name: " << endl;
				cin.getline(name, MAX_CHAR_INPUT);
				cout << "Please enter your password: (press 0 to exit) " << endl;
				cin.getline(pass, MAX_CHAR_INPUT);
				if (strcmp(pass, "0") == 0)
					break;
			}
		}
		// להכניס בדיקה שהקונה ביצע הזמנה מהמוכר
		Buyer * my_buyer = user.findBuyer(name);
		char sellerName[MAX_CHAR_INPUT];
		int	purchaseDay;
		int orderNumber;
		int	purchaseMonth;
		int	purchaseYear;
		char description[MAX_DESCRIPTION_SIZE];
		cout << "Welcome, " << my_buyer->getName() << endl;
		cout << "Please enter the name of the seller you want to write a feedback to: " << endl;
		cin.getline(sellerName, MAX_CHAR_INPUT);
		cout << "Please enter the order number:" << endl;
		cin >> orderNumber;
		/*if (my_buyer->findOrder(orderNumber == 0))
			{
				cout << "We haven't found your'e order, returning to main menu" << endl;
				break;
			}*/
			// find order and confirm the buyer bought from this seller, then send a ref for this seller
		Seller * my_seller = user.findSeller(sellerName);
		cout << "Please enter the day,month and year you made the order :" << endl;
		cin >> purchaseDay;
		cin >> purchaseMonth;
		cin >> purchaseYear;
		Date purchaseDate(purchaseDay, purchaseMonth, purchaseYear);
		cout << "Please enter your feedback description : " << endl;
		cin.ignore(numeric_limits <streamsize> ::max(), '\n');
		cin.getline(description, MAX_DESCRIPTION_SIZE);
		Feedback my_feedback(my_buyer->getName(), purchaseDate, description);
		my_seller->addFeedback(&my_feedback);
	}break;
	//----------------------------------------------------------------------------------------//
	case 5:
	{// add product for buyer's cart
		char name[MAX_CHAR_INPUT];
		char pass[MAX_CHAR_INPUT];
		cout << "Please Log in first to add a product" << endl;
		cout << "Please enter your name: " << endl;
		cin.ignore(numeric_limits <streamsize> ::max(), '\n');
		cin.getline(name, MAX_CHAR_INPUT);
		cout << "Please enter your password: " << endl;
		cin.getline(pass, MAX_CHAR_INPUT);
		if (user.approveLogIn(name, pass, 0) == 0)
		{ // couldn't find the requested user
			while (user.approveLogIn(name, pass, 0) == 0)
			{
				int indicator;
				cout << "Your input didn't match, press 0 to exit: " << endl;
				cin >> indicator;
				if (indicator == 0)
					exit(1);
				cout << "Please enter your name: " << endl;
				cin.ignore(numeric_limits <streamsize> ::max(), '\n');
				cin.getline(name, MAX_CHAR_INPUT);
				cout << "Please enter your password: (press 0 to exit) " << endl;
				cin.getline(pass, MAX_CHAR_INPUT);
				if (strcmp(pass, "0") == 0)
					break;
			}
		}
		bool flag = false;
		int to_continue, pSerial;
		char pCategory[MAX_CHAR_INPUT];
		Buyer * my_buyer = user.findBuyer(name);
		cout << "Welcome, " << my_buyer->getName() << endl;
		while (flag == false) // press 1 to continue looking for products, 0 to start adding products to cart
		{
			cout << "Please enter the category you want to search in: (KIDS,ELECTRONICS,OFFICE,CLOTHES) " << endl;
			cin.getline(pCategory, MAX_CHAR_INPUT);
			cin.clear();
			while (strcmp(pCategory, "KIDS") != 0 && strcmp(pCategory, "OFFICE") != 0 && strcmp(pCategory, "ELECTRONICS") != 0 && strcmp(pCategory, "CLOTHES") != 0)
			{
				cout << "Please enter again the product category: (KIDS,CLOTHES,ELECTRONICS,OFFICE)" << endl;
				cin.getline(pCategory, MAX_CHAR_INPUT);
			}
			cout << "These are the products that are currently in the category " << pCategory << endl;
			for (int i = 0; i < user.GetSellerLogicSizeArr(); i++)
			{
				user.GetSellerAddress()[i]->getCart().PrintCartByCategory(pCategory);
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
		cin.getline(name, MAX_CHAR_INPUT);
		cout << "Please enter the product's serial number you want to add to your cart: " << endl;
		cin >> pSerial;
		Seller * my_seller = user.findSeller(name);
		if (my_seller == nullptr)
		{
			while (my_seller == nullptr)
			{
				cout << "Are you sure? seller not found! try again" << endl;
				cin.ignore(numeric_limits <streamsize> ::max(), '\n');
				cin.getline(name, MAX_CHAR_INPUT);
				my_seller = user.findSeller(name);
			}
			
		}
		Product * my_product = my_seller->getCart().getProductBySerial(pSerial);
		if (my_product == nullptr)
		{
			while (my_product == nullptr)
			{
				cout << "Are you sure? product not found! enter serial number again" << endl;
				cin >> pSerial;
				my_product = my_seller->getCart().getProductBySerial(pSerial);
			}
		}
		my_buyer->addToCart(my_product);
	}break;
	//----------------------------------------------------------------------------------------//
	case 6:
	{
		//place a order

		char name[MAX_CHAR_INPUT];
		char pass[MAX_CHAR_INPUT];
		cout << "Hello buyer,please Log in first to make a order" << endl;
		cout << "Please enter your name: " << endl;
		cin.ignore(numeric_limits <streamsize> ::max(), '\n');
		cin.getline(name, MAX_CHAR_INPUT);
		cout << "Please enter your password: " << endl;
		cin.getline(pass, MAX_CHAR_INPUT);
		while (user.approveLogIn(name, pass, 0) == 0)//not fount the user
		{
			cout << "Your input didn't match, please enter again:" << endl;
			cout << "Please enter your name: " << endl;
			cin.ignore(numeric_limits <streamsize> ::max(), '\n');
			cin.getline(name, MAX_CHAR_INPUT);
			cout << "Please enter your password: " << endl;
			cin.ignore(numeric_limits <streamsize> ::max(), '\n');
			cin.getline(pass, MAX_CHAR_INPUT);
		}
		int countP = 0, counterArr = 0;
		int serial;
		Buyer *my_buyer = (user.findBuyer(name));
		cout << "Welcome, " << my_buyer->getName() << endl;
		if (my_buyer->getCart().getProductArr() == nullptr)
		{
			cout << "You don't have Items in your cart, return to the main menu." << endl; break;
		}
		cout << "This is your current cart:" << endl;
		my_buyer->getCart().PrintCart();
		cout << "Please enter the number of the product that you going to buy:" << endl;
		cin >> countP;
		Order order(countP);
		if (countP == 0) 
		{
			cout << "You Pressed 0 Proudcts." << endl; break;
		}
		cout << "Please write the serial number of the product that you want to order:(if you want to stop adding press -1)" << endl;
		cin >> serial;
		Product *temp;
		int logicArr = my_buyer->getCart().GetLogicS();//how many proudcts in the old cart
		while (serial != -1)
		{
			for (int i = 0; i < logicArr; i++)
			{
				if ((my_buyer->getCart().getProductArr())[i]->getSerial() == serial)
				{
					temp = ((my_buyer->getCart().getProductArr())[i]);
					order.GetProductsArray()[counterArr] = temp;
					counterArr++;
				}
			}
			cout << "Please write the serial number of the product that you want to order:(if you want to stop adding prees -1:)" << endl;
			cin >> serial;
		}
		order.setNumberOfProd(counterArr);
		my_buyer->AddOrderToOrderArr(&order);
		cout << "that is your cart:" << endl;
		for (int i = 0; i < countP; i++)
		{
			cout << "<----------------------------------------->" << endl;
			cout << "- Product's Name : " << order.GetProductsArray()[i]->getName() << endl;
			cout << "- Product's Price : " << order.GetProductsArray()[i]->getPrice() << endl;
			cout << "- Product's serial number : " << order.GetProductsArray()[i]->getSerial() << endl;

		}
		cout << "<----------------------------------------->" << endl;
		cout << "Total cart cost:-" << order.GetPriceOfOrder() << "- shekel's" << endl;
	}break;
	//----------------------------------------------------------------------------------------//
	case 7:
	{
		//payment for order:
		int input, temp, serialnumber;
		char name[MAX_CHAR_INPUT];
		char pass[MAX_CHAR_INPUT];
		cout << "Hello buyer,please Log in first to make a order" << endl;
		cout << "Please enter your name: " << endl;
		cin.ignore(numeric_limits <streamsize> ::max(), '\n');
		cin.getline(name, MAX_CHAR_INPUT);
		cout << "Please enter your password: " << endl;
		cin.getline(pass, MAX_CHAR_INPUT);
		while (user.approveLogIn(name, pass, 0) == 0)//not fount the user
		{
			cout << "Your input didn't match, please enter again:" << endl;
			cout << "Please enter your name: " << endl;
			cin.ignore(numeric_limits <streamsize> ::max(), '\n');
			cin.getline(name, MAX_CHAR_INPUT);
			cout << "Please enter your password: " << endl;
			cin.ignore(numeric_limits <streamsize> ::max(), '\n');
			cin.getline(pass, MAX_CHAR_INPUT);
		}
		Buyer *my_buyer = (user.findBuyer(name));
		cout << "Welcome, " << my_buyer->getName() << endl;
		if (my_buyer->getOrderlogicsize() == 0)
		{
			cout << "You don't have orders to pay for, return to the main menu." << endl; break;
		}
		int lastorder = my_buyer->getOrderlogicsize() - 1;//size of the  order array size-1
		int numberofProducts = (my_buyer->GetOrderArray()[lastorder])->getNumberOfProd();
		cout << "We understand that you want to pay for your final cart:" << endl;
		for (int i = 0; i < numberofProducts; i++)
		{
			cout << "Product name: " << (my_buyer->GetOrderArray()[lastorder])->GetProductsArray()[i]->getName() <<
				" Product Serial: " << (my_buyer->GetOrderArray()[lastorder])->GetProductsArray()[i]->getSerial() << " Prouct Price: "
				<< (my_buyer->GetOrderArray()[lastorder])->GetProductsArray()[i]->getPrice() << endl;// *(my_buyer.GetOrderArray()[lastorder])->GetProductsArray()[i]->getPrice() << endl;
		}
		cout << "The total price of your cart is:" << my_buyer->GetOrderArray()[lastorder]->GetPriceOfOrder() << endl;
			int logicOrder, logicCart, serialOrder, serialCart;
			Product **order;
			Product **cart;
			cart = my_buyer->getCart().getProductArr();
			order = (my_buyer->GetOrderArray()[lastorder])->GetProductsArray();
			logicOrder = my_buyer->GetOrderArray()[lastorder]->getNumberOfProd();
			logicCart = my_buyer->getCart().GetLogicS();
			int counter = 0;
			for (int i = 0; i < logicCart; i++)
			{
				if (my_buyer->getCart().getProductArr()[i] != nullptr)
				{
					for (int j = 0; j < logicOrder; j++)
					{
						serialCart = my_buyer->getCart().getProductArr()[i]->getSerial();//serial in the cart in the place i
						serialOrder = my_buyer->GetOrderArray()[lastorder]->GetProductsArray()[j]->getSerial();//serial in the order in the place j
						if (serialCart == serialOrder && (i + 1 < logicCart))//case 1:when its not the last one
						{
							my_buyer->getCart().getProductArr()[i] = my_buyer->getCart().getProductArr()[i + 1];
							my_buyer->getCart().getProductArr()[i + 1] = nullptr;
							j = -1;//becuse if you put new item in my_buyer->getCart().getProductArr()[i]  you have to check it again
							counter++;//to know how many proudct deleted
						}
						if ((serialCart == serialOrder) && (i + 1 == logicCart))//case 2:its the last place in the array
						{
							my_buyer->getCart().getProductArr()[i] = nullptr;
							counter++;
						}
					}
				}
			}
			for (int i = 0; i < logicCart; i++)
			{
				if (my_buyer->getCart().getProductArr()[i] == nullptr)
					delete my_buyer->getCart().getProductArr()[i];
			}
			my_buyer->getCart().SetLogicS(logicCart - counter);
			if(my_buyer->getCart().GetPhiS()-1!=0)
			my_buyer->getCart().SetPhiS(logicCart - counter);
			cout << "Thank you for your purchase,enjoy!" << endl;
		
	}break;
	case 8:
	{
		for (int i = 0; i < user.GetBuyerLogicSizeArr(); i++)
			user.GetBuyerAddress()[i]->printBuyer();
	}break;
	case 9:
	{
		for (int j = 0; j < user.GetSellerLogicSizeArr(); j++)
			user.GetSellerAddress()[j]->printSeller();
	}break;
	case 10:
	{
		char pName[MAX_CHAR_INPUT];
		cout << "Please enter the name of the product you want to search for: " << endl;
		cin.ignore(numeric_limits <streamsize> ::max(), '\n');
		cin.getline(pName, MAX_CHAR_INPUT);
		for (int i = 0; i < user.GetSellerLogicSizeArr(); i++)
		{
			user.GetSellerAddress()[i]->getCart().PrintCartByProductName(pName);
		}
	}
	}
}
