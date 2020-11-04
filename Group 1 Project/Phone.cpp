//
//  Phone.cpp
//  Group 1 Project
//
//  Created by Ed Rutherford on 11/3/20.
//

#include "Phone.h"

//Define Constructors
Phone::Phone()
{
	cout << "[+] Default Phone constructor is running..." << endl;
	model = "undefined";
	releaseYear = 0;
	price = 0.0;
}

Phone::Phone(string theModel, int theYear, double thePrice)
{
	cout << "[+] Param Phone constructor is now running..." << endl;
	model = theModel;
	releaseYear = theYear;
	price = thePrice;
}

//Define Destructor
Phone::~Phone(){}

//Define Public Methods (Getters & Setters)
void Phone::setModel(string theModel)
{
	// validate the input
	if (theModel.length() > 0)
		model = theModel;
	else
		model = "unknown";
}

void Phone::setReleaseYear(int theYear)
{
	// validate the input
	if (theYear > 0)
		releaseYear = theYear;
	else
		releaseYear = 0;
}

void Phone::setPrice(double thePrice)
{
	// validate the input
	if (thePrice > 0.0)
		price = thePrice;
	else
		price = 0.0;
}