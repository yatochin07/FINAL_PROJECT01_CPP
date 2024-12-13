#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <vector>
#include <limits>
#include "Tic-Tac-Toe/game1.h"
#include "Sudoku/game2.h"
#include "Suit/game3.h"
#include "start.h"

#ifdef _WIN32
    #define CLEAR "CLS"
#else
    #define CLEAR "clear"
#endif

using namespace std;

//starter game
void starter();

// Game Tic-Tac-Toe
void playTicTacToe();

// Game Batu-Gunting-Kertas
void playSuit();

// Game Sudoku
void playSudoku();

int main() {
    int pilihan;
    
    starter();
    
    do {
        system(CLEAR);
        cout << "\n+=====================================+\n";
        cout << "|          PILIH GAME ANDA           |\n";
        cout << "+=====================================+\n";
        cout << "| 1. Tic-Tac-Toe                     |\n";
        cout << "| 2. Sudoku                          |\n";
        cout << "| 3. Batu-Gunting-Kertas             |\n";
        cout << "| 4. Keluar                          |\n";
        cout << "+=====================================+\n";
        cout << "\nMasukkan pilihan Anda: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                playTicTacToe();
                break;
            case 2:
                playSudoku();
                break;
            case 3:
                playSuit();
                break;
            case 4:
                cout << "\nTerima kasih telah bermain!" << endl;
                break;
            default:
                cout << "\nPilihan tidak valid. Coba lagi." << endl;
                cin.ignore();
                cin.get();
                break;
        }
    } while (pilihan != 4);

    return 0;
}
