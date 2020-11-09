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

using namespace std;

class Phone
{
private:
	string model, price;
	int releaseYear;
	

public:
	//Constructor and Destructor
	Phone();
	Phone(string theModel, int theYear, double thePrice);
	~Phone();
	
	//Getters and Setters
	string getModel(){return model;}
	void setModel(string theModel);
	
	int getReleaseYear(){return releaseYear;}
	void setReleaseYear(int theYear);
	
	string getPrice(){return price;}
	void setPrice(string thePrice);

	void displayPhoneData();
};
