//
//  Phone.h
//  Group 1 Project
//
//  Created by Ed Rutherford 11/3/20.
//

#pragma once

#include <iostream>
#include <string>

using namespace std;

class Phone
{
private:
	string model;
	int releaseYear;
	double price;

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
	
	double getPrice(){return price;}
	void setPrice(double thePrice);
};
