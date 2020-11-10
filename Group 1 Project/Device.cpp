//
//  Device.cpp
//  Group 1 Project
//
//  Created by Ed Rutherford on 11/9/20.
//

#include "Device.h"
#include <iomanip>

//Define Constructors
Device::Device()
{
	cout << "[+] Default Device constructor is running..." << endl;
	model = "undefined";
	releaseYear = 0;
	price = 0.0;
}

Device::Device(string theModel, int theYear, double thePrice)
{
	cout << "[+] Param Device constructor is now running..." << endl;
	model = theModel;
	releaseYear = theYear;
	price = thePrice;
}

//Define Destructor
Device::~Device(){}

//Define Public Methods (Getters & Setters)
void Device::setModel(string theModel)
{
	// validate the input
	if (theModel.length() > 0)
		model = theModel;
	else
		model = "unknown";
}

void Device::setReleaseYear(int theYear)
{
	// validate the input
	if (theYear > 0)
		releaseYear = theYear;
	else
		releaseYear = 0;
}

void Device::setPrice(string thePrice)
{
	// validate the input
	if (thePrice.length() > 0)
		price = thePrice;
	else
		price = "$0.00";
}
