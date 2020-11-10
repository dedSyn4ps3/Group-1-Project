//
//  Phone.cpp
//  Group 1 Project
//
//  Created by Ed Rutherford on 11/3/20.
//

#include "Phone.h"
#include <iomanip>

//Define Constructors
Phone::Phone():Device()
{
	cout << "[+] Default Phone constructor is running..." << endl;
	inventory = 0;
}

Phone::Phone(string phoneModel, int phoneReleaseYear, string phonePrice, int theInventory):Device(phoneModel, phoneReleaseYear, phonePrice)
{
	cout << "[+] Param Phone constructor is now running..." << endl;
	inventory = theInventory;
}

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

	cout << "\n\nModel Name: " << getModel() << endl;

	cout << "\n\nModel Year: " << getReleaseYear() << endl;

	cout << fixed << setprecision(2);
	cout << "\nPhone Price: " << getPrice() << endl;
}