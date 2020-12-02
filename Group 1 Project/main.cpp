//
//  main.cpp
//  Group 1 Project
//
//  Created by Ed Rutherford on 11/03/20
//  Group Members: Josh Morgan, James Finch, Fray Contreras, Marvin Parks
//  Edited 11/25/2020

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <conio.h>
#include <memory>
#include <Windows.h>

#include "Phone.h"
#include "Plan.h"
#include "Tablet.h"


using namespace std;

const string phoneFile = "phoneList.txt";
const string planFile = "planList.txt";
const string tabletFile = "tabletList.txt";

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

    string name, price, screen;
    int year, inventory;
                                                                //***Previous way of running the program. Does not use Objects***//
    unique_ptr<Phone> phone(new Phone);                         //***New way of running program, which uses a dynamic pointer object of the Phone class***//

    cout << ""; setColor(10); cout << "[+] Please provide the following information to update new phone records[+]" << ""; setColor(7); cout << endl;

    cout << "\nEnter Model Name: ";
    cin.ignore();
    getline(cin, name);
    phone->setModel(name);                                      //***Utilizes the Phone class methods to set & get attributes***//
    file << phone->getModel() << "\t\t\t";
    
    cout << "Enter Screen Size: ";
    cin >> screen;
    phone->screensize.set(screen);
    file << phone->screensize.getScreenSize() << "\t\t\t";
    
    cout << "Enter Release Year: ";
    cin >> year;
    phone->setReleaseYear(year);
    file << phone->getReleaseYear() << "\t\t\t";
    
    cout << "Enter Price: ";
    cin >> price;
    phone->setPrice(price);
    file << phone->getPrice() << "\t\t\t\t";

    cout << "Enter Inventory: ";
    cin >> inventory;
    phone->setInventory(inventory);
    file << phone->getInventory() << endl;

    file.close();

    cout << ""; setColor(3); cout << "[+] You entered the following information >>> \n" << ""; setColor(7); cout << endl;
    phone->displayData();
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
    file << plan.getName() << "\t\t\t";

    cout << "\nEnter Contract Length: ";
    cin >> length;
    plan.setContractLength(length);
    file << plan.getContractLength() << "\t\t\t";
    
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

void createTabletRecord() {

    // file pointer
    fstream file;

    // creates a new file
    file.open(tabletFile, ios::out | ios::app);

    string name, price, screen;
    int year, inventory;
                                                                   //***Previous way of running the program. Does not use Objects***//
    unique_ptr<Tablet> tablet(new Tablet);                         //***New way of running program, which uses a dynamic pointer object of the Tablet class***//

    cout << ""; setColor(10); cout << "[+] Please provide the following information to update new tablet records [+]" << ""; setColor(7); cout << endl;

    cout << "\nEnter Model Name: ";
    cin.ignore();
    getline(cin, name);
    tablet->setModel(name);                                      //***Utilizes the Tablet class methods to set & get attributes***//
    file << tablet->getModel() << "\t\t\t";

    cout << "Enter Screen Size: ";
    cin >> screen;
    tablet->screensize.set(screen);
    file << tablet->screensize.getScreenSize() << "\t\t\t";

    cout << "Enter Release Year: ";
    cin >> year;
    tablet->setReleaseYear(year);
    file << tablet->getReleaseYear() << "\t\t\t";

    cout << "Enter Price: ";
    cin >> price;
    tablet->setPrice(price);
    file << tablet->getPrice() << "\t\t\t";

    cout << "Enter Inventory: ";
    cin >> inventory;
    tablet->setInventory(inventory);
    file << tablet->getInventory() << endl;

    file.close();

    cout << ""; setColor(3); cout << "[+] You entered the following information >>> \n" << ""; setColor(7); cout << endl;
    tablet->displayData();
}

void readTabletRecord() {

    fstream file;

    if (openFile(file, tabletFile))
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
   readTabletRecord();

   //Competitors prices
   cout << "\n\n[-] THEIR PRICES [-]\n" << endl;
   //cout << "\nSamsung Galaxy S20 5G | 2020 | $1199.00" << endl;
   //cout << "iPhone 12 Pro | 2020 | $1429.00" << endl;                       //***This was the old way, not using objects***//
   //cout << "iPhone 12 Mini | 2020 | $875.00" << endl;

   Phone *iphonePro = new Phone("iPhone 12 Pro", 2020, "$1497.00", 120, "6.1\"");
   Phone *iphoneMini = new Phone("iPhone 12 Mini", 2020, "$1199.00", 95, "5.4\"");
   Phone *galaxy = new Phone("Samsung Galaxy S20 5G", 2020, "1199.00", 62, "6.2\"");   //***New way; Utilizes Class Pointers***//

   cout << setw(16) << "Model Name"
        << setw(20) << "Screen Size" << setw(8)
        << setw(19) << "Model Year" << setw(23)
        << setw(19) << "Price" << setw(23)
        << setw(24) << "Inventory\n";
   cout << "---------------------------------------------------------------------------------------------------\n";

   cout << iphonePro->getModel() << "\t\t\t" << iphonePro->screensize.getScreenSize() << "\t\t" << iphonePro->getReleaseYear() << "\t\t" << iphonePro->getPrice() << "\t\t" << iphonePro->getInventory() << endl;
   cout << iphoneMini->getModel() << "\t\t\t" << iphoneMini->screensize.getScreenSize() << "\t\t" << iphoneMini->getReleaseYear() << "\t\t" << iphoneMini->getPrice() << "\t\t" << iphoneMini->getInventory() << endl;
   cout << galaxy->getModel() << "\t\t" << galaxy->screensize.getScreenSize() << "\t\t" << galaxy->getReleaseYear() << "\t\t" << galaxy->getPrice() << "\t\t\t" << galaxy->getInventory() << endl;

   delete iphoneMini;
   delete iphonePro;                   //Clean up the dynamically allocated memory
   delete galaxy;

   //Plan prices
   //Our plan prices
   cout << "\n[+] OUR PLANS [+]\n" << endl;

   cout << setw(10) << "Plan Name"
        << setw(30) << "Contract Length(Years)" << setw(8)
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
        << setw(36) << "Contract Length(Years)" << setw(8)
        << setw(12) << "Price\n";
   cout << "-------------------------------------------------------------------\n";

   for (int i = 0; i < NUM_PLANS; i++)
   {
       cout << setw(20) << plan[i].getName();
       cout << setw(30) << plan[i].getContractLength();
       cout << setw(16) << plan[i].getPrice() << endl;
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
        cout << ""; setColor(14); cout << "\n\n[ PLEASE SELECT FROM THE FOLLOWING CHOICES ] \n\n" << ""; setColor(7); cout << endl;

        cout << "1. Enter New Phone Model Details (Admins ONLY)\n";
        cout << "2. Enter New Tablet Model Details (Admins ONLY)\n";
        cout << "3. Enter New Plan Details (Admins ONLY)\n";
        cout << "4. View Phone & Plan Prices vs Our Competitors\n";
        cout << "5. Exit Program\n\n";
        cout << ""; setColor(10); cout << "================================================================" << ""; setColor(7); cout << endl;

        cin >> *menuPtr;

        switch (choice) {
        case 1:
            createPhoneRecord();
            break;
        case 2:
            createTabletRecord();
            break;
        case 3:
            createPlanRecord();
            break;
         case 4:
            displayComparison();
            break;
        case 5:
            break;

        default:
       cout << ""; setColor(12); cout << "[!]" << ""; setColor(7); cout << "Please Make A Valid Choice" << ""; setColor(12); cout << "[!]" << ""; setColor(7); cout << endl;
        }
    } while (*menuPtr != 5);

    cout << "[+] Press any key to continue..." << endl;
    _getch();                                                                  //***Pause program for user input to quit***//

    return 0;
}
