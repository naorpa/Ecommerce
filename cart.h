#ifndef __CART_H
#define __CART_H

class Product;

class Cart
{
public:
	friend class Buyer;
	friend class Seller;
public:
	Cart();
	Cart(const Cart&other);
	~Cart();
	const int GetLogicS() const;
	const int GetPhiS() const;
	Product ** getProductArr() const;
	void SetLogicS(int logic);
	void SetPhiS(int phis);
	void PrintCart();
	void PrintCartByCategory(char * pCategory);
	void PrintCartByProductName(char * pName);
	Product* getProductBySerial(int serial);
	void SetProductArr(Product **Arr);
private:
	int c_logicSize;
	int c_phsize;
	Product ** c_prouductArr;
};


#endif // !__CART_H

