#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include "game4.h"

using namespace std;

// Fungsi untuk mencetak grid
void printGrid(const vector<string>& grid) {
    for (const string& row : grid) {
        for (char c : row) {
            cout << c << ' ';
        }
        cout << endl;
    }
}

// Fungsi untuk binary search pada daftar kata
bool binarySearch(const vector<string>& words, const string& target) {
    int left = 0, right = words.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (words[mid] == target)
            return true;
        else if (words[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return false;
}

// Fungsi untuk mengacak huruf dalam grid
void fillGridWithRandomLetters(vector<string>& grid, const vector<string>& words) {
    srand(time(0));  // Seed untuk random

    // Menyisipkan kata-kata dalam grid secara acak
    for (const string& word : words) {
        bool placed = false;
        while (!placed) {
            // Pilih posisi acak dan arah (horizontal/vertikal)
            int row = rand() % grid.size();
            int col = rand() % grid[row].size();
            bool horizontal = rand() % 2; // Acak arah, 0 = horizontal, 1 = vertikal

            bool canPlace = true;

            // Periksa apakah kata bisa ditempatkan sesuai arah
            if (horizontal) {
                if (col + word.size() > grid[row].size()) {
                    canPlace = false;  // Kata tidak muat secara horizontal
                } else {
                    // Periksa apakah posisi untuk kata kosong
                    for (int i = 0; i < word.size(); i++) {
                        if (grid[row][col + i] != ' ') {
                            canPlace = false;
                            break;
                        }
                    }
                }
            } else {
                if (row + word.size() > grid.size()) {
                    canPlace = false;  // Kata tidak muat secara vertikal
                } else {
                    // Periksa apakah posisi untuk kata kosong
                    for (int i = 0; i < word.size(); i++) {
                        if (grid[row + i][col] != ' ') {
                            canPlace = false;
                            break;
                        }
                    }
                }
            }

            // Tempatkan kata jika bisa
            if (canPlace) {
                for (int i = 0; i < word.size(); i++) {
                    if (horizontal) {
                        grid[row][col + i] = word[i];
                    } else {
                        grid[row + i][col] = word[i];
                    }
                }
                placed = true;
            }
        }
    }

    // Mengisi sisa grid dengan huruf acak
    for (auto& row : grid) {
        for (auto& cell : row) {
            if (cell == ' ') {
                cell = 'A' + rand() % 26;  // Huruf acak dari A-Z
            }
        }
    }
}

void clearScreen() {
    // Membersihkan layar untuk sistem operasi Windows atau Unix
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Fungsi untuk mengganti huruf pada grid setelah kata ditemukan
void removeWordFromGrid(vector<string>& grid, const string& word) {
    for (int row = 0; row < grid.size(); ++row) {
        for (int col = 0; col < grid[row].size(); ++col) {
            // Mencari kata yang sesuai
            if (grid[row][col] == word[0]) {
                // Cek apakah kata berada dalam arah horizontal
                if (col + word.size() <= grid[row].size()) {
                    bool canRemove = true;
                    for (int i = 0; i < word.size(); ++i) {
                        if (grid[row][col + i] != word[i]) {
                            canRemove = false;
                            break;
                        }
                    }
                    if (canRemove) {
                        // Menghapus kata dari grid
                        for (int i = 0; i < word.size(); ++i) {
                            grid[row][col + i] = ' ';
                        }
                        return;
                    }
                }
                // Cek apakah kata berada dalam arah vertikal
                if (row + word.size() <= grid.size()) {
                    bool canRemove = true;
                    for (int i = 0; i < word.size(); ++i) {
                        if (grid[row + i][col] != word[i]) {
                            canRemove = false;
                            break;
                        }
                    }
                    if (canRemove) {
                        // Menghapus kata dari grid
                        for (int i = 0; i < word.size(); ++i) {
                            grid[row + i][col] = ' ';
                        }
                        return;
                    }
                }
            }
        }
    }
}

void playCariKata() {
    char playAgain;
    do {
    
        // Grid 15x15 dengan huruf acak dan beberapa kata tersembunyi
        vector<string> grid(15, string(15, ' '));  // Membuat grid 15x15 dengan spasi kosong

        // Daftar kata yang harus ditemukan (harus urut untuk binary search)
        vector<string> words = {
            "ACEH", "AMBON", "BALI", "BANDUNG", "JAKARTA", "KUPANG", "MAKASSAR", "MANADO", "MEDAN", "PADANG", "PALANGKA", "SOLO", "SURABAYA", "YOGYAKARTA"
        };

        // Salin daftar kata untuk digunakan nanti
        vector<string> remainingWords = words;

        // Mengurutkan kata-kata untuk binary search
        sort(words.begin(), words.end());

        int chances = 5; // Kesempatan menjawab
        int score = 0;   // Skor pemain

        // Mengisi grid dengan kata-kata dan huruf acak
        fillGridWithRandomLetters(grid, words);

        // Menampilkan tampilan awal permainan
        clearScreen();
        cout << "+-----------------------------------------+\t" << endl;
        cout << "|    SELAMAT DATANG DI GAME CARI KATA     |\t" << endl;
        cout << "+-----------------------------------------+\t" << endl << endl;
        cout << "Temukan kata-kata yang tersembunyi dalam grid berikut : " << endl << endl;

        // Menampilkan grid sekali di awal permainan
        printGrid(grid);

        vector<string> foundWords;  // Daftar kata yang telah ditemukan

        while (chances > 0 && !words.empty()) {
            string guess;
            cout << "\nMasukkan kata yang Anda temukan : ";
            cin >> guess;

            // Konversi ke huruf besar agar case-insensitive
            transform(guess.begin(), guess.end(), guess.begin(), ::toupper);

            // Cek apakah kata ada di daftar menggunakan binary search
            if (binarySearch(words, guess) && find(foundWords.begin(), foundWords.end(), guess) == foundWords.end()) {
                cout << "Benar! Anda menemukan kata = " << guess << endl;
                score += 10;

                // Menambahkan kata yang ditemukan ke daftar kata yang sudah ditemukan
                foundWords.push_back(guess);

                // Hapus kata yang ditemukan dari daftar kata yang harus dicari
                words.erase(remove(words.begin(), words.end(), guess), words.end());

                // Menghapus kata dari grid
                removeWordFromGrid(grid, guess);
            } else {
                cout << "Salah! Kata tidak ditemukan." << endl;
                chances--;
            }

            // Setelah input, refresh layar dan tampilkan status terbaru
            clearScreen();

            // Menampilkan grid setelah perubahan
            printGrid(grid);

            // Menampilkan informasi permainan
            cout << "\nKesempatan tersisa = " << chances << endl;
            cout << "Skor Anda = " << score << endl;
        }

        // Jika semua kata ditemukan atau kesempatan habis
        if (words.empty()) {
            cout << endl;
            cout << "Selamat! Anda telah menemukan semua kata!" << endl;
        } else if (chances == 0) {
            cout << "Kesempatan Anda habis. Permainan selesai." << endl;
        }

        // Menampilkan hasil setelah permainan selesai
        cout << endl;
        cout << "Skor akhir Anda = " << score << endl;

        // Menampilkan kata yang ditemukan (sesuai urutan ditemukan)
        cout << endl;
        cout << "Kata-kata yang Anda temukan (berdasarkan urutan ditemukan) : \n";
        for (const string& word : foundWords) {
            cout << word << " ";
        }
        cout << endl;

        // Jika pemain kalah, tampilkan kata yang belum ditemukan
        if (chances == 0) {
            cout << endl;
            cout << "Kata-kata yang belum ditemukan : \n";
            for (const string& word : words) {
                cout << word << " ";
            }
            cout << endl;
        }

        cout << "Terima kasih telah bermain!" << endl;

        // Tanya apakah pemain ingin bermain lagi
        cout << "\nApakah Anda ingin bermain lagi? (y/n) : ";
        cin >> playAgain;

        // Memastikan jika pemain memilih 'n' atau 'N', permainan akan kembali ke menu utama
        if (playAgain == 'n' || playAgain == 'N') {
            break;  // Menghentikan permainan dan kembali ke menu utama
        }

    } while (playAgain == 'Y' || playAgain == 'y');
}
