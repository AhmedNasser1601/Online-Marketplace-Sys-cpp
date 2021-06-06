#include "Product.h"

#include <iostream>
#include <stack>
#include <queue>
#include <list>
#include <string>
#include <assert.h>

using namespace std;

template <class T>
Product<T>::Product() {}

template<class T>
Product<T>::Product(int i, string n, float p, string c, int si) {
	id = i;
	name = n;
	price = p;
	category = c;
	sellerId = si;
}

template<class T>
void Product<T>::addProduct() {
	int Id, SellerId;
	string Name, Category;
	float Price;

	cout << "Enter Id: "; cin >> Id;
	cout << "Enter Name: "; cin >> Name;
	cout << "Enter Price: "; cin >> Price;
	cout << "Enter Category: "; cin >> Category;
	cout << "Enter Seller Id: "; cin >> SellerId;

	Product<T> p(Id, Name, Price, Category, SellerId);

	return p;
}

template<class T>
T Product<T>::fun() {

	return T();
}

template <class T>
Product<T>::~Product() {}