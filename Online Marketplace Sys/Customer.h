#pragma once
#include <string>

using namespace std;

template<class T>
class Customer {
	T id, phone;
	string name, address, email;
	float cartTotalPrice = 0;

public:
	Customer();
	Customer(string, T, string, T, string);
	Customer addCustomer();
	bool searchId(T);
	void display();
	~Customer(void);
};