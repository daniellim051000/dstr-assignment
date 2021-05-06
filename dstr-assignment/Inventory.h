#pragma once
#include <iostream>
#include<string>
#include <regex>
#include <fstream>
using namespace std;

//stucture the information of inventory
struct InventoryInfo {
	int BookID;
	string BookName;
	string BookType;
	double UnitPrice;
	int Quantity;
	InventoryInfo* next;
	void push(InventoryInfo** head_ref, int id, string name, string category, int price, int qty);
};
struct InventoryInfo* headInventory = NULL;
void inventoryMenu();


//add inventory function
void addInventory() {
	struct InventoryInfo* add_inventory = new struct InventoryInfo;

	cout << "Enter Book ID >>";
	cin >> add_inventory->BookID;

	//create temp pointer
	struct InventoryInfo* checkBookID;
	checkBookID = headInventory;
	//transverse
	//check existing book id
	while (checkBookID != NULL) {
		if (add_inventory->BookID == checkBookID->BookID) {
			cout << "There is a duplicated Book ID." << endl;
			cout << "Please enter a new Book ID >>" << endl;
			cin >> add_inventory->BookID;
			checkBookID = NULL;
		}
		else {
			checkBookID = checkBookID->next;
		}
	}

	//book name
	cout << "Please enter the Book Name >>";
	cin >> add_inventory->BookName;
	//getline(cin, add_inventory->BookName);
	
	//book type
	cout << "Please Enter the book type >>";
	//getline(cin, add_inventory->BookType);
	cin >> add_inventory->BookType;

	//unit price for the book
	cout << "Please enter the unit price for the book >>";
	cin >> add_inventory->UnitPrice;
	while (add_inventory->UnitPrice <0)	{
		cout << "The Unit Price must at least 1" << endl;
		cout << "Please Enter a new unit price for the book >>";
		cin >> add_inventory->UnitPrice;
	}

	//quantity 
	cout << "Please enter the quantity for the book >>";
	cin >> add_inventory->Quantity;
	while (add_inventory->Quantity < 0) {
		cout << "Minimum quantity must at least 1" << endl;
		cout << "Please enter a renter quanity >>";
		cin >> add_inventory->Quantity;
	}
	add_inventory->next = headInventory;
	headInventory = add_inventory;
}

//Edit Invetory
void editInventory() {
	int searchID;
	cout << "Enter Book ID to Search >>";
	cin >> searchID;
	struct InventoryInfo* current;
	current = headInventory;
	while (current != NULL) {
		if (current->BookID == searchID) {
			int selection;
			cout << "Book ID Book Name Book Type Unit Price Quantity" << endl;
			cout << current->BookID << "  " << current->BookName << "  " << current->BookType << "  " << current->UnitPrice << "  " << current->Quantity << "  " << endl;
			cout << "-----------------------------------" << endl;
			cout << "Edit Inventory" << endl;
			cout << "1 Edit Book Name" << endl;
			cout << "2 Edit Book Type" << endl;
			cout << "3 Edit Unit Price" << endl;
			cout << "4 Edit Quantity" << endl;
			cout << "5 Exit Edit Inventory\n" << endl;
			cout << "-----------------------------------" << endl;		
			cin >> selection;
			switch (selection) {
				case 1:
					cout << "Enter the new Book Name >>";
					cin >> current->BookName;
					break;
				case 2:
					cout << "Enter the new book type >>";
					cin >> current->BookType;
					break;
				case 3:
					cout << "Enter the new Unit Price >>";
					cin >> current->UnitPrice;
					while (current->UnitPrice < 0) {
						cout << "Unit Price must be at least 1" << endl;
						cout << "please enter an new unit price >>";
						cin >> current->UnitPrice;
					}
					break;
				case 4:
					cout << "Enter the new quantity >>";
					cin >> current->Quantity;
					while (current->Quantity < 0) {
						cout << "quantity must be at least 1" << endl;
						cout << "please enter an new quantity >>";
						cin >> current->Quantity;
					}
					break;
				case 5:
					return;
					system("CLS");
				default:
					cout << "Invalid selection.\n" << endl;
			}
		}
		else {
			cout << "No Book is found" << endl;
			current = current->next;
		}
	}
}

void deleteInventory() {
	cout << "delete inventory havent comeplete" << endl;
	/*int deleteID;
	cout << "Enter Customer ID to delete record: " << endl;
	cin >> deleteID;
	//transverse
	struct InventoryInfo* current = headInventory;

	if (current == NULL) {
		cout << "No customer record";
	}

	bool found = false;

	while (current != NULL) {
		if (head->custId == deleteID) {
			cout << "Delete all elements of the record [Y/N]: " << endl;
			char choice;
			cin >> choice;

			if (choice == 'Y' || choice == 'y') {
				customerInfo* first = head;
				first = first->next;
				delete head;
				//free(head)
				head = first;
			}
			found = true;
			cout << "Customer record deleted " << endl;
			break;

		}
		else if (current->next->custId == deleteID) {
			cout << "Customer ID \tName \tPhone Number \tEmail\n";
			cout << "" << current->custId <<
				"\t \t" << current->name <<
				"\t \t \t" << current->phoneNo <<
				"\t \t" << current->email << "\n";

			cout << "Going to delete all elements of the record [Y/N]: " << endl;
			char choice;
			cin >> choice;

			if (choice == 'Y' || choice == 'y') {
				customerInfo* prev = current;
				customerInfo* toDelete = current;
				prev->next = toDelete->next;
				delete toDelete;
				//free(head)
			}

			found = true;
			cout << "Customer record deleted " << endl;
			break; // keep infinite loop

		}
		else {
			current = current->next;
		}
	}

	if (found == false) {
		cout << "Customer not found! " << endl;
	}*/
}

//view intenvory list
void viewInventory() {
	system("CLS");
	struct InventoryInfo* view;
	view = headInventory;
	cout << "Book ID Book Name Book Type Unit Price Quantity" << endl;
	if (view == NULL) {
		cout << "No book in inventory" << endl;
	}
	while (view != NULL) {
		cout << view->BookID << "  " << view->BookName << "  " << view->BookType << "  " << view->UnitPrice << "  " << view->Quantity << "  "  << endl;
		view = view->next;
	}
}

//search inventory
void searchInventory() {
	int searchID;
	cout << "Enter Book ID to perform search >>";
	cin >> searchID;
	struct InventoryInfo* current;
	current = headInventory;
	while (current != NULL) {
		if (current->BookID == searchID) {
			cout << "Book ID Book Name Book Type Unit Price Quantity" << endl;
			cout << current->BookID << "  " << current->BookName << "  " << current->BookType << "  " << current->UnitPrice << "  " << current->Quantity << "  " << endl;
			return;
		}
		else {
			current = current->next;
		}
	}
}

//sort bookid, unit price, quantity
void sortBookId_ascending() {
	struct InventoryInfo* sort;
	sort = headInventory;
	int tempBookId;
	string tempBookName;
	string tempBookType;
	double tempUnitPrice;
	int tempQuantity;
	int counter = 0;

	if (sort == NULL) {
		cout << "No transaction record" << endl;
	}
	else {
		//get the total data for counter to loop
		while (sort) {
			sort = sort->next;
			counter++;
		}
		sort = headInventory;

		for (int i = 0; i < counter; i++) { // 1st loop
			while (sort != NULL && sort->next != NULL) { // 2nd loop to compare between two loops data
				if (sort->BookID > sort->next->BookID) {
					tempBookId = sort->BookID;
					sort->BookID = sort->next->BookID;
					sort->next->BookID = tempBookId;

					tempBookName = sort->BookName;
					sort->BookName = sort->next->BookName;
					sort->next->BookName = tempBookName;

					tempBookType = sort->BookType;
					sort->BookType = sort->next->BookType;
					sort->next->BookType = tempBookType;

					tempUnitPrice = sort->UnitPrice;
					sort->UnitPrice = sort->next->UnitPrice;
					sort->next->UnitPrice = tempUnitPrice;

					tempQuantity = sort->Quantity;
					sort->Quantity = sort->next->Quantity;
					sort->next->Quantity = tempQuantity;
				}
				sort = sort->next;
			}
			sort = headInventory;
		}
		cout << "Sorted Book ID in Ascending" << endl;
		cout << "Book ID \tBook Name \tBook Type \tUnit Price \tQuantity\t" << endl;
		while (sort != NULL) {
			cout << sort->BookID << " \t\t " << sort->BookName << " \t\t " << sort->BookType << " \t\t " << sort->UnitPrice << " \t\t " << sort->Quantity << " \t" << endl;
			sort = sort->next;
		}
	}
}

void sortBookId_descending() {
	struct InventoryInfo* sort;
	sort = headInventory;
	int tempBookId;
	string tempBookName;
	string tempBookType;
	double tempUnitPrice;
	int tempQuantity;
	int counter = 0;

	if (sort == NULL) {
		cout << "No transaction record" << endl;
	}
	else {
		//get the total data for counter to loop
		while (sort) {
			sort = sort->next;
			counter++;
		}
		sort = headInventory;

		for (int i = 0; i < counter; i++) { // 1st loop
			while (sort != NULL && sort->next != NULL) { // 2nd loop to compare between two loops data
				if (sort->BookID < sort->next->BookID) {
					tempBookId = sort->BookID;
					sort->BookID = sort->next->BookID;
					sort->next->BookID = tempBookId;

					tempBookName = sort->BookName;
					sort->BookName = sort->next->BookName;
					sort->next->BookName = tempBookName;

					tempBookType = sort->BookType;
					sort->BookType = sort->next->BookType;
					sort->next->BookType = tempBookType;

					tempUnitPrice = sort->UnitPrice;
					sort->UnitPrice = sort->next->UnitPrice;
					sort->next->UnitPrice = tempUnitPrice;

					tempQuantity = sort->Quantity;
					sort->Quantity = sort->next->Quantity;
					sort->next->Quantity = tempQuantity;
				}
				sort = sort->next;
			}
			sort = headInventory;
		}
		cout << "Sorted Book ID in Descending" << endl;
		cout << "Book ID \tBook Name \tBook Type \tUnit Price \tQuantity\t" << endl;
		while (sort != NULL) {
			cout << sort->BookID << " \t\t " << sort->BookName << " \t\t " << sort->BookType << " \t\t " << sort->UnitPrice << " \t\t " << sort->Quantity << " \t" << endl;
			sort = sort->next;
		}
	}
}

void sortBookPrice_ascending() {
	struct InventoryInfo* sort;
	sort = headInventory;
	int tempBookId;
	string tempBookName;
	string tempBookType;
	double tempUnitPrice;
	int tempQuantity;
	int counter = 0;

	if (sort == NULL) {
		cout << "No transaction record" << endl;
	}
	else {
		//get the total data for counter to loop
		while (sort) {
			sort = sort->next;
			counter++;
		}
		sort = headInventory;

		for (int i = 0; i < counter; i++) { // 1st loop
			while (sort != NULL && sort->next != NULL) { // 2nd loop to compare between two loops data
				if (sort->UnitPrice > sort->next->UnitPrice) {
					tempBookId = sort->BookID;
					sort->BookID = sort->next->BookID;
					sort->next->BookID = tempBookId;

					tempBookName = sort->BookName;
					sort->BookName = sort->next->BookName;
					sort->next->BookName = tempBookName;

					tempBookType = sort->BookType;
					sort->BookType = sort->next->BookType;
					sort->next->BookType = tempBookType;

					tempUnitPrice = sort->UnitPrice;
					sort->UnitPrice = sort->next->UnitPrice;
					sort->next->UnitPrice = tempUnitPrice;

					tempQuantity = sort->Quantity;
					sort->Quantity = sort->next->Quantity;
					sort->next->Quantity = tempQuantity;
				}
				sort = sort->next;
			}
			sort = headInventory;
		}
		cout << "Sorted Unit Price in Ascending" << endl;
		cout << "Book ID \tBook Name \tBook Type \tUnit Price \tQuantity\t" << endl;
		while (sort != NULL) {
			cout << sort->BookID << " \t\t " << sort->BookName << " \t\t " << sort->BookType << " \t\t " << sort->UnitPrice << " \t\t " << sort->Quantity << " \t" << endl;
			sort = sort->next;
		}
	}
}

void sortBookPrice_descending() {
	struct InventoryInfo* sort;
	sort = headInventory;
	int tempBookId;
	string tempBookName;
	string tempBookType;
	double tempUnitPrice;
	int tempQuantity;
	int counter = 0;

	if (sort == NULL) {
		cout << "No transaction record" << endl;
	}
	else {
		//get the total data for counter to loop
		while (sort) {
			sort = sort->next;
			counter++;
		}
		sort = headInventory;

		for (int i = 0; i < counter; i++) { // 1st loop
			while (sort != NULL && sort->next != NULL) { // 2nd loop to compare between two loops data
				if (sort->UnitPrice < sort->next->UnitPrice) {
					tempBookId = sort->BookID;
					sort->BookID = sort->next->BookID;
					sort->next->BookID = tempBookId;

					tempBookName = sort->BookName;
					sort->BookName = sort->next->BookName;
					sort->next->BookName = tempBookName;

					tempBookType = sort->BookType;
					sort->BookType = sort->next->BookType;
					sort->next->BookType = tempBookType;

					tempUnitPrice = sort->UnitPrice;
					sort->UnitPrice = sort->next->UnitPrice;
					sort->next->UnitPrice = tempUnitPrice;

					tempQuantity = sort->Quantity;
					sort->Quantity = sort->next->Quantity;
					sort->next->Quantity = tempQuantity;
				}
				sort = sort->next;
			}
			sort = headInventory;
		}
		cout << "Sorted Unit Price in Descending" << endl;
		cout << "Book ID \tBook Name \tBook Type \tUnit Price \tQuantity\t" << endl;
		while (sort != NULL) {
			cout << sort->BookID << " \t\t " << sort->BookName << " \t\t " << sort->BookType << " \t\t " << sort->UnitPrice << " \t\t " << sort->Quantity << " \t" << endl;
			sort = sort->next;
		}
	}
}

void sortQuantity_ascending() {
	struct InventoryInfo* sort;
	sort = headInventory;
	int tempBookId;
	string tempBookName;
	string tempBookType;
	double tempUnitPrice;
	int tempQuantity;
	int counter = 0;

	if (sort == NULL) {
		cout << "No transaction record" << endl;
	}
	else {
		//get the total data for counter to loop
		while (sort) {
			sort = sort->next;
			counter++;
		}
		sort = headInventory;
		
		for (int i = 0; i < counter; i++) { // 1st loop
			while (sort != NULL && sort->next != NULL) { // 2nd loop to compare between two loops data
				if (sort->Quantity > sort->next->Quantity) {
					tempBookId = sort->BookID;
					sort->BookID = sort->next->BookID;
					sort->next->BookID = tempBookId;

					tempBookName = sort->BookName;
					sort->BookName = sort->next->BookName;
					sort->next->BookName = tempBookName;

					tempBookType = sort->BookType;
					sort->BookType = sort->next->BookType;
					sort->next->BookType = tempBookType;

					tempUnitPrice = sort->UnitPrice;
					sort->UnitPrice = sort->next->UnitPrice;
					sort->next->UnitPrice = tempUnitPrice;

					tempQuantity = sort->Quantity;
					sort->Quantity = sort->next->Quantity;
					sort->next->Quantity = tempQuantity;
				}
				sort = sort->next;
			}
			sort = headInventory;
		}
		cout << "Sorted Book Quantity in Ascending" << endl;
		cout << "Book ID \tBook Name \tBook Type \tUnit Price \tQuantity\t" << endl;
		while (sort != NULL) {
			cout << sort->BookID << " \t\t " << sort->BookName << " \t\t " << sort->BookType << " \t\t " << sort->UnitPrice << " \t\t " << sort->Quantity << " \t" << endl;
			sort = sort->next;
		}
	}
}

void sortQuantity_descending() {
	struct InventoryInfo* sort;
	sort = headInventory;
	int tempBookId;
	string tempBookName;
	string tempBookType;
	double tempUnitPrice;
	int tempQuantity;
	int counter = 0;

	if (sort == NULL) {
		cout << "No transaction record" << endl;
	}
	else {
		//get the total data for counter to loop
		while (sort) {
			sort = sort->next;
			counter++;
		}
		sort = headInventory;

		for (int i = 0; i < counter; i++) { // 1st loop
			while (sort != NULL && sort->next != NULL) { // 2nd loop to compare between two loops data
				if (sort->Quantity < sort->next->Quantity) {
					tempBookId = sort->BookID;
					sort->BookID = sort->next->BookID;
					sort->next->BookID = tempBookId;

					tempBookName = sort->BookName;
					sort->BookName = sort->next->BookName;
					sort->next->BookName = tempBookName;

					tempBookType = sort->BookType;
					sort->BookType = sort->next->BookType;
					sort->next->BookType = tempBookType;

					tempUnitPrice = sort->UnitPrice;
					sort->UnitPrice = sort->next->UnitPrice;
					sort->next->UnitPrice = tempUnitPrice;

					tempQuantity = sort->Quantity;
					sort->Quantity = sort->next->Quantity;
					sort->next->Quantity = tempQuantity;
				}
				sort = sort->next;
			}
			sort = headInventory;
		}
		cout << "Sorted Book Quantity in Descending" << endl;
		cout << "Book ID \tBook Name \tBook Type \tUnit Price \tQuantity\t" << endl;
		while (sort != NULL) {
			cout << sort->BookID << " \t\t " << sort->BookName << " \t\t " << sort->BookType << " \t\t " << sort->UnitPrice << " \t\t " << sort->Quantity << " \t" << endl;
			sort = sort->next;
		}
	}
}

void sortInventory() {
	struct InventoryInfo* sort;
	sort = headInventory;
	if (sort == NULL) {
		cout << "No transaction record" << endl;
	}
	else {
		int choice;
		system("CLS");
		do {
			// sort inventory menu information
			cout << "Sort Invertory" << endl;
			cout << "To perform an action, enter" << endl;
			cout << "1 Sort Book ID in Ascending Order" << endl;
			cout << "2 Sort Book ID in Descending Order" << endl;
			cout << "3 Sort Book Price in Ascending Order" << endl;
			cout << "4 Sort Book Price in Descending Order" << endl;
			cout << "5 Sort Quantity in Ascending Order" << endl;
			cout << "6 Sort Quantity in Descending Order" << endl;
			cout << "7 Exit Sort Inventory \n" << endl;
			cout << "-----------------------------------" << endl;
			cin >> choice;

			switch (choice) {
			case 1:
				sortBookId_ascending();
				break;
			case 2:
				sortBookId_descending();
				break;
			case 3:
				sortBookPrice_ascending();
				break;
			case 4:
				sortBookPrice_descending();
				break;
			case 5:
				sortQuantity_ascending();
				break;
			case 6:
				sortQuantity_descending();
				break;
			}
		} while (choice != 7);
		system("CLS");
	}
}

// push value
void InventoryInfo::push(InventoryInfo** head_ref, int id, string name, string category, int price, int qty) {
	bool duplicate = false;
	InventoryInfo* as1 = new InventoryInfo;
	// if id=0, then let system generates the book ID,else use the manual id provided by user
	as1->BookID = id;
	as1->BookName = name;
	as1->BookType = category;
	as1->UnitPrice = price;
	as1->Quantity = qty;
	as1->next = *head_ref;
	*head_ref = as1;
	//free(new_node);
}

//show inventory menu
void inventoryMenu() {
	int choice;
	system("CLS");
	do {
		//inventory menu information
		cout << "Inventory Management" << endl;
		cout << "To perform an action, enter" << endl;
		cout << "1 Add Inventory" << endl;
		cout << "2 Edit Inventory" << endl;
		cout << "3 View Inventory" << endl;
		cout << "4 Search Inventory" << endl;
		cout << "5 Sort Inventory" << endl;
		cout << "6 Exit Inventory Management\n" << endl;
		cout << "-----------------------------------" << endl;
		cin >> choice;

		switch (choice) {
		case 1:
			addInventory();
			system("CLS");
			break;
		case 2:
			editInventory();
			break;
		case 3:
			viewInventory();
			break;
		case 4:
			searchInventory();
			break;
		case 5:
			sortInventory();
			break;
		}
	} while (choice != 6);
	system("CLS");
}

