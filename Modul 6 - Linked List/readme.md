# <h1 align="center">Laporan Praktikum Modul Linked List</h1>

<p align="center">Muhammad Azka</p>

## Features

- [Dasar Teori](#dasar-teori)
- [Guided](#guided)
- [Unguided](#unguided)
- [Kesimpulan](#kesimpulan)
- [Referensi](#referensi)

## Dasar Teori

### A. Linked List Non Circular
Linked list non circular merupakan linked list di mana node pertama (head) dan node terakhir (tail) tidak saling terhubung [1]. Pointer terakhir selalu bernilai NULL untuk menandakan akhir dari list [2]. Secara umum struktur data dan operasi linked list non circular adalah sebagai berikut [1,3]:

1. Deklarasi struct node dengan fields data dan pointer ke node berikutnya. 
2. Inisialisasi pointer head dan tail ke NULL.
3. Operasi penambahan, penghapusan, ubah dan tampil node. 
4. Pointer tail diupdate jika node baru ditambahkan sebagai node terakhir.

### B. Linked List Circular
Berbeda dengan linked list non circular, pada linked list circular node terakhir akan terhubung kembali ke node pertama sehingga membentuk sebuah lingkaran [4]. Umumnya struktur data dan operasi linked list circular adalah sebagai berikut [2,5]:

1. Penggunaan dummy node untuk menandai akhir dari list.
2. Pointer tail tidak diset ke NULL tetapi mengarah ke dummy node. 
3. Operasi penambahan node di awal dan akhir agak berbeda dari non circular.
4. Untuk menampilkan semua node, digunakan looping sampai node saat ini sama dengan dummy node.
5. Operasi penghapusan juga memerlukan pengecekan tambahan untuk kasus hanya satu node.

### C. Double Linked List
Double linked list merupakan pengembangan dari single linked list dimana setiap node memiliki dua buah pointer, yaitu pointer ke node sebelumnya dan pointer ke node berikutnya. Kelebihan double linked list dibanding single linked list adalah operasi penambahan dan penghapusan node lebih mudah karena dapat diakses dari kedua arah [6].
Struktur data dan operasi pada double linked list adalah sebagai berikut:

1. Setiap node memiliki dua buah pointer, yaitu prev dan next.
2. Pointer head dan tail digunakan untuk menandai awal dan akhir list. 
3. Operasi penambahan dapat dilakukan di awal (mengubah pointer head) atau akhir (mengubah pointer tail).
4. Operasi penghapusan dapat dilakukan dengan mengubah pointer prev dan next dari node sebelum dan sesudah node yang dihapus.
5. Operasi penambahan dan penghapusan node di tengah-tengah lebih mudah karena dapat diakses dari kedua arah.

Dengan kemampuan mengakses dari kedua arah, double linked list lebih fleksibel dibanding single linked list meski memiliki ruang pemakaian memory yang lebih besar.

## Guided

### 1. Linked List Non-Circular

```C++
#include <iostream>
using namespace std;

/// PROGRAM SINGLE LINKED LIST NON-CIRCULAR
// Deklarasi Struct Node
struct Node {
    int data;
    Node *next;
};

Node *head;
Node *tail;

// Inisialisasi Node
void init() {
    head = NULL;
    tail = NULL;
}

// Pengecekan apakah list kosong
bool isEmpty() {
    return (head == NULL);
}

// Tambah Data di Depan
void insertDepan(int nilai) {
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty()) {
        head = tail = baru;
    } else {
        baru->next = head;
        head = baru;
    }
}

// Tambah Data di Belakang
void insertBelakang(int nilai) {
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty()) {
        head = tail = baru;
    } else {
        tail->next = baru;
        tail = baru;
    }
}

// Hitung Jumlah Node
int hitungList() {
    Node *hitung = head;
    int jumlah = 0;
    while (hitung != NULL) {
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}

// Tambah Data di Tengah
void insertTengah(int data, int posisi) {
    if (posisi < 1 || posisi > hitungList()) {
        cout << "Posisi diluar jangkauan" << endl;
    } else if (posisi == 1) {
        cout << "Posisi bukan posisi tengah" << endl;
    } else {
        Node *baru = new Node();
        baru->data = data;
        Node *bantu = head;
        for (int nomor = 1; nomor < posisi - 1; nomor++) {
            bantu = bantu->next;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}

// Hapus Node di Depan
void hapusDepan() {
    if (!isEmpty()) {
        Node *hapus = head;
        if (head->next != NULL) {
            head = head->next;
        } else {
            head = tail = NULL;
        }
        delete hapus;
    } else {
        cout << "List kosong!" << endl;
    }
}

// Hapus Node di Belakang
void hapusBelakang() {
    if (!isEmpty()) {
        Node *hapus = tail;
        if (head != tail) {
            Node *bantu = head;
            while (bantu->next != tail) {
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
        } else {
            head = tail = NULL;
        }
        delete hapus;
    } else {
        cout << "List kosong!" << endl;
    }
}

// Hapus Node di Tengah
void hapusTengah(int posisi) {
    if (posisi < 1 || posisi > hitungList()) {
        cout << "Posisi di luar jangkauan" << endl;
    } else if (posisi == 1) {
        cout << "Posisi bukan posisi tengah" << endl;
    } else {
        Node *hapus;
        Node *bantu = head;
        for (int nomor = 1; nomor < posisi - 1; nomor++) {
            bantu = bantu->next;
        }
        hapus = bantu->next;
        bantu->next = hapus->next;
        delete hapus;
    }
}

// Ubah Data di Depan
void ubahDepan(int data) {
    if (!isEmpty()) {
        head->data = data;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Ubah Data di Tengah
void ubahTengah(int data, int posisi) {
    if (!isEmpty()) {
        if (posisi < 1 || posisi > hitungList()) {
            cout << "Posisi di luar jangkauan" << endl;
        } else if (posisi == 1) {
            cout << "Posisi bukan posisi tengah" << endl;
        } else {
            Node *bantu = head;
            for (int nomor = 1; nomor < posisi; nomor++) {
                bantu = bantu->next;
            }
            bantu->data = data;
        }
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Ubah Data di Belakang
void ubahBelakang(int data) {
    if (!isEmpty()) {
        tail->data = data;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus Semua Node
void clearList() {
    Node *hapus;
    while (head != NULL) {
        hapus = head;
        head = head->next;
        delete hapus;
    }
    tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}

// Tampilkan List
void tampil() {
    Node *bantu = head;
    if (!isEmpty()) {
        while (bantu != NULL) {
            cout << bantu->data << " ";
            bantu = bantu->next;
        }
        cout << endl;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

int main() {
    init();
    insertDepan(3); tampil();
    insertBelakang(5); tampil();
    insertDepan(2); tampil();
    insertDepan(1); tampil();
    hapusDepan(); tampil();
    hapusBelakang(); tampil();
    insertTengah(7, 2); tampil();
    hapusTengah(2); tampil();
    ubahDepan(1); tampil();
    ubahBelakang(8); tampil();
    ubahTengah(11, 2); tampil();
    clearList();
    return 0;
}
```

### Interpretasi:

Kodingan di atas merupakan implementasi Single Linked List Non-Circular dalam bahasa C++. Berikut interpretasi detailnya:

**Struktur Data:**

* **Struct Node:**
    * `data`: Menyimpan nilai data (integer) pada setiap node.
    * `next`: Menyimpan pointer ke node berikutnya dalam list.
* **Variabel Global:**
    * `head`: Pointer ke node pertama dalam list.
    * `tail`: Pointer ke node terakhir dalam list.

**Fungsi-Fungsi:**

* **init():** Inisialisasi list dengan `head` dan `tail` bernilai `NULL`.
* **isEmpty():** Memeriksa apakah list kosong. Mengembalikan `true` jika `head` bernilai `NULL`, dan `false` jika tidak.
* **insertDepan(int nilai):** Menambahkan node baru dengan nilai `nilai` di depan list.
* **insertBelakang(int nilai):** Menambahkan node baru dengan nilai `nilai` di belakang list.
* **hitungList():** Menghitung jumlah node dalam list.
* **insertTengah(int data, int posisi):** Menambahkan node baru dengan nilai `data` di posisi `posisi` dalam list.
* **hapusDepan():** Menghapus node pertama dalam list.
* **hapusBelakang():** Menghapus node terakhir dalam list.
* **hapusTengah(int posisi):** Menghapus node di posisi `posisi` dalam list.
* **ubahDepan(int data):** Mengubah nilai data node pertama dalam list menjadi `data`.
* **ubahTengah(int data, int posisi):** Mengubah nilai data node di posisi `posisi` dalam list menjadi `data`.
* **ubahBelakang(int data):** Mengubah nilai data node terakhir dalam list menjadi `data`.
* **clearList():** Menghapus semua node dalam list.
* **tampil():** Menampilkan nilai data dari setiap node dalam list.

**Alur Program Utama (main()):**

1. **Inisialisasi list:** Memanggil fungsi `init()` untuk menginisialisasi list.
2. **Memasukkan data:**
    * Memasukkan 3 di depan list dan menampilkannya.
    * Memasukkan 5 di belakang list dan menampilkannya.
    * Memasukkan 2 di depan list dan menampilkannya.
    * Memasukkan 1 di depan list dan menampilkannya.
3. **Penghapusan data:**
    * Menghapus node pertama dan menampilkan list.
    * Menghapus node terakhir dan menampilkan list.
4. **Memasukkan data di tengah:**
    * Memasukkan 7 di posisi 2 dan menampilkan list.
5. **Menghapus data di tengah:**
    * Menghapus node di posisi 2 dan menampilkan list.
6. **Mengubah data:**
    * Mengubah nilai data node pertama menjadi 1 dan menampilkan list.
    * Mengubah nilai data node terakhir menjadi 8 dan menampilkan list.
    * Mengubah nilai data node di posisi 2 menjadi 11 dan menampilkan list.
7. **Penghapusan semua data:**
    * Menghapus semua node dalam list dan menampilkan pesan.

**Kesimpulan:**

Kodingan ini menunjukkan implementasi Single Linked List Non-Circular yang lengkap dengan fungsi-fungsi untuk menambahkan, menghapus, mengubah, dan menampilkan data dalam list.

### 2. Double Linked List

```C++
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void push(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->prev = nullptr;
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        } else {
            tail = newNode;
        }
        head = newNode;
    }

    void pop() {
        if (head == nullptr) {
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
    }

    bool update(int oldData, int newData) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == oldData) {
                current->data = newData;
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void deleteAll() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }

    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;
    while (true) {
        cout << "1. Add data" << endl;
        cout << "2. Delete data" << endl;
        cout << "3. Update data" << endl;
        cout << "4. Clear data" << endl;
        cout << "5. Display data" << endl;
        cout << "6. Exit" << endl;
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                int data;
                cout << "Enter data to add: ";
                cin >> data;
                list.push(data);
                break;
            }
            case 2: {
                list.pop();
                break;
            }
            case 3: {
                int oldData, newData;
                cout << "Enter old data: ";
                cin >> oldData;
                cout << "Enter new data: ";
                cin >> newData;
                bool updated = list.update(oldData, newData);
                if (!updated) {
                    cout << "Data not found" << endl;
                }
                break;
            }
            case 4: {
                list.deleteAll();
                break;
            }
            case 5: {
                list.display();
                break;
            }
            case 6: {
                return 0;
            }
            default: {
                cout << "Invalid choice" << endl;
                break;
            }
        }
    }
    return 0;
}
```

### Interpretasi:

Kodingan di atas merupakan implementasi Doubly Linked List dalam bahasa C++. Berikut interpretasi detailnya:

**Struktur Data:**

* **Class Node:**
    * `data`: Menyimpan nilai data (integer) pada setiap node.
    * `prev`: Menyimpan pointer ke node sebelumnya dalam list.
    * `next`: Menyimpan pointer ke node berikutnya dalam list.
* **Class DoublyLinkedList:**
    * `head`: Pointer ke node pertama dalam list.
    * `tail`: Pointer ke node terakhir dalam list.

**Fungsi-Fungsi dalam DoublyLinkedList:**

* **DoublyLinkedList():** Konstruktor untuk inisialisasi list dengan `head` dan `tail` bernilai `nullptr`.
* **push(int data):** Menambahkan node baru dengan nilai `data` di depan list.
* **pop():** Menghapus node pertama dalam list.
* **update(int oldData, int newData):** Mencari node dengan nilai `oldData` dan memperbaruinya menjadi `newData`. Mengembalikan `true` jika data ditemukan, dan `false` jika tidak ditemukan.
* **deleteAll():** Menghapus semua node dalam list.
* **display():** Menampilkan nilai data dari setiap node dalam list.

**Program Utama (main()):**

1. **Membuat objek DoublyLinkedList:** Deklarasi objek `list` dari class `DoublyLinkedList`.
2. **Menu interaktif:**
    * Menampilkan menu dengan pilihan untuk menambah, menghapus, update, menghapus semua, menampilkan data, dan keluar.
    * Menggunakan loop `while(true)` untuk menjalankan program sampai pengguna memilih keluar.
    * Membaca pilihan pengguna dan melakukan tindakan sesuai pilihan:
        * **Pilihan 1 (Tambah data):** Meminta pengguna untuk memasukkan data baru dan memanggil fungsi `push` untuk menambahkannya ke depan list.
        * **Pilihan 2 (Hapus data):** Memanggil fungsi `pop` untuk menghapus node pertama dalam list.
        * **Pilihan 3 (Update data):** Meminta pengguna untuk memasukkan data lama dan data baru. Memanggil fungsi `update` untuk memperbarui data. Menampilkan pesan jika data tidak ditemukan.
        * **Pilihan 4 (Hapus semua data):** Memanggil fungsi `deleteAll` untuk menghapus semua node dalam list.
        * **Pilihan 5 (Tampilkan data):** Memanggil fungsi `display` untuk menampilkan nilai data dari setiap node dalam list.
        * **Pilihan 6 (Keluar):** Keluar dari program dengan mengembalikan nilai 0.
        * **Pilihan lain:** Menampilkan pesan untuk pilihan yang tidak valid.

**Kesimpulan:**

Kodingan ini menunjukkan implementasi Doubly Linked List yang lengkap dengan menu interaktif untuk melakukan berbagai operasi pada list. Pengguna dapat menambah, menghapus, memperbarui, menghapus semua, dan menampilkan data dalam list.

### 3. Linked List Circular

```C++
#include <iostream>
using namespace std;

/// PROGRAM SINGLE LINKED LIST CIRCULAR

// Deklarasi Struct Node
struct Node {
    string data;
    Node *next;
};

Node *head, *tail, *baru, *bantu, *hapus;

void init() {
    head = NULL;
    tail = head;
}

// Pengecekan
int isEmpty() {
    if (head == NULL)
        return 1; // true
    else
        return 0; // false
}

// Buat Node Baru
void buatNode(string data) {
    baru = new Node;
    baru->data = data;
    baru->next = NULL;
}

// Hitung List
int hitungList() {
    bantu = head;
    int jumlah = 0;

    while (bantu != NULL) {
        jumlah++;
        bantu = bantu->next;
    }

    return jumlah;
}

// Tambah Depan
void insertDepan(string data) {
    // Buat Node baru
    buatNode(data);

    if (isEmpty() == 1) {
        head = baru;
        tail = head;
        baru->next = head;
    } else {
        while (tail->next != head) {
            tail = tail->next;
        }

        baru->next = head;
        head = baru;
        tail->next = head;
    }
}

// Tambah Tengah
void insertTengah(string data, int posisi) {
    if (isEmpty() == 1) {
        head = baru;
        tail = head;
        baru->next = head;
    } else {
        baru->data = data;

        // transversing
        int nomor = 1;
        bantu = head;

        while (nomor < posisi -1) {
            bantu = bantu->next;
            nomor++;
        }

        baru->next = bantu->next;
        bantu->next = baru;
    }
}

// Tambah Belakang
void insertBelakang(string data) {
    // Buat Node Baru
    buatNode(data);

    if (isEmpty() == 1) {
        head = baru;
        tail = head;
        baru->next = head;
    } else {
        while (tail->next != head) {
            tail = tail->next;
        }

        tail->next = baru;
        baru->next = head;
    }
}

// Hapus Depan
void hapusDepan() {
    if (isEmpty() == 0) {
        hapus = head;
        tail = head;

        if (hapus->next == head) {
            head = NULL;
            tail = NULL;
            delete hapus;
        } else {
            while (tail->next != hapus) {
                tail = tail->next;
            }

            head = head->next;
            tail->next = head;
            hapus->next = NULL;
            delete hapus;
        }
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus Belakang
void hapusBelakang() {
    if (isEmpty() == 0) {
        hapus = head;
        tail = head;

        if (hapus->next == head) {
            head = NULL;
            tail = NULL;
            delete hapus;
        } else {
            while (hapus->next != head) {
                hapus = hapus->next;
            }

            while (tail->next != hapus) {
                tail = tail->next;
            }

            tail->next = head;
            hapus->next = NULL;
            delete hapus;
        }
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus Tengah
void hapusTengah(int posisi) {
    if (isEmpty() == 0) {
        // Transversing untuk mencari node di posisi yang ingin dihapus
        int nomor = 1;
        bantu = head;

        while (nomor < posisi - 1) {
            bantu = bantu->next;
            nomor++;
        }

        hapus = bantu->next;
        bantu->next = hapus->next;
        delete hapus;

    } else {
        cout << "List masih kosong!" << endl;
    }
}


// Hapus List
void clearList() {
    if (head != NULL) {
        hapus = head->next;

        while (hapus != head) {
            bantu = hapus-> next;
            delete hapus;
            hapus = bantu;
        }

        delete head;
        head = NULL;
    }

    cout << "List berhasil terhapus!" << endl;
}

//Tampilan List
void tampil() {
    if (isEmpty() == 0) {
        tail = head;

        do {
            cout << tail->data << ends;
            tail = tail->next;
        } while (tail != head);

        cout << endl;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

int main() {
    init();
    insertDepan("Ayam");
    tampil();
    insertDepan("Bebek");
    tampil();
    insertBelakang("Cicak");
    tampil();
    insertBelakang("Domba");
    tampil();
    hapusBelakang();
    tampil();
    insertTengah("Sapi", 2);
    tampil();
    hapusTengah(2);
    tampil();
    insertBelakang("Domba");
    tampil();
    return 0;
}
```

### Interpretasi:

Kodingan di atas merupakan implementasi Single Linked List Circular dalam bahasa C++. Berikut interpretasi detailnya:

**Struktur Data:**

* **Struct Node:**
    * `data`: Menyimpan nilai data (string) pada setiap node.
    * `next`: Menyimpan pointer ke node berikutnya dalam list.
* **Variabel Global:**
    * `head`: Pointer ke node pertama dalam list.
    * `tail`: Pointer ke node terakhir dalam list.
    * `baru`: Pointer ke node baru yang akan ditambahkan.
    * `bantu`: Pointer yang digunakan untuk membantu dalam operasi list.
    * `hapus`: Pointer ke node yang akan dihapus.

**Fungsi-Fungsi:**

* **init():** Inisialisasi list dengan `head` dan `tail` bernilai `NULL`.
* **isEmpty():** Memeriksa apakah list kosong. Mengembalikan `1` jika list kosong, dan `0` jika tidak.
* **buatNode(string data):** Membuat node baru dengan nilai `data` dan pointer `next` bernilai `NULL`.
* **hitungList():** Menghitung jumlah node dalam list.
* **insertDepan(string data):** Menambahkan node baru dengan nilai `data` di depan list.
* **insertTengah(string data, int posisi):** Menambahkan node baru dengan nilai `data` di posisi `posisi` dalam list.
* **insertBelakang(string data):** Menambahkan node baru dengan nilai `data` di belakang list.
* **hapusDepan():** Menghapus node pertama dalam list.
* **hapusBelakang():** Menghapus node terakhir dalam list.
* **hapusTengah(int posisi):** Menghapus node di posisi `posisi` dalam list.
* **clearList():** Menghapus semua node dalam list.
* **tampil():** Menampilkan nilai data dari setiap node dalam list.

**Program Utama (main()):**

1. **Inisialisasi list:** Memanggil fungsi `init()` untuk menginisialisasi list.
2. **Menambahkan data:**
    * Memanggil `insertDepan("Ayam")` untuk menambahkan node baru dengan nilai "Ayam" di depan list.
    * Memanggil `insertDepan("Bebek")` untuk menambahkan node baru dengan nilai "Bebek" di depan list.
    * Memanggil `insertBelakang("Cicak")` untuk menambahkan node baru dengan nilai "Cicak" di belakang list.
    * Memanggil `insertBelakang("Domba")` untuk menambahkan node baru dengan nilai "Domba" di belakang list.
3. **Penghapusan data:**
    * Memanggil `hapusBelakang()` untuk menghapus node terakhir (nilai "Domba").
4. **Penambahan data di tengah:**
    * Memanggil `insertTengah("Sapi", 2)` untuk menambahkan node baru dengan nilai "Sapi" di posisi 2.
5. **Penghapusan data di tengah:**
    * Memanggil `hapusTengah(2)` untuk menghapus node di posisi 2 (nilai "Sapi").
6. **Penambahan data:**
    * Memanggil `insertBelakang("Domba")` untuk menambahkan node baru dengan nilai "Domba" di belakang list.
7. **Penampilan list:**
    * Memanggil `tampil()` untuk menampilkan nilai data dari setiap node dalam list.

**Kesimpulan:**

Kodingan ini merupakan implementasi Single Linked List Circular yang lengkap dan fungsional.

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

[1] S. Karumanchi, "Linked Lists," in Data Structures and Algorithms Made Easy in Java: Data Structure and Algorithmic Puzzles, India: CareerMonk Publications, 2020, ch. 2, sec. 1.1, pp. 51-53. 

[2] W. Chen, J. Xiao and C. Yang, "Research on data structures and algorithms of circular linked list based on C++," IOP Conf. Series: Materials Science and Engineering, vol. 1064, no. 1, 2022. 

[3] M. Goel et al., "Implementation of Operations on Linked List," in Proc. Int. Conf. Emerging Trends in Electrical, Electronic and Communications Engineering (ELECOM), Indore, India, Dec. 2020, pp. 1-6, doi: 10.1109/ELECOM49947.2020.9249689.

[4] H. Shrestha, "Exploring Basic Linked List Implementation in C++," International Journal of Scientific & Engineering Research, vol. 11, no. 11, pp. 1-5, Nov. 2020. 

[5] A. J. Mishra et al., "Implementation of circular linked list in C++ programming," IJESC, vol. 12, no. 2, pp. 12824-12828, 2023.

[6] L. Liu et al., "Implementation and Application of Double Linked List," JCP, vol. 15, no. 9, pp. 1138-1143, Sep. 2020, doi: 10.3966/160792642020091509004.
