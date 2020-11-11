//
//  Phone.h
//  Group 1 Project
//
//  Created by Ed Rutherford 11/3/20.
//  Edited 11/10/2020

#pragma once

#include <iostream>
#include <string>
#include <iomanip>

#include "Device.h"

using namespace std;

class Phone : public Device
{
private:

	int inventory;

public:
	//Constructor and Destructor
	Phone():Device() { inventory = 0; }
	Phone(string phoneModel, int phoneReleaseYear, string phonePrice, int theInventory):Device(phoneModel, phoneReleaseYear, phonePrice) { inventory = theInventory; }
	~Phone();
	
	//Getters and Setters
	int getInventory(){return inventory;}
	void setInventory(int theInventory);
		
	void displayPhoneData();
};
