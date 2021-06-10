#include <iostream>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <string>

#include "Seller.cpp"
#include "Product.cpp"
#include "Customer.cpp"
//#include "Cart.cpp"

using namespace std;

static int vsCounter = 0, vpCounter = 0, vcCounter = 0;

Seller<int> S;
Product<int> P;
Customer<int> C;
//Cart<int> CC;

vector<Seller<int>> vls;
vector<Product<int>> vlp;
vector<Customer <int>> vlc;

/////////////////////////////=> Seller Functions <=/////////////////////////////
void addSellers() {
	cout << "Enter num of the new Sellers: ";
	int sizeS; cin >> sizeS;

	for (int i = 0; i < sizeS; i++) {
		cout << "\nEnter Seller (" << i + 1 << ") Data :-\n";

		vls.push_back(S.addSeller());
		vsCounter++;
	}
}

void displaySellers() {
	for (int i = 0; i < vsCounter; i++) {
		vls[i].display();
	}
}

void sizeSellers() {
	cout << "Sellers num is: " << vsCounter << endl;
}

void addProducts() {
	cout << "Enter num of the new Products: ";
	int sizeP; cin >> sizeP;

	for (int i = 0; i < sizeP; i++) {
		cout << "\nEnter Product (" << i + 1 << ") Data :-\n";

		vlp.push_back(P.addProduct());
		vpCounter++;
	}
}

/////////////////////////////=> Customer Functions <=////////////////////////////
void addCustomers() {
	cout << "Enter num of the new Customers: ";
	int sizeC; cin >> sizeC;

	for (int i = 0; i < sizeC; i++) {
		cout << "\nEnter Customer (" << i + 1 << ") Data :-\n";

		vlc.push_back(C.addCustomer());
		vcCounter++;
	}
}

void displayCustomers() {
	for (int i = 0; i < vcCounter; i++) {
		vlc[i].display();
	}
}

void sizeCustomers() {
	cout << "Customers num is: " << vcCounter << endl;
}

void buyProducts() {
	for (int i = 0; i < vpCounter; i++) {
		vlp[i].display();
	}
}

/////////////////////////////=> Product Functions <=////////////////////////////
void searchName() {
	cout << "Enter the Product Name to Search: ";
	string name; cin >> name;

	for (int i = 0; i < vpCounter; i++) {
		if (vlp[i].searchName(name))
			vlp[i].display();
	}
}
void searchId() {
	cout << "Enter the Product Id to Search: ";
	int id; cin >> id;

	for (int i = 0; i < vpCounter; i++) {
		if (vlp[i].searchId(id))
			vlp[i].display();
	}
}

void searchCategory() {
	cout << "Enter the Category Name to Search: ";
	string category; cin >> category;

	for (int i = 0; i < vpCounter; i++) {
		if (vlp[i].searchCategory(category))
			vlp[i].display();
	}
}

void searchProducts() {
	cout << "\n\t\t° Enter >-[1]-> Search by Name\n";
	cout << "\n\t\t° Enter >-[2]-> Search by Id\n";
	cout << "\n\t\t° Enter >-[3]-> Search by Category\n";

	cout << "\n\nYour Choise is: ";
	int searchOption = 0; cin >> searchOption;

	if (searchOption == 1)
		searchName();

	else if (searchOption == 2)
		searchId();

	else if (searchOption == 3)
		searchCategory();

	else {
		cout << "\n\n\tInvalid Option\n\n";
	}
}

////////////////////////////////////////////////////////////////////////////////

bool Back_Option_fn(int back_option) {
	cout << "\n\n\n*********\n";
	cout << "\n\t° --> To Return Main-Menu,, Enter [0] --> ";
	cin >> back_option;

	if (Back_Option_fn == 0)
		return true;     //Back Successed,, Returning to Menu

	while (back_option != 0) {
		cout << "\n\t\tInvalid ";
		cout << "\n\t° --> To Return Main-Menu,, Enter [0] --> ";
		cin >> back_option;

		if (Back_Option_fn == 0)
			return true;
	}
	system("cls");
}

////////////////////////////////////////////////////////////////////////////////
int main() {
	/////--> Initializing <--/////
	int choiseMenu = 0;
	int choiseSub = 0;
	int back_option = 1;

	do {
		system("cls");

		back_option = 1;     //To Enter the (Do --> While) LOOP

		cout << "\n\t\t   @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
		cout << "\n\t\t @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
		cout << "\n\t\t@@@@ -------> WELCOME to: <------- @@@@";
		cout << "\n\t\t@@@@-> Online => Marketplace Sys <-@@@@";
		cout << "\n\t\t @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
		cout << "\n\t\t   @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << "\n\n";

		////////////////////--> Options <--////////////////////
		cout << "\n\t° Enter >-[1]-> to:-> be a Seller\n";
		cout << "\n\t° Enter >-[2]-> to:-> be a Customer\n";
		cout << "\n\n\t° Enter >-[0]-> to:-> Exit\n\n";

		cout << "\n\n\n*********\n";
		cout << "\n\t° -> Your Choise is:-> ";
		cin >> choiseMenu;

		while (choiseMenu != 0 && choiseMenu != 1 && choiseMenu != 2) {
			cout << "\t\tInvalid ";
			cout << "\n\t° -> Your Choise is:-> ";
			cin >> choiseMenu; cout << endl;
		}

		////////////////////////////////////////////////////////////////////////////////
		if (choiseMenu == 1) { //Option Seller
			system("cls");

			cout << "Hello Seller\n\n";

			////////////////////--> Options <--////////////////////
			cout << "\n\t° Enter >-[1]-> to:-> Add New Sellers\n";
			cout << "\n\t° Enter >-[2]-> to:-> Display Sellers\n";
			cout << "\n\t° Enter >-[3]-> to:-> Sellers Number\n";
			cout << "\n\t° Enter >-[4]-> to:-> Add new Products\n";
			cout << "\n\n\t° Enter >-[0]-> to:-> Return Main-Menu\n\n";

			cout << "\n\n\n*********\n";
			cout << "\n\t° -> Your Choise is:-> ";
			cin >> choiseSub;

			while (choiseSub != 0 && choiseSub != 1 && choiseSub != 2 && choiseSub != 3 && choiseSub != 4) {
				cout << "\t\tInvalid ";
				cout << "\n\t° -> Your Choise is:-> ";
				cin >> choiseSub; cout << endl;
			}

			{
				if (choiseSub == 1) { //Add Sellers
					system("cls");
					cout << "\tAdd new Sellers\n\n";
					addSellers();
				}

				if (choiseSub == 2) { //Display Sellers
					system("cls");
					cout << "\tDisplay Sellers\n\n";
					displaySellers();
				}

				if (choiseSub == 3) { //Sellers Number
					system("cls");
					cout << "\tSellers Number\n\n";
					sizeSellers();
				}

				if (choiseSub == 4) { //Add Products
					system("cls");
					cout << "\tAdd new Products\n\n";
					addProducts();
				}

				if (choiseSub == 0) {
					continue;
				}

				Back_Option_fn(back_option);     //Returns to Menu
			}
		}
		////////////////////////////////////////////////////////////////////////////////
		if (choiseMenu == 2) { //Option Customer
			system("cls");

			cout << "Hello Seller\n\n";

			////////////////////--> Options <--////////////////////
			cout << "\n\t° Enter >-[1]-> to:-> Add New Customers\n";
			cout << "\n\t° Enter >-[2]-> to:-> Display Customers\n";
			cout << "\n\t° Enter >-[3]-> to:-> Customers Number\n";
			cout << "\n\t° Enter >-[4]-> to:-> Buy Products\n";
			cout << "\n\t° Enter >-[5]-> to:-> Search Products\n";
			cout << "\n\n\t° Enter >-[0]-> to:-> Return Main-Menu\n\n";

			cout << "\n\n\n*********\n";
			cout << "\n\t° -> Your Choise is:-> ";
			cin >> choiseSub;

			while (choiseSub != 0 && choiseSub != 1 && choiseSub != 2 && choiseSub != 3 && choiseSub != 4 && choiseSub != 5) {
				cout << "\t\tInvalid ";
				cout << "\n\t° -> Your Choise is:-> ";
				cin >> choiseSub; cout << endl;
			}

			{
				if (choiseSub == 1) { //Add Customers
					system("cls");
					cout << "\tAdd new Customers\n\n";
					addCustomers();
				}

				if (choiseSub == 2) { //Display Customers
					system("cls");
					cout << "\tDisplay Customers\n\n";
					displayCustomers();
				}

				if (choiseSub == 3) { //Customers Number
					system("cls");
					cout << "\tCustomer Number\n\n";
					sizeCustomers();
				}

				if (choiseSub == 4) { //Buy Products
					system("cls");
					cout << "\tBuy Products\n\n";
					buyProducts();
				}

				if (choiseSub == 5) { //Search Products
					system("cls");
					cout << "\tSearch Products\n\n";
					searchProducts();
				}

				if (choiseSub == 0) {
					continue;
				}

				Back_Option_fn(back_option);     //Returns to Menu
			}
		}
		////////////////////////////////////////////////////////////////////////////////
		if (choiseMenu == 0)     //Option --> [EXIT]
			back_option = 0;     //To Scape the (Do --> While) LOOP
		////////////////////////////////////////////////////////////////////////////////
	} while (back_option != 0);     //LOOPs --> During Back_fn is true

	return 0;
}