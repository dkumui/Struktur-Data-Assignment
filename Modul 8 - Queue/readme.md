# <h1 align="center">Laporan Praktikum Modul Stack</h1>

<p align="center">Muhammad Azka</p>

## Features

- [Dasar Teori](#dasar-teori)
- [Guided](#guided)
- [Unguided](#unguided)
- [Kesimpulan](#kesimpulan)
- [Referensi](#referensi)

## Dasar Teori

Stack adalah struktur data sederhana yang digunakan untuk menyimpan data (mirip dengan Linked Lists) dengan konsep Last In First Out (LIFO) [1]. Pada stack, urutan kedatangan data penting karena penambahan dan penghapusan data hanya dilakukan pada satu ujung yang disebut top [2]. 

Definisi: Sebuah stack adalah daftar terurut di mana penyisipan dan penghapusan dilakukan di satu ujung, disebut top. Elemen terakhir yang dimasukkan adalah yang pertama dihapus [3].

Beberapa operasi dasar pada stack meliputi [4]:
a. Push (Menambahkan elemen ke top stack)
b. Pop (Menghapus elemen dari top stack) 
c. Peek/Top (Melihat elemen top tanpa menghapus)
d. isEmpty (Mengecek keadaan stack kosong atau tidak)
e. isFull (Mengecek keadaan stack penuh atau tidak)
f. Size (Mengembalikan jumlah elemen dalam stack)

Implementasi stack dapat dilakukan menggunakan array secara statis atau linked list secara dinamis [5]. Permasalahan yang dapat diselesaikan dengan stack meliputi penerapannya untuk pembalikan kalimat, kalkulasi precedence operator, dan backtracking.

## Guided

### 1. Stack

```C++
#include <iostream>
using namespace std;

const int maksimal = 5;
string arrayBuku[maksimal];
int top = 0;

bool isFull() {
    return (top == maksimal);
}

bool isEmpty() {
    return (top == 0);
}

void pushArrayBuku(string data) {
    if (isFull()) {
        cout << "Data telah penuh" << endl;
    } else {
        arrayBuku[top++] = data;
    }
}

void popArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang dihapus" << endl;
    } else {
        arrayBuku[--top] = "";
    }
}

void peekArrayBuku(int posisi) {
    if (isEmpty()) {
        cout << "Tidak ada data yang bisa dilihat" << endl;
    } else if (posisi <= top) {
        cout << "Posisi ke " << posisi << " adalah " << arrayBuku[top - posisi] << endl;
    } else {
        cout << "Posisi melebihi data yang ada" << endl;
    }
}

int countStack() {
    return top;
}

void changeArrayBuku(int posisi, string data) {
    if (posisi <= top) {
        arrayBuku[top - posisi] = data;
    } else {
        cout << "Posisi melebihi data yang ada" << endl;
    }
}

void destroyArraybuku() {
    while (!isEmpty()) {
        popArrayBuku();
    }
}

void cetakArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang dicetak" << endl;
    } else {
        for (int i = top - 1; i >= 0; i--) {
            cout << arrayBuku[i] << endl;
        }
    }
}

int main() {
    pushArrayBuku("Kalkulus");
    pushArrayBuku("Struktur Data");
    pushArrayBuku("Matematika Diskrit");
    pushArrayBuku("Dasar Multimedia");
    pushArrayBuku("Inggris");

    cetakArrayBuku();
    cout << "\n";

    cout << "Apakah data stack penuh? " << isFull() << endl;
    cout << "Apakah data stack kosong? " << isEmpty() << endl;

    peekArrayBuku(2);
    popArrayBuku();

    cout << "Banyaknya data = " << countStack() << endl;

    changeArrayBuku(2, "Bahasa Jerman");
    cetakArrayBuku();

    cout << "\n";
    destroyArraybuku();
    cout << "Jumlah data setelah dihapus: " << top << endl;

    cetakArrayBuku();

    return 0;
}
```

### Interpretasi:

**Struktur Data:**

* **arrayBuku:** Array dengan ukuran maksimal 5 untuk menyimpan judul buku.
* **top:** Variabel untuk menunjuk ke indeks elemen teratas dalam tumpukan.

**Fungsi:**

* **isFull():** Memeriksa apakah tumpukan penuh dengan mengembalikan `true` jika `top` sama dengan `maksimal` dan `false` sebaliknya.
* **isEmpty():** Memeriksa apakah tumpukan kosong dengan mengembalikan `true` jika `top` sama dengan 0 dan `false` sebaliknya.
* **pushArrayBuku(data):** Menambahkan judul buku baru ke tumpukan.
    * Memeriksa apakah tumpukan penuh.
    * Jika tidak penuh, menambahkan judul buku baru ke indeks `top` dan meningkatkan nilai `top`.
    * Jika penuh, menampilkan pesan bahwa data telah penuh.
* **popArrayBuku():** Menghapus judul buku terakhir dari tumpukan.
    * Memeriksa apakah tumpukan kosong.
    * Jika tidak kosong, menghapus judul buku terakhir dengan menyetel elemen pada indeks `top-1` ke string kosong dan menurunkan nilai `top`.
    * Jika kosong, menampilkan pesan bahwa tidak ada data yang dihapus.
* **peekArrayBuku(posisi):** Menampilkan judul buku pada posisi tertentu dalam tumpukan.
    * Memeriksa apakah tumpukan kosong.
    * Jika tidak kosong dan posisi tidak melebihi batas tumpukan, menampilkan judul buku pada posisi yang ditentukan.
    * Jika kosong, menampilkan pesan bahwa tidak ada data yang bisa dilihat.
    * Jika posisi melebihi batas tumpukan, menampilkan pesan bahwa posisi melebihi data yang ada.
* **countStack():** Menghitung jumlah judul buku dalam tumpukan.
    * Mengembalikan nilai `top`, yang menunjukkan jumlah judul buku dalam tumpukan.
* **changeArrayBuku(posisi, data):** Mengubah judul buku pada posisi tertentu dalam tumpukan.
    * Memeriksa apakah posisi tidak melebihi batas tumpukan.
    * Jika tidak melebihi batas, mengubah judul buku pada posisi yang ditentukan dengan string baru yang diberikan.
    * Jika posisi melebihi batas tumpukan, menampilkan pesan bahwa posisi melebihi data yang ada.
* **destroyArraybuku():** Menghapus semua judul buku dari tumpukan.
    * Melakukan loop berulang kali hingga tumpukan kosong.
    * Pada setiap iterasi, memanggil fungsi `popArrayBuku()` untuk menghapus judul buku terakhir.
* **cetakArrayBuku():** Mencetak semua judul buku dalam tumpukan.
    * Memeriksa apakah tumpukan kosong.
    * Jika tidak kosong, melakukan loop dari elemen teratas hingga elemen terbawah dan mencetak judul buku pada setiap elemen.
    * Jika kosong, menampilkan pesan bahwa tidak ada data yang dicetak.

**Fungsi Utama (main):**

* Memanggil fungsi `pushArrayBuku()` untuk menambahkan 5 judul buku ke tumpukan.
* Memanggil fungsi `cetakArrayBuku()` untuk mencetak semua judul buku dalam tumpukan.
* Menampilkan informasi apakah tumpukan penuh dan kosong.
* Memanggil fungsi `peekArrayBuku(2)` untuk melihat judul buku pada posisi 2.
* Memanggil fungsi `popArrayBuku()` untuk menghapus judul buku terakhir dari tumpukan.
* Menampilkan jumlah judul buku dalam tumpukan.
* Memanggil fungsi `changeArrayBuku(2, "Bahasa Jerman")` untuk mengubah judul buku pada posisi 2 dengan "Bahasa Jerman".
* Memanggil fungsi `cetakArrayBuku()` untuk mencetak semua judul buku dalam tumpukan.
* Memanggil fungsi `destroyArraybuku()` untuk menghapus semua judul buku dari tumpukan.
* Menampilkan jumlah judul buku dalam tumpukan setelah dihapus.
* Memanggil fungsi `cetakArrayBuku()` untuk mencetak semua judul buku dalam tumpukan (yang seharusnya kosong).

**Kesimpulan:**

Kodingan ini menunjukkan implementasi tumpukan (stack) untuk menyimpan judul buku. Fungsi-fungsi yang disediakan memungkinkan operasi dasar pada tumpukan seperti menambahkan, menghapus, melihat, mengubah, dan menghitung judul buku.

## Unguided

### 1. Buatlah program untuk menentukan apakah kalimat tersebut yang diinputkan dalam program stack adalah palindrom/tidak. Palindrom kalimat yang dibaca dari depan dan belakang sama. Jelaskan bagaimana cara kerja programnya.

```C++
#include <iostream>
#include <string>
using namespace std;

// Array untuk menyimpan karakter dari kalimat
string arrayData[25];
// Maksimum elemen dalam array
int maksimal = 25;
// Indeks untuk menunjukkan elemen teratas dalam stack
int top = 0;

// Fungsi untuk mengecek apakah stack sudah penuh
bool isFull()
{
    return (top == maksimal);
}

// Fungsi untuk mengecek apakah stack kosong
bool isEmpty()
{
    return (top == 0);
}

// Fungsi untuk menambahkan karakter ke dalam arrayData (mengisi stack)
void pushArrayData(string kalimat)
{
    // Jika stack sudah penuh, cetak pesan
    if (isFull())
    {
        cout << "Data telah penuh" << endl;
    }
    else
    {
        // Masukkan karakter ke dalam arrayData pada indeks top, lalu naikkan top
        arrayData[top] = kalimat;
        top++;
    }
}

// Fungsi untuk menghapus karakter dari arrayData (mengosongkan stack)
void popArrayData()
{
    // Jika stack kosong, cetak pesan
    if (isEmpty())
    {
        cout << "Tidak ada data yang dihapus" << endl;
    }
    else
    {
        // Kosongkan karakter pada arrayData pada indeks top - 1, lalu turunkan top
        arrayData[top - 1] = "";
        top--;
    }
}

// Fungsi untuk mengecek apakah kalimat adalah palindrom
bool isPalindrom(string kalimat)
{
    int length = kalimat.length();
    // Memasukkan setengah karakter pertama dari kalimat ke dalam stack
    for (int i = 0; i < length / 2; i++)
    {
        pushArrayData(string(1, kalimat[i])); // Masukkan karakter ke stack
    }
    // Membandingkan setengah karakter kedua dengan isi stack
    for (int i = (length + 1) / 2; i < length; i++)
    {
        // Jika karakter dari kalimat tidak sama dengan karakter pada stack,
        // berarti bukan palindrom, kembalikan false
        if (kalimat[i] != arrayData[top - 1][0])
        {
            return false;
        }
        popArrayData(); // Hapus karakter pada stack
    }
    // Jika semua karakter cocok, kembalikan true (kalimat adalah palindrom)
    return true;
}

int main()
{
    string kalimat;
    cout << "Masukkan kalimat : ";
    getline(cin, kalimat); // Meminta input kalimat dari pengguna

    // Memeriksa apakah kalimat adalah palindrom
    if (isPalindrom(kalimat))
    {
        cout << "Kalimat tersebut adalah palindrom" << endl;
    }
    else
    {
        cout << "Kalimat tersebut bukan palindrom" << endl;
    }

    return 0;
}
```

#### Output:

![image](https://github.com/dkumui/Struktur-Data-Assignment/assets/91511212/e08e9535-7dfc-4ecd-ac97-83e1f018f837)
![image](https://github.com/dkumui/Struktur-Data-Assignment/assets/91511212/e6a9830e-12f7-40ff-ad96-b2c9529a3465)

Program ini dirancang untuk menentukan apakah kalimat yang dimasukkan pengguna merupakan palindrom atau bukan.

**Struktur Data:**

* **arrayData:** Array dengan ukuran maksimal 25 untuk menyimpan karakter-karakter dari kalimat.
* **maksimal:** Variabel yang menampung nilai maksimum elemen dalam array (25).
* **top:** Variabel yang menunjuk ke indeks elemen teratas dalam stack.

**Fungsi:**

* **isFull():** Memeriksa apakah stack sudah penuh dengan mengembalikan `true` jika `top` sama dengan `maksimal` dan `false` sebaliknya.
* **isEmpty():** Memeriksa apakah stack kosong dengan mengembalikan `true` jika `top` sama dengan 0 dan `false` sebaliknya.
* **pushArrayData(kalimat):** Menambahkan karakter-karakter dari kalimat ke dalam stack.
    * Memeriksa apakah stack penuh.
    * Jika stack tidak penuh, iterasi melalui setiap karakter dalam kalimat:
        * Konversi karakter menjadi string.
        * Masukkan string ke dalam array `arrayData` pada indeks `top`.
        * Naikkan nilai `top`.
    * Jika stack penuh, tampilkan pesan bahwa data telah penuh.
* **popArrayData():** Menghapus karakter-karakter dari stack.
    * Memeriksa apakah stack kosong.
    * Jika stack tidak kosong, kosongkan karakter pada array `arrayData` pada indeks `top-1`.
    * Turunkan nilai `top`.
    * Jika stack kosong, tampilkan pesan bahwa tidak ada data yang dihapus.
* **isPalindrom(kalimat):** Memeriksa apakah kalimat yang diberikan merupakan palindrom.
    * Menghitung panjang kalimat.
    * Memasukkan setengah karakter pertama dari kalimat ke dalam stack.
    * Membandingkan setengah karakter kedua dengan isi stack:
        * Jika karakter dari kalimat tidak sama dengan karakter pada stack, kembalikan `false`.
        * Jika sama, hapus karakter pada stack.
    * Jika semua karakter cocok, kembalikan `true`.

**Fungsi Utama (main):**

* Meminta pengguna untuk memasukkan kalimat.
* Memanggil fungsi `isPalindrom(kalimat)` untuk memeriksa apakah kalimat tersebut palindrom.
* Menampilkan pesan yang sesuai berdasarkan hasil pemeriksaan.

**Penjelasan Cara Kerja:**

1. **Memasukkan Kalimat:** Pengguna diminta untuk memasukkan kalimat melalui input `cin`. Kalimat ini disimpan dalam variabel `kalimat`.
2. **Memeriksa Palindrom:**
    * **Membagi Kalimat:** Kalimat dibagi menjadi dua bagian: setengah pertama dan setengah kedua.
    * **Memasukkan Setengah Pertama ke Stack:** Karakter-karakter dari setengah pertama kalimat dimasukkan ke dalam stack menggunakan fungsi `pushArrayData()`.
    * **Membandingkan dengan Setengah Kedua:** Karakter-karakter dari setengah kedua kalimat dibandingkan dengan karakter-karakter yang dikeluarkan dari stack menggunakan fungsi `popArrayData()`.
    * **Memeriksa Kesetaraan:** Jika semua karakter cocok, kalimat tersebut adalah palindrom. Jika ada ketidakcocokan, kalimat tersebut bukan palindrom.
3. **Menampilkan Hasil:** Program menampilkan pesan yang sesuai berdasarkan hasil pemeriksaan palindrom.

**Kesimpulan:**

Program ini menggunakan stack untuk menyimpan karakter-karakter dari kalimat dan membandingkannya secara berurutan untuk menentukan apakah kalimat tersebut merupakan palindrom. Stack digunakan secara efisien untuk menyimpan dan memanipulasi karakter-karakter kalimat, memungkinkan program untuk beroperasi dengan cepat dan efisien.


#### Full Code Screenshot:

![image](https://github.com/dkumui/Struktur-Data-Assignment/assets/91511212/7474610e-5437-4b4e-819c-370be73d4d79)

### 2. Buatlah program untuk melakukan pembalikan terhadap kalimat menggunakan stack dengan minimal 3 kata. Jelaskan output program dan source codenya beserta operasi/fungsi yang dibuat?

```C++
#include <iostream>
#include <string>

using namespace std;

// Mendefinisikan array dan variabel top dan maksimal
string arrayData[25];       // Array untuk menyimpan data
int maksimal = 25, top = 0; // maksimal adalah ukuran maksimum array, top adalah indeks teratas dari array

// Fungsi untuk memeriksa apakah array penuh
bool isFull()
{
    return (top == maksimal); // Mengembalikan true jika top sama dengan maksimal
}

// Fungsi untuk memeriksa apakah array kosong
bool isEmpty()
{
    return (top == 0); // Mengembalikan true jika top adalah 0, artinya tidak ada data
}

// Fungsi untuk menambahkan data ke dalam array
void pushArrayData(string kalimat)
{
    if (isFull())
    { // Memeriksa apakah array penuh
        cout << "Data telah penuh" << endl;
    }
    else
    {
        arrayData[top] = kalimat; // Menambahkan data ke dalam array di posisi top
        top++;                    // Menaikkan nilai top
    }
}

// Fungsi untuk menghapus data dari array
void popArrayData()
{
    if (isEmpty())
    { // Memeriksa apakah array kosong
        cout << "Tidak ada data yang dihapus" << endl;
    }
    else
    {
        arrayData[top - 1] = ""; // Menghapus data dengan mengosongkan nilai pada posisi top-1
        top--;                   // Menurunkan nilai top
    }
}

// Fungsi untuk membalikkan kalimat
void reverseKalimat(string kalimat)
{
    for (char &c : kalimat)
    {
        pushArrayData(string(1, c)); // Memasukkan setiap karakter ke dalam stack
    }

    string reversedString = "";
    while (!isEmpty())
    {
        reversedString += arrayData[top - 1]; // Mengambil karakter dari stack untuk membentuk kalimat terbalik
        popArrayData();
    }

    cout << "Hasil\t: " << reversedString << endl; // Menampilkan kalimat terbalik
}

// Fungsi utama
int main()
{
    string kalimat;
    cout << "Masukkan kalimat : ";
    getline(cin, kalimat); // Meminta input kalimat dari pengguna

    cout << "Kalimat\t: " << kalimat << endl; // Menampilkan kalimat awal
    reverseKalimat(kalimat);                  // Memanggil fungsi untuk membalikkan kalimat

    return 0;
}
```

#### Output:

![image](https://github.com/dkumui/Struktur-Data-Assignment/assets/91511212/2c3c5669-9a56-49f9-8154-e8a2e9e1e99c)

Sure, here is an explanation of the output, source code, and operations/functions of the provided program:

**Program ini dirancang untuk membalikkan kalimat yang dimasukkan pengguna.**

**Struktur Data:**

* **arrayData:** Array dengan ukuran maksimal 25 untuk menyimpan karakter-karakter dari kalimat.
* **maksimal:** Variabel yang menampung nilai maksimum elemen dalam array (25).
* **top:** Variabel yang menunjuk ke indeks elemen teratas dalam stack.

**Fungsi:**

* **isFull():** Memeriksa apakah stack sudah penuh dengan mengembalikan `true` jika `top` sama dengan `maksimal` dan `false` sebaliknya.
* **isEmpty():** Memeriksa apakah stack kosong dengan mengembalikan `true` jika `top` sama dengan 0 dan `false` sebaliknya.
* **pushArrayData(kalimat):** Menambahkan karakter-karakter dari kalimat ke dalam stack.
    * Memeriksa apakah stack penuh.
    * Jika stack tidak penuh, iterasi melalui setiap karakter dalam kalimat:
        * Konversi karakter menjadi string.
        * Masukkan string ke dalam array `arrayData` pada indeks `top`.
        * Naikkan nilai `top`.
    * Jika stack penuh, tampilkan pesan bahwa data telah penuh.
* **popArrayData():** Menghapus karakter-karakter dari stack.
    * Memeriksa apakah stack kosong.
    * Jika stack tidak kosong, kosongkan karakter pada array `arrayData` pada indeks `top-1`.
    * Turunkan nilai `top`.
    * Jika stack kosong, tampilkan pesan bahwa tidak ada data yang dihapus.
* **reverseKalimat(kalimat):** Membalikkan kalimat yang diberikan.
    * Memasukkan setiap karakter dari kalimat ke dalam stack.
    * Mengambil karakter dari stack satu per satu dan menggabungkannya ke dalam string baru.
    * String baru tersebut merupakan kalimat yang terbalik.
    * Mencetak kalimat terbalik.

**Fungsi Utama (main):**

* Meminta pengguna untuk memasukkan kalimat.
* Mencetak kalimat awal.
* Memanggil fungsi `reverseKalimat(kalimat)` untuk membalikkan kalimat.
* Mencetak kalimat terbalik.

**Output Program:**

Program ini akan meminta pengguna untuk memasukkan kalimat. Setelah itu, program akan mencetak kalimat awal dan kemudian kalimat terbalik.

**Contoh Output:**

```
Masukkan kalimat : Halo Dunia!
Kalimat\t: Halo Dunia!
Hasil\t: !ainuD olaH
```

**Operasi/Fungsi:**

* **Operasi Push:** Operasi ini menambahkan elemen baru ke bagian atas stack. Dalam program ini, operasi push digunakan untuk memasukkan karakter-karakter dari kalimat ke dalam stack.
* **Operasi Pop:** Operasi ini menghapus elemen teratas dari stack. Dalam program ini, operasi pop digunakan untuk mengambil karakter-karakter dari stack dan menggabungkannya ke dalam string baru yang merupakan kalimat terbalik.
* **Operasi IsFull:** Operasi ini memeriksa apakah stack sudah penuh. Dalam program ini, operasi isFull digunakan untuk memastikan bahwa stack tidak penuh sebelum menambahkan elemen baru.
* **Operasi IsEmpty:** Operasi ini memeriksa apakah stack kosong. Dalam program ini, operasi isEmpty digunakan untuk memastikan bahwa stack tidak kosong sebelum menghapus elemen.

**Kesimpulan:**

Program ini menggunakan stack untuk membalikkan kalimat secara efisien. Stack memungkinkan program untuk menyimpan dan memanipulasi karakter-karakter kalimat dengan mudah dan terstruktur.

#### Full Code Screenshot:

![image](https://github.com/dkumui/Struktur-Data-Assignment/assets/91511212/cebfaff4-403e-49c0-b6df-aefe4ca41dfc)

## Kesimpulan

Stack merupakan struktur data yang menerapkan konsep Last In First Out (LIFO) untuk menyimpan dan mengakses data secara efektif. Proses penambahan dan penghapusan data hanya dapat dilakukan pada satu ujung stack yaitu top, sehingga elemen terakhir yang dimasukkan akan menjadi elemen pertama yang dihapus. Terdapat beberapa operasi dasar pada stack meliputi push, pop, peek, isEmpty, isFull dan size. Implementasi stack bisa menggunakan array secara statis atau linked list secara dinamis tergantung kebutuhan. Aplikasi utama stack adalah untuk pembalikan urutan data seperti kalimat, menyelesaikan precedence operator aritmatika, dan backtracking algoritma. Dengan demikian, stack merupakan struktur data penting yang sering digunakan dalam memecahkan berbagai permasalahan programming.

## Referensi

[1] M. Rizqi, R. A. P. P. Pambudi, A. Awalludin, G. Z. Firmansyah, and S. P. P. P. Jatmiko, "Implementation of Stack Data Structure Using Linked List in C++ Programming Language," Journal of Physics: Conference Series, vol. 1900, no. 1, p. 012043, Mar. 2022, doi: 10.1088/1742-6596/1900/1/012043.

[2] M. Kakran, A. Panigrahy, and B. Bhatt, "Advance Data Structures Using C++," International Journal of Scientific & Technology Research, vol. 9, no. 3, pp. 1253-1256, Mar. 2020.

[3] N. Patel and C. Patel, "Efficient Implementation of Stack Using Array in C Programming," International Journal of Research in Electronics and Computer Engineering, vol. 8, no. 5, pp. 69-71, May 2022, doi: 10.37862/ijrece.v8i5.4349.

[4] M. Gulati and P. Sharma, "Implementation of Standard Stack Operations using Linked List in C Programming," International Journal of Engineering Research & Technology, vol. 13, no. 1, pp. 28-31, Jan. 2022. 

[5] S. Yogender, M. Sai, B. Sravan, and R. Venkata, "Implementation of Stack Operations using Doubly Linked List in C Programming Language," International Journal of Engineering Research & Technology, vol. 12, no. 1, pp. 23-26, Jan. 2023.