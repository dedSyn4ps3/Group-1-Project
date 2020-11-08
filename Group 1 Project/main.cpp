//
//  main.cpp
//  Group 1 Project
//
//  Created by Ed Rutherford on 11/03/20
//  Group Members: Josh Morgan, James Finch, Fray Contreras, Marvin Parks
//  Edited on 11/07/2020

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <conio.h>

#include "Phone.h"
#include "Plan.h"

using namespace std;

const string phoneFile = "phoneList.csv";
const string planFile = "planList.csv";

bool openFile(fstream& file, string name)
{
   file.open(name, ios::in);
   if (file.fail())
      return false;
   else
      return true;
}

void showContent(fstream& file)
{
    string line;

    while (getline(file, line)) //file >> line
    {
        cout << line << endl;

    }
}

void createPhoneRecord() {

    // file pointer
    fstream file;

    // creates a new file
    file.open(phoneFile, ios::out | ios::app);

    string name, year, price;

    cout << "[+] Please provide the following information to update new Phone records >>>";

    cout << "\nEnter Model Name: ";
    cin.ignore();
    getline(cin, name);
    file << name << ",";
    
    cout << "Enter Release Year: ";
    getline(cin, year);
    file << year << ",";
    
    cout << "Enter Price: ";
    getline(cin, price);
    file << price << endl;

    file.close();
}

void readPhoneRecord() {

    fstream file;
    
    if (openFile(file, phoneFile))
    {
       showContent(file);
       file.close();
    }
    else
       cout << "[!] File Open Error!" << endl;
}

void createPlanRecord() {

    // file pointer
    fstream file;

    // creates a new file
    file.open(planFile, ios::out | ios::app);

    string name, length, price;

    cout << "[+] Please provide the following information to update new Plan records >>>";

    cout << "\nEnter Plan Name: ";
    cin.ignore();
    getline(cin, name);
    file << name << ",";

    cout << "\nEnter Contract Length: ";
    getline(cin, length);
    file << length << ",";
    
    cout << "Enter Price: ";
    getline(cin, price);
    file << price << endl;

    file.close();
}

void readPlanRecord() {

    fstream file;
    
    if (openFile(file, planFile))
    {
       showContent(file);
       file.close();
    }
    else
       cout << "[!] File Open Error!" << endl;
}



void displayComparison()
{
   //Our phone prices
   cout << "[+] Our Prices >>> \n" << endl;
   readPhoneRecord();

   //Competitors prices
   cout << "\n[-] Competitors Prices >>> " << endl;
   cout << "\nModel A: $149.00" << endl;
   cout << "Model B: $599.00" << endl;
   cout << "Model C: $875.00" << endl;

   //Plan prices
   //Our plan prices
   cout << "[+] Our Plans >>> \n" << endl;
   readPlanRecord();

   //Competitors prices
   cout << "\n[-] Competitors Plans >>> " << endl;
   cout << "\nPlan A: $36.99" << endl;
   cout << "Plan B: $69.99" << endl;
   cout << "Plan C: $79.99" << endl;
}

int main(int argc, const char * argv[]) {
    int choice;

    int* menuPtr = &choice;

    *menuPtr = 0;

    do
    {
        cout << "====================================================" << endl;
        cout << "\n[+] Group 1 | Phones & Plans Console Program | >>>";
        cout << "\n[Please select from the following choices]: \n";

        cout << "1. Enter New Phone Model Details (Admins ONLY)\n";
        cout << "2. Enter New Plan Details (Admins ONLY)\n";
        cout << "3. View Phone & Plan Prices vs Our Competitors\n";
        cout << "4. Exit Program\n\n";
        cout << "====================================================" << endl;

        cin >> *menuPtr;

        switch (choice) {
        case 1:
            createPhoneRecord();
            break;
        case 2:
            createPlanRecord();
            break;
         case 3:
            displayComparison();
            break;
        case 4:
            break;

        default:
            cout << "[!] Please make valid selection...";
        }
    } while (*menuPtr != 4);

    cout << "[+] Press any key to continue..." << endl;
    _getch();

    return 0;
}
