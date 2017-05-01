// Norman Lew
// CS 360
// Assignment 1
// Spring 2017

// This is the implementation file for the Contact class.  It contains the name and phone number for a contact, 
// as well as functions to set and get the contact's paramaters.

#include "Contact.h"
#include <string>
#include <iostream>
using namespace std;

// Default constructor
Contact::Contact()
{
	name = "";
	phoneNumber = "";
}

// Constructor that takes a name and phone number as paramaters and stores them
Contact::Contact(string contactName, string contactPhoneNumber)
{
	name = contactName;
	phoneNumber = contactPhoneNumber;
}

// Sets the name for the contact
void Contact::setName(string contactName)
{
	name = contactName;
}

// Sets the phone number for the contact
void Contact::setPhoneNumber(string contactPhoneNumber)
{
	phoneNumber = contactPhoneNumber;
}

// Returns the name of the contact
string Contact::getName() 
{
	return name;
}

// Returns the phone number of the contact
string Contact::getPhoneNumber()
{
	return phoneNumber;
}

bool Contact::operator==(Contact c)
{
	if (name.compare(c.getName()) == 0 && phoneNumber.compare(c.getPhoneNumber()) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Prints the contact information
void printContact(Contact &c)
{
	cout << c.name << endl;
	cout << c.phoneNumber << endl;
}