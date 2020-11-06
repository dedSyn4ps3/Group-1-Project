//
//  Plan.h
//  Group 1 Project
//
//  Created by Ed Rutherford 11/3/20.
//

#pragma once

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Plan
{
private:
  string name;
  int contractLength;
  double price;

public:
  //Constructor and Destructor
  Plan();
  Plan(string theName, int theLength, double thePrice);
  ~Plan();
 
  //Getters and Setters
  string getName(){return name;}
  void setName(string theName);
 
  int getContractLength(){return contractLength;}
  void setContractLength(int theLength);
 
  double getPrice(){return price;}
  void setPrice(double thePrice);

  void displayPlanData();
};