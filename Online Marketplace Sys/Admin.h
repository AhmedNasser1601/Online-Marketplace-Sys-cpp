#pragma once
#include <string>

using namespace std;

template <class T>
class Admin {
	string username = "admin";
	T password = 123;

public:
	Admin();
	bool login();
	~Admin(void);
};