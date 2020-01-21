#include "buyer.h"
#include <vector>
#include "product.h"
Buyer::Buyer(const string & name, const string & password, Address &add)
	:Users(name, password, add)
{
}
//----------------------------------------------------------------------------------------//
Buyer::~Buyer()
{//d'tor
	this->b_order.clear();
}
//----------------------------------------------------------------------------------------//
const Buyer & Buyer::operator=(const Buyer & other)
{
	if (this != &other)
	{
		Users::operator=(other);
		this->b_cart = other.b_cart;
		this->b_order = other.b_order;
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
		this->b_order = other.b_order;
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
	vector<Order *>::iterator itr = this->b_order.begin();
	vector<Order *>::iterator itrEnd = this->b_order.end();
	for (; itr!=itrEnd;++itr)
	{
		if ((*itr)->GetOrderNumber() == num_of_order)
		{
			if ((*itr)->getPaymentSatus() == true)
			{
				return true;
			}
		}
	}
	return false;
}
//----------------------------------------------------------------------------------------//
vector <Order *> Buyer::GetOrderArray() const
{
	return this->b_order;
}
//----------------------------------------------------------------------------------------//
/*void Buyer::SetOrderLogicSize(const int size)
{
	this->b_order_size = size;
}*/
//----------------------------------------------------------------------------------------//
void Buyer::AddOrderToOrderArr(Order * order)
{
	this->b_order.push_back(order);
	if (this->b_order.capacity() == this->b_order.size())
		this->b_order.reserve(this->b_order.capacity() * 2); // for better complexity*/
}
//----------------------------------------------------------------------------------------//
int Buyer::getOrderlogicsize() const
{
	return this->b_order.size();
}

//----------------------------------------------------------------------------------------//
void Buyer::makeOrder()
{
	bool found = false;
	int lastOrder = -1;
	for (int i = 0; i < this->b_order.size() && found == false; i++)
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
				this->b_cart.deleteFromCart(this->b_cart.getProductArr()[i]);
				//this->b_cart.getProductArr()[i] = nullptr;
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
						this->b_cart.deleteFromCart(this->b_cart.getProductArr()[j]);
						//this->b_cart.getProductArr()[j] = nullptr;
						flag = true;
					}
				}
			}
		}
	}
	if (updatedCartSize > 0)
	{
	//	this->b_cart.setSize(updatedCartSize);
		this->GetOrderArray()[lastOrder]->setPaymentSatus(true);
	}
	if (updatedCartSize <= 0)
	{ // cart need initialization
	//	this->b_cart.setSize(updatedCartSize);
		this->GetOrderArray()[lastOrder]->setPaymentSatus(true);
	}
}

//----------------------------------------------------------------------------------------//

ostream & operator<<(ostream & os, Buyer & buyer)
{
	os << "- Buyer's Name : " << buyer.getName() << endl;
	os << "- Buyer's Address : " << buyer.add.getState() << ", " << buyer.add.getCity() << ", " << buyer.add.getStreet() << endl;
	if (buyer.b_order.size() == 0)
		os << "- " << buyer.getName() << " didn't buy anything yet!" << endl;
	else
	{
		cout << "- These are the products " << buyer.getName() << " bought:" << endl;
		for (int i = 0; i < buyer.b_order.size(); i++)
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