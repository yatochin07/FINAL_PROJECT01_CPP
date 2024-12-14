#include <iostream>
#include <string>
#include <conio.h>
#include <cstdlib>
#include "start.h"

using namespace std;

void showStartScreen() 
{
    cout << "=======================================" << endl;
    cout << "||      WELCOME TO LOGICAL GAME      ||" << endl;
    cout << "||  University of Amikom Yogyakarta  ||" << endl;
    cout << "||   Developed by : IF04,8th Group   ||" << endl;
    cout << "=======================================" << endl;
    cout << "Press Enter to start..." << endl;
}

void startGame() 
{
    system("CLS"); // Clear the console screen
}

void starter() 
{
    showStartScreen();

    // Wait for the user to press Enter
    while (true) 
    {
        if (getch() == '\r') { // '\r' represents the Enter key
            startGame();
            break;
        }
    }
}
