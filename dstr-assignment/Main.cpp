#include "Customer.h"
#include "Inventory.h"
#include "Transaction.h"
#include "link-transaction.h"
#include <iostream>

using namespace std;

int main() {
	int choice;
	do {
		cout << "*** Bookstore System ***" << endl;
		cout << "To perform an action, enter " << endl;
		cout << "1 Customer Management" << endl;
		cout << "2 Inventory Management" << endl;
		cout << "3 Transaction Management" << endl;
		cout << "4 to exit\n" << endl;
		cin >> choice;
		switch (choice) {
		case 1:
			customerMenu();
			break;
		case 2:
			inventoryMenu();
			break;
		case 3:
			transactionMenu();
			break;
		default:
			cout << "Invalid selection.\n" << endl;
		}
	} while (choice != 4);
}