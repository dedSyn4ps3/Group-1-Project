//
//  Phone.cpp
//  Group 1 Project
//
//  Created by Eddie Sneed on 11/3/20.
//

#include "Phone.h"

Phone::Phone()
{
	cout << "[+] Default Phone constructor is running..." << endl;
	model = "undefined";
	year = 0;
	price = 0.0;
}

Phone::Phone(string model, int year, double price)
{
	cout << "[+] Param Phone constructor is now running..." << endl;
	model = model;
	year = year;
	price = price;
}

Phone::~Phone(){}


