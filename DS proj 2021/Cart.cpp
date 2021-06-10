#include "Cart.h"

#include <iostream>
#include <stack>
#include <queue>
#include <list>
#include <string>
#include <assert.h>

using namespace std;

stack<int> z;

template <class T>
void Cart<T>::printall() {
	cout << "items in cart is :" << endl;

	while (!z.empty()) {
		cout << z.top() << endl;
		z.pop();
	}
}

template <class T>
void Cart<T>::cart_data() {
	int flag = 1;

	while (flag == 1) {
		cout
			<< "Add to cart press :-  1" << endl
			<< "delete item from cart  press :-  2" << endl
			<< "display all items in cart press  :-  3" << endl;
		int choice; cin >> choice;

		cout << endl;

		if (choice == 1) {
			cout << "enter item id" << endl;
			int id; cin >> id;
			z.push(id);
		}

		else if (choice == 2) {
			if (!z.empty())
				z.pop();
			else
				cout << "your cart is empty ";
		}

		else if (choice == 3) {
			printall();
		}

		cout
			<< "if you want continue press : 1" << endl
			<< "else press : 0 " << endl;
		cin >> flag;

		if (flag == 1)
			continue;
		else
			break;
	}
}

template<class T>
Cart<T>::~Cart(void) {}