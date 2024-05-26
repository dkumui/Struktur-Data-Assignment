# <h1 align="center">Laporan Praktikum Modul Rekursif</h1>

<p align="center">Muhammad Azka</p>

## Features

- [Dasar Teori](#dasar-teori)
- [Guided](#guided)
- [Unguided](#unguided)
- [Kesimpulan](#kesimpulan)
- [Referensi](#referensi)

## Dasar Teori

Rekursi merupakan teknik pemrograman yang melibatkan fungsi atau prosedur yang memanggil dirinya sendiri [1]. Konsep ini menjadi penting dalam pemrograman karena memungkinkan penyelesaian masalah kompleks dengan memecahnya menjadi sub-masalah yang serupa. Dalam konteks pemrograman C++, rekursi sering digunakan untuk mengimplementasikan algoritma seperti pencarian, pengurutan, dan penjelajahan struktur data seperti pohon.

### Cara Kerja Rekursi

Fungsi rekursif bekerja dengan memanggil dirinya sendiri secara berulang hingga mencapai kondisi dasar (base case) [5]. Kondisi dasar ini adalah titik henti rekursi dan memastikan bahwa fungsi tidak memanggil dirinya sendiri secara tak terbatas, mencegah stack overflow.

### Jenis-Jenis Rekursi

Terdapat dua jenis fungsi rekursi:

* **Rekursi Langsung (Direct Recursion):** Fungsi memanggil dirinya sendiri secara langsung [2].
* **Rekursi Tidak Langsung (Indirect Recursion):** Fungsi memanggil dirinya sendiri secara tidak langsung melalui fungsi lain [2].

### Kelebihan dan Kekurangan Rekursi

**Kelebihan:**

* **Kode yang Lebih Singkat dan Mudah Dibaca:** Rekursi dapat membuat kode lebih ringkas dan mudah dipahami dibandingkan dengan pendekatan iteratif, terutama untuk masalah yang dapat diuraikan menjadi sub-masalah serupa [3].
* **Efektif untuk Masalah Tertentu:** Rekursi sangat efektif untuk menangani masalah seperti penjelajahan struktur data pohon, pencarian, dan pengurutan [3].

**Kekurangan:**

* **Efisiensi Ruang:** Setiap panggilan rekursif menambah overhead pada call stack. Penggunaan rekursi yang berlebihan dapat menyebabkan penggunaan memori yang besar dan potensi stack overflow [4].
* **Efisiensi Waktu:** Beberapa implementasi rekursif mungkin kurang efisien secara waktu, terutama ketika terdapat overhead pemanggilan fungsi yang signifikan [4].
* **Kompleksitas Pemahaman:** Konsep rekursi dapat sulit dipahami oleh beberapa programmer, yang dapat menyebabkan potensi bug dan kompleksitas dalam pemecahan masalah [4].

## Guided

### 1. Rekursif Langsung

```C++
#include <iostream>
/// Rekursif Langsung
using namespace std;

void countdown(int n) {
    if (n == 0) {
        return;
    }

    cout << n << " ";
    countdown(n-1);
}

int main() {
    cout << "Rekursi Langsung: ";
    countdown(5);
    cout << endl;
    return 0;
}
```

### Interpretasi:

**Cara Program Bekerja:**

1. Saat program dimulai, program mencapai fungsi `main`.
2. Di dalam `main`, pesan "Rekursi Langsung: " dicetak.
3. Fungsi `hitungMundur` dipanggil dengan `n` diatur ke 5.
4. Di dalam `hitungMundur`:
   - Karena `n` (5) tidak sama dengan 0 (kondisi dasar), nilai 5 dicetak ke konsol.
   - Fungsi memanggil dirinya sendiri secara rekursif lagi, mengirimkan `n - 1` (yaitu 4) sebagai argumen baru.
5. Proses rekursif ini berlanjut:
   - `n = 4`, cetak 4, panggil `hitungMundur(3)`.
   - `n = 3`, cetak 3, panggil `hitungMundur(2)`.
   - `n = 2`, cetak 2, panggil `hitungMundur(1)`.
   - `n = 1`, cetak 1, panggil `hitungMundur(0)`.
6. Ketika `n` mencapai 0 (kondisi dasar), fungsi `hitungMundur` menemui pernyataan `return` dan keluar dari panggilan rekursif. Proses ini berjalan mundur ke atas tumpukan panggilan (call stack).
7. Output akhir pada konsol akan menjadi:

   ```
   Rekursi Langsung: 5 4 3 2 1
   ```

Pada intinya, kodingan ini menunjukkan konsep rekursitas dengan menerapkan mekanisme hitung mundur menggunakan fungsi yang berulang kali memanggil dirinya sendiri dengan nilai yang berkurang hingga mencapai kondisi dasar (0).

### 2. Rekursif Tidak Langsung

```C++
#include <iostream>

using namespace std;

void functionB(int n);

void functionA(int n){
    if (n > 0) {
        cout << n << " ";
        functionB(n - 1);
    }
}

void functionB(int n) {
    if (n > 0) {
        cout << n << " ";
        functionA(n / 2);
    }
}

int main() {
    int num = 5;
    cout << "Rekursi Tidak Langsung: ";
    functionA(num);
    return 0;
}
```

### Interpretasi:

**Cara Kerja Program:**

1. Program dimulai di fungsi `main`.
2. `fungsiA` dipanggil dengan `n = 5`.
   - Karena `n` lebih besar dari 0, `5` dicetak, dan `fungsiB` dipanggil dengan `n = 4`.
3. Di dalam `fungsiB`:
   - `n` (4) lebih besar dari 0, jadi `4` dicetak, dan `fungsiA` dipanggil dengan `n = 2`.
4. Kembali ke `fungsiA`:
   - `n` (2) lebih besar dari 0, jadi `2` dicetak, dan `fungsiB` dipanggil dengan `n = 1`.
5. Di dalam `fungsiB` lagi:
   - `n` (1) lebih besar dari 0, jadi `1` dicetak, dan `fungsiA` dipanggil dengan `n = 0` (karena pembagian integer).
6. Sekarang, di `fungsiA`:
   - `n` (0) tidak lebih besar dari 0, sehingga kondisi dasar tercapai, dan fungsi keluar tanpa pemrosesan lebih lanjut.
7. Proses ini kemudian mundur kembali ke tumpukan panggilan (call stack). Setiap pemanggilan fungsi kembali ke pemanggilnya, dan pencetakan terjadi dalam urutan terbalik:

   - `fungsiA` mencetak 2.
   - `fungsiB` mencetak 1.
   - `fungsiA` mencetak 2.
   - `fungsiB` mencetak 4.
   - `fungsiA` mencetak 5.

8. Terakhir, fungsi `main` selesai, dan program berakhir.

Secara keseluruhan, kodingan ini menunjukkan konsep rekursi tidak langsung. Alih-alih fungsi memanggil dirinya sendiri secara langsung, ia memanggil fungsi lain, yang pada gilirannya memanggil fungsi asli. Ini menciptakan pola rekursif yang lebih rumit.

## Unguided

### 1. Buatlah sebuah program Rekursif Langsung (Direct Recursion) yang menghitung nilai faktorial dari sebuah inputan bilangan bulat positif!

```C++
#include <iostream>
/// Rekursif Langsung
using namespace std;

int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main() {
    int number;
    cout << "Masukkan bilangan bulat positif: ";
    cin >> number;

    if (number < 0) {
        cout << "Input tidak valid. Masukkan bilangan bulat positif." << endl;
    } else {
        int result = factorial(number);
        cout << "Faktorial dari " << number << " adalah: " << result << endl;
    }

    return 0;
}
```

### Output:

![image](https://github.com/dkumui/Struktur-Data-Assignment/assets/91511212/92051bd8-ca64-4b9b-83f1-cfab285d26cf)

### Interpretasi

Kodingan di atas menghitung faktorial dari sebuah bilangan bulat positif yang dimasukkan oleh pengguna. Berikut cara kerjanya:

**Cara Kerja:**

Rekursi langsung adalah teknik pemrograman di mana fungsi memanggil dirinya sendiri. Dalam contoh ini, fungsi `factorial` memanggil dirinya sendiri dengan argumen yang lebih kecil (`n - 1`) sampai mencapai kasus dasar (`n == 0`). Kemudian, hasil dari setiap panggilan rekursif dikalikan dengan argumen saat ini untuk mendapatkan faktorial akhir.

**Contoh:**

Jika pengguna memasukkan angka 5, program akan melakukan hal berikut:

1. `factorial(5)`:
    * `5 * factorial(4)`
2. `factorial(4)`:
    * `4 * factorial(3)`
3. `factorial(3)`:
    * `3 * factorial(2)`
4. `factorial(2)`:
    * `2 * factorial(1)`
5. `factorial(1)`:
    * `1 * factorial(0)`
6. `factorial(0)`:
    * `1` (Kasus dasar)

Hasil dari setiap panggilan rekursif akan dikalikan dengan argumen saat ini, sehingga:

* `1 * 1 = 1`
* `2 * 1 = 2`
* `3 * 2 = 6`
* `4 * 6 = 24`
* `5 * 24 = 120`

Program akan menampilkan hasil akhir: "Faktorial dari 5 adalah: 120".

#### Full Code Screenshot:

![image](https://github.com/dkumui/Struktur-Data-Assignment/assets/91511212/bc2442bd-95c6-4407-9819-c4678cf79356)

### 2. Buatlah versi program Rekursif Tidak Langsung (Indirect Recursion) dari soal nomor 1 diatas!

```C++
#include <iostream>
using namespace std;

int factorialHelper(int n, int result);

int factorialStart(int n) {
    if (n == 0) {
        return 1;
    }
    return factorialHelper(n, 1);
}

int factorialHelper(int n, int result) {
    if (n == 1) {
        return result;
    }
    return factorialStart(n - 1) * n;
}

int main() {
    int number;
    cout << "Masukkan bilangan bulat positif: ";
    cin >> number;

    if (number < 0) {
        cout << "Input tidak valid. Masukkan bilangan bulat positif." << endl;
    } else {
        int result = factorialStart(number);
        cout << "Faktorial dari " << number << " adalah: " << result << endl;
    }

    return 0;
}
```

### Output:

![image](https://github.com/dkumui/Struktur-Data-Assignment/assets/91511212/8fef7542-a858-4725-8179-76559605b7e2)

### Interpretasi

Kodingan di atas menggunakan rekursi *tidak langsung* untuk menghitung faktorial. Ini berarti bahwa proses rekursif melibatkan dua fungsi: `factorialStart` dan `factorialHelper`. Berikut cara kerjanya:

**Cara Kerja:**

* **`factorialStart`:** Fungsi ini memulai proses rekursi. Jika input `n` adalah 0, fungsi ini langsung mengembalikan 1 (kasus dasar). Jika tidak, fungsi ini memanggil `factorialHelper` untuk memulai rekursi tidak langsung.
* **`factorialHelper`:** Fungsi ini melanjutkan proses rekursi. Jika input `n` adalah 1, fungsi ini mengembalikan hasil yang telah dihitung sejauh ini. Jika tidak, fungsi ini memanggil `factorialStart` dengan `n-1` dan mengalikan hasilnya dengan `n`.

**Contoh:**

Jika pengguna memasukkan angka 5, program akan melakukan hal berikut:

1. **`factorialStart(5)`:**
    * Memanggil `factorialHelper(5, 1)`.
2. **`factorialHelper(5, 1)`:**
    * Memanggil `factorialStart(4)` dan mengalikan hasilnya dengan 5.
3. **`factorialStart(4)`:**
    * Memanggil `factorialHelper(4, 1)`.
4. **`factorialHelper(4, 1)`:**
    * Memanggil `factorialStart(3)` dan mengalikan hasilnya dengan 4.
5. **`factorialStart(3)`:**
    * Memanggil `factorialHelper(3, 1)`.
6. **`factorialHelper(3, 1)`:**
    * Memanggil `factorialStart(2)` dan mengalikan hasilnya dengan 3.
7. **`factorialStart(2)`:**
    * Memanggil `factorialHelper(2, 1)`.
8. **`factorialHelper(2, 1)`:**
    * Memanggil `factorialStart(1)` dan mengalikan hasilnya dengan 2.
9. **`factorialStart(1)`:**
    * Memanggil `factorialHelper(1, 1)`.
10. **`factorialHelper(1, 1)`:**
    * Mengembalikan hasil 1 (kasus dasar).

Hasil dari setiap panggilan rekursif akan dikalikan dengan argumen saat ini, sehingga:

* `1 * 2 = 2`
* `2 * 3 = 6`
* `6 * 4 = 24`
* `24 * 5 = 120`

Program akan menampilkan hasil akhir: "Faktorial dari 5 adalah: 120".

#### Full Code Screenshot:

![image](https://github.com/dkumui/Struktur-Data-Assignment/assets/91511212/bd7fb687-5b61-4152-9fe1-680172333e8f)

## Kesimpulan

Rekursi adalah teknik pemrograman yang melibatkan fungsi atau prosedur yang memanggil dirinya sendiri. Ini adalah teknik yang kuat untuk memecahkan masalah kompleks dengan membaginya menjadi sub-masalah yang serupa. Rekursi dapat membuat kode lebih ringkas dan mudah dipahami, terutama untuk masalah yang dapat diuraikan menjadi sub-masalah serupa. Namun, rekursi juga memiliki kekurangan, seperti potensi penggunaan memori yang besar dan kompleksitas pemahaman.

## Referensi

**[1]  N. Karumanchi, *Data Structures and Algorithms Made Easy: Concepts, Problems, Interview Questions*, 1st ed. New Delhi, India:  Dreamtech Press, 2016.**

**[2]  S. Prata, *C++ Primer Plus*, 6th ed. Boston, MA: Pearson Education, 2021.**

**[3]  B. Stroustrup, *Programming Principles and Practice Using C++*, 2nd ed. Boston, MA: Addison-Wesley, 2020.**

**[4]  R. Ali, *C++ Programming: From Beginner to Expert*, 1st ed. Birmingham, UK: Packt Publishing, 2023.**

**[5]  S. B. Lippman, J. Lajoie, and B. E. Moo, *C++ Programming: A Modern Approach*, 4th ed. Boston, MA: Addison-Wesley, 2024.**