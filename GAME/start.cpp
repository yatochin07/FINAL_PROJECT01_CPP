#include <iostream>
#include <cstdlib>  
#include <conio.h>  // Header untuk _kbhit() dan _getch()
#include "start.h"

using namespace std;

void showStartScreen() 
{
    system("cls");  // Menggunakan 'cls' untuk membersihkan layar di Windows
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
    system("cls"); // Clear the console screen (di Windows, gunakan cls)
}

void starter() 
{
    showStartScreen();

    // Menampilkan teks sekali tanpa efek kelap-kelip
    showTextOnce();

    // Tunggu sampai pemain menekan Enter
    while (true) 
    {
        // Menggunakan _kbhit() dan _getch() untuk mendeteksi penekanan tombol Enter
        if (_kbhit()) {
            if (_getch() == '\r') { // '\r' adalah karakter untuk Enter di Windows
                startGame();
                break;
            }
        }
    }
}
