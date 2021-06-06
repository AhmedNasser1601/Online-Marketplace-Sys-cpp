#pragma once

class Customer {
	int count = 0;

public:
	Customer();
	void addCustomer();
	void display();
	~Customer(void);
};