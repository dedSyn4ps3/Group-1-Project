//
//  Tablet.h
//  Group 1 Project
//
//  Created by Marvin Parks 11/14/2020.
//  

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
	Tablet(string tabletModel, int tabletReleaseYear, string tabletPrice, int theInventory):Device(tabletModel, tabletReleaseYear, tabletPrice) { inventory = theInventory; }
	~Tablet();
	
	//Getters and Setters
	int getInventory(){return inventory;}
	void setInventory(int theInventory);
		
	void displayTabletData();
};
