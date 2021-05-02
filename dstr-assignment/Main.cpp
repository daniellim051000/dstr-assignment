#include "Customer.h"
#include "Inventory.h"
#include "Transaction.h"
#include "Order.h";

void showSelection() {
	cout << "*** Bookstore System ***" << endl;
	cout << "To perform an action, enter " << endl;
	cout << "1 Customer Management" << endl;
	cout << "2 Order Management" << endl;
	cout << "3 Inventory Management" << endl;
	cout << "4 Transaction Management" << endl;
	cout << "5 to exit\n" << endl;
}

int main() {
	int choice;
	showSelection();
	cin >> choice;

	while (choice != 5)	{
		switch (choice) {
		case 1:
			showSelectionCustomer(choice);
			break;
		case 2:
			showOrderMenu(choice);
			break;
		case 3:
			inventoryMenu();
			break;
		case 4:
			showSelectionTransaction(choice);
			break;
		default:
			cout << "Invalid selection.\n" << endl;
		}
		cout << endl;
		showSelection();
		cin >> choice;
	}
}