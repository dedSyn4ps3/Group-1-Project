//
//  Phone.cpp
//  Group 1 Project
//
//  Created by Ed Rutherford on 11/3/20.
//  Edited 11/20/2020

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

void Phone::displayData()
{
	Device::displayData();

	cout << "\n\nDEVICE SCREEN SIZE: " << screensize.getScreenSize() << endl;            //***Calling the print function through screensize aggregation object***//

	cout << "\nCURRENT INVENTORY: " << inventory << endl;
}