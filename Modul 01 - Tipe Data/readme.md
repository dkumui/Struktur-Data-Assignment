# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>

<p align="center">Muhammad Azka</p>

## Features

- [Dasar Teori](#dasar-teori)
- [Guided](#guided)
- [Unguided](#unguided)
- [Kesimpulan](#kesimpulan)
- [Referensi](#referensi)

## Dasar Teori

Tipe data merupakan cara untuk mengelompokkan dan mengklasifikasikan data dalam pemrograman. Ada tiga jenis tipe data utama yang umumnya digunakan:

### 1. Tipe Data Primitif:

Tipe data primitif adalah jenis data yang sudah ditentukan oleh sistem dan disediakan oleh banyak bahasa pemrograman. Contohnya:

- **Int**: Digunakan untuk menyimpan bilangan bulat seperti 12, 1, atau 4.
- **Float**: Menggunakan bilangan desimal seperti 1.5, 2.1, atau 3.14.
- **Char**: Berfungsi untuk menyimpan huruf atau simbol seperti A, B, C.
- **Boolean**: Digunakan untuk menyimpan nilai boolean, yaitu true atau false.

Karakteristik:

- Ukuran memori tetap.
- Dapat dioperasikan dengan operator aritmatika dan logika.
- Memiliki nilai default[1].

### 2. Tipe Data Abstrak:

Tipe data abstrak, atau Abstrak Data Type (ADT), dibentuk oleh programer dan bisa berisi berbagai jenis data. Fitur class dalam Object Oriented Programming (OOP) mirip dengan struktur data struct pada bahasa C++, dengan perbedaan akses default (public untuk struct, private untuk class).

Karakteristik:

- Fleksibilitas dalam membentuk jenis data sesuai kebutuhan.
- Struktur data statis.
- Akses default berbeda (public untuk struct, private untuk class)[1].

### 3. Tipe Data Koleksi:

Tipe data koleksi digunakan untuk mengelompokkan dan menyimpan beberapa nilai atau objek secara bersamaan. Beberapa contoh tipe data koleksi meliputi:

- **Array**: Struktur data statis dengan elemen-elemen tipe data yang sama dan ukuran tetap.
- **Vector**: Mirip dengan array, tetapi dinamis dengan alokasi memorinya otomatis.
- **Map**: Mirip dengan array, tetapi indeksnya bisa berupa tipe data selain integer, disebut "key", dan menggunakan struktur pohon self-balancing seperti Red-Black Tree pada std::map.

Karakteristik:

- Pengelolaan dan akses data yang terstruktur.
- Ukuran statis (array) atau dinamis (vector, map).
- Struktur data dinamis (vector, map) menggunakan Red-Black Tree[1].

Tipe data koleksi memungkinkan pengelolaan dan akses data yang lebih terstruktur, sementara tipe data abstrak memberikan fleksibilitas dalam membentuk jenis data sesuai kebutuhan programer. Tipe data primitif, di sisi lain, sudah ditentukan oleh sistem dengan perbedaan tergantung pada bahasa pemrograman dan sistem operasional yang digunakan.

### Perbandingan Tipe Data:

| Tipe Data |           Definisi           |                         Karakteristik                         |         Contoh         |
| :-------: | :--------------------------: | :-----------------------------------------------------------: | :--------------------: |
| Primitif  | Dasar, disediakan bahasa C++ | Ukuran memori tetap, operasi aritmatika/logika, nilai default | int, float, char, bool |
|  Abstrak  | Dibuat programer, fleksibel  |          Struktur data statis, akses default berbeda          |     struct, class      |
|  Koleksi  |  Mengelompokkan nilai/objek  |         Pengelolaan/akses terstruktur, statis/dinamis         |   array, vector, map   |

## [Guided](#guided)

### 1. Tipe Data Primitif

```C++
#include <iostream>
using namespace std;
// Main program
main()
{
    char op;
    float num1, num2;
    // It allows user to enter operator i.e. +, -, *, /
    cin >> op;
    // It allow user to enter the operands
    cin >> num1 >> num2;
    // Switch statement begins
    switch (op)
    {
    // If user enter +
    case '+':
        cout << num1 + num2;
        break;
    // If user enter -
    case '-':
        cout << num1 - num2;
        break;
    // If user enter *
    case '*':
        cout << num1 * num2;
        break;
    // If user enter /
    case '/':
        cout << num1 / num2;
        break;
    // If the operator is other than +, -, * or /,
    // error massage will display
    default:
        cout << "Error! operator is not correct";
    } // Switch statement ends
    return 0;
}
```

#### Output:

![image](https://github.com/dkumui/Struktur-Data-Assignment/assets/91511212/e440a49d-865f-48e7-b9c4-979d7b12ea9a)

Kode di atas adalah program yang meminta pengguna untuk memasukkan operator matematika (+, -, \*, /) dan dua bilangan floating-point. Setelah menerima input, program menggunakan switch statement untuk melakukan operasi sesuai dengan operator yang dimasukkan. Hasil operasi tersebut kemudian dicetak ke layar. Jika operator yang dimasukkan tidak sesuai dengan yang sudah disediakan, maka program akan mencetak pesan error. Program berakhir setelah operasi selesai dan hasilnya ditampilkan.

### 2. Tipe Data Abstrak

```C++
#include <stdio.h>

//struct
struct Mahasiswa
{
    const char *name;
    const char *address;
    int age;
};

int main()
{
    // Menggunakan struct
    struct Mahasiswa mhs1, mhs2;
    // Mengisi nilai ke struct
    mhs1.name = "Dian";
    mhs1.address = "Mataram";
    mhs1.age = 22;
    mhs2.name = "Bambang";
    mhs2.address = "Surabaya";
    mhs2.age = 23;

    // Mencetak isi struct
    printf("## Mahasiswa 1 ##\n");
    printf("Nama: %s\n", mhs1.name);
    printf("Alamat: %s\n", mhs1.address);
    printf("Umur: %d\n", mhs1.age);
    printf("## Mahasiswa 2 ##\n");
    printf("Nama: %s\n", mhs2.name);
    printf("Alamat: %s\n", mhs2.address);
    printf("Umur: %d\n", mhs2.age);
    return 0;
}
```

#### Output:

![image](https://github.com/dkumui/Struktur-Data-Assignment/assets/91511212/c98c67ca-4158-40ec-a911-6ca9d8430a70)

Kode di atas merupakan program yang menggunakan struktur data atau struct untuk merepresentasikan informasi mahasiswa. Dalam struct `Mahasiswa`, terdapat tiga anggota yaitu `name` (nama), `address` (alamat), dan `age` (umur). Program kemudian membuat dua variabel bertipe struct Mahasiswa, yaitu `mhs1` dan `mhs2`, dan mengisi nilai untuk masing-masing variabel.

Selanjutnya, program mencetak informasi mahasiswa ke layar menggunakan fungsi `printf`, termasuk nama, alamat, dan umur untuk kedua mahasiswa. Hasilnya adalah mencetak informasi mahasiswa 1 (mhs1) dan mahasiswa 2 (mhs2) ke layar sesuai dengan nilai yang telah diisikan sebelumnya.

### 3. Tipe Data Koleksi

```C++
#include <iostream>
using namespace std;
int main()
{
    //deklarasi dan inisialisasi array
    int nilai[5];
    nilai[0] = 23;
    nilai[1] = 50;
    nilai[2] = 34;
    nilai[3] = 78;
    nilai[4] = 90;

    //mencetak array
    cout << "Isi array pertama :" << nilai[0] << endl;
    cout << "Isi array kedua :" << nilai[1] << endl;
    cout << "Isi array ketiga :" << nilai[2] << endl;
    cout << "Isi array keempat :" << nilai[3] << endl;
    cout << "Isi array kelima :" << nilai[4] << endl;
    return 0;
}
```

#### Output:

![image](https://github.com/dkumui/Struktur-Data-Assignment/assets/91511212/ee3dff4d-694e-4047-be4c-bb2b5ee6debe)

Kode di atas adalah program yang menggunakan array untuk menyimpan beberapa nilai integer. Array tersebut bernama `nilai` dan memiliki panjang 5. Nilai-nilai tersebut diinisialisasi secara terpisah untuk setiap elemen array menggunakan indeks 0 hingga 4.

Selanjutnya, program mencetak setiap nilai dari array `nilai` ke layar menggunakan perintah `cout`. Hasilnya adalah mencetak nilai dari setiap elemen array, yaitu nilai[0], nilai[1], nilai[2], nilai[3], dan nilai[4], secara berurutan. Program kemudian mengembalikan nilai 0, menandakan bahwa program berjalan dengan sukses.

## Unguided

### 1. Buatlah program menggunakan tipe data primitif minimal dua fungsi dan bebas. Menampilkan program, jelaskan program tersebut dan ambil kesimpulan dari materi tipe data primitif!

```C++
#include <iostream>
using namespace std;

// Fungsi untuk menghitung luas persegi
int hitungLuasPersegi(int sisi) {
    return sisi * sisi;
}

// Fungsi untuk menghitung volume kubus
int hitungVolumeKubus(int sisi) {
    return sisi * sisi * sisi;
}

int main() {
    char pilihanMenu; // Deklarasi variabel yang digunakan untuk memproses menu pilihan user
    float ukuranSisi; // Deklarasi variabel yang digunakan untuk menampung data input dari user
    cout << "1. Hitung Luas Persegi\n2. Hitung Volume Kubus\nPilih Menu (1,2) :" << endl;
    cin >> pilihanMenu;

    switch (pilihanMenu)
    {
    case '1' :
        cout << "Masukkan  panjang sisi persegi: " <<endl;
        cin >> ukuranSisi;
        // Menampilkan hasil perhitungan luas persegi
        cout << "Luas Persegi dengan sisi " << ukuranSisi << " adalah: " << hitungLuasPersegi(ukuranSisi) << endl;
        break;
    case '2' :
        cout << "Masukkan  panjang sisi persegi: " <<endl;
        cin >> ukuranSisi;
        // Menampilkan hasil perhitungan volume kubus
        cout << "Volume Kubus dengan sisi " << ukuranSisi << " adalah: " << hitungVolumeKubus(ukuranSisi) << endl;
        break;
    default:
        cout << "Menu Tidak Ada";
    }
    return 0;
}
```

#### Output:

![image](https://github.com/dkumui/Struktur-Data-Assignment/assets/91511212/fba131a6-4220-454b-95eb-86d3509187f3)

Kode di atas adalah program yang memungkinkan pengguna memilih antara menghitung luas persegi atau volume kubus. Program meminta pengguna untuk memasukkan pilihan menu (1 untuk menghitung luas persegi, 2 untuk menghitung volume kubus).

Setelah memasukkan pilihan menu, program meminta pengguna untuk memasukkan panjang sisi persegi. Berdasarkan pilihan yang dimasukkan, program menggunakan fungsi-fungsi terpisah (`hitungLuasPersegi` dan `hitungVolumeKubus`) untuk melakukan perhitungan dan mencetak hasilnya ke layar.

Program ini menggunakan switch statement untuk memproses pilihan menu yang dimasukkan oleh pengguna dan memberikan output sesuai dengan operasi yang dipilih. Jika pengguna memasukkan pilihan yang tidak valid, program akan mencetak "Menu Tidak Ada".

#### Kesimpulan materi tipe data primitif:

Kesimpulan dari materi di atas adalah bahwa tipe data primitif adalah klasifikasi jenis data yang sudah ditentukan oleh sistem dan disediakan oleh berbagai bahasa pemrograman. Contoh tipe data primitif meliputi int untuk menyimpan bilangan bulat, float untuk bilangan desimal, char untuk huruf atau simbol, dan boolean untuk menyimpan nilai boolean dengan dua kemungkinan nilai, yaitu true atau false.

### 2. Jelaskan fungsi dari class dan struct secara detail dan berikan contoh programnya

#### Class

Class adalah suatu fitur dalam pemrograman berorientasi objek (OOP) yang memungkinkan programmer untuk membuat struktur data yang kompleks. Class digunakan untuk mendefinisikan sebuah tipe data baru yang dapat menyimpan data (atribut) dan perilaku (metode) bersama-sama. Dengan kata lain, class dapat digambarkan sebagai "blueprint" atau cetak biru untuk menciptakan objek. Setiap objek yang dibuat dari suatu class memiliki atribut dan metode yang sama, namun nilainya bisa berbeda.

#### Struct

Struct, singkatan dari structure, juga digunakan untuk membuat struktur data, tetapi memiliki perbedaan utama dengan class. Struct tidak memiliki kemampuan untuk menyembunyikan akses ke atribut atau metodenya, dan secara default bersifat public. Ini berarti semua anggota struct dapat diakses langsung dari luar struct.

#### Perbedaan

Perbedaan utama antara class dan struct adalah pada hak akses defaultnya. Dalam class, anggota bersifat private secara default, sementara dalam struct bersifat public secara default. Dengan class, kita dapat menggunakan hak akses private untuk menyembunyikan implementasi internal dari pengguna class, sementara struct lebih terbuka dan digunakan terutama untuk menyimpan data tanpa perilaku yang kompleks.

#### Contoh Program

```C++
#include <iostream>
#include <string>
using namespace std;

//Class biasa yang belum publik akses
class Employee {
    string nama;
    int umur;
    string email;
};

//Class yang sudah menjadi publik akses
class Employee2 {
public:
    string nama;
    int umur;
    string email;
};

struct Employeee {
    string nama;
    int umur;
    string email;
};

int main() {
    Employeee emp1;
    Employee2 emp2;

    emp1.nama = "Dundun";
    emp1.umur = 19;
    emp1.email = "dundunat@gmail.com";
    cout << "==== Employee 1 ===="
        << "\nNama: " << emp1.nama
        << "\nUmur: " << emp1.umur << " tahun"
        << "\nEmail: " << emp1.email << endl;

    emp2.nama = "Kumui";
    emp2.umur = 18;
    emp2.email = "kumuidd@gmail.com";
    cout << "==== Employee 2 ===="
        << "\nNama: " << emp2.nama
        << "\nUmur: " << emp2.umur << " tahun"
        << "\nEmail: " << emp2.email << endl;

    return 0;
}
```

#### Output:

![image](https://github.com/dkumui/Struktur-Data-Assignment/assets/91511212/4c478871-0264-4cd0-bca2-5f15770306b4)

#### Class Employee:

- Terdapat dua class Employee, satu tanpa deklarasi hak akses (default private) dan satunya dengan hak akses public.
- Class Employee pertama memiliki atribut nama, umur, dan email, tetapi anggotanya tidak dapat diakses langsung dari luar class karena hak akses private.
- Class Employee kedua memiliki hak akses public, sehingga atribut nama, umur, dan email dapat diakses dari luar class.

#### Struct Employeee:

- Terdapat struct Employeee dengan atribut nama, umur, dan email.
- Struct ini bersifat default public, sehingga atributnya dapat diakses langsung dari luar struct.

#### Fungsi main:

- Membuat objek emp1 dari struct Employeee dan objek emp2 dari class Employee2.
- Mengisi nilai atribut objek emp1 dan emp2.
- Menampilkan informasi karyawan (employee) menggunakan objek emp1 dan emp2 melalui cout.

Dengan demikian, program ini menunjukkan perbedaan dalam penggunaan class dan struct, terutama terkait dengan hak akses default anggota (private pada class, public pada struct). Objek emp1 menggunakan struct, sementara emp2 menggunakan class dengan hak akses public.

### 3. Buat dan jelaskan program menggunakan fungsi map dan jelaskan perbedaan dari array dengan map.

```C++
#include <iostream>
#include <map>
using namespace std;

int main() {
    // Deklarasi dan inisialisasi map
    map<int, int> nilai;
    nilai[0] = 60;
    nilai[1] = 25;
    nilai[2] = 87;
    nilai[3] = 12;
    nilai[4] = 56;

    // Mencetak nilai dari map
    for (const auto& pair : nilai) {
        cout << "Isi Array ke-" << pair.first + 1 << " : " << pair.second << endl;
    }

    return 0;
}
```

#### Output:

![image](https://github.com/dkumui/Struktur-Data-Assignment/assets/91511212/003b2158-1afc-4032-9341-63196154a7db)

Kode di atas menggunakan struktur data map untuk menyimpan pasangan nilai (key-value). Key dalam hal ini adalah indeks, dan value adalah nilai yang terkait. Setelah map diinisialisasi dan diisi dengan beberapa pasangan nilai, program menggunakan loop for untuk mencetak nilai dari setiap pasangan. Hasilnya adalah mencetak nilai-nilai tersebut ke layar tanpa nomor indeks array tertentu.

#### Perbedaan Dari Array dan Map:

- Array cocok digunakan ketika kita tahu ukuran data yang akan disimpan, sementara map lebih fleksibel karena dapat menyesuaikan ukurannya.
- Array diakses menggunakan indeks numerik, sementara map diakses menggunakan kunci unik untuk mendapatkan nilai yang terkait.
- Map lebih cocok untuk situasi di mana hubungan antara kunci dan nilai penting, sedangkan array digunakan untuk kumpulan data dengan indeks numerik.

Singkatnya, array cocok untuk situasi dengan data yang memiliki ukuran tetap dan diakses secara numerik, sementara map lebih fleksibel dan berguna untuk data yang memiliki hubungan kunci-nilai yang unik.

## Kesimpulan

Pemahaman tipe data, struktur data, dan konsep class/struct merupakan dasar yang penting dalam pemrograman. Tipe data primitif menyediakan dasar untuk menyimpan informasi, tipe data abstrak memberikan fleksibilitas, dan tipe data koleksi memungkinkan pengelolaan data yang terstruktur. Class dan struct memberikan kemampuan untuk membuat struktur data yang kompleks, sementara array dan map menyediakan cara penyimpanan yang berbeda untuk data yang beragam. Program-program contoh memberikan implementasi praktis dari konsep-konsep ini.

## Referensi

[1] Paul J. Deitel and Harvey M. Deitel, C++20 Programming - Fundamentals to Advanced Features, 1st ed. Boston, MA, USA: Pearson, 2020.

[2] "cppreference", [Online]. Available: https://en.cppreference.com/w/. [Accessed: March 7, 2024].
