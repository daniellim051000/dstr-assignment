#pragma once
#include <iostream>
#include<string>
#include <regex>
#include <fstream>
using namespace std;

//stucture the information of inventory
struct InventoryInfo {
	string BookID;
	string BookType;
	string BookName;
	int UnitPrice;
	int Quantity;
	InventoryInfo* next;
};

struct InventoryInfo* inventoryMain = NULL;
void inventoryMenu();

//add inventory function
void addInventory() {
	struct InventoryInfo* addBook = new struct InventoryInfo;

	//input new inventoryid
	cout << "Enter Book ID: ";
	cin >> addBook->BookID;
	
	//check existing book id
	struct InventoryInfo* checkID;
	checkID = inventoryMain;
	while(checkID != NULL) {
		//if got existing book id
		if (addBook->BookID == checkID->BookID) {
			cout << "there is duplicate book id" << endl << "please enter a new book id";
			cin >> addBook->BookID;
			checkID = NULL;
		} else {
			//else proceed to adding inventory
			checkID = checkID->next;
		}
	}

	//adding book into inventory
	cout << "please enter book name" << endl;
	cout << "Enter book name: ";
	//use to ignore or clear one or more characters from the input buffer
	cin.ignore();
	getline(cin, addBook->BookName);

	cout << "please enter book type" << endl;
	cout << "Enter book type: ";
	getline(cin, addBook->BookType);

	cout << "please enter book unit price" << endl;
	cout << "Enter book unit price: ";
	cin >> addBook->UnitPrice;

	cout << "please enter book quantity" << endl;
	cout << "Enter book quantity: ";
	cin >> addBook->Quantity;

	addBook->next = inventoryMain;
	inventoryMain = addBook;

	//store data into inventory text file
	fstream db;
	db.open("Inventory.txt", ios_base::app);
	db << addBook->BookID << "," << addBook->BookName << "," << addBook->BookType << "," << addBook->UnitPrice << "," << addBook->Quantity << endl;
	cout << "Book is succesfully added into inventory" << endl;
	db.close();
}

//Edit Invetory
void editInventory() {
	cout << "edit inventory havent comeplete" << endl;
}

//view intenvory list
void viewInventory() {
	//cout << "view inventory havent comeplete" << endl;
	system("CLS");
	
}

//search inventory
void searchInventory() {
	cout << "search inventory havent comeplete" << endl;
}

//sort inventory
void sortInventory() {
	cout << "sort inventory havent comeplete" << endl;
}

//show inventory menu
void inventoryMenu() {
	int choice;
	string id;
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

}