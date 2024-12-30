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

   Berikut adalah penjelasan alur algoritma dari program tersebut.
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
Fungsi ini menampilkan menu pilihan untuk pemain yang ingin memilih antara batu, kertas, atau gunting. Menu ini ditampilkan dengan menggunakan angka 1, 2, atau 3.
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





C. GAME Sudoku :

   Berikut adalah penjelasan dari bagian-bagian program dan alurnya:

1. Fungsi cetakGrid
Fungsi ini bertugas untuk menampilkan grid Sudoku dengan format yang jelas dan terstruktur, termasuk pemisah antar blok 3x3. Fungsi ini akan menampilkan grid dengan angka yang ada, dan jika posisi kosong (nilai 0), maka akan ditampilkan sebagai spasi.
Menampilkan angka dengan pemisahan antar kotak 3x3.
Format kotak yang jelas dengan tanda +, |, dan - untuk batas grid.

2. Fungsi langkahValid
Fungsi ini memeriksa apakah langkah yang diambil pemain valid, yaitu apakah angka yang dimasukkan memenuhi aturan Sudoku:
Tidak ada angka yang sama dalam baris yang sama.
Tidak ada angka yang sama dalam kolom yang sama.
Tidak ada angka yang sama dalam kotak 3x3 yang sama.

Fungsi ini melakukan pengecekan untuk setiap kolom, baris, dan kotak 3x3.

3. Fungsi selesaikanSudoku
Fungsi ini adalah implementasi algoritma backtracking untuk menyelesaikan Sudoku. Algoritma ini mencoba mengisi angka secara rekursif dan kembali jika ditemukan kesalahan.
Fungsi ini mencari posisi kosong (bernilai 0) pada grid.
Untuk setiap posisi kosong, mencoba angka dari 1 hingga 9.
Jika angka valid, ia mengisi posisi tersebut dan melanjutkan pencarian.
Jika tidak ada angka yang valid, fungsi ini melakukan backtracking dengan menghapus angka yang telah dimasukkan dan mencoba posisi berikutnya.
Fungsi ini berfungsi sebagai penyelesaian otomatis jika pemain ingin meminta komputer menyelesaikan grid.

4. Fungsi inisialisasiGrid
Fungsi ini menginisialisasi grid dengan angka acak di beberapa posisi. Setiap angka di grid yang dipilih tetap akan disimpan di gridTetap agar pemain tidak dapat mengubah angka-angka tersebut selama permainan.
Angka dimasukkan dengan probabilitas 25% (1 dari 4), dan hanya angka yang valid yang akan dimasukkan.
Angka-angka yang dimasukkan disalin ke dalam gridTetap agar pemain tidak bisa mengubahnya.

5. Fungsi validasiInputAngka
Fungsi ini memvalidasi input angka untuk memastikan bahwa input yang diberikan pemain adalah angka yang valid. Jika input salah (misalnya, memasukkan huruf atau karakter lain), fungsi ini akan membersihkan input dan mengembalikan false.

6. Fungsi mainGame
Fungsi ini adalah inti dari permainan Sudoku. Di sini, pemain akan bermain dengan mengisi grid dan memeriksa apakah langkah yang diambil valid.
Pemain diminta untuk mengisi baris, kolom, dan angka.
Pemain dapat mengetik -1 pada baris untuk meminta komputer menyelesaikan grid secara otomatis menggunakan algoritma backtracking.
Program akan memastikan bahwa pemain hanya bisa mengubah angka yang tidak tetap (angka yang bukan bagian dari gridTetap).
Jika langkah yang dimasukkan tidak valid, program akan meminta pemain untuk mencoba lagi.
Setelah pemain selesai, permainan berakhir.

7. Fungsi playSudoku
Fungsi ini adalah fungsi utama untuk memulai permainan. Di sini, grid diinisialisasi, dan fungsi permainan utama (mainGame) dipanggil untuk memulai sesi permainan. Selain itu, fungsi ini juga mengatur inisialisasi grid acak dan mencetak pesan selamat datang.

Proses Permainan

1. Inisialisasi Grid: Beberapa angka awal diisi secara acak pada grid, dan angka yang tetap disalin ke dalam gridTetap agar tidak bisa diubah oleh pemain.
2. Menampilkan Grid: Program menampilkan grid dengan format yang jelas.
3. Meminta Input Pemain: Pemain diminta untuk memilih baris, kolom, dan angka (dalam rentang 1-9).
4. Validasi Langkah: Langkah pemain diverifikasi berdasarkan aturan Sudoku.
5. Penyelesaian Otomatis: Pemain dapat memilih untuk membiarkan komputer menyelesaikan Sudoku secara otomatis dengan mengetik -1.
6. Perulangan: Proses ini berlanjut hingga permainan selesai.






D. Cari Kata

   1. Inisialisasi Game
Grid ukuran 15x15 diinisialisasi dengan karakter kosong ' '.
Daftar kata yang akan disembunyikan di dalam grid, seperti "ACEH", "AMBON", "BALI", diinisialisasi dalam bentuk vektor string.
Daftar kata disortir menggunakan sort() untuk memungkinkan pencarian binary search.
Peluang untuk menemukan kata diatur pada variabel chances = 5, dan skor awal dimulai dari score = 0.

2. Mengisi Grid dengan Kata dan Huruf Acak
Fungsi fillGridWithRandomLetters:
Kata-kata dari daftar disisipkan secara acak di grid. Setiap kata ditempatkan dengan:
Memilih posisi awal (baris dan kolom) secara acak.
Memilih arah secara acak (horizontal atau vertikal).
Memeriksa apakah kata dapat ditempatkan di posisi tersebut (tanpa konflik).
Jika valid, huruf-huruf kata ditempatkan dalam grid.
Setelah semua kata disisipkan, sisa grid yang kosong diisi dengan huruf-huruf acak (A-Z).

3. Proses Permainan
Gameplay:
Pemain ditampilkan grid dengan kata-kata tersembunyi, skor, dan jumlah kesempatan yang tersisa.
Pemain memasukkan kata yang mereka temukan.
Kata diubah menjadi huruf besar (toupper) agar tidak case-sensitive.
Pencarian kata dilakukan menggunakan binary search untuk efisiensi.
Jika kata ditemukan:
Kata dihapus dari daftar kata yang harus dicari.
Huruf-huruf kata dihapus dari grid (diubah menjadi ' ').
Skor pemain bertambah 10 poin.
Jika kata salah atau sudah ditemukan sebelumnya:
Kesempatan pemain berkurang 1.
Setelah setiap masukan, grid dan informasi permainan diperbarui.

4. Akhir Permainan
Permainan berakhir jika:
Semua kata berhasil ditemukan (pemain menang).
Kesempatan habis (pemain kalah).
Laporan akhir permainan ditampilkan:
Skor akhir pemain.
Kata-kata yang berhasil ditemukan (urut sesuai temuan).
Kata-kata yang belum ditemukan (jika kalah).

5. Bermain Kembali
Setelah permainan selesai, pemain diberikan opsi untuk bermain kembali atau keluar.
Jika memilih bermain lagi (Y/y), game akan diulang dengan grid baru dan daftar kata baru.
Penjelasan Fungsi Utama
printGrid: Menampilkan grid ke layar.
binarySearch: Mencari kata di daftar menggunakan algoritma binary search.
fillGridWithRandomLetters: Mengisi grid dengan kata-kata dari daftar dan huruf acak.
removeWordFromGrid: Menghapus kata dari grid jika pemain menemukannya.
clearScreen: Membersihkan layar untuk tampilan grid yang lebih rapi.
playCariKata: Fungsi utama yang menjalankan seluruh alur permainan, termasuk tampilan, logika permainan, dan interaksi pemain.

fungsi easteregg :


Algoritma program ini menggambarkan animasi visual 3D berbentuk objek rotasi menggunakan karakter ASCII. Berikut adalah alur kerja dan penjelasan langkah-langkah dari program ini:

1. Deklarasi Variabel:

Variabel A, B digunakan untuk sudut rotasi objek.

Variabel i, j digunakan untuk perhitungan sudut (phi dan theta) untuk objek 3D.

Variabel k digunakan untuk perulangan dalam pencetakan karakter.

Array z adalah buffer untuk menyimpan kedalaman (depth) setiap titik, untuk mendukung rendering objek 3D.

Array b digunakan untuk menyimpan karakter ASCII yang akan diprint pada posisi tertentu.



2. Fungsi gotoxy: Fungsi ini menggerakkan posisi kursor ke koordinat tertentu pada layar (x, y) di konsol Windows, untuk membuat animasi lebih mulus.


3. Fungsi easterEgg: Ini adalah bagian utama dari program yang menghasilkan animasi ASCII 3D:

Pembersihan layar: Menggunakan kode \x1b[2J untuk membersihkan layar (meskipun ini tidak selalu berfungsi di semua terminal Windows).

Perulangan Utama:

Program memasuki perulangan tak terhingga (while (true)) untuk terus memperbarui dan menampilkan animasi.

Di dalam perulangan utama, ada dua perulangan for:

Perulangan j (untuk sudut theta, dengan kenaikan 0.07).

Perulangan i (untuk sudut phi, dengan kenaikan 0.02).


Perhitungan Posisi Titik 3D:

Posisi titik 3D dihitung dengan menggunakan rumus trigonometri untuk menentukan posisi objek pada layar 2D berdasarkan rotasi dan kedalaman. Rumus-rumus trigonometri yang digunakan di sini melibatkan sin() dan cos() untuk perhitungan sudut.


Perhitungan Kedalaman (D): Kedalaman titik dihitung untuk membuat efek perspektif. Titik-titik yang lebih dekat ke layar (dengan kedalaman lebih kecil) akan muncul lebih terang.

Luminance: Variabel N dihitung untuk menentukan seberapa terang atau gelapnya titik berdasarkan pencahayaan (luminance). Luminance ini akan dipetakan ke karakter ASCII, dengan karakter yang lebih terang digunakan untuk titik yang lebih terang.

Penyimpanan di Buffer:

Posisi titik pada layar dihitung sebagai x dan y dengan mempertimbangkan kedalaman.

Jika titik berada dalam area layar yang valid (x dan y berada dalam rentang tertentu), maka karakter ASCII yang sesuai dipilih dan disimpan dalam buffer b.

Kedalaman setiap titik disimpan dalam array z untuk mencegah titik yang lebih dekat menutupi titik yang lebih jauh.





4. Mencetak Frame:

Setelah seluruh titik dihitung, kursor dipindahkan kembali ke posisi (0, 0) dengan gotoxy.

Setiap karakter dari buffer b kemudian diprint satu per satu ke layar untuk membentuk gambar 3D dalam format ASCII.

Karakter putchar(k % 80 ? b[k] : 10) digunakan untuk mencetak karakter ke layar, di mana setiap baris terdiri dari 80 karakter (untuk membentuk bentuk kotak).



5. Memperbarui Sudut Rotasi:

Variabel A dan B diperbarui pada setiap iterasi untuk merotasi objek 3D sedikit demi sedikit, menciptakan efek rotasi yang halus.



6. Penundaan Animasi:

Fungsi Sleep(10) digunakan untuk memberi penundaan 10 milidetik di antara setiap frame, memperlambat kecepatan animasi sehingga terlihat lebih mulus.



7. Perulangan Tak Terhingga:

Seluruh proses diulang terus menerus (perulangan tak terbatas), menciptakan animasi berkelanjutan sampai program dihentikan.




Secara keseluruhan, program ini membuat animasi objek 3D berputar yang digambarkan menggunakan karakter-karakter ASCII di layar terminal.








