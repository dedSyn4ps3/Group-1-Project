//
//  main.cpp
//  Group 1 Project
//
//  Created by Ed Rutherford on 11/03/20
//  Group Members: Josh Morgan, James Finch, Fray Contreras, Marvin Parks
//  Edited 11/14/2020

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <conio.h>
#include <memory>
#include <Windows.h>

#include "Phone.h"
#include "Plan.h"


using namespace std;

const string phoneFile = "phoneList.csv";
const string planFile = "planList.csv";

void setColor(unsigned short color)
{
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);                
    SetConsoleTextAttribute(hcon, color);                         
}

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

    while (getline(file, line)) 
    {
        cout << line << endl;

    }
}

void createPhoneRecord() {

    // file pointer
    fstream file;

    // creates a new file
    file.open(phoneFile, ios::out | ios::app);

    string name, price;
    int year, inventory;
                                                                //***Previous way of running the program. Does not use Objects***//
    unique_ptr<Phone> phone(new Phone);                         //***New way of running program, which uses a dynamic pointer object of the Phone class***//

    cout << ""; setColor(10); cout << "[+] Please provide the following information to update new phone records[+]" << ""; setColor(7); cout << endl;

    cout << "\nEnter Model Name: ";
    cin.ignore();
    getline(cin, name);
    phone->setModel(name);                                      //***Utilizes the Phone class methods to set & get attributes***//
    file << phone->getModel() << "\t";
    
    
    cout << "Enter Release Year: ";
    cin >> year;
    phone->setReleaseYear(year);
    file << phone->getReleaseYear() << "\t";
    
    cout << "Enter Price: ";
    cin >> price;
    phone->setPrice(price);
    file << phone->getPrice() << "\t";

    cout << "Enter Inventory: ";
    cin >> inventory;
    phone->setInventory(inventory);
    file << phone->getInventory() << endl;

    file.close();

    cout << ""; setColor(10); cout << "[+] You entered the following information >>> \n" << ""; setColor(7); cout << endl;
    phone->displayPhoneData();
}

void readPhoneRecord() {

    fstream file;
    
    if (openFile(file, phoneFile))
    {
       showContent(file);
       file.close();
    }
    else
    {
        cout << ""; setColor(12); cout << "[!]" << ""; setColor(7); cout << "File Open Error" << ""; setColor(12); cout << "[!]" << ""; setColor(7); cout << endl;
    }
}

void createPlanRecord() {

    // file pointer
    fstream file;

    // creates a new file
    file.open(planFile, ios::out | ios::app);

    string name, price;
    int length;
    
    Plan plan;                                   //***Create an object of the Plan class***//

    cout << "[+] Please provide the following information to update new Plan records [+]";

    cout << "\nEnter Plan Name: ";
    cin.ignore();
    getline(cin, name);
    plan.setName(name);
    file << plan.getName() << "\t";

    cout << "\nEnter Contract Length: ";
    cin >> length;
    plan.setContractLength(length);
    file << plan.getContractLength() << "\t";
    
    cout << "Enter Price: ";
    cin >> price;
    plan.setPrice(price);
    file << plan.getPrice() << endl;            //***Use the public methods for the plan object to set and get attributes***//

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
    {
        cout << ""; setColor(12); cout << "[!]" << ""; setColor(7); cout << "File Open Error" << ""; setColor(12); cout << "[!]" << ""; setColor(7); cout << endl;
    }
}



void displayComparison()
{
   //Our phone prices
   cout << "\n[+] OUR PRICES [+]\n" << endl;
   readPhoneRecord();

   //Competitors prices
   cout << "\n\n[-] THEIR PRICES [-]\n" << endl;
   //cout << "\nSamsung Galaxy S20 5G | 2020 | $1199.00" << endl;
   //cout << "iPhone 12 Pro | 2020 | $1429.00" << endl;                       //***This was the old way, not using objects***//
   //cout << "iPhone 12 Mini | 2020 | $875.00" << endl;

   Phone *iphonePro = new Phone("iPhone 12 Pro", 2020, "$1497.00", 120);
   Phone *iphoneMini = new Phone("iPhone 12 Mini", 2020, "$1199.00", 95);
   Phone *galaxy = new Phone("Samsung Galaxy S20 5G", 2020, "1199.00", 62);   //***New way; Utilizes Class Pointers***//

   cout << setw(18) << "Model Name"
        << setw(18) << "Model Year" << setw(8)
        << setw(12) << "Price" << setw(8)
        << setw(18) << "Inventory\n";
   cout << "------------------------------------------------------\n";

   cout << iphonePro->getModel() << "\t" << iphonePro->getReleaseYear() << "\t" << iphonePro->getPrice() << "\t" << iphonePro->getInventory() << endl;
   cout << iphoneMini->getModel() << "\t" << iphoneMini->getReleaseYear() << "\t" << iphoneMini->getPrice() << "\t" << iphoneMini->getInventory() << endl;
   cout << galaxy->getModel() << "\t" << galaxy->getReleaseYear() << "\t" << galaxy->getPrice() << "\t" << galaxy->getInventory() << endl;

   delete iphoneMini;
   delete iphonePro;                   //Clean up the dynamically allocated memory
   delete galaxy;

   //Plan prices
   //Our plan prices
   cout << "\n[+] OUR PLANS [+]\n" << endl;

   cout << setw(18) << "Plan Name"
        << setw(26) << "Contract Length(Years)" << setw(8)
        << setw(12)  << "Price\n";
   cout << "------------------------------------------------------\n";
   
   readPlanRecord();

   //Competitors prices
   cout << "\n[-] THEIR PLANS [-]\n" << endl;

   //cout << "\nPay-As-You-Go: $86.99" << endl;
   //cout << "Family Plan: $179.99" << endl;                            //***Old way of displaying plans; Does not use object array***//
   //cout << "Unlimited Everything: $89.99" << endl;

   const int NUM_PLANS = 3;
   
   Plan plan[NUM_PLANS] = {                                             //***New way using an object array***//
       Plan("Pay-As-You-Go", 0, "$86.99"),
       Plan("Family Unlimited", 2, "$179.99"),
       Plan("Unlimited Everything", 1, "$89.99") 
   };
   
   cout << setw(18) << "Plan Name"
        << setw(26) << "Contract Length(Years)" << setw(8)
        << setw(12) << "Price\n";
   cout << "-------------------------------------------------------\n";

   for (int i = 0; i < NUM_PLANS; i++)
   {
       cout << setw(18) << plan[i].getName();
       cout << setw(26) << plan[i].getContractLength();
       cout << setw(13) << plan[i].getPrice() << endl;
   }
}

int main(int argc, const char * argv[]) {
    int choice;

    int* menuPtr = &choice;

    *menuPtr = 0;

    do                         //***Uses setColor function to modify the color of the text***//
    {
        cout << ""; setColor(10); cout <<"================================================================" << ""; setColor(14); cout << endl;
        cout << "\n" << ""; setColor(14); cout << "<<<" ""; setColor(5); cout << "[+]" << ""; setColor(11); cout << "Group 1" << ""; setColor(8); cout << "|" << ""; setColor(11); cout << "Phones & Plans Console Program"<< ""; setColor(8); cout << "|" << ""; setColor(5); cout << "[+]" << ""; setColor(14); cout << ">>>" << ""; setColor(7); cout << endl;
        cout << "\n\n[ PLEASE SELECT FROM THE FOLLOWING CHOICES ] \n";

        cout << "1. Enter New Phone Model Details (Admins ONLY)\n";
        cout << "2. Enter New Plan Details (Admins ONLY)\n";
        cout << "3. View Phone & Plan Prices vs Our Competitors\n";
        cout << "4. Exit Program\n\n";
        cout << ""; setColor(10); cout << "================================================================" << ""; setColor(7); cout << endl;

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
       cout << ""; setColor(12); cout << "[!]" << ""; setColor(7); cout << "Please Make A Valid Choice" << ""; setColor(12); cout << "[!]" << ""; setColor(7); cout << endl;
        }
    } while (*menuPtr != 4);

    cout << "[+] Press any key to continue..." << endl;
    _getch();                                                                  //***Pause program for user input to quit***//

    return 0;
}
