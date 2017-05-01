// Norman Lew
// CS 360
// Assignment 1
// Spring 2017

// This is the implementation file for the PhoneBook class.  A PhoneBook contains an array of Contact objects.  It has functions to 
// add and delete contacts, search the phone book for a contact, and print the entire phone book.

#include "PhoneBook.h"
#include <string>
#include <iostream>
using namespace std;

// Constructor
PhoneBook::PhoneBook()
{
	// Set the capacity of the phone book to 10 contacts and dynamically create a new array of 10 contacts
	size = 0;
	capacity = 10;
	listOfContacts = new Contact[capacity];
}

// Destructor
PhoneBook::~PhoneBook()
{
	delete [] listOfContacts;
}

// Internal function to double the size of the phone book
void PhoneBook::doubleTheCapacity()
{
	capacity = capacity * 2;
	Contact * temp = new Contact[capacity];

	for (int i = 0; i < size; i++)
	{
		temp[i].setName(listOfContacts[i].getName());
		temp[i].setPhoneNumber(listOfContacts[i].getPhoneNumber());
	}

	delete [] listOfContacts;
	listOfContacts = temp;
}

// Add a contact
void PhoneBook::addContact(string name, string phoneNumber)
{
	// If the phonebook is full, double the capacity of it
	if (size >= capacity)
	{
		doubleTheCapacity();
	}

	listOfContacts[size].setName(name);
	listOfContacts[size].setPhoneNumber(phoneNumber);
	size++;
}

// Delete a contact
void PhoneBook::deleteContact(string name)
{
	int index = 0;
	bool found = false;

	while (found != true && index < size)
	{
		if (listOfContacts[index].getName().compare(name) == 0)
		{
			found = true;
		}
		else
		{
			index++;
		}
	}

	if (found)
	{
		while (index < (size - 1))
		{
			listOfContacts[index].setName(listOfContacts[index + 1].getName());
			listOfContacts[index].setPhoneNumber(listOfContacts[index + 1].getPhoneNumber());
			index++;
		}
		size--;
	}
}

// Search for a contact
bool PhoneBook::searchForContact(string name, string &phoneNumber)
{
	int index = 0;
	bool found = false;

	while (found != true && index < size)
	{
		if (listOfContacts[index].getName().compare(name) == 0)
		{
			found = true;
			phoneNumber = listOfContacts[index].getPhoneNumber();
		}
		else
		{
			index++;
		}
	}

	if (found)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// Print the phone book
void PhoneBook::listPhoneBook()
{
	for (int i = 0; i < size; i++)
	{
		printContact(listOfContacts[i]);
	}
}

