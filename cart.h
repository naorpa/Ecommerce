#ifndef __CART_H
#define __CART_H

class Product;

class Cart
{
public:
	Cart();
	Cart(const Cart&other);
	~Cart();
	const int GetLogicS() const;
	const int GetPhiS() const;
	Product ** getProductArr();
	void SetLogicS(int logic);
	void SetPhiS(int phis);
	void PrintCart();
	void PrintCartByCategory(char * pCategory);
	void PrintCartByProductName(char * pName);
	const char * getProductName(int index);
	Product* getProductBySerial(int serial);
	void SetProductArr(Product **Arr);
	void addToCart(Product * product);
public:
	const Cart& operator=(const Cart &other);
private:
	int c_logicSize;
	int c_phsize;
	Product ** c_prouductArr;
};


#endif // !__CART_H

