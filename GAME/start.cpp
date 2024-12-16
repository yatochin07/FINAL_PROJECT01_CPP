#include <iostream>
#include <cstdlib>  
#include <conio.h>  
#include "start.h"

using namespace std;

void showStartScreen() 
{
    system("cls");  
    cout << "=======================================" << endl;
    cout << "||      WELCOME TO LOGICAL GAME      ||" << endl;
    cout << "||  University of Amikom Yogyakarta  ||" << endl;
    cout << "||   Developed by : IF04,8th Group   ||" << endl;
    cout << "=======================================" << endl;
}

void showTextOnce() 
{
    cout << "\nPress Enter to start..." << flush; 
}

void startGame() 
{
    system("cls"); 
}

void starter() 
{
    showStartScreen();

    showTextOnce();

    while (true) 
    {
        if (_kbhit()) 
        {
            if (_getch() == '\r') 
            { 
                startGame();
                break;
            }
        }
    }
}
