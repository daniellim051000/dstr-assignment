#pragma once
#include <iostream>
#include <ctime>
#include <string>
using namespace std;

void paymentOption();

void addTransaction() {
	struct bookstoreInfo* addTransactions = new struct bookstoreInfo;

	cout << "	____________________________________" << endl;
	cout << "	|Transaction ID:\t\t    |" << endl;
	cout << "	|\t\t\t\t    |" << endl;
	cout << "	|Date & Time:\t\t\t    |" << endl;
	cout << "	|\t\t\t\t    |" << endl;
	cout << "	|Payment type:\t\t\t    |" << endl;
	cout << "	|\t\t\t\t    |" << endl;
	cout << "	|Total price:\t\t\t    |" << endl;
	cout << "	|\t\t\t\t    |" << endl;
	cout << "	|Customer ID:\t\t\t    |" << endl;
	cout << "	|___________________________________|" << endl;

	cout << "Enter transaction ID: ";
	cin >> addTransactions->transId;

	//creating temp pointer
	struct bookstoreInfo* checkId;
	checkId = head;
	//transverse
	while (checkId != NULL) {
		if (addTransactions->transId == checkId->transId) {
			cout << "Duplicate transaction ID!" << endl << "Please reenter transaction ID : ";
			cin >> addTransactions->transId;
			checkId = NULL; //to break the loop
		}
		else {
			checkId = checkId->next;
		}
	}

	cout << "What is transaction date?" << endl << "Enter transaction date: ";
	cout << addTransactions->dateTime;

	cout << "What is payment type of transaction?" << endl;
	paymentOption();
	cout << "Enter payment type: ";
	cin.ignore();
	getline(cin, addTransactions->paymentType);

	cout << "What is the total price of transaction?" << endl;
	cout << "Enter total price: ";
	cin >> addTransactions->totalPrice;

	cout << "What is the customer id? " << endl;
	cout << "Enter customer id: ";
	cin >> addTransactions->custId;

	addTransactions->next = head;
	head = addTransactions;

	// store data into Customer.txt file
	fstream file;
	file.open("Transaction.txt", ios_base::app);
	// insert data into file
	file << addTransactions->transId << ", "
		<< addTransactions->paymentType << ", "
		<< addTransactions->totalPrice << ", "
		<< addTransactions->custId << ", "
		<< addTransactions->dateTime << endl;

	cout << "Transaction has successfully insert " << endl;
	file >> addTransactions->custId;
	cout << addTransactions->custId << endl;
	file.close();
}

void sortTransaction() {

}

void searchTransaction() {

}

void viewTransaction() {

}

void viewTransactionDetail() {

}

void showSelectionTransaction(int selected) {
	if (selected == 2) {
		cout << "*** Bookstore System ***" << endl;
		cout << "To perform an action, enter " << endl;
		cout << "1 Add Transaction Details" << endl;
		cout << "2 Sort Transaction" << endl;
		cout << "3 Search Transaction" << endl;
		cout << "4 View Transaction" << endl;
		cout << "5 View Transaction Details" << endl;
		cout << "6 to exit\n" << endl;

		int choice{};
		showSelectionTransaction(choice);
		cin >> choice;

		while (choice != 2)
		{
			switch (choice)
			{
			case 1:
				addTransaction();
				break;
				/*case 2:
					sortTransaction();
					break;
				case 3:
					searchTransaction();
					break;
				case 4:
					viewTransaction();
					break;
				case 5:
					viewTransactionDetail();
					break;*/
			default:
				cout << "Invalid selection.\n" << endl;
			}
			cout << endl;
			showSelectionTransaction(choice);
			cin >> choice;
		}
	}
}

void paymentOption() {
	cout << "*** Bookstore System ***" << endl;
	cout << "To perform an action, enter " << endl;
	cout << "1 Cash" << endl;
	cout << "2 Debit Cards" << endl;
	cout << "3 Credit Cards" << endl;
	cout << "4 Mobile payments" << endl;
	cout << "5 Online banking" << endl;
	cout << "6 to exit\n" << endl;
}