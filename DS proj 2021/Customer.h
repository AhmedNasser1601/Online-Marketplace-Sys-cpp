#pragma once
#include<string>

using namespace std;

template<class T>
class Customer {
	T id, phone;
	string name, address, email;

public:
	Customer();
	Customer(string, T, string, T, string);
	Customer addCustomer();
	void display();
	~Customer(void);
};