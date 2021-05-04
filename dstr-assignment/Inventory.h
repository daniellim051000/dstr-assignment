#pragma once
#include <iostream>
#include<string>
#include <regex>
#include <fstream>
using namespace std;

//stucture the information of inventory
struct InventoryInfo {
	string BookID;
	string BookName;
	string BookType;
	int UnitPrice;
	int Quantity;
	InventoryInfo* next;
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
	string searchID;
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
					while (current->Quantity < 0) {
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

//view intenvory list
void viewInventory() {
	//cout << "view inventory havent comeplete" << endl;
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
	string searchID;
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

//sort inventory
void sortInventory() {
	cout << "sort inventory havent comeplete" << endl;
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