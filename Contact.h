// Norman Lew
// CS 360
// Assignment 1
// Spring 2017

// This is the header file for the Contact class.  It contains the name and phone number for a contact, 
// as well as functions to set and get the contact's paramaters.

#include <string>
using namespace std;

#ifndef CONTACT_H
#define CONTACT_H

class Contact
{
private:
	
	// Variables to hold the contact information
	string name;
	string phoneNumber;

public:

	// Constructors for the contact
	Contact();
	Contact(string contactName, string contactPhoneNumber);

	// Set the name for the contact
	void setName(string contactName);

	// Set the phone number for the contact
	void setPhoneNumber(string contactPhoneNumber);

	// Get the name of the contact
	string getName();

	// Get the phone number of the contact
	string getPhoneNumber();

	// Prints the contact information
	friend void printContact(Contact &c);

	// Checks to see if one contact is the same as another
	bool operator==(Contact);
};

#endif