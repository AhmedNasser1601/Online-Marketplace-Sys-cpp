#pragma once
#include<string>

using namespace std;

template <class T>
class Product {
	T id, sellerId;
	string name, category;
	float price;

public:
	Product();
	Product(T, string, float, string, T);
	Product addProduct();
	void display();
	~Product(void);
};