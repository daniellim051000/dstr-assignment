#pragma once
#include <iostream>
#include <ctime>
#include <string>
#include <fstream>
using namespace std;

struct transactionInfo {
	int custId, transId;
	time_t now = time(0);
	char* dateTime = ctime(&now);
	string paymentType;
	double totalPrice;
	transactionInfo* next;
};

struct transactionInfo* headTransaction = NULL;
void paymentOption();
void transactionMenu();


void addTransaction() {
	struct transactionInfo* addTransactions = new struct transactionInfo;
	ifstream transfile("Transaction.txt");
	int transactionId;

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
	struct transactionInfo* checkCustId;
	checkCustId = headTransaction;
	//transverse
	while (checkCustId != NULL) {
		/*while (!transfile.eof()) {
			while (transfile >> transactionId) {*/

				if (addTransactions->transId == checkCustId->transId) {
					//checkId->transId = transactionId;
					cout << "Duplicate transaction ID!" << endl << "Please reenter transaction ID : ";
					cin >> addTransactions->transId;
					checkCustId = NULL; //to break the loop
				}
				else {
					checkCustId = checkCustId->next;
				}
			//}
		//}
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
	
	// variable for loop data
	int Id;
	string Name, PhoneNo, Email;
	// read customer file
	ifstream custfile("Customer.txt");
	
	cout << "What is the customer id? " << endl;
	cout << "Enter customer id: ";
	cin >> addTransactions->custId;
	if (custfile.is_open()) {
		while (!custfile.eof()) {
			// loop each element to the declared variables
			while (custfile >> Id >> Name >> PhoneNo >> Email) {
				if (addTransactions->custId == Id) {
					addTransactions->custId = Id;
					cin >> addTransactions->custId;			
					
					// open Customer.txt file
					fstream file;
					file.open("Transaction.txt", ios_base::app);
					// insert data into file
					file << addTransactions->transId << "\t "
						<< addTransactions->paymentType << "\t\t "
						<< addTransactions->totalPrice << "\t "
						<< addTransactions->custId << "\t "
						<< addTransactions->dateTime << endl;

					cout << "Transaction has successfully insert " << endl;
					file >> addTransactions->custId;
					cout << addTransactions->custId << endl;
					file.close();	
				}
			}
		}
		custfile.close();
	}
	else {
		cout << "Unable to open file!" << endl;
	}

	addTransactions->next = headTransaction;
	headTransaction = addTransactions;

}

void sortTransaction() {
	struct transactionInfo* current;
	current = headTransaction;
	int tempId, tempCustId;
	string tempType;
	char* tempDate;
	double tempPrice;
	//int Id, CustomerId;
	//string Type, Price, Date;
	ifstream file("Transaction.txt");
	int counter = 0;

	if (file.fill() == NULL) {
		cout << "No transaction record";
	}

	while (current) {
		current = current->next;
		counter++;
	}

	if (file.is_open()) {
		cout << " _______________________________________________________________________________________________________________" << endl;
		cout << " |Transaction ID \t\tPayment Type \t\t\tTotal Price \t\t\tCustomer ID \t\t\tTransaction Date\t\t\t\t|" << endl;
		//if file not end of the file
		while (!file.eof()) {
			// loop each element to the declared variables
			while (file >> tempId >> tempType >> tempPrice >> tempCustId >> tempDate) {

				if (current != NULL) {
					for (int i = 0; i < counter; i++) {
						for (int j = 0; j < counter - i; j++) {
							if (current->totalPrice > current->next->totalPrice) {
								tempId = current->transId;
								current->transId = current->next->transId;
								current->next->transId = tempId;

								tempType = current->paymentType;
								current->paymentType = current->next->paymentType;
								current->next->paymentType = tempType;

								tempPrice = current->totalPrice;
								current->totalPrice = current->next->totalPrice;
								current->next->totalPrice = tempPrice;

								tempCustId = current->custId;
								current->custId = current->next->custId;
								current->next->custId = tempCustId;

								tempDate = current->dateTime;
								current->dateTime = current->next->dateTime;
								current->next->dateTime = tempDate;

								cout << "Sorted customer detail" << endl;
								cout << "" << tempId <<
									"\t \t" << tempType <<
									"\t \t" << tempPrice <<
									"\t \t" << tempCustId <<
									"\t \t" << tempDate << "\n";
								return;

							}
							else {
								current = current->next;
							}
						}
					}
				}
			}
		}
		file.close();
	}
	else {
		cout << "Unable to open file!" << endl;
	}
}

void searchTransaction() {
	int searchTransId;
	cout << "Enter search customer ID: ";
	cin >> searchTransId;
	int Id, CustomerId;
	string Type, Price, Date;
	ifstream file("Transaction.txt");

	if (file.is_open()) {
		cout << " _______________________________________________________________________________________________________________" << endl;
		cout << " |Transaction ID \t\tPayment Type \t\t\tTotal Price \t\t\tCustomer ID \t\t\tTransaction Date\t\t\t\t|" << endl;
		//if file not end of the file
		while (!file.eof()) {
			// loop each element to the declared variables
			while (file >> Id >> Type >> Price >> CustomerId >> Date) {
				if (Id == searchTransId) {
					cout << " |" << Id << "\t\t\t" << Type << "\t\t\t" << Price << "\t\t\t" << CustomerId << "\t\t\t" << Date << " \t\t|" << endl;
				}
			}
		}
		cout << " |______________________________________________________________________________________________________________|" << endl;
		file.close();
	}
	else {
		cout << "Unable to open file!" << endl;
	}
}

void viewTransactionDetail() {
	int Id, CustomerId;
	string Type, Price, Date;
	ifstream file("Transaction.txt");

	if (file.is_open()) {
		cout << " _______________________________________________________________________________________________________________" << endl;
		cout << " |Transaction ID \t\tPayment Type \t\t\tTotal Price \t\t\tCustomer ID \t\t\tTransaction Date\t\t\t\t|" << endl;
		//if file not end of the file
		while (!file.eof()) {
			// loop each element to the declared variables
			while (file >> Id >> Type >> Price >> CustomerId >> Date) {
				cout << " |" << Id << "\t\t\t" << Type << "\t\t\t" << Price << "\t\t\t" << CustomerId << "\t\t\t" << Date << " \t\t|" << endl;
			}
		}
		cout << " |______________________________________________________________________________________________________________|" << endl;
		file.close();
	}
	else {
		cout << "Unable to open file!" << endl;
	}
}

void transactionMenu() {
	int choice;
	system("CLS");
	do {
		cout << "*** Transaction Management ***" << endl;
		cout << "To perform an action, enter " << endl;
		cout << "1 Add Transaction Details" << endl;
		cout << "2 Sort Transaction" << endl;
		cout << "3 Search Transaction" << endl;
		cout << "4 View Transaction Details" << endl;
		cout << "5 Exit Transaction Management\n" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			addTransaction();
			break;
		case 2:
			sortTransaction();
			break;
		case 3:
			searchTransaction();
			break;
		case 4:
			viewTransactionDetail();
			break;
		default:
			cout << "Invalid selection.\n" << endl;
		}
	} while (choice != 5);
	system("CLS");
}

void paymentOption() {
	cout << "*** Payment Methods ***" << endl;
	cout << "To perform an action, enter " << endl;
	cout << "1 Cash" << endl;
	cout << "2 Debit Cards" << endl;
	cout << "3 Credit Cards" << endl;
	cout << "4 Mobile payments" << endl;
	cout << "5 Online banking" << endl;
	cout << "6 to exit\n" << endl;
}