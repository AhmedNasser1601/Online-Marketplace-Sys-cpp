#include "Customer.h"

#include <iostream>
#include <stack>
#include <queue>
#include <list>
#include <string>
#include <assert.h>

using namespace std;

template<class T>
Customer<T>::Customer() {
	id = 0;
	phone = 0;
	name = "";
	address = "";
	email = "";
}

template<class T>
Customer<T>::Customer(string N, T I, string A, T P, string E) {
	name = N;
	id = I;
	address = A;
	phone = P;
	email = E;
}

template<class T>
Customer<T> Customer<T>::addCustomer() {
	T Id, Phone;
	string Name, Address, Email;

	cout << "Enter Name: "; cin >> Name;
	cout << "Enter Id: "; cin >> Id;
	cout << "Enter Address: "; cin >> Address;
	cout << "Enter Phone: "; cin >> Phone;
	cout << "Enter Email: "; cin >> Email;

	Customer<T> c(Name, Id, Address, Phone, Email);

	return c;
}

template<class T>
void Customer<T>::display() {
	cout
		<< "Name: " << name
		<< "\tId: " << id
		<< "\tAddress: " << address
		<< "\tPhone: " << phone
		<< "\tEmail: " << email
		<< endl;
}

template <class T>
Customer<T>::~Customer(void) {}