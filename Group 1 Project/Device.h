//
//  Device.h
//  Group 1 Project
//
//  Created by Ed Rutherford 11/9/20.
//  Edited 11/10/2020

#pragma once

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Device
{
private:
	string model, price;
	int releaseYear;
public:
	//Constructor and Destructor
	Device();
	Device(string theModel, int theYear, string thePrice);
	~Device();
	
	//Getters and Setters
	string getModel(){return model;}
	void setModel(string theModel);
	
	int getReleaseYear(){return releaseYear;}
	void setReleaseYear(int theYear);
	
	string getPrice(){return price;}
	void setPrice(string thePrice);
};
