#include "Customer.h"
#include "Inventory.h"

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