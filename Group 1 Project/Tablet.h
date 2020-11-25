//
//  Tablet.h
//  Group 1 Project
//
//  Created by Marvin Parks 11/14/2020.
//  Edited by Ed Rutherford on 11/25/20.

#pragma once

#include <iostream>
#include <string>
#include <iomanip>

#include "Device.h"

using namespace std;

class Tablet : public Device
{
private:

	int inventory;

public:
	//Constructor and Destructor
	Tablet():Device() { inventory = 0; }
	Tablet(string tabletModel, int tabletReleaseYear, string tabletPrice, int theInventory, string tabletScreenSize):Device(tabletModel, tabletReleaseYear, tabletPrice, tabletScreenSize) { inventory = theInventory; }
	~Tablet();
	
	//Getters and Setters
	int getInventory(){return inventory;}
	void setInventory(int theInventory) { inventory = theInventory; }
		
	void displayTabletData();
};
