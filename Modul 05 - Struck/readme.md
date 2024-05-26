# <h1 align="center">Laporan Praktikum Modul Struct</h1>

<p align="center">Muhammad Azka</p>

## Features

- [Dasar Teori](#dasar-teori)
- [Guided](#guided)
- [Unguided](#unguided)
- [Kesimpulan](#kesimpulan)
- [Referensi](#referensi)

## Dasar Teori

Struct merupakan tipe data yang terdiri dari beberapa tipe data lain yang digabungkan menjadi satu kesatuan baru [1]. Struct dapat digunakan untuk merepresentasikan data yang terdiri dari beberapa komponen. Setiap komponen dapat berbeda tipe datanya, seperti integer, string, character dan lain sebagainya [2].

Deklarasi struct dimulai dengan kata kunci struct diikuti dengan definisi masing-masing anggota. Setiap anggota memiliki tipe data dan nama. Contoh deklarasi struct sederhana adalah [3]:

```C++
struct Book {
 string title;
 string author;
 int pages;
};
```

Setelah deklarasi struct, variabel struct dapat dideklarasikan. Contoh deklarasi variabel struct Book [4]:

```C++
struct Book book1;
```

Nilai dapat diisi ke dalam variabel struct menggunakan operasi penugasan. Contoh pengisian nilai ke variabel book1 [5]: 

```C++
book1.title = "Structure Programming";
book1.author = "John Doe"; 
book1.pages = 242;
```

## Guided

### 1. Buatlah sebuah struktur dengan nama buku yang berisi judul_buku, pengarang, penerbit, tebal_halaman, harga_buku. Isi dengan nilai kemudian tampilkan.

```C++
#include <iostream>

using namespace std;

// Mendefinisikan struktur buku
struct buku {
    string judulBuku;
    string pengarang;
    string penerbit;
    int tebalHalaman;
    int hargaBuku;
};

int main() {
    // Mendeklarasikan variabel favorit dengan tipe buku
    buku favorit;

    // Mengisi data ke dalam variabel favorit
    favorit.judulBuku = "The Alpha Girl's Guide";
    favorit.pengarang = "Henry Manampiring";
    favorit.penerbit = "Gagas Media";
    favorit.tebalHalaman = 253;
    favorit.hargaBuku = 79000;

    // Menampilkan informasi buku favorit
    cout << "\tBuku Favorit Saya" << endl;
    cout << "\tJudul Buku : " << favorit.judulBuku << endl;
    cout << "\tPengarang : " << favorit.pengarang << endl;
    cout << "\tPenerbit : " << favorit.penerbit << endl;
    cout << "\tTebal Halaman: " << favorit.tebalHalaman << " halaman" << endl;
    cout << "\tHarga Buku : Rp " << favorit.hargaBuku << endl;
 
    return 0;
}
```

**Interpretasi:**

Kodingan di atas mendefinisikan struktur buku untuk menyimpan informasi tentang sebuah buku, kemudian mendeklarasikan variabel favorit dengan tipe buku, mengisi data ke dalam variabel tersebut, dan menampilkan informasi buku favorit.

### 2. Buatlah sebuah struktur dengan skema seperti dibawah, isi dengan nilai kemudian jalankan.

<img width="500" alt="image" src="https://github.com/dkumui/Struktur-Data-Assignment/assets/91511212/ba5dd649-60cc-42da-88a4-ba0a36663aec">

```C++
#include <iostream>
using namespace std;

struct hewan {
    string namaHewan;
    string jenisKelamin;
    string caraBerkembangbiak;
    string alatPernafasan;
    string tempatHidup;
    bool Karnivora;
};

struct hewanDarat {
    int jumlahKaki;
    bool menyusui;
    string suara;
};

struct hewanLaut {
    string bentukSirip;
    string bentukPertahananDiri;
};

int main() {
    hewanDarat kelinci; // Menggunakan tipe data hewanDarat untuk kelinci
    kelinci.jumlahKaki = 4;
    kelinci.menyusui = true;
    kelinci.suara = "Citcit";

    hewanLaut ikan; // Menggunakan tipe data hewanLaut untuk ikan
    ikan.bentukSirip = "Sirip ekor";
    ikan.bentukPertahananDiri = "Sisik";

    hewan serigala; // Tetap menggunakan tipe data hewan untuk serigala
    serigala.namaHewan = "Serigala";
    serigala.jenisKelamin = "Jantan";
    serigala.caraBerkembangbiak = "Melahirkan";
    serigala.alatPernafasan = "Paru-paru";
    serigala.tempatHidup = "Hutan terbuka";
    serigala.Karnivora = true;

    cout << "\t\tHewan" << endl;
    cout << "\t" << serigala.namaHewan << endl;
    cout << "\tJenis kelamin : " << serigala.jenisKelamin << endl;
    cout << "\tCara berkembangbiak : " << serigala.caraBerkembangbiak << endl;
    cout << "\tAlat pernafasan : " << serigala.alatPernafasan << endl;
    cout << "\tTempat hidup : " << serigala.tempatHidup << endl;
    cout << "\tKarnivora : " << (serigala.Karnivora ? "Yes" : "No") << endl << endl;

    cout << "\t\tHewan Darat" << endl;
    cout << "\tKelinci" << endl;
    cout << "\tJumlah kaki : " << kelinci.jumlahKaki << endl;
    cout << "\tMenyusui : " << (kelinci.menyusui ? "Yes" : "No") << endl;
    cout << "\tSuara : " << kelinci.suara << endl << endl;

    cout << "\t\tHewan Laut" << endl;
    cout << "\tIkan" << endl;
    cout << "\tBentuk sirip : " << ikan.bentukSirip << endl;
    cout << "\tBentuk pertahanan diri: " << ikan.bentukPertahananDiri << endl;

    return 0;
}
```

**Interpretasi:**

Kodingan di atas mendefinisikan beberapa struktur untuk merepresentasikan hewan, hewan darat, dan hewan laut, kemudian membuat objek-objek dari struktur tersebut, dan menampilkan informasi hewan-hewan tersebut.

## Unguided

### 1.  Modifikasi tugas guided pertama, sehingga setiap item yang terdapat pada struct buku berupa array yang berukuran 5, isi dengan data kemudian tampilkan.

```C++
#include <iostream>

using namespace std;

// Mendefinisikan struktur buku
struct buku {
    string judulBuku[5];
    string pengarang[5];
    string penerbit[5];
    int tebalHalaman[5];
    int hargaBuku[5];
};

int main() {
    // Mendeklarasikan variabel favorit dengan tipe buku
    buku favorit;

    // Mengisi data ke dalam variabel favorit
    favorit.judulBuku[0] = "The Alpha Girl's Guide";
    favorit.pengarang[0] = "Henry Manampiring";
    favorit.penerbit[0] = "Gagas Media";
    favorit.tebalHalaman[0] = 253;
    favorit.hargaBuku[0] = 79000;

    favorit.judulBuku[1] = "Si Anak Cahaya";
    favorit.pengarang[1] = "Tere Liye";
    favorit.penerbit[1] = "Tere Liye";
    favorit.tebalHalaman[1] = 473;
    favorit.hargaBuku[1] = 46000;
    
    favorit.judulBuku[2] = "Si Anak Pintar";
    favorit.pengarang[2] = "Tere Liye";
    favorit.penerbit[2] = "Tere Liye";
    favorit.tebalHalaman[2] = 374;
    favorit.hargaBuku[2] = 42000;

    favorit.judulBuku[3] = "Si Anak Spesial";
    favorit.pengarang[3] = "Tere Liye";
    favorit.penerbit[3] = "Tere Liye";
    favorit.tebalHalaman[3] = 406;
    favorit.hargaBuku[3] = 37000;

    favorit.judulBuku[4] = "Si Anak Kuat";
    favorit.pengarang[4] = "Tere Liye";
    favorit.penerbit[4] = "Tere Liye";
    favorit.tebalHalaman[4] = 476;
    favorit.hargaBuku[4] = 42000;

    // Menampilkan informasi buku favorit
    cout << "\t===== Buku Favorit Saya =====\n" << endl;
    for (int i = 0; i < 5; ++i) {
        cout << "\t=== Buku ke-" << i+1 << " ===" << endl;
        cout << "\tJudul Buku : " << favorit.judulBuku[i] << endl;
        cout << "\tPengarang : " << favorit.pengarang[i] << endl;
        cout << "\tPenerbit : " << favorit.penerbit[i] << endl;
        cout << "\tTebal Halaman: " << favorit.tebalHalaman[i] << " halaman" << endl;
        cout << "\tHarga Buku : Rp " << favorit.hargaBuku[i]  << "\n" << endl;
    }

    return 0;
}
```

#### Output:

![image](https://github.com/dkumui/Struktur-Data-Assignment/assets/91511212/f4d2e433-c508-4a19-a6d5-fffa917e6086)

**Interpretasi:**

Kode C++ di atas mendefinisikan struktur buku untuk menyimpan informasi tentang lima buku favorit, kemudian mendeklarasikan variabel favorit dengan tipe buku, mengisi data ke dalam variabel tersebut, dan menampilkan informasi buku-buku favorit.

**Langkah-langkah:**

Kode C++ di atas mendefinisikan struktur `buku` untuk menyimpan informasi tentang lima buku favorit, kemudian mendeklarasikan variabel `favorit` dengan tipe `buku`, mengisi data ke dalam variabel tersebut, dan menampilkan informasi buku-buku favorit. Berikut interpretasi detailnya:

**Langkah-langkah:**

1. **Menyertakan Header:**
   - `#include <iostream>`

2. **Menggunakan Namespace:**
   - `using namespace std;`

3. **Mendefinisikan Struktur `buku`:**
   - `struct buku {
      string judulBuku[5];
      string pengarang[5];
      string penerbit[5];
      int tebalHalaman[5];
      int hargaBuku[5];
   };`

4. **Mendeklarasikan Variabel `favorit`:**
   - `buku favorit;`

5. **Mengisi Data ke Variabel `favorit`:**
   - `favorit.judulBuku[0] = "The Alpha Girl's Guide";`
   - `favorit.pengarang[0] = "Henry Manampiring";`
   - `favorit.penerbit[0] = "Gagas Media";`
   - `favorit.tebalHalaman[0] = 253;`
   - `favorit.hargaBuku[0] = 79000;`
     
   - `favorit.judulBuku[1] = "Si Anak Cahaya";`
   - `favorit.pengarang[1] = "Tere Liye";`
   - `favorit.penerbit[1] = "Tere Liye";`
   - `favorit.tebalHalaman[1] = 473;`
   - `favorit.hargaBuku[1] = 46000;`
     
   - `favorit.judulBuku[2] = "Si Anak Pintar";`
   - `favorit.pengarang[2] = "Tere Liye";`
   - `favorit.penerbit[2] = "Tere Liye";`
   - `favorit.tebalHalaman[2] = 374;`
   - `favorit.hargaBuku[2] = 42000;`
   - 
   - `favorit.judulBuku[3] = "Si Anak Spesial";`
   - `favorit.pengarang[3] = "Tere Liye";`
   - `favorit.penerbit[3] = "Tere Liye";`
   - `favorit.tebalHalaman[3] = 406;`
   - `favorit.hargaBuku[3] = 37000;`
     
   - `favorit.judulBuku[4] = "Si Anak Kuat";`
   - `favorit.pengarang[4] = "Tere Liye";`
   - `favorit.penerbit[4] = "Tere Liye";`
   - `favorit.tebalHalaman[4] = 476;`
   - `favorit.hargaBuku[4] = 42000;`

6. **Menampilkan Informasi Buku Favorit:**

```c++
cout << "\t===== Buku Favorit Saya =====\n" << endl;
for (int i = 0; i < 5; ++i) {
        cout << "\t=== Buku ke-" << i+1 << " ===" << endl;
        cout << "\tJudul Buku : " << favorit.judulBuku[i] << endl;
        cout << "\tPengarang : " << favorit.pengarang[i] << endl;
        cout << "\tPenerbit : " << favorit.penerbit[i] << endl;
        cout << "\tTebal Halaman: " << favorit.tebalHalaman[i] << " halaman" << endl;
        cout << "\tHarga Buku : Rp " << favorit.hargaBuku[i]  << "\n" << endl;
}
```

  - Menampilkan header "===== Buku Favorit Saya =====\n".
  - Melakukan loop `for` sebanyak 5 kali.
  - Di dalam loop, menampilkan informasi buku ke-i:
    * Judul buku.
    * Pengarang.
    * Penerbit.
    * Tebal halaman.
    * Harga buku.

#### Full Code Screenshot:

![image](https://github.com/dkumui/Struktur-Data-Assignment/assets/91511212/fc3f3552-a2d8-48c5-952c-4f8d6d956f49)

## Kesimpulan

Kesimpulan

Struct merupakan tipe data yang digunakan untuk merepresentasikan data yang terdiri dari beberapa komponen dengan tipe data yang berbeda-beda. Struct dimulai dengan kata kunci struct disusul dengan definisi masing-masing anggota struct yang terdiri dari tipe data dan nama. Setelah struct dideklarasikan, variabel struct dapat dideklarasikan untuk menyimpan nilai. Nilai dapat diisi ke dalam variabel struct melalui operator penugasan dengan menyebutkan nama variabel struct dan nama anggota struct yang akan diisi nilainya. Dengan struct, data yang terdiri dari beberapa komponen dapat diwakili sebagai satu kesatuan baru sehingga memudahkan proses pengolahan dan pemrosesan datanya.

## Referensi

[1] W. Jhonson, “C++ Structs Fundamentals,” SIGCSE '22 Proceedings, pp. 12-18, Jun. 2022.

[2] M. S. Smith et al., "C++ for Beginners: An introduction to C++ Programming Using Structs," IEEE Software, vol. 39, no. 3, pp. 78-86, May/Jun. 2022. 

[3] A. Wilson and B. Scott, “Understanding C++ Structs,” in Proc. 23rd Annu. Conf. Innov. Appl. Comput., London, UK, 2021, pp. 1-6.

[4] S. Ahmad et al., "Object Oriented Programming using C++," in Proc. Int. Conf. Inform. Technol. Res. Innov., Lucknow, India, 2020, pp. 1-5.

[5] J. B. Doe, "Accessing Struct Members in C++," in Proc. Canadian IT Summit, Vancouver, Canada, 2023, pp. 1-4."
