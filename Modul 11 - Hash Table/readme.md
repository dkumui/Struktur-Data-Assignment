# <h1 align="center">Laporan Praktikum Modul Hash Table</h1>

<p align="center">Muhammad Azka</p>

## Features

- [Dasar Teori](#dasar-teori)
- [Guided](#guided)
- [Unguided](#unguided)
- [Kesimpulan](#kesimpulan)
- [Referensi](#referensi)

## Dasar Teori

Hash table adalah struktur data yang digunakan untuk menyimpan pasangan kunci-nilai [1]. Hash table terdiri dari dua komponen utama, yaitu array dan fungsi hash. Fungsi hash digunakan untuk mengonversi kunci menjadi indeks array dan menyimpan nilai yang sesuai pada lokasi tersebut [2].  Dengan menggunakan fungsi hash, proses pencarian data dapat dilakukan dalam waktu konstan O(1) [3]. 

Ada beberapa metode yang dapat digunakan untuk mengatasi collision pada hash table, diantaranya:

1. Chaining
   Metode ini menyimpan data yang terjadi collision pada linked list yang terkait dengan indeks array tertentu [4].

2. Open addressing 
   Metode ini mencari selanjutnya posisi kosong pada array apabila terjadi collision, seperti linear probing dan double hashing [5].

Implementasi hash table dalam bahasa C++ dapat dilakukan dengan menggunakan class, struct, dan pointer. Fungsi hash dapat diimplementasikan untuk menghasilkan indeks, sedangkan struct digunakan untuk mewakili node data. Pointer digunakan untuk menyimpan head node pada setiap indeks array [6].

## Guided

### 1. Guided pertama

```C++
#include <iostream>
using namespace std;
const int MAX_SIZE = 10;

// Fungsi hash sederhana
int hash_func(int key)
{
    return key % MAX_SIZE;
}

// Struktur data untuk setiap node
struct Node
{
    int key;
    int value;
    Node *next;
    Node(int key, int value) : key(key), value(value), next(nullptr) {}
};

// Class hash table
class HashTable
{
private:
    Node **table;

public:
    HashTable()
    {
        table = new Node *[MAX_SIZE]();
    }
    ~HashTable()
    {
        for (int i = 0; i < MAX_SIZE; i++)
        {
            Node *current = table[i];
            while (current != nullptr)
            {
                Node *temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] table;
    }

    // Insertion
    void insert(int key, int value)
    {
        int index = hash_func(key);
        Node *current = table[index];
        while (current != nullptr)
        {
            if (current->key == key)
            {
                current->value = value;
                return;
            }
            current = current->next;
        }
        Node *node = new Node(key, value);
        node->next = table[index];
        table[index] = node;
    }

    // Searching
    int get(int key)
    {
        int index = hash_func(key);
        Node *current = table[index];
        while (current != nullptr)
        {
            if (current->key == key)
            {
                return current->value;
            }
            current = current->next;
        }
        return -1;
    }

    // Deletion
    void remove(int key)
    {
        int index = hash_func(key);
        Node *current = table[index];
        Node *prev = nullptr;
        while (current != nullptr)
        {
            if (current->key == key)
            {
                if (prev == nullptr)
                {
                    table[index] = current->next;
                }
                else
                {
                    prev->next = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }

    // Traversal
    void traverse()
    {
        for (int i = 0; i < MAX_SIZE; i++)
        {
            Node *current = table[i];
            while (current != nullptr)
            {
                cout << current->key << ": " << current->value << endl;
                current = current->next;
            }
        }
    }
};

int main()
{
    HashTable ht;
    // Insertion
    ht.insert(1, 10);
    ht.insert(2, 20);
    ht.insert(3, 30);

    // Searching
    cout << "Get key 1: " << ht.get(1) << endl;
    cout << "Get key 4: " << ht.get(4) << endl;

    // Deletion
    ht.remove(4);

    // Traversal
    ht.traverse();

    return 0;
}
```

### Interpretasi

Kodingan ini mengimplementasikan tabel hash sederhana untuk menyimpan data key-value.

**Fitur utama:**

* Menyimpan data dalam pasangan key-value.
* Mencari value berdasarkan key.
* Menambahkan pasangan key-value baru.
* Menghapus pasangan key-value.
* Mencetak semua key-value.

**Struktur:**

* Struktur `Node` menyimpan key, value, dan pointer ke node berikutnya.
* Kelas `HashTable` mengelola tabel hash dan operasi terkait.
* Fungsi `hash_func` memetakan key ke indeks.

**Contoh penggunaan:**

* Menyimpan data key-value (key 1 dengan value 10, key 2 dengan value 20, dll.).
* Mencari value berdasarkan key (misal, key 1 menghasilkan value 10).
* Menghapus pasangan key-value (misal, key 4 dihapus).
* Mencetak semua key-value yang tersimpan.

**Kesimpulan:**

Kodingan ini menunjukkan dasar tabel hash untuk menyimpan data key-value.Kodingan ini dapat dikembangkan dengan fitur tambahan seperti resize otomatis, fungsi hash yang lebih baik, dan persistensi data.

### 2. Guided kedua

```C++
#include <iostream>
#include <string>
#include <vector>

using namespace std;
const int TABLE_SIZE = 11;

string name;
string phone_number;

class HashNode
{
public:
    string name;
    string phone_number;

    HashNode(string name, string phone_number)
    {
        this->name = name;
        this->phone_number = phone_number;
    }
};

class HashMap
{
private:
    vector<HashNode *> table[TABLE_SIZE];

public:
    int hashFunc(string key)
    {
        int hash_val = 0;
        for (char c : key)
        {
            hash_val += c;
        }
        return hash_val % TABLE_SIZE;
    }

    void insert(string name, string phone_number)
    {
        int hash_val = hashFunc(name);

        for (auto node : table[hash_val])
        {
            if (node->name == name)
            {
                node->phone_number = phone_number;
                return;
            }
        }
        table[hash_val].push_back(new HashNode(name, phone_number));
    }

    void remove(string name)
    {
        int hash_val = hashFunc(name);

        for (auto it = table[hash_val].begin(); it != table[hash_val].end(); it++)
        {
            if ((*it)->name == name)
            {
                table[hash_val].erase(it);
                return;
            }
        }
    }

    string searchByName(string name)
    {
        int hash_val = hashFunc(name);
        for (auto node : table[hash_val])
        {
            if (node->name == name)
            {
                return node->phone_number;
            }
        }
        return "";
    }

    void print()
    {
        for (int i = 0; i < TABLE_SIZE; i++)
        {
            cout << i << ": ";
            for (auto pair : table[i])
            {
                if (pair != nullptr)
                {
                    cout << "[" << pair->name << ", " << pair->phone_number << "]";
                }
            }
            cout << endl;
        }
    }
};

int main()
{
    HashMap employee_map;

    employee_map.insert("Mistah", "1234");
    employee_map.insert("Pastah", "5678");
    employee_map.insert("Ghana", "91011");

    cout << "Nomer Hp Mistah : " << employee_map.searchByName("Mistah") << endl;
    cout << "Phone Hp Pastah : " << employee_map.searchByName("Pastah") << endl;

    employee_map.remove("Mistah");

    cout << "Nomer Hp Mistah setelah dihapus : " << employee_map.searchByName("Mistah") << endl
         << endl;

    cout << "Hash Table : " << endl;

    employee_map.print();

    return 0;
}
```
### Interpretasi

Kodingan ini mengimplementasikan tabel hash untuk menyimpan nomor telepon karyawan berdasarkan nama mereka.

**Fitur Utama:**

* **Penyimpanan Data:**
    - Nama karyawan disimpan sebagai string.
    - Nomor telepon disimpan sebagai string.
    - Tabel hash digunakan untuk menyimpan dan mengambil data ini dengan efisien.
* **Operasi Tabel Hash:**
    - `hashFunc`: Fungsi ini menghitung nilai hash dari string nama. Nilai ini digunakan untuk menentukan bucket (indeks) dalam tabel hash di mana informasi karyawan harus disimpan.
    - `insert`: Fungsi ini menambahkan karyawan baru (nama dan nomor telepon) ke tabel hash.
    - `remove`: Fungsi ini menghapus karyawan (berdasarkan nama) dari tabel hash.
    - `searchByName`: Fungsi ini mencari nomor telepon karyawan berdasarkan namanya.
    - `print`: Fungsi ini mencetak isi seluruh tabel hash, menunjukkan setiap bucket dan informasi karyawan yang disimpannya (jika ada).
* **Contoh Penggunaan:**
    - Kodingan ini membuat tabel hash bernama `employee_map`.
    - Tiga karyawan ("Mistah", "Pastah", "Ghana") ditambahkan dengan nomor telepon yang sesuai.
    - Nomor telepon untuk "Mistah" dan "Pastah" diambil dan dicetak.
    - "Mistah" dihapus dari tabel hash.
    - Nomor telepon untuk "Mistah" dicari lagi (menunjukkan tidak ditemukan setelah penghapusan).
    - Akhirnya, seluruh isi tabel hash dicetak.

**Kesimpulan:**

Kodingan ini menunjukkan bagaimana tabel hash dapat digunakan untuk mengatur dan mengelola data dengan akses cepat berdasarkan kunci (nama karyawan dalam kasus ini).


## Unguided

### 1. Soal mengenai Hash Table
Implementasikan hash table untuk menyimpan data mahasiswa. Setiap mahasiswa memiliki NIM dan nilai. Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan nilai. Dengan ketentuan :

a. Setiap mahasiswa memiliki NIM dan nilai.

b. Program memiliki tampilan pilihan menu berisi poin C.

c. Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan rentang nilai (80 – 90).

```C++
#include <iostream>
#include <iomanip>
using namespace std;

const int MAX_SIZE = 10;

// struktur data untuk setiap node
struct mahasiswa
{
    string nama;
    long long NIM;
    int nilai;
    mahasiswa *next; // pointer untuk menunjukkan node selanjutnya dalam collision handling

    mahasiswa(string nama, long long NIM, int nilai) : nama(nama), NIM(NIM), nilai(nilai), next(nullptr) {}
};

// class hash table
class HashTable
{
private:
    mahasiswa **table; // array pointer untuk menunjukkan ke elemen-elemen tabel hash

    // fungsi hash sederhana
    int hash_func(long long key)
    {
        return key % MAX_SIZE; // menggunakan modulus untuk mendapatkan indeks
    }

public:
    // constructor
    HashTable()
    {
        table = new mahasiswa *[MAX_SIZE](); // inisialisasi array pointer dengan nullptr
    }

    // destructor
    ~HashTable()
    {
        // menghapus semua node dan array pointer
        for (int i = 0; i < MAX_SIZE; ++i)
        {
            mahasiswa *current = table[i];
            while (current != nullptr)
            {
                mahasiswa *temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] table;
    }

    // insertion
    void insert(string nama, long long NIM, int nilai)
    {
        int index = hash_func(NIM);                                 // mendapatkan indeks berdasarkan NIM
        mahasiswa *new_mahasiswa = new mahasiswa(nama, NIM, nilai); // membuat node baru
        new_mahasiswa->next = table[index];                         // menambahkan node baru ke depan daftar di indeks yang tepat
        table[index] = new_mahasiswa;
    }

    // deletion
    void remove(long long NIM)
    {
        int index = hash_func(NIM);        // mendapatkan indeks berdasarkan NIM
        mahasiswa *current = table[index]; // mengambil node pertama di indeks yang tepat
        mahasiswa *prev = nullptr;         // pointer untuk node sebelumnya
        while (current != nullptr)
        {
            if (current->NIM == NIM)
            {
                if (prev == nullptr)
                {
                    table[index] = current->next; // jika node yang dihapus adalah node pertama di indeks, atur node berikutnya sebagai node pertama
                }
                else
                {
                    prev->next = current->next; // jika bukan, hubungkan node sebelumnya dengan node setelahnya
                }
                delete current; // hapus node yang ditemukan
                cout << "Mahasiswa dengan NIM " << NIM << " telah dihapus." << endl;
                return;
            }
            prev = current;
            current = current->next;
        }
        cout << "Mahasiswa dengan NIM " << NIM << " tidak ditemukan." << endl;
    }

    // searching by NIM
    mahasiswa *cari_NIM(long long NIM)
    {
        long long index = hash_func(NIM);  // mendapatkan indeks berdasarkan NIM
        mahasiswa *current = table[index]; // mengambil node pertama di indeks yang tepat
        while (current != nullptr)
        {
            if (current->NIM == NIM)
            {
                return current; // kembalikan node jika NIM cocok
            }
            current = current->next;
        }
        return nullptr; // kembalikan nullptr jika tidak ditemukan
    }

    // searching by rentang nilai
    void cari_nilai(int awal, int akhir)
    {
        // mencetak header tabel
        cout << "-----------------------------------------------------------" << endl;
        cout << "|       Nama         |       NIM        |      Nilai      |" << endl;
        cout << "-----------------------------------------------------------" << endl;
        // traverse semua bucket pada tabel hash
        for (int i = 0; i < MAX_SIZE; ++i)
        {
            mahasiswa *current = table[i]; // mengambil node pertama di indeks yang tepat
            // traverse semua node dalam bucket
            while (current != nullptr)
            {
                // jika nilai berada dalam rentang yang ditentukan, cetak informasi mahasiswa
                if (current->nilai >= awal && current->nilai <= akhir)
                {
                    cout << "| " << setw(19) << left << current->nama
                         << "| " << setw(17) << current->NIM
                         << "| " << setw(15) << current->nilai << " |" << endl;
                }
                current = current->next;
            }
        }
        cout << "-----------------------------------------------------------" << endl;
    }

    // traversal
    void traverse()
    {
        // mencetak header tabel
        cout << "-----------------------------------------------------------" << endl;
        cout << "|       Nama         |       NIM        |      Nilai      |" << endl;
        cout << "-----------------------------------------------------------" << endl;
        // traverse semua bucket pada tabel hash
        for (int i = 0; i < MAX_SIZE; ++i)
        {
            mahasiswa *current = table[i]; // mengambil node pertama di indeks yang tepat
            // traverse semua node dalam bucket
            while (current != nullptr)
            {
                // cetak informasi mahasiswa
                cout << "| " << setw(19) << left << current->nama
                     << "| " << setw(17) << current->NIM
                     << "| " << setw(15) << current->nilai << " |" << endl;
                current = current->next;
            }
        }
        cout << "-----------------------------------------------------------" << endl;
    }
};

int main()
{
    HashTable ht;

    int pilih, nilai, awal, akhir;
    string nama;
    long long NIM;

    do
    {
        // menu utama
        cout << "\nMenu:" << endl;
        cout << "1. Tambah Data Mahasiswa" << endl;
        cout << "2. Hapus Data Mahasiswa" << endl;
        cout << "3. Cari berdasarkan NIM" << endl;
        cout << "4. Cari berdasarkan Rentang Nilai" << endl;
        cout << "5. Tampilkan Semua Data" << endl;
        cout << "6. Keluar" << endl;
        cout << "Pilih menu : ";
        cin >> pilih;

        switch (pilih)
        {
        case 1:
            // tambah data mahasiswa
            cout << "Masukan nama : ";
            cin.ignore();
            getline(cin, nama);
            cout << "Masukan NIM : ";
            cin >> NIM;
            cout << "Masukan nilai : ";
            cin >> nilai;
            ht.insert(nama, NIM, nilai);
            cout<<"Data berhasil ditambahkan"<<endl;
            break;
        case 2:
            // hapus data mahasiswa berdasarkan NIM
            cout << "Masukan NIM yang ingin dihapus : ";
            cin >> NIM;
            ht.remove(NIM);
            break;
        case 3:
            // cari mahasiswa berdasarkan NIM
            cout << "Masukan NIM yang ingin dicari : ";
            cin >> NIM;
            {
                mahasiswa *mahasiswa_ptr = ht.cari_NIM(NIM);
                if (mahasiswa_ptr)
                {
                    cout << "Ditemukan mahasiswa dengan NIM " << NIM << " bernama " << mahasiswa_ptr->nama << " dan memiliki nilai " << mahasiswa_ptr->nilai << endl;
                }
                else
                {
                    cout << "mahasiswa dengan NIM " << NIM << " tidak ditemukan" << endl;
                }
            }
            break;
        case 4:
            // cari mahasiswa berdasarkan rentang nilai
            cout << "masukan nilai awal : ";
            cin >> awal;
            cout << "maukan nilai akhir : ";
            cin >> akhir;
            ht.cari_nilai(awal, akhir);
            break;
        case 5:
            // tampilkan semua data mahasiswa
            ht.traverse();
            break;
        case 6:
            cout << "Matur Tengkyu." << endl; // keluar dari program
            break;
        default:
            cout << "Pilihan invalid!" << endl; // jika pilihan tidak valid
        }
    } while (pilih != 6); // ulangi sampai pengguna memilih untuk keluar

    return 0;
}

```

### Output menu 1:

![image](https://github.com/kepin7/Struktur-Data-Assignment/assets/91511212/fe11bfdc-4336-4ef9-a341-f9946a49f9e9)

### Output menu 2:

![image](https://github.com/kepin7/Struktur-Data-Assignment/assets/91511212/9ac9a5f7-77af-48b0-aeab-f84e1755bbfb)

### Output menu 3:

![image](https://github.com/kepin7/Struktur-Data-Assignment/assets/91511212/f9d647d0-f5a5-41bb-9104-ebfd73b43ff7)

### Output menu 4:

![image](https://github.com/kepin7/Struktur-Data-Assignment/assets/91511212/5023369d-4272-4a20-b50e-a44911596fb0)

### Output menu 5:

![image](https://github.com/kepin7/Struktur-Data-Assignment/assets/91511212/8a0134a9-9be7-4923-9123-d34a1896a6d3)

### Output menu 6:

![image](https://github.com/kepin7/Struktur-Data-Assignment/assets/91511212/7b481089-98bc-4547-a48c-6a58d9e705fe)

### Interpretasi

**Fitur utama tabel hash ini:**

* **Penyimpanan data mahasiswa:** Setiap node dalam tabel hash menyimpan informasi mahasiswa seperti nama, NIM, dan nilai.
* **Pencarian berdasarkan NIM:** Metode `cari_NIM` memungkinkan pencarian mahasiswa berdasarkan NIM mereka.
* **Pencarian berdasarkan rentang nilai:** Metode `cari_nilai` memungkinkan pencarian mahasiswa berdasarkan rentang nilai mereka.
* **Penambahan data mahasiswa:** Metode `insert` memungkinkan penambahan data mahasiswa baru ke tabel hash.
* **Penghapusan data mahasiswa:** Metode `remove` memungkinkan penghapusan data mahasiswa berdasarkan NIM mereka.
* **Traversal:** Metode `traverse` memungkinkan pencetakan semua data mahasiswa dalam tabel hash.

**Struktur kode:**

* **Struktur data mahasiswa:** Struktur `mahasiswa` mendefinisikan node dalam tabel hash, yang menyimpan informasi nama, NIM, nilai, dan pointer ke node berikutnya dalam daftar berantai (collision handling).
* **Kelas HashTable:** Kelas `HashTable` mendefinisikan tabel hash dan operasi terkait seperti penyisipan, penghapusan, pencarian, dan traversal.
* **Fungsi hash:** Fungsi `hash_func` digunakan untuk memetakan NIM ke indeks dalam tabel hash.
* **Fungsi main:** Fungsi `main` adalah titik masuk program. Ini menampilkan menu utama, menerima input pengguna, dan melakukan operasi yang sesuai.

**Penjelasan lebih lanjut:**

* Tabel hash menggunakan teknik **collision handling** untuk menangani tabrakan saat memetakan NIM ke indeks yang sama. Dalam kodingan ini, collision handling menggunakan daftar berantai.
* Nilai default untuk ukuran maksimum tabel hash adalah `10`. Anda dapat mengubah nilai ini jika diperlukan.
* Fungsi hash dalam kodingan ini adalah fungsi hash sederhana yang menggunakan modulus untuk mendapatkan indeks. Anda dapat menggunakan fungsi hash yang lebih kompleks jika diperlukan.

**Kesimpulan:**

Kodingan ini menunjukkan implementasi tabel hash sederhana untuk menyimpan data mahasiswa. Kodingan ini menyediakan fungsionalitas dasar untuk menambah, menghapus, mencari, dan menampilkan data mahasiswa. Kodingan dapat diperluas lagi dengan menambahkan fitur lain seperti pengurutan, statistik, dan persistensi data.

### Full Code Screenshot:

![image](https://github.com/dkumui/Struktur-Data-Assignment/assets/91511212/d8aa83cd-f7ea-4180-9dc6-ca094500023b)

## Kesimpulan

Hash table adalah struktur data yang efisien digunakan untuk memetakan kunci ke nilai-nilai tertentu. Dengan menggunakan fungsi hash, kunci-kunci tersebut diubah menjadi indeks yang menunjukkan lokasi penyimpanan dalam tabel hash. Hal ini memungkinkan akses cepat dan efisien terhadap data, dengan waktu akses rata-rata yang konstan (O(1)). Selain itu, teknik penanganan collision seperti chaining memungkinkan penanganan konflik yang terjadi saat dua kunci menghasilkan indeks yang sama. Dengan demikian, hash table sangat berguna dalam pengelolaan data di berbagai aplikasi, seperti basis data, pencarian, dan penyimpanan asosiatif.

## Referensi

**[1] M. Gaur, "Implementation of Hash Table in C++," 2020, doi: 10.13140/RG.2.2.23686.62882.**

**[2] M. Kumar and S. Jain, "A Comparative Analysis of Various Hashing Techniques," 2021, doi: 10.1109/ICTC52289.2021.00046.**

**[3] I. Sheremet et al., "Hash table implementation and optimization for collision resolution methods chaining and robin hood hashing," 2021, doi: 10.1109/ICCCUS51299.2021.9496256.**

**[4] B. Ahmed, M. A. Azam and M. Shahriar, "An efficient implementation of hash tables using linear probing and chaining," 2023, doi: 10.1109/ICECTECH54585.2023.9660849.**

**[5] P. K. Sahu and S. K. Sahu, "An efficient load balancing technique for hash tables using dynamic linear probing," 2024, doi: 10.1109/JSAN.2023.2315409.**

**[6] A. K. Singh, "Practical implementation of hash table in C++," 2020, doi: 10.13140/RG.2.2.34053.67683.**