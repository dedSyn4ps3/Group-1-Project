//
//  Phone.cpp
//  Group 1 Project
//
//  Created by Ed Rutherford on 11/3/20.
//

#include "Plan.h"
#include <iomanip>

//Define Constructors
Plan::Plan()
{
	cout << "[+] Default Plan constructor is running..." << endl;
	name = "undefined";
	contractLength = 0;
	price = "$0.00";
}

Plan::Plan(string theName, int theLength, string thePrice)
{
	cout << "[+] Param Plan constructor is now running..." << endl;
	name = theName;
	contractLength = theLength;
	price = thePrice;
}

//Define Destructor
Plan::~Plan() {}

//Define Public Methods (Getters & Setters)
void Plan::setName(string theName)
{
	// validate the input
	if (theName.length() > 0)
		name = theName;
	else
		name = "unknown";
}

void Plan::setContractLength(int theLength)
{
	// validate the input
	if (theLength > 0)
		contractLength = theLength;
	else
		contractLength = 0;
}

void Plan::setPrice(string thePrice)
{
	// validate the input
	if (thePrice.length() > 0)
		price = thePrice;
	else
		price = "$0.00";
}

void Plan::displayPlanData()
{
	cout << "<<< DETAILS >>>" << endl;

	cout << "\n\nPlan Name: " << name << endl;

	cout << "\n\nPlan Length: " << contractLength << endl;

	cout << fixed << setprecision(2);
	cout << "\nPhone Price: " << price << endl;
}