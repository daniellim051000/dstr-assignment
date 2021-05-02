#include <iostream>
#include<string>
#include <regex>
#include <fstream>
using namespace std;

struct orderInfo {
	string orderID;
	string bookID;
	int quantity;
	int totalPrice;
	int transID;
};

void addOrder() {
	cout << "havent complete" << endl;
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

void showOrderMenu(int selected) {
	if (selected == 2) {
		cout << "Order Management" << endl;
		cout << "To perform an action, enter" << endl;
		cout << "1 Add Order" << endl;
		cout << "2 View Order" << endl;
		cout << "3 Edit Order" << endl;
		cout << "4 Cancel Order" << endl;
		cout << "6 View Cancel Order" << endl;
		cout << "5 Exit Order Management\n" << endl;

		int choice{};
		showOrderMenu(choice);
		cin >> choice;
		while (choice != 6) {
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
			cout << endl;
			inventoryMenu(choice);
			cin >> choice;
		}
	}
}