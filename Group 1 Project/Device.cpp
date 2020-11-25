//
//  Device.cpp
//  Group 1 Project
//
//  Created by Ed Rutherford on 11/9/20.
//  Edited 11/20/2020

#include "Device.h"
#include <iomanip>

//Define Constructors
Device::Device()
{
	cout << "[+] Default Device constructor is running..." << endl;
	model = "undefined";
	releaseYear = 0;
	price = "$0.00";
}

Device::Device(string theModel, int theYear, string thePrice, string theScreenSize)
{
	cout << "[+] Param Device constructor is now running..." << endl;
	model = theModel;
	releaseYear = theYear;
	price = thePrice;

	screensize.set(theScreenSize);
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
		model = "Unknown";
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

void Device::displayPhoneData()
{
	//cout << "<<< DETAILS >>>\n" << endl;

	//cout << "\nModel Name: " << getModel() << endl;

	//cout << "\nModel Year: " << getReleaseYear() << endl;
																		//***Old way of printing data; Not very neat***//
	//cout << fixed << setprecision(2);
	//cout << "\nPhone Price: " << getPrice() << endl;

	//cout << "\n\nCURRENT INVENTORY: " << inventory << endl;

	cout << setw(18) << "Model Name"
		 << setw(18) << "Model Year" << setw(4)
		 << setw(12) << "Price\n";
	cout << "---------------------------------------------------\n";

	cout << setw(18) << getModel();
	cout << setw(18) << getReleaseYear();
	cout << setw(13) << getPrice() << endl;
}
