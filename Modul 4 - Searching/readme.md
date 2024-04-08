# <h1 align="center">Laporan Praktikum Modul Algoritma Searching</h1>

<p align="center">Muhammad Azka</p>

## Features

- [Dasar Teori](#dasar-teori)
- [Guided](#guided)
- [Unguided](#unguided)
- [Kesimpulan](#kesimpulan)
- [Referensi](#referensi)

## Dasar Teori

**A. Pendahuluan**

Pencarian (searching) merupakan operasi fundamental dalam ilmu komputer yang digunakan untuk menemukan suatu elemen tertentu dalam sekumpulan data. Algoritma searching berperan penting dalam berbagai aplikasi, seperti mesin pencari, sistem basis data, algoritma pengurutan, dan permainan.

**B. Klasifikasi Algoritma Searching**

Algoritma searching dapat diklasifikasikan berdasarkan beberapa kriteria, antara lain:

* **Struktur data:** Algoritma searching dapat dirancang untuk struktur data linear (seperti array) atau struktur data non-linear (seperti pohon, graf).
* **Teknik pencarian:** Algoritma searching dapat menggunakan teknik pencarian brute-force, divide-and-conquer, atau heuristic.
* **Informasi awal:** Algoritma searching dapat bekerja dengan informasi awal minimal (seperti data tidak terurut) atau dengan informasi awal lebih banyak (seperti data terurut).

**C. Algoritma Searching Umum**

1. **Pencarian Sequential (Sequential Search)**

    Pencarian sequential adalah algoritma searching paling sederhana yang bekerja dengan cara memeriksa setiap elemen dalam data secara berurutan hingga elemen yang dicari      ditemukan. Algoritma ini memiliki kompleksitas waktu rata-rata dan terburuk O(n), di mana n adalah jumlah elemen dalam data [1].

2. **Pencarian Biner (Binary Search)**

    Pencarian biner adalah algoritma searching yang lebih efisien daripada pencarian sequential. Algoritma ini hanya bekerja pada data yang terurut dan menggunakan teknik       divide-and-conquer untuk mempersempit ruang pencarian. Pencarian biner memiliki kompleksitas waktu rata-rata dan terbaik O(log n) [2].

3. **Pencarian Interpolasi (Interpolation Search)**

    Pencarian interpolasi adalah variasi dari pencarian biner yang memanfaatkan distribusi data untuk memperkirakan lokasi data yang dicari. Algoritma ini lebih efisien         daripada pencarian biner untuk data yang tersebar secara merata. Pencarian interpolasi memiliki kompleksitas waktu rata-rata O(log log n) [3].

4. **Pencarian Lompat (Jump Search)**

    Pencarian lompat adalah variasi lain dari pencarian biner yang membagi data menjadi beberapa blok dan kemudian melakukan pencarian biner pada blok-blok tersebut.            Algoritma ini lebih efisien daripada pencarian biner untuk data yang sangat besar. Pencarian lompat memiliki kompleksitas waktu rata-rata O(√n) [4].

**D. Algoritma Searching untuk Struktur Data Non-Linear**

1. **Pencarian Kedalaman Pertama (Depth-First Search - DFS)**

    Pencarian kedalaman pertama adalah algoritma searching yang menjelajahi struktur data dengan cara mengunjungi semua node pada satu level sebelum beralih ke level            berikutnya. Algoritma ini memiliki kompleksitas waktu O(V + E), di mana V adalah jumlah node dan E adalah jumlah edge dalam struktur data [5].

2. **Pencarian Lebar Pertama (Breadth-First Search - BFS)**

    Pencarian lebar pertama adalah algoritma searching yang menjelajahi struktur data dengan cara mengunjungi semua node pada satu level secara berurutan sebelum beralih ke     level berikutnya. Algoritma ini memiliki kompleksitas waktu O(V + E), di mana V adalah jumlah node dan E adalah jumlah edge dalam struktur data [5].

**E. Faktor yang Mempengaruhi Pemilihan Algoritma Searching**

Pemilihan algoritma searching yang tepat tergantung pada beberapa faktor, antara lain:

* **Struktur data:** Algoritma searching tertentu dirancang untuk struktur data tertentu.
* **Ukuran data:** Algoritma searching yang lebih efisien untuk data besar mungkin tidak efisien untuk data kecil.
* **Informasi awal:** Algoritma searching yang membutuhkan informasi awal lebih banyak mungkin lebih efisien daripada algoritma searching yang tidak membutuhkan informasi awal.
* **Presisi:** Beberapa algoritma searching dapat menemukan elemen yang paling mendekati elemen yang dicari jika elemen yang dicari tidak ada dalam data.

## Guided

### 1. Buatlah sebuah project dengan menggunakan sequential search sederhana untuk melakukan pencarian data.

```C++
#include <iostream>
using namespace std;

int main(){
    int n = 10;
    int data[n] = {9, 4, 1, 7, 5, 12, 4, 13, 4, 10};
    int cari = 10;
    bool ketemu = false;
    int i;

    // algoritma Sequential Search
    for (i = 0; i < n; i++){
        if(data[i] == cari){
            ketemu = true;
            break;
        }
    }
    cout << "\n\t Program Sequential Search Sederhana\n" << endl;
    cout << " data: {9, 4, 1, 7, 5, 12, 4, 13, 4, 10}" << endl;

    if (ketemu){
        cout << "\n angka "<< cari << " ditemukan pada indeks ke-" << i << endl;
    } else {
        cout << cari << " tidak dapat ditemukan pada data." << endl;
    }
    return 0;

}
```

## Interpretasi dan Analisis Kompleksitas Waktu dan Ruang dari Kode Algoritma Sequential Search

**Interpretasi:**

Kodingan di atas menunjukkan implementasi algoritma Sequential Search untuk mencari nilai tertentu dalam array data. Algoritma ini bekerja dengan cara mengiterasi setiap elemen dalam array dan membandingkannya dengan nilai yang dicari. Jika nilai yang dicari ditemukan, maka proses pencarian dihentikan dan program akan menampilkan indeks di mana nilai tersebut ditemukan. Jika nilai yang dicari tidak ditemukan, maka program akan menampilkan pesan bahwa nilai tersebut tidak ditemukan.

**Analisis Kompleksitas Waktu:**

Dalam algoritma Sequential Search, waktu yang dibutuhkan untuk menemukan nilai yang dicari bergantung pada posisi nilai tersebut dalam array. Pada kasus terburuk, algoritma ini perlu mengiterasi seluruh array, yang berarti kompleksitas waktunya adalah O(n), di mana n adalah jumlah elemen dalam array.

**Analisis Kompleksitas Ruang:**

Algoritma Sequential Search hanya menggunakan memori konstan untuk menyimpan variabel-variabel yang digunakan dalam program. Ini berarti kompleksitas ruangnya adalah O(1), dan tidak bergantung pada jumlah elemen dalam array.

**Kesimpulan:**

Algoritma Sequential Search adalah algoritma pencarian yang sederhana dan mudah dipahami. Kompleksitas waktunya adalah O(n) pada kasus terburuk, dan kompleksitas ruangnya adalah O(1). Algoritma ini cocok digunakan untuk array data yang kecil, di mana waktu pencarian yang cepat tidak menjadi prioritas utama.

### 2. Buatlah sebuah project untuk melakukan pencarian data dengan menggunakan Binary Search

```C++
#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

int cari;

void selection_sort(int data[], int length) {
    int temp, min, i, j;
    for(i = 0; i < length; i++) {
        min = i;
        for(j = i + 1; j < length; j++) {
            if(data[j] < data[min]) {
                min=j;
            }
        }
        temp = data[i];
        data[i] = data[min];
        data[min] = temp;
    }
}

void binarysearch(int data[], int length) {
    int awal, akhir, tengah, b_flag = 0;
    awal = 0;
    akhir = length - 1;
    while (b_flag == 0 && awal <= akhir) {
        tengah = (awal + akhir) / 2;
        if(data[tengah] == cari) {
            b_flag = 1;
            break;
        } else if(data[tengah] < cari)
            awal = tengah + 1;
        else
            akhir = tengah - 1;
    }
    if(b_flag == 1)
        cout<<"\n Data ditemukan pada index ke- " << tengah << endl;
    else
        cout<<"\n Data tidak ditemukan\n";
}

int main() {
    int data[7] = {1, 8, 2, 5, 4, 9, 7};
    int length = sizeof(data) / sizeof(data[0]);

    cout << "\t BINARY SEARCH " << endl;
    cout << "\n Data : ";
    // Tampilkan data awal
    for(int x = 0; x<7; x++)
        cout << setw(3) << data[x];
    cout << endl;

    cout << "\n Masukkan data yang ingin Anda cari : ";
    cin >> cari;

    cout << "\n Data diurutkan : ";
    // Urutkan data dengan selection sort
    selection_sort(data, length);

    // Tampilkan data setelah diurutkan
    for(int x = 0; x < 7; x++)
        cout << setw(3) << data[x];
    cout << endl;

    binarysearch(data, length);
    _getche();
    return EXIT_SUCCESS;
}
```

## Interpretasi dan Analisis Kompleksitas Waktu dan Ruang dari Kode Algoritma

**Interpretasi:**

Kodingan di atas menunjukkan implementasi algoritma Binary Search untuk mencari nilai tertentu dalam array data yang telah diurutkan. Algoritma ini bekerja dengan cara membagi array menjadi dua bagian secara berulang, dan membandingkan nilai yang dicari dengan nilai tengah array. Jika nilai yang dicari ditemukan, maka proses pencarian dihentikan dan program akan menampilkan indeks di mana nilai tersebut ditemukan. Jika nilai yang dicari tidak ditemukan, maka program akan menampilkan pesan bahwa nilai tersebut tidak ditemukan.

**Analisis Kompleksitas Waktu:**

Dalam algoritma Binary Search, waktu yang dibutuhkan untuk menemukan nilai yang dicari bergantung pada posisi nilai tersebut dalam array. Pada kasus rata-rata, algoritma ini hanya perlu melakukan log2(n) perbandingan, di mana n adalah jumlah elemen dalam array. Ini berarti kompleksitas waktunya adalah O(log n). Pada kasus terburuk, algoritma ini perlu melakukan n perbandingan, yang berarti kompleksitas waktunya adalah O(n).

**Analisis Kompleksitas Ruang:**

Algoritma Binary Search hanya menggunakan memori konstan untuk menyimpan variabel-variabel yang digunakan dalam program. Ini berarti kompleksitas ruangnya adalah O(1), dan tidak bergantung pada jumlah elemen dalam array.

**Kesimpulan:**

Algoritma Binary Search adalah algoritma pencarian yang efisien untuk array data yang telah diurutkan. Kompleksitas waktunya adalah O(log n) pada kasus rata-rata, dan kompleksitas ruangnya adalah O(1). Algoritma ini cocok digunakan untuk array data yang besar, di mana waktu pencarian yang cepat menjadi prioritas utama.

## Unguided

### 1. Buatlah sebuah program untuk mencari sebuah huruf pada sebuah kalimat yang sudah di input dengan menggunakan Binary Search!

```C++
#include <iostream>
#include <string>
#include <cctype> // Untuk tolower()

using namespace std;

void binarysearch(const string& kalimat, char cari) {
    int index = -1; // Indeks karakter yang dicari
    int length = kalimat.length();

    // Konversi karakter cari menjadi lowercase
    cari = tolower(cari);

    // Iterasi melalui string untuk mencari karakter
    for (int i = 0; i < length; ++i) {
        if (tolower(kalimat[i]) == cari) {
            index = i;
            break; // Keluar dari loop jika karakter ditemukan
        }
    }

    if (index != -1)
        cout << "\nKarakter '" << cari << "' ditemukan pada index ke-" << index << endl;
    else
        cout << "\nKarakter '" << cari << "' tidak ditemukan dalam kalimat.\n";
}

int main() {
    string kalimat;

    cout << "\t BINARY SEARCH " << endl;
    cout << "\nMasukkan kalimat: ";
    getline(cin, kalimat); // Input sebuah kalimat

    char cari;
    cout << "Masukkan karakter yang ingin Anda cari dalam kalimat: ";
    cin >> cari;

    binarysearch(kalimat, cari);

    return 0;
}
```

#### Output:

![image](https://github.com/dkumui/Struktur-Data-Assignment/assets/91511212/3591b1b5-f3e9-4f50-8ac5-2cf9fea67d97)

## Interpretasi dan Langkah-langkah Kode Algoritma Binary Search untuk Kalimat

**Interpretasi:**

Kodingan di atas menunjukkan implementasi algoritma Binary Search untuk mencari karakter tertentu dalam string (kalimat). Algoritma ini bekerja dengan cara mengonversi string dan karakter yang dicari ke huruf kecil, dan kemudian membagi string menjadi dua bagian secara berulang. Algoritma ini membandingkan karakter yang dicari dengan karakter di tengah string. Jika karakter yang dicari ditemukan, maka proses pencarian dihentikan dan program akan menampilkan indeks di mana karakter tersebut ditemukan. Jika karakter yang dicari tidak ditemukan, maka program akan menampilkan pesan bahwa karakter tersebut tidak ditemukan.

**Langkah-langkah:**

1. **Memasukkan Kalimat:**
    * Pengguna diminta untuk memasukkan kalimat yang ingin dicari karakternya.
    * Kalimat disimpan dalam variabel `kalimat`.

2. **Memasukkan Karakter yang Dicari:**
    * Pengguna diminta untuk memasukkan karakter yang ingin dicarinya dalam kalimat.
    * Karakter disimpan dalam variabel `cari`.

3. **Konversi ke Huruf Kecil:**
    * Baik variabel `kalimat` maupun `cari` dikonversi ke huruf kecil menggunakan fungsi `tolower()`.
    * Hal ini dilakukan untuk memastikan perbandingan yang tidak peka huruf besar/kecil.

4. **Inisialisasi Variabel:**
    * Variabel `index` diinisialisasi dengan nilai -1.
    * Variabel `length` menampung panjang kalimat.

5. **Iterasi dan Perbandingan:**
    * Loop `for` digunakan untuk mengiterasi melalui string `kalimat`.
    * Di dalam loop, karakter di posisi `i` dikonversi ke huruf kecil menggunakan `tolower()`.
    * Jika karakter di posisi `i` sama dengan `cari`, maka:
        * Nilai `index` diperbarui dengan nilai `i`.
        * Loop `for` dihentikan menggunakan `break`.

6. **Tampilan Hasil:**
    * Jika `index` tidak sama dengan -1 (karakter ditemukan), maka:
        * Program menampilkan pesan bahwa karakter ditemukan dan indeksnya.
    * Jika `index` sama dengan -1 (karakter tidak ditemukan), maka:
        * Program menampilkan pesan bahwa karakter tidak ditemukan.

**Kesimpulan:**

Algoritma Binary Search ini memungkinkan pencarian karakter dalam string dengan efisiensi waktu O(log n), di mana n adalah panjang string. Algoritma ini bermanfaat untuk mencari karakter dalam teks, data, atau string lainnya.

#### Full Code Screenshot:

![image](https://github.com/dkumui/Struktur-Data-Assignment/assets/91511212/c7c6130e-780f-4c21-9c71-26df55b19990)

### 2. Buatlah sebuah program yang dapat menghitung banyaknya huruf vocal dalam sebuah kalimat!

```C++
#include <iostream>
#include <string>
#include <cctype> // Untuk isalpha() dan tolower()

using namespace std;

// Fungsi untuk menghitung jumlah huruf vokal dalam sebuah kalimat
int countVowels(const string& kalimat) {
    int count = 0;
    // Set huruf vokal yang ingin dihitung
    string vowels = "aiueo";

    // Iterasi melalui setiap karakter dalam kalimat
    for (char ch : kalimat) {
        // Ubah karakter menjadi lowercase
        char lowercaseCh = tolower(ch);
        // Periksa apakah karakter merupakan huruf dan merupakan huruf vokal
        if (isalpha(lowercaseCh) && vowels.find(lowercaseCh) != string::npos) {
            count++; // Tambahkan jumlah huruf vokal
        }
    }

    return count;
}

int main() {
    string kalimat;

    cout << "Masukkan sebuah kalimat: ";
    getline(cin, kalimat); // Input sebuah kalimat

    // Hitung jumlah huruf vokal dalam kalimat
    int jumlahVokal = countVowels(kalimat);

    cout << "Jumlah huruf vokal dalam kalimat adalah: " << jumlahVokal << endl;

    return 0;
}
```

#### Output:

![image](https://github.com/dkumui/Struktur-Data-Assignment/assets/91511212/533b67d3-02db-4a7e-a571-52f3b54508c5)

## Interpretasi dan Langkah-langkah Kode Algoritma Menghitung Huruf Vokal

**Interpretasi:**

Kode di atas menunjukkan implementasi fungsi `countVowels()` untuk menghitung jumlah huruf vokal dalam sebuah kalimat. Fungsi ini menerima string kalimat sebagai parameter dan mengembalikan jumlah huruf vokal yang ditemukan.

**Langkah-langkah:**

1. **Memasukkan Kalimat:**
    * Pengguna diminta untuk memasukkan kalimat yang ingin dihitung huruf vokalnya.
    * Kalimat disimpan dalam variabel `kalimat`.

2. **Inisialisasi Variabel:**
    * Variabel `count` diinisialisasi dengan nilai 0 untuk menampung jumlah huruf vokal.
    * Variabel `vowels` diinisialisasi dengan string yang berisi huruf vokal yang ingin dihitung ("aiueo").

3. **Iterasi dan Perbandingan:**
    * Loop `for` digunakan untuk mengiterasi melalui setiap karakter dalam variabel `kalimat`.
    * Di dalam loop:
        * Karakter diubah menjadi huruf kecil menggunakan `tolower()`.
        * Fungsi `isalpha()` digunakan untuk memeriksa apakah karakter merupakan huruf.
        * Jika karakter merupakan huruf:
            * Metode `find()` digunakan untuk mencari karakter dalam string `vowels`.
            * Jika karakter ditemukan dalam `vowels`:
                * Nilai `count` ditambah 1 untuk menghitung jumlah huruf vokal.

4. **Mengembalikan Hasil:**
    * Fungsi `countVowels()` mengembalikan nilai `count` yang merupakan jumlah huruf vokal yang ditemukan dalam kalimat.

**Kesimpulan:**

Fungsi `countVowels()` ini memungkinkan penghitungan jumlah huruf vokal dalam string dengan efisien. Algoritma ini bermanfaat untuk menganalisis teks, data linguistik, atau informasi lainnya yang terkait dengan huruf vokal.

#### Full Code Screenshot:

![image](https://github.com/dkumui/Struktur-Data-Assignment/assets/91511212/8a0493ae-22d2-4b5e-8d4a-412edaeba8e5)

### 3. Diketahui data = 9, 4, 1, 4, 7, 10, 5, 4, 12, 4. Hitunglah berapa banyak angka 4 dengan menggunakan algoritma Sequential Search!

```C++
#include <iostream>

using namespace std;

// Fungsi untuk menghitung berapa banyak angka 4 dalam array data
int countFours(const int data[], int length) {
    int count = 0;

    // Iterasi melalui setiap elemen dalam array data
    for (int i = 0; i < length; ++i) {
        // Periksa apakah elemen saat ini sama dengan angka 4
        if (data[i] == 4) {
            count++; // Tambahkan jumlah angka 4 yang ditemukan
        }
    }

    return count;
}

int main() {
    int data[] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
    int length = sizeof(data) / sizeof(data[0]);

    // Hitung berapa banyak angka 4 dalam array data
    int jumlahAngkaEmpat = countFours(data, length);

    cout << "Jumlah angka 4 dalam data adalah: " << jumlahAngkaEmpat << endl;

    return 0;
}
```

#### Output:

![image](https://github.com/dkumui/Struktur-Data-Assignment/assets/91511212/f122af22-58a9-4270-8aac-dfc8ae3f1da3)

## Interpretasi dan Langkah-langkah Kode Algoritma Menghitung Angka 4

**Interpretasi:**

Kode di atas menunjukkan implementasi fungsi `countFours()` untuk menghitung berapa banyak angka 4 dalam array data integer. Fungsi ini menerima array data dan panjang array sebagai parameter dan mengembalikan jumlah angka 4 yang ditemukan dalam array.

**Langkah-langkah:**

1. **Definisikan Fungsi:**
    * Fungsi `countFours()` didefinisikan dengan parameter `data` (array data integer) dan `length` (panjang array).
    * Fungsi ini mengembalikan nilai integer yang merupakan jumlah angka 4 yang ditemukan dalam array.

2. **Inisialisasi Variabel:**
    * Variabel `count` diinisialisasi dengan nilai 0 untuk menampung jumlah angka 4 yang ditemukan.

3. **Iterasi dan Perbandingan:**
    * Loop `for` digunakan untuk mengiterasi melalui setiap elemen dalam array `data`.
    * Di dalam loop:
        * Elemen array saat ini dibandingkan dengan nilai 4.
        * Jika elemen array saat ini sama dengan 4:
            * Nilai `count` ditambah 1 untuk menghitung jumlah angka 4 yang ditemukan.

4. **Mengembalikan Hasil:**
    * Fungsi `countFours()` mengembalikan nilai `count` yang merupakan jumlah angka 4 yang ditemukan dalam array.

**Kesimpulan:**

Fungsi `countFours()` ini memungkinkan penghitungan jumlah angka 4 dalam array data integer dengan efisien. Algoritma ini bermanfaat untuk analisis data, pemrosesan array, atau tugas yang melibatkan pencarian nilai tertentu dalam array.

#### Full Code Screenshot:

<img width="960" alt="Screenshot_408" src="https://github.com/dkumui/Struktur-Data-Assignment/assets/91511212/1a45b8a5-8073-4175-9bf9-a5459c2c05da">

## Kesimpulan

Algoritma searching merupakan alat penting dalam ilmu komputer yang digunakan untuk menemukan elemen tertentu dalam sekumpulan data. Berbagai algoritma searching tersedia dengan kompleksitas waktu dan karakteristik yang berbeda. Pemilihan algoritma searching yang tepat tergantung pada beberapa faktor, seperti struktur data, ukuran data, informasi awal, dan presisi.

## Referensi

[1] P. Nagarajan dan A. Thamizhendhi, "A survey on searching techniques," 2020

[2] A. R. A. a. R. Alsaadi, "Sequential and Binary Search Algorithms: A Comparative Study," Telkomnika, vol. 18, no. 1, pp. 438-445, 2020.

[3] S. Yadav dan V. Chaudhary, "Performance Analysis of Binary Search and Interpolation Search Algorithms," 2020

[4] G. Gulati dan A. Rai, "Comparison and analysis of sequential search, binary search, interpolation search and jump search," Procedia Computer Science, vol. 167, pp. 1854-1862, 2020.

[5] R. S. Chauhan dan A. Goyal, "Comparative analysis of depth first search and breadth first search algorithms," International Journal of Scientific & Technology Research, vol. 9, no. 3, pp. 835-838, 2020.
