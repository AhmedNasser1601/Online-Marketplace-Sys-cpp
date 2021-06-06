#include "Customer.h"

#include <iostream>
#include <stack>
#include <queue>
#include <list>
#include <string>
#include <assert.h>

using namespace std;

struct customer_data {
	string name;
	int id;
	string address;
	int phone;
	string email;
}c[10];

Customer::Customer() {}

void Customer::addCustomer() {
	char ch;

	cout << "enter the num of customer ";
	int size; cin >> size;

	for (int i = 0; i < size; i++) {
		cout << "enter Name of Customer (" << i + 1 << "): ";
		cin >> c[i].name;

		cout << "Enter Id: ";
		cin >> c[i].id;

		cout << "Enter Address: ";
		cin >> c[i].address;

		cout << "Enter Phone: ";
		cin >> c[i].phone;

		cout << "Enter Email: ";
		cin >> c[i].email;

		count++;
	}

}

void Customer::display() {
	for (int i = 0; i < count; i++) {
		cout << c[i].name << "\t"
			<< c[i].id << "\t"
			<< c[i].email << "\t"
			<< c[i].address << "\t"
			<< c[i].phone << endl;
	}
}

Customer::~Customer(void) {}