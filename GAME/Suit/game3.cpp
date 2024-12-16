#include <iostream>
#include <cstdlib>
#include <cstdlib>
#include <ctime>
#include "game3.h"
using namespace std;

//Fungsi input dari komputer
string inputPilihanKomputer() 
{
    int pilihanRandom = rand() % 3; //menghasilkan angka acak 0, 1, atau 2
    if (pilihanRandom == 0) 
    {
        return "batu"; 
    } 
    if (pilihanRandom == 1) 
    {
        return "kertas"; 
    }
    return "gunting"; 
    
}

//Fungsi menentukan pemenang
string pemenang(string player, string komputer) 
{
    if (player == komputer) 
    {
        return "Seri";
    }
    if ((player == "batu" && komputer == "kertas") || (player == "kertas" && komputer == "batu") 
        || (player == "gunting" && komputer == "kertas")) 
    {
        return "Player Menang";
    }
    return "Komputer Menang";
}

//Fungsi menampilkan pilihan
void pilihan() 
{
    cout << "\n+======== Pilihan ========+" << endl;
    cout << "| 1. Kertas               |" << endl;
    cout << "| 2. Batu                 |" << endl;
    cout << "| 3. Gunting              |" << endl;
    cout << "+=========================+" << endl;
}

//Fungsi input player
string inputPilihanPlayer() 
{
    int pilihanPemain;
    cout << "\n\tMasukkan pilihan (1/2/3)\t: ";
    cin >> pilihanPemain;
    
    switch (pilihanPemain) {
        case 1:
            return "kertas";
        case 2:
            return "batu";
        case 3: 
            return "gunting";
        default:
            return "invalid";
    }
}


void playSuit() 
{
    system("cls");
    srand(static_cast<unsigned int>(time(0))); //inisialisasi angka acak

    int skorPlayer = 0;
    int skorKomputer = 0;

    char mainLagi;

    do 
    {
        pilihan();
        string pilihanPlayer = inputPilihanPlayer();
        cout << "\n\tPilihan Anda\t\t\t: " << pilihanPlayer << endl;

        //Validasi input
        if (pilihanPlayer == "invalid") {
            system("cls");
            cout << "\nPilihan tidak valid, Silahkan coba lagi !!" << endl;
            cout << "\n------------------------------------------" << endl;
            continue;
        }

        string pilihanKomputer = inputPilihanKomputer();
        cout << "\n\tKomputer memilih\t\t: " << pilihanKomputer << endl;

        string hasil = pemenang(pilihanPlayer, pilihanKomputer);
        cout << "\n\tHasil\t\t\t\t: " << hasil << endl;

        if (hasil == "Player Menang") 
        {
            skorPlayer++;
        } else if (hasil == "Komputer Menang") 
        {
            skorKomputer++;
        }
        cout << "\n\tSkor sementara : " << endl;
        cout << "\tPlayer " << skorPlayer << " - " << skorKomputer << " Komputer" << endl;

        cout << "\n\tIngin Bermain Lagi? (y/n)\t: ";
        cin >> mainLagi;

        if (mainLagi == 'y' || 'Y') 
        {
            system("cls");
        }

    } 
    while (mainLagi == 'y' || mainLagi == 'Y');
    cout << "\n\tSkor Akhir :" << endl;
    cout << "Player " << skorPlayer << " - " << skorKomputer << " Komputer" << endl;
    
    if (skorKomputer > skorPlayer) 
    {
       cout << "Pemenang adalah Komputer." << endl;
    }
    if (skorPlayer > skorKomputer) 
    {
        cout << "Pemenang adalah Player." << endl;
    }
    if (skorPlayer == skorKomputer) 
    {
        cout << "Hasil adalah seri." << endl;
    }
    cout << "\nTerima Kasih Sudah Bermain." << endl;
}