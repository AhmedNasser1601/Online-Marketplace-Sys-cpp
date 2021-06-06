#include "Seller.h"

#include <iostream>
#include <stack>
#include <queue>
#include <list>
#include <string>
#include <assert.h>

using namespace std;

template<class T>
Seller<T>::Seller() {

}

template<class T>
Seller<T>::Seller(T i, string n, string e) {
	id = i;
	name = n;
	email = e;
}

template<class T>
Seller<T> Seller<T>::addSeller() {
	T Id;
	string Name, Email;

	cout << "Enter Id: "; cin >> Id;
	cout << "Enter Name: "; cin >> Name;
	cout << "Enter Email: "; cin >> Email;

	Seller<T> s(Id, Name, Email);

	return s;
}

template <class T>
void Seller<T>::display() {
	cout
		<< "Id: " << id
		<< "\tName: " << name
		<< "\tEmail: " << email
		<< endl;
}

template <class T>
Seller<T>::~Seller(void) {}