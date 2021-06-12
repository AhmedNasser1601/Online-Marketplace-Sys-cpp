#pragma once
#include <string>

using namespace std;

template <class T>
class Seller {
	T id;
	string name, email;

public:
	Seller();
	Seller(T, string, string);
	Seller addSeller();
	bool searchId(T);
	void display();
	~Seller(void);
};