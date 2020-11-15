//
//  Tablet.cpp
//  Group 1 Project
//
//  Created by Marvin Parks on 11/14/20.
//  

#include "Tablet.h"
#include <iomanip>


//Define Destructor
Tablet::~Tablet(){}

//Define Public Methods (Getters & Setters)
void Tablet::setInventory(int theInventory)
{
	// validate the input
	if (theInventory > 0)
		inventory = theInventory;
	else
		inventory = 0;
}


void Tablet::displayTabletData()
{
	cout << setw(18) << "Model Name"
         << setw(18) << "Model Year" << setw(4)
         << setw(12)  << "Price\n";
    cout << "-------------------------------------\n";

	cout << setw(18) << getModel();
    cout << setw(18)  << getReleaseYear();
    cout << setw(13)  << getPrice() << endl;

	cout << "\n\nCURRENT INVENTORY: " << inventory << endl;
}
