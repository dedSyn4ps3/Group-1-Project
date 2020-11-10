//
//  Phone.cpp
//  Group 1 Project
//
//  Created by Ed Rutherford on 11/3/20.
//

#include "Phone.h"
#include <iomanip>

//Define Constructors
Phone::Phone()
{
	cout << "[+] Default Phone constructor is running..." << endl;
	plansAvailable = "None";
	inventory = 0;
}

Phone::Phone(string thePlans, int theInventory)
{
	cout << "[+] Param Phone constructor is now running..." << endl;
	plansAvailable = thePlans;
	inventory = theInventory;
}

//Define Destructor
Phone::~Phone(){}

//Define Public Methods (Getters & Setters)
void Phone::setInventory(string theInventory)
{
	// validate the input
	if (theInventory > 0)
		inventory = theInventory;
	else
		inventory = 0;
}

void Phone::setPlansAvailable(int thePlans)
{
	plansAvailable = thePlans;
}

void Phone::displayPhoneData()
{
	cout << "<<< DETAILS >>>" << endl;

	cout << "\n\nModel Name: " << getModel() << endl;

	cout << "\n\nModel Year: " << getReleaseYear() << endl;

	cout << fixed << setprecision(2);
	cout << "\nPhone Price: " << getPrice() << endl;
}