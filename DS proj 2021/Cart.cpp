#include "Cart.h";

#include <iostream>
#include <fstream>
#include <stack>
#include <queue>
#include <list>
#include <string>
#include <assert.h>

using namespace std;

stack<Cart<int>> z;

template<class T>
Cart<T>::Cart() {

}

template<class T>
void Cart<T>::displayAll() {
	/*ofstream cart_cart;
	cart_cart.open("2ndcart.txt");

	cout << "items in cart is :" << endl;

	while (!z.empty()) {
		cout << z.top() << endl;
		cart_cart << "item in cart is" << z.top() << endl;
		z.pop();
	}

	cart_cart.close();*/
}

template<class T>
void Cart<T>::cartData() {
	T flag = 1;

	while (flag == 1) {
		cout << "Add to cart press :-  1" << endl << "delete item from cart  press :-  2" << endl << "display all items in cart press  :-  3" << endl;
		T choice; cin >> choice;

		if (choice == 1) {
			cout << "enter item id" << endl;
			T id; cin >> id;

			z.push(id);
		}

		else if (choice == 2) {
			if (!z.empty())
				z.pop();
			else
				cout << "your cart is empty ";
		}

		else if (choice == 3) {
			displayAll();
		}

		cout << "if you want continue press : 1" << endl << "else press : 0 ";
		cin >> flag;

		if (flag == 1)
			continue;
		else
			break;
	}
}

template <class T>
Cart<T>::~Cart(void) {}