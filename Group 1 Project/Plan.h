//
//  Plan.h
//  Group 1 Project
//
//  Created by Ed Rutherford 11/3/20.
//  Edited on 11/09/2020

#pragma once

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Plan
{
private:
  string name, price;
  int contractLength;
  

public:
  //Constructor and Destructor
  Plan();
  Plan(string theName, int theLength, string thePrice);
  ~Plan();
 
  //Getters and Setters
  string getName(){return name;}
  void setName(string theName);
 
  int getContractLength(){return contractLength;}
  void setContractLength(int theLength);
 
  string getPrice(){return price;}
  void setPrice(string thePrice);

  void displayPlanData();
};