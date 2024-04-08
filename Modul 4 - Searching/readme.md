# <h1 align="center">Laporan Praktikum Modul Array</h1>

<p align="center">Muhammad Azka</p>

## Features

- [Dasar Teori](#dasar-teori)
- [Guided](#guided)
- [Unguided](#unguided)
- [Kesimpulan](#kesimpulan)
- [Referensi](#referensi)

## Dasar Teori

## Algoritma Sorting

Algoritma Sorting merupakan operasi dasar dalam pemrograman untuk mengurutkan data. Berbagai algoritma sorting tersedia dengan kelebihan dan kekurangannya masing-masing.

**Jenis-jenis Algoritma Sorting:**

* **Insertion Sort:**
    * Membandingkan elemen secara berurutan dan menyisipkannya pada posisi tepat.
    * Sederhana dan efektif untuk data kecil[3].

* **Selection Sort:**
    * Mencari elemen terkecil dan menukar posisinya.
    * Lebih lambat dari insertion sort, namun efisien untuk data sedang[1] [5].

* **Bubble Sort:**
    * Membandingkan dua elemen berurutan dan menukar posisinya.
    * Paling sederhana, namun kurang efisien untuk data besar[2], [4].

## Guided

### 1. Mengurutkan secara ascending untuk data numerik bertipe double menggunakan Algoritma Bubble Sort

```C++
#include <iostream>
using namespace std;

void bubble_sort(double arr[], int length){
    bool not_sorted = true;
    int j=0;
    double tmp;

    while (not_sorted){
        not_sorted = false;
        j++;
        for (int i = 0; i < length - j; i++){
            if (arr[i] > arr[i + 1]) {
                tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
                not_sorted = true;
            }//end of if
        }//end of for loop
    }//end of while loop
}//end of bubble_sort

void print_array(double a[], int length) {
    for(int i=0; i<length; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;
}

int main() {
    int length = 5;
    double a[] = {22.1, 15.3, 8.2, 33.21, 99,99};

    cout << "Urutan bilangan sebelum sorting: " << endl;
    print_array(a, length);

    bubble_sort(a, length);
    
    cout << "\nUrutan bilangan setelah sorting: " << endl;
    print_array(a, length);
}
```

## Interpretasi dan Analisis Kompleksitas Waktu dan Ruang Kode Selection Sort

Kode di atas mengimplementasikan algoritma Selection Sort untuk mengurutkan nilai IPK mahasiswa dari terbesar ke terkecil. Berikut adalah interpretasi dan analisis kompleksitas waktu dan ruangnya:

**Kompleksitas Waktu:**

* **Kasus Terburuk (Worst Case):** O(n^2)
    * Pada kasus terburuk, elemen terkecil selalu berada di akhir array. Algoritma perlu melakukan perbandingan pada setiap elemen untuk menemukan elemen terkecil di setiap iterasi.
    * Jumlah perbandingan total: n + (n-1) + (n-2) + ... + 1 = n(n+1)/2, yang setara dengan O(n^2).

* **Kasus Terbaik (Best Case):** O(n^2)
    * Pada kasus terbaik, elemen terkecil selalu berada di awal array. Algoritma hanya perlu melakukan perbandingan n-1 kali.
    * Jumlah perbandingan total: n-1, yang setara dengan O(n^2).

* **Kasus Rata-rata (Average Case):** O(n^2)
    * Pada kasus rata-rata, elemen terkecil tersebar secara acak di array. Algoritma perlu melakukan perbandingan rata-rata n(n+1)/4 kali.
    * Jumlah perbandingan total: n(n+1)/4, yang setara dengan O(n^2).

**Alasan:**

* Algoritma Selection Sort melakukan loop sebanyak n kali (baris 5).
* Di dalam loop, terdapat loop lain sebanyak n-i kali (baris 7).
* Di dalam loop kedua, terdapat perbandingan nilai IPK (baris 8).

**Kesimpulan:**

Kompleksitas waktu algoritma Selection Sort selalu O(n^2) dalam semua kasus.

**Kompleksitas Ruang:**

* **Ruang Konstan:** O(1)
    * Algoritma ini hanya menggunakan variabel konstan untuk menyimpan nilai minimum dan melakukan penukaran.
    * Penggunaan memori tidak tergantung pada ukuran array.

**Kesimpulan:**

Kompleksitas ruang algoritma Selection Sort selalu O(1) dalam semua kasus.

### 2. Mengurutkan karakter secara descending (dari terbesar hingga terkecil) menggunakan Algoritma Insertion Sort

```C++
#include <iostream>
using namespace std;

void insertion_sort(char arr[], int length) {
    int i, j;
    char tmp;
    for (i = 1; i < length; i++) {
        j = i;
        while (j > 0 && arr[j - 1] < arr[j]) {
            tmp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = tmp;
            j--;  
        }//end of while loop
    }//end of for loop
}

void print_array(char a[], int length) {

    for(int i=0; i<length; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;
}

int main() {
    int length = 6;
    char a[length] = {'c', 'f', 'a', 'z', 'd', 'p'};

    cout << "Urutan karakter sebelum sorting: " << endl;
    print_array(a, length);

    insertion_sort(a, length);

    cout << "\nUrutan karakter setelah sorting: " << endl;
    print_array(a, length);
}
```

## Interpretasi dan Analisis Kompleksitas Waktu dan Ruang Kode Insertion Sort

Kode di atas mengimplementasikan algoritma Insertion Sort untuk mengurutkan array karakter. Berikut adalah interpretasi dan analisis kompleksitas waktu dan ruangnya:

**Interpretasi:**

* Fungsi `insertion_sort` melakukan pengurutan karakter dalam array `a` dari terkecil ke terbesar.
* Fungsi `print_array` menampilkan isi array ke konsol.

**Kompleksitas Waktu:**

* **Kasus Terburuk (Worst Case):** O(n^2)
    * Kasus terburuk terjadi ketika array sudah terurut terbalik (elemen terbesar di awal). 
    * Diperlukan pergeseran elemen sebanyak n-1 kali pada setiap iterasi loop luar (baris 4).
    * Jumlah pergeseran total: (n-1) + (n-2) + ... + 1 = n(n-1)/2, yang setara dengan O(n^2).

* **Kasus Terbaik (Best Case):** O(n)
    * Kasus terbaik terjadi ketika array sudah terurut (elemen terkecil di awal).
    * Loop while pada baris 6 tidak akan pernah dijalankan, sehingga hanya membutuhkan n iterasi loop luar (baris 4).
    * Jumlah pergeseran total: 0, yang setara dengan O(n).

* **Kasus Rata-rata (Average Case):** O(n^2)
    * Pada kasus rata-rata, elemen acak dan perlu dilakukan pergeseran rata-rata n(n-1)/4 kali.
    * Jumlah pergeseran total: n(n-1)/4, yang setara dengan O(n^2).

**Alasan:**

* Loop luar (baris 4) dijalankan n kali untuk iterasi setiap elemen dalam array.
* Loop while (baris 6) dijalankan untuk memindahkan elemen ke posisi yang benar.
* Jumlah iterasi loop while tergantung pada keterurutan awal array.
* Dalam kasus terburuk, loop while dijalankan n-1 kali untuk setiap elemen, menghasilkan kompleksitas waktu O(n^2).

**Kesimpulan:**

Kompleksitas waktu algoritma Insertion Sort bergantung pada keterurutan awal array. Dalam kasus terburuk dan rata-rata, kompleksitasnya adalah O(n^2). Namun, pada kasus terbaik, kompleksitasnya menjadi lebih baik yaitu O(n).

**Kompleksitas Ruang:**

* **Ruang Konstan (Constant Space):** O(1)
    * Algoritma ini hanya menggunakan variabel konstan untuk penukaran elemen dan indeks.
    * Penggunaan memori tidak tergantung pada ukuran array.

**Kesimpulan:**

Kompleksitas ruang algoritma Insertion Sort selalu O(1) dalam semua kasus.

## Unguided

### 1. Kelas S1 IF 2016 G memiliki 5 mahasiswa. Pada akhir semester mereka menerima lembar Indeks Prestasi Semester (IPS), masing-masing mahasiswa tersebut memiliki IPS sebagai berikut: {3.8, 2.9, 3.3, 4.0, 2.4}. Buatlah program untuk mengurutkan IPS mahasiswa tersebut dari yang terbesar hingga terkecil dengan menggunakan algoritma Selection Sort!

```C++
#include <iostream>
using namespace std;

int main() {
  // Array untuk menyimpan nilai IPS
  float ips[5] = {3.8, 2.9, 3.3, 4.0, 2.4};

  // Menjalankan algoritma Selection Sort
  for (int i = 0; i < 5; i++) {
    int minIndex = i;
    for (int j = i + 1; j < 5; j++) {
      if (ips[minIndex] < ips[j]) {
        minIndex = j;
      }
    }
    // Menukar nilai IPS pada indeks minimum dengan indeks saat ini
    float temp = ips[i];
    ips[i] = ips[minIndex];
    ips[minIndex] = temp;
  }

  // Menampilkan hasil pengurutan
  cout << "\nIPS mahasiswa setelah diurutkan dari terbesar ke terkecil:" << endl;
  for (int i = 0; i < 5; i++) {
    cout << ips[i] << ", ";
  }
  cout << endl;

  return 0;
}
```

#### Output:

![image](https://github.com/dkumui/Struktur-Data-Assignment/assets/91511212/491a5d3f-0e4d-415d-b56f-b2f01bd83611)

Kodingan di atas mengimplementasikan algoritma Selection Sort untuk mengurutkan array ips yang berisi nilai Indeks Prestasi Semester (IPS) dari sejumlah mahasiswa. Berikut adalah penjelasan langkah-langkahnya:

- Array ips diinisialisasi dengan nilai-nilai IPS dari 5 mahasiswa.
- Algoritma Selection Sort dijalankan dengan iterasi melalui setiap elemen array.
- Pada setiap iterasi, indeks minIndex ditetapkan sebagai indeks minimum, awalnya sama dengan indeks saat ini.
- Iterasi kedua dilakukan untuk mencari nilai minimum dari sisa array yang belum diurutkan.
- Jika ditemukan nilai yang lebih kecil dari nilai yang diindeks oleh minIndex, minIndex diperbarui menjadi indeks dari nilai yang lebih kecil tersebut.
- Setelah iterasi kedua selesai, nilai yang ditemukan sebagai nilai terkecil diurutkan dengan nilai pada indeks saat ini dengan menukar posisi keduanya.
- Proses ini diulangi sampai seluruh array terurut secara descending (dari terbesar ke terkecil).
- Setelah pengurutan selesai, hasil pengurutan ditampilkan dalam loop terakhir menggunakan cout.

Jadi, output program tersebut adalah daftar IPS mahasiswa yang telah diurutkan dari terbesar ke terkecil.

#### Full Code Screenshot:

![image](https://github.com/dkumui/Struktur-Data-Assignment/assets/91511212/526c8966-f6aa-407e-9624-e4e499144ad8)

### 2. Pak RT memiliki 10 warga dengan nama: siti, situ, sana, ana, ani, caca, cici, dida, dodo, dan dadi. Supaya mudah dalam melakukan pencarian, Pak RT akan mengurutkan namanama tersebut sesuai dengan alfabet. Buatlah program untuk membantu Pak RT dengan menggunakan algoritma Bubble Sort!

```C++
#include <iostream>
#include <string>

using namespace std;

int main() {
  // Array untuk menyimpan nama warga
  string nama[10] = {"siti", "situ", "sana", "ana", "ani", "caca", "cici", "dida", "dodo", "dadi"};

  // Menjalankan algoritma Bubble Sort
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10 - i - 1; j++) {
      if (nama[j] > nama[j + 1]) {
        string temp = nama[j];
        nama[j] = nama[j + 1];
        nama[j + 1] = temp;
      }
    }
  }

  // Menampilkan hasil pengurutan
  cout << "\nDaftar nama warga setelah diurutkan:" << endl;
  for (int i = 0; i < 10; i++) {
    cout << nama[i] << ", ";
  }
  cout << endl;

  return 0;
}
```

#### Output:

![image](https://github.com/dkumui/Struktur-Data-Assignment/assets/91511212/63714f02-76fd-4ad0-9775-e38f0eaada6a)

Kodingan di atas mengimplementasikan algoritma Bubble Sort untuk mengurutkan array nama yang berisi nama-nama warga. Berikut adalah penjelasan langkah-langkahnya:

- Array nama diinisialisasi dengan nama-nama warga.
- Algoritma Bubble Sort dijalankan dengan dua iterasi nested.
- Pada setiap iterasi luar (i), elemen-elemen array dibandingkan secara berpasangan.
- Jika elemen ke-j lebih besar dari elemen ke-(j+1), maka keduanya ditukar posisinya.
- Proses ini diulangi sampai seluruh array terurut secara ascending (dari A-Z).
- Setelah pengurutan selesai, hasil pengurutan ditampilkan dalam loop terakhir menggunakan cout.
- Jadi, output program tersebut adalah daftar nama warga yang telah diurutkan secara alfabetis dari A-Z.

#### Full Code Screenshot:

![image](https://github.com/dkumui/Struktur-Data-Assignment/assets/91511212/3fd87837-b57f-427d-b2b1-527ffcb965a0)

### 3. Buatlah program yang meminta user menginputkan suatu bilangan n dan meminta user untuk menginputkan sejumlah n karakter. Kemudian program akan melakukan sorting secara menaik (ascending) dan menurun (descending)!

<img src="https://github.com/dkumui/Struktur-Data-Assignment/assets/91511212/77f5fb8c-2251-48e7-bb12-0ba24368eff3" width="450">

```C++
#include <iostream>

using namespace std;

void ascendingSort(char arr[], int n) {
  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (arr[i] > arr[j]) {
        char temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }
}

void descendingSort(char arr[], int n) {
  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (arr[i] < arr[j]) {
        char temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }
}

int main() {
  int n;
  cout << "\nMasukkan jumlah karakter (n): ";
  cin >> n;

  char characters[n];

  for (int i = 0; i < n; ++i) {
    cout << "Masukkan karakter ke-" << i + 1 << ": ";
    cin >> characters[i];
  }

  // Menampilkan urutan karakter sebelum sorting
  cout << "Urutan karakter sebelum sorting: ";
  for (int i = 0; i < n; ++i) {
    cout << characters[i] << " ";
  }
  cout << endl;

  // Sorting secara menaik (ascending)
  ascendingSort(characters, n);

  // Menampilkan urutan karakter setelah sorting ascending
  cout << "Urutan karakter setelah ascending sort: ";
  for (int i = 0; i < n; ++i) {
    cout << characters[i] << " ";
  }
  cout << endl;

  // Sorting secara menurun (descending)
  descendingSort(characters, n);

  // Menampilkan urutan karakter setelah sorting descending
  cout << "Urutan karakter setelah descending sort: ";
  for (int i = 0; i < n; ++i) {
    cout << characters[i] << " ";
  }
  cout << endl;

  return 0;
}
```

#### Output:

<img src="https://github.com/dkumui/Struktur-Data-Assignment/assets/91511212/3d35ea35-8db9-4a7e-a021-c9fb4e32e934" width="750">

Program di atas merupakan implementasi dari fungsi `ascendingSort` dan `descendingSort` untuk mengurutkan array karakter (`char`). Berikut adalah penjelasan singkat mengenai program tersebut:

- Fungsi `ascendingSort` digunakan untuk melakukan pengurutan karakter secara naik (ascending) menggunakan algoritma Bubble Sort.
- Fungsi `descendingSort` digunakan untuk melakukan pengurutan karakter secara turun (descending) menggunakan algoritma Bubble Sort.
- Pada fungsi `ascendingSort` dan `descendingSort`, terdapat dua loop bersarang yang digunakan untuk membandingkan dan menukar elemen-elemen array.
- Di dalam `main` function, program meminta pengguna untuk memasukkan jumlah karakter (\( n \)) dan karakter-karakter itu sendiri.
- Setelah memasukkan karakter, program menampilkan urutan karakter sebelum sorting.
- Kemudian, program melakukan sorting karakter secara naik menggunakan `ascendingSort`, dan menampilkan urutan karakter setelah sorting secara naik.
- Terakhir, program melakukan sorting karakter secara turun menggunakan `descendingSort`, dan menampilkan urutan karakter setelah sorting secara turun.

Jadi, output program tersebut adalah urutan karakter sebelum dan setelah pengurutan (ascending dan descending).

#### Full Code Screenshot:

![image](https://github.com/dkumui/Struktur-Data-Assignment/assets/91511212/8488700d-fef4-4f21-b9e3-eee232a19ccf)

## Kesimpulan

Algoritma sorting adalah operasi penting dalam pemrograman untuk mengurutkan data. Ada berbagai jenis algoritma sorting dengan kelebihan dan kekurangannya masing-masing.

## Referensi

[1] Dhankawade, S., Gaikwad, A. N., & Jadhav, A. S. (2020). Insertion Sort: An Algorithm and Its Analysis. IJRITCC.

[2] Gaurav. (2023). Heap Sort Algorithm: A Comparative Study. International Journal of Innovative Technology and Exploring Engineering.

[3] Kumar, S., & Saraswat, Y. (2023). An Overview of Sorting Algorithms. International Journal of Computer Engineering & Technology.

[4] Patil, S., & Kale, V. (2023). A Comparative Analysis of Selection and Bubble Sort Algorithm. International Journal of Engineering Research & Technology.

[5] Singh, A., & Sharma, N. (2022). Analysis of Selection Sort Algorithm. Conflux Journal of Mathematics.
