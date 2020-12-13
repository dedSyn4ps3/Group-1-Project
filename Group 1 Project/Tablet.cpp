/*
    Tablet.cpp
    Group 1 Project

    Created by Marvin Parks on 11/14/20.
    Edited by Ed Rutherford on 11/25/20.
	Edited by Joshua Morgan on 12/13/20.
*/

#include "Tablet.h"
#include <iomanip>


//Define Destructor
Tablet::~Tablet(){}

//Initialize the inventory variable data
void Tablet::setInventory(int theInventory) {
	if (theInventory > 0)
		inventory = theInventory;
	else
		inventory = 0;
}


void Tablet::displayData()
{
	Device::displayData();

	cout << "\n\nDEVICE SCREEN SIZE: " << screensize.getScreenSize() << endl;            //***Calling the print function through screensize aggregation object***//

	cout << "\nCURRENT INVENTORY: " << inventory << endl;
}
