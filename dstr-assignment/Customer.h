#pragma once
#include <iostream>
#include<string>
#include <regex>
#include <fstream>
using namespace std;

struct customerInfo {
	int custId;
	string name, phoneNo, email;
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

	// store data into Customer.txt file
	fstream file;
	file.open("Customer.txt", ios_base::app);
	// insert data into file
	file << addCustomers->custId << "\t "
		<< addCustomers->name << "\t "
		<< addCustomers->phoneNo << "\t "
		<< addCustomers->email << endl;

	cout << "Customer has successfully inserted " << endl;
	file >> addCustomers->custId;
	cout << addCustomers->custId << endl;
	file.close();
}

void updateCustomer() {
	int searchCustId;
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

			cout << "\nChoose the mark that you want to update:\n";
			cout << "To perform an action, enter " << endl;
			cout << "1 Edit Name" << endl;
			cout << "2 Edit Phone Number" << endl;
			cout << "3 Edit Email" << endl;
			cout << "4 to exit\n" << endl;
			
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
			default:
				cout << "Invalid selection.\n" << endl;
			}
		}
		else {
			current = current->next;
		}
	}
	cout << "Can't find the entered customer ID! " << endl;
	cout << "Reenter search customer ID: " << endl;
	cin >> searchCustId;
}

void searchCustomer() {
	int searchCustId;
	cout << "Enter search customer ID: ";
	cin >> searchCustId;
	int Id;
	string Name, PhoneNo, Email;
	ifstream file("Customer.txt");

	if (file.is_open()) {
		cout << " _______________________________________________________________________________________________________________" << endl;
		cout << " |Customer ID \t\tName \t\t\tPhone Number \t\t\tEmail\t\t\t\t|" << endl;
		//if file not end of the file
		while (!file.eof()) {
			// loop each element to the declared variables
			while (file >> Id >> Name >> PhoneNo >> Email) {
				if (Id == searchCustId) {
					cout << " |" << Id << "\t\t\t" << Name << "\t\t\t" << PhoneNo << "\t\t\t" << Email << " \t\t|" << endl;
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

void viewCustomerDetail() {
	string line;
	int id;
	string name, PhoneNo, Email;
	ifstream file("Customer.txt");

	if (file.is_open()) {
		cout << " _______________________________________________________________________________________________________________" << endl;
		cout << " |Customer ID \t\tName \t\t\tPhone Number \t\t\tEmail\t\t\t\t|" << endl;
		while (!file.eof()) {
			// loop each element to the declared variables
			while (file >> id >> name >> PhoneNo >> Email) {
				cout << " |" << id << "\t\t\t" << name << "\t\t\t" << PhoneNo << "\t\t\t" << Email << " \t\t|" << endl;
			}
		}
		cout << " |______________________________________________________________________________________________________________|" << endl;
		file.close();
	}
	else {
		cout << "Unable to open file!" << endl;
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