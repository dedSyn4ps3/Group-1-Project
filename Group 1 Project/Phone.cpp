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

Phone::Phone(string model, int releaseYear, double price)
{
	cout << "[+] Param Phone constructor is now running..." << endl;
	model = model;
	releaseYear = releaseYear;
	price = price;
}

//Define Destructor
Phone::~Phone(){}

//Define Public Methods (Getters & Setters)
void Phone::setModel(string model)
{
	// validate the input
	if (model.length() > 0)
		model = model;
	else
		model = "unknown";
}

void Phone::setReleaseYear(int releaseYear)
{
	// validate the input
	if (releaseYear > 0)
		releaseYear = releaseYear;
	else
		releaseYear = 0;
}

void Phone::setPrice(double price)
{
	// validate the input
	if (price > 0.0)
		price = price;
	else
		price = 0.0;
}