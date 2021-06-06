#include "Customer.h"
#include<iostream>
#include<String>
using namespace std;
struct customer_data{
	string name;
	int id;
	string address;
	int phone;
	string email;
};
customer_data c[10];
void Customer::add_customer(){
	char ch;
	cout << "enter the num of customer ";
	int size;
	cin >> size;
	for (int i = 0; i < size; i++){
		cout << "enter the name of the customer num "<<i+1 << endl;
		cin >> c[i].name;
		cout << "enter the id " << endl;
		cin >> c[i].id;
		cout << "enter the address  " << endl;
		cin >> c[i].address;
		cout << "enter the phone " << endl;
		cin >> c[i].phone;
		cout << "enter the email " << endl;
		cin >> c[i].email;
		count++;

	}

}
void Customer::display() {

	for (int i = 0; i < count; i++){

		cout << c[i].name << "\t" << c[i].id << "\t" << c[i].email << "\t" << c[i].address << "\t" << c[i].phone << endl;
	}

}
