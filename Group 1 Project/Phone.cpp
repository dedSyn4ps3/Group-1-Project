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
	cout << "<<< DETAILS >>>\n" << endl;

	//cout << "\nModel Name: " << getModel() << endl;

	//cout << "\nModel Year: " << getReleaseYear() << endl;
                                                                        //***Old way of printing data; Not very neat***//
	//cout << fixed << setprecision(2);
	//cout << "\nPhone Price: " << getPrice() << endl;

	//cout << "\n\nCURRENT INVENTORY: " << inventory << endl;

	cout << setw(14) <<"Model Name"
         << setw(10) << "Model Year" << setw(4)
         << setw(8) << "Price\n";
    cout << "-------------------------------------\n";

	cout << setw(14) << getModel();
    cout << setw(8) << getReleaseYear();
    cout << setw(7) << getPrice() << endl;

	cout << "\n\nCURRENT INVENTORY: " << inventory << endl;
}