// Norman Lew
// CS 360
// Assignment 1
// Spring 2017


// This program will create a phone book.  It will read in the contents of a text file into the phone book.  It will allow
// the user to enter and delete entries from the phone book.  It will also allow the user to search the phone book for contacts and
// to print the phone book.

#include "Contact.h"
#include "PhoneBook.h"
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	// The phonebook
	PhoneBook aPhoneBook;

	// Variables to hold user input
	char menuSelection;
	string name, phoneNumber;

	string lastName;

	// Variable to hold whether a contact was found in the phone book
	bool foundNumber;

	// Open the file and read in the input into the phone book
	ifstream myfile;
	myfile.open("phonebook.txt");
	if (myfile.is_open()) {
		while (!myfile.eof())
		{
			myfile >> name >> lastName >> phoneNumber;
			name = name + " " + lastName;
			aPhoneBook.addContact(name, phoneNumber);
		}
	}
	while (!myfile.eof())
	{
		cin >> name >> lastName >> phoneNumber;
		name = name + " " + lastName;
		aPhoneBook.addContact(name, phoneNumber);
	}
	myfile.close();

	cout << "This is a phone book application." << endl;
	cout << "Please choose an operation" << endl;

	// Ask the user which action they want to do with the phonebook and perform the task
	do {
		cout << "(A)dd | (S)earch | (D)elete | (L)ist | (Q)uit: ";
		cin >> menuSelection;

		// Prompt user for new name and phone number to add to phone book
		if (menuSelection == 'A' || menuSelection == 'a')
		{
			cout << "Enter a name: ";
			cin.ignore();
			getline(cin, name);
			cout << "Enter a phone number: ";
			cin >> phoneNumber;
			aPhoneBook.addContact(name, phoneNumber);
			cout << endl;
		}

		// Prompt user for name to search in phone book
		if (menuSelection == 'S' || menuSelection == 's')
		{
			cout << "Enter a name: ";
			cin.ignore();
			getline(cin, name);
			foundNumber = aPhoneBook.searchForContact(name, phoneNumber);

			if (foundNumber)
			{
				cout << "Phone number: " << phoneNumber << endl;
			} 
			else {
				cout << "Could not find contact." << endl;
			}

			cout << endl;
		}

		// Prompt user for name to delete from phone book
		if (menuSelection == 'D' || menuSelection == 'd')
		{
			cout << "Enter a name: ";
			cin.ignore();
			getline(cin, name);
			aPhoneBook.deleteContact(name);
			cout << endl;
		}

		// Print the contents of the phone book
		if (menuSelection == 'L' || menuSelection == 'l')
		{
			aPhoneBook.listPhoneBook();
			cout << endl;
		}

	} while (menuSelection != 'Q' && menuSelection != 'q');

	cin.get();
	return 0;
}


// I did not utilize the operator overload function for "==" in the Contact class in the main program above, but to show that it works, you can
// comment out the main program above and uncomment out the main program below
/*int main()
{
	Contact a("Norman", "2062959258");
	Contact b("Norman", "2062959258");
	Contact c("Susan", "8392929");
	Contact d("Norman", "999999999");
	Contact e("Maurice", "8392929");

	if (a == b)
	{
		cout << "Contact a and b are the same." << endl;
	}
	else
	{
		cout << "Contact a and b are different." << endl;
	}

	if (b == c)
	{
		cout << "Contact b and c are the same." << endl;
	}
	else
	{
		cout << "Contact b and c are different." << endl;
	}

	if (b == d)
	{
		cout << "Contact b and d are the same." << endl;
	}
	else
	{
		cout << "Contact b and d are different." << endl;
	}

	if (c == e)
	{
		cout << "Contact c and e are the same." << endl;
	}
	else
	{
		cout << "Contact c and e are different." << endl;
	}

	cin.get();
}
*/