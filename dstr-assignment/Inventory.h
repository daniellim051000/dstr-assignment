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
	void push(InventoryInfo** head_ref, int id, string name, string category, double price, int qty);
};
struct InventoryInfo* headInventory = NULL;
int bookID = 1;
void inventoryMenu();

//add inventory function
void addInventory() {
	struct InventoryInfo* add_inventory = new struct InventoryInfo;
	add_inventory->BookID = bookID;
	bookID++; // auto generated book id

	cout << "Enter Book ID >>";
	cout << add_inventory->BookID << endl;

	//create temp pointer
	struct InventoryInfo* checkBookID;
	checkBookID = headInventory;
	bookID++;	

	//book name
	cout << "Please enter the Book Name >>";
	cin >> add_inventory->BookName;
	//getline(cin, add_inventory->BookName);
	
	//book type
	cout << "Please enter the book type >>";
	//getline(cin, add_inventory->BookType);
	cin >> add_inventory->BookType;

	//unit price for the book
	cout << "Please enter the unit price for the book >>";
	cin >> add_inventory->UnitPrice;
	while (!cin.good() || add_inventory->UnitPrice < 0)	{ // validation for in and min price of  1
		cout << "Please enter the valid Unit Price with at least 1" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Please enter a new unit price for the book >>";
		cin >> add_inventory->UnitPrice;
	}

	//quantity 
	cout << "Please enter the quantity for the book >>";
	cin >> add_inventory->Quantity;
	while (!cin.good() || add_inventory->Quantity < 0) { // validation for int and min quantity of 1
		cout << "Please enter the valid quantity with at least 1" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Please enter a new quanity >>";
		cin >> add_inventory->Quantity;
	}

	add_inventory->next = headInventory;
	headInventory = add_inventory;
}

//Edit Invetory
void editInventory() {
	int searchID;
	cout << "Please enter Book ID to Search >>";
	cin >> searchID;
	while (!(cin.good())) { // validation for int
		cout << "Invalid Input! The input must be NUMERIC" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Please enter a new Book ID to search >> ";
		cin >> searchID;
	}

	struct InventoryInfo* current;
	current = headInventory;
	while (current != NULL) {
		if (current->BookID == searchID) {
			int selection;
			cout << "Book ID \tBook Name \t\tBook Type \t\tUnit Price \tQuantity\t" << endl;
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
						cout << "Please enter a new unit price >>";
						cin >> current->UnitPrice;
						if (!(cin.good())) { // validation for int
							cout << "Invalid Input! The input must be NUMERIC" << endl;
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
							cout << "Please enter a new unit price >> ";
							cin >> current->UnitPrice;
						}
					}
					break;
				case 4:
					cout << "Enter the new quantity >>";
					cin >> current->Quantity;
					while (current->Quantity < 0) {
						cout << "quantity must be at least 1" << endl;
						cout << "please enter a new quantity >>";
						cin >> current->Quantity;
						if (!(cin.good())) { // validation for int
							cout << "Invalid Input! The input must be NUMERIC" << endl;
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
							cout << "Please enter a new quantity >> ";
							cin >> current->Quantity;
						}
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
	int deleteID;
	cout << "Enter Book ID to delete record >> " << endl;
	cin >> deleteID;
	while (!(cin.good())) { // validation for int
		cout << "Invalid Input! The input must be NUMERIC" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Please enter the Book ID >> ";
		cin >> deleteID;
	}
	
	InventoryInfo* current = headInventory;
	InventoryInfo* previous = NULL;
	InventoryInfo* tempnext = NULL;

	while (current->BookID != deleteID && current != NULL) {
		previous = current;
		current = current->next;
		/*if (headInventory->Quantity != 0) {
			cout << "Book Quantity is not ZERO! Cannot be deleted " << endl;
			cout << "Please enter the Book ID>> ";
			cin >> deleteID;
		}*/
	}
	
	if (current == NULL) {
		cout << "No inventory record!" << endl;
	}
	else if (previous == NULL) { // delete at the beginning
		cout << "Book ID \tBook Name \t\tBook Type \t\tUnit Price \tQuantity\t" << endl;
		cout << current->BookID << " \t\t " << current->BookName << "\t\t" << current->BookType << "\t\t" << current->UnitPrice << "\t\t" << current->Quantity << " \t " << endl;
		cout << "Delete all elements of the record [Y/N]: " << endl;
		
		char choice;
		cin >> choice;

		if (choice == 'Y' || choice == 'y') {
			tempnext = current->next;
			headInventory = tempnext;
			delete current;
			cout << "Deleting..." << endl;
			cout << "Book record has been deleted " << endl;
		}
		else {
			cout << "Book record is not delete " << endl;
		}
	}
	else { // delete at the end
		cout << "Book ID \tBook Name \t\tBook Type \t\tUnit Price \tQuantity\t" << endl;
		cout << current->BookID << " \t\t " << current->BookName << "\t\t" << current->BookType << "\t\t" << current->UnitPrice << "\t\t" << current->Quantity << " \t " << endl;
		cout << "Delete all elements of the record [Y/N]2:" << endl;
		
		char choice;
		cin >> choice;

		if (choice == 'Y' || choice == 'y') {
			tempnext = current->next;
			previous->next = tempnext;
			delete current;
			cout << "Deleting..." << endl;
			cout << "Book record has been deleted " << endl;
		}
		else {
			cout << "Book record is not delete " << endl;
		}
	}
}

//view intenvory list
void viewInventory() {
	system("CLS");
	struct InventoryInfo* view;
	view = headInventory;
	cout << "Book ID \tBook Name \t\tBook Type \t\tUnit Price \tQuantity\t" << endl;
	if (view == NULL) {
		cout << "No book in inventory" << endl;
	}
	while (view != NULL) {
		cout << view->BookID << " \t\t " << view->BookName << " \t\t " << view->BookType << " \t\t " << view->UnitPrice << " \t\t " << view->Quantity << " \t "  << endl;
		view = view->next;
	}
}

//search inventory
void searchInventory() {
	int searchID;
	cout << "Enter Book ID to perform search >>";
	cin >> searchID;
	while (!(cin.good())) { // validation for int
		cout << "Invalid Input! The input must be NUMERIC" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Please enter a new Book ID to search >> ";
		cin >> searchID;
	}
	struct InventoryInfo* current;
	current = headInventory;
	while (current != NULL) {
		if (current->BookID == searchID) {
			cout << "Book ID \tBook Name \t\tBook Type \t\tUnit Price \tQuantity\t" << endl;
			cout << current->BookID << " \t\t " << current->BookName << " \t\t " << current->BookType << " \t\t " << current->UnitPrice << " \t\t " << current->Quantity << " \t " << endl;
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
		cout << "Book ID \tBook Name \t\tBook Type \t\tUnit Price \tQuantity\t" << endl;
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
		cout << "Book ID \tBook Name \t\tBook Type \t\tUnit Price \tQuantity\t" << endl;
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
		cout << "Book ID \tBook Name \t\tBook Type \t\tUnit Price \tQuantity\t" << endl;
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
		cout << "Book ID \tBook Name \t\tBook Type \t\tUnit Price \tQuantity\t" << endl;
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
		cout << "Book ID \tBook Name \t\tBook Type \t\tUnit Price \tQuantity\t" << endl;
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
		cout << "Book ID \tBook Name \t\tBook Type \t\tUnit Price \tQuantity\t" << endl;
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
			case 7: 
				return;
				break;
			default: 
				cout << "Invalid selection! Please select again " << endl;
			}
		} while (choice != 7);
		system("CLS");
	}
}

// push value
void InventoryInfo::push(InventoryInfo** head_ref, int id, string name, string category, double price, int qty) {
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
	//headInventory->push(&headInventory->productDetails, id, name, category, price, qty);
	do {
		//inventory menu information
		cout << "-----------------------------------" << endl;
		cout << "Inventory Management" << endl;
		cout << "To perform an action, enter" << endl;
		cout << "1 Add Inventory" << endl;
		cout << "2 Edit Inventory" << endl;
		cout << "3 Delete Inventory" << endl;
		cout << "4 View Inventory" << endl;
		cout << "5 Search Inventory" << endl;
		cout << "6 Sort Inventory" << endl;
		cout << "7 Exit Inventory Management\n" << endl;
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
			deleteInventory();
			break;
		case 4:
			viewInventory();
			break;
		case 5:
			searchInventory();
			break;
		case 6:
			sortInventory();
			break;
		case 7:
			return;
			break;
		default:
			cout << "Invalid selection! Please select again " << endl;
		}
	} while (choice != 6);
	system("CLS");
}

