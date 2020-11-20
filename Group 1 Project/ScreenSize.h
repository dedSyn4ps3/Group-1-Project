#ifndef SCREENSIZE
#define SCREENSIZE

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// ScreenSize Class

class ScreenSize
{
private:
    string screenSize;

public:
    // Default constructor stores empty string
    ScreenSize(){set("");}

    ScreenSize(string screenSize){set(screenSize);}

    void set(string screenSize)
    {
        this->screenSize = screenSize;
    }

    string getScreenSize() { return screenSize; }
};

#endif