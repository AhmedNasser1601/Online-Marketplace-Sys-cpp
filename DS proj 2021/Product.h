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
	Product(int, string, float, string, int);
	void addProduct();
	T fun();
	~Product(void);
};