#include "Admin.h"

#include <iostream>
#include <string>

using namespace std;

template<class T>
Admin<T>::Admin() {}

template<class T>
bool Admin<T>::login() {
	cout << "\n\tLogin First\n\n";

	cout << "Enter Username: "; string u; cin >> u;
	cout << "Enter Password: "; T p; cin >> p;

	if (username == u && password == p) {
		return true;
	}
	else {
		cout << "\n\n\n\tInvalid Admin Login\n\n";
		return false;
	}
}

template<class T>
Admin<T>::~Admin(void) {}