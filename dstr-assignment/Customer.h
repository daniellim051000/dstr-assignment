#pragma once
#include <iostream>
#include<string>
#include <regex>
#include <fstream>
using namespace std;

struct customerInfo {
	string custId, name, phoneNo, email;
	customerInfo* next;
};


regex PhoneNo("[[:digit:]]{2}-[[:digit:]]{3}-[[:digit:]]{4}");
regex Email("(\\w + )(\\. | _) ? (\\w*)@(\\w + )(\\.(\\w + )) + ");
struct customerInfo* headCustomer = NULL;
void customerMenu();

void addCustomer() {
	//struct for those that consists of string data type
	struct customerInfo* addCustomers = new struct customerInfo;
	
	cout << "	____________________________________" << endl;
	cout << "	|Customer ID:\t\t\t    |" << endl;
	cout << "	|\t\t\t\t    |" << endl;
	cout << "	|Customer name:\t\t\t    |" << endl;
	cout << "	|\t\t\t\t    |" << endl;
	cout << "	|Customer phone number:\t\t    |" << endl;
	cout << "	|\t\t\t\t    |" << endl;
	cout << "	|Customer email:\t\t    |" << endl;
	cout << "	|___________________________________|" << endl;

	cout << "Enter customer ID: ";
	cin >> addCustomers->custId;

	//creating temp pointer
	struct customerInfo* checkId;
	checkId = headCustomer;
	//transverse
	while (checkId != NULL) {
		if (addCustomers->custId == checkId->custId) {
			cout << "Duplicate customer ID!" << endl << "Please reenter customer ID : ";
			cin >> addCustomers->custId;
			checkId = NULL; //to break the loop
		}
		else {
			checkId = checkId->next;
		}
	}

	cout << "What is your name?" << endl << "Enter name: ";
	//use to ignore or clear one or more characters from the input buffer
	cin.ignore();
	getline(cin, addCustomers->name);

	cout << "What is your phone number?" << endl << "Enter phone number: ";
	//cin.ignore();
	getline(cin, addCustomers->phoneNo);
	while (regex_match(addCustomers->phoneNo, PhoneNo)) {
		cout << "Invalid input\n";
		cout << "What is your phone number?" << endl << "Enter phone number: ";
		//cin.ignore();
		getline(cin, addCustomers->phoneNo);
	}

	cout << "What is your email?" << endl;
	cout << "Enter email: ";
	//cin.ignore();
	getline(cin, addCustomers->email);
	while (regex_match(addCustomers->email, Email)) {
		cout << "Invalid input\n";
		cout << "What is your email?" << endl << "Enter email: ";
		//cin.ignore();
		getline(cin, addCustomers->email);
	}

	addCustomers->next = headCustomer;
	headCustomer = addCustomers;
}

void updateCustomer() {
	string searchCustId;
	cout << "Enter search customer ID: " << endl;
	cin >> searchCustId;
	struct customerInfo* current;
	current = headCustomer;

	while (current != NULL) {
		if (current->custId == searchCustId) {
			cout << "Customer ID \tName \t\t\tPhone Number \t\t\tEmail\n";
			cout << "" << current->custId <<
				"\t \t" << current->name <<
				"\t \t" << current->phoneNo <<
				"\t \t \t" << current->email << "\n";
			cout << "-----------------------------------" << endl;
			cout << "Edit Customer" << endl;
			cout << "1 Edit Name" << endl;
			cout << "2 Edit Phone Number" << endl;
			cout << "3 Edit Email" << endl;
			cout << "4 Exit Edit Customer\n" << endl;

			int updateChoice;
			cin >> updateChoice;

			switch (updateChoice) {
			case 1:
				cout << "What is your name?" << endl << "Enter name: ";
				cin.ignore();
				getline(cin, current->name);
				break;
			case 2:
				cout << "What is your phone number?" << endl << "Enter phone number: ";
				cin.ignore();
				getline(cin, current->phoneNo);
				while (regex_match(current->phoneNo, regex("[[:digit:]]{2}-[[:digit:]]{3}-[[:digit:]]{4}"))) {
					cout << "Invalid input\n";
					cout << "What is your phone number?" << endl << "Enter phone number: ";
					cin.ignore();
					getline(cin, current->phoneNo);
				}
				break;
			case 3:
				cout << "What is your email?" << endl << "Enter email: ";
				cin.ignore();
				getline(cin, current->email);
				while (regex_match(current->email, regex("(\\w + )(\\. | _) ? (\\w*)@(\\w + )(\\.(\\w + )) + "))) {
					cout << "Invalid input\n";
					cout << "What is your email?" << endl << "Enter email: ";
					cin.ignore();
					getline(cin, current->email);
				}
				break;
			case 4:
				return;
			default:
				cout << "Invalid selection.\n" << endl;
			}
		}
		else {
			cout << "No Customer is found" << endl;
			current = current->next;
		}
	}
}

void searchCustomer() {
	string searchCustId;
	cout << "Enter search customer ID: ";
	cin >> searchCustId;
	struct customerInfo* current;
	current = headCustomer;
	cout << "Transaction ID \tTotal Price \tPayment Type \tCustomer ID \tTransaction Date\t" << endl;
	if (current == NULL) {
		cout << "No transaction" << endl;
	}
	while (current != NULL) {
		if (current->custId == searchCustId) {
			cout << current->custId << " \t\t " << current->name << " \t\t " << current->phoneNo << " \t\t " << current->email << " \t " << endl;
			return;
		}
		else {
			current = current->next;
		}
	}
}

void viewCustomerDetail() {
	string searchCustId;
	cout << "Enter search customer ID: ";
	cin >> searchCustId;
	struct customerInfo* view;
	view = headCustomer;
	cout << "Transaction ID \tTotal Price \tPayment Type \tCustomer ID \tTransaction Date\t" << endl;
	if (view == NULL) {
		cout << "No transaction" << endl;
	}
	while (view != NULL) {
			cout << view->custId << " \t\t " << view->name << " \t\t " << view->phoneNo << " \t\t " << view->email << " \t " << endl;
			view = view->next;
	}
}

void customerMenu() {
	int choice;
	system("CLS");
	do {
		cout << "*** Customer Management ***" << endl;
		cout << "To perform an action, enter " << endl;
		cout << "1 Add Customer Details" << endl;
		cout << "2 Update Customer Details" << endl;
		cout << "3 Search Customer" << endl;
		cout << "4 View Customer Details" << endl;
		cout << "5 Exit Customer Management\n" << endl;
		cin >> choice;

		switch (choice) {
		case 1:
			addCustomer();
			break;
		case 2:
			updateCustomer();
			break;
		case 3:
			searchCustomer();
			break;
		case 4:
			viewCustomerDetail();
			break;
		default:
			cout << "Invalid selection.\n" << endl;
		}	
	} while (choice != 5);
	system("CLS");
}