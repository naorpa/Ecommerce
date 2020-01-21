#ifndef __CART_H
#define __CART_H
#include <string>
#include <vector>
using namespace std;
class Product;

class Cart
{
public:
	Cart();
	~Cart();
public:
	vector <Product *> getProductArr() ;
	void PrintCart();
	void PrintCartByCategory(const string & pCategory);
	void PrintCartByProductName(const string & pName);
	const int & GetLogicS() const;
	const string & getProductName(int index);
	Product * getProductBySerial(int serial);
	void SetProductArr(vector<Product *> Arr);
	void addToCart(Product * product);
	void deleteFromCart(Product * product);
	vector<Product *>::iterator & getBegin();
public:
	//const Cart& operator=(const Cart &other);
private:
	vector<Product *>c_prouductArr;
};


#endif // !__CART_H

