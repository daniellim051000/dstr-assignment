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
	void displayInventory(InventoryInfo* head);
	std::string showInventory(int method);
	InventoryInfo* search(int id, InventoryInfo* head);
	int getInventoryID();
	void setInventoryID(int BookID);
	std::string getBookName();
	void setBookName(string BookName);
	std::string getBookType();
	void setBookType(string BookType);
	double getUnitPrice();
	void setUnitPrice(double UnitPrice);
	int getQuantity();
	void setQuantity(int Quantity);
	void updateInventoryStatus(InventoryInfo* status);
};
struct InventoryInfo* headInventory = NULL;
int bookID = 1;
void inventoryMenu();

int InventoryInfo::getInventoryID() {
	return this->BookID;
}

void InventoryInfo::setInventoryID(int BookID) {
	this->BookID = bookID;
}

string InventoryInfo::getBookName() {
	return this->BookName;
}

void InventoryInfo::setBookName(string BookName) {
	this->BookName = BookName;
}

string InventoryInfo::getBookType() {
	return this->BookType;
}

void InventoryInfo::setBookType(string BookType) {
	this->BookType = BookType;
}

double InventoryInfo::getUnitPrice() {
	return this->UnitPrice;
}

void InventoryInfo::setUnitPrice(double UnitPrice) {
	this->UnitPrice = UnitPrice;
}

int InventoryInfo::getQuantity() {
	return this->Quantity;
}

void InventoryInfo::setQuantity(int Quantity) {
	this->Quantity = Quantity;
}


string InventoryInfo::showInventory(int method) {
	switch (method) {
	case 1: {
		return to_string(getInventoryID()) + "\t" + getBookName() + "\t" + getBookType() + "\t" + to_string(getUnitPrice()) + "\t" + to_string(getQuantity()) + "\n";
	}
		  break;
	case 2: {
		return "Book ID    : " + to_string(getInventoryID()) + "\n" + "Book Name  : " + getBookName() + "\n" + "Category   : " + getBookType() + "\n" + "Unit Price :RM " + to_string(getUnitPrice()) + "\n" + "Quantity   : " + to_string(getQuantity()) + "\n";
	}
		  break;
	default:
		return "Book ID    : " + to_string(getInventoryID()) + "\n" + "Book Name  : " + getBookName() + "\n" + "Category   : " + getBookType() + "\n" + "Unit Price :RM " + to_string(getUnitPrice()) + "\n" + "Quantity   : " + to_string(getQuantity()) + "\n";
	}
}

//add inventory function
void addInventory() {
	struct InventoryInfo* add_inventory = new struct InventoryInfo;
	add_inventory->BookID = bookID;
	bookID++; // auto generated book id

	//book id
	cout << "Enter Book ID >>";
	cout << add_inventory->BookID << endl;

	//book name
	cout << "Please enter the Book Name >>";
	cin >> add_inventory->BookName;
	//getline(cin, add_inventory->BookName);

	//book type
	int choice = 0;
	do {
		cout << "Please choose the book category >>" << endl;
		cout << "---------Fiction------------" << endl;
		cout << "1 Classics" << endl;
		cout << "2 Mystery" << endl;
		cout << "3 Fantasy" << endl;
		cout << "4 Romance" << endl;
		cout << "5 Science" << endl;
		cout << "---------Non-Fiction---------" << endl;
		cout << "6 Poetry" << endl;
		cout << "7 Self-Help" << endl;
		cout << "8 CookBook" << endl;
		cout << "9 Memoir" << endl;
		cout << "10 History" << endl;
		cout << "-----------------------------------" << endl;
		cin >> choice;
		if (choice == 1) {
			add_inventory->BookType = "Classics";
			cout << add_inventory->BookType << endl;
			break;
		}
		else if (choice == 2) {
			add_inventory->BookType = "Mystery";
			cout << add_inventory->BookType << endl;
			break;
		}
		else if (choice == 3) {
			add_inventory->BookType = "Fantasy";
			cout << add_inventory->BookType << endl;
			break;
		}
		else if (choice == 4) {
			add_inventory->BookType = "Romance";
			cout << add_inventory->BookType << endl;
			break;
		}
		else if (choice == 5) {
			add_inventory->BookType = "Science";
			cout << add_inventory->BookType << endl;
			break;
		}
		else if (choice == 6) {
			add_inventory->BookType = "Poetry";
			cout << add_inventory->BookType << endl;
			break;
		}
		else if (choice == 7) {
			add_inventory->BookType = "Self-Help";
			cout << add_inventory->BookType << endl;
			break;
		}
		else if (choice == 8) {
			add_inventory->BookType = "CookBook";
			cout << add_inventory->BookType << endl;
			break;
		}
		else if (choice == 9) {
			add_inventory->BookType = "Memoir";
			cout << add_inventory->BookType << endl;
			break;
		}
		else if (choice == 10) {
			add_inventory->BookType = "History";
			cout << add_inventory->BookType << endl;
			break;
		}
		else {
			cout << "Invalid selection.\n" << endl;
		}
	} while (choice != 10);

	//unit price for the book
	cout << "Please enter the unit price for the book >>";
	cin >> add_inventory->UnitPrice;
	while (!cin.good() || add_inventory->UnitPrice < 0) { // validation for in and min price of  1
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
	while (!cin.good() || searchID < 0) { // validation for int and min quantity of 1
		cout << "Please enter the valid quantity with at least 1" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Please enter a new quanity >>";
		cin >> searchID;
	}

	struct InventoryInfo* current;
	current = headInventory;
	while (current != NULL) {
		if (current->BookID == searchID) {
			int selection;
			int choice;
			cout << "Book ID \tBook Name \t\tBook Type \t\tUnit Price \tQuantity\t" << endl;
			cout << current->BookID << " \t\t " << current->BookName << " \t\t " << current->BookType << " \t\t " << current->UnitPrice << " \t\t " << current->Quantity << " \t " << endl;
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
			case 1: // edit book name
				cout << "Enter the new Book Name >>";
				cin >> current->BookName;
				break;
			case 2:// edit book type
				do {
					cout << "Please choose the new book category >>" << endl;
					cout << "---------Fiction------------" << endl;
					cout << "1 Classics" << endl;
					cout << "2 Mystery" << endl;
					cout << "3 Fantasy" << endl;
					cout << "4 Romance" << endl;
					cout << "5 Science" << endl;
					cout << "---------Non-Fiction---------" << endl;
					cout << "6 Poetry" << endl;
					cout << "7 Self-Help" << endl;
					cout << "8 CookBook" << endl;
					cout << "9 Memoir" << endl;
					cout << "10 History" << endl;
					cout << "-----------------------------------" << endl;
					cin >> choice;
					if (choice == 1) {
						current->BookType = "Classics";
						cout << current->BookType << endl;
						break;
					}
					else if (choice == 2) {
						current->BookType = "Mystery";
						cout << current->BookType << endl;
						break;
					}
					else if (choice == 3) {
						current->BookType = "Fantasy";
						cout << current->BookType << endl;
						break;
					}
					else if (choice == 4) {
						current->BookType = "Romance";
						cout << current->BookType << endl;
						break;
					}
					else if (choice == 5) {
						current->BookType = "Science";
						cout << current->BookType << endl;
						break;
					}
					else if (choice == 6) {
						current->BookType = "Poetry";
						cout << current->BookType << endl;
						break;
					}
					else if (choice == 7) {
						current->BookType = "Self-Help";
						cout << current->BookType << endl;
						break;
					}
					else if (choice == 8) {
						current->BookType = "CookBook";
						cout << current->BookType << endl;
						break;
					}
					else if (choice == 9) {
						current->BookType = "Memoir";
						cout << current->BookType << endl;
						break;
					}
					else if (choice == 10) {
						current->BookType = "History";
						cout << current->BookType << endl;
						break;
					}
					else {
						cout << "Invalid selection.\n" << endl;
					}
				} while (choice != 10);
				break;
			case 3: // edit book unit price
				cout << "Enter the new Unit Price >>";
				cin >> current->UnitPrice;
				while (!cin.good() || current->UnitPrice < 0) { // validation for in and min price of  1
					cout << "Please enter the valid Unit Price with at least 1" << endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Please enter a new unit price for the book >>";
					cin >> current->UnitPrice;
				}
				break;
			case 4: // edit book quantity
				cout << "Enter the new quantity >>";
				cin >> current->Quantity;
				while (!cin.good() || current->Quantity < 0) { // validation for int and min quantity of 1
					cout << "Please enter the valid quantity with at least 1" << endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Please enter a new quanity >>";
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
			current = current->next;
		}
	}
	cout << "No Book is found" << endl;
}

void deleteInventory() {
	int deleteID;
	string choice;
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

	if (current == NULL) {
		cout << "No inventory record!" << endl;
	}
	else {
		while (current->BookID != deleteID && current != NULL) {
			previous = current;
			current = current->next;
		}
		if (previous == NULL) { // delete at the beginning
			if (current->Quantity != 0) { // not equal 0
				cout << "Book Quantity is not ZERO! Cannot be deleted " << endl;
				cout << "To exit. please enter 'exit' to exit" << endl;
				cout << "To enter the new book ID. please enter 'new' to exit" << endl;
				cin >> choice;
				if (choice == "exit") {
					return;
				}
				else {
					return deleteInventory();
				}
			}
			else {
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
		}
		else { // delete at the end
			if (current->Quantity != 0) { // not equal 0
				cout << "Book Quantity is not ZERO! Cannot be deleted " << endl;
				cout << "To exit. please enter 'exit' to exit" << endl;
				cout << "To enter the new book ID. please enter 'new' to exit" << endl;
				cin >> choice;
				if (choice == "exit") {
					return;
				}
				else {
					return deleteInventory();
				}
			}
			else {
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
		cout << view->BookID << " \t\t " << view->BookName << " \t\t " << view->BookType << " \t\t " << view->UnitPrice << " \t\t " << view->Quantity << " \t " << endl;
		view = view->next;
	}
}

void InventoryInfo::displayInventory(InventoryInfo* head) {
	struct InventoryInfo* view;
	cout << "Book ID \tBook Name \t\tBook Type \t\tUnit Price \tQuantity\t" << endl;
	if (head == NULL) {
		view = headInventory;
	}
	else {
		view = head;
	}
	if (view == NULL) {
		cout << "No book in inventory" << endl;
	}
	while (view != NULL) {
		cout << view->BookID << " \t\t " << view->BookName << " \t\t " << view->BookType << " \t\t " << view->UnitPrice << " \t\t " << view->Quantity << " \t " << endl;
		view = view->next;
	}
}

//search inventory
InventoryInfo* InventoryInfo::search(int id, InventoryInfo* head) {
	struct InventoryInfo* current;
	if (head == NULL) {
		current = headInventory;
	}
	else
	{
		current = head;
	}
	if (current == NULL) {
		return current;
	} while (current != NULL) {
		if (current->getInventoryID() == id) {
			return current;
		}
		current = current->next;
	}
	current = NULL;
	return current;
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
		cout << "No inventory record" << endl;
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
		cout << "No inventory record" << endl;
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
		cout << "No inventory record" << endl;
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
		cout << "No inventory record" << endl;
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
		cout << "No inventory record" << endl;
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
		cout << "No inventory record" << endl;
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
				if (sort->Quantity != sort->next->Quantity) {
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
		cout << "No inventory record" << endl;
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

void filterCategory() {
	struct InventoryInfo* current;
	current = headInventory;
	//string option[10] = {"Classics", "Mystery", "Fantasy", "Romance", "Science", "Poetry", "Self-Help", "CookBook", "Memoir", "History"};
	string filter;
	int choice;
	int tempBookId;
	string tempBookName;
	string tempBookType;
	double tempUnitPrice;
	int tempQuantity;
	int counter = 0;

	if (current == NULL) {
		cout << "No inventory record" << endl;
	}
	else {
		do {
			cout << "Please choose the book category to filter >>" << endl;
			cout << "---------Fiction------------" << endl;
			cout << "1 Classics" << endl;
			cout << "2 Mystery" << endl;
			cout << "3 Fantasy" << endl;
			cout << "4 Romance" << endl;
			cout << "5 Science" << endl;
			cout << "---------Non-Fiction---------" << endl;
			cout << "6 Poetry" << endl;
			cout << "7 Self-Help" << endl;
			cout << "8 CookBook" << endl;
			cout << "9 Memoir" << endl;
			cout << "10 History" << endl;
			cout << "-----------------------------------" << endl;
			cin >> choice;
			if (choice == 1) {
				filter = "Classics";
				cout << filter << endl;
				break;
			}
			else if (choice == 2) {
				filter = "Mystery";
				cout << filter << endl;
				break;
			}
			else if (choice == 3) {
				filter = "Fantasy";
				cout << filter << endl;
				break;
			}
			else if (choice == 4) {
				filter = "Romance";
				cout << filter << endl;
				break;
			}
			else if (choice == 5) {
				filter = "Science";
				cout << filter << endl;
				break;
			}
			else if (choice == 6) {
				filter = "Poetry";
				cout << filter << endl;
				break;
			}
			else if (choice == 7) {
				filter = "Self-Help";
				cout << filter << endl;
				break;
			}
			else if (choice == 8) {
				filter = "CookBook";
				cout << filter << endl;
				break;
			}
			else if (choice == 9) {
				filter = "Memoir";
				cout << filter << endl;
				break;
			}
			else if (choice == 10) {
				filter = "History";
				cout << filter << endl;
				break;
			}
			else {
				cout << "Invalid selection.\n" << endl;
			}

		} while (choice != 10);

		cout << "Filtered Book List" << endl;
		cout << "Book ID \tBook Name \t\tBook Type \t\tUnit Price \tQuantity\t" << endl;
		while (current != NULL) {
			if (current->BookType == filter) {
				cout << current->BookID << " \t\t " << current->BookName << " \t\t " << current->BookType << " \t\t " << current->UnitPrice << " \t\t " << current->Quantity << " \t " << endl;
			}
			current = current->next;
		}
		// here got problem
		cout << "No book in " << filter << " category" << endl;
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

void InventoryInfo::updateInventoryStatus(InventoryInfo* status) {
	InventoryInfo* current = headInventory;
	if (current == NULL) {
		return;
	}
	else if (status == NULL) {
		return;
	}
	while (current != NULL) {
		if (status->getInventoryID() == current->getInventoryID()) {
			current->setQuantity(current->getQuantity() - status->getQuantity());
			break;
		}
		current = current->next;
	}
	status = status->next;
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
		cout << "7 Filter Inventory Category" << endl;
		cout << "8 Exit Inventory Management\n" << endl;
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
			filterCategory();
			break;
		case 8:
			return;
			system("CLS");
			break;
		default:
			cout << "Invalid selection! Please select again " << endl;
		}
	} while (choice != 8);
	system("CLS");
}
