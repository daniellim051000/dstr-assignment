#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include "Inventory.h"
using namespace std;

struct Transaction {
		int transactionID;
		double totatPrice;
		InventoryInfo* bookDetails = NULL;
		Transaction* next;

		void viewCart(Transaction** head);
		void newTransaction();
		//transaction id
		void setNewID(int transactionID);
		int getNewID();
		//total price
		void setTotalPrice(double totalPrice);
		double getTotalPrice();
		Transaction* searchTransaction(int id, Transaction* head);
		//bought book
		InventoryInfo* getAddedBooks();
		void setAddedBooks(int id, std::string name, std::string booktype, double unitPrice, int quantity);
		void addToCart(Transaction** head);
		double calculateTotal(Transaction** head);
		void showTransactionRecord();
};

Transaction* headTransaction = NULL;
Transaction* transaction1 = new Transaction;
InventoryInfo* seeInventory = new InventoryInfo;
int newTransID = 1001;

void showNewTransMenu();

int Transaction::getNewID() {
	return this->transactionID;
}

void Transaction::setNewID(int transactionID) {
	this->transactionID = transactionID;
}

double Transaction::getTotalPrice() {
	return this->totatPrice;
}

void Transaction::setTotalPrice(double totalPrice) {
	this->totatPrice = totalPrice;
}

InventoryInfo* Transaction::getAddedBooks() {
	return this->bookDetails;
}

void Transaction::setAddedBooks(int id, string name, string booktype, double unitPrice, int quantity) {
	InventoryInfo* current = new InventoryInfo;
	current->push(&this->bookDetails, id, name, booktype, unitPrice, quantity);
}

void Transaction::newTransaction() {
	Transaction* newCart = new Transaction;

	viewCart(&newCart);
	int choice = 0;
	//set new id for transaction
	newCart->setNewID(newTransID);
	newTransID++;
	
	do {
		cout << "please select an action.\n1. Add books to Order\n2. View Order\n3. Checkout Order\n4.Cancel Order\n";
		cin >> choice;

		switch (choice) {
		case 1:
			addToCart(&newCart);
			system("CLS");
			break;
		case 2:
			viewCart(&newCart);
			break;
		case 3:
			if (newCart->getAddedBooks() == NULL) {
				cout << "there is nothing in the order. Please have some books before checkout" << endl;
			}
			else {
				cout << "perform checkout" << endl;
				newCart->setTotalPrice(calculateTotal(&newCart));
				seeInventory->updateInventoryStatus(newCart->getAddedBooks());
				newCart->next = headTransaction;
				headTransaction = newCart;
				cout << "checkout successful" << endl;
				return;
			}
			break;
		default:
			cout << "Invalid selection.\n" << endl;
		}
	} while (choice != 4);
}

void Transaction::addToCart(Transaction** head) {
	int choice;
	int quantity = 0;
	int counter = 0;
	InventoryInfo* temp = new InventoryInfo;
	InventoryInfo* itemInStock = new InventoryInfo;
	InventoryInfo* itemInCart = new InventoryInfo;
	InventoryInfo* cart = (*head)->getAddedBooks();

	do {
		if (counter == 0) {
			cout << "please enter the book id wanted to add into cart" << endl;
			itemInStock->displayInventory(NULL);
			cout << "To exit. please enter 0 to exit" << endl;
			cin >> choice;
			if (choice == 0) {
				break;
			}
			temp = itemInStock->search(choice, NULL);
			if (temp == NULL) {
				cout << "Book Not found! Please Enter another book " << endl;
				continue;
			}
			counter++;
		}
		else if (counter == 1) {
			cout << temp->showInventory(2);
			cout << "please enter a quantity of book u wish to buy." << endl;
			cout << "Enter 0 to exit" << endl;
			cin >> quantity;
			while (cin.fail() && quantity < 0) {
				if (cin.fail()) {
					cin.clear();
					cin.ignore();
				}
				cout << "Invalid input" << endl;
				cout << "Please key in the postive number for quantity" << endl;
				cin >> quantity;
			}
			if (quantity == 0)break;
			if (quantity > temp->getQuantity()) {
				cout << "Quantity more than stock. please re-enter a smaller number" << endl;
				continue;
			}
			//if the cart is empty, then allow add
			if (cart == NULL) {
				(*head)->setAddedBooks(temp->getInventoryID(), temp->getBookName(), temp->getBookType(), temp->getUnitPrice(), quantity);
				return;
			}
			//search for the choosen book in the transaction cart
			itemInCart = itemInStock->search(choice, cart);
			//if the book is not found in the cart
			if (itemInCart == NULL) {
				cout << "there is nothing in cart" << endl;
				(*head)->setAddedBooks(temp->getInventoryID(), temp->getBookName(), temp->getBookType(), temp->getUnitPrice(), quantity);
				return;
			}
			else {
				if (temp->getQuantity() < itemInCart->getQuantity() + quantity) {
					//here got problem
					cout << "quantity more than stock available. please re-enter a smaller number" << endl;
					continue;
				}
				else {
					while (cart != NULL) {
						if (cart->getInventoryID() == temp->getInventoryID()) {
							cart->setQuantity(cart->getQuantity() + quantity);
							break;
						}
						cart = cart->next;
					}
				}
				counter++;
			}
		}
	} while (counter < 2);
}

void Transaction::viewCart(Transaction** headTransaction) {
	InventoryInfo* current = (*headTransaction)->getAddedBooks();
	if (current == NULL) {
		cout << "No Books is found" << endl;
	}
	else {
		current->displayInventory(current);
	}
}

void Transaction::showTransactionRecord() {
	struct Transaction* current;
	Transaction *choiceTrans = new Transaction;
	current = headTransaction;
	int choice;
	int counter = 0;
	
	if (current == NULL) {
		cout << "No Transaction is found" << endl;
		return;
	} 
	do {
		if (counter == 0) {
			cout << "Transaction ID \t Total Price (RM)" << endl;
			while (current != NULL) {
				cout << current->getNewID() << "\t\t " << ceil(current->getTotalPrice() * 100.0) / 100.0 << endl;
				InventoryInfo* purchase = current->getAddedBooks();
				current = current->next;
			}
			cout << "Please enter the transaction to view the details" << endl;
			cout << "Enter 0 to exit menu" << endl;
			cin >> choice;
			while (cin.fail()) {
				if (cin.fail()) {
					cin.clear();
					cin.ignore();
				}
				cout << "invalid Input" << endl;
				cout << "Please key in the transaction ID again" << endl;
				cin >> choice;
			}
			if (choice == 0) { break; }
			choiceTrans = choiceTrans->searchTransaction(choice, headTransaction);
			if (choiceTrans == NULL) {
				cout << "Transaction not found! Please enter another ID" << endl;
				current = headTransaction;
				continue;
			}
			counter++;
		}
		if (counter == 1) {
			seeInventory->displayInventory(choiceTrans->getAddedBooks());
			cout << "DO you want to check another Transaction?" << endl;
			cout << "1. Yes" << endl;
			cout << "2. No" << endl;
			cin >> choice;
			if (choice == 1) {
				current = headTransaction;
				counter--;
				continue;
			}
			else {
				counter++;
			}
		}
	} while (counter < 2);
}

Transaction* Transaction::searchTransaction(int id, Transaction* head) {
	struct Transaction* current;
	current = head;
	if (current == NULL) {
		return current;
	} while (current != NULL) {
		if (current->getNewID() == id) {
			return current;
		}
		current = current->next;
	}
	current = NULL;
	return current;
}

double Transaction::calculateTotal(Transaction** head) {
	InventoryInfo* current = (*head)->getAddedBooks();
	float total = 0;
	if (current == NULL) {
		return total;
	}
	while (current != NULL) {
		total = current->getUnitPrice() * current->getQuantity();
		current = current->next;
	}
	return total;
}

void sortTotalPriceAscending() {
	struct Transaction* sort;
	sort = headTransaction;
	int tempID;
	double tempPrice;
	int counter = 0;
	if (sort == NULL) {
		cout << "there is no transaction" << endl;
	}
	else {
		while (sort != NULL) {
			sort = sort->next;
			counter++;
		}
	}
	for (int i = 0; i < counter; i++) {
		while (sort != NULL && sort->next != NULL) {
			if (sort->totatPrice > sort->next->totatPrice) {
				tempID = sort->transactionID;
				sort->transactionID = sort->next->transactionID;
				sort->next->transactionID = tempID;

				tempPrice = sort->totatPrice;
				sort->totatPrice = sort->next->totatPrice;
				sort->next->totatPrice = tempPrice;
			}
			sort = sort->next;
		}
		sort = headTransaction;
	}
	cout << "Sort Transaction in Ascending" << endl;
	cout << "Transaction ID Total Price" << endl;
	while (sort != NULL) {
		cout << sort->transactionID << " " << sort->totatPrice << endl;
		sort = sort->next;
	}
}

void sortTotalPriceDescending() {
	struct Transaction* sort;
	sort = headTransaction;
	int tempID;
	double tempPrice;
	int counter = 0;
	if (sort == NULL) {
		cout << "there is no transaction" << endl;
	}
	else {
		while (sort != NULL) {
			sort = sort->next;
			counter++;
		}
	}
	for (int i = 0; i < counter; i++) {
		while (sort != NULL && sort->next != NULL) {
			if (sort->totatPrice < sort->next->totatPrice) {
				tempID = sort->transactionID;
				sort->transactionID = sort->next->transactionID;
				sort->next->transactionID = tempID;

				tempPrice = sort->totatPrice;
				sort->totatPrice = sort->next->totatPrice;
				sort->next->totatPrice = tempPrice;
			}
			sort = sort->next;
		}
		sort = headTransaction;
	}
	cout << "Sort Transaction in Descending" << endl;
	cout << "Transaction ID Total Price" << endl;
	while (sort != NULL) {
		cout << sort->transactionID << " " << sort->totatPrice << endl;
		sort = sort->next;
	}
}

void sortTransaction() {
	int choice;
	system("CLS");
	do {
		cout << "Sort Transaction" << endl;
		cout << "To perform an action, enter" << endl;
		cout << "1 Sort Book Price in Ascending Order" << endl;
		cout << "2 Sort Book Price in Descending Order" << endl;
		cout << "3 TO Exit" << endl;
		cin >> choice;

		switch (choice) {
		case 1:
			sortTotalPriceAscending();
			break;
		case 2:
			sortTotalPriceDescending();
			break;
		default:
			cout << "Invalid selection. Please pick again.\n" << endl;
		}
	} while (choice != 3);
	system("CLS");
}

void showNewTransMenu() {
	int choice;
	system("CLS");
	do {
		cout << "New Transaction Management" << endl;
		cout << "To perform an action, enter" << endl;
		cout << "1 Create Transaction" << endl;
		cout << "2 View Transaction Details" << endl;
		cout << "3 Sort Transaction" << endl;
		cout << "4 Exit Transaction Management\n" << endl;
		cin >> choice;

		switch (choice) {
		case 1:
			transaction1->newTransaction();
			system("CLS");
			break;
		case 2:
			transaction1->showTransactionRecord();
			break;
		case 3:
			sortTransaction();
			system("CLS");
			break;
		default:
			cout << "Invalid selection. Please pick again.\n" << endl;
		}
	} while (choice != 4);
	system("CLS");
}