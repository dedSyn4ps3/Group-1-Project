//
//  Phone.h
//  Group 1 Project
//
//  Created by Ed Rutherford 11/3/20.
//

#ifndef Phone_h
#define Phone_h


#endif /* Phone_h */

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
	Phone(string model, int year, double price);
	~Phone();
	
	//Getters and Setters
	string getModel(){return model;}
	void setModel(string model);
	
	int getReleaseYear(){return releaseYear;}
	void setReleaseYear(int year);
	
	double getPrice(){return price;}
	void setPrice(double price);
};
