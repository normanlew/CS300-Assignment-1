// Norman Lew
// CS 360
// Assignment 1
// Spring 2017

// This is the header file for the PhoneBook class.  A PhoneBook contains an array of Contact objects.  It has functions to add and delete
// contacts, search the phone book for a contact, and print the entire phone book.

#include "Contact.h"
#include <string>
using namespace std;

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

class PhoneBook
{
private:
	// The array of contacts is dynamically created
	Contact * listOfContacts;

	// The number of contacts in the phone book
	int size;

	// The total number of contacts that the phone book can contain
	int capacity;

	// Internal function to double the sie of the phone book
	void doubleTheCapacity();

public:
	// Constructor
	PhoneBook();

	// Destructor
	~PhoneBook();

	// Add a contact
	void addContact(string name, string phoneNumber);

	// Delete a contact
	void deleteContact(string name);

	// Search for a contact
	bool searchForContact(string name, string &phoneNumber);

	// Print the phone book
	void listPhoneBook();


};

#endif
