#include <iostream>
#include <cstdlib>  
#include <unistd.h>
#include "start.h"

using namespace std;

void showStartScreen() 
{
    system("clear");
    cout << "=======================================" << endl;
    cout << "||      WELCOME TO LOGICAL GAME      ||" << endl;
    cout << "||  University of Amikom Yogyakarta  ||" << endl;
    cout << "||   Developed by : IF04,8th Group   ||" << endl;
    cout << "=======================================" << endl;
}

void showTextOnce() 
{
    // Teks tidak berkedip, hanya ditampilkan sekali
    cout << "\nPress Enter to start..." << flush; // Tampilkan teks sekali tanpa mengganti
}

void startGame() 
{
    system("clear"); // Clear the console screen (di Linux, gunakan clear)
}

void starter() 
{
    showStartScreen();

    // Menampilkan teks sekali tanpa efek kelap-kelip
    showTextOnce();

    // Tunggu sampai pemain menekan Enter
    while (true) 
    {
        // Mengganti getch() dengan cin.get(), yang akan menunggu input
        if (cin.get() == '\n') { // '\n' adalah karakter untuk Enter
            startGame();
            break;
        }
    }
}
