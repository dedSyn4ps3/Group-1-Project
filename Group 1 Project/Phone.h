//
//  Phone.h
//  Group 1 Project
//
//  Created by Ed Rutherford 11/3/20.
//

#pragma once

#include <iostream>
#include <string>
#include <iomanip>

#include "Device.h"

using namespace std;

class Phone : public Device
{
private:
	string plansAvailable;
	int inventory;

public:
	//Constructor and Destructor
	Phone();
	Phone(string thePlans, int theInventory);
	~Phone();
	
	//Getters and Setters
	int getInventory(){return inventory;}
	void setInventory(int theInventory);
	
	string getPlansAvailable(){return plansAvailable;}
	void setPlansAvailable(string thePlans);
	
	void displayPhoneData();
};
