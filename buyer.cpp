#include "buyer.h"
#include "product.h"
Buyer::Buyer(const char * name, const char * password, Address &add)
	:Users(name,password,add)
{
	//main c'tor
	this->b_order = nullptr;
	this->b_order_size = 0;
}
//----------------------------------------------------------------------------------------//
Buyer::Buyer(const Buyer & other) : Users(other) ,b_cart(other.b_cart)
{//copy c'tor
	SetOrderLogicSize(other.b_order_size);
	this->b_order = new Order *[this->b_order_size];
	for (int i = 0; i < this->b_order_size; i++)
	{
		this->b_order[i] = new Order(*this->b_order[i]);
	}
}
//----------------------------------------------------------------------------------------//
Buyer::Buyer(Buyer && other) : Users(move(other))
{
	//move c'tor
	this->b_order = other.b_order;
	other.b_order = nullptr;
}
//----------------------------------------------------------------------------------------//
Buyer::~Buyer()
{//d'tor

	for (int i = 0; i < this->b_order_size; i++)
		delete this->b_order[i];
	delete[] this->b_order;
}
//----------------------------------------------------------------------------------------//
const Buyer & Buyer::operator=(const Buyer & other)
{
	if (this != &other)
	{
		Users::operator=(other);
		this->b_cart = other.b_cart;
		if (this->b_order_size > 0)
		{
			for (int i = 0; i < this->b_order_size; i++)
				delete this->b_order[i];
			delete[] this->b_order;
		}
		SetOrderLogicSize(other.b_order_size);
		this->b_order = new Order *[this->b_order_size];
		for (int i = 0; i < this->b_order_size; i++)
		{
			this->b_order[i] = new Order(*this->b_order[i]);
		}
	}
	return *this;
}
//----------------------------------------------------------------------------------------//
const Buyer & Buyer::operator=(Buyer && other)
{
	if (this != &other)
	{
		Users::operator=(other);
		this->b_cart = other.b_cart;
		other.b_cart.SetProductArr(nullptr);
		for (int i = 0; i < this->b_order_size; i++)
				delete this->b_order[i];
		delete[] this->b_order;
		this->b_order_size = other.b_order_size;
		this->b_order = other.b_order;
		other.b_order = nullptr;
	}
	return *this;
}
//----------------------------------------------------------------------------------------//
Cart & Buyer::getCart()
{
	return this->b_cart;
}
//----------------------------------------------------------------------------------------//
bool Buyer::findOrder(int num_of_order)
{ // finds a specific order and return true if the order exits and already paid, false if it doesn't
	for (int i = 0; i < this->b_order_size; i++)
	{
		if (this->b_order[i]->GetOrderNumber() == num_of_order)
		{
			if (this->b_order[i]->getPaymentSatus() == true)
			{
				return true;
			}
		}
	}
	return false;
}
//----------------------------------------------------------------------------------------//
Order ** Buyer::GetOrderArray() const
{
	return this->b_order;
}
//----------------------------------------------------------------------------------------//
void Buyer::SetOrderLogicSize(const int size)
{
	this->b_order_size = size;
}
//----------------------------------------------------------------------------------------//
void Buyer::AddOrderToOrderArr(Order * order)
{
	if (this->b_order == nullptr)
	{//empty arr
		this->b_order = new Order*;
		this->b_order[0] = new Order(*order);
		this->b_order_size++;
	}
	else
	{ // realloc
		Order ** new_order_array = new Order *[this->b_order_size+1];
		int size = this->b_order_size;
		for (int i = 0; i < size; i++)
		{
			new_order_array[i] = this->b_order[i];
		}
		delete[] this->b_order;
		this->b_order = new_order_array;
		this->b_order[this->b_order_size] = new Order(*order); //insert new order by ptr
		this->b_order_size++;
	}

}
//----------------------------------------------------------------------------------------//
int Buyer::getOrderlogicsize() const
{
	return this->b_order_size;
}

//----------------------------------------------------------------------------------------//
void Buyer::makeOrder()
{
	bool found = false;
	int lastOrder = -1;
	for (int i = 0; i < this->b_order_size && found == false; i++)
	{//find the last order the buyer didn't pay for
		if (this->b_order[i]->getPaymentSatus() == false)
		{
			lastOrder = i;
			found = true;
		}
	}
	if (lastOrder == -1)
	{ //all the orders have been paid, or no orders exist yet
		return; //have no orders to pay for right now
	}
	int updatedCartSize = this->b_cart.GetLogicS() - this->GetOrderArray()[lastOrder]->getNumberOfProd();
	int lastIndex = -1;
	bool flag = false;

	for (int i = 0; i < this->b_cart.GetLogicS(); i++)
	{
		for (int j = 0; j < this->b_order[lastOrder]->getNumberOfProd() && flag == false; j++)
		{
			if (this->b_cart.getProductArr()[i] == this->b_order[lastOrder]->GetProductsArray()[j])
			{
				this->b_cart.getProductArr()[i] = nullptr;
				flag = true;
			}
		}
		flag = false;
	}
	if (updatedCartSize != 0)
	{
		for (int i = 0; i < this->b_cart.GetLogicS(); i++)
		{
			if (this->b_cart.getProductArr()[i] == nullptr)
			{
				flag = false;
				for (int j = i + 1; j < this->b_cart.GetLogicS() && flag == false; j++)
				{
					if (this->b_cart.getProductArr()[j] != nullptr)
					{
						this->b_cart.getProductArr()[i] = this->b_cart.getProductArr()[j];
						this->b_cart.getProductArr()[j] = nullptr;
						flag = true;
					}
				}
			}
		}
	}
	if (updatedCartSize > 0)
	{

		this->b_cart.SetLogicS(updatedCartSize);
		this->b_cart.SetPhiS(updatedCartSize);
		this->GetOrderArray()[lastOrder]->setPaymentSatus(true);
	}
	if (updatedCartSize <= 0)
	{ // cart need initialization
		this->b_cart.SetLogicS(0);
		this->b_cart.SetPhiS(1);
		this->b_cart.SetProductArr(nullptr);
		this->GetOrderArray()[lastOrder]->setPaymentSatus(true);
	}
}
//----------------------------------------------------------------------------------------//

ostream & operator<<(ostream & os, Buyer & buyer)
{
	os << "- Buyer's Name : " << buyer.getName() << endl;
	os << "- Buyer's Address : " << buyer.add.getState() << ", " << buyer.add.getCity() << ", " << buyer.add.getStreet() << endl;
	if (buyer.b_order_size == 0)
		os << "- " << buyer.getName() << " didn't buy anything yet!" << endl;
	else
	{
		cout << "- These are the products " << buyer.getName() << " bought:" << endl;
		for (int i = 0; i < buyer.b_order_size; i++)
		{
			for (int j = 0; j < buyer.b_order[i]->getNumberOfProd(); j++)
			{
				os << "	- Product's Name : " << buyer.b_order[i]->GetProductsArray()[j]->getName() << endl;
				os << "	- Product's Price : " << buyer.b_order[i]->GetProductsArray()[j]->getPrice() << endl;
				os << "	- Product's serial number : " << buyer.b_order[i]->GetProductsArray()[j]->getSerial() << endl;
				os << "<----------------------------------------->" << endl;
			}
		}
	}
	os << "<----------------------------------------->" << endl;
	return os;
}
//----------------------------------------------------------------------------------------//
const Buyer & Buyer::operator>(Buyer & other1)
{
	int sum1 = 0, sum2 = 0;
	int Logic1, Logic2;
	Logic1 = other1.getCart().GetLogicS();
	Logic2 = this->b_cart.GetLogicS();
	for (int i = 0; i < Logic1; i++)
		sum1 += other1.getCart().getProductArr()[i]->getPrice();
	for (int i = 0; i < Logic2; i++)
		sum2 += this->b_cart.getProductArr()[i]->getPrice();
	if (sum1 == sum2)
		cout << "equal carts! we choose random buyer." << endl;
	if (sum1 > sum2)
		return other1;
	else
		return *this;

}