//
//  Phone.cpp
//  Group 1 Project
//
//  Created by Ed Rutherford on 11/3/20.
//  Edited 11/10/2020

#include "Phone.h"
#include <iomanip>


//Define Destructor
Phone::~Phone(){}

//Define Public Methods (Getters & Setters)
void Phone::setInventory(int theInventory)
{
	// validate the input
	if (theInventory > 0)
		inventory = theInventory;
	else
		inventory = 0;
}


void Phone::displayPhoneData()
{
	cout << "<<< DETAILS >>>" << endl;

	cout << "\nModel Name: " << getModel() << endl;

	cout << "\nModel Year: " << getReleaseYear() << endl;

	cout << fixed << setprecision(2);
	cout << "\nPhone Price: " << getPrice() << endl;

	cout << "\n\nCURRENT INVENTORY: " << inventory << endl;
}