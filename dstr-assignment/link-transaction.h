#include <iostream>
#include<string>
#include <regex>
#include <fstream>
using namespace std;

struct orderInfo {
	int transactionID;
	time_t currentTime = time(0);
	char* dateTime = ctime(&currentTime);
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

void addOrder() {
	struct orderInfo* current = new struct orderInfo;


	InventoryInfo* as = new InventoryInfo;


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



	//cout << "Enter Transaction ID >>";
	//cin >> current->transactionID
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
		cout << "Order Management" << endl;
		cout << "To perform an action, enter" << endl;
		cout << "1 Add Order" << endl;
		cout << "2 View Order" << endl;
		cout << "3 Edit Order" << endl;
		cout << "4 Cancel Order" << endl;
		cout << "5 View Cancel Order" << endl;
		cout << "6 Exit Order Management\n" << endl;
		cin >> choice;

		switch (choice) {
		case 1:
			addOrder();
			break;
		case 2:
			viewOrder();
			break;
		case 3:
			editOrder();
			break;
		case 4:
			cancelOrder();
			break;
		case 5:
			viewCancelOrder();
			break;
		default:
			cout << "Invalid selection. Please pick again.\n" << endl;
		}
	} while (choice != 6);
	system("CLS");
}