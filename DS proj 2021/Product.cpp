#include "Product.h"

#include <iostream>
#include <stack>
#include <queue>
#include <list>
#include <string>
#include <assert.h>

using namespace std;

template <class T>
Product<T>::Product() {

}

template<class T>
Product<T>::Product(T i, string n, float p, string c, T si) {
	id = i;
	name = n;
	price = p;
	category = c;
	sellerId = si;
}

template<class T>
Product<T> Product<T>::addProduct() {
	T Id, SellerId;
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
void Product<T>::display() {
	cout
		<< "Id: " << id
		<< "\tName: " << name
		<< "\tPrice: " << price
		<< "\tCategory: " << category
		<< "\tSeller Id: " << sellerId
		<< endl;
}

template <class T>
Product<T>::~Product() {}