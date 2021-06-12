#pragma once
#include <string>

using namespace std;

template <class T>
class Product {
	T id, sellerId, quantity;
	string name, category;
	float price;
	bool state;

public:
	Product();
	Product(T, string, float, string, T, T, bool);
	Product addProduct(T);
	bool searchName(string);
	bool searchId(T);
	bool searchCategory(string);
	void display(bool);
	void changeState(string);
	float getPrice();
	bool checkQuantity(T);
	bool checkSellerId(T);
	void updateQuantity(T);
	~Product(void);
};