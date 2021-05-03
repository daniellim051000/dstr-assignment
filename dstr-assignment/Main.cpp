#include "Customer.h"
#include "Inventory.h"
#include "Transaction.h"
#include "Order.h";

int main() {
	int choice;
	
	do {
		cout << "*** Bookstore System ***" << endl;
		cout << "To perform an action, enter " << endl;
		cout << "1 Customer Management" << endl;
		cout << "2 Order Management" << endl;
		cout << "3 Inventory Management" << endl;
		cout << "4 Transaction Management" << endl;
		cout << "5 to exit\n" << endl;
		cin >> choice;
		switch (choice) {
		case 1:
			showSelectionCustomer();
			break;
		case 2:
			showOrderMenu();
			break;
		case 3:
			inventoryMenu();
			break;
		case 4:
			showSelectionTransaction();
			break;
		default:
			cout << "Invalid selection.\n" << endl;
		}
	} while (choice != 5);
}