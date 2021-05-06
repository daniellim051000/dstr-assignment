#include <iostream>
#include<string>
#include <regex>
#include <fstream>
using namespace std;

struct orderInfo {
	int transactionID;
	//time_t currentTime = time(0);
	//char* dateTime = ctime(&currentTime);
	string paymentType;
	double totalPrice;
	InventoryInfo* productDetails=NULL;
	orderInfo* next;
	void setProduct(int id, string name, string category, int price, int qty);
};

void orderInfo::setProduct(int id, string name, string category, int price, int qty) {
	InventoryInfo* test = new InventoryInfo;
	test->push(&this->productDetails, id, name, category, price, qty);
}

struct orderInfo* headOrder = NULL;
int orderID = 1009;

void testAddTrans() {
	struct orderInfo* current = new struct orderInfo;
	current->transactionID = orderID;
	orderID++;
	current->setProduct(1, "test", "daniel", 12, 23);
	current->setProduct(2, "test2", "daniel2", 12, 23);
	current->setProduct(3, "test2", "daniel2", 12, 23);
	
	current->next = headOrder;
	headOrder = current;

	struct orderInfo* current1 = new struct orderInfo;
	current1->transactionID=orderID;
	orderID++;
	current1->setProduct(4, "test", "daniel", 12, 23);
	current1->setProduct(22, "test2", "daniel2", 12, 23);
	current1->setProduct(334, "test2", "daniel2", 12, 23);
	current1->next = headOrder;
	headOrder = current1; 

	//view
	InventoryInfo* view = new InventoryInfo;
	orderInfo* run = new orderInfo;
	run = headOrder;
	while (run != NULL) {
		cout << run->transactionID << endl;
		view = run->productDetails;
		cout << "Book ID Book Name Book Type Unit Price Quantity" << endl;
		while (view != NULL) {
			cout << view->BookID << "  " << view->BookName << "  " << view->BookType << "  " << view->UnitPrice << "  " << view->Quantity << "  " << endl;
			view = view->next;
		}
		run = run->next;
	}
}

void addTrans() {
	
	//display existing book information
	//to allow user to pick book
	cout << "Please add which book to perform transaction" << endl;
	struct InventoryInfo* view;
	view = headInventory;
	cout << "Book ID Book Name Book Type Unit Price Quantity" << endl;
	if (view == NULL) {
		cout << "No book in inventory" << endl;
	}
	while (view != NULL) {
		cout << view->BookID << "  " << view->BookName << "  " << view->BookType << "  " << view->UnitPrice << "  " << view->Quantity << "  " << endl;
		view = view->next;
	}

	cout << "Please enter the ID to add. To Exit, please type exit" << endl;
	int selectID;
	cin >> selectID;
	double currentTotalPrice = 0;
	struct orderInfo* current = new struct orderInfo;
	if (cin.good()) {
		cout << "cin is good" << endl;
		struct InventoryInfo* as = new InventoryInfo;
		as = headInventory;
		while (as != NULL) {
			cout << "item is found" << endl;
			if (as->BookID == selectID) {
				//input ID
				current->transactionID = orderID;
				orderID++;

				//input payment type
				cout << "Please Select the payment method" << endl;
				cout << "1. Cash" << endl;
				cout << "2. Credit and Debit Card" << endl;
				cout << "3. Online Banking" << endl;
				int selection;
				cin >> selection;
				switch (selection) {
				case 1:
					current->paymentType = "cash";
					break;
				case 2:
					current->paymentType = "Credit Card";
					break;
				case 3:
					current->paymentType = "Online Bankning";
					break;
				default:
					cout << "invalid input" << endl;
					break;
				}

				//product detail
				current->setProduct(as->BookID, as->BookName, as->BookType, as->UnitPrice, as->Quantity);


				//input total price
				
				currentTotalPrice = currentTotalPrice + as->UnitPrice;
				current->totalPrice = currentTotalPrice;

				current = current->next;
				headOrder = current;
			}
			as = as->next;
			
		}
	}
	else {
		cout << "please enter a numeric to select transaction id" << endl;
	}
}

void viewOrder() {
	cout << "havent complete" << endl;
}

void editOrder() {
	cout << "havent complete" << endl;
}

void cancelOrder() {
	cout << "havent complete" << endl;
}

void viewCancelOrder() {
	cout << "havent complete" << endl;
}

void showOrderMenu() {
	int choice;
	system("CLS");
	do {
		cout << "New Transactio Management" << endl;
		cout << "To perform an action, enter" << endl;
		cout << "1 Add Purchase" << endl;
		cout << "2 View Purchase" << endl;
		cout << "3 Sort Purchase" << endl;
		cout << "4 Add Order" << endl;
		cout << "5 Exit Order Management\n" << endl;
		cin >> choice;

		switch (choice) {
		case 1:
				addTrans();
				break;
		case 2:
			viewOrder();
			break;
		case 3:
			editOrder();
			break;
		case 4:
			testAddTrans();
			break;
		default:
			cout << "Invalid selection. Please pick again.\n" << endl;
		}
	} while (choice != 5);
	system("CLS");
}