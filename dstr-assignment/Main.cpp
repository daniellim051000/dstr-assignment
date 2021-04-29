#include "Customer.h"
#include "Inventory.h"

void showSelection() {
	cout << "*** Bookstore System ***" << endl;
	cout << "To perform an action, enter " << endl;
	cout << "1 Customer Dashboard" << endl;
	/*cout << "2 Product Dashboard" << endl;
	cout << "3 Order Dasboard" << endl;*/
	cout << "4 Transaction Dashboard" << endl;
	cout << "3 to exit\n" << endl;
}

int main() {
	int choice;
	showSelection();
	cin >> choice;

	while (choice != 3)
	{
		switch (choice)
		{
		case 1:
			showSelectionCustomer(choice);
			break;
		/*case 2:
			showSelectionTransaction(choice);
			break;
		case 3:
			showSelectionProduct();
				break;
		case 4:
			showSelectionOrder();
			break;*/
		default:
			cout << "Invalid selection.\n" << endl;
		}
		cout << endl;
		showSelection();
		cin >> choice;
	}
}