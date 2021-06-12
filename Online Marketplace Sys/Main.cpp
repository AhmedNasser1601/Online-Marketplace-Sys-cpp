#include <iostream>
#include <vector>
#include <string>
#include <thread>

#include "Admin.cpp"
#include "Seller.cpp"
#include "Product.cpp"
#include "Customer.cpp"

using namespace std;

static int vsCounter = 0, vpCounter = 0, vcCounter = 0;

Admin<int> A;
Seller<int> S;
Product<int> P;
Customer<int> C;

vector<Seller<int>> vls;
vector<Product<int>> vlp;
vector<Customer<int>> vlc;

vector<Product<int>> Cart;
vector<float> TotalCartCost;

/////////////////////////////=> Seller Functions <=/////////////////////////////
int loginSeller() {
	cout << "Enter Your Seller Id: ";
	int sId; cin >> sId;

	int flagAvailable = 0;

	for (int i = 0; i < vsCounter; i++) {
		if (vls[i].searchId(sId)) {
			cout << "\n\n||=> Hello Seller,\n\n\t Your Id is =(" << sId << ")=>, Please Continue,,\n\n\n";
			flagAvailable = 1;
			this_thread::sleep_for(3000ms);
			system("cls");

			return sId;
		}
	}

	if (flagAvailable != 1) {
		cout << "\n\tThis Id not Found among Sellers\n";
		this_thread::sleep_for(2000ms);
	}
	return -1;
}

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
	this_thread::sleep_for(1000ms);
}

void addProducts(int sId) {
	cout << "\tAdd new Products\n\n";

	cout << "Enter num of the new Products: ";
	int sizeP; cin >> sizeP;

	for (int i = 0; i < sizeP; i++) {
		cout << "\nEnter Product (" << i + 1 << ") Data :-\n";

		vlp.push_back(P.addProduct(sId));
		vpCounter++;
	}
}

void productsOFseller() {
	cout << "\n\nEnter Seller Id: ";
	int sId; cin >> sId;

	cout << "\n\n";

	for (int i = 0; i < vpCounter; i++) {
		if (vlp[i].checkSellerId(sId))
			vlp[i].display(false);
	}
}

/////////////////////////////=> Product Functions <=////////////////////////////
void displayProducts(bool controller) {
	if (controller)
		for (int i = 0; i < vpCounter; i++) {
			vlp[i].display(true); //Display all the Products that has status=>(ture)
		}
	else
		for (int i = 0; i < vpCounter; i++) {
			vlp[i].display(false); //Display all the Products that has status=>(false)
		}
}

void searchName() {
	cout << "\nEnter the Product Name to Search: ";
	string name; cin >> name; cout << endl;

	for (int i = 0; i < vpCounter; i++) {
		if (vlp[i].searchName(name))
			displayProducts(true);
	}

	this_thread::sleep_for(50ms);
}
void searchId() {
	cout << "\nEnter the Product Id to Search: ";
	int id; cin >> id; cout << endl;

	for (int i = 0; i < vpCounter; i++) {
		if (vlp[i].searchId(id))
			displayProducts(true);
	}

	this_thread::sleep_for(50ms);
}

void searchCategory() {
	cout << "\nEnter the Category Name to Search: ";
	string category; cin >> category; cout << endl;

	for (int i = 0; i < vpCounter; i++) {
		if (vlp[i].searchCategory(category))
			displayProducts(true);
	}

	this_thread::sleep_for(50ms);
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

/////////////////////////////=> Customer Functions <=////////////////////////////
int loginCustomer() {
	cout << "Enter Your Customer Id: ";
	int cId; cin >> cId;

	int flagAvailable = 0;

	for (int i = 0; i < vcCounter; i++) {
		if (vlc[i].searchId(cId)) {
			cout << "\n\n||=> Hello Customer,\n\n\t Your Id is =(" << cId << ")=>, Please Continue,,\n\n\n";
			flagAvailable = 1;
			this_thread::sleep_for(3000ms);
			system("cls");

			return cId;
		}
	}

	if (flagAvailable != 1) {
		cout << "\n\tThis Id not Found among Customers\n";
		this_thread::sleep_for(2000ms);
	}
	return -1;
}

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
	this_thread::sleep_for(1000ms);
}

void buyProducts(float totalPrice) {
	cout << "\tBuy Products\n\n";
	displayProducts(true);
	this_thread::sleep_for(1000ms);

	cout << "\n\n\tEnter Product Id you want to buy: ";
	int id; cin >> id;

	cout << "\tEnter Quantity: ";
	int quantity; cin >> quantity;

	int flagAvailable = 0;

	for (int i = 0; i < vpCounter; i++) {
		if (vlp[i].searchId(id)) {
			flagAvailable = 1;

			if (vlp[i].checkQuantity(quantity)) {
				vlp[i].updateQuantity(quantity);
				Cart.push_back(vlp[i]); //Add =(to)=> Carts Vector
				totalPrice += (vlp[i].getPrice() * quantity);
				cout << "\nAdded Successfully\n";
				break;
			}
			else {
				cout << "\nSorry, You can't add this Product, No available Quantity .!\n";
				this_thread::sleep_for(1000ms);
				break;
			}
		}
	}

	if (flagAvailable != 1) {
		cout << "\n\tThis Id not Found among Products\n";
		this_thread::sleep_for(2000ms);
	}

	{
		system("cls");
		cout << "\tBuy Products\n\n";
		displayProducts(true);
		this_thread::sleep_for(1000ms);

		cout << "\nContinue Shopping (Y/N)? : ";
		char again; cin >> again;

		if (again == 'y' || again == 'Y' || again == '1') {
			system("cls");
			buyProducts(totalPrice);
		}
		else {
			cout << "\n\n\tTotal Price is: " << totalPrice << endl;
			TotalCartCost.push_back(totalPrice); //Add =(to)=> Prices Vector
			this_thread::sleep_for(1000ms);
		}
	}
}

//////////////////////////////=> Admin Functions <=//////////////////////////////
void removeSeller() {
	cout << "\tRemove Seller\n\n";

	displaySellers();
	this_thread::sleep_for(1000ms);

	cout << "\n\nEnter Seller Id to Remove: ";
	int sId; cin >> sId;
	for (int i = 0; i < vsCounter; i++) {
		if (vls[i].searchId(sId)) {
			vls.erase(vls.begin() + i);
			break;
		}
	}
	vsCounter--;

	system("cls");
	cout << "\tRemove Seller\n\n";

	displaySellers();
	this_thread::sleep_for(500ms);

	if (sId != 0)
		cout << "\n\n\tTargeted Seller Deleted\n";
	else
		cout << "\n\n\tId not Found\n";

	this_thread::sleep_for(1000ms);
}

void removeCustomer() {
	cout << "\tRemove Customer\n\n";

	displayCustomers();
	this_thread::sleep_for(1000ms);

	cout << "\n\nEnter Customer Id to Remove: ";
	int cId; cin >> cId;

	for (int i = 0; i < vcCounter; i++) {
		if (vlc[i].searchId(cId)) {
			vlc.erase(vlc.begin() + i);
			break;
		}
	}
	vcCounter--;

	system("cls");
	cout << "\tRemove Customer\n\n";

	displayCustomers();
	this_thread::sleep_for(500ms);

	if (cId != 0)
		cout << "\n\n\tTargeted Customer Deleted\n";
	else
		cout << "\n\n\tId not Found\n";

	this_thread::sleep_for(1000ms);
}

void removeProduct() {
	cout << "\tRemove Product\n\n";

	displayProducts(false);
	this_thread::sleep_for(1000ms);

	cout << "\n\nEnter Product Id to Remove: ";
	int pId; cin >> pId;

	for (int i = 0; i < vpCounter; i++) {
		if (vlp[i].searchId(pId)) {
			vlp.erase(vlp.begin() + i);
			break;
		}
	}
	vpCounter--;

	system("cls");
	cout << "\tRemove Product\n\n";

	displayProducts(false);
	this_thread::sleep_for(500ms);

	if (pId != 0)
		cout << "\n\n\tTargeted Product Deleted\n";
	else
		cout << "\n\n\tId not Found\n";

	this_thread::sleep_for(1000ms);
}

void authProduct() {
	cout << "\tAuthorize Product\n\n";

	displayProducts(false);
	this_thread::sleep_for(1000ms);

	cout << "\n\n\tEnter Product Id to Change State: ";
	int pId; cin >> pId;

	cout << "\n\t\t(Accept/Reject)?: ";
	string status; cin >> status;

	int flagAvailable = 0;

	for (int i = 0; i < vpCounter; i++) {
		if (vlp[i].searchId(pId)) {
			flagAvailable = 1;

			vlp[i].changeState(status);
			this_thread::sleep_for(1000ms);
		}
	}

	if (flagAvailable != 1) {
		cout << "\n\tThis Id not Found among Products\n";
		this_thread::sleep_for(2000ms);
	}

	{
		system("cls");
		cout << "\tAuthorize Product\n\n";

		displayProducts(false);
		this_thread::sleep_for(1000ms);

		cout << "\nAnother Operation (Y/N)? : ";
		char again; cin >> again;

		if (again == 'y' || again == 'Y' || again == '1') {
			system("cls");
			authProduct();
		}
	}
}

////////////////////////////////////////////////////////////////////////////////

bool Back_Option_fn(int back_option) {
	cout << "\n\n\n*********\n";
	this_thread::sleep_for(50ms);
	cout << "\n\t° --> To Return Main-Menu,, Enter [0] --> ";
	cin >> back_option;

	if (Back_Option_fn == 0)
		return true;     //Back Successed,, Returning to Menu

	while (back_option != 0) {
		cout << "\n\t\tInvalid ";
		this_thread::sleep_for(500ms);
		cout << "\n\t° --> To Return Main-Menu,, Enter [0] --> ";
		cin >> back_option;

		if (Back_Option_fn == 0)
			return true;
	}
	system("cls");
}

////////////////////////////////////////////////////////////////////////////////
int main() {
	//////--> Initializing <--//////
	int choiseMenu = 0;
	int choiseSub = 0;
	int back_option = 1;

	/////--> Pre Registered <--/////
	vls.push_back(Seller<int>(10, "s1", "e1@s1")); //Seller(1)
	vls.push_back(Seller<int>(11, "s2", "e2@s2")); //Seller(2)
	vls.push_back(Seller<int>(12, "s3", "e3@s3")); //Seller(3)
	vsCounter += 3;

	vlc.push_back(Customer<int>("c1", 13, "add1", 010, "e1@c1")); //Customer(1)
	vlc.push_back(Customer<int>("c2", 14, "add2", 011, "e2@c2")); //Customer(2)
	vlc.push_back(Customer<int>("c3", 15, "add3", 012, "e3@c3")); //Customer(3)
	vcCounter += 3;

	vlp.push_back(Product<int>(16, "p1", 50, "Cat1", 10, 11, true)); //Product(1)
	vlp.push_back(Product<int>(17, "p1", 100, "Cat2", 11, 9, false)); //Product(2) => Rejected by default
	vlp.push_back(Product<int>(18, "p2", 150, "Cat3", 12, 7, true)); //Product(3)
	vlp.push_back(Product<int>(19, "p3", 200, "Cat4", 10, 5, false)); //Product(4) => Rejected by default
	vlp.push_back(Product<int>(20, "p4", 250, "Cat5", 11, 3, true)); //Product(5)
	vlp.push_back(Product<int>(21, "p5", 300, "Cat6", 12, 1, false)); //Product(6) => Rejected by default
	vpCounter += 6;

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
		cout << "\n\t° Enter >-[1]-> to:-> be Seller\n";
		cout << "\n\t° Enter >-[2]-> to:-> be Customer\n";
		cout << "\n\t° Enter >-[3]-> to:-> Administration\n";
		cout << "\n\n\t° Enter >-[0]-> to:-> Exit\n\n";

		cout << "\n\n\n*********\n";
		this_thread::sleep_for(500ms);
		cout << "\n\t° -> Your Choise is:-> ";
		cin >> choiseMenu;

		while (choiseMenu != 0 && choiseMenu != 1 && choiseMenu != 2 && choiseMenu != 3) {
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
			cout << "\n\t° Enter >-[5]-> to:-> Seller's Products\n";
			cout << "\n\n\t° Enter >-[0]-> to:-> Return Main-Menu\n\n";

			cout << "\n\n\n*********\n";
			this_thread::sleep_for(500ms);
			cout << "\n\t° -> Your Choise is:-> ";
			cin >> choiseSub;

			while (choiseSub != 0 && choiseSub != 1 && choiseSub != 2 && choiseSub != 3 && choiseSub != 4 && choiseSub != 5) {
				cout << "\t\tInvalid ";
				this_thread::sleep_for(500ms);
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
					this_thread::sleep_for(1000ms);
				}

				if (choiseSub == 3) { //Sellers Number
					system("cls");
					cout << "\tSellers Number\n\n";
					sizeSellers();
				}

				if (choiseSub == 4) { //Add Products
					system("cls");
					int loginAcceptor = loginSeller();

					if (loginAcceptor != -1)
						addProducts(loginAcceptor);
				}

				if (choiseSub == 5) { //Seller's Products
					system("cls");
					cout << "\tSeller's Products\n\n";
					productsOFseller();
					this_thread::sleep_for(1000ms);
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

			cout << "Hello Customer\n\n";

			////////////////////--> Options <--////////////////////
			cout << "\n\t° Enter >-[1]-> to:-> Add New Customers\n";
			cout << "\n\t° Enter >-[2]-> to:-> Display Customers\n";
			cout << "\n\t° Enter >-[3]-> to:-> Customers Number\n";
			cout << "\n\t° Enter >-[4]-> to:-> Buy Products\n";
			cout << "\n\t° Enter >-[5]-> to:-> Search Products\n";
			cout << "\n\n\t° Enter >-[0]-> to:-> Return Main-Menu\n\n";

			cout << "\n\n\n*********\n";
			this_thread::sleep_for(500ms);
			cout << "\n\t° -> Your Choise is:-> ";
			cin >> choiseSub;

			while (choiseSub != 0 && choiseSub != 1 && choiseSub != 2 && choiseSub != 3 && choiseSub != 4 && choiseSub != 5) {
				cout << "\t\tInvalid ";
				this_thread::sleep_for(500ms);
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
					this_thread::sleep_for(1000ms);
				}

				if (choiseSub == 3) { //Customers Number
					system("cls");
					cout << "\tCustomers Number\n\n";
					sizeCustomers();
				}

				if (choiseSub == 4) { //Buy Products
					system("cls");
					int loginAcceptor = loginCustomer();

					if (loginAcceptor != -1) {
						system("cls");
						float totalPrice = 0;
						buyProducts(totalPrice);
					}
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
		if (choiseMenu == 3) { //Option Admin
			system("cls");

			if (A.login()) {
				system("cls");

				cout << "Hello Admin\n\n";

				////////////////////--> Options <--////////////////////
				cout << "\n\t° Enter >-[1]-> to:-> Remove Seller\n";
				cout << "\n\t° Enter >-[2]-> to:-> Remove Customer\n";
				cout << "\n\t° Enter >-[3]-> to:-> Remove Product\n";
				cout << "\n\t° Enter >-[4]-> to:-> Authorize Product\n";
				cout << "\n\n\t° Enter >-[0]-> to:-> Return Main-Menu\n\n";

				cout << "\n\n\n*********\n";
				this_thread::sleep_for(500ms);
				cout << "\n\t° -> Your Choise is:-> ";
				cin >> choiseSub;

				while (choiseSub != 0 && choiseSub != 1 && choiseSub != 2 && choiseSub != 3 && choiseSub != 4) {
					cout << "\t\tInvalid ";
					this_thread::sleep_for(500ms);
					cout << "\n\t° -> Your Choise is:-> ";
					cin >> choiseSub; cout << endl;
				}

				{
					if (choiseSub == 1) { //Remove Seller
						system("cls");
						removeSeller();
					}

					if (choiseSub == 2) { //Remove Customer
						system("cls");
						removeCustomer();
					}

					if (choiseSub == 3) { //Remove Product
						system("cls");
						removeProduct();
					}

					if (choiseSub == 4) { //Authorize Product
						system("cls");
						authProduct();
					}

					if (choiseSub == 0) {
						continue;
					}

					Back_Option_fn(back_option);     //Returns to Menu
				}
			}
			else {
				Back_Option_fn(back_option);     //Returns to Menu
			}
		}
		////////////////////////////////////////////////////////////////////////////////
		if (choiseMenu == 0)     //Option --> [EXIT]
			back_option = 0;     //To Scape the (Do --> While) LOOP
		////////////////////////////////////////////////////////////////////////////////
	} while (back_option != 0);     //LOOPs --> During Back_fn is true

	system("cls");
	cout << "\n\n\n\n\n\t\t\t Thanks\n\n\n\t\t\tGood Buy\n\n\n\n\n\n";
	this_thread::sleep_for(2500ms);

	return 0;
}