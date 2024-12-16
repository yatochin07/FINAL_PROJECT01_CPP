compile code bash : g++ main.cpp Tic-Tac-Toe/game1.cpp Sudoku/game2.cpp Suit/game3.cpp Cari-Kata/game4.cpp start.cpp credit.cpp easteregg.cpp -o games

structure of code :

    (A) GAME
        - main.cpp (include semua header.h) 
        - start.cpp
        - start.h
        - credit.cpp
        - credit.h
        - easteregg.cpp
        - easteregg.h
        - games.exe (file eksekusi program) 

          (1) Tic-Tac-Toe
                - game1.cpp
                - game1.h
          (2) Sudoku
                - game2.cpp
                - game2.h
          (3) Suit
                - game3.cpp
                - game3.h
          (4) Cari_Kata
                - game4.cpp
                - game4.h

Algoritma
A. GAME Tic-Tac-Toe :

   Program ini adalah implementasi permainan Tic-Tac-Toe dengan dua mode permainan: Pemain vs Pemain dan Pemain vs Komputer. Berikut adalah penjelasan alur algoritma dari program tersebut:

1. Deklarasi dan Inisialisasi

Array square[10] digunakan untuk mewakili papan permainan, dengan indeks 1-9 digunakan untuk posisi yang dapat diisi oleh pemain atau komputer.

Program menggunakan X untuk pemain 1 dan O untuk pemain 2 (atau komputer).


2. Fungsi checkwin

Fungsi ini memeriksa apakah ada pemenang berdasarkan kondisi tertentu. Ada 8 kemungkinan garis kemenangan (3 horizontal, 3 vertikal, 2 diagonal).

Fungsi mengembalikan nilai:

1 jika ada pemenang (sama dengan tiga tanda yang berurutan).

0 jika permainan berakhir seri (semua kotak sudah terisi).

-1 jika permainan masih berlangsung.



3. Fungsi board

Fungsi ini menggambar papan permainan di layar menggunakan posisi yang ada di array square[10].

Papan digambar dengan format yang rapi menggunakan tanda "|" dan garis pemisah.


4. Fungsi isMoveValid

Fungsi ini memeriksa apakah langkah yang diambil valid, yaitu memastikan bahwa posisi yang dipilih oleh pemain tidak terisi oleh tanda X atau O.


5. Algoritma Minimax

Fungsi minimax digunakan untuk memutuskan langkah terbaik ketika komputer bermain. Ini adalah algoritma rekursif yang digunakan dalam permainan dua pemain dengan pengetahuan penuh.

Algoritma ini bekerja dengan dua keadaan:

Maximizing player (komputer, dengan simbol 'X') berusaha memaksimalkan skor.

Minimizing player (pemain, dengan simbol 'O') berusaha meminimalkan skor.


Setiap langkah dievaluasi untuk menentukan mana yang memberikan hasil terbaik bagi pemain yang bergerak.


6. Fungsi bestMove

Fungsi ini digunakan oleh komputer untuk mencari langkah terbaik menggunakan algoritma minimax.

Fungsi ini mencoba semua langkah yang valid, kemudian memanggil fungsi minimax untuk mengevaluasi skor setiap langkah, dan memilih langkah yang menghasilkan skor terbaik.


7. Fungsi playTicTacToe

Fungsi utama yang menjalankan permainan:

Memulai dengan memilih mode permainan: Pemain vs Pemain atau Pemain vs Komputer.

Mengulang permainan dengan mengatur ulang papan dan meminta pemain untuk memilih langkah.

Pemain 1 selalu menggunakan simbol 'X' dan pemain 2 menggunakan simbol 'O'.

Jika mode permainan adalah "Pemain vs Komputer", komputer memilih langkah terbaik menggunakan bestMove.

Setelah setiap langkah, fungsi checkwin dipanggil untuk memeriksa apakah ada pemenang atau jika permainan seri.

Setelah permainan selesai, program menanyakan apakah pemain ingin bermain lagi.



8. Logika Permainan

Setiap giliran pemain, program:

Menggambar papan.

Meminta pemain untuk memilih langkah jika itu giliran pemain, atau komputer jika giliran komputer.

Memvalidasi langkah, memastikan bahwa langkah pemain atau komputer sah.

Memeriksa status permainan untuk melihat apakah ada pemenang atau permainan seri.



9. Pengaturan Ulang untuk Permainan Baru

Setelah setiap permainan, program akan menanyakan apakah pemain ingin bermain lagi. Jika ya, papan akan direset, dan permainan dimulai dari awal.


Ringkasan Proses

1. Pemain memilih mode permainan: Pemain vs Pemain atau Pemain vs Komputer.


2. Jika Pemain vs Komputer, komputer memilih langkah terbaik menggunakan algoritma minimax.


3. Permainan berlanjut dengan menggambar papan dan memvalidasi langkah.


4. Program terus mengecek apakah ada pemenang atau permainan berakhir seri.


5. Setelah permainan selesai, pemain ditanya apakah ingin bermain lagi.









B. GAME Suit :

   Berikut adalah penjelasan alur algoritma dari program tersebut:

1. Fungsi inputPilihanKomputer

Fungsi ini mengembalikan pilihan komputer secara acak. Pilihan komputer berupa "batu", "kertas", atau "gunting", yang dipilih dengan menggunakan angka acak dari rand() % 3. Nilai acak ini menghasilkan angka 0, 1, atau 2, yang masing-masing mewakili pilihan tersebut:

0 → "batu"

1 → "kertas"

2 → "gunting"



2. Fungsi pemenang

Fungsi ini menentukan pemenang berdasarkan aturan permainan:

Jika pilihan pemain dan komputer sama, hasilnya adalah seru (draw).

Jika pemain memilih batu dan komputer memilih gunting, pemain menang, dan seterusnya.


Fungsi ini mengembalikan hasil berupa string yang bisa berisi "Seri", "Player Menang", atau "Komputer Menang".


3. Fungsi pilihan

Fungsi ini menampilkan menu pilihan untuk pemain yang ingin memilih antara batu, kertas, atau gunting. Menu ini ditampilkan dengan menggunakan angka 1, 2, atau 3:

1 → Kertas

2 → Batu

3 → Gunting



4. Fungsi inputPilihanPlayer

Fungsi ini meminta pemain untuk memilih salah satu dari tiga pilihan (kertas, batu, gunting) menggunakan angka 1, 2, atau 3.

Fungsi akan mengembalikan string yang sesuai dengan pilihan pemain ("kertas", "batu", "gunting"), atau jika input tidak valid (angka selain 1, 2, atau 3), maka akan mengembalikan "invalid".


5. Fungsi playSuit

Ini adalah fungsi utama yang menjalankan permainan.

Dimulai dengan menginisialisasi skor untuk pemain dan komputer ke 0.

Pemain diminta untuk memilih pilihan (kertas, batu, atau gunting) dengan memanggil fungsi inputPilihanPlayer.

Komputer memilih secara acak menggunakan fungsi inputPilihanKomputer.

Hasil perbandingan antara pilihan pemain dan komputer dihitung menggunakan fungsi pemenang. Skor dihitung berdasarkan hasil ini:

Jika pemain menang, skor pemain bertambah.

Jika komputer menang, skor komputer bertambah.


Program menampilkan skor sementara dan menanyakan apakah pemain ingin bermain lagi (mainLagi). Jika pemain memilih y atau Y, permainan akan diulang.

Setelah permainan selesai (pemain memilih tidak ingin bermain lagi), program menampilkan skor akhir dan menentukan siapa yang menang berdasarkan skor total:

Jika skor komputer lebih tinggi, maka "Komputer Menang".

Jika skor pemain lebih tinggi, maka "Player Menang".

Jika skor sama, maka hasilnya seri.


Terakhir, program mengucapkan terima kasih kepada pemain yang telah bermain.


6. Alur Permainan

Pemain memilih pilihan (1 untuk kertas, 2 untuk batu, 3 untuk gunting).

Komputer memilih pilihan secara acak.

Hasil ditentukan berdasarkan aturan permainan batu mengalahkan gunting, gunting mengalahkan kertas, dan kertas mengalahkan batu.

Skor sementara ditampilkan setelah setiap putaran.

Pemain dapat memilih untuk bermain lagi atau tidak.











