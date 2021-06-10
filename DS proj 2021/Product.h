#pragma once
#include <string>

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
	bool searchName(string Name);
	bool searchId(T Id);
	bool searchCategory(string Category);
	void display();
	~Product(void);
};