#include "Customer.h"
#include "Inventory.h"
#include "new-transaction.h"
#include <iostream>

using namespace std;

int main() {
	int choice;
	do {
		cout << "*** Bookstore System ***" << endl;
		cout << "To perform an action, enter " << endl;
		cout << "1 Inventory Management" << endl;
		cout << "2 Transaction Management" << endl;
		cout << "3 to exit\n" << endl;
		cin >> choice;
		switch (choice) {
		case 1:
			inventoryMenu();
			break;
		case 2:
			showNewTransMenu();
			break;
		default:
			cout << "Invalid selection.\n" << endl;
		}
	} while (choice != 3);
}