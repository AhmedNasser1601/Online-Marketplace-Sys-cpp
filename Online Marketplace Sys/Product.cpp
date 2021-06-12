#include "Product.h"

#include <iostream>
#include <string>

using namespace std;

template <class T>
Product<T>::Product() {}

template<class T>
Product<T>::Product(T i, string n, float p, string c, T si, T q, bool s) {
	id = i;
	name = n;
	price = p;
	category = c;
	sellerId = si;
	quantity = q;
	state = s;
}

template<class T>
Product<T> Product<T>::addProduct(T sId) {
	T Id, Quantity;
	string Name, Category;
	float Price;
	bool State = false;

	cout << "Enter Id: "; cin >> Id;
	cout << "Enter Name: "; cin >> Name;
	cout << "Enter Price: $"; cin >> Price;
	cout << "Enter Category: "; cin >> Category;
	cout << "Enter Quantity: "; cin >> Quantity;
	cout << endl;

	Product<T> p(Id, Name, Price, Category, sId, Quantity, State);

	return p;
}

template<class T>
bool Product<T>::searchName(string Name) {
	if (name == Name)
		return true;

	return false;
}

template<class T>
bool Product<T>::searchId(T Id) {
	if (id == Id)
		return true;

	return false;
}

template<class T>
bool Product<T>::searchCategory(string Category) {
	if (category == Category)
		return true;

	return false;
}

template<class T>
void Product<T>::display(bool prodStatus) {
	if (!prodStatus || (prodStatus && state)) {
		cout
			<< "Id: " << id
			<< "\tName: " << name
			<< "\tPrice: $" << price
			<< "\tCategory: " << category
			<< "\tSeller Id: " << sellerId
			<< "\tQuantity: " << quantity;

		if (!prodStatus) {
			cout << "\tStatus: ";

			if (state)
				cout << "Accepted";
			else
				cout << "Rejected";
		}

		cout << endl;
	}
}

template<class T>
void Product<T>::changeState(string State) {
	if (State == "Accept" || State == "accept" || State == "1") {
		state = true;
		cout << "\tAccepted\n";
	}
	else {
		state = false;
		cout << "\tRejected\n";
	}
}

template<class T>
float Product<T>::getPrice() {
	return price;
}

template<class T>
bool Product<T>::checkQuantity(T Required) {
	if (quantity - Required >= 0)
		return true;

	return false;
}

template<class T>
bool Product<T>::checkSellerId(T sId) {
	if (sellerId == sId)
		return true;

	return false;
}

template<class T>
void Product<T>::updateQuantity(T Quantity) {
	quantity -= Quantity;
}

template <class T>
Product<T>::~Product() {}