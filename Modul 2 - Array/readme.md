# <h1 align="center">Laporan Praktikum Modul Array</h1>

<p align="center">Muhammad Azka - 2311110049</p>

## Features

- [Dasar Teori](#dasar-teori)
- [Guided](#guided)
- [Unguided](#unguided)
- [Kesimpulan](#kesimpulan)
- [Referensi](#referensi)

## Dasar Teori

Array (larik) ialah penampung sejumlah data sejenis (homogen) yang menggunakan satu identifier (pengenal). Masing-masing elemen larik diakses menggunakan indeks (subscript) dari nol sampai n-1 (n menyatakan jumlah elemen
larik). Pengolahan data larik harus per elemen. Elemen larik dapat diakses langsung (acak). Tujuannya adalah untuk memanipulasi elemen keempat tidak harus melalui elemen
pertama, kedua, dan ketiga. Berdasarkan banyaknya indeks, larik dibagi menjadi larik satu dimensi dan multidimensi (dua dimensi dan tiga dimensi)[1].

### 1. Array Satu Dimensi:

Array satu dimensi adalah kumpulan elemen yang bersebelahan di mana individu elemen diidentifikasi oleh subskrip integer unik yang dimulai dengan nol. Sekali array dibuat, ukurannya tidak dapat diubah[2]. Dapat disebut juga dengan istilah vektor yang menggambarkan data dalam suatu urutan

### 2. Array Dua Dimensi

Array dua demensi yakni suatu kumpulan elemen yang dapat dilakukan penyimpanan secara terurut di suatu tempat yang terbagi menjadi dua 2 unsur yakni baris dan kolom[2]. Sering digambarkan sebagai sebuah matriks yaitu sekumpulan informasi yang setiap individu elemennya diacu dengan menggunakan dua buah indeks (biasanya dikonotasikan dengan baris dan kolom)[1].

### 3. Array Multi Dimensi

Array multidimensi adalah larik yang berisi satu atau lebih larik. Array Multidimensi merupakan array yang serupa dengan array satu dimensi maupun array dua dimensi, namun array multidimensi dapat memiliki memori yang lebih besar. Biasanya array multidimensi digunakan untuk menyebut array dengan dimensi lebih dari dua atau array yang mempunyai lebih dari dua subskrip, seperti untuk menyebut array tiga dimensi, empat dimensi, lima dimensi dan seterusnya[3].

### Keunggulan dan Kelemahan Array:
#### Keunggulan: 
- Array sangat cocok untuk pengaksesan acak. Sembarang elemen di array dapat diacu secara langsung tanpa melalui elemen-elemen lain[4].
- Jika berada di suatu lokasi elemen, maka sangat mudah menelusuri ke elemen-elemen tetangga, baik elemen pendahulu atau elemen penerus 3[4].
- Jika elemen-elemen array adalah nilai-nilai independen dan seluruhnya harus terjaga, maka penggunaan penyimpanannya sangat efisien[4].

#### Kelemahan:
Array mempunyai fleksibilitas rendah, sehingga tidak cocok untuk berbagai aplikasi karena array mempunyai batasan sebagai berikut:
- Array harus bertipe homogen. Kita tidak dapat mempunyai array dimana satu elemen adalah karakter, elemen lain bilangan, dan elemen lain adalah tipe-tipe lain[4].
- Kebanyakan bahasa pemrograman mengimplementasikan array statik yang sulit diubah ukurannya di waktu eksekusi. Bila penambahan dan pengurangan terjadi terus-menerus, maka representasi statis[4].
- Tidak efisien dalam penggunaan memori[4].
- Menyiakan banyak waktu komputasi[4].

## Guided

### 1. Program Input Array Tiga Dimensi

```C++
#include <iostream>
using namespace std;
// PROGRAM INPUT ARRAY 3 DIMENSI
int main()
{
  // Deklarasi array
  int arr[2][3][3];
  // Input elemen
  for (int x = 0; x < 2; x++)
  {
    for (int y = 0; y < 3; y++)
    {
      for (int z = 0; z < 3; z++)
      {
        cout << "Input Array[" << x << "][" << y << "][" << z << "] = ";
        cin >> arr[x][y][z];
      }
    }
    cout << endl;
  }
  // Output Array
  for (int x = 0; x < 2; x++)
  {
    for (int y = 0; y < 3; y++)
    {
      for (int z = 0; z < 3; z++)
      {
        cout << "Data Array[" << x << "][" << y << "][" << z << "] = " << arr[x][y][z] << endl;
      }
    }
  }
  cout << endl;
  // Tampilan array
  for (int x = 0; x < 2; x++)
  {
    for (int y = 0; y < 3; y++)
    {
      for (int z = 0; z < 3; z++)
      {
        cout << arr[x][y][z] << ends;
      }
      cout << endl;
    }
    cout << endl;
  }
}
```

program mendeklarasikan array `arr` dengan dimensi `[2][3][3]`. Kemudian, program meminta pengguna untuk memasukkan nilai-nilai ke dalam array tersebut dengan menggunakan tiga nested loop. Pertama, loop pertama digunakan untuk mengakses elemen di dimensi pertama `x`, loop kedua untuk dimensi kedua `y`, dan loop ketiga untuk dimensi ketiga `z`. Setelah selesai memasukkan nilai, program kemudian menampilkan nilai-nilai yang telah dimasukkan.

Selanjutnya, program akan menampilkan kembali nilai-nilai array dalam format yang terstruktur dengan mencetak indeks `x`, `y`, `z`, beserta nilainya. Terakhir, program akan menampilkan kembali nilai-nilai array dalam format yang lebih sederhana tanpa indeks `x`, `y`, `z`, hanya nilai-nilainya saja.

### 2. Program Mencari Nilai Maksimal pada Array

```C++
#include <iostream>
using namespace std;

int main()
{
    int maks, a, i = 1, lokasi;
    cout << "Masukkan panjang array: ";
    cin >> a;
    int array[a];
    cout << "Masukkan " << a << " angka\n";
    for (i = 0; i < a; i++)
    {
        cout << "Array ke-" << (i) << ": ";
        cin >> array[i];
    }
    maks = array[0];
    for (i = 0; i < a ; i++)
    {
        if (array[i] > maks)
        {
            maks = array[i];
            lokasi = i;
        }
    }
    cout << "Nilai maksimum adalah " << maks << " berada di array ke-" << lokasi << endl;
}
```

Program meminta untuk memasukkan panjang array yang diinginkan. Setelah panjang array dimasukkan, program mendeklarasikan array dengan panjang tersebut. Kemudian, program meminta user untuk memasukkan nilai-nilai elemen array satu per satu.

Setelah semua nilai dimasukkan, program melakukan iterasi melalui setiap elemen array untuk menemukan nilai maksimum. Variabel `maks` diinisialisasi dengan nilai elemen pertama array. Selanjutnya, program membandingkan setiap elemen array dengan nilai `maks`. Jika nilai elemen array saat ini lebih besar dari `maks`, maka nilai `maks` diperbarui dengan nilai elemen array tersebut, dan lokasi elemen tersebut disimpan dalam variabel `lokasi`.

Setelah proses selesai, program mengeluarkan hasil berupa nilai maksimum yang ditemukan beserta lokasinya dalam array.

## Unguided

### 1. Buatlah program untuk menampilkan Output seperti berikut dengan data yang diinputkan oleh user!

<img src="https://github.com/dkumui/Struktur-Data-Assignment/assets/91511212/887a9b1e-a3bc-4131-8fcb-7837a9d9e779" width="500">

```C++
#include <iostream>

using namespace std;

int main() {
  int n;
  cout << "\nMasukkan jumlah elemen array: ";
  cin >> n;

  int arr[n];
  cout << "Masukkan data array: ";
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  cout << "\nData Array: ";
  for (int i = 0; i < n; i++) {
    cout << arr[i] << ", ";
  }

  cout << "\nNomor Genap: ";
  for (int i = 0; i < n; i++) {
    if (arr[i] % 2 == 0) {
      cout << arr[i] << ", ";
    }
  }

  cout << "\nNomor Ganjil: ";
  for (int i = 0; i < n; i++) {
    if (arr[i] % 2 != 0) {
      cout << arr[i] << " ";
    }
  }

  cout << endl;

  return 0;
}
```

#### Output:

<img src="https://github.com/dkumui/Struktur-Data-Assignment/assets/91511212/35242d31-2271-45b8-938a-fc6309b99017" width="750">

Kodingan di atas adalah sebuah program yang meminta pengguna untuk memasukkan jumlah elemen array, kemudian meminta pengguna untuk memasukkan data untuk setiap elemen array. Setelah itu, program menampilkan data array tersebut, kemudian memisahkan antara angka genap dan angka ganjil, dan menampilkan angka-angka tersebut secara terpisah.

#### Full Code Screenshot:

![image](https://github.com/dkumui/Struktur-Data-Assignment/assets/91511212/76781fef-f9d6-4574-a8fa-b2c2091bf369)

### 2. Buatlah program Input array tiga dimensi (seperti pada guided) tetapi jumlah atau ukuran elemennya diinputkan oleh user!

```C++
#include <iostream>
using namespace std;

int main() {
    // Deklarasi variabel untuk menyimpan ukuran array
    int size_x, size_y, size_z;

    // Meminta pengguna untuk memasukkan ukuran array
    cout << "Masukkan ukuran array (x y z): ";
    cin >> size_x >> size_y >> size_z;

    // Deklarasi array sesuai dengan ukuran yang dimasukkan pengguna
    int arr[size_x][size_y][size_z];

    // Input elemen array
    for (int x = 0; x < size_x; x++) {
        for (int y = 0; y < size_y; y++) {
            for (int z = 0; z < size_z; z++) {
                cout << "Input Array[" << x << "][" << y << "][" << z << "] = ";
                cin >> arr[x][y][z];
            }
        }
        cout << endl;
    }

    // Tampilan array
    cout << "Array:\n";
    for (int x = 0; x < size_x; x++) {
        for (int y = 0; y < size_y; y++) {
            for (int z = 0; z < size_z; z++) {
                cout << arr[x][y][z] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
```

#### Output:

![image](https://github.com/dkumui/Struktur-Data-Assignment/assets/91511212/52e308e3-739b-4824-a32a-b041250ee2b8)

Kodingan di atas adalah sebuah program yang memungkinkan pengguna untuk memasukkan ukuran array tiga dimensi (x, y, dan z) dan kemudian memasukkan nilai-nilai untuk setiap elemen array. Setelah itu, program menampilkan array tersebut dalam bentuk tiga dimensi.

#### Full Code Screenshot:

![image](https://github.com/dkumui/Struktur-Data-Assignment/assets/91511212/64235661-ac13-42c9-ad46-606555b63500)

### 3. Buatlah program menu untuk mencari nilai Maksimum, Minimum dan Nilai rata – rata dari suatu array dengan input yang dimasukan oleh user!

```C++
#include <iostream>

using namespace std;

int main() {
  int n;
  cout << "Masukkan jumlah nilai: ";
  cin >> n;

  int arr[n];
  cout << "Masukkan data nilai: ";
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  int max = arr[0], min = arr[0], sum = 0;
  for (int i = 1; i < n; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
    if (arr[i] < min) {
      min = arr[i];
    }
    sum += arr[i];
  }

  float avg = (float)sum / n;

  int choice;
  do {
    cout << "\nMenu:" << endl;
    cout << "1. Tampilkan nilai maksimum" << endl;
    cout << "2. Tampilkan nilai minimum" << endl;
    cout << "3. Tampilkan nilai rata-rata" << endl;
    cout << "0. Keluar" << endl;

    cout << "Masukkan pilihan: ";
    cin >> choice;

    switch (choice) {
      case 1:
        cout << "Nilai maksimum: " << max << endl;
        break;
      case 2:
        cout << "Nilai minimum: " << min << endl;
        break;
      case 3:
        cout << "Nilai rata-rata: " << avg << endl;
        break;
      case 0:
        cout << "Terima kasih!" << endl;
        break;
      default:
        cout << "Pilihan tidak valid!" << endl;
    }
  } while (choice != 0);

  return 0;
}
```

#### Output:

![image](https://github.com/dkumui/Struktur-Data-Assignment/assets/91511212/f409502f-7918-45f4-9288-67fc39aa8568)

Kodingan di atas merupakan sebuah program sederhana yang meminta pengguna untuk memasukkan sejumlah nilai, kemudian program tersebut akan menampilkan beberapa pilihan statistik dasar dari nilai-nilai tersebut seperti nilai maksimum, nilai minimum, dan rata-rata.

#### Full Code Screenshot:

![image](https://github.com/dkumui/Struktur-Data-Assignment/assets/91511212/77e05fed-44a0-41fb-aa5b-cec20be1b9e2)

## Kesimpulan

Array merupakan struktur data yang digunakan untuk menyimpan kumpulan nilai yang serupa dengan tipe data yang sama dalam satu variabel. Dalam array, elemen-elemen disimpan secara berurutan dalam memori dan diakses melalui indeks. Penggunaan array memungkinkan pengelolaan data yang efisien dan memudahkan akses terhadap nilai-nilai tersebut. Namun, perlu diingat bahwa ukuran array biasanya tetap setelah dideklarasikan, sehingga perlu hati-hati dalam pengelolaan memori agar tidak terjadi overflow atau underflow. Array juga memungkinkan penggunaan banyak algoritma dan teknik pemrograman yang berguna, seperti pencarian dan pengurutan. Dengan pemahaman yang baik tentang array dalam C++, program dapat lebih efisien dan mudah untuk dikembangkan.

## Referensi

[1] Mulyana, A., et al., Cara Mudah Mempelajari Algoritma dan Struktur Data. Edisi Pertama. Yogyakarta : DIVA Press, 2021

[2] Zein, A. dan Eriana, E.S., Algoritma dan Struktur Data. Edisi Pertama. Tangerang Selatan : Unpam Press, 2022.

[3] Rus'an, J.A.P., “Program C++ : Array Multidimensi Menghitung Nilai Tertinggi, Perkalian Matriks, dan Rata-rata”, 30-Des-2022. [Online]. Available: https://medium.com/@jasmeinalbaar29/program-c-array-multidimensi-menghitung-nilai-tertinggi-perkalian-matriks-dan-rata-rata-3d175f2792da.

[4] A. Suhendar, “Struktur data sederhana (statis array)”, 30-Mar-2019. [Online]. Available: https://osf.io/preprints/osf/s2r57.

[5] "geeksforgeeks", [Online]. Available: https://www.geeksforgeeks.org/. [Accessed: March 15, 2024].
